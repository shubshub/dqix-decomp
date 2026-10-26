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
struct Struct_ov002_0215505c_2;
struct GridCursor;
struct Struct_02052df8;

struct MenuModel {
    char unk_0[0x88];
};

struct Struct_ov005_02153ba4 {
    short item_;
    signed char count_;
    unsigned char unknown_3_;
    void* vramState_;
    MenuModel* model_;
    int x_;
    int y_;
    int unknown_14_;
    short unknown_18_;
};

struct MemberScreen {
    char unk_0[REGION(0x4e4,0x4e8)];
    int memberCount_;
    int members_[4];
};

struct EquipmentMenu {
    SafeAllocator allocator_;
    SafeAllocator modelAllocator_;
    SafeAllocator equippedAllocators_[8];
    SafeAllocator itemAllocators_[16];
    SafeAllocator dragAllocator_;
    SafeAllocator textAllocator_;
    SafeAllocator unknown_230_;
    SafeAllocator unknown_244_;
    SafeAllocator unknown_258_;
    SafeAllocator unknown_26c_;
    SafeAllocator unknown_280_;
    char vramStates_[0xdf4 - 0x294];
    void* items_;
    char texts_[0x18];
    unsigned short* text_;
    char unknown_e14_[4];
    char layout_[REGION(0x48,0x4c)];
    void* unknown_e64_;
    int unknown_e68_;
    char unknown_e6c_[0x10];
    unsigned char unknown_e7c_;
    unsigned char unknown_e7d_;
    char unknown_e7e_[2];
    int layers_;
    char backgrounds_[3][0x20];
    char window_[0xfa0 - 0xee4];
    char canvases_[3][0xe0];
    void* pixels_;
    char unknown_1244_[REGION(0x1958 - 0x1240,0x19e0 - 0x1244)];
    char unknown_19e0_[0x19ec - 0x19e0];
    char unknown_19ec_[0x19f4 - 0x19ec];
    char cursor_[0x1a34 - 0x19f4];
    char frame_[0x1a70 - 0x1a34];
    MenuModel models_[36];
    Struct_ov005_02153ba4 slots_[24];
    MenuModel slotModels_[24];
    MenuModel dragModel_;
    short dragged_;
    char unknown_3d7a_[2];
    int unknown_3d7c_;
    int unknown_3d80_;
    int unknown_3d84_;
    char* pageFiles_;
    char* dragFile_;
    char* equippedFiles_;
    char* itemFile_;
    short unknown_3d98_[8];
    unsigned char unknown_3da8_;
    unsigned char unknown_3da9_;
    unsigned char unknown_3daa_;
    unsigned char unknown_3dab_;
    unsigned short unk_3dac;
    unsigned short unknown_3dae_;
    unsigned short unknown_3db0_;
    unsigned short unknown_3db2_;
    unsigned short unknown_3db4_;
    char unknown_3db6_;
    unsigned char loading_;
    unsigned char state_;
    unsigned char unknown_3db9_;
    unsigned char step_;
    signed char slot_;
    unsigned char kind_;
    signed char page_;
    unsigned char unknown_3dbe_;
    signed char unknown_3dbf_;
    signed char unknown_3dc0_;
    char unknown_3dc1_;
    unsigned short unk_3dc2;
    unsigned char unknown_3dc4_;
    char unknown_3dc5_[3];
    int task_;
    unsigned int flags_;
    unsigned char unknown_3dd0_;
    unsigned char unknown_3dd1_;
    unsigned char unknown_3dd2_;
    unsigned char unknown_3dd3_;
    unsigned char unknown_3dd4_[8];
    unsigned char unknown_3ddc_;
    unsigned char menuResult_;
    signed char menuChoice_;
    unsigned char unknown_3ddf_;
    short unknown_3de0_;
    short unknown_3de2_;
    int ticks_;
    int animationTime_;
    int unknown_3dec_;
    signed char unknown_3df0_;
    signed char unknown_3df1_;
    signed char unknown_3df2_;
    unsigned char unknown_3df3_;
    unsigned char unknown_3df4_[8];
    unsigned char pages_[8];
    signed char unknown_3e04_;
    signed char unknown_3e05_;
    signed char unknown_3e06_;
    signed char unknown_3e07_;
    short unknown_3e08_;
    short unknown_3e0a_;
    unsigned short unknown_3e0c_[20][3];
    unsigned short names_[8][REGION(0xa,0x40)];
#if !defined(jpn)
    unsigned char unknown_4284_[8];
#endif
};

