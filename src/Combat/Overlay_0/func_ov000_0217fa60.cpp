#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Main/BattleList.h"

struct Struct_ov000_02170fd0;
extern "C" void func_ov000_02175754(void* obj);
extern "C" int func_ov000_021719f8(int* obj);
extern "C" void func_ov000_02170fd0(struct Struct_ov000_02170fd0* obj, int b);

struct Struct_ov000_0217fa60 {
    char pad0[0x24];
    unsigned char field24;
    char unknown_25_[0x4c - 0x25];
    int field4c;
#if defined(jpn)
    char unknown_50_[0xc7 - 0x50];
#else
    char unknown1_50_[0x87 - 0x50];
#endif
    unsigned char active;
    char unknown_88_[0x445 - 0x88];
    unsigned char unknown_445_;
    char unknown_446_[0x448 - 0x446];
};

struct Party_0217fa60 {
    char pad0[0xf78];
    unsigned char ids[4];
    unsigned char count;
};

struct Struct_ov000_0217fa60_3 {
    char pad0[0x6c];
    signed char order[4];
    char unknown_70_[0x17c - 0x70];
    int selected;
    char unknown_180_[0x958 - 0x180];
    struct Struct_ov000_0217fa60 slots[4];
};

static inline struct Struct_ov000_0217fa60* inline_ov000_0217fa60_2(struct Struct_ov000_0217fa60_3* obj, int index) {
    return &obj->slots[index];
}

static inline int inline_ov000_0217fa60(int index) {
    return index >= 0 && index <= 3;
}

// USA: func_ov000_0217fa60
extern "C" ARM void func_ov000_0217fa60(struct Struct_ov000_0217fa60_3* obj) {
    func_ov000_02175754(obj);
    for (unsigned char i = 0; i < 4; i++) {
        inline_ov000_0217fa60_2(obj, obj->order[i])->active = 0;
    }
    struct Party_0217fa60* party = (struct Party_0217fa60*)GameState_GetParty(GameState::GetInstance());
    for (unsigned char i = 0; i < party->count; i++) {
        inline_ov000_0217fa60_2(obj, party->ids[i])->active = 1;
    }
    struct Struct_ov000_0217fa60* slot;
    int first = -1;
    for (int i = 0; i < 4; i++) {
        slot = &obj->slots[obj->order[i]];
        if (slot->field4c < 0) continue;
        if (slot->active == 0) continue;
        if (func_ov000_021719f8((int*)slot)) continue;
        if (slot->unknown_445_ == 0) continue;
        func_ov000_02170fd0((struct Struct_ov000_02170fd0*)slot, 0);
        slot->field24 &= ~4;
        if (first < 0) {
            first = slot->field4c;
        }
    }
    if (inline_ov000_0217fa60(first)) {
        obj->selected = first;
    }
}
