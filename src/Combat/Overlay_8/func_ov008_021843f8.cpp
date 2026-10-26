#include <globaldefs.h>
#include "GameState/BattleRecordSnapshot.h"
#include "GameState/GameState.h"
#include "World/Object3D.h"
#include <Memory/SafeAllocator.h>

struct Struct_ov008_021843f8_2 {
    Struct_020ac4f8 unknown_0_[2];
    unsigned int unknown_8_0_ : 17;
    unsigned int unknown_a_1_ : 7;
    unsigned int unknown_b_0_ : 7;
    unsigned int unknown_b_7_ : 1;
    unsigned int unknown_c_0_ : 17;
    unsigned int unknown_e_1_ : 7;
    unsigned int unknown_f_0_ : 7;
    unsigned int unknown_f_7_ : 1;
    unsigned int unknown_10_0_ : 9;
    unsigned int unknown_11_1_ : 14;
    unsigned int unknown_12_7_ : 9;
    unsigned int unk_14;
};

struct Struct_ov008_021843f8_3 {
    Struct_020ac4f8 unknown_0_;
    Struct_020ac4f8 unk_4;
    unsigned int unk_8;
    unsigned int unk_c;
    unsigned int unknown_10_0_ : 9;
    unsigned int unknown_11_1_ : 14;
    unsigned int unknown_12_7_ : 9;
    char unknown_14_[0x90 - 0x14];
    Struct_ov008_021843f8_2 unknown_90_;
    unsigned int unknown_a8_;
    unsigned int unk_ac;
};

struct Struct_ov000_021735d0 {
    unsigned int flags_[15];
};

struct Struct_ov008_021843f8 {
    Struct_ov000_021735d0 flags_;
    Struct_ov008_021843f8_3 unknown_3c_;
};

static inline Struct_ov008_021843f8* inline_ov008_021843f8(GameState* gameState)
{
#if defined(jpn)
    return (Struct_ov008_021843f8*)((char*)gameState + 0x2c4 + 0x7000);
#else
    return (Struct_ov008_021843f8*)((char*)gameState + 0x104 + 0x7400);
#endif
}

struct Struct020dfc40;
struct Struct_020a13c4;
struct BackgroundGraphics;
struct InitTarget0205cfd4;
struct GridCursor;

extern "C" void* GlobalFlags_GetInstance();
extern "C" void FlagWord_SetBits(unsigned int* field, unsigned int bits);
extern "C" void KeyTable_Reset(Struct020dfc40* texts);
extern "C" void func_020a13c4(Struct_020a13c4* arg0);
extern "C" void Background_Init(BackgroundGraphics* background);
extern "C" void Window_Init(InitTarget0205cfd4* window);
extern "C" void GridCursor_Init(GridCursor* cursor);
extern "C" void func_020a2010(void* camera);
extern "C" void WindowPane_Init(void* canvas);

struct Struct_ov008_021842a0_2 {
    SafeAllocator allocator_;
    SafeAllocator unknown_14_;
    SafeAllocator textAllocator_;
    SafeAllocator spriteAllocator_;
    SafeAllocator iconAllocator_;
    SafeAllocator modelAllocator_;
    SafeAllocator titleAllocator_;
    SafeAllocator unknown_8c_;
    char texts_[0x18];
    char* text_;
    char unknown_bc_[0x14];
    char backgrounds_[3][0x20];
    char window_[0xbc];
    char canvases_[6][0xe0];
    void* pixels_;
    void* renderer_;
    void* sprites_;
    void* animations_;
    void* iconRenderer_;
    void* iconSprite_;
    unsigned char items_[8];
    unsigned char unknown_74c_;
    char unknown_74d_[3];
    char cursor_[0x40];
    Object3D model_;
    char camera_[0x2c8];
    void* titles_;
    void* unknown_b08_;
    void* page_;
    signed char state_;
    unsigned char step_;
    unsigned char unknown_b12_;
    unsigned char unknown_b13_;
    short unknown_b14_;
    short unknown_b16_;
    int flags_;
    int unknown_b1c_;
    int task_;
    int mode_;
    unsigned char kind_;
    unsigned char unknown_b29_;
    unsigned char unknown_b2a_;
    int titleX_;
    const void* unknown_b30_;
    void* unknown_b34_;
    void* unknown_b38_;
#if !defined(jpn)
    void* guestTitles_;
#endif
    Struct_020ac4f8 unknown_b40_[2];
};

extern "C" void func_ov008_02186cec(Struct_ov008_021842a0_2* self);

// USA: func_ov008_021843f8
extern "C" ARM void func_ov008_021843f8(Struct_ov008_021842a0_2* self)
{
    FlagWord_SetBits((unsigned int*)GlobalFlags_GetInstance(), 0xf);
    self->allocator_.ResetAllocatorPointer();
    self->unknown_14_.ResetAllocatorPointer();
    self->textAllocator_.ResetAllocatorPointer();
    self->spriteAllocator_.ResetAllocatorPointer();
    self->iconAllocator_.ResetAllocatorPointer();
    self->modelAllocator_.ResetAllocatorPointer();
    self->titleAllocator_.ResetAllocatorPointer();
    self->unknown_8c_.ResetAllocatorPointer();
    KeyTable_Reset((Struct020dfc40*)self->texts_);
    self->text_ = NULL;
    func_020a13c4((Struct_020a13c4*)self->unknown_bc_);
    Background_Init((BackgroundGraphics*)self->backgrounds_[0]);
    Background_Init((BackgroundGraphics*)self->backgrounds_[1]);
    Background_Init((BackgroundGraphics*)self->backgrounds_[2]);
    Window_Init((InitTarget0205cfd4*)self->window_);
    for (int i = 0; i < 6; i++)
        WindowPane_Init(self->canvases_[i]);
    self->pixels_ = NULL;
    self->renderer_ = NULL;
    self->sprites_ = NULL;
    self->animations_ = NULL;
    self->iconRenderer_ = NULL;
    self->sprites_ = NULL;
    GridCursor_Init((GridCursor*)self->cursor_);
    self->model_.Initialize();
    func_020a2010(self->camera_);
    self->titles_ = NULL;
    self->unknown_b08_ = NULL;
    self->page_ = NULL;
    self->state_ = 0;
    self->step_ = 0;
    self->unknown_b12_ = 0;
    self->unknown_b13_ = 0;
    self->unknown_b14_ = -1;
    self->unknown_b16_ = -1;
    self->flags_ = 0;
    self->unknown_b1c_ = 0;
    self->task_ = 0;
    self->mode_ = 0;
    self->kind_ = 0;
    self->unknown_b29_ = 0;
    self->unknown_b2a_ = 0;
    self->titleX_ = 0;
    self->unknown_b30_ = NULL;
    self->unknown_b34_ = NULL;
    self->unknown_b38_ = NULL;
#if !defined(jpn)
    self->guestTitles_ = NULL;
#endif
    func_ov008_02184598(&self->unknown_b40_[0]);
    func_ov008_02184598(&self->unknown_b40_[1]);
    Struct_ov008_021843f8* saved = inline_ov008_021843f8(GameState::GetInstance());
    if (saved->unknown_3c_.unknown_10_0_ != 0)
        self->flags_ |= 0x2000;
    if (saved->unknown_3c_.unknown_90_.unknown_12_7_ != 0)
        self->flags_ |= 4;
    func_ov008_02186cec(self);
}
