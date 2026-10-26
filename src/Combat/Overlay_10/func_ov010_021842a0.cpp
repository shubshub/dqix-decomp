#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Struct_020727d8 {
    void* unk_0;
    void* unk_4;
};

extern "C" void func_020727d8(Struct_020727d8* list);

struct Struct_ov010_021842a0 {
    unsigned char unk_0;
    unsigned char unk_1;
    unsigned short unk_2;
    int unk_4;
    char unknown_8_[0xc - 0x8];
    Struct_020727d8 list_;
    SafeAllocator allocator_;
};

// USA: func_ov010_021842a0
extern "C" ARM void func_ov010_021842a0(Struct_ov010_021842a0* self) {
    self->unk_0 = 0;
    self->unk_2 = 0;
    self->unk_4 = -1;
    func_020727d8(&self->list_);
    self->allocator_.ResetAllocatorPointer();
    self->unk_1 = 0;
}
