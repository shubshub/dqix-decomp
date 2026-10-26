#include <globaldefs.h>
#include "std_library_functions.h"
struct Struct_02032e58;

struct Bytes02033b88;
void ClearSubstructFlag0x100_02048c50(unsigned char*);
void GameObject_UnfreezeAnimation(ObjectStatePrefix*);
void ClearFlagBit_020d76d8(unsigned char* base, int bit);
extern "C" int func_ov000_02159f18(void* unused, unsigned long long bits, unsigned int bit);
void GameObject_ForceMotionState(Bytes02033b88* obj, int v);
void GameObject_FreezeAnimation(ObjectStatePrefix*);
void SetSubstructFlag0x100_02048c38(unsigned char*);
void ResetCombatantSlot020d7334(unsigned char*, int);
extern "C" void func_020d6f9c(void* param0, int combatantId, int reason);

#if defined(jpn)
#define data_ov000_021838d8 data_ov000_02184a18
#endif
extern const char data_ov000_021838d8[];

enum Enum_ov000_02162dc4 { Enum_ov000_02162dc4_0, Enum_ov000_02162dc4_1, Enum_ov000_02162dc4_2, Enum_ov000_02162dc4_3, Enum_ov000_02162dc4_4, Enum_ov000_02162dc4_5 };
enum Enum_ov000_02162dc4_B { Enum_ov000_02162dc4_B_0, Enum_ov000_02162dc4_B_1, Enum_ov000_02162dc4_B_2, Enum_ov000_02162dc4_B_3, Enum_ov000_02162dc4_B_4, Enum_ov000_02162dc4_B_5 };

struct Struct_ov000_02162dc4_2 {
    char unknown_0_[4];
    short unknown_4_;
    char unknown_6_[0x14 - 6];
    char* unknown_14_;
    char unknown_18_[0xc1 - 0x18];
    unsigned char unknown_c1_0_ : 4;
    unsigned char unknown_c1_4_ : 4;
};

struct Struct_ov000_02162dc4 {
#if defined(jpn)
    char unknown_0_[0x218];
    void* unknown_29c_;
    char unknown_21c_[0xe20 - 0x21c];
#else
    char unknown1_0_[0x29c];
    void* unknown_29c_;
    char unknown_2a0_[0xea4 - 0x2a0];
#endif
    unsigned char* unknown_ea4_;
};

inline int inline_ov000_02162dc4(Struct_ov000_02162dc4* arg0, unsigned long long arg1, unsigned int arg2, unsigned int arg3,
                       unsigned int arg4, unsigned int arg5) {
    return !func_ov000_02159f18(arg0->unknown_29c_, arg1, arg4) &&
           ((arg2 & arg3) || func_ov000_02159f18(arg0->unknown_29c_, arg1, arg5));
}

inline int inline_ov000_02162dc4_2(int arg0) { return (arg0 >= 0xc0 && arg0 <= 0xc7) ? 1 : 0; }

