#include <globaldefs.h>
#if defined(jpn)
#include "Resource/MessageSystem.h"
extern "C" int func_0206cc50(void*, unsigned short*);
extern "C" int func_02069408(void*, unsigned short);
extern "C" int func_020694a0(void*, unsigned short);

// JPN: func_0206cdcc
extern "C" ARM void func_0206cdcc(void* arg0, int* arg1, int* arg2) {
    Struct_02021b84* var0 = static_cast<Struct_02021b84*>(arg0);
    unsigned short* var1 = static_cast<unsigned short*>(var0->unknown_1c_);
    int var2 = var0->unknown1_40_;
    int var3 = var0->unknown_78_;
    int var4;
    int var5;
    unsigned short* var6 = var1 + var2;
    unsigned short* var7 = var1 + var3;
    var4 = var0->unknown_860_;
    var5 = 0;
    arg1[var5] = var4 - (func_0206cc50(var0, var6) >> 1);
    arg2[var5] = 0;
    var6++;
    var5++;
    while (var6 != var7) {
        if (func_02069408(var0, *var6)) return;
        if (func_020694a0(var0, *var6)) {
            var6++;
            arg1[var5] = var4 - (func_0206cc50(var0, var6) >> 1);
            arg2[var5] = 0;
            var5++;
        }
        var6++;
    }
}
#else

extern "C" int func_0206b37c(void* arg0, void* arg1);
extern "C" int func_0206ac6c(void* arg0, void* arg1);
extern "C" bool func_02067a9c(void* arg0, void* arg1);
extern "C" int func_02067ad8(int arg0, void* arg1);
extern "C" int func_0206abf8(void* arg0, void* arg1);

struct Struct_0204254c {
    int unknown_0_;
    char unknown_4_;
    signed char unknown_5_0_ : 6;
    signed char unknown_5_6_ : 2;
    char unknown_6_[2];
};

struct Entry0204254c* Font_FindCharacter(int key, int tableIdx);

// USA: func_0206b528
extern "C" ARM int func_0206b528(unsigned char* arg0, int* arg1, int* arg2) {
    unsigned char* var0 = *(unsigned char**)(arg0 + 0x50);
    int var1 = *(int*)(arg0 + 0x84);
    int var2 = *(int*)(arg0 + 0x990);
    int var3;
    unsigned char* var4 = var0 + var1;

    arg1[0] = var2 - (func_0206b37c(arg0, var4) >> 1);
    arg2[0] = 0;
    var3 = 1;

    for (;;) {
        signed char var5 = *(signed char*)var4;
        if (var5 == 0) return var5;
        if (func_0206ac6c(arg0, var4)) {
            bool var6 = func_02067a9c(arg0, var4);
            if (var6) return var6;
            if (func_02067ad8((int)arg0, var4)) {
                var4 += 2;
                arg1[var3] = var2 - (func_0206b37c(arg0, var4) >> 1);
                arg2[var3] = 0;
                var3++;
            } else {
                var4 = (var4 + 2) + func_0206abf8(arg0, var4) * 2;
                goto again;
            }
        } else {
            int adv = 1;
            struct Entry0204254c* e = Font_FindCharacter((int)p, (obj + 0x1000)[0x9dc]);
            if (e) adv = e->field5;
            p += adv;
        }
    again: ;
    }
}

#endif
