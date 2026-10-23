#include <globaldefs.h>

extern "C" void Background_FlushMap(void* p, int flag);

struct Elem0205d274 { char b[0x20]; };

struct Cont0205d274 {
    char pad0[0x98];
    Elem0205d274* list98;
    char pad9c[0x16];
    unsigned char countB2;
};

// Main, originally CallFunc0204b04cOverList0x98 (USA 0x0205d274, EUR 0x0205d284, JPN 0x0205e5a4)
ARM void Window_FlushLayers(Cont0205d274* obj) {
    unsigned char i;
    if (obj->list98 == NULL) return;
    for (i = 0; i < obj->countB2; i++) {
        Background_FlushMap(&obj->list98[i], 0);
    }
}
