#include <globaldefs.h>
extern "C" void SoundPlayer_LoadSeq(void*, void*, int*);
extern "C" void SoundPlayer_StartSeq(struct Obj0203aba8*, void*, void*);

struct Actor0209c678;
extern "C" void BgmPlayer_FadeOut(struct Actor0209c678* actor, int arg);
extern "C" void SoundPlayer_RestoreHeapState(void* obj, int arg1);
extern "C" void func_0209c2e0(void* obj, int a, int b);
extern "C" void func_020bbd9c(void);

// USA: func_0209c6d8
extern "C" ARM void func_0209c6d8(void* actor, int arg) {
    BgmPlayer_FadeOut((struct Actor0209c678*)actor, 0);
    {
        int f = *(int*)((char*)actor + 0xb4);
        if (f > 0) {
            SoundPlayer_RestoreHeapState(actor, f);
        }
    }
    *(short*)((char*)actor + 0xce) = arg;
    SoundPlayer_LoadSeq((void*)(actor), (void*)(arg), (int*)(0));
    SoundPlayer_StartSeq((struct Obj0203aba8*)(actor), (void*)(arg), (void*)((char*)actor + 0xc4));
    func_0209c2e0(actor, *(unsigned char*)((char*)actor + 0xcd), 0);
    func_020bbd9c();
}
