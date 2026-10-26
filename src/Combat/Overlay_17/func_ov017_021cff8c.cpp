#include <globaldefs.h>
#include "GameState/GameState.h"

void* LinkMessageQueue_GetInstance(void);
int GetFieldAt0x150_02053c6c(unsigned char* obj);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Struct_ov017_021cff8c {
    int unknown_0_;
    unsigned char unknown_4_;
    unsigned char unknown_5_;
    short unknown_6_[4];
};

struct Struct_ov017_021cff8c_2 {
    unsigned char unknown_0_;
    unsigned char unknown_1_[3];
    struct Struct_ov017_021cff8c unknown_4_;
};

// USA: func_ov017_021cff8c
extern "C" ARM void func_ov017_021cff8c(int id, int skipCheck) {
    void* mgr = LinkMessageQueue_GetInstance();
    GameState* battle = GameState::GetInstance();
    unsigned char* list = (unsigned char*)GameState_GetParty(battle);

    int var3 = 0;
    if (arg1) {
        var3 = 1;
    } else {
        int var4;
        for (var4 = 0; var4 < var2[0xf7c]; var4++) {
            unsigned char* var5 = var2 + var4;
            if (arg0 == var5[0xf78]) { var3 = 1; break; }
        }
    }
    if (!var3) return;

    GameObject* var6 = func_0200ff1c(var1, arg0);
    if (!var6) return;

    int var7 = func_02053c6c((unsigned char*)var6);
    if (!var7) return;

    short* var8 = (short*)(var7 + 0x454);

    struct Struct_ov017_021cff8c_2 var9;
    struct Struct_ov017_021cff8c* var10 = &var9.unknown_4_;
    var9.unknown_0_ = 0xa8;
    var10->unknown_0_ = arg0;
    var10->unknown_5_ = 4;
    var10->unknown_4_ = 0;
    int var11;
    for (var11 = 0; var11 < var10->unknown_5_; var11++) {
        var10->unknown_6_[var11] = var8[var10->unknown_4_ + var11];
    }
    func_0205e330(var0, &var9, 0);

    unsigned char var12 = var10->unknown_5_;
    int var13 = 0;
    var10->unknown_4_ = var12;
    for (; var13 < var10->unknown_5_; var13++) {
        var10->unknown_6_[var13] = var8[var10->unknown_4_ + var13];
    }
    func_0205e330(var0, &var9, 0);
}
