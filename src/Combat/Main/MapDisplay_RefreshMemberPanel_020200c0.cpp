#include <globaldefs.h>
#include <GameState/GameState.h>
#include "Combat/CombatantRecovery.h"
#include "Resource/GameResources.h"

// StandardStrings keys (strstd_<LG>.nat)
enum {
    StandardString_Dead = 0xe,
    StandardString_Poisoned = 0xf,
    StandardString_Cursed = 0x10,
    StandardString_Hp = 0xc9,
    StandardString_Mp = 0xca,
    StandardString_Level = 0x3f3,   // "Lv. "
};

// CombatantStatus::flags bits, by the word this function shows for each
enum {
    CombatantStatus_Dead = 1,
    CombatantStatus_Poisoned = 2,
    CombatantStatus_Cursed = 4,
};

enum { kCardBytes = 0x800 };   // one member's 64 x 64 card of 4bpp OBJ tiles

// One cell of the canvas (CanvasRect_InitFromSprite fills it from a cell record): its tile offset and rectangle
struct Struct02020520 {
    int offset;
    short x;
    short y;
    short width;
    short height;
};

// A pixel canvas (Canvas_DrawTile's Canvas0205b530): the tile buffer, its cell rectangles and their count
struct S_b20c {
    int pixels;
    int rects;
    unsigned char rectCount;
};

// The 12-byte name argument NameText_InitFromPartyMember fills
struct NameDescriptor {
    char* unknown_0_;
    char* unknown_4_;
    unsigned int flags;
};

// The head of the MessageSystem: the name argument for <tags>, and its 0x800-byte tile scratch buffer at +0x60
struct MessageStore020200c0 {
    NameDescriptor* names;
    char pad4[0x60 - 0x4];
    void* tileBuffer;
};

// A file-local view of PartyMemberData (GameState/PartyMember.h): levels_[vocation_] is the level, and the 13
// bytes after levels_ count each vocation's revocations
struct PartyMemberData {
    unsigned char unk_0[0x186];
    unsigned char revocations_[13];
#if defined(jpn)
    unsigned char unk_193[0x8b8 - 0x193];
#else
    unsigned char unk_193[0x950 - 0x193];
#endif
    int vocation_;
};
// A party member's GameObject, which points at its PartyMemberData
struct PartyMemberObject : GameObject {
#if defined(jpn)
    unsigned char unknown_13c_[0x144 - 0x13c];
#else
    unsigned char unknown1_13c_[0x150 - 0x13c];
#endif
    PartyMemberData* data;
};

struct Obj0205b674;

extern "C" MessageStore020200c0* MessageSystem_GetInstance(void);
extern "C" void* memcpy(void* dst, const void* src, unsigned int n);
extern "C" void GlyphDestinationRect_Clear(struct Struct02020520* s);
extern "C" void CanvasRect_InitFromSprite(struct Struct02020520* layout, int mode, int value);
extern "C" void GlyphDestination_Clear(struct S_b20c* obj);
extern "C" void GlyphDestination_SetPixels(void* obj, int value);
extern "C" void GlyphDestination_SetRects(void* obj, int value, unsigned char flag);
extern "C" void Canvas_FillRect(struct S_b20c* dest, int x, int y, int width, int height, int mode);
extern "C" const char* StandardStrings_Get(int key);
extern "C" void GlyphDestination_DrawText(struct S_b20c* dest, short x, int y, const char* text, int color, int mode);
extern "C" int Font_GetTextWidth(const char* text, int large);
extern "C" int func_ov017_021bdbcc(GameResources* res);
extern "C" void* func_020421b0(int index);
extern "C" void Canvas_DrawTile(struct S_b20c* dest, void* tile, short x, short y, int size, int color);
extern "C" unsigned short GameObject_GetPartyMemberLevel(void* obj);
extern "C" void Canvas_DrawNumber(struct Obj0205b674* obj, short posX, int param2, int param3,
                                         unsigned char param4, unsigned char arg5, unsigned char arg6, unsigned char param7);
extern "C" void __clear(void* buf, int n);
extern "C" int sprintf(char* dst, const char* fmt, ...);
extern "C" void NameText_Clear(void* p);
extern "C" void NameText_InitFromPartyMember(void* obj, int combatantId);
extern "C" void MessageSystem_FormatText(MessageStore020200c0* store, int a, const char* format, char* output, int size, int b, int c);
extern "C" void OS_WaitVBlankIntr(void);
void CleanInvalidateCacheRange(const void* addr, unsigned int size);
extern "C" void LoadToSubObjVRAM(const void* src, unsigned int offset, unsigned int size);
extern char data_020ef580[];

