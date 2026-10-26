#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_ov025_021eb8e8_3 {
    unsigned long long mask;
    char pad8[0x10];
    unsigned int unknown_18_;
    unsigned char show;
    unsigned char unknown_1d_;
    unsigned char unknown_1e_;
};

struct Struct_ov025_021eb8e8 {
    char pad0[0x28];
    unsigned int unknown_28_;
    char pad2c[3];
    unsigned char unknown_2f_;
};

struct Struct_ov025_021eb8e8_2 {
    char pad0[0xc];
    int unknown_c_;
};

extern "C" void* func_ov000_02160130(void);
extern "C" char* func_ov000_02160f08(void* obj);
extern "C" int func_ov000_0215e9fc(int a, short* buf, int max, int start);
extern "C" int func_ov000_0215ec1c(int a, short* buf, int max, int start);
extern "C" Struct_ov025_021eb8e8_3* func_0204a01c(unsigned char* obj);
extern "C" void func_ov000_02162dc4(void* work, GameObject* arg1, GameObject* actor, unsigned int flags,
                                    int arg4, int arg5, unsigned long long mask, int flag);
extern "C" Struct_ov025_021eb8e8* func_ov025_021dafd0(char* obj, int id);
extern "C" void func_ov000_0217616c(Struct_ov025_021eb8e8* p);
extern "C" void func_ov000_0216ff20(char*, unsigned char);
extern "C" void func_0204a00c(unsigned char* obj, int value);
extern "C" int func_0204a0f8(unsigned char* obj);
extern "C" void func_0204a0e0(unsigned char* obj);
extern "C" int func_0204a040(unsigned char* obj);
extern "C" void func_0204a030(unsigned char* obj, int value);
extern "C" void GameObject_FaceGameObject(GameObject* obj, int id, int flag);

// USA: func_ov025_021eb8e8
extern "C" ARM void func_ov025_021eb8e8(Struct_ov025_021eb8e8_2* obj) {
    GameState* gs = GameState::GetInstance();
    void* work = func_ov000_02160130();
    char* var2 = func_ov000_02160f08(work);
    short buf[16];
    int n = 0;
    n = n + func_ov000_0215e9fc(obj->unknown_c_, buf, 0x10, n);
    n = n + func_ov000_0215ec1c(obj->unknown_c_, buf + n, 0x10 - n, 0);
    short* p = buf;
    for (int i = 0; i < n; p++, i++) {
        GameObject* c = gs->GetCombatantByIndex(*p);
        if (c == 0) {
            continue;
        }
        Struct_ov025_021eb8e8_3* hit = func_0204a01c((unsigned char*)c);
        if (hit != 0) {
            unsigned int flags = hit->unknown_18_ & ~0x80000;
            func_ov000_02162dc4(work, 0, c, flags, hit->unknown_1d_, hit->unknown_1e_, hit->mask, 1);
            Struct_ov025_021eb8e8* hud = func_ov025_021dafd0(var2, *p);
            if (hud != 0) {
                hud->unknown_28_ = flags;
                func_ov000_0217616c(hud);
                func_ov000_0216ff20((char*)hud, hit->unknown_1d_);
                hud->unknown_2f_ = hit->unknown_1e_;
            }
            func_0204a00c((unsigned char*)c, 0);
        }
        if (func_0204a0f8((unsigned char*)c)) {
            c->obj3D_.SetInheritedAlpha(0x1f);
            func_0204a0e0((unsigned char*)c);
        }
        if (func_0204a040((unsigned char*)c) != 0xff) {
            GameObject_FaceGameObject(c, func_0204a040((unsigned char*)c), 1);
            func_0204a030((unsigned char*)c, 0xff);
        }
    }
}
