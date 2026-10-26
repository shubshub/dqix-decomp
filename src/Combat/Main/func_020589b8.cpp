#include <globaldefs.h>
#include <NitroSDK/Memory/SignedAllocator.h>
#include <std_library_functions.h>

struct Struct_020546c8;
struct Struct_020589b8 { char pad[0xd4]; SignedAllocatorList entries; };
struct Struct_020589b8_2 { unsigned int time; float value0; float unknown_8_; float unknown_c_; };
struct Struct_020589b8_3 { Struct_020589b8_2* entry; };
struct Struct_020589b8_4 { char pad[9]; unsigned char count; };
struct Struct_020589b8_5 {
    char pad0[4];
    unsigned int time;
    char pad1[0x20];
    Struct_020589b8* unknown_28_;
    char pad2[0x18];
    float unknown_44_;
    float unknown_48_;
    char pad3[0xc];
    float value0;
    float unknown_5c_;
    char pad4[8];
    unsigned short index;
};
extern "C" void* func_02055138(Struct_020546c8*);

// USA: func_020589b8
extern "C" ARM void func_020589b8(Struct_020589b8_5* self) {
    Struct_020589b8_4* counts = (Struct_020589b8_4*)func_02055138((Struct_020546c8*)self->unknown_28_);
    if (counts->count <= 1 || counts->count <= self->index) return;
    Struct_020589b8_3* previous = (Struct_020589b8_3*)self->unknown_28_->entries.GetNthElement(self->index);
    if (!previous || previous->entry->time >= self->time) return;
    self->index++;
    if (self->index >= counts->count) {
        self->unknown_44_ = 0;
        self->unknown_48_ = 0;
        return;
    }
    Struct_020589b8_3* next = (Struct_020589b8_3*)self->unknown_28_->entries.GetNthElement(self->index);
    if (!next) return;
    Struct_020589b8_2* entry = next->entry;
    int var4 = rand();
    int range = (int)entry->unknown_c_;
    float delta = (float)((var4 & (range << 1)) - (int)entry->unknown_c_) / 100.0f;
    float var7 = self->value0;
    float var8 = self->unknown_5c_;
    self->value0 = entry->value0 + entry->value0 * delta;
    self->unknown_5c_ = next->entry->unknown_8_ + next->entry->unknown_8_ * delta;
    self->unknown_44_ = (self->value0 - var7) / (float)(int)(next->entry->time - previous->entry->time);
    self->unknown_48_ = (self->unknown_5c_ - var8) / (float)(int)(next->entry->time - previous->entry->time);
}
