#include <globaldefs.h>

#include "GameState/GameState.h"
#include "Combat/Overlay_0/GetCombatantByID.h"

#if defined(jpn)
#define data_ov024_021fe748 data_ov024_021fef14
#endif

struct Struct_ov024_021ea4d0;
struct Struct_ov024_021eaa50;
struct Struct_ov024_021eaa50_2;
struct Struct_ov000_02153e78_3;
struct Struct_ov024_021dced0_2;

struct Struct_ov024_021eaa50_3 {
    char pad0[8];
    unsigned int unknown_8_0_ : 8;
    unsigned int p8 : 20;
    unsigned int unknown_b_4_ : 1;
    unsigned int unknown_b_5_ : 3;
    unsigned int unknown_c_;
    unsigned int flags10;
    unsigned int unknown_14_;
    unsigned int unknown_18_0_ : 12;
    unsigned int f18 : 4;
    unsigned int unknown_1a_0_ : 16;
    unsigned int unknown_1c_;
    unsigned int unknown_20_;
    unsigned int unknown_24_;
    unsigned int unknown_28_;
    unsigned int unknown_2c_0_ : 10;
    unsigned int unknown_2d_2_ : 4;
    unsigned int unknown_2d_6_ : 18;
    char p30[2];
    short unknown_32_;
};

struct Struct_ov024_021fe748 {
    short v[8];
};

extern Struct_ov024_021fe748 data_ov024_021fe748;

extern "C" GameObject* func_ov000_021536f8(int, int);
extern "C" int func_ov000_02153e78(Struct_ov000_02153e78_3*, short*, int, int, int);
extern "C" int func_ov000_02159c58(void*, int);
extern "C" int func_ov000_0215e9fc(char*, short*, int, unsigned int);
extern "C" int func_ov000_02159cb4(void*, int);
extern "C" int func_ov024_021eadfc(GameObject*);
extern "C" unsigned int func_020dd290(void*, unsigned int);
extern "C" int func_ov024_021dd010(Struct_ov024_021dced0_2*);
extern "C" int func_ov000_0215fd24(int, int);
extern "C" GameObject* func_0200ff58(GameState*, int);

static inline int IsPartyMember(int id) {
    return id >= 0 && id <= 3;
}

// USA: func_ov024_021eaa50
// KEEP-NAME
extern "C" ARM int func_ov024_021eaa50(Struct_ov024_021ea4d0* arg0, Struct_ov024_021eaa50* src,
                                      Struct_ov024_021eaa50_2* record, int flag4) {
    char* a0 = (char*)arg0;
    char* sb = (char*)src;
    Struct_ov024_021eaa50_3* action = (Struct_ov024_021eaa50_3*)record;
    GameState* gs = GameState::GetInstance();
    short id = *(short*)(*(char**)(sb + 0x10) + 0x20);
    GameObject* self = GetCombatantByID((int)*(char**)(a0 + 0x10), id);
    Struct_ov024_021fe748 tbl = data_ov024_021fe748;

    if (*(unsigned short*)sb == 0x153) {
        GameObject* c = func_ov000_021536f8((int)*(char**)(a0 + 0x10), *(short*)(*(char**)(sb + 0x10) + 0x20));
        if (c == 0) {
            *(unsigned short*)sb = 2;
            *(unsigned char*)(sb + 9) = 0;
            return 2;
        }
        if (func_ov000_02153e78((Struct_ov000_02153e78_3*)*(char**)(a0 + 0x10), tbl.v, 8, *((unsigned char*)c + 0x17c), 1) != 8) {
            *(unsigned short*)sb = 2;
            *(unsigned char*)(sb + 9) = 0;
            return 2;
        }
    }
    if (*(unsigned short*)sb == 0x31a) {
        GameObject* c = func_ov000_021536f8((int)*(char**)(a0 + 0x10), *(short*)(*(char**)(sb + 0x10) + 0x20));
        if (c == 0) {
            *(unsigned short*)sb = 2;
            *(unsigned char*)(sb + 9) = 0;
            return 2;
        }
        if (func_ov000_02153e78((Struct_ov000_02153e78_3*)*(char**)(a0 + 0x10), tbl.v, 8, *((unsigned char*)c + 0x17c), 1) != 3) {
            *(unsigned short*)sb = 2;
            *(unsigned char*)(sb + 9) = 0;
            return 2;
        }
    }
    if (func_ov000_02159c58(*(char**)(a0 + 0x10), *(unsigned short*)sb)) {
        if (func_ov000_0215e9fc(*(char**)(a0 + 0x10), tbl.v, 8, 1) != 4) {
            *(unsigned char*)(sb + 9) = 0;
            *(unsigned short*)sb = (unsigned short)func_ov000_02159cb4(*(char**)(a0 + 0x10), *(short*)(*(char**)(sb + 0x10) + 0x20));
            return *(unsigned short*)sb;
        }
    }

    int below = 0;
    if (!func_ov024_021eadfc(self) && flag4 == 0 && !action->unknown_b_4_) {
        short v6 = (short)action->unknown_8_0_;
        if (IsPartyMember(id)) {
            v6 = (short)func_020dd290(
                func_0200ff1c(gs, id), (unsigned int)v6);
        }
        if (action->unknown_8_0_ < 0xff) {
            if (self->currentStats_->primaryStats.currMP < v6) below = 1;
        } else {
            if (self->currentStats_->primaryStats.currMP == 0) below = 1;
        }
    }
    if (below) {
        int var11 = 0x1f8;
        if (action->f18 == 1) var11 = 0x3a9;
        unsigned short v = *(unsigned short*)sb;
        *(unsigned short*)(sb + 2) = v;
        *(unsigned char*)(sb + 9) = 0;
        *(unsigned short*)sb = var11;
        if (action->flags10 & 1) *((unsigned char*)self->currentStats_ + 0x3c) |= 8;
        else *((unsigned char*)self->currentStats_ + 0x3c) |= 0x20;
        return var11;
    }

    if ((action->flags10 & 1) && func_ov024_021dd010((Struct_ov024_021dced0_2*)self)) {
        unsigned short v = *(unsigned short*)sb;
        int var14 = 0x392;
        *(unsigned short*)(sb + 2) = v;
        *(unsigned char*)(sb + 9) = 0;
        *(unsigned short*)sb = var14;
        *((unsigned char*)self->currentStats_ + 0x3c) |= 8;
        return var14;
    }

    if (action->unknown_2d_2_ == 6 && IsPartyMember(id)) {
        int found = 0;
        if (func_ov000_0215fd24((int)*(char**)(a0 + 0x10), id)) {
            void* arr = GameState_GetParty(gs);
            if (*(unsigned int*)((char*)arr + 0xf6c) < action->unknown_32_) found = 1;
        } else {
            GameObject* p = func_0200ff58(gs, id);
            if (p != 0) {
                if (((int*)(*(char**)(a0 + 0x10) + 0x8e84))[0] < action->unknown_32_) found = 1;
            } else {
                if (((int*)(*(char**)(a0 + 0x10) + 0x8e84))[id] < action->unknown_32_) found = 1;
            }
        }
        if (found) {
            unsigned short v = *(unsigned short*)sb;
            int var19 = 0x3a7;
            *(unsigned short*)(sb + 2) = v;
            *(unsigned char*)(sb + 9) = 0;
            *(unsigned short*)sb = var19;
            return var19;
        }
    }
    return *(unsigned short*)sb;
}
