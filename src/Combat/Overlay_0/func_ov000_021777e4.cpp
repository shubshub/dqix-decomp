#include <globaldefs.h>
#include "GameState/GameState.h"

struct Container020e0310;

struct PartyInfo_021777e4 {
    char pad0[0xf7c];
    unsigned char memberCount;
};

struct Struct_ov000_021777e4 {
    char pad0[0x24];
    unsigned char flags;
    char unknown_25_[0x4c - 0x25];
    int memberIndex;
#if defined(jpn)
    char unknown_50_[0x88 - 0x50];
    char unknown_68_[0x488 - 0x88];
#else
    char unknown1_50_[0x68 - 0x50];
    char unknown_68_[0x448 - 0x68];
#endif
};

struct Struct_ov000_021777e4_2 {
#if defined(jpn)
    char pad0[0x8b4];
#else
    char pad0[0x94c];
#endif
    int vocation;
};

struct Struct_ov000_021777e4_3 {
    char pad0[0x6c];
    signed char order[0xb8 - 0x6c];
    char strings[0x958 - 0xb8];
    Struct_ov000_021777e4 entries[4];
#if defined(jpn)
    char pad[0x1fa3 - 0x958 - 4 * 0x488];
#else
    char pad[0x1d6b - 0x958 - 4 * 0x448];
#endif
    signed char cursor;
    char unknown_1d6c_[0x1d74 - 0x1d6c];
    unsigned char choices[8];
};

extern "C" int func_ov000_0217542c(void* obj);
extern "C" int Text_AppendFrameTag(char* dst, int a1, int a2, int a3, int a4, int a5);
extern "C" int Text_AppendCursorTag(char* dst, int cursor);
extern "C" Struct_ov000_021777e4_2* func_02053c6c(unsigned char* obj);
extern "C" void __clear(void* dst, int size);
extern "C" int func_ov000_02170c7c(Struct_ov000_021777e4* entry);
extern "C" int func_02041dd0(char* dst, int value);
#if defined(jpn)
extern "C" void func_0203bdf4(char* slot, char* out);
#define func_0203c248 func_0203bdf4
#else
extern "C" void func_0203c248(char* slot, char* out);
#endif
extern "C" int Text_AppendNTag(char* dst, int n, const char* name);
extern "C" int func_02041a28(char* dst, int x);
extern "C" const char* KeyTable_Get(struct Container020e0310* c, int key);
extern "C" int Text_Append(char* dst, const char* src);
extern "C" const char* StandardStrings_Get(int key);
#if defined(jpn)
extern char data_ov000_02185160[];
#endif

static inline int inline_ov000_02156cc4_2(int i) {
    return i >= 0 && i <= 3;
}

// USA: func_ov000_021777e4
extern "C" ARM void func_ov000_021777e4(Struct_ov000_021777e4_3* menu, char* dst) {
    if (dst == NULL) return;

    Struct_ov000_021777e4* entry;
    GameState* gs;
    int cursor;
    int n;
    PartyInfo_021777e4* party;
    unsigned char i;
    GameObject* obj;
    Struct_ov000_021777e4_2* info;
    signed char vocation;
#if defined(jpn)
    char name[0x20];
#else
    char name[0x80];
#endif
    int member;

    gs = GameState::GetInstance();
    cursor = menu->cursor;
    n = 0;

    if (func_ov000_0217542c(menu)) {
        Text_AppendFrameTag(dst, cursor, 8, 5, 5, 5);
    }
    Text_AppendCursorTag(dst, cursor);

    party = (PartyInfo_021777e4*)GameState_GetParty(gs);
    for (i = 0; i < party->memberCount; i++) {
        entry = &menu->entries[menu->order[i]];
        member = entry->memberIndex;
        if (!inline_ov000_02156cc4_2(member)) continue;
        if (entry->flags & 2) continue;

        obj = gs->GetPartyMemberByIndex(member);
        if (obj == NULL) return;
        info = func_02053c6c((unsigned char*)obj);
        __clear(name, sizeof(name));
        vocation = info->vocation;

        func_02041dd0(dst, func_ov000_02170c7c(entry));
        func_0203c248(entry->unknown_68_, name);
        Text_AppendNTag(dst, n, name);
        func_02041a28(dst, 0x4e);
        func_02041dd0(dst, 0);
        Text_Append(dst, KeyTable_Get((struct Container020e0310*)menu->strings, (short)(vocation + 0x753e)));
        Text_Append(dst, KeyTable_Get((struct Container020e0310*)menu->strings, 0));
        menu->choices[n] = member;
        n++;
    }
    menu->choices[n] = 4;
#if defined(jpn)
    Text_AppendNTag(dst, n, data_ov000_02185160);
#else
    Text_AppendNTag(dst, n, StandardStrings_Get(0x1a));
#endif
}
