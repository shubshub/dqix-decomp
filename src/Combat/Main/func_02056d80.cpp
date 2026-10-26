#include <globaldefs.h>
#include <NitroSDK/Memory/SignedAllocator.h>

struct Struct_02056d80_6 {
    int x;
    union {
        float y;
        unsigned int duration;
    };
    float z;
    float w;
};
struct Struct_020557a4 {
    Struct_02056d80_6* unknown_0_;
};
struct Struct_020546c8 {
    unsigned char padding[8];
    SignedAllocatorList unknown_8_[3];
    SignedAllocatorList rotation[3];
    SignedAllocatorList scale[3];
    SignedAllocatorList duration;
    SignedAllocatorList extra[3];
    SignedAllocatorList vector;
    SignedAllocatorList unknown_b0_[4];
    unsigned char unknown_e0_[12];
    SignedAllocatorList unknown_ec_[4];
    SignedAllocatorList unknown_11c_;
};
struct Struct_02056d80_5 {
    unsigned char padding[16];
    unsigned char unknown_10_[4];
};
struct Struct_02056d80_7 {
    unsigned char padding[0x24];
    unsigned char unknown_24_[3];
    unsigned char rotation[3];
    unsigned char scale[3];
};
struct Struct_02056d80_8 {
    unsigned char padding[4];
    unsigned char count;
};
struct Struct_02056d80 {
    unsigned char padding[16];
    unsigned char unknown_10_[3];
    unsigned char vector;
};
struct Struct_02056d80_2 {
    unsigned char unknown_0_;
    unsigned char delay;
    unsigned char repeat;
    unsigned char flags;
};
struct Struct_02056d80_3 {
    unsigned char padding[12];
    unsigned short unknown_c_;
};
struct Struct_02056d80_4 {
    int field_0x0;
    int frame;
    int endFrame;
    unsigned char repeat;
    unsigned char unknown_d_[0x1b];
    void* active;
    int unknown_2c_;
    Struct_020546c8* resource;
    unsigned char unknown_34_[4];
    unsigned char flags;
    unsigned char unknown_39_[0x13];
    float unknown_4c_[4];
    unsigned short unknown_5c_[4];
    float unknown_64_[3];
    float unknown_70_[3];
    float unknown_7c_[3];
    unsigned short unknown_88_[3];
    unsigned short unknown_8e_[3];
    unsigned short unknown_94_[3];
    unsigned char unknown_9a_[2];
    float unknown_9c_;
    unsigned short unknown_a0_;
    unsigned char unknown_a2_[2];
    float unknown_a4_[3];
    float unknown_b0_[3];
    unsigned short unknown_bc_[3];
    unsigned short unknown_c2_;
    unsigned char unknown_c4_[0x54];
    float unknown_118_[4];
    float unknown_128_[3];
    float rotation[3];
    float scale[3];
    float duration;
    int unknown_150_;
    int delay;
    float extra[3];
    float vector[3];
};

extern "C" int func_02055168(Struct_020546c8*);
extern "C" void* func_020550a8(Struct_020546c8*);
extern "C" void* func_020550c0(Struct_020546c8*);
extern "C" void* func_020550d8(Struct_020546c8*);
extern "C" void* func_020550f0(Struct_020546c8*);
extern "C" void* func_02055090(Struct_020546c8*);
extern "C" float func_020578e8(Struct_020557a4*, Struct_020557a4*);

