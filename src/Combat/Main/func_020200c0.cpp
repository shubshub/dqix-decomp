#include <globaldefs.h>
#include <GameState/GameState.h>
#include "Combat/CombatantRecovery.h"
#include "Resource/GameResources.h"

struct Struct_020200c0_3 {
    int unknown_0_;
    short unknown_4_;
    short unknown_6_;
    short unknown_8_;
    short unknown_a_;
};

struct Struct_020200c0_4 {
    int unknown_0_;
    int unknown_4_;
    unsigned char unknown_8_;
};

struct Struct_020200c0_5 {
    char* unknown_0_;
    char* unknown_4_;
    unsigned int unknown_8_;
};

struct Struct_020200c0_6 {
    Struct_020200c0_5* unknown_0_;
    char unknown_4_[0x60 - 0x4];
    void* unknown_60_;
};

struct Struct_020200c0_7 {
    unsigned char unknown_0_[0x186];
    unsigned char unknown_186_[13];
#if defined(jpn)
    unsigned char unknown_193_[0x8b8 - 0x193];
#else
    unsigned char unknown1_193_[0x950 - 0x193];
#endif
    int unknown_950_;
};
struct Struct_020200c0_8 : GameObject {
#if defined(jpn)
    unsigned char unknown_13c_[0x144 - 0x13c];
#else
    unsigned char unknown1_13c_[0x150 - 0x13c];
#endif
    Struct_020200c0_7* unknown_150_;
};

struct Struct_020200c0_2;

MessageStore020200c0* MessageSystem_GetInstance(void);
extern "C" void* memcpy(void* dst, const void* src, unsigned int n);
void ClearStruct02020520(struct Struct02020520* s);
extern "C" void func_0205b890(struct Struct02020520* layout, int mode, int value);
void ClearTwoWordsAndByte_0205b20c(struct S_b20c* obj);
void SetField0_0205b220(void* obj, int value);
void SetFieldsAt0x4And0x8_0205b228(void* obj, int value, unsigned char flag);
extern "C" void func_0205b734(struct S_b20c* dest, int x, int y, int width, int height, int mode);
const char* StandardStrings_Get(int key);
extern "C" void func_0205b234(struct S_b20c* dest, short x, int y, const char* text, int color, int mode);
extern "C" int Font_GetTextWidth(const char* text, int large);
extern "C" int func_ov017_021bdbcc(GameResources* res);
void* GetTableEntry020421b0(int index);
extern "C" void func_0205b530(struct S_b20c* dest, void* tile, short x, short y, int size, int color);
unsigned short GetTableValue_0202053c(void* obj);
void PositionAndFormatValueLabel0205b674(struct Obj0205b674* obj, short posX, int param2, int param3,
                                         unsigned char param4, unsigned char param5, unsigned char param6, unsigned char param7);
extern "C" void __clear(void* buf, int n);
extern "C" int sprintf(char* dst, const char* fmt, ...);
void Clear12Bytes020e46c4(void* p);
void NameText_InitFromPartyMember(void* obj, int combatantId);
extern "C" void MessageSystem_FormatText(MessageStore020200c0* store, int a, const char* format, char* output, int size, int b, int c);
void DelayThenSyncBit0_020c9820(void);
void CleanInvalidateCacheRange(const void* addr, unsigned int size);
extern "C" void LoadToSubObjVRAM(const void* src, unsigned int offset, unsigned int size);
extern char data_020ef580[];

