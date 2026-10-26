#include <globaldefs.h>
#include "Resource/ActionDataTables.h"
#include "GameState/GameState.h"

struct Struct_ov024_021e99d8 {
    unsigned int lo : 10;
    unsigned int hi : 10;
    unsigned int rest : 12;
};

struct Struct_ov024_021e99d8_2 {
    char pad0[0x20];
    struct Struct_ov024_021e99d8 range;
};

struct Struct_ov024_021e99d8_3 {
    unsigned int pad0;
    unsigned int id : 12;
    unsigned int unknown_5_4_ : 20;
    char pad8[0x10 - 0x8];
    unsigned int flags10;
    char unknown_14_[0x20 - 0x14];
    struct Struct_ov024_021e99d8 range;
};

struct Struct_ov024_021e99d8_4 {
    char pad0[0x20];
    short id;
};

struct Struct_ov024_021e99d8_5 {
    char pad0[2];
    short command;
    char pad4[0xb - 0x4];
    unsigned char bit0 : 1;
    unsigned char unknown_b_1_ : 1;
    unsigned char rest : 6;
    char unknown_c_[0x10 - 0xc];
    struct Struct_ov024_021e99d8_4* actor;
};

struct Struct_ov024_021e99d8_6 {
    char pad0[0x14];
    int unknown_14_;
};

struct Struct_ov024_021e99d8_7 {
#if defined(jpn)
    char pad0[0x144];
#else
    char pad0[0x150];
#endif
    unsigned char* field150;
};

extern "C" void* func_02079e2c(char* p, int key);
extern "C" unsigned short func_ov024_021da644(int idx, int a, int b);
extern "C" int func_020850d0(unsigned char* p);

static inline int IsPartyMember(int id) {
    return id >= 0 && id <= 3;
}

// USA: func_ov024_021e99d8
extern "C" ARM int func_ov024_021e99d8(struct Struct_ov024_021e99d8_6* ctx, struct Struct_ov024_021e99d8_5* cmd,
                                       struct Struct_ov024_021e99d8_3* action) {
    int id = cmd->actor->id;
    if ((action->flags10 & 0x2000000) && ctx->unknown_14_ <= 0) {
        if (IsPartyMember(id)) {
            cmd->unknown_b_1_ = 1;
            return 0x1ef;
        }
    }
    if (action->id == 0x1f8) {
        struct Struct_ov024_021e99d8_2* entry =
            (struct Struct_ov024_021e99d8_2*)func_02079e2c((char*)func_020797dc(), cmd->command);
        if (!entry) {
            return 0;
        }
        if ((unsigned short)cmd->command == 0x1c || (unsigned short)cmd->command == 0x247) {
            return 0x2e;
        }
        return func_ov024_021da644(id, entry->range.lo, entry->range.hi);
    }
    int result = func_ov024_021da644(id, action->range.lo, action->range.hi);
    if (result == 1 && IsPartyMember(id)) {
        struct Struct_ov024_021e99d8_7* c =
            (struct Struct_ov024_021e99d8_7*)func_0200ff1c(GameState::GetInstance(), id);
        if (c && (action->flags10 & 0x100000)) {
            if (func_020850d0(c->field150)) {
                return 0x10;
            }
        }
    }
    return result;
}
