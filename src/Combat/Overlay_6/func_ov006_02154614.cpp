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
    char unk_0[0x10];
    int state_;
    unsigned char unk_14;
};

struct Struct_ov006_02154614_2 {
    char unk_0[R(0x6f0,0x774)];
    unsigned short flags_;
    char unknown_776_[0x7];
    signed char unknown_77d_;
    char unknown_77e_[0x1d];
    unsigned char unknown_79b_0_ : 1;
    unsigned char unknown_79b_1_ : 1;
};

struct Struct_ov006_02156e54 {
    char unk_0[0x7c];
};

struct Struct_ov006_02154614 {
#if !defined(jpn)
    char names_[3][0x80];
#endif
    SafeAllocator* allocators_;
    SafeAllocator* unknown_184_;
    SafeAllocator* unknown_188_;
    SafeAllocator unknown_18c_;
    void* previousCamera_;
    void* canvasBuffer_;
    unsigned char* unknown_1a8_;
    void* itemNames_;
    void* texts_;
    void* unknown_1b4_;
    void* nextRecipe_;
    int unknown_1bc_;
    void* unknown_1c0_;
    unsigned char* unknown_1c4_;
    void* layout_;
    void* backgrounds_;
    void* canvases_;
    void* menu_;
    void* item_;
    void* nextItem_;
    void* sprites_;
    char renderer_[0x54];
    Object3D unknown_238_;
    Object3D pot_;
    Object3D unknown_390_;
    Object3D effect_;
    Object3D steam_;
    char unknown_594_[0x38];
    char camera_[0x2c8];
    Struct_ov006_02156e54 ingredients_[4];
    SafeAllocator unknown_a84_[4];
    int task_;
    int unknown_ad8_;
    unsigned char state_;
    unsigned char unknown_add_;
    unsigned char unknown_ade_;
    unsigned char unknown_adf_;
    unsigned char unknown_ae0_;
    unsigned char unknown_ae1_;
    unsigned short flags_;
    Struct_ov006_02154614_2 window_;
    SafeAllocator* unknown_1280_;
    SafeAllocator* unknown_1284_;
    char partNames_[0x18];
    Struct_020dbd9c unknown_12a0_;
    short itemId_;
    signed char unknown_12ba_;
    unsigned char unknown_12bb_;
    unsigned char unknown_12bc_;
    unsigned char unknown_12bd_;
};

extern "C" void func_ov023_021dc134(Struct_ov006_02154614_2* window, short item, signed char mode);
extern "C" void SpriteContext_Init(char* renderer);
extern "C" void func_ov006_0215479c(Struct_ov006_02156e54* sprite);
extern "C" void func_020dbd9c(Struct_020dbd9c* effect);

// USA: func_ov006_02154614
extern "C" ARM void func_ov006_02154614(Struct_ov006_02154614* self) {
#if !defined(jpn)
    memset(self->names_, 0, sizeof(self->names_));
#endif
    self->allocators_ = 0;
    self->unknown_184_ = 0;
    self->unknown_188_ = 0;
    self->previousCamera_ = 0;
    self->unknown_1a8_ = 0;
    self->itemNames_ = 0;
    self->texts_ = 0;
    self->unknown_1b4_ = 0;
    self->nextRecipe_ = 0;
    self->unknown_1bc_ = 0;
    self->unknown_1c0_ = 0;
    self->unknown_1c4_ = 0;
    self->layout_ = 0;
    self->backgrounds_ = 0;
    self->canvases_ = 0;
    self->menu_ = 0;
    self->item_ = 0;
    self->nextItem_ = 0;
    self->sprites_ = 0;
    self->unknown_1284_ = 0;
    self->unknown_1280_ = 0;
    func_ov023_021dc134(&self->window_, -1, 1);
    self->window_.flags_ |= 0x10 | 0x200;
    SpriteContext_Init(self->renderer_);
    self->unknown_238_.Initialize();
    self->pot_.Initialize();
    self->unknown_390_.Initialize();
    self->effect_.Initialize();
    self->steam_.Initialize();
    memset(self->unknown_594_, 0, sizeof(self->unknown_594_));
    self->unknown_18c_.ResetAllocatorPointer();
    for (unsigned char i = 0; i < 4; i++) {
        func_ov006_0215479c(&self->ingredients_[i]);
        self->unknown_a84_[i].ResetAllocatorPointer();
    }
    self->task_ = -1;
    self->unknown_ad8_ = -1;
    self->state_ = 0;
    self->unknown_add_ = 0;
    self->unknown_ade_ = 0;
    self->unknown_adf_ = 0;
    self->unknown_ae0_ = 0;
    self->flags_ = 0;
    self->unknown_12bb_ = 0;
    self->itemId_ = 0;
    self->unknown_12ba_ = 0;
    self->unknown_12bc_ = 0;
    func_020dbd9c(&self->unknown_12a0_);
    self->unknown_12bd_ = 0;
}
