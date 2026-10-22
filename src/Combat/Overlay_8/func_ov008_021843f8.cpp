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
    unsigned int unknown_14_;
};

struct Struct_ov008_021843f8_3 {
    Struct_020ac4f8 unknown_0_;
    Struct_020ac4f8 unknown_4_;
    unsigned int unknown_8_;
    unsigned int unknown_c_;
    unsigned int unknown_10_0_ : 9;
    unsigned int unknown_11_1_ : 14;
    unsigned int unknown_12_7_ : 9;
    char unknown_14_[0x90 - 0x14];
    Struct_ov008_021843f8_2 unknown_90_;
    unsigned int unknown_a8_;
    unsigned int unknown_ac_;
};

struct Struct_ov000_021735d0 {
    unsigned int unknown_0_[15];
};

struct Struct_ov008_021843f8 {
    Struct_ov000_021735d0 unknown_0_;
    Struct_ov008_021843f8_3 unknown_3c_;
};

static inline Struct_ov008_021843f8* inline_ov008_021843f8(GameState* arg0)
{
#if defined(jpn)
    return (Struct_ov008_021843f8*)((char*)arg0 + 0x2c4 + 0x7000);
#else
    return (Struct_ov008_021843f8*)((char*)arg0 + 0x104 + 0x7400);
#endif
}

struct Struct_0201099c_14;
struct Struct_020a13c4;
struct Struct_02020cb8;
struct Struct_0205cfd4;
struct Struct_0205bef8;

void* GetDataPtr02114e04_020d6c00();
void OrBitsIntoField0_020466e4(unsigned int* field, unsigned int bits);
void ResetStruct020dfc40(Struct020dfc40* texts);
void ClearStruct020a13c4(S020a13c4* guides);
void ResetList0204af64(List0204af64* background);
void InitStruct0205cfd4(InitTarget0205cfd4* window);
void GridCursor_Init(Struct_0205bef8* cursor);
void InitCombatController020a2010(void* camera);
extern "C" void func_0204c684(void* canvas);

struct Struct_ov008_021842a0_2 {
    SafeAllocator unknown_0_;
    SafeAllocator unknown_14_;
    SafeAllocator unknown_28_;
    SafeAllocator unknown_3c_;
    SafeAllocator unknown_50_;
    SafeAllocator unknown_64_;
    SafeAllocator unknown_78_;
    SafeAllocator unknown_8c_;
    char unknown_a0_[0x18];
    char* unknown_b8_;
    char unknown_bc_[0x14];
    char unknown_d0_[3][0x20];
    char unknown_130_[0xbc];
    char unknown_1ec_[6][0xe0];
    void* unknown_72c_;
    void* unknown_730_;
    void* unknown_734_;
    void* unknown_738_;
    void* unknown_73c_;
    void* unknown_740_;
    unsigned char unknown_744_[8];
    unsigned char unknown_74c_;
    char unknown_74d_[3];
    char unknown_750_[0x40];
    Object3D unknown_790_;
    char unknown_83c_[0x2c8];
    void* unknown_b04_;
    void* unknown_b08_;
    void* unknown_b0c_;
    signed char unknown_b10_;
    unsigned char unknown_b11_;
    unsigned char unknown_b12_;
    unsigned char unknown_b13_;
    short unknown_b14_;
    short unknown_b16_;
    int unknown_b18_;
    int unknown_b1c_;
    int unknown_b20_;
    int unknown_b24_;
    unsigned char unknown_b28_;
    unsigned char unknown_b29_;
    unsigned char unknown_b2a_;
    int unknown_b2c_;
    const void* unknown_b30_;
    void* unknown_b34_;
    void* unknown_b38_;
#if !defined(jpn)
    void* unknown_b3c_;
#endif
    Struct_020ac4f8 unknown_b40_[2];
};

extern "C" void func_ov008_02186cec(Struct_ov008_021842a0_2* arg0);

// USA: func_ov008_021843f8
extern "C" ARM void func_ov008_021843f8(Struct_ov008_021842a0_2* arg0)
{
    OrBitsIntoField0_020466e4((unsigned int*)GetDataPtr02114e04_020d6c00(), 0xf);
    self->allocator_.ResetAllocatorPointer();
    self->backgroundAllocator_.ResetAllocatorPointer();
    self->textAllocator_.ResetAllocatorPointer();
    self->spriteAllocator_.ResetAllocatorPointer();
    self->iconAllocator_.ResetAllocatorPointer();
    self->modelAllocator_.ResetAllocatorPointer();
    self->titleAllocator_.ResetAllocatorPointer();
    self->guideAllocator_.ResetAllocatorPointer();
    ResetStruct020dfc40((Struct020dfc40*)self->texts_);
    self->text_ = NULL;
    ClearStruct020a13c4((S020a13c4*)self->titleTable_);
    ResetList0204af64((List0204af64*)self->backgrounds_[0]);
    ResetList0204af64((List0204af64*)self->backgrounds_[1]);
    ResetList0204af64((List0204af64*)self->backgrounds_[2]);
    InitStruct0205cfd4((InitTarget0205cfd4*)self->window_);
    for (int i = 0; i < 6; i++)
        func_0204c684(self->canvases_[i]);
    self->pixels_ = NULL;
    self->renderer_ = NULL;
    self->sprites_ = NULL;
    self->animations_ = NULL;
    self->iconRenderer_ = NULL;
    self->sprites_ = NULL;
    GridCursor_Init((Struct_0205bef8*)self->cursor_);
    self->model_.Initialize();
    InitCombatController020a2010(self->camera_);
    self->titles_ = NULL;
    self->guide_ = NULL;
    self->page_ = NULL;
    self->state_ = 0;
    self->step_ = 0;
    self->loadStep_ = 0;
    self->exit_ = 0;
    self->title_ = -1;
    self->comment_ = -1;
    self->flags_ = 0;
    self->unk_b1c = 0;
    self->task_ = 0;
    self->mode_ = 0;
    self->kind_ = 0;
    self->top_ = 0;
    self->closed_ = 0;
    self->titleX_ = 0;
    self->guest_ = NULL;
    self->guestRecords_ = NULL;
    self->guestTexts_ = NULL;
#if !defined(jpn)
    arg0->unknown_b3c_ = NULL;
#endif
    func_ov008_02184598(&arg0->unknown_b40_[0]);
    func_ov008_02184598(&arg0->unknown_b40_[1]);
    Struct_ov008_021843f8* var1 = inline_ov008_021843f8(GameState::GetInstance());
    if (var1->unknown_3c_.unknown_10_0_ != 0)
        arg0->unknown_b18_ |= 0x2000;
    if (var1->unknown_3c_.unknown_90_.unknown_12_7_ != 0)
        arg0->unknown_b18_ |= 4;
    func_ov008_02186cec(arg0);
}
