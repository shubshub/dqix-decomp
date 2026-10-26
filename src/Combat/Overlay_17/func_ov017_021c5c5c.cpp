#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Graphics/Vector.h"
#include "Resource/GameResources.h"

struct Struct_02038598_5;

struct Struct_ov017_021c5c5c {
    char unknown_0_[8];
    unsigned short unknown_8_;
};

struct Struct_ov017_021c5c5c_2 {
    char unknown_0_[2];
    unsigned char unknown_2_;
};

struct Struct_ov017_021c5c5c_3 {
    char unknown_0_;
    unsigned char unknown_1_;
    char unknown_2_;
    unsigned char unknown_3_;
    char unknown_4_[0x64 - 4];
    int unknown_64_;
};

struct Struct_ov017_021c5c5c_4 {
#if defined(jpn)
    char unknown_0_[0x34ec];
#else
    char unknown1_0_[0x36fc];
#endif
    Struct_02038598_5* unknown_36fc_;
    char unknown_3700_[0x3718 - 0x3700];
    Struct_ov017_021c5c5c_2* unknown_3718_;
#if defined(jpn)
    char unknown_350c_[0x38ec - 0x350c];
#else
    char unknown_371c_[0x3b0c - 0x371c];
#endif
    Struct_ov017_021c5c5c_3* unknown_3b0c_;
    char unknown_3b10_[0x42e7 - 0x3b10];
    unsigned char unknown_42e7_;
};

struct Struct_ov017_021c5c5c_5 {
    unsigned int unknown_0_;
};

struct Struct_ov017_021c5c5c_6 {
    Object3D unknown_0_;
    char unknown_ac_[0xc3 - 0xac];
    unsigned char unknown_c3_;
    char unknown_c4_[0x130 - 0xc4];
    Struct_ov017_021c5c5c_5* unknown_130_;
    char unknown_134_[0x17d - 0x134];
    unsigned char unknown_17d_;
#if defined(jpn)
    char unknown_17e_[0x180 - 0x17e];
#else
    char unknown1_17e_[0x18c - 0x17e];
#endif
    unsigned int unknown_18c_;
};

extern "C" Event_021c5c5c* func_ov017_021b8478(Node718_021c5c5c* node);
Combatant_021c5c5c* FindCombatantByField16a_021a278c(void* base, int val);
unsigned char GameObject_IsClimbingLadder(char* obj);
int ListContainsId(ListHead02046b60* list, int id);
void SetFlagAndMaybeNotify_021ab010(void* obj, int flag);
int FieldTaskQueue_IsEmpty(void** list);

// USA: func_ov017_021c5c5c
extern "C" ARM int func_ov017_021c5c5c(int unused, int id) {
    GameState* gs = GameState::GetInstance();
    Ctx_021c5c5c* ctx = (Ctx_021c5c5c*)GetGameResources();
    Combatant_021c5c5c* leader;
    ListHead02046b60* list = ctx->list;
    leader = (Combatant_021c5c5c*)gs->GetLeader();
    if (leader == NULL) {
        return 0;
    }
    if (var1->unknown_42e7_ != 0) {
        return 0;
    }
    if (var1->unknown_3718_->unknown_2_ != 0) {
        Struct_ov017_021c5c5c* var4 = func_ov017_021b8478(var1->unknown_3718_);
        if (var4->unknown_8_ == arg1) {
            return 1;
        }
    }
    if (!(var2->unknown_130_->unknown_0_ & 1) && !(var2->unknown_18c_ & 1) && (int)var2->unknown_c3_ > 0) {
        return 0;
    }

    Struct_ov017_021c5c5c_6* var5 = func_ov017_021a278c(var1, arg1);
    if (var5 == NULL) {
        return 0;
    }
    unsigned char var6 = var5->unknown_17d_ & 0x80;
    if (var6) {
        return 0;
    }
    var5->unknown_17d_ |= 0x80;

    if (var2->unknown_0_.GetField06() != var5->unknown_0_.GetField06()) {
        return 0;
    }
    if (GameObject_IsClimbingLadder((char*)leader) != 0) {
        return 0;
    }

    Vector3fix var7 = var2->unknown_0_.position_;
    Vector3fix var8 = var5->unknown_0_.position_;
    if (fix32abs(var7.y - var8.y) > 0x1800) {
        return 0;
    }
    if (Vector3fix_Distance(&var8, &var7) > 0xf000) {
        return 0;
    }

    Struct_ov017_021c5c5c_3* var9 = var1->unknown_3b0c_;
    if (func_02046b60(var3, 0x1a) && var9->unknown_64_ != 0) {
        return 0;
    }
    if (node->field3 != 0 && node->field1 == 0) {
        SetFlagAndMaybeNotify_021ab010(node, 0);
    } else if (!FieldTaskQueue_IsEmpty((void**)list)) {
        return 0;
    }
    return 1;
}
