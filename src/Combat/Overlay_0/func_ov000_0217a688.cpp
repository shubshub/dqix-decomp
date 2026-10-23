#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Resource/CharacterCreationUI.h>

struct Struct_020200c0_5 { char* unknown_0_; char* unknown_4_; unsigned int unknown_8_; };
struct Struct_020465c0 { char unknown_0_[0x20]; Struct_020200c0_5* unknown_20_; };
struct Struct_ov000_02178938 {
    char unknown_0_[0x1c];
    signed char unknown_1c_;
    char unknown_1d_[0xb8 - 0x1d];
    Struct_0201099c_3 unknown_b8_;
#if defined(jpn)
    char unknown_c0_[0x1d94 - 0xc0];
    char unknown_1d94_[8][0x38];
#else
    char unknown1_c0_[0x1d1c - 0xc0];
#endif
    int unknown_1d1c_[8];
    int unknown_1d3c_[8];
};

int CountMatchingValues02175348(void*, int);
StoreStruct* GetGlobalField0x1c020421a0();
int KeyTable_Get(Container020e0310*, int);
int IsField0x118Equal2_ov000_0217542c(void*);
int AppendFrameTag02041c08(char*, int, int, int, int, int);
int AppendCursorTag_02041ea4(char*, int);
int AppendString02042058(char*, const char*);
extern "C" void* __clear(void*, int);
extern "C" void func_02046380(Struct_020465c0*);
extern "C" void* func_020e46c4(void*);
extern "C" GameObject* func_0200fea4(GameState*, int);
extern "C" void func_020e4ce8(Struct_020200c0_5*, GameObject*, int);
extern "C" void func_ov000_0217aa08(char*, char*);
extern "C" void func_020e4f18(Struct_020200c0_5*, Struct_020200c0_5*, int);
extern "C" void func_020465c0(Struct_020465c0*, int, int);
extern "C" void func_02046608(Struct_020465c0*, int, const char*, char*, int, int, int);
extern "C" int func_02041b70(char*, int, const char*);
extern char data_ov000_02184060[];

#if defined(jpn)
extern "C" void func_0203bdf4(char*, char*);
extern "C" void func_02046574(Struct_020465c0*, int, char*);
extern "C" void func_020474a8(Struct_020465c0*, int, const char*, char*);
#endif

// USA: func_ov000_0217a688
extern "C" ARM void func_ov000_0217a688(Struct_ov000_02178938* arg0, void* arg1, int arg2, char* arg3) {
    if (!arg3) return;
    int var0;
    unsigned int var1;
#if defined(jpn)
    bool var2;
#else
    int var2;
#endif
    int var3;
    int var4;
    var1 = -1;
    var0 = 0;
    var2 = 0;
    var4 = 0;
    var3 = arg0->unknown_1c_;
    for (; var4 < arg2; ++var4) {
        int var5 = arg0->unknown_1d1c_[var4];
        if (var1 == var5) continue;
        var1 = var5;
        int var6 = func_ov000_02175348(arg0, var5);
        if (var4 <= var3 && var3 < var4 + var6) var0 = var4;
    }
    Struct_020465c0* var7 = func_020421a0();
#if !defined(jpn)
    GameState* game = GameState::GetInstance();
    const char* separator = (const char*)KeyTable_Get(&self->strings_, 0);
    const char* format = (const char*)KeyTable_Get(&self->strings_, 0x754f);
#endif
    var1 = -1;
#if defined(jpn)
    int var11 = func_ov000_0217542c(arg0);
    if (var11)
#else
    if (func_ov000_0217542c(arg0))
#endif
        func_02041c08(arg3, var0, 8, 5, 5, 5);
    func_02041ea4(arg3, var0);
    for (int var12 = 0; var12 < arg2; ++var12) {
        int var13 = arg0->unknown_1d1c_[var12];
        if (var1 == var13) continue;
        var1 = var13;
        int var14 = func_ov000_02175348(arg0, var13);
        if (!var14) continue;
#if defined(jpn)
        if (separated) AppendString02042058(output, (const char*)KeyTable_Get(&self->strings_, 0));
#else
        if (var2) func_02042058(arg3, var9);
#endif
#if defined(jpn)
        char var15[0x20];
        __clear(var15, sizeof(var15));
        char var16[0x40];
        __clear(var16, sizeof(var16));
#else
        char var16[0x80];
        __clear(var16, sizeof(var16));
#endif
        int var17 = var12;
        if (var12 <= var3 && var3 < var12 + var14) var17 = var3;
#if defined(jpn)
        func_0203bdf4(arg0->unknown_1d94_[var17], var15);
        if (var11 && var0 == var12) {
            char var18[0x20];
            __clear(var18, sizeof(var18));
            memcpy(var18, var15, sizeof(var18));
            memset(var15, 0, sizeof(var15));
            func_ov000_0217aa08(var18, var15);
        }
        func_02046380(store);
        _Z22SetIndexedName02046574P11Obj02046574iPc(store, 0, nameText);
        StoreInArray0x8b0_020465c0(store, 0, members);
        func_020474a8(store, 10, (const char*)KeyTable_Get(&self->strings_, 0x754f), text);
#else
        func_02046380(var7);
        Struct_020200c0_5 var19;
        func_020e46c4(&var19);
        GameObject* var20 = func_0200fea4(var8, arg0->unknown_1d3c_[var17]);
        char var21[0x80];
        __clear(var21, sizeof(var21));
        char var22[0x80];
        __clear(var22, sizeof(var22));
        if (var20) {
            func_020e4ce8(&var19, var20, 1);
            Struct_020200c0_5 var23;
            func_020e4ce8(&var23, var20, 0);
            func_ov000_0217aa08(var19.unknown_0_, var21);
            func_ov000_0217aa08(var19.unknown_4_, var22);
            var19.unknown_0_ = var21;
            var19.unknown_4_ = var22;
            func_020e4f18(&var23, &var19, 2);
            var19.unknown_8_ &= ~0x80000000;
        }
        var7->unknown_20_ = &var19;
        func_020465c0(var7, 0, var14);
        func_02046608(var7, 10, var10, var16, 0x100, 0, 0);
#endif
        func_02041b70(arg3, var12, var16);
        var2 = 1;
    }
#if !defined(jpn)
    func_02042058(arg3, data_ov000_02184060);
#endif
}
