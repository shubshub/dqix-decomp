#include <globaldefs.h>

void SoundPlayer_Init(void* obj);
void NNS_SndHandleInit(int* field);
extern "C" void func_0209c2e0(void* obj, int a, int b);
void SetModeClamped0209ca70(void* obj, int val);

struct Actor0209c174 {
    char pad0[0xb0];
    int state;               // 0xb0
    int field_b4;             // 0xb4
    short field_b8;             // 0xb8
    short field_ba;               // 0xba
    void* fieldBC;                 // 0xbc
    void* fieldC0;                   // 0xc0
    void* fieldC4;                     // 0xc4
    unsigned char field_c8;              // 0xc8
    unsigned char field_c9;                // 0xc9
    short field_ca;                          // 0xca
    unsigned char field_cc;                    // 0xcc
    unsigned char field_cd;                      // 0xcd
    short field_ce;                                // 0xce
};

// Main, originally ResetActor0209c174 (USA 0x0209c174, EUR 0x0209c184, JPN 0x0209deec)
ARM void BgmPlayer_Init(struct Actor0209c174* self) {
    SoundPlayer_Init(self);
    self->state = 0;
    self->field_b4 = 0;
    self->field_b8 = -1;
    NNS_SndHandleInit((int*)&self->fieldBC);
    self->field_ba = -1;
    NNS_SndHandleInit((int*)&self->fieldC0);
    NNS_SndHandleInit((int*)&self->fieldC4);
    self->field_c8 &= ~1;
    func_0209c2e0(self, 0x7f, 0);
    SetModeClamped0209ca70(self, 3);
    self->field_ce = -1;
    self->field_c9 = 0;
    self->field_ca = 0;
    self->field_c8 &= ~4;
    self->field_c8 &= ~8;
}
