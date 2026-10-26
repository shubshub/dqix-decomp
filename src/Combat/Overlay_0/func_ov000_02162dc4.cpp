#include <globaldefs.h>
#include "std_library_functions.h"
struct ObjectStatePrefix;

struct Bytes02033b88;
extern "C" void func_02048c50(unsigned char*);
extern "C" void GameObject_UnfreezeAnimation(ObjectStatePrefix*);
extern "C" void func_020d76d8(unsigned char* base, int bit);
extern "C" int func_ov000_02159f18(void* unused, unsigned long long bits, unsigned int bit);
extern "C" void GameObject_ForceMotionState(Bytes02033b88* obj, int v);
extern "C" void GameObject_FreezeAnimation(ObjectStatePrefix*);
extern "C" void func_02048c38(unsigned char*);
extern "C" void func_020d7334(unsigned char*, int);
extern "C" void func_020d6f9c(void* param0, int combatantId, int arg2);

#if defined(jpn)
#define data_ov000_021838d8 data_ov000_02184a18
#endif
extern const char data_ov000_021838d8[];

enum Enum_ov000_02162dc4 { Enum_ov000_02162dc4_0, Enum_ov000_02162dc4_1, Enum_ov000_02162dc4_2, Enum_ov000_02162dc4_3, Enum_ov000_02162dc4_4, Enum_ov000_02162dc4_5 };
enum Enum_ov000_02162dc4_B { Enum_ov000_02162dc4_B_0, Enum_ov000_02162dc4_B_1, Enum_ov000_02162dc4_B_2, Enum_ov000_02162dc4_B_3, Enum_ov000_02162dc4_B_4, Enum_ov000_02162dc4_B_5 };

struct Struct_ov000_02162dc4_2 {
    char pad0[4];
    short id;
    char pad6[0x14 - 6];
    char* name;
    char pad18[0xc1 - 0x18];
    unsigned char low : 4;
    unsigned char kind : 4;
};

struct Struct_ov000_02162dc4 {
#if defined(jpn)
    char pad0[0x218];
    void* unknown_29c_;
    char unknown_21c_[0xe20 - 0x21c];
#else
    char pad0[0x29c];
    void* unknown_29c_;
    char unknown_2a0_[0xea4 - 0x2a0];
#endif
    unsigned char* slots;
};

inline int inline_ov000_02162dc4(Struct_ov000_02162dc4* self, unsigned long long mask, unsigned int flags, unsigned int arg3,
                       unsigned int arg4, unsigned int arg5) {
    return !func_ov000_02159f18(self->unknown_29c_, mask, arg4) &&
           ((flags & arg3) || func_ov000_02159f18(self->unknown_29c_, mask, arg5));
}

inline int IsMonsterSlot(int id) { return (id >= 0xc0 && id <= 0xc7) ? 1 : 0; }

