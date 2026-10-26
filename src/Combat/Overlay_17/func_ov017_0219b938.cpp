#include <globaldefs.h>
#include "Graphics/Model3D.h"
#include "Memory/SafeAllocator.h"

struct Struct_020966a0;
struct Foo0207df50;

struct ZoneStruct0219b938 {
#if defined(jpn)
    char pad0[0x4b8];
#else
    char pad0[0x498];
#endif
    Model3D models[2];

    Model3D* inline_ov017_0219b938(int i) { return &models[i]; }
};

extern "C" struct ZoneStruct0219b938* Zone3D_GetInstance(void);
extern "C" void func_020966a0(struct Struct_020966a0* entries);
extern "C" void SprSprite_Init(void* p);
extern "C" void* func_0208e9e8(void);
extern "C" void func_0208f36c(void* p, int value);
extern "C" void VramState_Rewind(struct Foo0207df50* p);

struct Struct_ov017_021d64b0 {
    int ids[17];
};

extern struct Struct_ov017_021d64b0 data_ov017_021d64b0;

struct Struct_02000c9c_55 {
    char data[0x88];
};

struct Struct_ov017_0219b938_2 {
    char pad0[0x9c];
    SafeAllocator allocator;
#if defined(jpn)
    char unknown1_b0_[0x4ac - 0x9c - sizeof(SafeAllocator)];
    char fields4fc[0x2980 - 0x4ac];
#else
    char unknown_b0_[0x4fc - 0x9c - sizeof(SafeAllocator)];
    char fields4fc[0x2b90 - 0x4fc];
#endif
    struct Struct_02000c9c_55 entries[0x14];
#if defined(jpn)
    char unknown_3420_[0x4108 - 0x2980 - 0x14 * 0x88];
#else
    char unknown_3630_[0x4328 - 0x2b90 - 0x14 * 0x88];
#endif
    struct Struct_020966a0* unknown_4328_;
};

// USA: func_ov017_0219b938
extern "C" ARM void func_ov017_0219b938(struct Struct_ov017_0219b938_2* self) {
    struct ZoneStruct0219b938* zone = Zone3D_GetInstance();
    zone->inline_ov017_0219b938(0)->Func0207e2e0();
    zone->inline_ov017_0219b938(1)->Func0207e2e0();
    func_020966a0(self->unknown_4328_);
    struct Struct_ov017_021d64b0 list = data_ov017_021d64b0;
    int i;
    for (i = 0; list.ids[i] >= 0; i++) {
        SprSprite_Init(&self->entries[list.ids[i]]);
    }
    SprSprite_Init(&self->entries[0x12]);
    SprSprite_Init(&self->entries[0x13]);
    func_0208f36c(func_0208e9e8(), 0);
    self->allocator.Reset();
    VramState_Rewind((struct Foo0207df50*)self->fields4fc);
}
