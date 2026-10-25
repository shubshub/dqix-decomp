#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"
#include "Resource/GameResources.h"

struct Struct_02093b54 {
#if defined(jpn)
    char unknown_0_[0xb];
#else
    char unknown_0_[0x30];
#endif
};

struct Struct_02093ad8 {
    struct Struct_02093b54 unknown_0_;
#if defined(jpn)
    unsigned char unknown_b_;
#endif
    short unknown_30_;
    signed char unknown_32_;
    unsigned char unknown_33_;
};

struct Struct_02094030 {
    struct Struct_02093ad8 unknown_0_[8];
#if defined(jpn)
    char unknown_80_[0x13b - 0x80];
#else
    char unknown_1a0_[0x3cb - 0x1a0];
#endif
    signed char unknown_3cb_;
    char unknown_3cc_[0x3cd - 0x3cc];
    unsigned char unknown_3cd_;
};

extern "C" void func_02093980(char* arg0);
extern "C" void func_02093b54(struct Struct_02093ad8* arg0, struct Struct_02093ad8* arg1);
extern "C" int func_0209372c(int arg0);
extern "C" void* func_0202ae18(void);
extern "C" int func_0202c540(void* arg0);

// USA: func_02094030

extern "C" ARM int func_02094030(struct Struct_02094030* arg0, int arg1, int arg2, int arg3) {
    GameObject* var0 = GameState::GetInstance()->GetPartyMemberByIndex(arg3);
    void* var1 = func_0202ae18();
    GameResources* var2 = GetGameResources();

    if (func_0202c540(var1) != 0) {
        if (arg1 == 10000) return 1;
    }
    if (arg0->unknown_3cb_ >= 8) return 1;

    struct Struct_02093ad8* var3 = &arg0->unknown_0_[arg0->unknown_3cb_];
    func_02093980((char*)var3);

    if (combatant == 0 || requestId == 3) {
        char* name = cachedNames->partyNames[slot];
        if (name[0] == 0) return 1;
        sprintf(request->payload.data, name);
    } else if (combatant != 0) {
        sprintf(request->payload.data, combatant->baseStats_->name);
    }

    var3->unknown_30_ = (short)arg1;
    var3->unknown_32_ = (signed char)arg3;
    if (arg0->unknown_3cb_ <= 0) {
        arg0->unknown_3cd_ |= 1;
    }

    unsigned int var5 = (unsigned int)func_0209372c(var3->unknown_30_);
    arg0->unknown_3cb_++;

    int var6;
    for (var6 = arg0->unknown_3cb_ - 1; var6 >= 2; var6--) {
        if (func_0209372c(arg0->unknown_0_[var6 - 1].unknown_30_) <= var5) break;
        struct Struct_02093ad8 var7;
        func_02093b54(&var7, &arg0->unknown_0_[var6]);
        func_02093b54(&arg0->unknown_0_[var6], &arg0->unknown_0_[var6 - 1]);
        func_02093b54(&arg0->unknown_0_[var6 - 1], &var7);
    }
    return 0;
}
