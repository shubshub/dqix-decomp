#include <globaldefs.h>
#include "GameState/GameState.h"
#include "NitroSDK/Matrix.h"

#if defined(jpn)
#define RG(u, j) (j)
#else
#define RG(u, j) (u)
#endif

struct Struct_ov025_021dc940 {
    char pad0[0x8e14];
    signed char unknown_8e14_;
    char unknown_8e15_[0x8e24 - 0x8e15];
    int unknown_8e24_;
};

struct Struct_ov025_021dc940_3 {
    char pad0[0x20];
    unsigned short id;
};

struct Struct_ov025_021dc940_4 {
    char pad0[0xb];
    unsigned char lo : 2;
    unsigned char disabled : 1;
    char unknown_c_[4];
    Struct_ov025_021dc940_3* entry;
};

struct Struct_ov025_021dc940_5 {
    char pad0[RG(0x29c, 0x218)];
    Struct_ov025_021dc940* battle;
    char unknown_2a0_[RG(0x4d4 - 0x2a0, 0x450 - 0x21c)];
    char unknown_4d4_[0x890 - 0x4d4];
    char unknown_890_[0xc18 - 0x890];
    char unknown_c18_[0xc88 - 0xc18];
    int unknown_c88_[3];
    char unknown_c94_[RG(0x3760 - 0xc94, 0x371c - 0xc10)];
    char entryList[RG(0x55d8 - 0x3760, 0x57c8 - 0x371c)];
    int unknown_55d8_;
    char unknown_55dc_[RG(0x6e4b - 0x55dc, 0x703b - 0x57cc)];
    unsigned char state;
    unsigned char unknown_6e4c_;
    char unknown_6e4d_[0x6efc - 0x6e4d];
    short unknown_6efc_;
    unsigned char unknown_6efe_;
    char unknown_6eff_[0x6fd4 - 0x6eff];
    unsigned char unknown_6fd4_;
    char unknown_6fd5_[3];
    unsigned char unknown_6fd8_;
    char unknown_6fd9_[3];
    Vector3i unknown_6fdc_;
    unsigned char unknown_6fe8_;
    char unknown_6fe9_[0x6ff8 - 0x6fe9];
    unsigned char unknown_6ff8_;
    unsigned char unknown_6ff9_;
    char unknown_6ffa_[0x7747 - 0x6ffa];
    unsigned char started;
};

struct Actor0209c73c;

extern "C" void* func_02057924(void);
extern "C" int func_ov000_0215e9fc(void* party, short* buf, int max, int start);
extern "C" int func_ov000_0215ec1c(void* party, short* buf, int max, int start);
extern "C" int func_02058618(void* mgr);
extern "C" unsigned char* NumberPopups_GetInstance(void);
extern "C" int NumberPopups_IsEmpty(unsigned char* data);
extern "C" int func_ov025_021ed2f4(void* obj);
extern "C" int func_ov025_021ed0fc(void* obj);
extern "C" int func_0209ca2c(void* obj);
struct Bytes02033b88;
extern "C" void GameObject_ForceMotionState(Bytes02033b88*, int);
extern "C" void __clear(void* dst, int size);
extern "C" Struct_ov025_021dc940_4* func_ov000_02160f20(void* obj);
extern "C" void func_ov000_021754e0(int, int);
extern "C" void func_ov000_0218142c(void* list, int id);
extern "C" void func_ov000_0216f1e4(void* obj, int* pos, int a, int b);
extern "C" void* MessageSystem_GetInstance(void);
extern "C" void MessageSystem_Stop(void* obj);
extern "C" void func_0209c7fc(void* obj);
extern "C" void func_0209c73c(Actor0209c73c* actor);
extern "C" void func_02048994(void);

extern int g_bgmPlayer;

static inline unsigned char inline_ov025_021dc940(GameObject* c) {
    return *((unsigned char*)c + 0xbe);
}

