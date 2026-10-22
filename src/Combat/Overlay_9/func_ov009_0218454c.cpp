#include <globaldefs.h>
#include "Resource/CharacterCreationUI.h"
#include <std_library_functions.h>
#include "Memory/SafeAllocator.h"
#include "Combat/MapDisplay.h"
#include "World/Object3D.h"
#include "Resource/CreationSlotLayout.h"

struct Struct_0201099c_14 {
    char unknown_0_[0x18];
};

struct Struct_0205cfd4 {
    char unknown_0_[0xbc];
};

struct Struct_ov006_02158478 {
    char unknown_0_[0xe0];
};

struct Struct_0205bef8 {
    int unknown_0_[0x10];
};

unsigned int* GetDataPtr02114e04_020d6c00();
void OrBitsIntoField0_020466e4(unsigned int* field, unsigned int bits);
void ZeroInit020de848(void* table);
void ResetStruct020dfc40(Struct020dfc40* table);
#if defined(jpn)
#define func_ov009_021847ec func_ov009_02185850
#endif
extern "C" void func_ov009_021847ec(void* checker);
void ResetList0204af64(List0204af64* background);
void InitStruct0205cfd4(InitTarget0205cfd4* window);
extern "C" void func_0204c684(Canvas* canvas);
void GridCursor_Init(Struct_0205bef8* cursor);
void CharacterCreationUI_ResetTargetLayout(CreationSlotLayout* grid);
int FindEntryIndexByKey020424e4(int text, int mode);

extern char data_ov009_0218aca4[];

struct Struct_ov009_021842a0_2 {
#if defined(jpn)
    SafeAllocator unknown_0_[8];
#else
    SafeAllocator unknown_0_[9];
#endif
    SafeAllocator* unknown_b4_;
    SafeAllocator* unknown_b8_;
#if !defined(jpn)
    void* unknown_bc_;
    void* unknown_c0_;
    void* unknown_c4_;
#endif
    char unknown_c8_[0x18];
    Struct_0201099c_14 unknown_e0_;
    void* unknown_f8_;
#if defined(jpn)
    char unknown_fc_[0x20];
#else
    char unknown_fc_[0x3c];
#endif
    List0204af64 backgrounds_[6];
    InitTarget0205cfd4 windows_[2];
    Canvas canvases_[1];
    Canvas canvases2_[4];
    void* pixels_;
    void* pixels2_;
    void* renderer_;
    void* sprites_;
    void* unk_7e0;
    void* renderer2_;
    void* sprites2_;
    void* unk_7ec;
    void* characters_[2];
    void* character_;
    void* nextCharacter_;
    int unk_800;
    int targetAngle_;
    char unk_808[0x70];
    Object3D object_;
    char camera_[0x2c8];
    Struct_0205bef8 cursor_;
    CreationSlotLayout grid_;
    short cursorX_;
    short cursorY_;
    short cursorWidth_;
    short cursorHeight_;
    short lastX_;
    short lastY_;
    signed char state_;
    unsigned char step_;
    char unk_c5a[2];
    int modelTasks_[3];
    char unk_c68[0x70];
    Object3D object2_;
    unsigned char selection_;
    unsigned char unk_d85;
    char unk_d86[2];
    void* member_;
    int touchedChoice_;
    int task_;
    unsigned char loadStep_;
    unsigned char mode_;
    short timer_;
    short unk_d98;
    char unk_d9a[2];
    unsigned int flags_;
    signed char lastStates_[2];
    unsigned char vocation_;
    unsigned char sex_;
    unsigned char bodyType_[2];
    unsigned char hairStyle_[2];
    unsigned char skinColor_[2];
    unsigned char eyeColor_[2];
    unsigned char face_[2];
    unsigned char hairColor_[2];
#if defined(jpn)
    char unknown_d74_[2][11];
    unsigned char unknown_d8a_[2];
    unsigned char unknown1_d8c_;
    unsigned char unknown_d8d_;
    unsigned char unknown_db6_;
    char unknown_d8f_;
#else
    char** unknown_db0_;
    unsigned char unknown_db4_;
    unsigned char unknown_db5_;
    unsigned char unknown_db6_;
    char unknown_db7_;
#endif
};

