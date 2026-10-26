#include <globaldefs.h>

struct Actor0209c73c;
extern "C" void func_0209c73c(struct Actor0209c73c* actor);
extern "C" void SoundPlayer_UnloadAll(void* obj);
extern "C" int SoundPlayer_LoadSeq(void* obj, void* arg1, int* out);
struct Obj0203aba8;
extern "C" int SoundPlayer_StartSeq(struct Obj0203aba8* obj, void* key, void* target);
extern "C" void func_0209c2e0(void* obj, int a, int b);

struct Struct_0209c3b4 {
    unsigned char bit0 : 1;
    unsigned char unknown_0_1_ : 1;
    unsigned char bit2 : 1;
    unsigned char unknown_0_3_ : 1;
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
    struct Struct_0209c3b4 unknown_c8_;       // 0xc8
    unsigned char unknown_c9_;                // 0xc9
    short unknown_ca_;                          // 0xca
    unsigned char field_cc;                    // 0xcc
    unsigned char unknown_cd_;                      // 0xcd
    short field_ce;                                // 0xce
};

// USA: func_0209c3b4
extern "C" ARM void func_0209c3b4(struct Actor0209c3b4* actor, int val) {
    if (actor->state == 2) return;
    if (actor->state == 1 && val == actor->field_b8) return;
    if (actor->unknown_c8_.bit2) return;
    if (actor->field_ce > -1) {
        func_0209c73c((struct Actor0209c73c*)actor);
    }
    actor->state = 1;
    SoundPlayer_UnloadAll(actor);
    if (val > 0) {
        SoundPlayer_LoadSeq(actor, (void*)val, &actor->field_b4);
        SoundPlayer_StartSeq((struct Obj0203aba8*)actor, (void*)val, &actor->fieldBC);
        func_0209c2e0(actor, actor->unknown_cd_, 0);
    }
    actor->field_b8 = (short)val;
    actor->field_ce = -1;
    actor->unknown_c8_.bit2 = actor->unknown_c8_.unknown_0_3_;
    actor->unknown_c8_.unknown_0_3_ = 0;
}
