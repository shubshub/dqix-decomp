#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Graphics/Vector.h"

struct Struct_ov000_0215440c_2;
struct Struct_ov000_0215440c;
struct Struct_020338d4;
struct Vec3;

struct Struct_ov000_02160094 {
    char pad0[0x20];
    unsigned short unknown_20_;
};

struct Struct_ov000_021600f8 {
    char pad0[0xe];
    short unknown_e_;
};

struct Struct_ov025_021e6cf4 {
    char pad0[8];
    unsigned char kind : 7;
    unsigned char unknown_8_7_ : 1;
    unsigned char arg;
};

extern "C" unsigned char* func_ov000_02160130(void);
extern "C" void func_ov000_02167e6c(unsigned char* work);
extern "C" void func_ov000_02167dd8(unsigned char* work);
extern "C" void func_ov000_02167f10(unsigned char* work);
extern "C" void func_ov025_021def64(unsigned char* work, void* list, int arg);
extern "C" Struct_ov000_02160094* func_ov000_02160094(Struct_ov000_0215440c_2* list, int index);
extern "C" Struct_ov000_021600f8* func_ov000_021600f8(Struct_ov000_0215440c* list, int index);
extern "C" void func_ov025_021e4448(int* out, int x, int y, int z);
extern "C" void func_020338d4(Struct_020338d4* obj, Vec3* target);

// USA: func_ov025_021e6cf4
extern "C" ARM int func_ov025_021e6cf4(Struct_ov025_021e6cf4* task, void* list) {
    unsigned char* work = func_ov000_02160130();
    if (task->kind == 0) {
        func_ov000_02167e6c(work);
    } else if (task->kind == 1) {
        func_ov000_02167dd8(work);
    } else if (task->kind == 2) {
        GameState* gs = GameState::GetInstance();
        Struct_ov000_02160094* first = func_ov000_02160094((Struct_ov000_0215440c_2*)list, 0);
        Struct_ov000_021600f8* second = func_ov000_021600f8((Struct_ov000_0215440c*)list, 0);
        if (first == NULL || second == NULL) {
            return 1;
        }
        GameObject* a = gs->GetCombatantByIndex(first->unknown_20_);
        GameObject* b = gs->GetCombatantByIndex(second->unknown_e_);
        if (a == NULL || b == NULL) {
            return 1;
        }
        Vector3fix var6;
        var6 = a->obj3D_.position_;
        Vector3fix var7;
        var7 = b->obj3D_.position_;
        var6.y = 0xcc;
        var7.y = 0xcc;
        Vector3fix delta;
        Vector3fix dir;
        if (Vector3fixSquaredDistance(&var6, &var7) > 0) {
            Vector3fix_Subtract(&var7, &var6, &delta);
            Vector3fix_Normalize(&delta, &dir);
        } else {
            func_ov025_021e4448(&delta.x, 0, 0, 0x1000);
            func_ov025_021e4448(&dir.x, 0, 0, 0x1000);
        }
        int dist = a->obj3D_.GetRadius() / 2 + 0x6000 + b->obj3D_.GetRadius() / 2;
        Vector3fix var11;
        Vector3fix var12;
        Vector3fixMultiplyScalar(&dir, -dist / 2, &var11);
        Vector3fixMultiplyScalar(&dir, dist / 2, &var12);
        func_ov000_02167f10(work);
        var11.y = 0xcc;
        var12.y = 0xcc;
        a->obj3D_.position_ = var11;
        b->obj3D_.position_ = var12;
        if (task->unknown_8_7_) {
            func_020338d4((Struct_020338d4*)a, (Vec3*)&var12);
            func_020338d4((Struct_020338d4*)b, (Vec3*)&var11);
        }
    } else if (task->kind == 3) {
        func_ov000_02167f10(work);
        func_ov025_021def64(work, list, task->arg);
    }
    return 1;
}
