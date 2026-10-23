#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void __clear(void* arg0, int arg1);
extern "C" int func_02001aec(const void* arg0, const void* arg1, unsigned int arg2);
extern "C" int func_0205a658(void* arg0, void* arg1, int arg2, int arg3);
extern "C" int func_0205a984(void* arg0, void* arg1, int arg2, int arg3);
struct Struct_0205a528;
extern "C" int func_0205aaf8(Struct_0205a528*, void*, int);
extern "C" int func_0205ab78(void* arg0, void* arg1, int arg2);

extern char data_020f0504[];
extern char data_020f0509[];
extern char data_020f050e[];
extern char data_020f0513[];

// Main, originally func_0205a528 (USA 0x0205a528, EUR 0x0205a538, JPN 0x0205b8c4)
extern "C" ARM int SpriteContext_LoadFile(void* obj, void* data, int arg2, int arg3) {
    char magic[5];

    __clear(var0, 5);
    memcpy(var0, arg1, 4);

    if (func_02001aec(var0, data_020f0504, 4) == 0 && func_0205a658(arg0, arg1, arg2, arg3)) {
        return 1;
    } else if (func_02001aec(var0, data_020f0509, 4) == 0) {
        if (func_0205a984(arg0, arg1, arg2, arg3)) {
            return 1;
        }
    } else if (func_02001aec(var0, data_020f050e, 4) == 0) {
        if (func_0205aaf8((Struct_0205a528*)arg0, arg1, arg2)) {
            return 1;
        }
    } else if (func_02001aec(var0, data_020f0513, 4) == 0) {
        if (func_0205ab78(arg0, arg1, arg2)) {
            return 1;
        }
    }
    return 0;
}
