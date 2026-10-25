#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"

struct Obj0205d048;
struct BackgroundGraphics;
extern "C" void Window_Destroy(struct Obj0205d048* obj);
void Background_Destroy(struct BackgroundGraphics* obj);
void ResetSlot02170054(void* obj);

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
    char unknown_0_[SLOT_BYTES];
};

struct Struct_ov000_02172720 {
    char unknown_0_[0x188];
    char unknown_188_[0x8a4 - 0x188];
    char unknown_8a4_[0x20];
    char unknown_8c4_[0x20];
    char unknown_8e4_[0x90c - 0x8e4];
    int unknown_90c_;
    char unknown_910_[0x958 - 0x910];
    Struct_02000c9c_35 unknown_958_[4];
    SafeAllocator unknown_1a78_;
    SafeAllocator unknown_1a8c_;
    SafeAllocator unknown_1aa0_;
    SafeAllocator unknown_1ab4_;
    SafeAllocator unknown_1ac8_;
    SafeAllocator unknown_1adc_;
    char unknown_1af0_[0x1af8 - 0x1af0];
    SafeAllocator unknown_1af8_;
    char unknown_1b0c_[0x1d72 + FLAG_SHIFT - (0x1b0c + ALLOC_SHIFT)];
    unsigned short unknown_1d72_;
};

struct Struct_ov000_02184288 {
    int unknown_0_;
    int unknown_4_;
    int unknown_8_;
};
extern struct Struct_ov000_02184288 data_ov000_02184288;

extern "C" void func_ov000_02172850(Struct_ov000_02172720* arg0);

// USA: func_ov000_02172720
extern "C" ARM void func_ov000_02172720(Struct_ov000_02172720* arg0) {
    if (arg0->unknown_90c_ >= 0) {
        BackgroundLoader* var0 = BackgroundLoader::GetInstance();
        var0->RemoveTask(arg0->unknown_90c_);
        arg0->unknown_90c_ = -1;
    }
    Window_Destroy((struct Obj0205d048*)self->field_0x188);
    Background_Destroy((struct BackgroundGraphics*)self->list8c4);
    Background_Destroy((struct BackgroundGraphics*)self->list8a4);
#if defined(jpn)
    if (arg0->unknown_1aa0_.GetSignedAllocator() != 0) {
        arg0->unknown_1aa0_.Destroy();
    }
    if (arg0->unknown_1ab4_.GetSignedAllocator() != 0) {
        arg0->unknown_1ab4_.Destroy();
    }
    if (arg0->unknown_1ac8_.GetSignedAllocator() != 0) {
        arg0->unknown_1ac8_.Destroy();
    }
    if (arg0->unknown_1adc_.GetSignedAllocator() != 0) {
        arg0->unknown_1adc_.Destroy();
    }
    if (arg0->unknown_1af8_.GetSignedAllocator() != 0) {
        arg0->unknown_1af8_.Destroy();
    }
    if (arg0->unknown_1a78_.GetSignedAllocator() != 0) {
        arg0->unknown_1a78_.Destroy();
    }
    if (arg0->unknown_1a8c_.GetSignedAllocator() != 0) {
        arg0->unknown_1a8c_.Destroy();
    }
#else
    SafeAllocator* var1[7] = {
        &arg0->unknown_1aa0_,
        &arg0->unknown_1ab4_,
        &arg0->unknown_1ac8_,
        &arg0->unknown_1adc_,
        &arg0->unknown_1af8_,
        &arg0->unknown_1a78_,
        &arg0->unknown_1a8c_,
    };
    for (int var2 = 0; var2 < 7; var2++) {
        SafeAllocator* var3 = var1[var2];
        if (var3->GetSignedAllocator() != 0) {
            var3->Destroy();
        }
    }
#endif
    for (int var4 = 0; var4 < 4; var4++) {
        func_ov000_02170054(&arg0->unknown_958_[var4]);
    }
    func_ov000_02172850(arg0);
    arg0->unknown_1d72_ &= 0x40;
    data_ov000_02184288.unknown_8_ = 0;
}
