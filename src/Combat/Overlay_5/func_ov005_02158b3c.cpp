#if defined(jpn)
#define LOW_REGION(j, u) (j)
#else
#define LOW_REGION(j, u) (u)
#endif
#include <globaldefs.h>
#include <std_library_functions.h>
#include <GameState/GameState.h>
#include <Combat/Main/BattleList.h>
#include <Resource/GameResources.h>
#include <Resource/CharacterCreationUI.h>

extern "C" void* MessageSystem_GetInstance();
extern "C" void func_02046380(void* global);
extern "C" int* func_ov017_021a193c(int* p);
extern "C" void NameText_InitFromPartyMember(void* obj, int combatantId);
extern "C" void* __clear(void* dst, int count);
extern "C" void NameText_Clear(void* p);
extern "C" short func_ov005_0215a930(void* obj, int index);
extern "C" void func_020dcf7c(int count, void* buf);
extern "C" char* KeyTable_Get(Container020e0310* c, int key);
extern "C" void MessageSystem_FormatText(void* a, unsigned char b, const char* c, char* d, int e, int f, unsigned char g);

struct CombatantTail {
    char pad[LOW_REGION(0x4f8, 0x4fc)];
    int index;
};

struct Struct_ov005_02158b3c_7 {
    char unknown_0_[LOW_REGION(0x144, 0x150)];
    void* unknown_150_;
};

struct Struct_ov005_02158b3c {
    char unknown_0_[0x18];
    short count_;
    char unknown_1a_[0x20 - 0x1a];
};

struct Global_02158b3c {
    char unknown_0_[0x10];
    void* unknown_10_;
    void* unknown_14_;
    void* unknown_18_;
};

struct Struct_ov005_02158b3c_3 {
    void* unknown_0_;
    void* unknown_4_;
    void* unknown_8_;
};

struct Struct_ov005_02158b3c_4 {
    char unknown_0_[0x80];
    char unknown_80_[0x80];
};

struct Struct_ov005_02153ba4 {
    short item;
    signed char count;
    unsigned char equipped;
    void* vramState;
    void* model;
    int x;
    int y;
    int offset;
    short unknown_18_;
};

struct Struct_ov005_02158b3c_5 {
    char unknown_0_[0xdf8];
    Container020e0310 messages;
    char unknown_e00_[LOW_REGION(0x2d08, 0x2d90) - 0xdf8 - sizeof(Container020e0310)];
    Struct_ov005_02153ba4 slots[24];
    char unknown_3030_[0x3dbb - 0x3030];
    signed char selectedSlot;
    unsigned char kind_;
    char unknown_3dbd_[LOW_REGION(0x3d44, 0x3dcc) - LOW_REGION(0x3d35, 0x3dbd)];
    unsigned int flags_;
    char unknown_3dd0_[LOW_REGION(0x3d49, 0x3dd1) - LOW_REGION(0x3d48, 0x3dd0)];
    unsigned char unknown_3dd1_;
};

#if defined(jpn)
extern "C" void func_020de968(int value, char* text);
extern "C" void MessageSystem_SetStringArgument(void*, int, char*);
#endif

// USA: func_ov005_02158b3c
extern "C" ARM int func_ov005_02158b3c(void* object, void* buffer) {
    if (buffer == 0) return 0;
    Global_02158b3c* g = (Global_02158b3c*)MessageSystem_GetInstance();
    func_02046380(g);
    GameState* game = GameState::GetInstance();
#if defined(jpn)
    int id = ((CombatantTail*)func_ov017_021a193c((int*)GetGameResources()->unknown_ptr_array_3700[2]))->index;
#else
    CombatantTail* tail = (CombatantTail*)func_ov017_021a193c((int*)GetGameResources()->unknown_ptr_array_3700[2]);
    int id = tail->index;
#endif
    Struct_ov005_02158b3c_7* combatant = (Struct_ov005_02158b3c_7*)func_0200ff1c(game, id);
    if (combatant == 0) return 0;

#if defined(jpn)
    MessageSystem_SetStringArgument(g, 1, *(char**)((char*)combatant + 0x134));
#else
    Struct_ov005_02158b3c_3 obj;
    NameText_InitFromPartyMember(&obj, id);
    g->unknown_10_ = &obj;
    Struct_ov005_02158b3c_4 bufs;
    __clear(bufs.unknown_80_, 0x80);
    __clear(bufs.unknown_0_, 0x80);
    Struct_ov005_02158b3c_3 s;
    NameText_Clear(&s);
    s.unknown_0_ = bufs.unknown_80_;
    s.unknown_4_ = bufs.unknown_0_;

#endif
    Struct_ov005_02158b3c_5* menu = (Struct_ov005_02158b3c_5*)object;
    if (menu->flags_ & 0x8000) {
        unsigned char pick = func_ov005_0215a930(object, menu->kind_);
        Struct_ov005_02158b3c* e = (Struct_ov005_02158b3c*)((char*)combatant->unknown_150_ + 0x194) + pick;
        if (e) {
            func_02046380(g);
#if defined(jpn)
            char name[0x40];
            __clear(name, 0x40);
            func_020de968(e->count_, name);
            MessageSystem_SetStringArgument(g, 0, name);
#else
            func_020dcf7c(e->count_, &s);
            g->unknown_18_ = &s;
#endif
        }
        menu->flags_ &= ~0x8000;
    } else {
        signed char slot = menu->selectedSlot;
        short value = menu->slots[slot].item;
#if defined(jpn)
        char name[0x40];
        __clear(name, 0x40);
        func_020de968(value, name);
        MessageSystem_SetStringArgument(g, 0, name);
#else
        func_020dcf7c(value, &s);
        g->unknown_18_ = &s;
#endif
    }

    int w = 0xe3;
    unsigned char sel = menu->unknown_3dd1_;
    int v = -1;
    if (sel <= 7) w = 0xb4;
    switch (sel) {
    case 0: break;
    case 2: v = 0x2711; break;
    case 3: v = 0x2712; break;
    case 1: v = 0x2713; break;
    case 4: v = 0x2714; break;
    case 5: v = 0x2715; break;
    case 6: v = 0x2716; break;
    case 7: v = 0x2717; break;
    case 8: v = 0x2af8; break;
    case 9: v = 0x2af9; break;
    case 10: v = 0x2afa; break;
    case 11: v = 0x2afb; break;
    case 12: v = 0x2afc; break;
    case 13: v = 0x2afd; break;
    case 14: v = 0x2afe; break;
    }

    if (v >= 0) {
        sprintf((char*)buffer, KeyTable_Get(&menu->messages, v));
    }
#if !defined(jpn)
    char text[0x800];
    __clear(text, 0x800);
    MessageSystem_FormatText(g, 10, (const char*)buffer, text, w, 0, 0);
    sprintf((char*)buffer, text);

#endif
    if (v >= 0x2af8) {
        if (v <= 0x2afe) return 1;
    }
    return 0;
}
