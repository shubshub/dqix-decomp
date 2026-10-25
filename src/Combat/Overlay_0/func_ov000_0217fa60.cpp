#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Main/BattleList.h"

struct Struct_ov000_02170fd0;
extern "C" void func_ov000_02175754(void* arg0);
extern "C" int func_ov000_021719f8(int* arg0);
extern "C" void func_ov000_02170fd0(struct Struct_ov000_02170fd0* arg0, int arg1);

struct Struct_ov000_0217fa60 {
    char unknown_0_[0x24];
    unsigned char unknown_24_;
    char unknown_25_[0x4c - 0x25];
    int unknown_4c_;
#if defined(jpn)
    char unknown_50_[0xc7 - 0x50];
#else
    char unknown1_50_[0x87 - 0x50];
#endif
    unsigned char unknown_87_;
    char unknown_88_[0x445 - 0x88];
    unsigned char unknown_445_;
    char unknown_446_[0x448 - 0x446];
};

struct Struct_ov000_0217fa60_2 {
    char unknown_0_[0xf78];
    unsigned char unknown_f78_[4];
    unsigned char unknown_f7c_;
};

struct Struct_ov000_0217fa60_3 {
    char unknown_0_[0x6c];
    signed char unknown_6c_[4];
    char unknown_70_[0x17c - 0x70];
    int unknown_17c_;
    char unknown_180_[0x958 - 0x180];
    struct Struct_ov000_0217fa60 unknown_958_[4];
};

static inline struct Struct_ov000_0217fa60* inline_ov000_0217fa60_2(struct Struct_ov000_0217fa60_3* arg0, int arg1) {
    return &arg0->unknown_958_[arg1];
}

static inline int inline_ov000_0217fa60(int arg0) {
    return arg0 >= 0 && arg0 <= 3;
}

// USA: func_ov000_0217fa60
extern "C" ARM void func_ov000_0217fa60(struct Struct_ov000_0217fa60_3* arg0) {
    func_ov000_02175754(arg0);
    for (unsigned char var0 = 0; var0 < 4; var0++) {
        inline_ov000_0217fa60_2(arg0, arg0->unknown_6c_[var0])->unknown_87_ = 0;
    }
    struct Party_0217fa60* party = (struct Party_0217fa60*)GameState_GetParty(GameState::GetInstance());
    for (unsigned char i = 0; i < party->count; i++) {
        GetSlot(obj, party->ids[i])->active = 1;
    }
    struct Struct_ov000_0217fa60* var3;
    int var4 = -1;
    for (int var5 = 0; var5 < 4; var5++) {
        var3 = &arg0->unknown_958_[arg0->unknown_6c_[var5]];
        if (var3->unknown_4c_ < 0) continue;
        if (var3->unknown_87_ == 0) continue;
        if (func_ov000_021719f8((int*)var3)) continue;
        if (var3->unknown_445_ == 0) continue;
        func_ov000_02170fd0((struct Struct_ov000_02170fd0*)var3, 0);
        var3->unknown_24_ &= ~4;
        if (var4 < 0) {
            var4 = var3->unknown_4c_;
        }
    }
    if (inline_ov000_0217fa60(var4)) {
        arg0->unknown_17c_ = var4;
    }
}
