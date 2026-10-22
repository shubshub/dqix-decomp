#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"

extern int data_ov023_021fdd6c;
extern "C" void* __clear(void* arg0, int arg1);
extern "C" int func_020426bc(void* arg0, void* arg1, int arg2);
extern "C" int func_020d2ff0(const char* arg0);
extern "C" int func_020424e4(int arg0, int arg1);
extern "C" void func_02042764(void* arg0, void* arg1, int arg2);

struct Struct_0204254c {
    int unknown_0_;
    char unknown_4_;
    signed char unknown_5_0_ : 6;
    signed char unknown_5_6_ : 2;
    char unknown_6_[2];
};
struct Entry0204254c* Font_FindCharacter(int key, int tableIdx);
int AppendXTag_02041a28(char* dst, int x);
void AppendString02042058(char* dst, const char* src);
int AppendYTag_02041a5c(char* dst, int y);

#if defined(jpn)
extern "C" void func_020420e8(char*, int);
extern "C" void func_02042428(char*, int);
struct Struct_02072a68_2;
extern "C" char* func_02072a68(Struct_02072a68_2*, int);
extern "C" int func_02041a90(char*, int, int);
#endif

// USA: func_ov023_021e8cdc
extern "C" ARM void func_ov023_021e8cdc(char* arg0) {
    int var0;
    if (*(int*)(arg0 + 0x5f4) == 0) return;
    char* var1 = *(char**)(arg0 + 0x5d8);

#if defined(jpn)
    char* var2 = (char*)GameState::GetInstance() + 0x3c + 0x5400;
    func_020420e8(var1, 8);
    func_02042428(var1, 12);
    func_02042058(var1, func_02072a68(*(Struct_02072a68_2**)(arg0 + 0x5f4), 0x73));
    var1 += strlen(var1);
    char* var3 = var2 + 8;
    if (*(char**)(arg0 + 0x600)) var3 = *(char**)(arg0 + 0x600);
    for (int var4 = 0; var4 < 3; ++var4) {
        memcpy(var1, var3, 0x26);
        var3 += 0x26;
        var1 += 0x26;
        if (var4 != 2) {
            func_02041a90(var1, 1, var4 * 0x13 + 0x1b);
            var1 += strlen(var1);
            memcpy(var1, func_02072a68(*(Struct_02072a68_2**)(arg0 + 0x5f4), 0x7b), 2);
            var1 += 2;
        }
    }
#else
    char* var5 = (char*)GameState::GetInstance() + 0x29c + 0x5400;

    char var6[0x43a];
    __clear(var6, 0x3a);
    __clear(var6 + 0x3a, 0x400);

    char* var7 = *(char**)(arg0 + 0x600);
    if (var7 != 0) {
        var0 = func_020426bc(var7, var6, 1);
    } else {
        var0 = func_020d2ff0(var5 + 8);
        memcpy(var6, var5 + 8, var0);
    }

    signed char var8 = (signed char)func_020424e4((int)&data_ov023_021fdd6c, 1);
    for (; var0 < 0x39; var0++) var6[var0] = var8;

    func_02042764(var6, var6 + 0x3a, 1);

    char* var9 = var6 + 0x3a;
    int var10 = 0xf;
    int var11 = var10;
    int var12 = 8;
    int var13 = 0;
    for (;;) {
        if (*p == 0) return;
        int step = 1;
        struct Entry0204254c* e = Font_FindCharacter((int)p, step);
        if (e != 0) {
            AppendXTag_02041a28(dst, x);
            AppendString02042058(dst, (const char*)e->val);
            step = e->field5;
        }
        var13++;
        var9 += var14;
        var10 += 0xc;
        if (var13 == 0x13) {
            var12 += 0x13;
            var10 = var11;
            var13 = 0;
            func_02041a5c(var1, var12);
        }
    }
#endif
}
