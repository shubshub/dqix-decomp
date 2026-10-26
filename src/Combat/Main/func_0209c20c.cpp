#include <globaldefs.h>
extern "C" void SoundPlayer_StopStream(void*, void*, int);

struct Actor0209c678;
extern "C" void BgmPlayer_FadeOut(struct Actor0209c678* actor, int arg);

extern "C" void SoundPlayer_UnloadAll(void* obj);
extern "C" void NNS_SndHandleInit(int* field);

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
extern "C" ARM void func_0209c20c(struct Actor0209c20c* actor) {
    SoundPlayer_StopStream((void*)(actor), (void*)(0), (int)(0));
    BgmPlayer_FadeOut((struct Actor0209c678*)actor, 0);
    func_020bbd9c();
    SoundPlayer_UnloadAll(actor);
    actor->state = 0;
    actor->field_b4 = 0;
    actor->field_b8 = -1;
    NNS_SndHandleInit((int*)&actor->fieldBC);
    actor->field_ba = -1;
    NNS_SndHandleInit((int*)&actor->fieldC0);
    func_0209c2e0(actor, 0x7f, 0);
}
