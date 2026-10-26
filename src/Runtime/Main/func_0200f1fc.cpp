#include <globaldefs.h>

extern "C" void* func_0200d9e4(void* ptr, int* arg1);

struct Struct_0200f1fc_2 {
    char pad[4];
    unsigned char* data;
};

struct Struct_0200f1fc {
    char pad0[0x14];
    int f14;
    int f18;
    char pad1[0x38 - 0x1c];
    int unknown_38_;
    char pad2[0x48 - 0x3c];
    int unknown_48_;
    char pad3[0x60 - 0x4c];
    int f60;
    int f64;
    unsigned short f68;
    unsigned char unknown_6a_;
    unsigned char unknown_6b_;
    unsigned char f6c;
};

// USA: func_0200f1fc
extern "C" ARM void func_0200f1fc(Struct_0200f1fc* self, Struct_0200f1fc_2* ctx) {
    unsigned char* data = ctx->data;
    unsigned char byte0 = data[0];
    int var2 = byte0 & 0x40;
    self->unknown_6b_ = var2 ? 1 : 0;
    self->unknown_6a_ = (byte0 & 0x20) ? 1 : 0;
    int var3 = byte0 & 0x80;
    self->f6c = var3 ? 1 : 0;
    unsigned char var4 = data[1];
    unsigned char* var5 = data + 2;
    self->f68 = var4 << 4;
    self->f68 = self->f68 | 0x4000;
    var5 = (unsigned char*)func_0200d9e4(var5, &self->f60);
    if (var2 != 0) {
        func_0200d9e4(var5, &self->f64);
    }
    if (var2 != 0) {
        if (var3 != 0) {
            self->f18 = self->unknown_38_;
        } else {
            self->f18 = self->unknown_48_;
        }
    } else {
        self->f18 = self->f14;
    }
}
