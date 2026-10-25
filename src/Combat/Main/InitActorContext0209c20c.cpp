#include <globaldefs.h>
void ScaleAndNotify0203ad88(void*, void*, int);

struct Actor0209c678;
void BgmPlayer_FadeOut(struct Actor0209c678* actor, int arg);

void CallField0xa00203aa44(void* obj);
void ClearField0x0_020bc078(int* field);

extern "C" void func_020bbd9c(void);
extern "C" void func_0209c2e0(void* obj, int a, int b);

struct Actor0209c20c {
    char pad0[0xb0];
    int state;
    int field_b4;
    short field_b8;
    short field_ba;
    void* fieldBC;
    void* fieldC0;
};

// USA: func_0209c20c
ARM void InitActorContext0209c20c(struct Actor0209c20c* actor) {
    ScaleAndNotify0203ad88((void*)(actor), (void*)(0), (int)(0));
    BgmPlayer_FadeOut((struct Actor0209c678*)actor, 0);
    func_020bbd9c();
    CallField0xa00203aa44(actor);
    actor->state = 0;
    actor->field_b4 = 0;
    actor->field_b8 = -1;
    ClearField0x0_020bc078((int*)&actor->fieldBC);
    actor->field_ba = -1;
    ClearField0x0_020bc078((int*)&actor->fieldC0);
    func_0209c2e0(actor, 0x7f, 0);
}
