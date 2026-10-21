"""Fail when a hand-named function is missing from NAMING.md.

A hand-named function has an origin comment above its definition (an `#if` may sit between them):
`// Overlay N, originally func_...` or `// Main, originally ...`. Each such function needs its own row,
starting `| name | ...` (name in backticks), in NAMING.md above the Placeholders section.

usage: python tools/naming_check.py      exit 0: all listed, 1: something missing (printed)
"""
import glob, os, re, sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
ORIGIN = re.compile(r"^// (?:Overlay \d+|Main), originally ")
DEF = re.compile(r"\bARM\b[^(]*?([\w:]*\w)\s*\(")

named, bad = {}, []
for path in glob.glob(os.path.join(ROOT, "src/**/*.c*"), recursive=True):
    lines = open(path, encoding="utf-8", errors="replace").read().splitlines()
    for i, line in enumerate(lines):
        if not ORIGIN.match(line):
            continue
        m = next((m for m in map(DEF.search, lines[i + 1:i + 6]) if m), None)
        if m:
            named[m.group(1)] = os.path.relpath(path, ROOT)
        else:
            bad.append(f"{os.path.relpath(path, ROOT)}:{i + 1}: origin comment not followed by a definition")

decided = open(os.path.join(ROOT, "NAMING.md"), encoding="utf-8").read().split("## Placeholders")[0]
rows = set(re.findall(r"^\| `([\w:]+)` \|", decided, re.M))
missing = [f"not in NAMING.md: {n} ({p})" for n, p in sorted(named.items()) if n not in rows]
for line in bad + missing:
    print(line)
sys.exit(1 if bad or missing else 0)
