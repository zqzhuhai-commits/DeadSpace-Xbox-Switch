from pathlib import Path
import base64, hashlib, json, tempfile, unittest, sys
sys.path.insert(0,str(Path(__file__).resolve().parents[1]))
from apply_patch import apply
class PatchTests(unittest.TestCase):
    def test_valid_patch_and_no_overwrite(self):
        with tempfile.TemporaryDirectory() as tmp:
            p=Path(tmp);raw=b'abcdef';changed=b'abXYef';sha=lambda b:hashlib.sha256(b).hexdigest()
            (p/'in').write_bytes(raw)
            manifest={'size':len(raw),'original_sha256':sha(raw),'patched_sha256':sha(changed),'ranges':[{'offset':2,'size':2,'original_sha256':sha(b'cd'),'data_base64':base64.b64encode(b'XY').decode()}]}
            (p/'m.json').write_text(json.dumps(manifest));apply(p/'in',p/'out',p/'m.json');self.assertEqual((p/'out').read_bytes(),changed)
            with self.assertRaises(FileExistsError):apply(p/'in',p/'out',p/'m.json')
            (p/'in').write_bytes(b'wrong!')
            with self.assertRaises(ValueError):apply(p/'in',p/'other',p/'m.json')
            self.assertFalse((p/'other').exists())
    def test_manifest(self):
        m=json.loads((Path(__file__).resolve().parents[1]/'patches/nro-zh.json').read_text())
        self.assertEqual(m['version'],'1.0.0');self.assertEqual(m['size'],51140805)
        for r in m['ranges']:self.assertEqual(len(base64.b64decode(r['data_base64'],validate=True)),r['size'])
