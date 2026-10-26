#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

extern "C" void func_ov000_0216733c(struct BattleScene021663a0* scene);
extern "C" void func_ov000_02166540(struct BattleScene021663a0* scene, int id, int kind, int group);
extern "C" void IntArray_Shuffle(int* ids, int count);
GameObject* GetCombatantWithFlag0x400_0200fea4(GameState* battleStruct, int combatantId);
int CheckSubstructFlag0x80_02048bd0(unsigned char* obj);

struct Struct_ov000_021663a0_3 {
    unsigned short unknown_0_;
    unsigned char unknown_2_[8];
    unsigned char unknown_a_0_ : 4;
    unsigned char unknown_a_4_ : 4;
    char unknown_b_[0x18 - 0xb];
};

struct Struct_ov000_021663a0_4 {
    unsigned char unknown_0_;
    unsigned char unknown_1_0_ : 4;
    unsigned char unknown_1_4_ : 2;
    unsigned char unknown_1_6_ : 2;
    char unknown_2_[2];
    struct Struct_ov000_021663a0_3 unknown_4_[3];
};

struct Struct_ov000_021663a0_5 {
    char unknown_0_[0x81b0];
    struct Struct_ov000_021663a0_4 unknown_81b0_;
    char unknown_81fc_[0x8de0 - 0x81b0 - sizeof(struct Struct_ov000_021663a0_4)];
    int unknown_8de0_[8];
};

struct Struct_ov000_021663a0 {
    char unknown_0_[0x2c];
    int unknown_2c_;
};

struct Struct_ov000_021663a0_2 {
#if defined(jpn)
    char unknown_0_[0x218];
#else
    char unknown1_0_[0x29c];
#endif
    struct Struct_ov000_021663a0_5* unknown_29c_;
    struct Struct_ov000_021663a0* unknown_2a0_;
};

// USA: func_ov000_021663a0
extern "C" ARM void func_ov000_021663a0(struct Struct_ov000_021663a0_2* arg0) {
    GameState* var0 = GameState::GetInstance();
    GetGameResources();
    struct Struct_ov000_021663a0_4* var1 = &arg0->unknown_29c_->unknown_81b0_;
    int var2 = 0;
    func_ov000_0216733c(arg0);
    unsigned char var3[8];
    int var4[8];
    if (arg0->unknown_2a0_->unknown_2c_ != 0) {
        unsigned char* var5 = var3;
        for (int var6 = 0; var6 < 8; var6++) {
            *var5 = arg0->unknown_29c_->unknown_8de0_[var6];
            var5++;
        }
    }
    for (int var7 = 0; var7 < var1->unknown_1_4_; var7++) {
        struct Struct_ov000_021663a0_3* var8 = &var1->unknown_4_[var7];
        for (int var9 = 0; var9 < var8->unknown_a_0_; var9++) {
            int var10 = var8->unknown_2_[var9] + 0xc0;
            func_ov000_02166540(arg0, var10, var8->unknown_0_, var7);
            var4[var2++] = var10;
        }
    }
    if (arg0->unknown_2a0_->unknown_2c_ != 0) {
        unsigned char* var11 = var3;
        for (int var12 = 0; var12 < 8; var12++) {
            arg0->unknown_29c_->unknown_8de0_[var12] = *var11;
            var11++;
        }
    }
    IntArray_Shuffle(ids, count);
    for (int i = 0; i < count; i++) {
        GameObject* c = GetCombatantWithFlag0x400_0200fea4(gs, ids[i]);
        if (c != 0 && scene->config->field_0x2c == 0 && !CheckSubstructFlag0x80_02048bd0((unsigned char*)c)) {
            c->obj3D_.SetInheritedAlpha(0);
            ((unsigned char*)c)[0x183] = 0x10 / count * i + 5;
        }
    }
}
