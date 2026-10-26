#include <globaldefs.h>

struct Struct_0205c53c;
extern "C" void func_0205c53c(struct Struct_0205c53c* s);

struct InitTarget0205cfd4 {
    char pad0[0x98];
    int unknown_98_;
    int f9c;
    unsigned short unknown_a0_;
    unsigned short unknown_a2_;
    unsigned short unknown_a4_;
    unsigned short unknown_a6_;
    unsigned short unknown_a8_;
    unsigned short unknown_aa_;
    unsigned short unknown_ac_;
    unsigned short unknown_ae_;
    unsigned char unknown_b0_;
    unsigned char unknown_b1_;
    unsigned char unknown_b2_;
    unsigned char unknown_b3_;
    unsigned char unknown_b4_;
    unsigned char unknown_b5_;
    unsigned char unknown_b6_;
    unsigned char unknown_b7_;
    unsigned char fb8;
};

// Main, originally InitStruct0205cfd4 (USA 0x0205cfd4, EUR 0x0205cfe4, JPN 0x0205e304)
extern "C" ARM void Window_Init(struct InitTarget0205cfd4* s) {
    func_0205c53c((struct Struct_0205c53c*)s);
    s->unknown_98_ = 0;
    s->f9c = 0;
    s->unknown_a0_ = 1;
    s->unknown_a2_ = 1;
    s->unknown_a4_ = 0;
    s->unknown_a6_ = 0;
    s->unknown_a8_ = 4;
    s->unknown_aa_ = 4;
    s->unknown_ac_ = 0xa;
    s->unknown_ae_ = 0xb;
    s->unknown_b0_ = 0;
    s->unknown_b1_ = 0;
    s->unknown_b2_ = 0;
    s->unknown_b3_ = 0;
    s->unknown_b4_ = 0;
    s->unknown_b5_ = 0;
    s->unknown_b6_ = 0;
    s->unknown_b7_ = 0xa;
    s->fb8 = 0xff;
}
