#include <globaldefs.h>

struct Obj0204b010 { char b[0x20]; };
void Background_ClearMap(Obj0204b010*, void*);

struct Cont0205d1e0 {
    char pad0[0x98];
    Obj0204b010* list98;
    char pad9c[0x16];
    unsigned char countB2;
};

// Main, originally ClearBuffers0204b010OverList0x98 (USA 0x0205d1e0, EUR 0x0205d1f0, JPN 0x0205e510)
ARM void Window_ClearLayers(Cont0205d1e0* obj) {
    unsigned char i;
    if (obj->list98 == NULL) return;
    for (i = 0; i < obj->countB2; i++) {
        Background_ClearMap(&obj->list98[i], NULL);
    }
}
