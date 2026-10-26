#include <globaldefs.h>
#include <NitroSDK/Memory/SignedAllocator.h>
#include <std_library_functions.h>
struct Struct_020546c8;
struct Struct_02058b3c { char pad[0xe0]; SignedAllocatorList entries; };
struct Struct_02058b3c_2 { unsigned int time; float value, unknown_8_; };
struct Struct_02058b3c_3 { Struct_02058b3c_2* entry; };
struct Struct_02058b3c_4 { char pad[8]; unsigned char count; };
struct Struct_02058b3c_5 { char pad[4]; unsigned int time; char pad2[0x20]; Struct_02058b3c* unknown_28_; char pad3[0x20]; float unknown_4c_; char pad4[0x10]; float value; char pad5[6]; unsigned short index; };
extern "C" void* func_02055150(Struct_020546c8*);
// USA: func_02058b3c
extern "C" ARM void func_02058b3c(Struct_02058b3c_5* self) {
    Struct_02058b3c_4* counts = (Struct_02058b3c_4*)func_02055150((Struct_020546c8*)self->unknown_28_);
    if (counts->count <= 1 || counts->count <= self->index) return;
    Struct_02058b3c_3* previous = (Struct_02058b3c_3*)self->unknown_28_->entries.GetNthElement(self->index);
    if (!previous || previous->entry->time >= self->time) return;
    self->index++;
    if (self->index >= counts->count) { self->unknown_4c_ = 0; return; }
    Struct_02058b3c_3* next = (Struct_02058b3c_3*)self->unknown_28_->entries.GetNthElement(self->index);
    if (!next) return;
    Struct_02058b3c_2* entry = next->entry;
    int var4 = rand();
    int range = (int)entry->unknown_8_;
    float delta = (float)((var4 & (range << 1)) - (int)entry->unknown_8_) / 100.0f;
    self->value = entry->value + entry->value * delta;
    self->unknown_4c_ = self->value / (float)(int)(next->entry->time - previous->entry->time);
    if (self->unknown_4c_ < 0.0f) self->unknown_4c_ += 360.0f;
    if (self->unknown_4c_ > 360.0f) self->unknown_4c_ -= 360.0f;
}
