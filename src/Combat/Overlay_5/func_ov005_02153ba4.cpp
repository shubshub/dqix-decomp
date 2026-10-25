#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Memory/SafeAllocator.h>
#include <std_library_functions.h>
#include "Resource/GameResources.h"

#if defined(jpn)
#define REGION(j,u) (j)
#else
#define REGION(j,u) (u)
#endif

#define REG_DISPCNT (*(volatile unsigned int*)0x04000000)

struct S_e830;
struct Struct020dfc40;
struct BackgroundGraphics;
struct InitTarget0205cfd4;
struct Obj021e1318;
struct GridCursor;
struct Field150Holder02052df8;

struct Struct_ov005_02155d6c_2 {
    char unknown_0_[0x88];
};

struct Struct_ov005_02153ba4 {
    short unknown_0_;
    signed char unknown_2_;
    unsigned char unknown_3_;
    void* unknown_4_;
    Struct_ov005_02155d6c_2* unknown_8_;
    int unknown_c_;
    int unknown_10_;
    int unknown_14_;
    short unknown_18_;
};

struct Struct_ov005_02153ba4_2 {
    char unknown_0_[REGION(0x4e4,0x4e8)];
    int unknown_4e8_;
    int unknown_4ec_[4];
};

struct Struct_ov005_02153954 {
    SafeAllocator unknown_0_;
    SafeAllocator unknown_14_;
    SafeAllocator unknown_28_[8];
    SafeAllocator unknown_c8_[16];
    SafeAllocator unknown_208_;
    SafeAllocator unknown_21c_;
    SafeAllocator unknown_230_;
    SafeAllocator unknown_244_;
    SafeAllocator unknown_258_;
    SafeAllocator unknown_26c_;
    SafeAllocator unknown_280_;
    char unknown_294_[0xdf4 - 0x294];
    void* unknown_df4_;
    char unknown_df8_[0x18];
    unsigned short* unknown_e10_;
    char unknown_e14_[4];
    char unknown_e18_[REGION(0x48,0x4c)];
    void* unknown_e64_;
    int unknown_e68_;
    char unknown_e6c_[0x10];
    unsigned char unknown_e7c_;
    unsigned char unknown_e7d_;
    char unknown_e7e_[2];
    int unknown_e80_;
    char unknown_e84_[3][0x20];
    char unknown_ee4_[0xfa0 - 0xee4];
    char unknown_fa0_[3][0xe0];
    void* unknown_1240_;
    char unknown_1244_[REGION(0x1958 - 0x1240,0x19e0 - 0x1244)];
    char unknown_19e0_[0x19ec - 0x19e0];
    char unknown_19ec_[0x19f4 - 0x19ec];
    char unknown_19f4_[0x1a34 - 0x19f4];
    char unknown_1a34_[0x1a70 - 0x1a34];
    Struct_ov005_02155d6c_2 unknown_1a70_[36];
    Struct_ov005_02153ba4 unknown_2d90_[24];
    Struct_ov005_02155d6c_2 unknown_3030_[24];
    Struct_ov005_02155d6c_2 unknown_3cf0_;
    short unknown_3d78_;
    char unknown_3d7a_[2];
    int unknown_3d7c_;
    int unknown_3d80_;
    int unknown_3d84_;
    char* unknown_3d88_;
    char* unknown_3d8c_;
    char* unknown_3d90_;
    char* unknown_3d94_;
    short unknown_3d98_[8];
    unsigned char unknown_3da8_;
    unsigned char unknown_3da9_;
    unsigned char unknown_3daa_;
    unsigned char unknown_3dab_;
    unsigned short unknown_3dac_;
    unsigned short unknown_3dae_;
    unsigned short unknown_3db0_;
    unsigned short unknown_3db2_;
    unsigned short unknown_3db4_;
    char unknown_3db6_;
    unsigned char unknown_3db7_;
    unsigned char unknown_3db8_;
    unsigned char unknown_3db9_;
    unsigned char unknown_3dba_;
    signed char unknown_3dbb_;
    unsigned char unknown_3dbc_;
    signed char unknown_3dbd_;
    unsigned char unknown_3dbe_;
    signed char unknown_3dbf_;
    signed char unknown_3dc0_;
    char unknown_3dc1_;
    unsigned short unknown_3dc2_;
    unsigned char unknown_3dc4_;
    char unknown_3dc5_[3];
    int unknown_3dc8_;
    unsigned int unknown_3dcc_;
    unsigned char unknown_3dd0_;
    unsigned char unknown_3dd1_;
    unsigned char unknown_3dd2_;
    unsigned char unknown_3dd3_;
    unsigned char unknown_3dd4_[8];
    unsigned char unknown_3ddc_;
    unsigned char unknown_3ddd_;
    signed char unknown_3dde_;
    unsigned char unknown_3ddf_;
    short unknown_3de0_;
    short unknown_3de2_;
    int unknown_3de4_;
    int unknown_3de8_;
    int unknown_3dec_;
    signed char unknown_3df0_;
    signed char unknown_3df1_;
    signed char unknown_3df2_;
    unsigned char unknown_3df3_;
    unsigned char unknown_3df4_[8];
    unsigned char unknown_3dfc_[8];
    signed char unknown_3e04_;
    signed char unknown_3e05_;
    signed char unknown_3e06_;
    signed char unknown_3e07_;
    short unknown_3e08_;
    short unknown_3e0a_;
    unsigned short unknown_3e0c_[20][3];
    unsigned short unknown_3e84_[8][REGION(0xa,0x40)];
#if !defined(jpn)
    unsigned char unknown_4284_[8];
#endif
};

