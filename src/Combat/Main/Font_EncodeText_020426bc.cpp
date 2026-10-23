#include <globaldefs.h>

struct Entry020426bc {
    int val;
    char pad4;
    signed char field5 : 6;
    signed char unused2 : 2;
    char pad6[2];
};

struct Entry020426bc* Font_FindCharacter(int key, int tableIdx);
int Font_FindCharacterIndex(int key, int tableIdx);

// Main, originally func_020426bc (USA 0x020426bc, EUR 0x020426cc; JPN not identified)
extern "C" ARM int Font_EncodeText(char* str, unsigned char* out, int id) {
    if (out == 0) return 0;
    if (str == 0) {
        if (out != 0) *out = 0;
        return 0;
    }
    int count = 0;
    for (;;) {
        signed char c = *str;
        if (c == 0) {
            *out = 0;
            break;
        }
        int step = 1;
        int code = 0;
        struct Entry020426bc* e = Font_FindCharacter((int)str, id);
        if (e != 0) {
            step = e->field5;
        }
        if (c == 0x20) code = 0xff;
        int idx = Font_FindCharacterIndex((int)str, id);
        if (idx > 0) code = idx & 0xff;
        *out++ = (unsigned char)code;
        str += step;
        count++;
    }
    return count;
}
