#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"

struct Obj0205d048;
struct BackgroundGraphics;
extern "C" void Window_Destroy(struct Obj0205d048* obj);
extern "C" void Background_Destroy(struct BackgroundGraphics* obj);
extern "C" void func_ov000_02170054(void* obj);

#if defined(jpn)
#define SLOT_BYTES 0x488
#define ALLOC_SHIFT 0x100
#define FLAG_SHIFT 0x238
#else
#define SLOT_BYTES 0x448
#define ALLOC_SHIFT 0
#define FLAG_SHIFT 0
#endif
struct Struct_02000c9c_35 {
    char pad0[SLOT_BYTES];
};

struct Struct_ov000_02172720 {
    char pad0[0x188];
    char field_0x188[0x8a4 - 0x188];
    char list8a4[0x20];
    char list8c4[0x20];
    char unknown_8e4_[0x90c - 0x8e4];
    int taskId;
    char unknown_910_[0x958 - 0x910];
    Struct_02000c9c_35 slots[4];
    SafeAllocator unknown_1a78_;
    SafeAllocator unknown_1a8c_;
    SafeAllocator unknown_1aa0_;
    SafeAllocator unknown_1ab4_;
    SafeAllocator unknown_1ac8_;
    SafeAllocator unknown_1adc_;
    char unknown_1af0_[0x1af8 - 0x1af0];
    SafeAllocator unknown_1af8_;
    char unknown_1b0c_[0x1d72 + FLAG_SHIFT - (0x1b0c + ALLOC_SHIFT)];
    unsigned short flags;
};

struct Struct_ov000_02184288 {
    int field0;
    int field4;
    int field8;
};
extern struct Struct_ov000_02184288 data_ov000_02184288;

extern "C" void func_ov000_02172850(Struct_ov000_02172720* self);

// USA: func_ov000_02172720
extern "C" ARM void func_ov000_02172720(Struct_ov000_02172720* self) {
    if (self->taskId >= 0) {
        BackgroundLoader* loader = BackgroundLoader::GetInstance();
        loader->RemoveTask(self->taskId);
        self->taskId = -1;
    }
    Window_Destroy((struct Obj0205d048*)self->field_0x188);
    Background_Destroy((struct BackgroundGraphics*)self->list8c4);
    Background_Destroy((struct BackgroundGraphics*)self->list8a4);
#if defined(jpn)
    if (self->unknown_1aa0_.GetSignedAllocator() != 0) {
        self->unknown_1aa0_.Destroy();
    }
    if (self->unknown_1ab4_.GetSignedAllocator() != 0) {
        self->unknown_1ab4_.Destroy();
    }
    if (self->unknown_1ac8_.GetSignedAllocator() != 0) {
        self->unknown_1ac8_.Destroy();
    }
    if (self->unknown_1adc_.GetSignedAllocator() != 0) {
        self->unknown_1adc_.Destroy();
    }
    if (self->unknown_1af8_.GetSignedAllocator() != 0) {
        self->unknown_1af8_.Destroy();
    }
    if (self->unknown_1a78_.GetSignedAllocator() != 0) {
        self->unknown_1a78_.Destroy();
    }
    if (self->unknown_1a8c_.GetSignedAllocator() != 0) {
        self->unknown_1a8c_.Destroy();
    }
#else
    SafeAllocator* allocs[7] = {
        &self->unknown_1aa0_,
        &self->unknown_1ab4_,
        &self->unknown_1ac8_,
        &self->unknown_1adc_,
        &self->unknown_1af8_,
        &self->unknown_1a78_,
        &self->unknown_1a8c_,
    };
    for (int i = 0; i < 7; i++) {
        SafeAllocator* alloc = allocs[i];
        if (alloc->GetSignedAllocator() != 0) {
            alloc->Destroy();
        }
    }
#endif
    for (int i = 0; i < 4; i++) {
        func_ov000_02170054(&self->slots[i]);
    }
    func_ov000_02172850(self);
    self->flags &= 0x40;
    data_ov000_02184288.field8 = 0;
}
