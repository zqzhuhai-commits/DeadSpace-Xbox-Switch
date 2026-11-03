"""Apply the verified ds1-nx v1.0.0 Chinese text patch. Python 3, no dependencies."""
from pathlib import Path
import argparse, base64, hashlib, json
BASE = Path(__file__).resolve().parent

def apply(source, destination, manifest_path=None):
    source, destination = Path(source), Path(destination)
    manifest = json.loads(Path(manifest_path or BASE / "patches/nro-zh.json").read_text(encoding="utf8"))
    data = bytearray(source.read_bytes())
    sha = lambda value: hashlib.sha256(value).hexdigest()
    if len(data) != manifest["size"] or sha(data) != manifest["original_sha256"]:
        raise ValueError("Original NRO SHA-256 does not match the supported version.")
    for entry in manifest["ranges"]:
        offset, size = entry["offset"], entry["size"]
        replacement = base64.b64decode(entry["data_base64"], validate=True)
        if offset < 0 or offset + size > len(data) or len(replacement) != size:
            raise ValueError("Invalid patch range.")
        if sha(data[offset:offset + size]) != entry["original_sha256"]:
            raise ValueError("Original function checksum mismatch.")
        data[offset:offset + size] = replacement
    if sha(data) != manifest["patched_sha256"]:
        raise ValueError("Patched NRO SHA-256 verification failed.")
    with destination.open("xb") as output:
        output.write(data)
    return manifest["patched_sha256"]

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("source", type=Path)
    parser.add_argument("destination", type=Path)
    args = parser.parse_args()
    try:
        print("OK:", apply(args.source, args.destination))
    except (OSError, ValueError, KeyError) as exc:
        parser.exit(1, str(exc) + "\n")
