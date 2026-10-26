#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Graphics/Vector.h"
#include "std_library_functions.h"

struct Struct_02078398_2 {
    char name[0x10];
    unsigned char f10;
    unsigned char unknown_11_;
    short f12;
    short objectId;
    short unknown_16_;
    short f18;
    short unknown_1a_;
    short f1c;
    short pad1e;
    Vector3fix unknown_20_;
    Vector3fix position;
    Vector3fix rotation;
    Vector3fix scale;
};

struct Struct_ov000_0215440c_2;
struct Struct_ov000_0215440c;

struct Struct_ov000_0215440c_4 {
    char pad0[0x20];
    unsigned short id;
};

struct Struct_ov000_0215440c_5 {
    char pad0[0xe];
    short targetId;
};

struct Struct_ov025_021ef9a8 { int a; int b; int c; int d; int e; int f; };

struct Struct_ov025_021ef988_11 {
    char pad0[0x20];
    int state;
    int objectId;
};

struct Struct_ov025_021e4624 {
    char pad0[8];
    const char* name;
    unsigned short unknown_c_;
    short distance;
};

extern "C" Struct_ov000_0215440c_4* func_ov000_02160094(Struct_ov000_0215440c_2* list, int index);
extern "C" Struct_ov000_0215440c_5* func_ov000_021600f8(Struct_ov000_0215440c* list, int index);
extern "C" void func_ov025_021e3158(struct Struct_ov025_021ef9a8* p);
extern "C" void func_02078484(struct Struct_02078398_2* p);
extern "C" int func_02057fb4(void*, int, void*);
extern "C" void func_02057db8(void*, int);
extern "C" void* func_02057924(void);

extern struct Struct_ov025_021ef9a8 data_ov025_021ef9a8;
extern struct Struct_ov025_021ef988_11 data_ov025_021ef988;

// USA: func_ov025_021e4624
extern "C" ARM int func_ov025_021e4624(struct Struct_ov025_021e4624* p, void* slot) {
    GameState* gs = GameState::GetInstance();
    void* list = func_02057924();
    Struct_ov000_0215440c_4* var2 = func_ov000_02160094((Struct_ov000_0215440c_2*)slot, 0);
    Struct_ov000_0215440c_5* var3 = func_ov000_021600f8((Struct_ov000_0215440c*)slot, 0);
    int var4 = var2->id;
    int var5 = var3->targetId;
    GameObject* src = gs->GetGameObjectByIndex(var4);
    GameObject* dst = gs->GetGameObjectByIndex(var5);
    if (src == NULL || dst == NULL) {
        func_ov025_021e3158(&data_ov025_021ef9a8);
        return 1;
    }

    if (data_ov025_021ef988.state == 0) {
        struct Struct_02078398_2 req;
        func_02078484(&req);
        Vector3fix from = src->obj3D_.position_;
        Vector3fix to = dst->obj3D_.position_;
        Vector3fix dir;
        Vector3fix_Subtract(&to, &from, &dir);
        dir.y = 0;
        Vector3fix_Normalize(&dir, &dir);
        Vector3fixMultiplyScalar(&dir, p->distance, &req.unknown_20_);
        req.position = src->obj3D_.position_;
        req.rotation = src->obj3D_.rotation_;
        req.scale = src->obj3D_.GetScale();
        req.position.y += src->obj3D_.GetHeight() / 2;
        if (p->name != NULL) {
            strcpy(req.name, p->name);
        }
        data_ov025_021ef988.objectId = func_02057fb4(list, p->unknown_c_, &req);
        data_ov025_021ef988.state++;
        return 0;
    }

    if (data_ov025_021ef988.state == 1) {
        GameObject* effect = gs->GetGameObjectByIndex(data_ov025_021ef988.objectId);
        if (effect == NULL) {
            func_ov025_021e3158(&data_ov025_021ef9a8);
            return 1;
        }
        Vector3fix a = dst->obj3D_.position_;
        Vector3fix b = effect->obj3D_.position_;
        fix32_t dist = Vector3fix_Distance(&a, &b);
        fix32_t range = (src->obj3D_.GetHeight() + dst->obj3D_.GetHeight()) / 2;
        if (range < p->distance * 2) {
            range = p->distance * 2;
        }
        if (dist >= range) {
            return 0;
        }
        func_02057db8(list, data_ov025_021ef988.objectId);
        func_ov025_021e3158(&data_ov025_021ef9a8);
        return 1;
    }

    func_ov025_021e3158(&data_ov025_021ef9a8);
    return 1;
}
