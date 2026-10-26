#if defined(jpn)
enum { Enum_ov017_021c46ec_14132 = 0x3524, Enum_ov017_021c46ec_257 = 0xfd };
#else
enum { Enum_ov017_021c46ec_14132 = 0x3734, Enum_ov017_021c46ec_257 = 0x101 };
#endif

#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_ov017_021c46ec {
    unsigned char unknown_0_[4];
    unsigned short unknown_4_;
    unsigned char unknown_6_[0x10 - 0x6];
    int unknown_10_;
};

struct Struct_ov017_021c46ec_2 {
    unsigned char unknown_0_[3];
    unsigned char unknown_3_;
    unsigned char unknown_4_[0x12 - 0x4];
    unsigned char unknown_12_;
    unsigned char unknown_13_[Enum_ov017_021c46ec_257 - 0x13];
    unsigned char unknown_101_;
};

struct Struct_ov017_021c46ec_3 {
    unsigned char unknown_0_[Enum_ov017_021c46ec_14132];
    struct Struct_ov017_021c46ec_2* unknown_3734_;
};

struct SearchStruct0202c1a4;
extern "C" int LinkSession_IsGuest(struct SearchStruct0202c1a4* search);
extern "C" int LinkSession_IsHostOrSolo(struct SearchStruct0202c1a4* search);
extern "C" void func_020103c8(GameState* battleStruct, int arg);
GameObject* GetCombatantWithFlag0x1000_0200ff58(GameState* battleStruct, int combatantId);
signed char GetSignedByte0x2d0_020546a8(void* obj);
extern "C" void func_ov017_0219dac4(struct Ov021c46ec* ov, int idx, int id);
extern "C" void func_ov017_021c4fa0(int idx, int id);

// USA: func_ov017_021c46ec
extern "C" ARM void func_ov017_021c46ec(int idx, struct Evt021c46ec* evt, GameState* battleStruct, struct Ov021c46ec* ov, struct SearchStruct0202c1a4* search) {
    unsigned short id = evt->id;
    if (LinkSession_IsGuest(search) != 0 && idx == 0) {
        func_020103c8(battleStruct, evt->field10);
    }

    int var1 = 0;
    int var2;
    struct Struct_ov017_021c46ec_2* var3 = arg3->unknown_3734_;
    if (var3->unknown_3_ != 0) {
        var1 = 1;
    }

    GameObject* var4[4];
    GameObject* var5 = arg2->GetPartyMemberByIndex(arg0);
    if (!var1 || var3->unknown_101_ == 0) {
        int var6 = 0;
        var4[var6++] = var5;
        for (var2 = 0; var2 < 4; var2++) {
            GameObject* var7 = func_0200ff58(arg2, var2);
            if (var7 != NULL && arg0 == func_020546a8(var7)) {
                var4[var6++] = var7;
            }
        }

        if (!var1 || var3->unknown_101_ != 0 || var3->unknown_12_ == 0 || arg0 != 0) {
            for (var2 = 0; var2 < var6; var2++) {
                GameObject* var8 = var4[var2];
                if (var8 != NULL) {
                    if (var0 != var8->obj3D_.GetField06() || var0 == 0x170c) {
                        var8->obj3D_.MakeHidden();
                    }
                }
            }
        }
    }

    func_ov017_0219dac4(ov, idx, id);
    if (LinkSession_IsHostOrSolo(search) != 0) {
        func_ov017_021c4fa0(idx, id);
    }
}
