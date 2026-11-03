from pathlib import Path
import struct,json,hashlib
import sys
root=Path(sys.argv[2]).parent;b=Path(sys.argv[2]).read_bytes();shoff=struct.unpack_from('<Q',b,40)[0];size,n,st=struct.unpack_from('<HHH',b,58);ss=[struct.unpack_from('<IIQQQQIIQQ',b,shoff+i*size) for i in range(n)];names=b[ss[st][4]:ss[st][4]+ss[st][5]]
def nm(s):
 a=s[0];return names[a:names.index(0,a)].decode()
sections={nm(s):(i,s,b[s[4]:s[4]+s[5]]) for i,s in enumerate(ss)}
symsec=sections['.symtab'][1];strsec=ss[symsec[6]];strings=b[strsec[4]:strsec[4]+strsec[5]];symbols=[]
for i in range(symsec[4],symsec[4]+symsec[5],24):
 no,info,other,sec,value,sz=struct.unpack_from('<IBBHQQ',b,i);symbols.append((strings[no:strings.index(0,no)].decode(),sec,value,sz))
original=Path(sys.argv[1]).read_bytes();assert hashlib.sha256(original).hexdigest()=='34216488c7d71c3430d2a2211ffb76e35ac9052728b1efc349ebcc5317a1674b';patched=bytearray(original)
render=0x6a08c0;width=0x21a8470;cut=0x1f80
wcode=sections['.text.__imp__sub_825390C0'][2];rcode=sections['.text.__imp__sub_8253B578'][2];decoder=sections['.text.ds1_decode'][2];crcode=sections['.text._ZN3rex3ppc10CRRegister7compareEdd'][2]
tail=width+len(wcode);dec=tail+len(rcode)-cut;cr=dec+len(decoder);assert cr+len(crcode)<=width+0xc60
entry={'__imp__sub_825390C0':width,'__imp__sub_8253B578':render,'ds1_decode':dec,'_ZN3rex3ppc10CRRegister7compareEdd':cr}
for x in ['sub_825390C0','sub_8253B578']:entry[x]=entry['__imp__'+x]
def hostguest(a):
 at=original.find(struct.pack('<II',a,0));assert at>=0;return struct.unpack_from('<Q',original,at+8)[0]
for name,sec,value,sz in symbols:
 if name.startswith('sub_') and name not in entry:entry[name]=hostguest(int(name[4:],16))
def sx(x,n):return (x^(1<<(n-1)))-(1<<(n-1))
def branch(src,dst):
 d=dst-src;assert d%4==0 and -(1<<27)<=d<(1<<27);return 0x14000000|((d//4)&0x3ffffff)
def loc(name,offset):
 if name=='__imp__sub_8253B578':return render+offset if offset<cut else tail+offset-cut
 return entry[name]+offset
islands=[];islandnext=render+cut+4
# Only replace the two original functions; all segment headers and assets stay byte-identical.
for a,z in [(render,0x2000),(width,0xc60)]:patched[a:a+z]=struct.pack('<I',0xd503201f)*(z//4)
checks=[]
for name,code in [('__imp__sub_825390C0',wcode),('__imp__sub_8253B578',rcode),('ds1_decode',decoder),('_ZN3rex3ppc10CRRegister7compareEdd',crcode)]:
 rel={};rname='.rela.text.'+name
 if rname in sections:
  rsec=sections[rname][1]
  for at in range(rsec[4],rsec[4]+rsec[5],24):
   off,info,addend=struct.unpack_from('<QQq',b,at);sym=symbols[info>>32][0];typ=info&0xffffffff;assert typ==283,(name,typ,sym);rel[off]=(sym,addend)
 for off in range(0,len(code),4):
  src=loc(name,off);v=struct.unpack_from('<I',code,off)[0];target=None;bits=None
  if off in rel:
   sym,addend=rel[off];target=entry[sym]+addend;v=branch(src,target)|0x80000000;bits=26
  elif v&0x7c000000==0x14000000:
   old=off+4*sx(v&0x3ffffff,26);assert 0<=old<len(code),(name,hex(off),hex(old));target=loc(name,old);v=(v&0xfc000000)|(branch(src,target)&0x3ffffff);bits=26
  elif v&0xff000010==0x54000000 or v&0x7e000000==0x34000000 or v&0x7e000000==0x36000000:
   bits=14 if v&0x7e000000==0x36000000 else 19;mask=(1<<bits)-1;old=off+4*sx((v>>5)&mask,bits);assert 0<=old<len(code);target=loc(name,old)
   delta=target-src
   if not -(1<<(bits+1))<=delta<(1<<(bits+1)):
    assert src<render+cut and islandnext+4<=render+0x2000
    island=islandnext;islandnext+=4;islands.append((island,target));struct.pack_into('<I',patched,island,branch(island,target));target=island;delta=target-src
   assert delta%4==0 and -(1<<(bits+1))<=delta<(1<<(bits+1));v=(v&~(mask<<5))|(((delta//4)&mask)<<5)
  else:
   assert v&0x1f000000!=0x10000000,('unexpected ADR/P',name,hex(off))
   assert v&0x3b000000!=0x18000000,('unexpected literal load',name,hex(off))
  struct.pack_into('<I',patched,src,v)
  if target is not None:checks.append((src,target,bits))
struct.pack_into('<I',patched,render+cut,branch(render+cut,tail));checks.append((render+cut,tail,26))
checks +=[(a,z,26) for a,z in islands]
for src,target,bits in checks:
 v=struct.unpack_from('<I',patched,src)[0];actual=src+4*sx((v&0x3ffffff) if bits==26 else ((v>>5)&((1<<bits)-1)),bits);assert actual==target
ranges=[(render,render+0x2000),(width,width+0xc60)]
assert patched[:render]==original[:render] and patched[render+0x2000:width]==original[render+0x2000:width] and patched[width+0xc60:]==original[width+0xc60:]
assert hashlib.sha256(patched).hexdigest()=='3025da82e8756f109f91dbf83ecc3576ad77bd3074bea97ea8b8e889152e921d'
with Path(sys.argv[3]).open('xb') as f:f.write(patched)
print('Verified:',hashlib.sha256(patched).hexdigest())
