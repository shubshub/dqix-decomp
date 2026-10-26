#if defined(jpn)
enum { Enum_02078050_1058 = 0x442 };
#else
enum { Enum_02078050_1058 = 0x422 };
#endif

#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_ov009_0218aa28 { int unknown_0_; int unknown_4_; int unknown_8_; };

extern "C" void* LinkSession_GetInstance(void* self);

struct BitFlag02033f44;
int* GameObject_GetWallHit(struct BitFlag02033f44* self);

extern "C" void func_02076ccc(void* arg0, int arg1);

int LinkSession_IsActive(int*);

extern "C" void func_020794f8(void* arg0, int arg1, int arg2);

struct Obj02033b68;
void GameObject_SetMotionState(struct Obj02033b68* obj, int newVal);

struct Obj02033834;
void GameObject_SetFacing(struct Obj02033834* obj, int arg);

extern "C" int LinkSession_IsGuest(void* obj);

extern "C" void* Zone3D_GetInstance(void);

struct Struct_02039df4;

extern "C" int Zone3D_GetGroundHeight(int seed, void* v);

struct Vector3i;

struct SearchStruct0202c1a4;
signed char LinkSession_GetOwnSlot(struct SearchStruct0202c1a4* obj);

struct Struct_02078050_2 {
    unsigned short unknown_0_;
    unsigned char unknown_2_[Enum_02078050_1058];
    int unknown_424_;
};

struct Struct_02078050 {
    char unknown_0_[0x44];
    struct Struct_ov009_0218aa28 unknown_44_;
    char unknown_50_[0x62];
    unsigned short unknown_b2_;
    unsigned short unknown_b4_;
    char unknown_b6_[0x9e];
    int unknown_154_;
    struct Struct_ov009_0218aa28 unknown_158_;
};

// USA: func_02078050
extern "C" ARM void func_02078050(struct Entity02078050* self) {
    void* mgr = LinkSession_GetInstance(self);

    if (GameObject_GetWallHit((struct BitFlag02033f44*)self) != 0) {
        TrySetMode02076ccc(self, 1);
        self->f154 = 0;
        if (LinkSession_IsActive((int*)mgr) == 0) {
            return;
        }
        func_020794f8(arg0, 0, 0);
        return;
    }

    self->fb4 = 0x1c2;
    self->fb2 = 0x1c2;
    GameObject_SetMotionState((struct Obj02033b68*)self, 1);

    struct Struct_ov009_0218aa28 var1 = arg0->unknown_44_;
    var1.unknown_4_ = 0;
    struct Struct_ov009_0218aa28 var2 = arg0->unknown_158_;
    var2.unknown_4_ = 0;
    struct Struct_ov009_0218aa28 var3;
    int var4;

    dist = Vector3fix_Distance((const Vector3fix*)&pos44, (const Vector3fix*)&pos158);
    Vector3fix_Subtract((const Vector3fix*)&pos158, (const Vector3fix*)&pos44, (Vector3fix*)&delta);
    Vector3fix_Normalize((const Vector3fix*)&delta, (Vector3fix*)&delta);
    GameObject_SetFacing((struct Obj02033834*)self, fix32_Atan2(delta.x, delta.z));

    if (LinkSession_IsGuest(mgr) != 0) {
        return;
    }

    if (var4 >= 0x1800) {
        return;
    }

    struct Flags02078050* flags = (struct Flags02078050*)Zone3D_GetInstance();
    struct Vec3 v = self->f44;
    unsigned short curId = flags->f00;

    if (curId == ((Object3D*)((struct U16Field0x6_020375f8*)self))->GetField06() && flags->f424 == 0) {
        v.y = Zone3D_GetGroundHeight((int)flags, &v);
        *(Vector3i*)((int*)&self->f44) = *(Vector3i const*)((int*)&v);
    }

    TrySetMode02076ccc(self, 1);
    self->f154 = 0;
    if (LinkSession_IsActive((int*)mgr) == 0) {
        return;
    }
    if (LinkSession_GetOwnSlot((struct SearchStruct0202c1a4*)mgr) != 0) {
        return;
    }
    func_020794f8(arg0, 0, 0);
}