extern "C" void __clear(void* buffer, unsigned long size);
extern "C" void func_02074af4(void* state);
extern "C" char* Zone3D_GetInstance();
extern "C" short func_0201e830(S_e830* p);
extern "C" void KeyTable_Reset(Struct020dfc40* texts);
extern "C" void func_ov023_021e20c0(void* layout);
extern "C" void Background_Init(BackgroundGraphics* bg);
extern "C" void Window_Init(InitTarget0205cfd4* window);
extern "C" void WindowPane_Init(void* canvas);
extern "C" void func_ov023_021dc134(void* window, int a, int b);
extern "C" void func_ov023_021e1318(Struct_ov002_0215505c_2* list);
extern "C" void func_ov023_021dad78(void* table);
extern "C" void func_ov005_021536e0(void* frame);
extern "C" void* GameState_GetParty(GameState* gameState);
extern "C" unsigned char func_ov005_0215a948(void* unused, int index);
extern "C" unsigned char func_ov005_0215a918(void* unused, int index);
extern "C" short func_0207c620(unsigned char* p, unsigned int list);
extern "C" void GridCursor_Init(GridCursor* cursor);
extern "C" MemberScreen* func_ov017_021a193c(int* p);
extern "C" int func_0207c638(void* p, unsigned int list);
extern "C" short func_02052df8(Struct_02052df8* member, int part);
extern "C" int func_0207c7a0(void* p, int item, int a);
extern "C" short* func_0207c5f8(unsigned char* p, unsigned int list);

