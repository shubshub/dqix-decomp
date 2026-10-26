#if defined(jpn)
enum { Enum_02078050_1058 = 0x442 };
#else
enum { Enum_02078050_1058 = 0x422 };
#endif

#include <globaldefs.h>
#include "GameState/GameState.h"

struct Vec3 { int x; int y; int z; };

extern "C" void* LinkSession_GetInstance(void* self);

struct BitFlag02033f44;
extern "C" int* GameObject_GetWallHit(struct BitFlag02033f44* self);

extern "C" void func_02076ccc(void* self, int mode);

extern "C" int LinkSession_IsActive(int*);

extern "C" void func_020794f8(void* self, int a, int b);

struct Obj02033b68;
extern "C" void GameObject_SetMotionState(struct Obj02033b68* obj, int newVal);

struct Obj02033834;
extern "C" void GameObject_SetFacing(struct Obj02033834* obj, int arg);

extern "C" int LinkSession_IsGuest(void* obj);

extern "C" void* Zone3D_GetInstance(void);

struct U16Field0x6_020375f8;

extern "C" int Zone3D_GetGroundHeight(int seed, void* v);

struct Vector3i;

struct SearchStruct0202c1a4;
extern "C" signed char LinkSession_GetOwnSlot(struct SearchStruct0202c1a4* obj);

struct Flags02078050 {
    unsigned short unknown_0_;
    unsigned char unknown_2_[Enum_02078050_1058];
    int f424;
};

struct Struct_02078050 {
    char pad0[0x44];
    struct Vec3 unknown_44_;
    char unknown_50_[0x62];
    unsigned short unknown_b2_;
    unsigned short unknown_b4_;
    char unknown_b6_[0x9e];
    int f154;
    struct Vec3 unknown_158_;
};

// USA: func_02078050
extern "C" ARM void func_02078050(struct Struct_02078050* self) {
    void* mgr = LinkSession_GetInstance(self);

    if (GameObject_GetWallHit((struct BitFlag02033f44*)self) != 0) {
        func_02076ccc(self, 1);
        self->f154 = 0;
        if (LinkSession_IsActive((int*)mgr) == 0) {
            return;
        }
        func_020794f8(self, 0, 0);
        return;
    }

    self->unknown_b4_ = 0x1c2;
    self->unknown_b2_ = 0x1c2;
    GameObject_SetMotionState((struct Obj02033b68*)self, 1);

    struct Vec3 var1 = self->unknown_44_;
    var1.y = 0;
    struct Vec3 var2 = self->unknown_158_;
    var2.y = 0;
    struct Vec3 delta;
    int dist;

    dist = Vector3fix_Distance((const Vector3fix*)&var1, (const Vector3fix*)&var2);
    Vector3fix_Subtract((const Vector3fix*)&var2, (const Vector3fix*)&var1, (Vector3fix*)&delta);
    Vector3fix_Normalize((const Vector3fix*)&delta, (Vector3fix*)&delta);
    GameObject_SetFacing((struct Obj02033834*)self, fix32_Atan2(delta.x, delta.z));

    if (LinkSession_IsGuest(mgr) != 0) {
        return;
    }

    if (dist >= 0x1800) {
        return;
    }

    struct Flags02078050* flags = (struct Flags02078050*)Zone3D_GetInstance();
    struct Vec3 v = self->unknown_44_;
    unsigned short curId = flags->unknown_0_;

    if (curId == ((Object3D*)((struct U16Field0x6_020375f8*)self))->GetField06() && flags->f424 == 0) {
        v.y = Zone3D_GetGroundHeight((int)flags, &v);
        *(Vector3i*)((int*)&self->unknown_44_) = *(Vector3i const*)((int*)&v);
    }

    func_02076ccc(self, 1);
    self->f154 = 0;
    if (LinkSession_IsActive((int*)mgr) == 0) {
        return;
    }
    if (LinkSession_GetOwnSlot((struct SearchStruct0202c1a4*)mgr) != 0) {
        return;
    }
    func_020794f8(self, 0, 0);
}