static inline int inline_ov025_021dc940_2(int id) {
    return id >= 0 && id <= 3;
}

struct Struct_ov025_021dc940_2 { char pad[RG(0x5d8, 0x7c8)]; int turn; };

// USA: func_ov025_021dc940
extern "C" ARM int func_ov025_021dc940(Struct_ov025_021dc940_5* obj) {
    GameState* gs = GameState::GetInstance();
    Struct_ov025_021dc940* party = obj->battle;
    void* mgr = func_02057924();

    unsigned char state = obj->state;
    if (state != 0) {
        if (state == 3) {
            obj->state = 4;
            obj->unknown_6e4c_ = 0;
        }
        return 0;
    }
    if ((int)obj->unknown_6efe_ > 0) {
        return 0;
    }

    short buf[16];
    int n = 0;
    n = n + func_ov000_0215e9fc(party, buf, 0x10, n);
    n = n + func_ov000_0215ec1c(party, buf + n, 0x10 - n, 0);

    for (int i = 0; i < n; i++) {
        GameObject* c = gs->GetCombatantByIndex(buf[i]);
        if (c != NULL && (inline_ov025_021dc940(c) == 4 || inline_ov025_021dc940(c) == 3)) {
            return 0;
        }
    }

    if (func_02058618(mgr) > 0) {
        return 0;
    }
    if (NumberPopups_IsEmpty(NumberPopups_GetInstance()) == 0) {
        return 0;
    }
    if (func_ov025_021ed2f4(obj->unknown_890_) == 0) {
        return 0;
    }
    if (func_ov025_021ed0fc(obj->unknown_4d4_) == 0) {
        return 0;
    }
    if (func_0209ca2c(&g_bgmPlayer) != 0) {
        return 0;
    }

    int busy = 0;
    for (int i = 0; i < n; i++) {
        GameObject* c = gs->GetCombatantByIndex(buf[i]);
        if (c == NULL) {
            continue;
        }
        c->obj3D_.SetAnimationPlaybackSpeed(0x1000, 0);
        if (obj->started == 0) {
            unsigned char motion = inline_ov025_021dc940(c);
            if (motion != 4 && motion != 6) {
                GameObject_ForceMotionState((Bytes02033b88*)c, 0);
            }
        }
        if (c->obj3D_.IsVisible() && c->obj3D_.IsTransitioningAnimations()) {
            busy = 1;
        }
    }
    obj->started = 1;
    if (busy) {
        return 0;
    }
    obj->started = 0;

    Vector3i zero;
    __clear(&zero, sizeof(zero));
    obj->unknown_6fdc_ = zero;
    obj->unknown_6fe8_ = 0;
    obj->unknown_6fd8_ = 0;
    obj->unknown_6ff9_ = 0;
    obj->unknown_6efc_ = -1;
    obj->unknown_6ff8_ = 0;
    obj->unknown_6fd4_ = 0;

    Struct_ov025_021dc940_4* slot = func_ov000_02160f20(obj);
    Struct_ov025_021dc940_3* entry;
    if (slot != NULL && (entry = slot->entry) != NULL && !slot->disabled) {
        int id = entry->id;
        if (inline_ov025_021dc940_2(id)) {
            func_ov000_021754e0((int)obj->entryList, id);
            func_ov000_0218142c(obj->entryList, id);
        }
    }
    func_ov000_0216f1e4(obj->unknown_c18_, obj->unknown_c88_, 0, 0);
    MessageSystem_Stop(MessageSystem_GetInstance());

    Struct_ov025_021dc940* battle = obj->battle;
    if (((Struct_ov025_021dc940_2*)((int)obj + 0x5000))->turn == battle->unknown_8e24_ - 1 && battle->unknown_8e14_ != 0) {
        func_0209c7fc(&g_bgmPlayer);
    } else {
        func_0209c73c((Actor0209c73c*)&g_bgmPlayer);
    }
    func_02048994();
    return 1;
}