// USA: func_ov009_0218454c
extern "C" ARM void func_ov009_0218454c(Struct_ov009_021842a0_2* arg0, int arg1, int arg2)
{
    self->mode_ = mode;
    if (self->mode_ == CreationMode_PartyMemberCreation)
        OrBitsIntoField0_020466e4(GetDataPtr02114e04_020d6c00(), 0xf);
    self->allocators_[0].ResetAllocatorPointer();
    self->allocators_[1].ResetAllocatorPointer();
    self->allocators_[2].ResetAllocatorPointer();
    self->allocators_[3].ResetAllocatorPointer();
    self->allocators_[4].ResetAllocatorPointer();
    self->allocators_[5].ResetAllocatorPointer();
    self->allocators_[6].ResetAllocatorPointer();
    self->allocators_[7].ResetAllocatorPointer();
#if !defined(jpn)
    arg0->unknown_0_[8].ResetAllocatorPointer();
#endif
    arg0->unknown_b4_ = NULL;
    arg0->unknown_b8_ = NULL;
#if !defined(jpn)
    arg0->unknown_c0_ = NULL;
    arg0->unknown_c4_ = NULL;
#endif
    ZeroInit020de848(&self->partNames_);
    ResetStruct020dfc40(&self->texts_);
    self->unk_f8 = NULL;
    func_ov009_021847ec(&self->checker_);
    ResetList0204af64(&self->backgrounds_[0]);
    ResetList0204af64(&self->backgrounds_[1]);
    ResetList0204af64(&self->backgrounds_[2]);
    ResetList0204af64(&self->backgrounds_[3]);
    ResetList0204af64(&self->backgrounds_[4]);
    ResetList0204af64(&self->backgrounds_[5]);
    InitStruct0205cfd4(&self->windows_[0]);
    InitStruct0205cfd4(&self->windows_[1]);
    for (int i = 0; i < 1; i++)
        func_0204c684(&self->canvases_[i]);
    for (int i = 0; i < 4; i++)
        func_0204c684(&self->canvases2_[i]);
    self->pixels_ = NULL;
    self->pixels2_ = NULL;
    self->renderer_ = NULL;
    self->sprites_ = NULL;
    self->unk_7e0 = NULL;
    self->renderer2_ = NULL;
    self->sprites2_ = NULL;
    self->unk_7ec = NULL;
    self->characters_[0] = NULL;
    self->characters_[1] = NULL;
    self->character_ = NULL;
    self->nextCharacter_ = NULL;
    self->unk_800 = 0;
    self->targetAngle_ = 0;
    self->object_.Initialize();
    self->object2_.Initialize();
    GridCursor_Init(&self->cursor_);
    CharacterCreationUI_ResetTargetLayout(&self->grid_);
    self->cursorX_ = -1;
    self->cursorY_ = -1;
    self->cursorWidth_ = -1;
    self->cursorHeight_ = -1;
    self->lastX_ = -1;
    self->lastY_ = -1;
    self->state_ = 0;
    self->step_ = 0;
    self->selection_ = 0;
    self->unk_d85 = 0;
    self->member_ = NULL;
    self->touchedChoice_ = -1;
    self->task_ = 0;
    self->loadStep_ = 0;
    self->timer_ = 0;
    self->unk_d98 = 0;
    memset(&self->flags_, 0, sizeof(self->flags_));
    for (int i = 0; i < 2; i++)
        self->lastStates_[i] = 1;
    self->vocation_ = vocation;
    self->sex_ = 0;
    for (int i = 0; i < 2; i++)
    {
        arg0->unknown_da4_[var3] = 0;
        arg0->unknown_da6_[var3] = 0;
        arg0->unknown_da8_[var3] = 0;
        arg0->unknown_daa_[var3] = 0;
        arg0->unknown_dac_[var3] = 0;
        arg0->unknown_dae_[var3] = 0;
#if defined(jpn)
        memset(arg0->unknown_d74_[var3], 0, sizeof(arg0->unknown_d74_[var3]));
        arg0->unknown_d8a_[var3] = 0;
#endif
    }
#if defined(jpn)
    arg0->unknown1_d8c_ = 0;
    arg0->unknown_d8d_ = 0;
#else
    arg0->unknown_db0_ = NULL;
    arg0->unknown_db4_ = func_020424e4((int)data_ov009_0218aca4, 0);
#endif
    arg0->unknown_db6_ = 0;
#if defined(jpn)
    arg0->unknown_d8f_ = 0;
#endif
}
