#if defined(jpn)
#define R(j,u) (j)
#define data_ov015_02193d14 data_ov015_02194844
#define data_ov015_02193d2c data_ov015_0219485c
#define data_ov015_02193d38 data_ov015_02194868
#define data_ov027_021dd8e0 data_ov027_021de1a0
#define func_ov014_0218854c func_ov014_0218942c
#define func_ov014_021885bc func_ov014_0218948c
#define func_ov015_0219050c func_ov015_021910b0
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include <Memory/SafeAllocator.h>
#include <NitroSDK/Graphics.h>

struct Struct020dfc40;
struct BackgroundGraphics;
struct InitTarget0205cfd4;
struct Struct020a9ea4;

struct Struct_ov003_02158bb8_2 {
    char unknown_0_[0x10];
    unsigned char initialized;
    unsigned char unknown_11_;
    char pad12[2];
};

extern "C" void func_02074af4(Struct_ov003_02158bb8_2* state);
extern "C" void WindowPane_Init(void* canvas);
extern "C" void SpriteContext_Init(char* obj);
extern "C" void Window_Init(InitTarget0205cfd4* window);
extern "C" void Background_Init(BackgroundGraphics* background);
extern "C" void KeyTable_Reset(Struct020dfc40* texts);
extern "C" void func_020a9ea4(Struct020a9ea4* p);

struct Struct_ov003_02158bb8 {
    SafeAllocator unknown_0_;
    SafeAllocator unknown_14_;
    SafeAllocator alloc28;
    SafeAllocator alloc3c;
    SafeAllocator unknown_50_;
    char texts[0x80 - 0x64];
    Struct_ov003_02158bb8_2 unknown_80_;
    int layers;
    char field_0x98[0xec - 0x98];
    void* entries;
    void* unknown_f0_;
    char window[0x1b0 - 0xf4];
    char backgrounds[2][0x20];
    char canvases[4][0xe0];
    void* entryManager;
    char unknown_574_[0x580 - 0x574];
    unsigned char unknown_580_;
    unsigned char unknown_581_;
    unsigned char field_0x582;
    unsigned char unknown_583_;
    unsigned char unknown_584_;
    signed char unknown_585_;
    unsigned char unknown_586_;
    unsigned char unknown_587_;
    unsigned char unknown_588_;
    unsigned char unknown_589_;
    signed char unknown_58a_[6];
    unsigned char unknown_590_;
    unsigned char unknown_591_[4];
    char unknown_595_[0x598 - 0x595];
    int unknown_598_;
    unsigned char unknown_59c_;
    unsigned char unknown_59d_;
    unsigned char unknown_59e_;
    unsigned char unknown_59f_;
    unsigned char unknown_5a0_;
    signed char unknown_5a1_;
    char unknown_5a2_[2];
    int unknown_5a4_;
    int unknown_5a8_;
    int unknown_5ac_;
    unsigned char unknown_5b0_;
    unsigned char unknown_5b1_;
    unsigned char unknown_5b2_;
    unsigned char unknown_5b3_;
    unsigned char unknown_5b4_;
    char unknown_5b5_[3];
    char unknown_5b8_[4];
};

// USA: func_ov003_02158bb8
extern "C" ARM void func_ov003_02158bb8(Struct_ov003_02158bb8* self)
{
    self->unknown_80_.initialized = 0;
    self->unknown_80_.unknown_11_ = 0;
    func_02074af4(&self->unknown_80_);
    self->layers = (DISPCNT & 0x1f00) >> 8;
    DISPCNT = (DISPCNT & ~0x1f00) | 0x100;
    SpriteContext_Init(self->field_0x98);
    self->entries = NULL;
    self->unknown_f0_ = NULL;
    self->alloc3c.ResetAllocatorPointer();
    self->alloc28.ResetAllocatorPointer();
    self->unknown_14_.ResetAllocatorPointer();
    self->unknown_0_.ResetAllocatorPointer();
    Window_Init((InitTarget0205cfd4*)self->window);
    for (int i = 0; i < 2; i++) {
        Background_Init((BackgroundGraphics*)self->backgrounds[i]);
    }
    for (int i = 0; i < 4; i++) {
        WindowPane_Init(self->canvases[i]);
    }
    KeyTable_Reset((Struct020dfc40*)self->texts);
    self->unknown_587_ = 0;
    self->unknown_588_ = 0;
    self->unknown_580_ = 0;
    self->unknown_581_ = 0;
    self->unknown_589_ = 0;
    for (int i = 0; i < 6; i++) {
        self->unknown_58a_[i] = -1;
    }
    self->unknown_590_ = 0;
    for (int i = 0; i < 4; i++) {
        self->unknown_591_[i] = 0xff;
    }
    self->unknown_584_ = 0;
    self->unknown_585_ = -1;
    self->unknown_586_ = 0;
    self->unknown_5a1_ = -1;
    self->unknown_5a4_ = 0;
    self->unknown_5a8_ = 0;
    self->unknown_5ac_ = 0;
    self->unknown_59c_ = 0;
    self->field_0x582 = 0;
    self->unknown_583_ = 0;
    self->unknown_59d_ = 0;
    self->unknown_59e_ = 0;
    self->entryManager = NULL;
    self->unknown_59f_ = 0;
    self->unknown_5a0_ = 0;
    self->unknown_5b0_ = 0;
    self->unknown_5b1_ = 0;
    self->unknown_5b2_ = 1;
    self->unknown_5b3_ = 0;
    self->unknown_5b4_ = 0;
    func_020a9ea4((Struct020a9ea4*)self->unknown_5b8_);
    self->unknown_598_ = 0;
}
