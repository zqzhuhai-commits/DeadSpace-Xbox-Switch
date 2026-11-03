#pragma once
#include <cstdint>
namespace ds1zh {
struct Character { uint32_t value; uint32_t bytes; };
// Invalid sequences retain one original byte so legacy labels and control bytes
// make progress without swallowing following ASCII punctuation or NUL.
template<class Read> inline Character Decode(uint32_t address, Read read) {
 const uint32_t a=read(address);
 if(a<0x80) return {a,1};
 if(a>=0xC2 && a<=0xDF) {
  const uint32_t b=read(address+1);
  if((b&0xC0)==0x80) return {((a&31)<<6)|(b&63),2};
 } else if(a>=0xE0 && a<=0xEF) {
  const uint32_t b=read(address+1);
  if((b&0xC0)==0x80 && !(a==0xE0 && b<0xA0) && !(a==0xED && b>=0xA0)) {
   const uint32_t c=read(address+2);
   if((c&0xC0)==0x80) return {((a&15)<<12)|((b&63)<<6)|(c&63),3};
  }
 }
 return {a,1};
}
}
