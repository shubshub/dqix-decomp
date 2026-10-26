#include "Combat/TryApplyElemFields.h"
#include <globaldefs.h>
#include "GameState/GameState.h"

struct StoreStruct {
#if defined(jpn)
    char pad0[0x28];
#else
    char pad0[0x5c];
#endif
    char* textBuffer;
};

struct ElemList {
    char pad0[0xa0];
    short unknown_a0_;
    short unknown_a2_;
    short x;
    short y;
    short unknown_a8_;
    short unknown_aa_;
    short unknown_ac_;
    short unknown_ae_;
    char unknown_b0_;
    unsigned char unknown_b1_;
};

struct BattleMenu {
    char pad0[0x188];
    ElemList elements;
};

struct MenuEntry {
    char pad0[0xe];
    short value;
    char pad10[0x44 - 0x10];
    int x;
    int y;
    int combatantId;
};

struct Struct_0209a678 {
    char pad0[4];
    unsigned int nameId : 12;
    unsigned int pad4 : 20;
    unsigned int unknown_8_0_ : 8;
};

struct Struct_ov000_02179cdc_3 {
#if defined(jpn)
    char pad0[0x8b8];
#else
    char pad0[0x950];
#endif
    int vocation;
};

struct PartyMember {
#if defined(jpn)
    char pad0[0x144];
#else
    char pad0[0x150];
#endif
    Struct_ov000_02179cdc_3* stats;
};

#if defined(jpn)
#define data_ov000_02183510 data_ov000_02184590
#endif
extern unsigned short data_ov000_02183510[];

extern "C" StoreStruct* MessageSystem_GetInstance(void);
extern "C" void* memset(void* dst, int c, unsigned int n);
extern "C" Struct_0209a678* func_ov000_02170cf8(MenuEntry* entry, int key);
extern "C" GameObject* func_0200ff1c(GameState* gs, int idx);
extern "C" void func_020dd040(int id, char* buf);
extern "C" void MessageSystem_FormatText(StoreStruct* store, int kind, char* src, char* dst, int a, int b, int c);
extern "C" void func_02046380(StoreStruct* store);
extern "C" int func_ov000_02153a8c(GameObject* obj);
extern "C" int func_020dd290(void*, unsigned int);
extern "C" void func_020465c0(StoreStruct* store, int index, int value);
extern "C" const char* StandardStrings_Get(int key);
extern "C" void Text_Append(char* dst, const char* src);
struct Struct_0205d81c;
extern "C" void* func_0205d81c(Struct_0205d81c*, int);
#if defined(jpn)
extern "C" void Window_OpenPane(ElemList* list, char* text, int a, int b, int c, int d, int e);
extern "C" void func_020465f0(unsigned char*, int, unsigned char);
extern "C" void func_020465d8(unsigned char*, int, unsigned char);
extern char data_ov000_02185169[];
#else
extern "C" void Window_OpenPane(ElemList* list, char* text, int a, int b, int c, int d, int e, int f);
#endif

// USA: func_ov000_02179cdc
extern "C" ARM void func_ov000_02179cdc(BattleMenu* menu, MenuEntry* entry) {
    char* msg;
    StoreStruct* store;
    if (entry == 0) {
        return;
    }
    char* buf = MessageSystem_GetInstance()->textBuffer;
#if defined(jpn)
    memset(buf, 0, 0x800);
#else
    memset(buf, 0, 0x960);
#endif
    GameState* gs = GameState::GetInstance();
    GameObject* combatant = gs->GetCombatantByIndex(entry->combatantId);
    if (combatant == 0) {
        return;
    }
    PartyMember* member = (PartyMember*)gs->GetPartyMemberByIndex(entry->combatantId);
    if (member == 0) {
        return;
    }
    Struct_0209a678* skill = func_ov000_02170cf8(entry, data_ov000_02183510[member->stats->vocation]);
    GameObject* var7 = func_0200ff1c(gs, entry->combatantId);
    if (var7 == 0) {
        return;
    }
    func_020dd040(skill->nameId, buf);
#if !defined(jpn)
    char text[0x800];
#endif
#if defined(jpn)
    msg = buf;
#else
    MessageSystem_FormatText(MessageSystem_GetInstance(), 10, buf, text, 0x72, 0, 0);
    msg = text;
#endif
    store = MessageSystem_GetInstance();
    func_02046380(store);
    int value;
    if (func_ov000_02153a8c(combatant) != 0) {
        value = 0;
    } else if (skill->unknown_8_0_ >= 0xff) {
        value = entry->value;
    } else {
        value = func_020dd290(var7, skill->unknown_8_0_);
    }
    func_020465c0(store, 0, value);
    func_020465c0(store, 1, entry->value);
#if defined(jpn)
    func_020465f0((unsigned char*)store, 0, 3);
    func_020465f0((unsigned char*)store, 1, 3);
    func_020465d8((unsigned char*)store, 0, 1);
    func_020465d8((unsigned char*)store, 1, 1);
    Text_Append(msg, data_ov000_02185169);
#else
    Text_Append(msg, StandardStrings_Get(0x3ec));
#endif
    ElemList* list = &menu->elements;
    if (func_0205d81c((Struct_0205d81c*)list, 0x16) != 0) {
#if defined(jpn)
        Window_SetPaneText((StructA0205d5d0*)list, 0x16, (int)msg, 1);
#else
        Window_SetPaneText((StructA0205d5d0*)list, 0x16, (int)msg, 1, 0);
#endif
        return;
    }
    int x = entry->x;
    int y = entry->y;
#if defined(jpn)
    list->unknown_a0_ = 0xc;
#else
    list->unknown_a0_ = 0x10;
#endif
#if defined(jpn)
    list->unknown_a2_ = 6;
#else
    list->unknown_a2_ = 0xa;
#endif
#if defined(jpn)
    list->x = (x >> 3) + 0x16;
#else
    list->x = (x >> 3) + 0x10;
#endif
#if defined(jpn)
    list->y = y >> 3;
#else
    list->y = (short)(y >> 3) + 3;
#endif
    list->unknown_a8_ = 7;
#if defined(jpn)
    list->unknown_aa_ = 8;
#else
    list->unknown_aa_ = 6;
#endif
    list->unknown_ac_ = 0xa;
    list->unknown_ae_ = 0xe;
    list->unknown_b1_ = 0x16;
#if defined(jpn)
    Window_OpenPane(list, msg, 1, 0, 0, 1, 0);
#else
    Window_OpenPane(list, msg, 1, 0, 0, 1, 0, 0);
#endif
}