extern "C" void __clear(void* buffer, unsigned long size);
extern "C" void func_02074af4(void* state);
extern "C" char* Zone3D_GetInstance();
short GetFieldAt0x7e_0201e830(S_e830* p);
void KeyTable_Reset(Struct020dfc40* texts);
void ClearFields_021e20c0(void* layout);
void Background_Init(BackgroundGraphics* bg);
void Window_Init(InitTarget0205cfd4* window);
extern "C" void WindowPane_Init(void* canvas);
extern "C" void func_ov023_021dc134(void* window, int a, int b);
void ClearObj_021e1318(Obj021e1318* list);
extern "C" void func_ov023_021dad78(void* table);
extern "C" void func_ov005_021536e0(void* frame);
void* GameState_GetParty(GameState* gameState);
unsigned char GetTableByte0215a948(void* unused, int index);
unsigned char GetTableByte0215a918(void* unused, int index);
short GetShortFromArray0xc10_0207c620(unsigned char* p, unsigned int list);
void GridCursor_Init(GridCursor* cursor);
MemberScreen* GetField1c_021a193c(int* p);
int CountPositiveEntries0207c638(void* p, unsigned int list);
short GetHalfwordEntryFromField150(Field150Holder02052df8* member, int part);
extern "C" int func_0207c7a0(void* p, int item, int a);
short* GetPointerFromArray0xbd0_0207c5f8(unsigned char* p, unsigned int list);