// USA: func_020200c0
extern "C" ARM void func_020200c0(int combatantId, int value) {
    GameState* gameState = GameState::GetInstance();
    int isPartySlot;
    if (combatantId >= 0 && combatantId <= 3) isPartySlot = 1;
    else isPartySlot = 0;
    if (!isPartySlot || value == 0) return;
    GameResources* res = GetGameResources();
    if (res == NULL || res->unknown_ptr_36d0 == NULL) return;
    unsigned int offset = (combatantId + 1) << 11;
    MessageStore020200c0* store = MessageSystem_GetInstance();
    void* buffer = store->tileBuffer;
    if (buffer == NULL) return;
    memcpy(buffer, (void*)0x06600000, 0x800);

    Struct02020520 layout;
    ClearStruct02020520(&layout);
    func_0205b890(&layout, 1, value);
    S_b20c dest;
    ClearTwoWordsAndByte_0205b20c(&dest);
    SetField0_0205b220(&dest, (int)buffer);
    SetFieldsAt0x4And0x8_0205b228(&dest, (int)&layout, 1);
    func_0205b734(&dest, 7, 0x10, 0x17, 0x18, 1);
    func_0205b234(&dest, 7, 0xe, StandardStrings_Get(0xc9), 0xf, 0);
    func_0205b734(&dest, 7, 0x1c, 0x17, 0x24, 1);
    func_0205b234(&dest, 7, 0x1a, StandardStrings_Get(0xca), 0xf, 0);

    PartyMember020200c0* member = (PartyMember020200c0*)GetCombatantWithFlag0x100_0200ff1c(gameState, combatantId);
    if (member == NULL) return;
    char* name = member->baseStats_->name;
    func_0205b234(&dest, (short)((0x40 - Font_GetTextWidth(name, 0)) >> 1), 3, name, 0xf, 0);

    int var10;
    int var11;
    short var12;
    int var13;
    int var14;
    unsigned char var15;
    Struct_020200c0_7* var16 = var8->unknown_150_;
    var15 = var16->unknown_186_[var16->unknown_950_];
    var12 = var16->unknown_950_;
    if (func_ov017_021bdbcc(var2)) var12 = 0xd;
    if (var12 == 0) var12 = -1;
    if (var12 == 0xd) var12 = 0;
    var10 = 0xf;
    unsigned int var17 = var8->unknown_ac_.unknown_84_->unknown_0_;
    var11 = -1;
    if (var17 & 1) {
        var11 = 0xe;
        var10 = 8;
    } else if (var17 & 2) {
        var11 = var10;
        var10 = 3;
    } else if (var17 & 4) {
        var11 = 0x10;
    } else {
        int revocationColor = 5;
        if (revocations == 10) revocationColor = 0xd;
        const char* levelLabel = StandardStrings_Get(0x3f3);
        int labelWidth = Font_GetTextWidth(levelLabel, 0);
        if (vocation >= 0) {
            char* tile = (char*)GetTableEntry020421b0((unsigned char)(vocation * 4 + 0x28));
            for (row = 0; row < 2; row++) {
                for (col = 0; col < 2; col++) {
                    func_0205b530(&dest, tile, col * 8 + 6, row * 8 + 0x29, 8, 0xf);
                    tile += 0x20;
                }
            }
        }
        func_0205b234(&var7, 0x20, 0x2b, var19, 0xf, 0);
        func_0205b674((Struct_020200c0_2*)&var7, var20 + 0x1b, 0x2b, func_0202053c(var8), 0xf, 2, 1, 0);
        if (var15 != 0) {
            char var22[7];
            __clear(var22, 7);
            sprintf(var22, data_020ef580, var15);
            func_0205b234(&var7, 0x13, 0x2b, var22, var18, 0);
        }
    }
    if (messageKey >= 0) {
        NameDescriptor names;
        Clear12Bytes020e46c4(&names);
        NameText_InitFromPartyMember(&names, combatantId);
        const char* format = StandardStrings_Get(messageKey);
        char text[0x80];
        __clear(text, 0x80);
        store->names = &names;
        MessageSystem_FormatText(store, 10, format, text, 0x100, 0, 0);
        func_0205b234(&dest, (short)((0x40 - Font_GetTextWidth(text, 0)) >> 1), 0x2b, text, color, 0);
    }
    func_020c9820();
    CleanInvalidateCacheRange(var5, 0x800);
    LoadToSubObjVRAM(var5, var3, 0x800);
}