// Main, originally func_020200c0 (USA 0x020200c0, EUR 0x020200d0, JPN 0x0201fde4)
extern "C" ARM void MapDisplay_RefreshMemberPanel(int memberId, int cellRecord) {
    GameState* gameState = GameState::GetInstance();
    int isPartySlot;
    if (memberId >= 0 && memberId <= 3) isPartySlot = 1;
    else isPartySlot = 0;
    if (!isPartySlot || cellRecord == 0) return;
    GameResources* resources = GetGameResources();
    if (resources == NULL || resources->unknown_ptr_36d0 == NULL) return;
    unsigned int vramOffset = (memberId + 1) << 11;
    MessageStore020200c0* messages = MessageSystem_GetInstance();
    void* tiles = messages->tileBuffer;
    if (tiles == NULL) return;
    memcpy(tiles, (void*)0x06600000, kCardBytes);

    Struct02020520 cell;
    GlyphDestinationRect_Clear(&cell);
    CanvasRect_InitFromSprite(&cell, 1, cellRecord);
    S_b20c canvas;
    GlyphDestination_Clear(&canvas);
    GlyphDestination_SetPixels(&canvas, (int)tiles);
    GlyphDestination_SetRects(&canvas, (int)&cell, 1);
    Canvas_FillRect(&canvas, 7, 0x10, 0x17, 0x18, 1);
    GlyphDestination_DrawText(&canvas, 7, 0xe, StandardStrings_Get(StandardString_Hp), 0xf, 0);
    Canvas_FillRect(&canvas, 7, 0x1c, 0x17, 0x24, 1);
    GlyphDestination_DrawText(&canvas, 7, 0x1a, StandardStrings_Get(StandardString_Mp), 0xf, 0);

    PartyMemberObject* member = (PartyMemberObject*)func_0200ff1c(gameState, memberId);
    if (member == NULL) return;
    char* name = member->baseStats_->name;
    GlyphDestination_DrawText(&canvas, (short)((0x40 - Font_GetTextWidth(name, 0)) >> 1), 3, name, 0xf, 0);

    int textColor;
    int statusKey;
    short vocation;
    int col;
    int row;
    unsigned char revocations;
    PartyMemberData* data = member->data;
    revocations = data->revocations_[data->vocation_];
    vocation = data->vocation_;
    if (func_ov017_021bdbcc(resources)) vocation = 0xd;
    if (vocation == 0) vocation = -1;
    if (vocation == 0xd) vocation = 0;
    textColor = 0xf;
    unsigned int statusFlags = member->combatFields_.savedState_130_->flags;
    statusKey = -1;
    if (statusFlags & CombatantStatus_Dead) {
        statusKey = StandardString_Dead;
        textColor = 8;
    } else if (statusFlags & CombatantStatus_Poisoned) {
        statusKey = StandardString_Poisoned;
        textColor = 3;
    } else if (statusFlags & CombatantStatus_Cursed) {
        statusKey = StandardString_Cursed;
    } else {
        int revocationColor = 5;
        if (revocations == 10) revocationColor = 0xd;
        const char* levelLabel = StandardStrings_Get(StandardString_Level);
        int labelWidth = Font_GetTextWidth(levelLabel, 0);
        if (vocation >= 0) {
            char* icon = (char*)func_020421b0((unsigned char)(vocation * 4 + 0x28));
            for (row = 0; row < 2; row++) {
                for (col = 0; col < 2; col++) {
                    Canvas_DrawTile(&canvas, icon, col * 8 + 6, row * 8 + 0x29, 8, 0xf);
                    icon += 0x20;
                }
            }
        }
        GlyphDestination_DrawText(&canvas, 0x20, 0x2b, levelLabel, 0xf, 0);
        Canvas_DrawNumber((Obj0205b674*)&canvas, labelWidth + 0x1b, 0x2b, GameObject_GetPartyMemberLevel(member), 0xf, 2, 1, 0);
        if (revocations != 0) {
            char revocationText[7];
            __clear(revocationText, 7);
            sprintf(revocationText, data_020ef580, revocations);
            GlyphDestination_DrawText(&canvas, 0x13, 0x2b, revocationText, revocationColor, 0);
        }
    }
    if (statusKey >= 0) {
        NameDescriptor nameArgument;
        NameText_Clear(&nameArgument);
        NameText_InitFromPartyMember(&nameArgument, memberId);
        const char* format = StandardStrings_Get(statusKey);
        char text[0x80];
        __clear(text, 0x80);
        messages->names = &nameArgument;
        MessageSystem_FormatText(messages, 10, format, text, 0x100, 0, 0);
        GlyphDestination_DrawText(&canvas, (short)((0x40 - Font_GetTextWidth(text, 0)) >> 1), 0x2b, text, textColor, 0);
    }
    OS_WaitVBlankIntr();
    CleanInvalidateCacheRange(tiles, kCardBytes);
    LoadToSubObjVRAM(tiles, vramOffset, kCardBytes);
}
