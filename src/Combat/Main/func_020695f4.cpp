#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct_020695f4 {
    int unknown_0_;
    char unknown_4_;
    signed char unknown_5_0_ : 6;
    signed char unknown_5_6_ : 1;
    signed char unknown_5_7_ : 1;
    char unknown_6_[2];
};

char* FindUnescapedAngleBracket_020424ac(char* str);
extern "C" int func_02001aec(void* a, void* b, int n);
struct Entry020695f4* Font_FindCharacter(int key, int tableIdx);
void ToUpperBounded_02067f5c(signed char* s, int count);

extern char data_020f0916[];

// USA: func_020695f4
extern "C" ARM void func_020695f4(void* arg0, char* arg1, char* arg2, int arg3) {
    for (;;) {
        char var0 = *arg1;
        if (var0 == 0) {
            break;
        }
        if (c == '<') {
            char* gt = FindUnescapedAngleBracket_020424ac(src);
            if (gt != 0 && func_02001aec(src + 1, data_020f0916, 4) == 0) {
                src = gt + 1;
                struct Entry020695f4* e = Font_FindCharacter((int)src, id);
                if (e != 0 && e->flag5) {
                    int len = e->field5;
                    memcpy(dst, src, len);
                    ToUpperBounded_02067f5c((signed char*)dst, len);
                    src += len;
                    dst += len;
                }
                continue;
            }
        }
        *arg2++ = *arg1++;
    }
    *arg2 = 0;
}
