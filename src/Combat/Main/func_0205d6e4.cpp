#include <globaldefs.h>

extern "C" void func_0204c804(void* obj);

struct Struct_0205d6e4_2 {
    char pad0[0x98];
    int unknown_98_;
    int f9c;
    char unknown_a0_[0xb0 - 0xa0];
    unsigned char unknown_b0_;
    char unknown_b1_[0xb4 - 0xb1];
    unsigned char unknown_b4_;
};

struct Struct_0205d6e4 {
    char pad0[0xc2];
    unsigned short unknown_c2_;
    unsigned char fc4;
};

// USA: func_0205d6e4
extern "C" ARM void func_0205d6e4(Struct_0205d6e4_2* self, unsigned int count) {
    unsigned char i;

    if (self->unknown_98_ == 0) return;
    if (self->f9c == 0) return;
    if (self->unknown_b4_ == 0) return;

    for (i = 0; i < count; i++) {
        int idx1 = self->unknown_b4_ - 1;
        void* arr1 = (void*)self->f9c;
        Struct_0205d6e4* e1 = (Struct_0205d6e4*)((char*)arr1 + idx1 * 0xe0);
        e1->unknown_c2_ = 0;
        e1->fc4 = 0;
        func_0204c804(e1);

        int var4 = self->unknown_b4_ - 1;
        self->unknown_b4_ = var4;
        int var5 = var4 & 0xff;
        if (var5 == 0) return;

        void* arr2 = (void*)self->f9c;
        int idx2 = var5 - 1;
        Struct_0205d6e4* e2 = (Struct_0205d6e4*)((char*)arr2 + idx2 * 0xe0);
        e2->unknown_c2_ = 0;

        int var9 = self->unknown_b4_ - 1;
        void* var10 = (void*)self->f9c;
        Struct_0205d6e4* e3 = (Struct_0205d6e4*)((char*)var10 + var9 * 0xe0);
        self->unknown_b0_ = e3->fc4;
    }
}
