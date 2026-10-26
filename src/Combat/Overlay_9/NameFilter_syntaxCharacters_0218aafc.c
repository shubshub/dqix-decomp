// The 15 characters NameFilter_MatchPattern gives a meaning to, looked up in font 1 by NameFilter_Reset:
// letter class, group start and end, repeat start and end, negate, range, wildcard, then $ / @ & , <c/> '.
// Originally NameFilter_syntaxCharacters (USA/EUR 0x0218aafc; jpn has no name filter).
const char NameFilter_syntaxCharacters[15][5] = {
    ":", "[", "]", "{", "}", "^", "-", ".", "$", "/", "@", "&", ",", "<c/>", "'",
};
