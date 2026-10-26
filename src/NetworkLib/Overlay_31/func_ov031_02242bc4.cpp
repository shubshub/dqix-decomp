#include <globaldefs.h>

// USA: func_ov031_02242bc4
extern "C" ARM int func_ov031_02242bc4(char* out, int c) {
    if (c == 0x20) {
        out[0] = 0x2b;
        return 1;
    }
    if ((c >= 0x30 && c <= 0x39) || (c >= 0x41 && c <= 0x5a) || (c >= 0x61 && c <= 0x7a)) {
        out[0] = (char)c;
        return 1;
    }
    int hi = (c >> 4) & 0xf;
    int lo = c & 0xf;
    out[0] = 0x25;
    out[1] = (char)(hi < 10 ? hi + 0x30 : hi + 0x37);
    out[2] = (char)(lo < 10 ? lo + 0x30 : lo + 0x37);
    return 3;
}
