#include <globaldefs.h>

struct Struct_0205c53c;
extern void InitChannelPair0205c53c(struct Struct_0205c53c* s);

struct InitTarget0205cfd4 {
    char pad0[0x98];
    int f98;
    int f9c;
    unsigned short fa0;
    unsigned short fa2;
    unsigned short fa4;
    unsigned short fa6;
    unsigned short fa8;
    unsigned short faa;
    unsigned short fac;
    unsigned short fae;
    unsigned char fb0;
    unsigned char fb1;
    unsigned char fb2;
    unsigned char fb3;
    unsigned char fb4;
    unsigned char fb5;
    unsigned char fb6;
    unsigned char fb7;
    unsigned char fb8;
};

// Main, originally InitStruct0205cfd4 (USA 0x0205cfd4, EUR 0x0205cfe4, JPN 0x0205e304)
ARM void Window_Init(struct InitTarget0205cfd4* s) {
    InitChannelPair0205c53c((struct Struct_0205c53c*)s);
    s->f98 = 0;
    s->f9c = 0;
    s->fa0 = 1;
    s->fa2 = 1;
    s->fa4 = 0;
    s->fa6 = 0;
    s->fa8 = 4;
    s->faa = 4;
    s->fac = 0xa;
    s->fae = 0xb;
    s->fb0 = 0;
    s->fb1 = 0;
    s->fb2 = 0;
    s->fb3 = 0;
    s->fb4 = 0;
    s->fb5 = 0;
    s->fb6 = 0;
    s->fb7 = 0xa;
    s->fb8 = 0xff;
}
