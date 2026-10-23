#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

#if defined(jpn)
enum { Enum_ov003_0216ae0c_4708 = 0x10f4 };
enum { Enum_ov003_0216ae0c_4800 = 0x1150 };
enum { Enum_ov003_0216ae0c_4716 = 0x10fc };
enum { Enum_ov003_0216ae0c_4816 = 0x1160 };
enum { Enum_ov003_0216ae0c_4812 = 0x115c };
#else
enum { Enum_ov003_0216ae0c_4708 = 0x1264 };
enum { Enum_ov003_0216ae0c_4800 = 0x12c0 };
enum { Enum_ov003_0216ae0c_4716 = 0x126c };
enum { Enum_ov003_0216ae0c_4816 = 0x12d0 };
enum { Enum_ov003_0216ae0c_4812 = 0x12cc };
#endif


struct InitTarget0205cfd4;
ARM void InitStruct0205cfd4(struct InitTarget0205cfd4* s);
struct List0204af64;
ARM void Background_Init(struct List0204af64* obj);
extern "C" void func_0204c684(void* obj);
struct Struct0205a198;
void Sprite_Init(struct Struct0205a198*);
struct ClearTarget0205a234;
void ClearField0And40205a234(struct ClearTarget0205a234* target);

struct Struct_ov003_0216ae0c {
    char unknown_0_[Enum_ov003_0216ae0c_4708];
    void* unknown_1264_;
    void* unknown_1268_;
    char unknown_126c_[Enum_ov003_0216ae0c_4800 - Enum_ov003_0216ae0c_4716];
    void* unknown_12c0_;
    void* unknown_12c4_;
    void* unknown_12c8_;
    char unknown_12cc_[Enum_ov003_0216ae0c_4816 - Enum_ov003_0216ae0c_4812];
    SafeAllocator* unknown_12d0_;
};

// USA: func_ov003_0216ae0c
extern "C" ARM void func_ov003_0216ae0c(void* arg0, SafeAllocator* arg1) {
    if (arg1 == 0) return;
    struct Struct_ov003_0216ae0c* var0 = (struct Struct_ov003_0216ae0c*)arg0;

    var0->unknown_12d0_ = arg1;
    var0->unknown_12c0_ = var0->unknown_12d0_->Allocate(0xbc);
    var0->unknown_12c4_ = var0->unknown_12d0_->Allocate(0x40);
    var0->unknown_12c8_ = var0->unknown_12d0_->Allocate(0xe0);
    func_0205cfd4((struct Struct_0205cfd4*)var0->unknown_12c0_);

    for (int i = 0; i < 2; i++) {
        Background_Init((struct List0204af64*)((char*)obj->p2c4 + i * 0x20));
    }
    for (int var2 = 0; var2 < 1; var2++) {
        func_0204c684((char*)var0->unknown_12c8_ + var2 * 0xe0);
    }

    var0->unknown_1264_ = var0->unknown_12d0_->Allocate(0x258);
    var0->unknown_1268_ = var0->unknown_12d0_->Allocate(8);

    for (int i = 0; i < 0xf; i++) {
        Sprite_Init((struct Struct0205a198*)((char*)obj->p264 + i * 0x28));
    }
    func_0205a234((struct Struct_02043368*)var0->unknown_1268_);
}
