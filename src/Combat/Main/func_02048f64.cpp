#include <globaldefs.h>
#include "Combat/FormationPosition.h"
#include "GameState/GameState.h"
#include "Graphics/Vector.h"

struct Struct_02048e2c_2 {
    char unknown_0_[0x1c];
    unsigned char unknown_1c_;
    unsigned char unknown_1d_;
    unsigned char unknown_1e_;
    unsigned char unknown_1f_;
    unsigned int flags;
    unsigned char cells[0x10];
    unsigned char cellCount;
    char unknown_35_[0x3];
    int progress;
    short unknown_3c_;
    char unknown3e[0x2];
    int unknown_40_[3];
};

struct Struct_02048e2c {
    char unknown_0_[0x44];
    Vector3i position;
    char unknown50[0x6e];
    unsigned char unknown_be_;
    char unknown_bf_[0x7d];
    Struct_02048e2c_2* path;
};

extern "C" int func_02049ee8(unsigned char*);
struct Struct_02048f64_2;
extern "C" void func_020494c0(Struct_02048f64_2*);
struct Foo02033b58;
extern "C" void GameObject_StoreMotionState(Foo02033b58*, unsigned char);
struct Obj02033b68;
extern "C" void GameObject_SetMotionState(Obj02033b68*, int);
struct Struct_02048f64_3;
extern "C" void func_02049520(Struct_02048f64_3*);
struct Struct_02048f64;
extern "C" void func_02049a74(Struct_02048f64*);
struct Struct_02048c90;
extern "C" void func_02048c90(Struct_02048c90*);
extern "C" void func_02049390(unsigned char*, unsigned char);
struct Bytes02033b88;
extern "C" void GameObject_ForceMotionState(Bytes02033b88*, int);
struct Obj02033834;
extern "C" void GameObject_SetFacing(Obj02033834*, int);
extern "C" Vector3i func_ov025_021ee488(Vector3i* points, int count, int progress);

static inline Struct_02048cf0 inline_02048e2c_2(const int& cell) {
    return func_ov000_0216f74c(const_cast<int*>(&cell));
}

// USA: func_02048f64
extern "C" ARM void func_02048f64(Struct_02048e2c* actor) {
    if (!(actor->path->flags & 0x10)) {
        return;
    }
    fix32_t step;
    GameState* gs            = GameState::GetInstance();
    Struct_02048e2c_2* path = actor->path;
    int count                = path->cellCount;
    unsigned char* cells     = path->cells;
    if (count == 0) {
        path->flags &= ~0x10;
        return;
    }
    step             = FIX32_MULTIPLY((short)gs->GetAnimationDeltaTime(), 0xcc);
    fix32_t progress = path->progress;
    if (progress < 0) {
        path->progress = progress + step;
        return;
    }

    Vector3i points[16];
    int i;
    for (i = 0; i < count; i++) {
        Struct_02048cf0 pos = inline_02048e2c_2(cells[i]);
        points[i].x       = pos.x;
        points[i].y       = 0xcc;
        points[i].z       = pos.y;
    }
    int var9  = path->unknown_40_[2];
    int startX  = path->unknown_40_[0];
    points[0].x = startX;
    points[0].y = 0xcc;
    points[0].z = var9;

    int n = count;
    if (path->unknown_1f_ != 0xff) {
        Struct_02048cf0 pos = inline_02048e2c_2(path->unknown_1f_);
        points[count].x   = pos.x;
        points[count].y   = 0xcc;
        points[count].z   = pos.y;
        n                 = count + 1;
    }
    if (n < 4) {
        int last = n - 1;
        for (int j = n; j < 4; j++) {
            points[j] = points[last];
        }
        n = 4;
    }

    int var15       = (int)((float)path->progress / 4096.0f);
    Vector3i a    = points[var15];
    Vector3i b    = points[var15 + 1];
    fix32_t inverse = fix32_Divide(0x3000, Vector3fix_Distance(&a, &b));
    fix32_t speed   = FIX32_MULTIPLY(inverse, step);
    int lastIndex  = count - 1;
    if (path->unknown_3c_ < 0x1000) {
        path->unknown_3c_ += 0xcc;
    }
    fix32_t advance   = FIX32_MULTIPLY(speed, path->unknown_3c_);
    int var22    = 1;
    fix32_t remaining = FIX32_MULTIPLY((lastIndex << 12) - progress, 0x333);
    if (remaining < advance) {
        advance = remaining;
        if (func_02049ee8((unsigned char*)actor)) {
            if (actor->unknown_be_ != 0) {
                func_020494c0((Struct_02048f64_2*)actor);
            }
            GameObject_StoreMotionState((Foo02033b58*)actor, 0);
            var22 = 0;
        }
    } else if (func_02049ee8((unsigned char*)actor)) {
        GameObject_SetMotionState((Obj02033b68*)actor, 1);
    }

    short var24 = advance * 12;
    if (var24 < 0xc00) {
        var24 = 0xc00;
    } else if (var24 > 0x1400) {
        var24 = 0x1400;
    }
    ((Object3D*)actor)->SetAnimationPlaybackSpeed(var24, 0);
    path->progress = progress + advance;

    Vector3i target;
    if (remaining > 4) {
        target = func_ov025_021ee488(points, n, progress + advance);
    } else {
        target = points[lastIndex];
        if (func_02049ee8((unsigned char*)actor) && (actor->path->flags & 0x40)) {
            func_02049520((Struct_02048f64_3*)actor);
            func_02049a74((Struct_02048f64*)actor);
        }
        func_02048c90((Struct_02048c90*)actor);
        ((Object3D*)actor)->SetAnimationPlaybackSpeed(0x1000, 500);
        func_02049390((unsigned char*)actor, path->unknown_1d_);
        if (func_02049ee8((unsigned char*)actor) && actor->unknown_be_ == 1) {
            GameObject_ForceMotionState((Bytes02033b88*)actor, 0);
        }
        func_020494c0((Struct_02048f64_2*)actor);
        var22 = 0;
    }

    Vector3i current = actor->position;
    Vector3i delta;
    Vector3fix_Subtract(&target, &current, &delta);
    Vector3fix_Normalize(&delta, &delta);
    fix32_t angle   = fix32ReduceAngle0To2Pi(fix32_Atan2(delta.x, delta.z));
    actor->position = target;
    if (var22) {
        GameObject_SetFacing((Obj02033834*)actor, angle);
    }
}
