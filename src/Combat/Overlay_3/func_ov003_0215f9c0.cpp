#include <globaldefs.h>
#include "Resource/KeyTable.h"
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Graphics.h"

#if defined(jpn)
enum { Enum_ov003_0215f9c0_550 = 0x10e };
#else
enum { Enum_ov003_0215f9c0_550 = 0x226 };
#endif

struct Struct_02074af4 {
    unsigned short unknown_0_[8];
    unsigned char initialized;
    unsigned char unknown_11_;
    char unk_12[2];
};
struct Struct_02081ee4 {
    char unk_0[0xc];
};
struct Struct_02081ee4_2 {
    char unk_0[4];
};
struct Struct020a9ea4 {
    char unk_0[8];
};

extern "C" void func_02074af4(struct Struct_02074af4* obj);
extern "C" void SpriteContext_Init(char* obj);
extern "C" void func_02081ee4(struct Struct_02081ee4* obj, struct Struct_02081ee4_2* sub);
extern "C" void KeyTable_Reset(struct Struct020dfc40* p);
extern "C" void func_020a9ea4(struct Struct020a9ea4* p);

struct Struct_ov003_0215f9c0 {
    char buffer[Enum_ov003_0215f9c0_550];
    unsigned short unknown_226_;
    SafeAllocator allocA;
    SafeAllocator unknown_23c_;
    SafeAllocator unknown_250_;
    SafeAllocator unknown_264_;
    SafeAllocator unknown_278_;
    SafeAllocator unknown_28c_;
    SafeAllocator unknown_2a0_;
    SafeAllocator unknown_2b4_;
    char unknown_2c8_[0x2dc - 0x2c8];
    struct Struct020dfc40 unk_2dc;
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
    char unk_334[0x388 - 0x334];
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
    int flags;
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
    unsigned char unk_4a4;
    unsigned char unknown_4a5_;
    unsigned char unknown_4a6_;
    unsigned char unknown_4a7_;
    unsigned char unknown_4a8_;
    char unknown_4a9_[0x4b0 - 0x4a9];
    int unknown_4b0_;
    struct Struct020a9ea4 unknown_4b4_;
    unsigned char unknown_4bc_;
    unsigned char unknown_4bd_;
    unsigned char unknown_4be_;
    unsigned char unknown_4bf_;
    unsigned char unknown_4c0_;
};

// USA: func_ov003_0215f9c0
extern "C" ARM void func_ov003_0215f9c0(struct Struct_ov003_0215f9c0* self, int arg1) {
    memset(self->buffer, 0, sizeof(self->buffer));
    self->unknown_226_ = 0;
    self->allocA.ResetAllocatorPointer();
    self->unknown_23c_.ResetAllocatorPointer();
    self->unknown_264_.ResetAllocatorPointer();
    self->unknown_278_.ResetAllocatorPointer();
    self->unknown_28c_.ResetAllocatorPointer();
    self->unknown_2a0_.ResetAllocatorPointer();
    self->unknown_2b4_.ResetAllocatorPointer();
    self->unknown_2f4_.initialized = 0;
    self->unknown_2f4_.unknown_11_ = 0;
    func_02074af4(&self->unknown_2f4_);
    self->unknown_330_ = (DISPCNT & 0x1f00) >> 8;
    DISPCNT = (DISPCNT & ~0x1f00) | 0x100;
    SpriteContext_Init(self->unk_334);
    self->unknown_388_ = 0;
    func_02081ee4(&self->unknown_308_, &self->unknown_314_);
    KeyTable_Reset(&self->unk_2dc);
    self->unknown_318_ = 0;
    self->unknown_31c_ = 0;
    self->unknown_320_ = 0;
    self->unknown_324_ = 0;
    self->unknown_328_ = 0;
    self->unknown_32c_ = 0;
    self->unknown_390_ = 0;
    self->unknown_394_ = 0;
    self->unknown_398_ = 0;
    self->unknown_45c_ = 0;
    self->unknown_460_ = 0;
    self->flags = 0;
    memset(self->unknown_468_, 0, sizeof(self->unknown_468_));
    self->unknown_46c_ = -1;
    self->unknown_470_ = 0;
    self->unknown_474_ = -1;
    self->unknown_476_ = 0;
    self->unknown_478_ = 0;
    self->unknown_47a_ = 0;
    self->unknown_47c_ = -1;
    self->unknown_47e_ = -1;
    self->unknown_480_ = -1;
    self->unknown_482_ = -1;
    self->unknown_484_ = self->unknown_486_ = -1;
    self->unknown_48a_ = -1;
    self->unknown_48e_ = -1;
    self->unknown_490_ = -1;
    self->unknown_492_ = -1;
    self->unknown_494_ = -1;
    self->unknown_496_ = -1;
    self->unknown_498_ = -1;
    self->unknown_49a_ = -1;
    self->unknown_49c_ = -1;
    self->unknown_488_ = -1;
    self->unknown_49f_ = 0;
    self->unknown_4a0_ = 0;
    self->unknown_4a1_ = 0;
    self->unknown_4a2_ = -1;
    self->unknown_4a3_ = 0;
    self->unk_4a4 = 0;
    self->unknown_4a5_ = 0;
    self->unknown_4a6_ = 0;
    self->unknown_4a7_ = 0;
    self->unknown_4a8_ = 0;
    self->unknown_4b0_ = 0;
    func_020a9ea4(&self->unknown_4b4_);
    self->unknown_4bc_ = 0;
    if (arg1) {
        self->flags |= 0x30000;
    }
    self->unknown_4bd_ = 0xff;
    self->unknown_4be_ = 0;
    self->unknown_4bf_ = 0;
    self->unknown_4c0_ = 0;
}
