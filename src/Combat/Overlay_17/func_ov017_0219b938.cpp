#include <globaldefs.h>
#include "Graphics/Model3D.h"
#include "Memory/SafeAllocator.h"

struct Struct_020966a0;
struct Struct_0203d028;

struct Struct_ov017_0219b938 {
#if defined(jpn)
    char unknown_0_[0x4b8];
#else
    char unknown1_0_[0x498];
#endif
    Model3D unknown_498_[2];

    Model3D* inline_ov017_0219b938(int arg0) { return &unknown_498_[arg0]; }
};

extern "C" struct ZoneStruct0219b938* Zone3D_GetInstance(void);
void InvokeAllEntries020966a0(struct Entry020966a0* entries);
extern "C" void SprSprite_Init(void* p);
void* GetData02109020_0208e9e8(void);
extern "C" void func_0208f36c(void* p, int value);
void VramState_Rewind(struct Foo0207df50* p);

struct Struct_ov017_021d64b0 {
    int unknown_0_[17];
};

extern struct Struct_ov017_021d64b0 data_ov017_021d64b0;

struct Struct_02000c9c_55 {
    char unknown_0_[0x88];
};

struct Struct_ov017_0219b938_2 {
    char unknown_0_[0x9c];
    SafeAllocator unknown_9c_;
#if defined(jpn)
    char unknown1_b0_[0x4ac - 0x9c - sizeof(SafeAllocator)];
    char unknown_4fc_[0x2980 - 0x4ac];
#else
    char unknown_b0_[0x4fc - 0x9c - sizeof(SafeAllocator)];
    char unknown_4fc_[0x2b90 - 0x4fc];
#endif
    struct Struct_02000c9c_55 unknown_2b90_[0x14];
#if defined(jpn)
    char unknown_3420_[0x4108 - 0x2980 - 0x14 * 0x88];
#else
    char unknown_3630_[0x4328 - 0x2b90 - 0x14 * 0x88];
#endif
    struct Struct_020966a0* unknown_4328_;
};

// USA: func_ov017_0219b938
extern "C" ARM void func_ov017_0219b938(struct Battle0219b938* self) {
    struct ZoneStruct0219b938* zone = Zone3D_GetInstance();
    zone->GetModel(0)->Func0207e2e0();
    zone->GetModel(1)->Func0207e2e0();
    InvokeAllEntries020966a0(self->callbacks);
    struct EntryIdList0219b938 list = data_ov017_021d64b0;
    int i;
    for (i = 0; list.ids[i] >= 0; i++) {
        SprSprite_Init(&self->entries[list.ids[i]]);
    }
    SprSprite_Init(&self->entries[0x12]);
    SprSprite_Init(&self->entries[0x13]);
    func_0208f36c(GetData02109020_0208e9e8(), 0);
    self->allocator.Reset();
    VramState_Rewind((struct Foo0207df50*)self->fields4fc);
}