// USA: func_ov000_02162dc4
extern "C" ARM void func_ov000_02162dc4(Struct_ov000_02162dc4* self, Struct_ov000_02162dc4_2* arg1, Struct_ov000_02162dc4_2* actor,
                                        unsigned int flags, int arg4, int arg5, unsigned long long mask,
                                        unsigned char flag) {
    void* status;
    int var1;
    unsigned char* slots;
    int id;
    if (actor == NULL || (slots = self->slots) == NULL) return;
    id = actor->id;
    func_02048c50((unsigned char*)actor);
    GameObject_UnfreezeAnimation((ObjectStatePrefix*)actor);
    if (flags & 1) {
        func_020d76d8(slots, id);
        return;
    }
    status = self->unknown_29c_;
    int notify = 1;
    if (mask == 0 || func_ov000_02159f18(status, mask, 0) || func_ov000_02159f18(status, mask, 8) ||
        func_ov000_02159f18(status, mask, 0x1d) || func_ov000_02159f18(status, mask, 0x27)) {
        if (actor->name != NULL && strcmp(actor->name, data_ov000_021838d8) == 0) {
            notify = 0;
        } else if (arg4 != 0 && flag == 0) {
            notify = 0;
        }
    }
    Enum_ov000_02162dc4_B kind = Enum_ov000_02162dc4_B_0;
    Enum_ov000_02162dc4 var6 = Enum_ov000_02162dc4_5;
    if (arg4 != 0 && func_ov000_02159f18(status, mask, 0x17)) {
        if (arg4 == 4) notify = 0;
    }
    var1 = 1;
    if (flag != 0 && func_ov000_02159f18(status, mask, 0xb) &&
        (func_ov000_02159f18(status, mask, 0x17) || func_ov000_02159f18(status, mask, 0x18))) {
        var1 = 0;
    }
    if (inline_ov000_02162dc4(self, mask, flags, 8, 0x1a, 0x18) && var1) {
        if (var6 == Enum_ov000_02162dc4_5) var6 = Enum_ov000_02162dc4_3;
        actor->kind = 0;
        if (notify) GameObject_ForceMotionState((Bytes02033b88*)actor, 0);
        GameObject_FreezeAnimation((ObjectStatePrefix*)actor);
        func_02048c38((unsigned char*)actor);
    }
    if (inline_ov000_02162dc4(self, mask, flags, 0x10, 0x10, 0xe)) {
        if (kind == Enum_ov000_02162dc4_B_0) kind = Enum_ov000_02162dc4_B_2;
        if (var6 == Enum_ov000_02162dc4_5) var6 = Enum_ov000_02162dc4_1;
        func_02048c38((unsigned char*)actor);
        if (IsMonsterSlot(id)) GameObject_FreezeAnimation((ObjectStatePrefix*)actor);
    } else if (actor->kind == 2) {
        actor->kind = 0;
    }
    if (inline_ov000_02162dc4(self, mask, flags, 0x20, 0x19, 0x17) && var1) {
        if (var6 == Enum_ov000_02162dc4_5) var6 = Enum_ov000_02162dc4_4;
        actor->kind = kind;
        if (notify) GameObject_ForceMotionState((Bytes02033b88*)actor, 0);
    }
    if (inline_ov000_02162dc4(self, mask, flags, 2, 0x11, 0xf)) {
        if (var6 == Enum_ov000_02162dc4_5) var6 = Enum_ov000_02162dc4_0;
    }
    if (func_ov000_02159f18(status, mask, 0x16)) {
        if (var6 == Enum_ov000_02162dc4_5) var6 = Enum_ov000_02162dc4_2;
    }
    if (flags & 0x80000) {
        switch (arg4) {
        case 2:
            if (kind == Enum_ov000_02162dc4_B_0) kind = Enum_ov000_02162dc4_B_3;
            break;
        case 3:
            if (kind == Enum_ov000_02162dc4_B_0) kind = Enum_ov000_02162dc4_B_4;
            break;
        case 4:
            if (kind == Enum_ov000_02162dc4_B_0) kind = Enum_ov000_02162dc4_B_5;
            break;
        case 6:
        case 10:
            if (var6 == Enum_ov000_02162dc4_5) var6 = Enum_ov000_02162dc4_2;
            break;
        }
        if (kind == Enum_ov000_02162dc4_B_0) {
            actor->kind = 0;
            if (notify) GameObject_ForceMotionState((Bytes02033b88*)actor, 0);
        }
        func_02048c38((unsigned char*)actor);
    } else {
        Enum_ov000_02162dc4_B current = (Enum_ov000_02162dc4_B)actor->kind;
        if ((unsigned int)(current - Enum_ov000_02162dc4_B_3) <= Enum_ov000_02162dc4_B_5 - Enum_ov000_02162dc4_B_3) actor->kind = 0;
    }
    if (var6 == Enum_ov000_02162dc4_5) {
        func_020d7334(slots, id);
    } else {
        func_020d6f9c(slots, id, var6);
    }
    if (kind != Enum_ov000_02162dc4_B_0) actor->kind = kind;
    if (notify) {
        if (arg1 == NULL) {
            GameObject_ForceMotionState((Bytes02033b88*)actor, 0);
        } else if (arg1 != actor) {
            GameObject_ForceMotionState((Bytes02033b88*)actor, 0);
        }
    }
}
