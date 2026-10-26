#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/Brightness.h"

struct Struct_020a654c {
#if defined(jpn)
    char pad0[0x34ec];
#else
    char pad0[0x36fc];
#endif
    void* nodeList;
};

struct Struct_020a654c_2 {
    char pad0[3];
    unsigned char f3;
};

struct Struct_020a654c_3 {
    int f0;
    int f4;
};

extern "C" void* Zone3D_GetInstance();
extern "C" void LinkSession_GetInstance();
struct PointerField32c_ffc0;
extern "C" void* GameState_GetShip(PointerField32c_ffc0*);
struct HeadNode02046b24;
extern "C" int FieldTaskQueue_GetCurrentKind(HeadNode02046b24**);
struct S02046b1c;
extern "C" void* func_02046b1c(S02046b1c*);
struct GameResources;
int IsBrightnessTransitionActive(GameResources*);
extern "C" void func_020a75ec(void* p);
extern "C" void func_ov017_02193428(void*, void*);
extern "C" void func_020a7ce0(void* p);
extern "C" int func_020a7d74(void* p, int* out1, int* out2);
extern "C" int FieldTaskQueue_IsEmpty(void**);
extern "C" int func_ov017_021a93f0(void* res, int a, int b);

// USA: func_020a654c
extern "C" ARM void func_020a654c(struct Struct_020a654c* self) {
    void* gs = GameState::GetInstance();
    unsigned short* p;
    void* nodeList = self->nodeList;
    p = (unsigned short*)Zone3D_GetInstance();
    LinkSession_GetInstance();
    void* obj = GameState_GetShip((PointerField32c_ffc0*)gs);
    ((GameState*)gs)->GetLeader();
    int id = FieldTaskQueue_GetCurrentKind((HeadNode02046b24**)nodeList);
    void* var5 = func_02046b1c((S02046b1c*)nodeList);
    if (obj == 0) {
        return;
    }
    if (id == 10 && ((struct Struct_020a654c_2*)var5)->f3 != 0) {
        return;
    }
    if (id == 3) {
        if (IsBrightnessTransitionActive((GameResources*)self) == 0) {
            return;
        }
    }
    func_020a75ec(obj);
    if (TestFlags00((GameResources*)self, 0x2020) == 0) {
        func_ov017_02193428(obj, (void*)1);
    }
    if (*p == 0x2710) {
        func_020a7ce0(obj);
    }
    if (TestFlags00((GameResources*)self, 0x2020) != 0) {
        return;
    }
    struct Struct_020a654c_3 out;
    out.f4 = 0;
    out.f0 = 0;
    if (func_020a7d74(obj, &out.f4, &out.f0) == 0) {
        return;
    }
    if (out.f0 != 0 && out.f0 == 1) {
        out.f4 = 0x76c;
    }
    if (out.f4 == 0) {
        return;
    }
    if (FieldTaskQueue_IsEmpty((void**)self->nodeList) == 0) {
        return;
    }
    func_ov017_021a93f0(self, out.f4, 0);
}
