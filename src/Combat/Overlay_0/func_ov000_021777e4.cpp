#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_0201099c_3;

struct Struct_ov000_021777e4_4 {
    char unknown_0_[0xf7c];
    unsigned char unknown_f7c_;
};

struct Struct_ov000_021777e4 {
    char unknown_0_[0x24];
    unsigned char unknown_24_;
    char unknown_25_[0x4c - 0x25];
    int unknown_4c_;
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
    char unknown_0_[0x8b4];
#else
    char unknown1_0_[0x94c];
#endif
    int unknown_94c_;
};

struct Struct_ov000_021777e4_3 {
    char unknown_0_[0x6c];
    signed char unknown_6c_[0xb8 - 0x6c];
    char unknown_b8_[0x958 - 0xb8];
    Struct_ov000_021777e4 unknown_958_[4];
#if defined(jpn)
    char unknown_1b78_[0x1fa3 - 0x958 - 4 * 0x488];
#else
    char unknown_1a78_[0x1d6b - 0x958 - 4 * 0x448];
#endif
    signed char unknown_1d6b_;
    char unknown_1d6c_[0x1d74 - 0x1d6c];
    unsigned char unknown_1d74_[8];
};

int IsField0x118Equal2_ov000_0217542c(void* obj);
int Text_AppendFrameTag(char* dst, int a1, int a2, int a3, int a4, int a5);
int Text_AppendCursorTag(char* dst, int cursor);
MemberInfo_021777e4* GetFieldAt0x150_02053c6c(unsigned char* obj);
extern "C" void __clear(void* dst, int size);
extern "C" int func_ov000_02170c7c(MenuEntry_021777e4* entry);
int FormatCombatLogSuffix02041dd0(char* dst, int value);
#if defined(jpn)
extern "C" void func_0203bdf4(char* arg0, char* arg1);
#define func_0203c248 func_0203bdf4
#else
extern "C" void func_0203c248(char* arg0, char* arg1);
#endif
int Text_AppendNTag(char* dst, int n, const char* name);
int AppendXTag_02041a28(char* dst, int x);
const char* KeyTable_Get(struct Container020e0310* c, int key);
int Text_Append(char* dst, const char* src);
const char* StandardStrings_Get(int key);
#if defined(jpn)
extern char data_ov000_02185160[];
#endif

static inline int inline_ov000_02156cc4_2(int arg0) {
    return arg0 >= 0 && arg0 <= 3;
}

// USA: func_ov000_021777e4
extern "C" ARM void func_ov000_021777e4(Struct_ov000_021777e4_3* arg0, char* arg1) {
    if (arg1 == NULL) return;

    Struct_ov000_021777e4* var0;
    GameState* var1;
    int var2;
    int var3;
    Struct_ov000_021777e4_4* var4;
    unsigned char var5;
    GameObject* var6;
    Struct_ov000_021777e4_2* var7;
    signed char var8;
#if defined(jpn)
    char var9[0x20];
#else
    char var9[0x80];
#endif
    int var10;

    var1 = GameState::GetInstance();
    var2 = arg0->unknown_1d6b_;
    var3 = 0;

    if (IsField0x118Equal2_ov000_0217542c(menu)) {
        Text_AppendFrameTag(dst, cursor, 8, 5, 5, 5);
    }
    Text_AppendCursorTag(dst, cursor);

    party = (PartyInfo_021777e4*)GameState_GetParty(gs);
    for (i = 0; i < party->memberCount; i++) {
        entry = &menu->entries[menu->order[i]];
        member = entry->memberIndex;
        if (!IsPartyIndex(member)) continue;
        if (entry->flags & 2) continue;

        var6 = var1->GetPartyMemberByIndex(var10);
        if (var6 == NULL) return;
        var7 = func_02053c6c((unsigned char*)var6);
        __clear(var9, sizeof(var9));
        var8 = var7->unknown_94c_;

        FormatCombatLogSuffix02041dd0(dst, func_ov000_02170c7c(entry));
        _Z25InvokeGlobalEntry0203c248Pci(entry->nameSlot, name);
        Text_AppendNTag(dst, n, name);
        AppendXTag_02041a28(dst, 0x4e);
        FormatCombatLogSuffix02041dd0(dst, 0);
        Text_Append(dst, KeyTable_Get((struct Container020e0310*)menu->strings, (short)(vocation + 0x753e)));
        Text_Append(dst, KeyTable_Get((struct Container020e0310*)menu->strings, 0));
        menu->choices[n] = member;
        n++;
    }
    arg0->unknown_1d74_[var3] = 4;
#if defined(jpn)
    Text_AppendNTag(dst, n, data_ov000_02185160);
#else
    Text_AppendNTag(dst, n, StandardStrings_Get(0x1a));
#endif
}
