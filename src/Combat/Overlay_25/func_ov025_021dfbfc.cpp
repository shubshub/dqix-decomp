#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_ov025_021dfbfc_4 {
#if defined(jpn)
    char pad0[0x8b4];
#else
    char pad0[0x94c];
#endif
    int status;
};

extern "C" struct Struct_ov025_021dfbfc_4* func_02053c6c(unsigned char* obj);
extern "C" void func_02049458(unsigned char* obj, unsigned char value);

struct Struct_ov025_021dfbfc {
    char pad0[0xe];
    short value;
};

struct Struct_ov025_021dfbfc_2 {
    char pad0[0x20];
    unsigned short id;
    char unknown_22_[0xe];
    struct Struct_ov025_021dfbfc_2* next;
};

struct Struct_ov025_021dfbfc_3 {
    char pad0[0x10];
    struct Struct_ov025_021dfbfc_2* head;
    struct Struct_ov025_021dfbfc* action;
    char pad18[0x10];
};

struct Struct_ov025_021dfbfc_5 {
    char pad0[0x821c];
    struct Struct_ov025_021dfbfc_3 slots[77];
    int unknown_8e24_;
};

struct Struct_ov025_021dfbfc_6 {
#if defined(jpn)
    char pad0[0x218];
#else
    char pad0[0x29c];
#endif
    struct Struct_ov025_021dfbfc_5* party;
};

static inline int inline_ov025_021dfbfc(int id) {
    return id >= 0xc0 && id <= 0xc7;
}

// USA: func_ov025_021dfbfc
extern "C" ARM void func_ov025_021dfbfc(Struct_ov025_021dfbfc_6* obj) {
    GameState* bs = GameState::GetInstance();
    struct Struct_ov025_021dfbfc_5* party = obj->party;
    for (int i = 0; i < party->unknown_8e24_; i++) {
        struct Struct_ov025_021dfbfc_3* slot = &party->slots[i];
        for (struct Struct_ov025_021dfbfc_2* node = slot->head; node != 0; node = node->next) {
            int id = node->id;
            int apply = 0;
            if (inline_ov025_021dfbfc(id)) {
                apply = 1;
            } else {
                GameObject* c = func_0200ff1c(bs, id);
                if (c != 0) {
                    struct Struct_ov025_021dfbfc_4* info = func_02053c6c((unsigned char*)c);
                    if (info != 0 && (signed char)info->status != 5) {
                        apply = 1;
                    }
                }
            }
            if (apply) {
                GameObject* target = bs->GetCombatantByIndex(id);
                if (target != 0 && slot->action != 0) {
                    func_02049458((unsigned char*)target, slot->action->value);
                }
            }
        }
    }
}
