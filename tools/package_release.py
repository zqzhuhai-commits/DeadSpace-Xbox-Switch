from pathlib import Path
import hashlib, zipfile
root=Path(__file__).resolve().parents[1];out=root/'dist';out.mkdir(exist_ok=True)
path=out/'DeadSpace-Switch-Chinese-v1.0.0.zip'
with zipfile.ZipFile(path,'w',zipfile.ZIP_DEFLATED) as z:
    for name in ['apply_patch.py','patches/nro-zh.json','README.md','LICENSE','VERSION','RELEASE_NOTES.md']:
        z.write(root/name,name)
(out/'SHA256SUMS.txt').write_text(hashlib.sha256(path.read_bytes()).hexdigest()+'  '+path.name+'\n',encoding='ascii')
print(path)
