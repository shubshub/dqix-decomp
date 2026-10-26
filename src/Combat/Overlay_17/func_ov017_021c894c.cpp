#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

void* LinkMessageQueue_GetInstance(void);
void* GetField6b0_021b8470(void* obj);
extern "C" void* memset(void* dst, int c, unsigned int n);
extern "C" int func_ov000_0215e9fc(void* obj, short* buf, int max, int flag);
extern "C" int func_ov000_0215eb1c(void* obj, short* buf, int max, int flag);
int GetSubstructByte0x1c_020493a4(unsigned char* obj);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Struct_ov017_021c894c {
    unsigned char unknown_0_[4];
    unsigned char unknown_4_[8];
    unsigned short unknown_c_;
    unsigned char unknown_e_[2];
};

struct Struct_ov017_021c894c_2 {
    unsigned char unknown_0_;
    unsigned char unknown_1_[3];
    struct Struct_ov017_021c894c unknown_4_;
};

// USA: func_ov017_021c894c
extern "C" ARM void func_ov017_021c894c(unsigned short value) {
    GameState* battleStruct = GameState::GetInstance();
    GameResources* res = GetGameResources();
    void* data = LinkMessageQueue_GetInstance();
    void* field = GetField6b0_021b8470(res->unknown_ptr_3718);
    if (field == NULL) {
        return;
    }

    struct Struct_ov017_021c894c_2 var4;
    short var5[8];
    memset(&var4, 0, sizeof(var4));
    struct Struct_ov017_021c894c* var6 = &var4.unknown_4_;
    var4.unknown_0_ = 0x79;
    var6->unknown_c_ = arg0;
    int var7;
    for (var7 = 0; var7 < 4; var7++) {
        var6->unknown_0_[var7] = 0xff;
    }
    int var8;
    for (var8 = 0; var8 < 8; var8++) {
        var6->unknown_4_[var8] = 0xff;
    }

    int var9 = func_ov000_0215e9fc(var3, var5, 8, 0x10);
    int var10;
    for (var10 = 0; var10 < var9; var10++) {
        GameObject* var11 = var0->GetCombatantByIndex(var5[var10]);
        if (var11 != NULL) {
            var6->unknown_0_[var5[var10]] = func_020493a4((unsigned char*)var11);
        }
    }

    var9 = func_ov000_0215eb1c(var3, var5, 8, 0x10);
    int var12;
    for (var12 = 0; var12 < var9; var12++) {
        GameObject* var13 = var0->GetCombatantByIndex(var5[var12]);
        if (var13 != NULL) {
            int var14 = var5[var12] - 0xc0;
            var6->unknown_4_[var14] = func_020493a4((unsigned char*)var13);
        }
    }

    func_0205e330(var2, &var4, 0);
}
