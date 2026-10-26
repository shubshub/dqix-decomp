#include <globaldefs.h>
#include "NitroSDK/Memory.h"

struct Struct_ov031_0220528c;
struct Struct_ov031_02206410_3 {
    unsigned char unknown_0_[0xf8];
    int capacity;
    unsigned char* data;
    unsigned short position;
    unsigned char unknown_102_[0xa];
    Struct_ov031_0220528c* callback;
};
struct Struct_ov031_02206410 {
    unsigned char unknown_0_[0xa];
    unsigned short unknown_a_;
    unsigned char unknown_c_[0x5c];
    Struct_ov031_02206410_3* buffer;
    unsigned char unknown_6c_[7];
    signed char mode;
    unsigned short unknown_74_;
    unsigned short unknown_76_;
    void* unknown_78_;
};
struct Struct_ov031_02206410_2 {
    unsigned char unknown_0_[0xd];
    unsigned char flags;
    unsigned char unknown_e_[2];
    void* unknown_10_;
    int unknown_14_;
    void* unknown_18_;
    int unknown_1c_;
    unsigned short position;
    unsigned char unknown_22_[2];
    unsigned short unknown_24_;
    unsigned short tag;
    void* unknown_28_;
};
extern "C" void* func_ov031_02205134(void*, void*, int);
extern "C" int func_ov031_0220528c(Struct_ov031_0220528c*, void*);
extern "C" unsigned short func_ov031_02203078();
extern "C" void func_ov031_02206584();

// USA: func_ov031_02206410
extern "C" ARM int func_ov031_02206410(Struct_ov031_02206410* self, const unsigned char* source, int length, int offset, unsigned short tag, void* arg5, int flags) {
    Struct_ov031_02206410_3* buffer = self->buffer;
    Struct_ov031_02206410_2* record = (Struct_ov031_02206410_2*)func_ov031_02205134((void*)func_ov031_02206584, buffer->callback, flags);
    if (!record) return -33;
    if ((flags & 1) && self->mode != 1) record->flags = 3;
    else record->flags = 0;
    unsigned char* base = buffer->data;
    int capacity = buffer->capacity;
    int end = offset + length;
    if (end < capacity) {
        record->unknown_10_ = base + offset;
        record->unknown_14_ = length;
        record->unknown_18_ = 0;
        offset = end;
        record->unknown_1c_ = 0;
    } else {
        record->unknown_10_ = base + offset;
        record->unknown_14_ = capacity - offset;
        record->unknown_18_ = base;
        offset = length - record->unknown_14_;
        record->unknown_1c_ = offset;
        VectorizedInvertedMemcpy(source + record->unknown_14_, record->unknown_18_, offset);
    }
    VectorizedInvertedMemcpy(source, record->unknown_10_, record->unknown_14_);
    unsigned short var5 = buffer->position;
    record->position = offset;
    buffer->position = record->position;
    if (self->mode == 1) {
        if (self->unknown_74_ == 0) {
            self->unknown_74_ = func_ov031_02203078();
            self->unknown_a_ = self->unknown_74_;
        }
        record->unknown_24_ = self->unknown_74_;
        if (self->unknown_78_ == 0 || arg5 != 0) {
            record->unknown_28_ = arg5;
            record->tag = tag;
        } else {
            record->unknown_28_ = self->unknown_78_;
            record->tag = self->unknown_76_;
        }
    } else record->unknown_28_ = 0;
    if (func_ov031_0220528c(buffer->callback, record)) {
        length = 0;
        buffer->position = var5;
    }
    return length;
}
