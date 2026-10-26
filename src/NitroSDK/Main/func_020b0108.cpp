#include <globaldefs.h>

struct Struct_020b0074;
extern "C" unsigned char* func_020b0074(Struct_020b0074* h);
struct Struct_0205a658_2;
extern "C" unsigned char* func_020b00e0(Struct_0205a658_2* h, unsigned int i);
extern "C" void func_020b0094(char* base);

struct Struct_020b0108 {
    char pad[4];
    int unknown_4_;
};

struct Struct_020b0108_2 {
    unsigned short count;
    unsigned short flags;
    unsigned char* base;
    char pad1[0xc - 0x8];
    Struct_020b0108* sub;
    char pad2[0x14 - 0x10];
    char* unknown_14_;
};

// USA: func_020b0108
extern "C" ARM void func_020b0108(Struct_020b0108_2* self) {
    self->base = self->base + (unsigned int)self;
    unsigned char* var0 = func_020b0074((Struct_020b0074*)self);
    unsigned short i = 0;
    if (i < self->count) {
        do {
            Struct_020b0108* e = (Struct_020b0108*)func_020b00e0((Struct_0205a658_2*)self, i);
            e->unknown_4_ = e->unknown_4_ + (int)var0;
            i = i + 1;
        } while (i < self->count);
    }
    if (self->sub != 0) {
        Struct_020b0108* sub = (Struct_020b0108*)((char*)self->sub + (unsigned int)self);
        self->sub = sub;
        sub->unknown_4_ = sub->unknown_4_ + (int)sub;
        self->sub = sub;
    }
    if (self->unknown_14_ != 0) {
        self->unknown_14_ = self->unknown_14_ + (unsigned int)self;
        func_020b0094(self->unknown_14_);
    }
}
