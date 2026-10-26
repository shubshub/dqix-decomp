#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void func_ov000_0217228c(void* obj);
extern "C" void* LinkSession_GetInstance(GameState* gs);

struct Struct_ov000_02174b14 {
    char unknown_0_[0x24];
    unsigned char unknown_24_;
    char unknown_25_[0x44 - 0x25];
    int unknown_44_;
    int unknown_48_;
    int unknown_4c_;
#if defined(jpn)
    char unknown_50_[0x488 - 0x50];
#else
    char unknown1_50_[0x448 - 0x50];
#endif
};

struct Struct_ov000_02174b14_2 {
    char unknown_0_[0x6c];
    signed char unknown_6c_[4];
    char unknown_70_[0x958 - 0x70];
    struct Struct_ov000_02174b14 unknown_958_[4];
};

// USA: func_ov000_02174b14
extern "C" ARM void func_ov000_02174b14(struct Obj02174b14* obj) {
    func_ov000_0217228c(obj);
    LinkSession_GetInstance(GameState::GetInstance());
    int any = 0;
    for (int i = 0; i < 4; i++) {
        struct Entry02174b14* entry = &obj->entries[obj->order[i]];
        if (entry->combatantId < 0) {
            continue;
        }
        int var3 = (var2->unknown_24_ & 4) ? 1 : 0;
        var0 = (var0 | var3) ? 1 : 0;
    }
    int var4 = 0;
    if (!var0) {
        var4 = 0x20;
    }
    struct Struct_ov000_02174b14* var5;
    for (int var6 = 0; var6 < 4; var6++) {
        var5 = &arg0->unknown_958_[arg0->unknown_6c_[var6]];
        int var7 = var5->unknown_4c_;
        int var8 = 0;
        if (var7 >= 0) {
            var8 = var7 <= 3;
        }
        if (!var8) {
            continue;
        }
        var5->unknown_44_ = 0;
        var5->unknown_48_ = var4;
        if (var5->unknown_24_ & 4) {
            var4 += 0x48;
        } else {
            var4 += 0x28;
        }
    }
}
