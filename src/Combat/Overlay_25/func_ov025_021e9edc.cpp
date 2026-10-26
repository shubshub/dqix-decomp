#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_ov000_02176134;

struct Struct_ov025_021e9edc_5 {
    char pad0[0x20];
    unsigned short id;
    unsigned short value;
    char pad24[0xc];
    Struct_ov025_021e9edc_5* next;
};

struct Struct_ov025_021e9edc {
    char pad0[0x10];
    Struct_ov025_021e9edc_5* head;
};

struct Struct_ov025_021e9edc_2 {
    char pad0[0xc];
    unsigned short value;
};

struct Struct_ov025_021e9edc_3 {
    char pad0[4];
    unsigned short value;
};

struct Struct_ov025_021e9edc_4 {
    char pad0[0x130];
    Struct_ov025_021e9edc_3* view;
};

extern "C" void* func_ov000_02160130(void);
extern "C" Struct_ov025_021e9edc* func_ov000_02160f20(void* work);
extern "C" int func_ov025_021def24(void* work);
extern "C" char* func_ov000_02160f08(void* work);
extern "C" Struct_ov025_021e9edc_2* func_ov025_021dafd0(char* list, int id);
extern "C" void func_ov000_02176134(Struct_ov000_02176134* obj, unsigned short val);

static inline int IsPartyMember(int id) {
    return id >= 0 && id <= 3;
}

// USA: func_ov025_021e9edc
extern "C" ARM void func_ov025_021e9edc(void* p) {
    void* work = func_ov000_02160130();
    Struct_ov025_021e9edc* slot = func_ov000_02160f20(work);
    if (func_ov025_021def24(work) != 0) {
        return;
    }
    GameState* gs = GameState::GetInstance();
    char* list = func_ov000_02160f08(func_ov000_02160130());
    for (Struct_ov025_021e9edc_5* node = slot->head; node != 0; node = node->next) {
        int id = node->id;
        unsigned short value = node->value;
        Struct_ov025_021e9edc_2* entry = func_ov025_021dafd0(list, id);
        Struct_ov025_021e9edc_4* comb = (Struct_ov025_021e9edc_4*)gs->GetCombatantByIndex(id);
        if (comb == 0) {
            continue;
        }
        if (IsPartyMember(id)) {
            value = node->value;
            entry = func_ov025_021dafd0(list, id);
            comb = (Struct_ov025_021e9edc_4*)gs->GetCombatantByIndex(id);
        }
        if (entry != 0 && comb != 0) {
            func_ov000_02176134((Struct_ov000_02176134*)entry, value);
            entry->value = value;
            comb->view->value = value;
        }
    }
}
