#include <globaldefs.h>
#include "GameState/GameState.h"
#include "NitroSDK/Matrix.h"

struct Struct_02049b54_2;
struct Obj02033874;
struct S_10088;

struct Struct_ov000_02161e30 {
    char pad0[0x8e20];
    int turns;
};

struct Struct_ov026_021daec8 {
    char pad0[0x240];
    Vector3fix center;
};

struct Struct_02049b54_3 {
    Vector3fix v;
};

extern "C" GameObject* func_0200fea4(GameState* gs, int id);
extern "C" Struct_02049b54_3 func_02049b54(Struct_02049b54_2* obj);
extern "C" void GameObject_SnapFacing(Obj02033874* obj, int angle);
extern "C" void func_02049bac(unsigned char* obj, int* rot);
extern "C" int func_02010088(S_10088* obj);

extern "C" {
void __clear(void* dst, int size);
int func_ov000_0215eb1c(Struct_ov000_02161e30*, short*, int, int);
void IntArray_Shuffle(int*, int);
}

// USA: func_ov026_021daec8
extern "C" ARM void func_ov026_021daec8(Struct_ov000_02161e30* battle, Struct_ov026_021daec8* view, int arg2) {
    short ids[8];
    GameState* gs = GameState::GetInstance();
    gs->GetResources();

    int count = func_ov000_0215eb1c(battle, ids, 8, 0);
    int n = 0;
    Vector3fix center = view->center;
    int order[8];
    int centerZ = center.z;

    for (int i = 0; i < count; i++) {
        GameObject* member = func_0200fea4(gs, ids[i]);
        if (member != NULL) {
            Vector3fix target;
            __clear(&target, sizeof(target));
            target.z = centerZ;

            Vector3fix pos = func_02049b54((Struct_02049b54_2*)member).v;
            pos.y = 0;

            Vector3fix dir;
            Vector3fix_Subtract(&target, &pos, &dir);
            dir.y = 0;
            Vector3fix_Normalize(&dir, &dir);
            fix32_t angle = fix32_Atan2(dir.x, dir.z);
            GameObject_SnapFacing((Obj02033874*)member, angle);

            Vector3fix rot;
            __clear(&rot, sizeof(rot));
            rot.y = angle;
            func_02049bac((unsigned char*)member, &rot.x);

            order[n++] = ids[i];
        }
    }

    if (arg2 && battle->turns > 0) {
        IntArray_Shuffle(order, n);
        for (int i = 0; i < n; i++) {
            GameObject* member = func_0200fea4(gs, order[i]);
            if (member != NULL && !member->obj3D_.IsTransitioningAnimations() && !func_02010088((S_10088*)member)) {
                member->obj3D_.SetNormalizedAnimationTime(0x1000 / n * i);
                member->obj3D_.AdvanceAnimations();
            }
        }
    }
}
