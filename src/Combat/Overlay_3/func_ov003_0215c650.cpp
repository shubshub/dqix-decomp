#include <globaldefs.h>
#include "Resource/KeyTable.h"
#include "Memory/SafeAllocator.h"
#include "GameState/GameState.h"
#include "Graphics/LightingManager.h"
#include "NitroSDK/Graphics.h"
#include "Combat/MapDisplay.h"

struct Struct_02074af4 {
    unsigned short unknown_0_;
    char pad2[2];
    unsigned short unknown_4_;
    char pad6[2];
    unsigned short unknown_8_;
    char padA[2];
    unsigned short unknown_c_;
    char unknown_e_[2];
    unsigned char initialized;
    unsigned char unknown_11_;
};

struct InitTarget0205cfd4 {
    char data[0xbc];
};

struct Elem0204c684 {
    char data[0xe0];
};

struct Struct_ov003_0215c650 {
    SafeAllocator unknown_0_;
    SafeAllocator unknown_14_;
    SafeAllocator alloc28;
    SafeAllocator alloc3c;
    SafeAllocator unknown_50_;
    struct Struct020dfc40 sub64;
#if defined(jpn)
    struct Struct020dfc40 sub7c;
#endif
    void* textBuf;
    struct Struct_02074af4 unknown_80_;
    int unknown_94_;
    struct InitTarget0205cfd4 sub98;
    struct BackgroundGraphics lists[2];
    struct Elem0204c684 elems[2];
    int unknown_354_;
    char sub358[0x3ac - 0x358];
    int unknown_3ac_;
    int unknown_3b0_;
    int unknown_3b4_;
    unsigned char unknown_3b8_;
    unsigned char unknown_3b9_;
    unsigned char unknown_3ba_;
    unsigned char unknown_3bb_;
    unsigned char unknown_3bc_;
    unsigned char unknown_3bd_[3];
    unsigned char unknown_3c0_;
    signed char unknown_3c1_;
    unsigned char unknown_3c2_;
    unsigned char unknown_3c3_;
    unsigned char unknown_3c4_[4];
    int unknown_3c8_;
    int unknown_3cc_;
    int timeOfDay;
    float unknown_3d4_;
    float unknown_3d8_;
    float unknown_3dc_;
    float unknown_3e0_;
    float unknown_3e4_;
    int unknown_3e8_;
    unsigned char unknown_3ec_;
    unsigned char unknown_3ed_;
    unsigned char unknown_3ee_;
    unsigned char unknown_3ef_;
    unsigned char unknown_3f0_;
    unsigned char unknown_3f1_;
    unsigned char unknown_3f2_;
    unsigned char unknown_3f3_;
    unsigned char unknown_3f4_;
    unsigned char unknown_3f5_;
    int field3f8;
};

extern "C" void func_02074af4(struct Struct_02074af4* obj);
extern "C" void KeyTable_Reset(struct Struct020dfc40* p);
extern "C" void Window_Init(struct InitTarget0205cfd4* s);
extern "C" void Background_Init(struct BackgroundGraphics* obj);
extern "C" void WindowPane_Init(struct Elem0204c684* obj);
extern "C" void SpriteContext_Init(char* obj);

// USA: func_ov003_0215c650
extern "C" ARM void func_ov003_0215c650(struct Struct_ov003_0215c650* self) {
    self->unknown_80_.initialized = 0;
    self->unknown_80_.unknown_11_ = 0;
    func_02074af4(&self->unknown_80_);
    self->unknown_94_ = (DISPCNT & 0x1f00) >> 8;
    DISPCNT = (DISPCNT & ~0x1f00) | 0x100;

    self->unknown_0_.ResetAllocatorPointer();
    self->alloc28.ResetAllocatorPointer();
    self->alloc3c.ResetAllocatorPointer();
    self->unknown_50_.ResetAllocatorPointer();
    KeyTable_Reset(&self->sub64);
#if defined(jpn)
    KeyTable_Reset(&self->sub7c);
#endif
    self->textBuf = 0;
    Window_Init(&self->sub98);

    for (int i = 0; i < 2; i++) {
        Background_Init(&self->lists[i]);
    }
    for (int j = 0; j < 2; j++) {
        WindowPane_Init(&self->elems[j]);
    }

    self->unknown_354_ = 0;
    SpriteContext_Init(self->sub358);
    self->unknown_3ac_ = 0;
    self->unknown_3b0_ = 0;
    self->unknown_3b4_ = 0;
    self->unknown_3b8_ = 0;
    self->unknown_3b9_ = 0;
    self->unknown_3bc_ = 0;
    self->unknown_3ba_ = 0;
    self->unknown_3bb_ = 0;
    for (int k = 0; k < 3; k++) {
        self->unknown_3bd_[k] = 0xff;
    }
    self->unknown_3c0_ = 0;
    self->unknown_3c1_ = -1;
    self->unknown_3c2_ = 0;
    self->unknown_3c3_ = 0;
    for (int m = 0; m < 4; m++) {
        self->unknown_3c4_[m] = 0xff;
    }
    self->unknown_3c8_ = -1;
    self->unknown_3cc_ = -1;
    GetDayThresholds(&self->unknown_3d4_, &self->unknown_3d8_, &self->unknown_3dc_,
                     &self->unknown_3e0_, &self->unknown_3e4_);
    self->timeOfDay = GameState::GetInstance()->IsMorningDayOrEvening();
    self->unknown_3ec_ = 0;
    self->unknown_3ed_ = 0;
    self->unknown_3ee_ = 0;
    self->unknown_3ef_ = 1;
    self->unknown_3f0_ = 0;
    self->unknown_3f1_ = 0;
    self->unknown_3f2_ = 0;
    self->unknown_3f3_ = 0;
    self->field3f8 = 0;
    self->unknown_3f4_ = 0;
    self->unknown_3f5_ = 0;
    self->unknown_3e8_ = 0;
}
