#include <globaldefs.h>
#include "std_library_functions.h"

void* Font_GetCharacter(int idx, int tableIdx);
extern unsigned char data_020e7a50;

// USA: func_02042764
extern "C" ARM void func_02042764(unsigned char* arg0, char* arg1, int arg2) {
    if (!arg1) return;
    if (!arg0) {
        if (arg1) *arg1 = 0;
        return;
    }
    unsigned char var0;
    unsigned char var1 = *((unsigned char*)&data_020e7a50 + 8);
    var0 = *((unsigned char*)&data_020e7a50 + 9);
    unsigned char var2[2];
    for (;;) {
        unsigned char var3 = *arg0;
        if (var3 == 0) {
            *arg1 = 0;
            return;
        }
        local[0] = b8;
        local[1] = b9;
        void* copySrc = local;
        int size = 1;
        void* entry = Font_GetCharacter(ch, n);
        if (entry != NULL) {
            copySrc = *(void**)entry;
            signed char raw = *((signed char*)entry + 5);
            size = (raw << 26) >> 26;
        }
        memcpy(arg1, var4, var5);
        arg0++;
        arg1 += var5;
    }
}
