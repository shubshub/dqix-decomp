#include <globaldefs.h>

struct Struct_02109bf4_4;
struct Struct_0209c3b4_2;

void BgmPlayer_FadeOut(struct Actor0209c678* actor, int arg);
int IsMissingFromTable0209c0f4(int value, int type);
void SetStateAndDispatch0209c3b4(struct Actor0209c3b4* actor, int val);
void SoundPlayer_RestoreHeapState(void* obj, int arg2);
int SetContextAndQuery0203ab6c(void*, void*);
int IsBattleActiveAndCombatantsBit0Set_0209c140();
void* CallFunc020bc594OnField0_020bc068(void* obj, int unused);
int IsHandleB8Active0209c6bc(void* obj);
extern "C" void func_0209c5e8(void* actor);

struct Struct_0209c530 {
    char unknown_0_[0xb0];
    int unknown_b0_;
    int unknown_b4_;
    short unknown_b8_;
    short unknown_ba_;
    void* unknown_bc_;
    void* unknown_c0_;
    void* unknown_c4_;
    unsigned char unknown_c8_;
    unsigned char unknown_c9_;
    short unknown_ca_;
    unsigned char unknown_cc_;
    unsigned char unknown_cd_;
    short unknown_ce_;
};

// USA: func_0209c530
extern "C" ARM void func_0209c530(struct Struct_0209c530* arg0) {
    if (arg0->unknown_b0_ != 2) return;

    BgmPlayer_FadeOut((struct Actor0209c678*)a, 0);
    a->state = 1;

    if (func_0209c0f4(arg0->unknown_b8_, arg0->unknown_ba_) != 0) {
        short var0 = arg0->unknown_b8_;
        arg0->unknown_b8_ = -1;
        func_0209c3b4((struct Struct_0209c3b4_2*)arg0, var0);
    } else {
        if (a->field_b4 > 0) {
            SoundPlayer_RestoreHeapState(a, a->field_b4);
        }
        SetContextAndQuery0203ab6c(a, (void*)a->field_b8);
        if (IsBattleActiveAndCombatantsBit0Set_0209c140() != 0) {
            BgmPlayer_FadeOut((struct Actor0209c678*)a, 0);
        } else {
            func_020bc068(&arg0->unknown_bc_, 0);
            if (func_0209c6bc(arg0) == 0) {
                func_0209c5e8(arg0);
            }
        }
    }

    arg0->unknown_ce_ = -1;
}
