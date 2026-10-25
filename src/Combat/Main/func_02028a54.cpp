#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "Resource/GameResources.h"

struct Struct_020288e0 {
    unsigned short unknown_0_;
    unsigned short unknown_2_0_ : 2;
    unsigned short unknown_2_2_ : 1;
    unsigned short unknown_2_3_ : 13;
    char unknown_4_[0xc];
    SafeAllocator* unknown_10_;
#if !defined(jpn)
    SafeAllocator* unknown_14_;
#endif
    char unknown_18_[0x300];
};

struct Struct_02028a54 {
    GameObject unknown_0_;
    char unknown_13c_[0x5c];
};

extern "C" void func_020289c4(Struct_020288e0*);
extern "C" void func_0200fd48(GameState*, int);
extern "C" void func_0200fd38(GameState*, int, GameObject*);
extern "C" void func_0202ae18();
extern "C" void Zone3D_GetInstance();
extern "C" void func_02076a8c(GameObject*);

// USA: func_02028a54
extern "C" ARM int func_02028a54(Struct_020288e0* arg0, int arg1)
{
    GameState* var0 = GameState::GetInstance();
    func_0202ae18();
    GetGameResources();
    Zone3D_GetInstance();
    state->GetGrottoStruct();
    for (int i = 0; i < 4; ++i) {
        if (id == records[i].id) return 0;
    }
    int var2 = -1;
    for (int var3 = 0; var3 < 4; ++var3) {
        if (!arg0[var3].unknown_2_2_) {
            var2 = var3;
            break;
        }
    }
    if (var2 < 0) return 0;
    Struct_020288e0* var4 = &arg0[var2];
    func_020289c4(var4);
    var4->unknown_2_2_ = 1;
    var4->unknown_0_ = arg1;
    var4->unknown_10_->Reset();
#if !defined(jpn)
    var4->unknown_14_->Reset();
#endif
    Struct_02028a54* var5 = (Struct_02028a54*)var4->unknown_10_->Allocate(0x1320);
    int var6 = 0;
    if (!var5) {
        int var7 = var2 * 12 + 0x70;
        for (; var6 < 12; ++var6) func_0200fd48(var0, var6 + var7);
        return 0;
    }
    int var8 = var2 * 12;
    var8 += 0x70;
    for (; var6 < 12; ++var6) {
        func_02076a8c(&var5[var6].unknown_0_);
        var5[var6].unknown_0_.obj3D_.MakeHidden();
        func_0200fd38(var0, var6 + var8, &var5[var6].unknown_0_);
    }
    return 1;
}
