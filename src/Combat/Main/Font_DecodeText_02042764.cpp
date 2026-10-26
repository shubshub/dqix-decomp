#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void* Font_GetCharacter(int idx, int tableIdx);
extern unsigned char data_020e7a50;

// Main, originally func_02042764 (USA 0x02042764, EUR 0x02042774, JPN 0x02042764)
extern "C" ARM void Font_DecodeText(unsigned char* src, char* dst, int n) {
    if (!dst) return;
    if (!src) {
        if (dst) *dst = 0;
        return;
    }
    unsigned char var0;
    unsigned char b8 = *((unsigned char*)&data_020e7a50 + 8);
    var0 = *((unsigned char*)&data_020e7a50 + 9);
    unsigned char local[2];
    for (;;) {
        unsigned char ch = *src;
        if (ch == 0) {
            *dst = 0;
            return;
        }
        local[0] = b8;
        local[1] = var0;
        void* var4 = local;
        int size = 1;
        void* entry = Font_GetCharacter(ch, n);
        if (entry != NULL) {
            var4 = *(void**)entry;
            signed char raw = *((signed char*)entry + 5);
            size = (raw << 26) >> 26;
        }
        memcpy(dst, var4, size);
        src++;
        dst += size;
    }
}
