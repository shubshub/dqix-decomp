"""Fail when a hand-named function is missing from NAMING.md.

A hand-named function has an origin comment above its definition (an `#if` may sit between them):
`// Overlay N, originally func_...` or `// Main, originally ...`. Each such function needs its own row,
starting `| name | ...` (name in backticks), in NAMING.md above the Placeholders section.

usage: python tools/naming_check.py [--badge out.json]      exit 0: all listed, 1: something missing (printed)
--badge also writes a shields.io endpoint badge: hand-named functions as a share of every usa function.
"""
import glob, json, os, re, sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
ORIGIN = re.compile(r"^// (?:Overlay \d+|Main), originally ")
DEF = re.compile(r"\bARM\b[^(]*?([\w:]*\w)\s*\(")
# a definition with no ARM marker: a class member (void Zone3D::SwitchZone(...)) or an asm function
DEF_PLAIN = re.compile(r"^(?:asm\s+)?[A-Za-z_][\w\s\*&<>,]*?\b((?:\w+::)?~?\w+)\s*\((?:[^;]*$|[^;{]*\)[^;{]*\{)")

named, bad = {}, []
for path in glob.glob(os.path.join(ROOT, "src/**/*.c*"), recursive=True):
    lines = open(path, encoding="utf-8", errors="replace").read().splitlines()
    for i, line in enumerate(lines):
        if not ORIGIN.match(line):
            continue
        m = next((m for m in map(DEF.search, lines[i + 1:i + 6]) if m), None) or \
            next((m for m in map(DEF_PLAIN.match, lines[i + 1:i + 4]) if m and not m.group(1).startswith("if")), None)
        if m:
            name = m.group(1)
            mm = re.match(r"_ZN(\d+)", name)          # a member defined under its mangled name: _ZN<n>Class<m>MethodE...
            if mm:
                n = int(mm[1]); cls = name[mm.end():mm.end() + n]; rest = name[mm.end() + n:]
                ml = re.match(r"(\d+)", rest)
                if ml:
                    name = f"{cls}::{rest[ml.end():ml.end() + int(ml[1])]}"
            named[name] = os.path.relpath(path, ROOT)
        else:
            bad.append(f"{os.path.relpath(path, ROOT)}:{i + 1}: origin comment not followed by a definition")

decided = open(os.path.join(ROOT, "NAMING.md"), encoding="utf-8").read().split("## Placeholders")[0]
rows = set(re.findall(r"^\| `([\w:]+)` \|", decided, re.M))
missing = [f"not in NAMING.md: {n} ({p})" for n, p in sorted(named.items()) if n not in rows]
for line in bad + missing:
    print(line)

if "--badge" in sys.argv:
    from report_badges import badge
    out = sys.argv[sys.argv.index("--badge") + 1]
    total = sum(open(p, encoding="utf-8").read().count(" kind:function")
                for p in glob.glob(os.path.join(ROOT, "config/usa/arm9/**/symbols.txt"), recursive=True))
    b = badge("functions named", 100 * len(named) / total)
    b["message"] += f" ({len(named):,}/{total:,})"
    os.makedirs(os.path.dirname(os.path.abspath(out)), exist_ok=True)
    json.dump(b, open(out, "w"))
    print(f"{out}: {b['message']}")
sys.exit(1 if bad or missing else 0)
