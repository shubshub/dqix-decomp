#if defined(jpn)
#define LOW_REGION(j, u) (j)
#else
#define LOW_REGION(j, u) (u)
#endif
#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* Zone3D_GetInstance(void);

struct Container020e0310;
extern "C" char* KeyTable_Get(struct Container020e0310* c, int key);

struct Obj0203c108 {
    char pad[0x14];
    short idx;
};
extern "C" void CachedTextLabel_SetText(struct Obj0203c108* obj, char* fmt);

extern "C" int func_ov000_02153a8c(GameObject* obj);
extern "C" int func_020dd290(void* obj, unsigned int value);

struct Struct_ov000_02171458_3 {
    int name;
    unsigned int id : 12;
    unsigned int unknown_5_4_ : 20;
    unsigned int value : 8;
    unsigned int unknown_9_0_ : 24;
};

extern "C" int func_ov000_02171210(struct Struct_ov000_02171458_3* entry, void* menu);
extern "C" struct Struct_ov000_02171458_3* func_ov000_02170cf8(void* menu, int id);
extern "C" void* __clear(void* dst, int count);
#if !defined(jpn)
extern "C" void func_020e4864(int a, char* b, int c, int d, int e, int f);
#endif
extern "C" void func_0206819c(const char* src, char* dst, int flag);

struct Struct_ov000_02171458 {
    char pad0[6];
    short limit;
    signed char unknown_8_[8];
    signed char depth;
    char unknown_11_[0x15 - 0x11];
    unsigned char unknown_15_;
    char pad16[0x18 - 0x16];
    signed char cursor;
    char unknown_19_[0x1e - 0x19];
    unsigned short unknown_1e_;
};

struct Struct_ov000_02171458_2 {
    char pad0[4];
    struct Container020e0310* container;
    struct Struct_ov000_02171458 state;
    char pad28[0x4c - 0x28];
    int combatantId;
    struct Obj0203c108 label;
    char unknown_66_[LOW_REGION(0xdc, 0x9c) - 0x66];
    struct Struct_ov000_02171458_3* entries[1];
};

// USA: func_ov000_02171458
extern "C" ARM void func_ov000_02171458(struct Struct_ov000_02171458_2* menu) {
    Zone3D_GetInstance();
    struct Struct_ov000_02171458* state = &menu->state;
    int cursor = state->cursor;
    if (menu->entries[cursor] == NULL) {
        state->depth++;
        state->unknown_8_[menu->state.depth] = 0xe;
        state->unknown_15_ = 0;
        CachedTextLabel_SetText(&menu->label, KeyTable_Get(menu->container, 5));
        return;
    }
    GameObject* c = func_0200ff1c(GameState::GetInstance(), menu->combatantId);
    int value = menu->entries[cursor]->value;
    if (c != NULL && func_ov000_02153a8c(c)) {
        value = 0;
    } else if (menu->entries[cursor]->id == 0x28) {
        value = 0x14;
    } else if (menu->entries[cursor]->value >= 0xff) {
        value = 1;
    } else {
        value = func_020dd290(c, value);
    }
    if (menu->state.limit < value) {
        state->depth++;
        state->unknown_8_[menu->state.depth] = 0x1a;
        return;
    }
    state->unknown_1e_ = menu->entries[cursor]->id;
    state->depth++;
    state->unknown_8_[state->depth] = func_ov000_02171210(menu->entries[cursor], menu);
    struct Struct_ov000_02171458_3* entry = func_ov000_02170cf8(menu, state->unknown_1e_);
    if (entry == NULL) {
        return;
    }
#if defined(jpn)
    CachedTextLabel_SetText(&menu->label, (char*)entry->name);
#else
    char buf1[0x80];
    __clear(buf1, 0x80);
    char buf2[0x80];
    __clear(buf2, 0x80);
    func_020e4864(entry->name, buf1, 1, 0, 0, 0);
    func_0206819c(buf1, buf2, 0);
    CachedTextLabel_SetText(&menu->label, buf2);
#endif
}