// USA: func_ov000_02162dc4
extern "C" ARM void func_ov000_02162dc4(Battle02162dc4* self, Combatant02162dc4* lead, Combatant02162dc4* actor,
                                        unsigned int flags, int b1d, int b1e, unsigned long long mask,
                                        unsigned char flag) {
    void* status;
    int allow;
    unsigned char* slots;
    int id;
    if (actor == NULL || (slots = self->slots) == NULL) return;
    id = actor->id;
    ClearSubstructFlag0x100_02048c50((unsigned char*)actor);
    GameObject_UnfreezeAnimation((ObjectStatePrefix*)actor);
    if (flags & 1) {
        ClearFlagBit_020d76d8(slots, id);
        return;
    }
    var0 = arg0->unknown_29c_;
    int var4 = 1;
    if (arg6 == 0 || func_ov000_02159f18(var0, arg6, 0) || func_ov000_02159f18(var0, arg6, 8) ||
        func_ov000_02159f18(var0, arg6, 0x1d) || func_ov000_02159f18(var0, arg6, 0x27)) {
        if (arg2->unknown_14_ != NULL && strcmp(arg2->unknown_14_, data_ov000_021838d8) == 0) {
            var4 = 0;
        } else if (arg4 != 0 && arg7 == 0) {
            var4 = 0;
        }
    }
    Enum_ov000_02162dc4_B var5 = Enum_ov000_02162dc4_B_0;
    Enum_ov000_02162dc4 var6 = Enum_ov000_02162dc4_5;
    if (arg4 != 0 && func_ov000_02159f18(var0, arg6, 0x17)) {
        if (arg4 == 4) var4 = 0;
    }
    var1 = 1;
    if (arg7 != 0 && func_ov000_02159f18(var0, arg6, 0xb) &&
        (func_ov000_02159f18(var0, arg6, 0x17) || func_ov000_02159f18(var0, arg6, 0x18))) {
        var1 = 0;
    }
    if (CheckStatus(self, mask, flags, 8, 0x1a, 0x18) && allow) {
        if (reason == REASON_NONE) reason = REASON_3;
        actor->kind = 0;
        if (notify) GameObject_ForceMotionState((Bytes02033b88*)actor, 0);
        GameObject_FreezeAnimation((ObjectStatePrefix*)actor);
        SetSubstructFlag0x100_02048c38((unsigned char*)actor);
    }
    if (CheckStatus(self, mask, flags, 0x10, 0x10, 0xe)) {
        if (kind == KIND_NONE) kind = KIND_2;
        if (reason == REASON_NONE) reason = REASON_1;
        SetSubstructFlag0x100_02048c38((unsigned char*)actor);
        if (IsMonsterSlot(id)) GameObject_FreezeAnimation((ObjectStatePrefix*)actor);
    } else if (actor->kind == 2) {
        actor->kind = 0;
    }
    if (CheckStatus(self, mask, flags, 0x20, 0x19, 0x17) && allow) {
        if (reason == REASON_NONE) reason = REASON_4;
        actor->kind = kind;
        if (notify) GameObject_ForceMotionState((Bytes02033b88*)actor, 0);
    }
    if (inline_ov000_02162dc4(arg0, arg6, arg3, 2, 0x11, 0xf)) {
        if (var6 == Enum_ov000_02162dc4_5) var6 = Enum_ov000_02162dc4_0;
    }
    if (func_ov000_02159f18(var0, arg6, 0x16)) {
        if (var6 == Enum_ov000_02162dc4_5) var6 = Enum_ov000_02162dc4_2;
    }
    if (arg3 & 0x80000) {
        switch (arg4) {
        case 2:
            if (var5 == Enum_ov000_02162dc4_B_0) var5 = Enum_ov000_02162dc4_B_3;
            break;
        case 3:
            if (var5 == Enum_ov000_02162dc4_B_0) var5 = Enum_ov000_02162dc4_B_4;
            break;
        case 4:
            if (var5 == Enum_ov000_02162dc4_B_0) var5 = Enum_ov000_02162dc4_B_5;
            break;
        case 6:
        case 10:
            if (var6 == Enum_ov000_02162dc4_5) var6 = Enum_ov000_02162dc4_2;
            break;
        }
        if (kind == KIND_NONE) {
            actor->kind = 0;
            if (notify) GameObject_ForceMotionState((Bytes02033b88*)actor, 0);
        }
        func_02048c38((unsigned char*)arg2);
    } else {
        Enum_ov000_02162dc4_B var7 = (Enum_ov000_02162dc4_B)arg2->unknown_c1_4_;
        if ((unsigned int)(var7 - Enum_ov000_02162dc4_B_3) <= Enum_ov000_02162dc4_B_5 - Enum_ov000_02162dc4_B_3) arg2->unknown_c1_4_ = 0;
    }
    if (var6 == Enum_ov000_02162dc4_5) {
        func_020d7334(var2, var3);
    } else {
        func_020d6f9c(var2, var3, var6);
    }
    if (kind != KIND_NONE) actor->kind = kind;
    if (notify) {
        if (lead == NULL) {
            GameObject_ForceMotionState((Bytes02033b88*)actor, 0);
        } else if (lead != actor) {
            GameObject_ForceMotionState((Bytes02033b88*)actor, 0);
        }
    }
}
