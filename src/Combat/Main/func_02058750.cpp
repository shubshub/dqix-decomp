#include <globaldefs.h>
#include <NitroSDK/Memory/SignedAllocator.h>

struct Struct_020546c8;
struct Struct_02058750_5 { char pad[0xb0]; SignedAllocatorList entries[2]; };
struct Struct_02058750 { unsigned int time; unsigned int value; };
struct Struct_02058750_2 { Struct_02058750* entry; };
struct Struct_02058750_3 { char pad[8]; unsigned char count[2]; };
struct Struct_02058750_4 {
    char pad0[4];
    unsigned int time;
    char pad1[0x20];
    Struct_02058750_5* unknown_28_;
    char pad2[4];
    float scale;
    float unknown_34_;
    float unknown_38_;
    float unknown_3c_;
    float unknown_40_;
    char pad3[0x20];
    unsigned short index[2];
};
extern "C" void* func_02055120(Struct_020546c8*);

// USA: func_02058750
extern "C" ARM void func_02058750(Struct_02058750_4* self) {
    Struct_02058750_3* counts = (Struct_02058750_3*)func_02055120((Struct_020546c8*)self->unknown_28_);
    if (counts->count[0] > 1 && counts->count[0] > self->index[0]) {
        Struct_02058750_2* previous = (Struct_02058750_2*)self->unknown_28_->entries[0].GetNthElement(self->index[0]);
        if (previous && previous->entry->time < self->time) {
            self->index[0]++;
            if (self->index[0] >= counts->count[0]) {
                self->unknown_34_ = 0;
                self->unknown_38_ = 0;
                self->unknown_3c_ = 0;
            } else {
                Struct_02058750_2* next = (Struct_02058750_2*)self->unknown_28_->entries[0].GetNthElement(self->index[0]);
                if (next) {
                    unsigned int var3;
                    unsigned int var4;
                    unsigned int var5;
                    unsigned int var6;
                    unsigned int var7;
                    unsigned int var8;
                    Struct_02058750* var9;
                    Struct_02058750* var10;
                    var9 = previous->entry;
                    var10 = next->entry;
                    var3 = var9->value & 0x1f;
                    var4 = (var9->value & 0x3e0) >> 5;
                    var5 = (var9->value & 0x7c00) >> 10;
                    var6 = var10->value & 0x1f;
                    var7 = (var10->value & 0x3e0) >> 5;
                    var8 = (var10->value & 0x7c00) >> 10;
                    self->unknown_34_ = (float)(var6 - var3) / (float)(int)(var10->time - var9->time);
                    self->unknown_38_ = (float)(var7 - var4) / (float)(int)(next->entry->time - previous->entry->time);
                    self->unknown_3c_ = (float)(var8 - var5) / (float)(int)(next->entry->time - previous->entry->time);
                }
            }
        }
    }
    if (counts->count[1] > 1 && counts->count[1] > self->index[1]) {
        Struct_02058750_2* previous = (Struct_02058750_2*)self->unknown_28_->entries[1].GetNthElement(self->index[1]);
        if (previous && (float)previous->entry->time * self->scale < (float)self->time) {
            self->index[1]++;
            if (self->index[1] >= counts->count[1]) {
                self->unknown_40_ = 0;
            } else {
                Struct_02058750_2* next = (Struct_02058750_2*)self->unknown_28_->entries[1].GetNthElement(self->index[1]);
                if (next) {
                    Struct_02058750* var13 = previous->entry;
                    float var14 = (float)var13->time * self->scale;
                    Struct_02058750* var15 = next->entry;
                    float var16 = (float)var15->time * self->scale;
                    float var17 = (float)(int)(var15->value - var13->value);
                    self->unknown_40_ = var17 / (var16 - var14);
                }
            }
        }
    }
}