// USA: func_02056d80
extern "C" ARM void func_02056d80(Struct_02056d80_4* self) {
    if (!self->resource || !self->active) return;
    Struct_02056d80_5* counts = (Struct_02056d80_5*)func_02055168(self->resource);
    Struct_020557a4* previous;
    Struct_020557a4* next;
    previous = (Struct_020557a4*)self->resource->unknown_ec_[0].ElementAfter(0);
    self->unknown_118_[0] = previous->unknown_0_->y;
    if (counts->unknown_10_[0] > 1) {
        self->unknown_5c_[0] = 1;
        next = (Struct_020557a4*)self->resource->unknown_b0_[0].GetNthElement(1);
        if (next) self->unknown_4c_[0] = func_020578e8(previous, next);
    }
    previous = (Struct_020557a4*)self->resource->unknown_ec_[1].ElementAfter(0);
    self->unknown_118_[1] = previous->unknown_0_->y;
    if (counts->unknown_10_[1] > 1) {
        self->unknown_5c_[1] = 1;
        next = (Struct_020557a4*)self->resource->unknown_b0_[1].GetNthElement(1);
        if (next) self->unknown_4c_[1] = func_020578e8(previous, next);
    }
    previous = (Struct_020557a4*)self->resource->unknown_ec_[2].ElementAfter(0);
    self->unknown_118_[2] = previous->unknown_0_->y;
    if (counts->unknown_10_[2] > 1) {
        self->unknown_5c_[2] = 1;
        next = (Struct_020557a4*)self->resource->unknown_b0_[2].GetNthElement(1);
        if (next) self->unknown_4c_[2] = func_020578e8(previous, next);
    }
    previous = (Struct_020557a4*)self->resource->unknown_ec_[3].ElementAfter(0);
    self->unknown_118_[3] = previous->unknown_0_->y;
    if (counts->unknown_10_[3] > 1) {
        self->unknown_5c_[3] = 1;
        next = (Struct_020557a4*)self->resource->unknown_b0_[3].GetNthElement(1);
        if (next) self->unknown_4c_[3] = func_020578e8(previous, next);
    }
    Struct_02056d80_7* var3 = (Struct_02056d80_7*)func_020550a8(self->resource);
    for (int i = 0; i < 3; i++) {
        previous = (Struct_020557a4*)self->resource->unknown_8_[i].ElementAfter(0);
        self->unknown_128_[i] = previous->unknown_0_->y;
        if (var3->unknown_24_[i] > 1) {
            self->unknown_88_[i] = 1;
            next = (Struct_020557a4*)self->resource->unknown_8_[i].GetNthElement(self->unknown_88_[i]);
            if (next) self->unknown_64_[i] = func_020578e8(previous, next);
        }
    }
    for (int i = 0; i < 3; i++) {
        previous = (Struct_020557a4*)self->resource->rotation[i].ElementAfter(0);
        self->rotation[i] = previous->unknown_0_->y;
        if (var3->rotation[i] > 1) {
            self->unknown_8e_[i] = 1;
            next = (Struct_020557a4*)self->resource->rotation[i].GetNthElement(self->unknown_8e_[i]);
            if (next) self->unknown_70_[i] = func_020578e8(previous, next);
        }
    }
    for (int i = 0; i < 3; i++) {
        previous = (Struct_020557a4*)self->resource->scale[i].ElementAfter(0);
        self->scale[i] = previous->unknown_0_->y;
        if (var3->scale[i] > 1) {
            self->unknown_94_[i] = 1;
            next = (Struct_020557a4*)self->resource->scale[i].GetNthElement(self->unknown_94_[i]);
            if (next) self->unknown_7c_[i] = func_020578e8(previous, next);
        }
    }
    Struct_02056d80_8* duration = (Struct_02056d80_8*)func_020550c0(self->resource);
    previous = (Struct_020557a4*)self->resource->duration.ElementAfter(0);
    self->duration = (float)previous->unknown_0_->duration;
    if (duration->count > 1) {
        self->unknown_a0_ = 1;
        next = (Struct_020557a4*)self->resource->duration.GetNthElement(1);
        if (next) self->unknown_9c_ = func_020578e8(previous, next);
    }
    Struct_02056d80* extra = (Struct_02056d80*)func_020550d8(self->resource);
    for (int i = 0; i < 3; i++) {
        previous = (Struct_020557a4*)self->resource->extra[i].ElementAfter(0);
        self->extra[i] = previous->unknown_0_->y;
        if (extra->unknown_10_[i] > 1) {
            self->unknown_bc_[i] = 1;
            next = (Struct_020557a4*)self->resource->extra[i].GetNthElement(self->unknown_bc_[i]);
            if (next) self->unknown_a4_[i] = func_020578e8(previous, next);
        }
    }
    previous = (Struct_020557a4*)self->resource->vector.ElementAfter(0);
    self->vector[0] = previous->unknown_0_->y;
    self->vector[1] = previous->unknown_0_->z;
    self->vector[2] = previous->unknown_0_->w;
    if (extra->vector > 1) {
        self->unknown_c2_ = 1;
        next = (Struct_020557a4*)self->resource->vector.GetNthElement(1);
        if (next) {
            self->unknown_b0_[0] = (next->unknown_0_->y - previous->unknown_0_->y) / (float)(next->unknown_0_->x - previous->unknown_0_->x);
            self->unknown_b0_[1] = (next->unknown_0_->z - previous->unknown_0_->z) / (float)(next->unknown_0_->x - previous->unknown_0_->x);
            self->unknown_b0_[2] = (next->unknown_0_->w - previous->unknown_0_->w) / (float)(next->unknown_0_->x - previous->unknown_0_->x);
        }
    }
    Struct_02056d80_2* settings = (Struct_02056d80_2*)func_020550f0(self->resource);
    self->frame = 0;
    self->endFrame = settings->unknown_0_ + settings->delay;
    self->repeat = settings->repeat;
    self->flags = settings->flags;
    self->delay = settings->delay;
    if (settings->repeat) self->repeat = 1;
    if (((Struct_02056d80_3*)func_02055090(self->resource))->unknown_c_ == 0) return;
    previous = (Struct_020557a4*)self->resource->unknown_11c_.ElementAfter(0);
    self->unknown_150_ = previous->unknown_0_->x;
}