// USA: func_ov005_02153ba4
extern "C" ARM void func_ov005_02153ba4(EquipmentMenu* self) {
    self->unk_e7c = 0;
    self->unk_e7d = 0;
    func_02074af4(self->screenState_);
    self->layers_ = (REG_DISPCNT & 0x1f00) >> 8;
    self->unk_3dc2 = GetFieldAt0x7e_0201e830((S_e830*)(Zone3D_GetInstance() + REGION(0x8c,0x6c)));
    self->allocator_.ResetAllocatorPointer();
    self->modelAllocator_.ResetAllocatorPointer();
    for (int i = 0; i < 8; i++)
        self->equippedAllocators_[i].ResetAllocatorPointer();
    for (int i = 0; i < 16; i++)
        self->itemAllocators_[i].ResetAllocatorPointer();
    self->dragAllocator_.ResetAllocatorPointer();
    self->textAllocator_.ResetAllocatorPointer();
    self->unk_230.ResetAllocatorPointer();
    self->infoAllocator_.ResetAllocatorPointer();
    self->sortAllocator_.ResetAllocatorPointer();
    self->modelTableAllocator_.ResetAllocatorPointer();
    self->unk_280.ResetAllocatorPointer();
    self->items_ = NULL;
    KeyTable_Reset((Struct020dfc40*)self->texts_);
    self->text_ = NULL;
    ClearFields_021e20c0(self->layout_);
    self->unk_e64 = NULL;
    self->unk_e68 = 0;
    Background_Init((BackgroundGraphics*)self->backgrounds_[0]);
    Background_Init((BackgroundGraphics*)self->backgrounds_[1]);
    Background_Init((BackgroundGraphics*)self->backgrounds_[2]);
    Window_Init((InitTarget0205cfd4*)self->window_);
    for (int i = 0; i < 3; i++)
        WindowPane_Init(self->canvases_[i]);
    self->pixels_ = NULL;
    func_ov023_021dc134(self->infoWindow_, -1, 0);
    ClearObj_021e1318((Obj021e1318*)self->sortList_);
    func_ov023_021dad78(self->modelTable_);
    func_ov005_021536e0(self->frame_);
    for (int i = 0; i < 36; i++)
        SprSprite_Init(&self->models_[i]);
    for (int i = 0; i < 24; i++)
        SprSprite_Init(&self->slotModels_[i]);
    SprSprite_Init(&self->dragModel_);
    self->dragged_ = -1;
    self->unk_3d7c = 0;
    self->unk_3d80 = 0;
    self->unk_3d84 = 0;
    self->pageFiles_ = NULL;
    self->dragFile_ = NULL;
    self->equippedFiles_ = NULL;
    self->itemFile_ = NULL;
    for (int i = 0; i < 24; i++) {
        self->slots_[i].item_ = -1;
        self->slots_[i].count_ = 0;
        self->slots_[i].equipped_ = 0;
        self->slots_[i].vramState_ = NULL;
        self->slots_[i].model_ = NULL;
        self->slots_[i].x_ = 0;
        self->slots_[i].y_ = 0;
        self->slots_[i].offset_ = -1;
        self->slots_[i].loadedItem_ = -1;
    }
    GameState* gameState = GameState::GetInstance();
    char* party = (char*)GameState_GetParty(gameState);
    for (int i = 0; i < 8; i++)
        self->itemCounts_[i] = GetShortFromArray0xc10_0207c620((unsigned char*)(party + 0x1d4), GetTableByte0215a948(self, i));
    self->unk_3da8 = 0;
    self->equippedStep_ = 0;
    self->pageStep_ = 0;
    self->dragStep_ = 0;
    self->unk_3dac = 0;
    self->equippedStart_ = 0;
    self->equippedEnd_ = 0;
    self->pageStart_ = 0;
    self->pageEnd_ = 0;
    self->loading_ = 0;
    self->state_ = 2;
    self->lastState_ = 2;
    self->step_ = 0;
    self->slot_ = 0;
    self->kind_ = 0;
    self->unk_3dbe = 0;
    self->page_ = 0;
    self->lastPage_ = 0;
    self->loadStep_ = 0;
    self->task_ = 0;
    memset(&self->flags_, 0, sizeof(self->flags_));
    self->unk_3dc0 = -1;
    GridCursor_Init((GridCursor*)self->cursor_);
    self->cursor_[0x3d] = 0;
    self->unk_3dd0 = 0;
    self->unk_3dd1 = 0;
    self->unk_3dd2 = 0;
    self->unk_3dd3 = 0;
    for (int i = 0; i < 8; i++)
        self->sortOrders_[i] = 0;
    self->menuStep_ = 0;
    self->menuResult_ = 0;
    self->menuChoice_ = 0;
    self->menuState_ = 0;
    for (int i = 0; i < 8; i++) {
#if defined(jpn)
        memset(arg0->unknown_3e84_[var10], 0, sizeof(arg0->unknown_3e84_[var10]));
#else
        for (int var11 = 0; var11 < 0x40; var11++)
            arg0->unknown_3e84_[var10][var11] = 0xffff;
        arg0->unknown_4284_[var10] = 0;
#endif
    }
    self->animationX_ = 0;
    self->ticks_ = 0;
    self->animationTime_ = 0;
    self->animationPhase_ = 0;
    self->blinks_ = 3;
    self->blinkTimer_ = 30;
    self->blinkTimer2_ = 30;
    self->fadeStep_ = 0;
    MemberScreen* screen = GetField1c_021a193c((int*)GetGameResources()->unknown_ptr_array_3700[2]);
    int* members = screen->members_;
    int memberCount = screen->memberCount_;
    for (int kind = 0; kind < 8; kind++) {
        unsigned char list = GetTableByte0215a948(self, kind);
        int part = GetTableByte0215a918(self, kind);
        int count = CountPositiveEntries0207c638(party + 0x1d4, list);
        short equipped[4];
        __clear(equipped, sizeof(equipped));
        for (int i = 0; i < memberCount; i++) {
            void* member = GetCombatantWithFlag0x100_0200ff1c(gameState, members[i]);
            if (member == NULL)
                continue;
            var19[var20] = func_02052df8((Struct_02052df8*)var21, var17);
            if (var19[var20] <= 0)
                continue;
            int var22;
            for (var22 = 0; var22 < var20; var22++)
                ;
            if (!func_0207c7a0(var7 + 0x1d4, var19[var20], 9))
                var18++;
        }
        if (var18 > 0)
            arg0->unknown_3df4_[var15] = (var18 - 1) / 16 + 1;
        else
            arg0->unknown_3df4_[var15] = 1;
        short* var23 = func_0207c5f8((unsigned char*)(var7 + 0x1d4), var16);
        short var24 = func_0207c620((unsigned char*)(var7 + 0x1d4), var16);
        int var25 = 0;
        for (int var26 = 0; var26 < var24; var26++) {
            if (var23[var26] > 0 && var25 < var26)
                var25 = var26;
        }
        unsigned char var27 = var25 / 16 + 1;
        if (var27 > arg0->unknown_3df4_[var15])
            arg0->unknown_3df4_[var15] = var27;
        arg0->unknown_3dfc_[var15] = 0;
    }
    arg0->unknown_3e04_ = 0;
    arg0->unknown_3e05_ = 0;
    arg0->unknown_3e07_ = -2;
    arg0->unknown_3e06_ = 0;
    arg0->unknown_3e08_ = -1;
    arg0->unknown_3e0a_ = -1;
}
