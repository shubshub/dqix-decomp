#include <globaldefs.h>
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

struct Struct_0201099c_14 {
    char unknown_0_[0x18];
};

struct Struct_0205cfd4 {
    char unknown_0_[0xbc];
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
    void* unknown1_7c_;
    struct Struct_02074af4 unknown_80_;
    int unknown_94_;
    struct Struct_0205cfd4 unknown_98_;
    struct Struct_02020cb8 unknown_154_[2];
    struct Struct_02000c9c_83 unknown_194_[2];
    int unknown_354_;
    char unknown_358_[0x3ac - 0x358];
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
    int unknown_3d0_;
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
    int unknown_3f8_;
};

extern "C" void func_02074af4(struct MainBgControlBackup02074af4* obj);
void KeyTable_Reset(struct Struct020dfc40* p);
void InitStruct0205cfd4(struct InitTarget0205cfd4* s);
void Background_Init(struct List0204af64* obj);
extern "C" void func_0204c684(struct Elem0204c684* obj);
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
    arg0->unknown1_7c_ = 0;
    func_0205cfd4(&arg0->unknown_98_);

    for (int i = 0; i < 2; i++) {
        Background_Init(&self->lists[i]);
    }
    for (int var1 = 0; var1 < 2; var1++) {
        func_0204c684(&arg0->unknown_194_[var1]);
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
