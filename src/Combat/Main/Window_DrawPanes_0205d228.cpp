#include <globaldefs.h>
void SomeFunc0204c8f0(struct Struct0204c8f0*);


struct Elem0205d228 { char b[0xe0]; };

struct Cont0205d228 {
    char pad0[0x98];
    void* list98;
    Elem0205d228* list9c;
    char padA0[0x13];
    unsigned char countB3;
};

// Main, originally CallFunc0204c8f0OverList0x9c (USA 0x0205d228, EUR 0x0205d238, JPN 0x0205e558)
ARM void Window_DrawPanes(Cont0205d228* obj) {
    unsigned char i;
    if (obj->list98 == NULL || obj->list9c == NULL) return;
    for (i = 0; i < obj->countB3; i++) {
        SomeFunc0204c8f0((struct Struct0204c8f0*)(&obj->list9c[i]));
    }
}
