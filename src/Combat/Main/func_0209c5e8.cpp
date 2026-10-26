#include <globaldefs.h>

struct Struct_0209c5e8_2 {
    unsigned char unknown_0_0_ : 1;
    unsigned char unknown_0_1_ : 1;
    unsigned char unknown_0_2_ : 1;
    unsigned char unknown_0_3_ : 5;
};

struct Struct_0209c5e8 {
    char unknown_0_[0xb0];
    int unknown_b0_;
    char unknown_b4_[0xb8 - 0xb4];
    short unknown_b8_;
    short unknown_ba_;
    void* unknown_bc_;
    void* unknown_c0_;
    char unknown_c4_[0xc8 - 0xc4];
    struct Struct_0209c5e8_2 unknown_c8_;
};

struct Struct_02109bf4_4;
struct Struct_0203aba8;

int IsBattleActiveAndCombatantsBit0Set_0209c140();
void BgmPlayer_FadeOut(struct Actor0209c678* actor, int arg);
void SoundPlayer_StopSeqOnHandle(void* obj, void* a, int b);
int SoundPlayer_StartSeq(struct Obj0203aba8* obj, void* key, void* target);

// USA: func_0209c5e8
extern "C" ARM void func_0209c5e8(struct Actor0209c5e8* actor) {
    if (actor->field_c8.bit2) return;
    if (IsBattleActiveAndCombatantsBit0Set_0209c140() != 0) {
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
