#include <globaldefs.h>
#include <std_library_functions.h>
#include "Memory/SafeAllocator.h"

struct Struct_ov023_021dad8c {
    unsigned int kind_ : 7; unsigned int unknown_0_7_ : 4; unsigned int unknown_1_3_ : 18;
    unsigned int unknown_3_5_ : 1; unsigned int mode_ : 2;
    unsigned int unknown_4_0_ : 12; unsigned int unknown_5_4_ : 15;
    unsigned int unknown_7_3_ : 1; unsigned int unknown_7_4_ : 1; unsigned int unknown_7_5_ : 1;
    unsigned int unknown_7_6_ : 2;
};
struct Slot {
    Struct_ov023_021dad8c* unknown_0_; void* unknown_4_;
    unsigned int type_ : 4; unsigned int unknown_8_4_ : 28;
    char unknown_c_[12]; short key_; char unknown_1a_[6];
};
struct Struct_ov005_02154da8 {
    unsigned short count_; unsigned short unknown_2_0_ : 15; unsigned short unknown_3_7_ : 1;
    int unknown_4_; unsigned int unknown_8_0_ : 31; unsigned int unknown_b_7_ : 1;
};
struct Struct_020de5b0 { Struct_ov005_02154da8 header_; Slot* slots_; void* unknown_10_; };
struct Struct_ov023_021dad8c_3 {
    short key_; unsigned short type_ : 4; unsigned short unknown_2_4_ : 12;
    unsigned int kind_ : 7; unsigned int unknown_4_7_ : 4; unsigned int unknown_5_3_ : 12;
    unsigned int unknown_6_7_ : 1; unsigned int mode_ : 2;
    unsigned int unknown_7_2_ : 1; unsigned int unknown_7_3_ : 1; unsigned int unknown_7_4_ : 1;
    unsigned int unknown_7_5_ : 3;
};
struct Struct_ov023_021dad8c_2 { Struct_ov023_021dad8c_3* entries_; unsigned short count_; unsigned short unknown_6_; };
extern "C" int func_020de574(Struct_020de5b0*, Slot*);
extern "C" int func_020de5b0(Struct_020de5b0*);

// USA: func_ov023_021dad8c
extern "C" ARM void func_ov023_021dad8c(Struct_ov023_021dad8c_2* self, SafeAllocator* allocator, Struct_ov005_02154da8* source, void* context) {
    if (!allocator || !source || !context) return;
    self->count_ = 0;
    self->unknown_6_ = 0;
    Struct_020de5b0 container;
    memset(&container, 0, sizeof(container));
    int var1 = 0;
    if (source) {
        memcpy(&container, source, sizeof(Struct_ov005_02154da8));
        container.slots_ = (Slot*)(source + 1);
        unsigned short extra = container.header_.unknown_2_0_;
        unsigned short count = container.header_.count_;
        int extension = container.header_.unknown_3_7_ ? 88 : 0;
        int size = extension + extra * 32 + count * 32;
        container.unknown_10_ = (char*)source + (size + 12);
        if (container.header_.unknown_b_7_) var1 = 1;
        else {
            Slot* slot = container.slots_;
            int i;
            unsigned short count;
            if (slot && (count = container.header_.count_) && (unsigned int)func_020de574) {
                for (i = 0; i < count; ++i, ++slot) func_020de574(&container, slot);
            }
            container.header_.unknown_b_7_ = 1;
            source->unknown_b_7_ = 1;
        }
    }
    if (!var1) func_020de5b0(&container);
    int count = container.header_.count_;
    {
        Slot* slot = container.slots_;
        for (int i = 0; i < count; ++i, ++slot) {
            int var12 = slot->type_ <= 7 ? 1 : 0;
            if (var12) ++self->count_;
        }
    }
    Struct_ov023_021dad8c_3* output = (Struct_ov023_021dad8c_3*)allocator->Allocate(self->count_ * sizeof(Struct_ov023_021dad8c_3));
    self->entries_ = output;
    if (!output) return;
    Slot* slot = container.slots_;
    for (int i = 0; i < count; ++i, ++slot) {
        int var16 = slot->type_ <= 7 ? 1 : 0;
        Struct_ov023_021dad8c* data;
        if (var16 && (data = slot->unknown_0_) != 0) {
            ++self->unknown_6_;
            output->key_ = slot->key_;
            output->type_ = (unsigned short)slot->type_;
            output->kind_ = data->kind_;
            output->unknown_4_7_ = data->unknown_0_7_;
            output->unknown_5_3_ = data->unknown_4_0_;
            output->unknown_6_7_ = data->unknown_3_5_;
            output->mode_ = data->mode_;
            output->unknown_7_2_ = data->unknown_7_3_;
            output->unknown_7_3_ = data->unknown_7_4_;
            output->unknown_7_4_ = data->unknown_7_5_;
            ++output;
        }
    }
}
