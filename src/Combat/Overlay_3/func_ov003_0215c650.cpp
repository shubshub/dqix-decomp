#include <globaldefs.h>
#include "Resource/KeyTable.h"
#include "Memory/SafeAllocator.h"
#include "GameState/GameState.h"
#include "Graphics/LightingManager.h"
#include "NitroSDK/Graphics.h"
#include "Combat/MapDisplay.h"

struct Struct_02074af4 {
    unsigned short unknown_0_;
    char unknown_2_[2];
    unsigned short unknown_4_;
    char unknown_6_[2];
    unsigned short unknown_8_;
    char unknown_a_[2];
    unsigned short unknown_c_;
    char unknown_e_[2];
    unsigned char unknown_10_;
    unsigned char unknown_11_;
};

struct InitTarget0205cfd4 {
    char data[0xbc];
};

struct Struct_02000c9c_83 {
    char unknown_0_[0xe0];
};

struct Struct_ov003_0215c650 {
    SafeAllocator unknown_0_;
    SafeAllocator unknown_14_;
    SafeAllocator unknown_28_;
    SafeAllocator unknown_3c_;
    SafeAllocator unknown_50_;
    struct Struct_0201099c_14 unknown_64_;
#if defined(jpn)
    struct Struct_0201099c_14 unknown_7c_;
#endif
    void* textBuf;
    struct MainBgControlBackup02074af4 bgBackup;
    int savedBgPlanes;
    struct InitTarget0205cfd4 sub98;
    struct BackgroundGraphics lists[2];
    struct Elem0204c684 elems[2];
    int field354;
    char sub358[0x3ac - 0x358];
    int field3ac;
    int field3b0;
    int field3b4;
    unsigned char field3b8;
    unsigned char field3b9;
    unsigned char field3ba;
    unsigned char field3bb;
    unsigned char field3bc;
    unsigned char field3bd[3];
    unsigned char field3c0;
    signed char field3c1;
    unsigned char field3c2;
    unsigned char field3c3;
    unsigned char field3c4[4];
    int field3c8;
    int field3cc;
    int timeOfDay;
    float nightToMorning;
    float morningToDay;
    float dayToEvening;
    float eveningToNight;
    float transitionTime;
    int field3e8;
    unsigned char field3ec;
    unsigned char field3ed;
    unsigned char field3ee;
    unsigned char field3ef;
    unsigned char field3f0;
    unsigned char field3f1;
    unsigned char field3f2;
    unsigned char field3f3;
    unsigned char field3f4;
    unsigned char field3f5;
    int field3f8;
};

extern "C" void func_02074af4(struct MainBgControlBackup02074af4* obj);
void KeyTable_Reset(struct Struct020dfc40* p);
void Window_Init(struct InitTarget0205cfd4* s);
void Background_Init(struct BackgroundGraphics* obj);
extern "C" void WindowPane_Init(struct Elem0204c684* obj);
void SpriteContext_Init(char* obj);

// USA: func_ov003_0215c650
extern "C" ARM void func_ov003_0215c650(struct Struct_ov003_0215c650* arg0) {
    arg0->unknown_80_.unknown_10_ = 0;
    arg0->unknown_80_.unknown_11_ = 0;
    func_02074af4(&arg0->unknown_80_);
    arg0->unknown_94_ = (DISPCNT & 0x1f00) >> 8;
    DISPCNT = (DISPCNT & ~0x1f00) | 0x100;

    self->alloc0.ResetAllocatorPointer();
    self->alloc28.ResetAllocatorPointer();
    self->alloc3c.ResetAllocatorPointer();
    self->alloc50.ResetAllocatorPointer();
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

    self->field354 = 0;
    SpriteContext_Init(self->sub358);
    self->field3ac = 0;
    self->field3b0 = 0;
    self->field3b4 = 0;
    self->field3b8 = 0;
    self->field3b9 = 0;
    self->field3bc = 0;
    self->field3ba = 0;
    self->field3bb = 0;
    for (int k = 0; k < 3; k++) {
        self->field3bd[k] = 0xff;
    }
    arg0->unknown_3c0_ = 0;
    arg0->unknown_3c1_ = -1;
    arg0->unknown_3c2_ = 0;
    arg0->unknown_3c3_ = 0;
    for (int var3 = 0; var3 < 4; var3++) {
        arg0->unknown_3c4_[var3] = 0xff;
    }
    arg0->unknown_3c8_ = -1;
    arg0->unknown_3cc_ = -1;
    GetDayThresholds(&arg0->unknown_3d4_, &arg0->unknown_3d8_, &arg0->unknown_3dc_,
                     &arg0->unknown_3e0_, &arg0->unknown_3e4_);
    arg0->unknown_3d0_ = GameState::GetInstance()->IsMorningDayOrEvening();
    arg0->unknown_3ec_ = 0;
    arg0->unknown_3ed_ = 0;
    arg0->unknown_3ee_ = 0;
    arg0->unknown_3ef_ = 1;
    arg0->unknown_3f0_ = 0;
    arg0->unknown_3f1_ = 0;
    arg0->unknown_3f2_ = 0;
    arg0->unknown_3f3_ = 0;
    arg0->unknown_3f8_ = 0;
    arg0->unknown_3f4_ = 0;
    arg0->unknown_3f5_ = 0;
    arg0->unknown_3e8_ = 0;
}
