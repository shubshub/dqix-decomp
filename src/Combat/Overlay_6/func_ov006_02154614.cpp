#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include <std_library_functions.h>
#include "Memory/SafeAllocator.h"
#include "World/Object3D.h"

struct Struct_020dbd9c {
    char unknown_0_[0x10];
    int unknown_10_;
    unsigned char unknown_14_;
};

struct Struct_ov006_02154614_2 {
    char unknown_0_[R(0x6f0,0x774)];
    unsigned short unknown_774_;
    char unknown_776_[0x7];
    signed char unknown_77d_;
    char unknown_77e_[0x1d];
    unsigned char unknown_79b_0_ : 1;
    unsigned char unknown_79b_1_ : 1;
};

struct Struct_ov006_02156e54 {
    char unknown_0_[0x7c];
};

struct Struct_ov006_02154614 {
#if !defined(jpn)
    char unknown_0_[3][0x80];
#endif
    SafeAllocator* unknown_180_;
    SafeAllocator* unknown_184_;
    SafeAllocator* unknown_188_;
    SafeAllocator unknown_18c_;
    void* unknown_1a0_;
    void* unknown_1a4_;
    unsigned char* unknown_1a8_;
    void* unknown_1ac_;
    void* unknown_1b0_;
    void* unknown_1b4_;
    void* unknown_1b8_;
    int unknown_1bc_;
    void* unknown_1c0_;
    unsigned char* unknown_1c4_;
    void* unknown_1c8_;
    void* unknown_1cc_;
    void* unknown_1d0_;
    void* unknown_1d4_;
    void* unknown_1d8_;
    void* unknown_1dc_;
    void* unknown_1e0_;
    char unknown_1e4_[0x54];
    Object3D unknown_238_;
    Object3D unknown_2e4_;
    Object3D unknown_390_;
    Object3D unknown_43c_;
    Object3D unknown_4e8_;
    char unknown_594_[0x38];
    char unknown_5cc_[0x2c8];
    Struct_ov006_02156e54 unknown_894_[4];
    SafeAllocator unknown_a84_[4];
    int unknown_ad4_;
    int unknown_ad8_;
    unsigned char unknown_adc_;
    unsigned char unknown_add_;
    unsigned char unknown_ade_;
    unsigned char unknown_adf_;
    unsigned char unknown_ae0_;
    unsigned char unknown_ae1_;
    unsigned short unknown_ae2_;
    Struct_ov006_02154614_2 unknown_ae4_;
    SafeAllocator* unknown_1280_;
    SafeAllocator* unknown_1284_;
    char unknown_1288_[0x18];
    Struct_020dbd9c unknown_12a0_;
    short unknown_12b8_;
    signed char unknown_12ba_;
    unsigned char unknown_12bb_;
    unsigned char unknown_12bc_;
    unsigned char unknown_12bd_;
};

extern "C" void func_ov023_021dc134(ItemInfoWindow* window, short item, signed char mode);
void SpriteContext_Init(char* renderer);
extern "C" void func_ov006_0215479c(IngredientSprite* sprite);
void InitStruct020dbd9c(Struct020dbd9c* effect);

// USA: func_ov006_02154614
extern "C" ARM void func_ov006_02154614(Struct_ov006_02154614* arg0) {
#if !defined(jpn)
    memset(arg0->unknown_0_, 0, sizeof(arg0->unknown_0_));
#endif
    self->allocators_ = 0;
    self->itemAllocator_ = 0;
    self->nextItemAllocator_ = 0;
    self->previousCamera_ = 0;
    self->amounts_ = 0;
    self->itemNames_ = 0;
    self->texts_ = 0;
    self->recipe_ = 0;
    self->nextRecipe_ = 0;
    self->unk_1bc = 0;
    self->record_ = 0;
    self->unk_1c4 = 0;
    self->layout_ = 0;
    self->backgrounds_ = 0;
    self->canvases_ = 0;
    self->menu_ = 0;
    self->item_ = 0;
    self->nextItem_ = 0;
    self->sprites_ = 0;
    self->windowSpriteAllocator_ = 0;
    self->windowAllocator_ = 0;
    func_ov023_021dc134(&self->window_, -1, 1);
    self->window_.flags_ |= 0x10 | 0x200;
    SpriteContext_Init(self->renderer_);
    self->protagonist_.Initialize();
    self->pot_.Initialize();
    self->lid_.Initialize();
    self->effect_.Initialize();
    self->steam_.Initialize();
    memset(self->unk_594, 0, sizeof(self->unk_594));
    self->effectAllocator_.ResetAllocatorPointer();
    for (unsigned char i = 0; i < 4; i++) {
        func_ov006_0215479c(&self->ingredients_[i]);
        self->ingredientAllocators_[i].ResetAllocatorPointer();
    }
    arg0->unknown_ad4_ = -1;
    arg0->unknown_ad8_ = -1;
    arg0->unknown_adc_ = 0;
    arg0->unknown_add_ = 0;
    arg0->unknown_ade_ = 0;
    arg0->unknown_adf_ = 0;
    arg0->unknown_ae0_ = 0;
    arg0->unknown_ae2_ = 0;
    arg0->unknown_12bb_ = 0;
    arg0->unknown_12b8_ = 0;
    arg0->unknown_12ba_ = 0;
    arg0->unknown_12bc_ = 0;
    func_020dbd9c(&arg0->unknown_12a0_);
    arg0->unknown_12bd_ = 0;
}
