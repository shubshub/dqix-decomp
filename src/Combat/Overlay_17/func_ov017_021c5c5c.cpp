#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Graphics/Vector.h"
#include "Resource/GameResources.h"

struct ListHead02046b60;

struct Struct_ov017_021c5c5c {
    char pad0[8];
    unsigned short targetId;
};

struct Struct_ov017_021c5c5c_2 {
    char pad0[2];
    unsigned char active;
};

struct Struct_ov017_021c5c5c_3 {
    char pad0;
    unsigned char field1;
    char pad2;
    unsigned char unknown_3_;
    char pad4[0x64 - 4];
    int unknown_64_;
};

struct Struct_ov017_021c5c5c_4 {
#if defined(jpn)
    char pad0[0x34ec];
#else
    char pad0[0x36fc];
#endif
    ListHead02046b60* list;
    char unknown_3700_[0x3718 - 0x3700];
    Struct_ov017_021c5c5c_2* unknown_3718_;
#if defined(jpn)
    char unknown_350c_[0x38ec - 0x350c];
#else
    char unknown_371c_[0x3b0c - 0x371c];
#endif
    Struct_ov017_021c5c5c_3* unknown_3b0c_;
    char unknown_3b10_[0x42e7 - 0x3b10];
    unsigned char busy;
};

struct Struct_ov017_021c5c5c_5 {
    unsigned int flags;
};

struct Combatant_021c5c5c {
    Object3D obj3D;
    char unknown_ac_[0xc3 - 0xac];
    unsigned char fieldC3;
    char unknown_c4_[0x130 - 0xc4];
    Struct_ov017_021c5c5c_5* status;
    char unknown_134_[0x17d - 0x134];
    unsigned char unknown_17d_;
#if defined(jpn)
    char unknown_17e_[0x180 - 0x17e];
#else
    char unknown1_17e_[0x18c - 0x17e];
#endif
    unsigned int unknown_18c_;
};

extern "C" Struct_ov017_021c5c5c* func_ov017_021b8478(Struct_ov017_021c5c5c_2* node);
extern "C" Combatant_021c5c5c* func_ov017_021a278c(void* base, int val);
extern "C" unsigned char GameObject_IsClimbingLadder(char* obj);
extern "C" int func_02046b60(ListHead02046b60* list, int id);
extern "C" void func_ov017_021ab010(void* obj, int flag);
extern "C" int FieldTaskQueue_IsEmpty(void** list);

// USA: func_ov017_021c5c5c
extern "C" ARM int func_ov017_021c5c5c(int unused, int id) {
    GameState* gs = GameState::GetInstance();
    Struct_ov017_021c5c5c_4* ctx = (Struct_ov017_021c5c5c_4*)GetGameResources();
    Combatant_021c5c5c* leader;
    ListHead02046b60* list = ctx->list;
    leader = (Combatant_021c5c5c*)gs->GetLeader();
    if (leader == NULL) {
        return 0;
    }
    if (ctx->busy != 0) {
        return 0;
    }
    if (ctx->unknown_3718_->active != 0) {
        Struct_ov017_021c5c5c* ev = func_ov017_021b8478(ctx->unknown_3718_);
        if (ev->targetId == id) {
            return 1;
        }
    }
    if (!(leader->status->flags & 1) && !(leader->unknown_18c_ & 1) && (int)leader->fieldC3 > 0) {
        return 0;
    }

    Combatant_021c5c5c* other = func_ov017_021a278c(ctx, id);
    if (other == NULL) {
        return 0;
    }
    unsigned char var6 = other->unknown_17d_ & 0x80;
    if (var6) {
        return 0;
    }
    other->unknown_17d_ |= 0x80;

    if (leader->obj3D.GetField06() != other->obj3D.GetField06()) {
        return 0;
    }
    if (GameObject_IsClimbingLadder((char*)leader) != 0) {
        return 0;
    }

    Vector3fix var7 = leader->obj3D.position_;
    Vector3fix var8 = other->obj3D.position_;
    if (fix32abs(var7.y - var8.y) > 0x1800) {
        return 0;
    }
    if (Vector3fix_Distance(&var8, &var7) > 0xf000) {
        return 0;
    }

    Struct_ov017_021c5c5c_3* node = ctx->unknown_3b0c_;
    if (func_02046b60(list, 0x1a) && node->unknown_64_ != 0) {
        return 0;
    }
    if (node->unknown_3_ != 0 && node->field1 == 0) {
        func_ov017_021ab010(node, 0);
    } else if (!FieldTaskQueue_IsEmpty((void**)list)) {
        return 0;
    }
    return 1;
}
