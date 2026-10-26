#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/Brightness.h"

struct Struct_ov017_0218e8c8 {
    unsigned char pad0[2];
    unsigned char enabled;
    unsigned char active;
};

struct Struct_ov017_0218e8c8_2 {
#if defined(jpn)
    unsigned char pad0[0x3508];
#else
    unsigned char pad0[0x3718];
#endif

    Struct_ov017_0218e8c8* table;
#if defined(jpn)
    unsigned char unknown_350c_[0x3910 - 0x350c];
#else
    unsigned char unknown_371c_[0x3b30 - 0x371c];
#endif

    Struct_ov017_0218e8c8* state;
};

extern "C" char* Zone3D_GetInstance(void);
extern "C" int func_020981e4(int, int);
extern "C" unsigned short func_ov017_021b8480(void* obj);
extern "C" unsigned char* func_ov017_021b8478(void* obj);
extern "C" int func_ov017_02191b58(void*, int);
extern "C" int func_020a35e0(unsigned char* obj, unsigned char index);
extern "C" void func_ov017_0218eafc(Struct_ov017_0218e8c8_2* ov, int idx);
extern "C" int GameObject_IsHidden(unsigned char* obj);
extern "C" int GameObject_Draw(void* obj, int a, int b);
extern "C" void func_ov017_0218dba0(int id);

// USA: func_ov017_0218e8c8
extern "C" ARM void func_ov017_0218e8c8(Struct_ov017_0218e8c8_2* ov, int id, int mode) {
#if defined(jpn)
 enum {regionalOffset0=0x860};
#else
 enum {regionalOffset0=0x840};
#endif
    GameState* gs = GameState::GetInstance();
    char* base = Zone3D_GetInstance();
    int inRange = 0;
    if (func_020981e4((int)(base + regionalOffset0), id)) {
        inRange = 1;
    }

    unsigned char* mask = NULL;
    if ((ov->table->active != 0 && func_ov017_021b8480(ov->table) == 0) ||
        (ov->state->active != 0 && ov->table->enabled != 0)) {
        mask = func_ov017_021b8478(ov->table);
    }

    for (int i = 0; i < 4; i++) {
        unsigned char b = func_ov017_02191b58(ov, i) | 2;
        if (mode == 1) {
            if (b != 0) continue;
        } else if (mode == 2 && b == 0) {
            continue;
        }

        int var6 = 0;
        GameObject* c = func_0200ff1c(gs, i);
        GameObject* obj = gs->GetGameObjectByIndex(i * 0xc + 0x14);
        if (c == NULL) continue;

        if (TestFlags08((GameResources*)ov, 2) == 0 && c->obj3D_.GetFlag(0x800000) == 0) {
            if (id != c->obj3D_.GetField06()) continue;
        } else if (TestFlags08((GameResources*)ov, 4) != 0) {
            if (id != c->obj3D_.GetField06()) continue;
        }

        if (mask != NULL && func_020a35e0(mask, i) == 0) continue;

        if (inRange && obj != NULL) {
            if (obj->obj3D_.unknown_2_ == 0x2347 || obj->obj3D_.unknown_2_ == 0x2348 ||
                obj->obj3D_.unknown_2_ == 0x2349) {
                var6 = 1;
            }
        }
        if (var6) continue;

        func_ov017_0218eafc(ov, i);
    }

    GameObject* member = gs->GetPartyMemberByIndex(0xce);
    if (member != NULL && !GameObject_IsHidden((unsigned char*)member) && GameObject_Draw(member, 1, 0)) {
        func_ov017_0218dba0(0xce);
    }
}
