#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Graphics.h"

#if defined(jpn)
enum { Enum_ov003_0215f9c0_550 = 0x10e };
#else
enum { Enum_ov003_0215f9c0_550 = 0x226 };
#endif

struct Struct_0201099c_14 {
    char unknown_0_[0x18];
};
struct Struct_02074af4 {
    unsigned short unknown_0_[8];
    unsigned char unknown_10_;
    unsigned char unknown_11_;
    char unknown_12_[2];
};
struct Struct_02081ee4 {
    char unknown_0_[0xc];
};
struct Struct_02081ee4_2 {
    char unknown_0_[4];
};
struct Struct_020a9ea4 {
    char unknown_0_[8];
};

extern "C" void func_02074af4(struct MainBgControlBackup02074af4* obj);
void SpriteContext_Init(char* obj);
void InitWithSub02081ee4(struct Obj02081ee4* obj, struct Sub02081ee4* sub);
void KeyTable_Reset(struct Struct020dfc40* p);
void ClearStruct020a9ea4(struct Struct020a9ea4* p);

struct Struct_ov003_0215f9c0 {
    char unknown_0_[Enum_ov003_0215f9c0_550];
    unsigned short unknown_226_;
    SafeAllocator unknown_228_;
    SafeAllocator unknown_23c_;
    SafeAllocator unknown_250_;
    SafeAllocator unknown_264_;
    SafeAllocator unknown_278_;
    SafeAllocator unknown_28c_;
    SafeAllocator unknown_2a0_;
    SafeAllocator unknown_2b4_;
    char unknown_2c8_[0x2dc - 0x2c8];
    struct Struct_0201099c_14 unknown_2dc_;
    struct Struct_02074af4 unknown_2f4_;
    struct Struct_02081ee4 unknown_308_;
    struct Struct_02081ee4_2 unknown_314_;
    int unknown_318_;
    int unknown_31c_;
    int unknown_320_;
    int unknown_324_;
    int unknown_328_;
    int unknown_32c_;
    int unknown_330_;
    char unknown_334_[0x388 - 0x334];
    int unknown_388_;
    char unknown_38c_[4];
    int unknown_390_;
    int unknown_394_;
    int unknown_398_;
#if !defined(jpn)
    char unknown_39c_[0x45c - 0x39c];
#endif
    int unknown_45c_;
    int unknown_460_;
    int unknown_464_;
    unsigned char unknown_468_[4];
    int unknown_46c_;
    int unknown_470_;
    short unknown_474_;
    short unknown_476_;
    short unknown_478_;
    short unknown_47a_;
    short unknown_47c_;
    short unknown_47e_;
    short unknown_480_;
    short unknown_482_;
    short unknown_484_;
    short unknown_486_;
    short unknown_488_;
    short unknown_48a_;
    char unknown_48c_[2];
    short unknown_48e_;
    short unknown_490_;
    short unknown_492_;
    short unknown_494_;
    short unknown_496_;
    short unknown_498_;
    short unknown_49a_;
    short unknown_49c_;
    char unknown_49e_;
    unsigned char unknown_49f_;
    unsigned char unknown_4a0_;
    unsigned char unknown_4a1_;
    signed char unknown_4a2_;
    unsigned char unknown_4a3_;
    unsigned char unknown_4a4_;
    unsigned char unknown_4a5_;
    unsigned char unknown_4a6_;
    unsigned char unknown_4a7_;
    unsigned char unknown_4a8_;
    char unknown_4a9_[0x4b0 - 0x4a9];
    int unknown_4b0_;
    struct Struct_020a9ea4 unknown_4b4_;
    unsigned char unknown_4bc_;
    unsigned char unknown_4bd_;
    unsigned char unknown_4be_;
    unsigned char unknown_4bf_;
    unsigned char unknown_4c0_;
};

// USA: func_ov003_0215f9c0
extern "C" ARM void func_ov003_0215f9c0(struct Struct_ov003_0215f9c0* arg0, int arg1) {
    memset(arg0->unknown_0_, 0, sizeof(arg0->unknown_0_));
    arg0->unknown_226_ = 0;
    arg0->unknown_228_.ResetAllocatorPointer();
    arg0->unknown_23c_.ResetAllocatorPointer();
    arg0->unknown_264_.ResetAllocatorPointer();
    arg0->unknown_278_.ResetAllocatorPointer();
    arg0->unknown_28c_.ResetAllocatorPointer();
    arg0->unknown_2a0_.ResetAllocatorPointer();
    arg0->unknown_2b4_.ResetAllocatorPointer();
    arg0->unknown_2f4_.unknown_10_ = 0;
    arg0->unknown_2f4_.unknown_11_ = 0;
    func_02074af4(&arg0->unknown_2f4_);
    arg0->unknown_330_ = (DISPCNT & 0x1f00) >> 8;
    DISPCNT = (DISPCNT & ~0x1f00) | 0x100;
    SpriteContext_Init(self->unk_334);
    self->unk_388 = 0;
    InitWithSub02081ee4(&self->unk_308, &self->unk_314);
    KeyTable_Reset(&self->unk_2dc);
    self->unk_318 = 0;
    self->unk_31c = 0;
    self->unk_320 = 0;
    self->unk_324 = 0;
    self->unk_328 = 0;
    self->unk_32c = 0;
    self->unk_390 = 0;
    self->unk_394 = 0;
    self->unk_398 = 0;
    self->unk_45c = 0;
    self->unk_460 = 0;
    self->flags = 0;
    memset(self->unk_468, 0, sizeof(self->unk_468));
    self->unk_46c = -1;
    self->unk_470 = 0;
    self->unk_474 = -1;
    self->unk_476 = 0;
    self->unk_478 = 0;
    self->unk_47a = 0;
    self->unk_47c = -1;
    self->unk_47e = -1;
    self->unk_480 = -1;
    self->unk_482 = -1;
    self->unk_484 = self->unk_486 = -1;
    self->unk_48a = -1;
    self->unk_48e = -1;
    self->unk_490 = -1;
    self->unk_492 = -1;
    self->unk_494 = -1;
    self->unk_496 = -1;
    self->unk_498 = -1;
    self->unk_49a = -1;
    self->unk_49c = -1;
    self->unk_488 = -1;
    self->unk_49f = 0;
    self->unk_4a0 = 0;
    self->unk_4a1 = 0;
    self->unk_4a2 = -1;
    self->unk_4a3 = 0;
    self->unk_4a4 = 0;
    self->unk_4a5 = 0;
    self->unk_4a6 = 0;
    self->unk_4a7 = 0;
    self->unk_4a8 = 0;
    self->unk_4b0 = 0;
    ClearStruct020a9ea4(&self->unk_4b4);
    self->unk_4bc = 0;
    if (setFlags) {
        self->flags |= 0x30000;
    }
    arg0->unknown_4bd_ = 0xff;
    arg0->unknown_4be_ = 0;
    arg0->unknown_4bf_ = 0;
    arg0->unknown_4c0_ = 0;
}