// USA: func_ov005_02153ba4
extern "C" ARM void func_ov005_02153ba4(EquipmentMenu* self) {
    self->unknown_e7c_ = 0;
    self->unknown_e7d_ = 0;
    func_02074af4(self->unknown_e6c_);
    self->layers_ = (REG_DISPCNT & 0x1f00) >> 8;
    self->unk_3dc2 = func_0201e830((S_e830*)(Zone3D_GetInstance() + REGION(0x8c,0x6c)));
    self->allocator_.ResetAllocatorPointer();
    self->modelAllocator_.ResetAllocatorPointer();
    for (int i = 0; i < 8; i++)
        self->equippedAllocators_[i].ResetAllocatorPointer();
    for (int i = 0; i < 16; i++)
        self->itemAllocators_[i].ResetAllocatorPointer();
    self->dragAllocator_.ResetAllocatorPointer();
    self->textAllocator_.ResetAllocatorPointer();
    self->unknown_230_.ResetAllocatorPointer();
    self->unknown_244_.ResetAllocatorPointer();
    self->unknown_258_.ResetAllocatorPointer();
    self->unknown_26c_.ResetAllocatorPointer();
    self->unknown_280_.ResetAllocatorPointer();
    self->items_ = NULL;
    KeyTable_Reset((Struct020dfc40*)self->texts_);
    self->text_ = NULL;
    func_ov023_021e20c0(self->layout_);
    self->unknown_e64_ = NULL;
    self->unknown_e68_ = 0;
    Background_Init((BackgroundGraphics*)self->backgrounds_[0]);
    Background_Init((BackgroundGraphics*)self->backgrounds_[1]);
    Background_Init((BackgroundGraphics*)self->backgrounds_[2]);
    Window_Init((InitTarget0205cfd4*)self->window_);
    for (int i = 0; i < 3; i++)
        WindowPane_Init(self->canvases_[i]);
    self->pixels_ = NULL;
    func_ov023_021dc134(self->unknown_1244_, -1, 0);
    func_ov023_021e1318((Struct_ov002_0215505c_2*)self->unknown_19e0_);
    func_ov023_021dad78(self->unknown_19ec_);
    func_ov005_021536e0(self->frame_);
    for (int i = 0; i < 36; i++)
        SprSprite_Init(&self->models_[i]);
    for (int i = 0; i < 24; i++)
        SprSprite_Init(&self->slotModels_[i]);
    SprSprite_Init(&self->dragModel_);
    self->dragged_ = -1;
    self->unknown_3d7c_ = 0;
    self->unknown_3d80_ = 0;
    self->unknown_3d84_ = 0;
    self->pageFiles_ = NULL;
    self->dragFile_ = NULL;
    self->equippedFiles_ = NULL;
    self->itemFile_ = NULL;
    for (int i = 0; i < 24; i++) {
        self->slots_[i].item_ = -1;
        self->slots_[i].count_ = 0;
        self->slots_[i].unknown_3_ = 0;
        self->slots_[i].vramState_ = NULL;
        self->slots_[i].model_ = NULL;
        self->slots_[i].x_ = 0;
        self->slots_[i].y_ = 0;
        self->slots_[i].unknown_14_ = -1;
        self->slots_[i].unknown_18_ = -1;
    }
    GameState* gameState = GameState::GetInstance();
    char* party = (char*)GameState_GetParty(gameState);
    for (int i = 0; i < 8; i++)
        self->unknown_3d98_[i] = func_0207c620((unsigned char*)(party + 0x1d4), func_ov005_0215a948(self, i));
    self->unknown_3da8_ = 0;
    self->unknown_3da9_ = 0;
    self->unknown_3daa_ = 0;
    self->unknown_3dab_ = 0;
    self->unk_3dac = 0;
    self->unknown_3dae_ = 0;
    self->unknown_3db0_ = 0;
    self->unknown_3db2_ = 0;
    self->unknown_3db4_ = 0;
    self->loading_ = 0;
    self->state_ = 2;
    self->unknown_3db9_ = 2;
    self->step_ = 0;
    self->slot_ = 0;
    self->kind_ = 0;
    self->unknown_3dbe_ = 0;
    self->page_ = 0;
    self->unknown_3dbf_ = 0;
    self->unknown_3dc4_ = 0;
    self->task_ = 0;
    memset(&self->flags_, 0, sizeof(self->flags_));
    self->unknown_3dc0_ = -1;
    GridCursor_Init((GridCursor*)self->cursor_);
    self->cursor_[0x3d] = 0;
    self->unknown_3dd0_ = 0;
    self->unknown_3dd1_ = 0;
    self->unknown_3dd2_ = 0;
    self->unknown_3dd3_ = 0;
    for (int i = 0; i < 8; i++)
        self->unknown_3dd4_[i] = 0;
    self->unknown_3ddc_ = 0;
    self->menuResult_ = 0;
    self->menuChoice_ = 0;
    self->unknown_3ddf_ = 0;
    for (int i = 0; i < 8; i++) {
#if defined(jpn)
        memset(self->names_[i], 0, sizeof(self->names_[i]));
#else
        for (int j = 0; j < 0x40; j++)
            self->names_[i][j] = 0xffff;
        self->unknown_4284_[i] = 0;
#endif
    }
    self->unknown_3de2_ = 0;
    self->ticks_ = 0;
    self->animationTime_ = 0;
    self->unknown_3dec_ = 0;
    self->unknown_3df0_ = 3;
    self->unknown_3df1_ = 30;
    self->unknown_3df2_ = 30;
    self->unknown_3df3_ = 0;
    MemberScreen* screen = func_ov017_021a193c((int*)GetGameResources()->unknown_ptr_array_3700[2]);
    int* members = screen->members_;
    int memberCount = screen->memberCount_;
    for (int kind = 0; kind < 8; kind++) {
        unsigned char list = func_ov005_0215a948(self, kind);
        int part = func_ov005_0215a918(self, kind);
        int count = func_0207c638(party + 0x1d4, list);
        short equipped[4];
        __clear(equipped, sizeof(equipped));
        for (int i = 0; i < memberCount; i++) {
            void* member = func_0200ff1c(gameState, members[i]);
            if (member == NULL)
                continue;
            equipped[i] = func_02052df8((Struct_02052df8*)member, part);
            if (equipped[i] <= 0)
                continue;
            int j;
            for (j = 0; j < i; j++)
                ;
            if (!func_0207c7a0(party + 0x1d4, equipped[i], 9))
                count++;
        }
        if (count > 0)
            self->unknown_3df4_[kind] = (count - 1) / 16 + 1;
        else
            self->unknown_3df4_[kind] = 1;
        short* items = func_0207c5f8((unsigned char*)(party + 0x1d4), list);
        short itemCount = func_0207c620((unsigned char*)(party + 0x1d4), list);
        int last = 0;
        for (int i = 0; i < itemCount; i++) {
            if (items[i] > 0 && last < i)
                last = i;
        }
        unsigned char pages = last / 16 + 1;
        if (pages > self->unknown_3df4_[kind])
            self->unknown_3df4_[kind] = pages;
        self->pages_[kind] = 0;
    }
    self->unknown_3e04_ = 0;
    self->unknown_3e05_ = 0;
    self->unknown_3e07_ = -2;
    self->unknown_3e06_ = 0;
    self->unknown_3e08_ = -1;
    self->unknown_3e0a_ = -1;
}
