#include <globaldefs.h>

extern int Font_characterTables[];

struct Struct_020425e4 { unsigned short key; signed char val; unsigned char pad; };

// Main, originally LookupKeyValue020425e4 (USA 0x020425e4, EUR 0x020425f4; JPN not identified)
extern "C" ARM int Font_GetKerning(int a, int b, int tableIdx) {
    char* t = (char*)Font_characterTables[tableIdx];
    unsigned short key = (a & 0xff) | ((b & 0xff) << 8);
    unsigned int count = *(unsigned int*)(t + 0x8);
    struct Struct_020425e4* p = *(struct Struct_020425e4**)(t + 0xc);
    unsigned int i;
    for (i = 0; i < count; i++) {
        if (p->key == key) return p->val;
        p++;
    }
    return 0;
}
