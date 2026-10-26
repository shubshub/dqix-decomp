#include <globaldefs.h>

struct Actor0209c73c;
void DispatchActorState0209c73c(struct Actor0209c73c* actor);
void SoundPlayer_UnloadAll(void* obj);
int SoundPlayer_LoadSeq(void* obj, void* arg1, int* out);
struct Obj0203aba8;
int SoundPlayer_StartSeq(struct Obj0203aba8* obj, void* key, void* target);
extern "C" void func_0209c2e0(void* obj, int a, int b);

struct Flags0209c3b4 {
    unsigned char bit0 : 1;
    unsigned char bit1 : 1;
    unsigned char bit2 : 1;
    unsigned char bit3 : 1;
    unsigned char rest : 4;
};

struct Actor0209c3b4 {
    char pad0[0xb0];
    int state;               // 0xb0
    int field_b4;             // 0xb4
    short field_b8;             // 0xb8
    short field_ba;               // 0xba
    void* fieldBC;                 // 0xbc
    void* fieldC0;                   // 0xc0
    void* fieldC4;                     // 0xc4
    struct Flags0209c3b4 field_c8;       // 0xc8
    unsigned char field_c9;                // 0xc9
    short field_ca;                          // 0xca
    unsigned char field_cc;                    // 0xcc
    unsigned char field_cd;                      // 0xcd
    short field_ce;                                // 0xce
};

// USA: func_0209c3b4
ARM void SetStateAndDispatch0209c3b4(struct Actor0209c3b4* actor, int val) {
    if (actor->state == 2) return;
    if (actor->state == 1 && val == actor->field_b8) return;
    if (actor->field_c8.bit2) return;
    if (actor->field_ce > -1) {
        DispatchActorState0209c73c((struct Actor0209c73c*)actor);
    }
    actor->state = 1;
    SoundPlayer_UnloadAll(actor);
    if (val > 0) {
        SoundPlayer_LoadSeq(actor, (void*)val, &actor->field_b4);
        SoundPlayer_StartSeq((struct Obj0203aba8*)actor, (void*)val, &actor->fieldBC);
        func_0209c2e0(actor, actor->field_cd, 0);
    }
    actor->field_b8 = (short)val;
    actor->field_ce = -1;
    actor->field_c8.bit2 = actor->field_c8.bit3;
    actor->field_c8.bit3 = 0;
}
