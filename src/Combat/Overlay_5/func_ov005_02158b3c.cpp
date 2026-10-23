#if defined(jpn)
#define LOW_REGION(j, u) (j)
#else
#define LOW_REGION(j, u) (u)
#endif
#include <globaldefs.h>
#include <std_library_functions.h>
#include <GameState/GameState.h>
#include <Combat/Main/BattleList.h>
#include <Resource/GameResources.h>
#include <Resource/CharacterCreationUI.h>

void* GetGlobalField0x1c020421a0();
extern "C" void func_02046380(void* global);
int* GetField1c_021a193c(int* p);
void InitObjFromCombatantId020e4bf4(void* obj, int combatantId);
extern "C" void* __clear(void* dst, int count);
void Clear12Bytes020e46c4(void* p);
short GetTableByte0215a930(void* obj, int index);
void DispatchIfCountPositive020dcf7c(int count, void* buf);
char* KeyTable_Get(Container020e0310* c, int key);
extern "C" void func_02046608(void* a, unsigned char b, const char* c, char* d, int e, int f, unsigned char g);

struct Struct_ov005_02158b3c_6 {
    char unknown_0_[LOW_REGION(0x4f8, 0x4fc)];
    int unknown_4fc_;
};

struct Struct_ov005_02158b3c_7 {
    char unknown_0_[LOW_REGION(0x144, 0x150)];
    void* unknown_150_;
};

struct Struct_ov005_02158b3c {
    char unknown_0_[0x18];
    short unknown_18_;
    char unknown_1a_[0x20 - 0x1a];
};

struct Struct_ov005_02158b3c_2 {
    char unknown_0_[0x10];
    void* unknown_10_;
    void* unknown_14_;
    void* unknown_18_;
};

struct Struct_ov005_02158b3c_3 {
    void* unknown_0_;
    void* unknown_4_;
    void* unknown_8_;
};

struct Struct_ov005_02158b3c_4 {
    char unknown_0_[0x80];
    char unknown_80_[0x80];
};

struct Struct_ov005_02153ba4 {
    short unknown_0_;
    signed char unknown_2_;
    unsigned char unknown_3_;
    void* unknown_4_;
    void* unknown_8_;
    int unknown_c_;
    int unknown_10_;
    int unknown_14_;
    short unknown_18_;
};

struct Struct_ov005_02158b3c_5 {
    char unknown_0_[0xdf8];
    Struct_0201099c_3 unknown_df8_;
    char unknown_e00_[LOW_REGION(0x2d08, 0x2d90) - 0xdf8 - sizeof(Struct_0201099c_3)];
    Struct_ov005_02153ba4 unknown_2d90_[24];
    char unknown_3030_[0x3dbb - 0x3030];
    signed char unknown_3dbb_;
    unsigned char unknown_3dbc_;
    char unknown_3dbd_[LOW_REGION(0x3d44, 0x3dcc) - LOW_REGION(0x3d35, 0x3dbd)];
    unsigned int unknown_3dcc_;
    char unknown_3dd0_[LOW_REGION(0x3d49, 0x3dd1) - LOW_REGION(0x3d48, 0x3dd0)];
    unsigned char unknown_3dd1_;
};

#if defined(jpn)
extern "C" void func_020de968(int arg0, char* arg1);
extern "C" void func_02046574(void*, int, char*);
#endif

// USA: func_ov005_02158b3c
extern "C" ARM int func_ov005_02158b3c(void* arg0, void* arg1) {
    if (arg1 == 0) return 0;
    Struct_ov005_02158b3c_2* var0 = (Struct_ov005_02158b3c_2*)func_020421a0();
    func_02046380(var0);
    GameState* var1 = GameState::GetInstance();
#if defined(jpn)
    int var3 = ((Struct_ov005_02158b3c_6*)func_ov017_021a193c((int*)GetGameResources()->unknown_ptr_array_36fc[3]))->unknown_4fc_;
#else
    Struct_ov005_02158b3c_6* var2 = (Struct_ov005_02158b3c_6*)func_ov017_021a193c((int*)GetGameResources()->unknown_ptr_array_36fc[3]);
    int var3 = var2->unknown_4fc_;
#endif
    Struct_ov005_02158b3c_7* var4 = (Struct_ov005_02158b3c_7*)func_0200ff1c(var1, var3);
    if (var4 == 0) return 0;

#if defined(jpn)
    func_02046574(var0, 1, *(char**)((char*)var4 + 0x134));
#else
    Struct_ov005_02158b3c_3 var5;
    func_020e4bf4(&var5, var3);
    var0->unknown_10_ = &var5;
    Struct_ov005_02158b3c_4 var6;
    __clear(var6.unknown_80_, 0x80);
    __clear(var6.unknown_0_, 0x80);
    Struct_ov005_02158b3c_3 var7;
    func_020e46c4(&var7);
    var7.unknown_0_ = var6.unknown_80_;
    var7.unknown_4_ = var6.unknown_0_;

#endif
    Struct_ov005_02158b3c_5* var8 = (Struct_ov005_02158b3c_5*)arg0;
    if (var8->unknown_3dcc_ & 0x8000) {
        unsigned char var9 = func_ov005_0215a930(arg0, var8->unknown_3dbc_);
        Struct_ov005_02158b3c* var10 = (Struct_ov005_02158b3c*)((char*)var4->unknown_150_ + 0x194) + var9;
        if (var10) {
            func_02046380(var0);
#if defined(jpn)
            char var11[0x40];
            __clear(var11, 0x40);
            func_020de968(var10->unknown_18_, var11);
            func_02046574(var0, 0, var11);
#else
            func_020dcf7c(var10->unknown_18_, &var7);
            var0->unknown_18_ = &var7;
#endif
        }
        var8->unknown_3dcc_ &= ~0x8000;
    } else {
        signed char var12 = var8->unknown_3dbb_;
        short var13 = var8->unknown_2d90_[var12].unknown_0_;
#if defined(jpn)
        char var14[0x40];
        __clear(var14, 0x40);
        func_020de968(var13, var14);
        func_02046574(var0, 0, var14);
#else
        func_020dcf7c(var13, &var7);
        var0->unknown_18_ = &var7;
#endif
    }

    int var15 = 0xe3;
    unsigned char var16 = var8->unknown_3dd1_;
    int var17 = -1;
    if (var16 <= 7) var15 = 0xb4;
    switch (var16) {
    case 0: break;
    case 2: var17 = 0x2711; break;
    case 3: var17 = 0x2712; break;
    case 1: var17 = 0x2713; break;
    case 4: var17 = 0x2714; break;
    case 5: var17 = 0x2715; break;
    case 6: var17 = 0x2716; break;
    case 7: var17 = 0x2717; break;
    case 8: var17 = 0x2af8; break;
    case 9: var17 = 0x2af9; break;
    case 10: var17 = 0x2afa; break;
    case 11: var17 = 0x2afb; break;
    case 12: var17 = 0x2afc; break;
    case 13: var17 = 0x2afd; break;
    case 14: var17 = 0x2afe; break;
    }

    if (v >= 0) {
        sprintf((char*)buffer, KeyTable_Get(&menu->messages, v));
    }
#if !defined(jpn)
    char var18[0x800];
    __clear(var18, 0x800);
    func_02046608(var0, 10, (const char*)arg1, var18, var15, 0, 0);
    sprintf((char*)arg1, var18);

#endif
    if (var17 >= 0x2af8) {
        if (var17 <= 0x2afe) return 1;
    }
    return 0;
}
