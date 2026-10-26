#include <globaldefs.h>

struct Actor0209c678;
struct Actor0209c3b4;

extern "C" void BgmPlayer_FadeOut(struct Actor0209c678* actor, int arg);
extern "C" int func_0209c0f4(int value, int type);
extern "C" void func_0209c3b4(struct Actor0209c3b4* actor, int val);
extern "C" void SoundPlayer_RestoreHeapState(void* obj, int arg1);
extern "C" int func_0203ab6c(void*, void*);
extern "C" int func_0209c140();
extern "C" void* func_020bc068(void* obj, int unused);
extern "C" int func_0209c6bc(void* obj);
extern "C" void func_0209c5e8(void* actor);

struct Struct_0209c530 {
    char pad0[0xb0];
    int state;
    int field_b4;
    short field_b8;
    short field_ba;
    void* fieldBC;
    void* fieldC0;
    void* fieldC4;
    unsigned char unknown_c8_;
    unsigned char unknown_c9_;
    short unknown_ca_;
    unsigned char field_cc;
    unsigned char unknown_cd_;
    short field_ce;
};

// USA: func_0209c530
extern "C" ARM void func_0209c530(struct Struct_0209c530* a) {
    if (a->state != 2) return;

    BgmPlayer_FadeOut((struct Actor0209c678*)a, 0);
    a->state = 1;

    if (func_0209c0f4(a->field_b8, a->field_ba) != 0) {
        short v = a->field_b8;
        a->field_b8 = -1;
        func_0209c3b4((struct Actor0209c3b4*)a, v);
    } else {
        if (a->field_b4 > 0) {
            SoundPlayer_RestoreHeapState(a, a->field_b4);
        }
        func_0203ab6c(a, (void*)a->field_b8);
        if (func_0209c140() != 0) {
            BgmPlayer_FadeOut((struct Actor0209c678*)a, 0);
        } else {
            func_020bc068(&a->fieldBC, 0);
            if (func_0209c6bc(a) == 0) {
                func_0209c5e8(a);
            }
        }
    }

    a->field_ce = -1;
}
