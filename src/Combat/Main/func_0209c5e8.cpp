#include <globaldefs.h>

struct Struct_0209c5e8_2 {
    unsigned char bit0 : 1;
    unsigned char unknown_0_1_ : 1;
    unsigned char bit2 : 1;
    unsigned char rest : 5;
};

struct Struct_0209c5e8 {
    char pad0[0xb0];
    int state;
    char unknown_b4_[0xb8 - 0xb4];
    short field_b8;
    short field_ba;
    void* fieldBC;
    void* fieldC0;
    char unknown_c4_[0xc8 - 0xc4];
    struct Struct_0209c5e8_2 unknown_c8_;
};

struct Actor0209c678;
struct Obj0203aba8;

extern "C" int func_0209c140();
extern "C" void BgmPlayer_FadeOut(struct Actor0209c678* actor, int arg);
extern "C" void SoundPlayer_StopSeqOnHandle(void* obj, void* a, int b);
extern "C" int SoundPlayer_StartSeq(struct Obj0203aba8* obj, void* key, void* target);

// USA: func_0209c5e8
extern "C" ARM void func_0209c5e8(struct Struct_0209c5e8* actor) {
    if (actor->unknown_c8_.bit2) return;
    if (func_0209c140() != 0) {
        BgmPlayer_FadeOut((struct Actor0209c678*)actor, 0);
        return;
    }
    if (actor->state == 1) {
        SoundPlayer_StopSeqOnHandle(actor, &actor->fieldBC, 0);
        SoundPlayer_StartSeq((struct Obj0203aba8*)actor, (void*)(int)actor->field_b8, &actor->fieldBC);
        return;
    }
    if (actor->state != 2) return;
    SoundPlayer_StopSeqOnHandle(actor, &actor->fieldC0, 0);
    SoundPlayer_StartSeq((struct Obj0203aba8*)actor, (void*)(int)actor->field_ba, &actor->fieldC0);
}
