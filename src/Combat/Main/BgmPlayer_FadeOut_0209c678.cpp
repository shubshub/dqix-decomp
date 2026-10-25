#include <globaldefs.h>

void SetContextAndDispatch0203ac10(void*, void*, int);

struct Actor0209c678 {
    unsigned char pad0[0xb0];
    int state;               // 0xb0
    unsigned char pad1[0x8]; // 0xb4
    void* fieldBC;           // 0xbc
    void* fieldC0;           // 0xc0
    unsigned char pad2[0x4]; // 0xc4
    unsigned char f0 : 1;    // 0xc8 bit0
    unsigned char f1 : 1;    // bit1
    unsigned char f2 : 1;    // bit2
};

// Main, originally DispatchContextByState0209c678 (USA 0x0209c678, EUR 0x0209c688, JPN 0x0209e3f0)
ARM void BgmPlayer_FadeOut(struct Actor0209c678* actor, int arg) {
    if (actor->f2) return;
    if (actor->state == 1) {
        SetContextAndDispatch0203ac10(actor, &actor->fieldBC, arg);
    } else if (actor->state == 2) {
        SetContextAndDispatch0203ac10(actor, &actor->fieldC0, arg);
    }
}
