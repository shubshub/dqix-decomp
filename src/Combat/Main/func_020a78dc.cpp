#include <globaldefs.h>
#include "GameState/Field3b0.h"
#include "GameState/GameState.h"
#include "Input/Input.h"
#include "Resource/GameResources.h"

struct Vec3 { int x; int y; int z; };
struct Bytes02033b88;
struct Obj02033b68;
struct Foo02033b58;
struct Obj02033834;
struct Container0201e8fc;
struct ShortField0x22e_020968c4;

struct Box0201e8fc {
    char pad0[0x18];
    short angle;
};

struct Field4328 {
    char pad0[0x220];
    unsigned char unknown_220_;
    unsigned char unknown_221_;
    unsigned char x1;
    unsigned char unknown_223_;
    unsigned char active;
};

struct Struct_020a78dc {
    char pad0[0x44];
    struct Vec3 pos;
    char unknown_50_[0xbe - 0x50];
    unsigned char unknown_be_;
    char unknown_bf_;
    unsigned char fc0;
    char unknown_c1_[0x134 - 0xc1];
    int mode;
    char unknown_138_[0x154 - 0x138];
    unsigned char f154;
    char unknown_155_[0x158 - 0x155];
    unsigned char dir;
    char unknown_159_[0x15d - 0x159];
    signed char unknown_15d_;
    short lockedAngle;
};

struct Struct_020e90a8 { int v[8]; };

extern "C" char* Zone3D_GetInstance();
extern "C" struct Field4328* GameResources_GetTouchWalk(void*);
extern "C" int FieldTaskQueue_IsEmpty(void** p);
extern "C" void GameObject_ForceMotionState(struct Bytes02033b88*, int);
extern "C" void GameObject_SetMotionState(struct Obj02033b68*, int);
extern "C" void GameObject_StoreMotionState(struct Foo02033b58*, unsigned char);
extern "C" int Camera_GetOrbitYaw(void*);
int fix32ReduceAngle0To2Pi(int);
extern "C" struct Box0201e8fc* ZoneFeatures_FindHeadingLockArea(struct Container0201e8fc*, struct Vec3*);
int fix32SignedAngleDistance(int, int);
int fix32abs(int);
extern "C" void GameObject_SetFacing(struct Obj02033834*, int);
extern "C" short TouchWalk_GetHeading(struct ShortField0x22e_020968c4*);

#if defined(jpn)
#define data_020e90a8 data_020e91b4
#endif
extern struct Struct_020e90a8 data_020e90a8;

// USA: func_020a78dc
extern "C" ARM void func_020a78dc(struct Struct_020a78dc* self) {
    char* world;
    void* camera;
    char* ov;
    struct Field4328* f;
    void** list;

    camera = GameState::GetInstance()->GetCamera();
    ov = (char*)GetGameResources();
#if defined(jpn)
    enum { regionalOffset0 = 0x34ec, regionalOffset1 = 0x8c };
#else
    enum { regionalOffset0 = 0x36fc, regionalOffset1 = 0x6c };
#endif
    list = *(void***)(ov + regionalOffset0);
    world = Zone3D_GetInstance();
    f = GameResources_GetTouchWalk(ov);
    struct Struct_020e90a8 table = data_020e90a8;

    self->mode = 0;
    if (g_keyManager.IsUpHeld() && g_keyManager.IsLeftHeld()) {
        self->mode = 1;
        self->dir = 0xc;
    } else if (g_keyManager.IsUpHeld() && g_keyManager.IsRightHeld()) {
        self->mode = 1;
        self->dir = 0xd;
    } else if (g_keyManager.IsDownHeld() && g_keyManager.IsLeftHeld()) {
        self->mode = 1;
        self->dir = 0xe;
    } else if (g_keyManager.IsDownHeld() && g_keyManager.IsRightHeld()) {
        self->mode = 1;
        self->dir = 0xf;
    } else if (g_keyManager.IsUpHeld()) {
        self->mode = 1;
        self->dir = 8;
    } else if (g_keyManager.IsDownHeld()) {
        self->mode = 1;
        self->dir = 9;
    } else if (g_keyManager.IsLeftHeld()) {
        self->mode = 1;
        self->dir = 0xa;
    } else if (g_keyManager.IsRightHeld()) {
        self->mode = 1;
        self->dir = 0xb;
    }

    if (g_touchInput.timeHeld_ >= 5) {
        self->mode = 2;
        struct Vec3 b;
        struct Vec3 a;
        int x1 = f->x1;
        int var9 = f->unknown_220_;
        int var10 = f->unknown_223_;
        int var11 = f->unknown_221_;
        int ay = var10 << 12;
        a.x = x1 << 12;
        a.y = ay;
        a.z = 0;
        b.x = var9 << 12;
        b.y = var11 << 12;
        b.z = 0;
        Vector3fix_Subtract((Vector3fix*)&a, (Vector3fix*)&b, (Vector3fix*)&a);
        if (Vector3fix_Length((Vector3fix*)&a) < 0x8000) {
            self->mode = 0;
        }
    }

    if (self->f154 == 0 || FieldTaskQueue_IsEmpty(list) == 0) {
        self->mode = 0;
    }

    if (self->mode == 0) {
        if (self->dir >= 8) {
            self->dir -= 8;
        }
        if (self->unknown_be_ != 0) {
            GameObject_ForceMotionState((struct Bytes02033b88*)self, 0);
        }
        self->unknown_15d_ = -1;
    } else if (self->mode == 1) {
        if (self->fc0 == 0 || self->fc0 == 0xa) {
            GameObject_SetMotionState((struct Obj02033b68*)self, 1);
        } else {
            GameObject_StoreMotionState((struct Foo02033b58*)self, 1);
        }
        int base = table.v[self->dir - 8];
        int angle = fix32ReduceAngle0To2Pi(base + Camera_GetOrbitYaw(camera));
        if (self->unknown_15d_ == self->dir) {
            angle = self->lockedAngle;
        } else {
            struct Vec3 pos = self->pos;
            struct Box0201e8fc* box = ZoneFeatures_FindHeadingLockArea((struct Container0201e8fc*)(world + regionalOffset1), &pos);
            if (box) {
                if (fix32abs(fix32SignedAngleDistance(angle, box->angle)) < 0xc91) {
                    self->unknown_15d_ = self->dir;
                    self->lockedAngle = box->angle;
                } else {
                    short flipped = fix32ReduceAngle0To2Pi(box->angle + 0x3244);
                    if (fix32abs(fix32SignedAngleDistance(angle, flipped)) < 0xc91) {
                        self->unknown_15d_ = self->dir;
                        self->lockedAngle = flipped;
                        angle = self->lockedAngle;
                    }
                }
            } else {
                self->unknown_15d_ = -1;
            }
        }
        GameObject_SetFacing((struct Obj02033834*)self, angle);
    } else if (self->mode == 2) {
        if (self->fc0 == 0) {
            GameObject_SetMotionState((struct Obj02033b68*)self, 1);
        } else {
            GameObject_StoreMotionState((struct Foo02033b58*)self, 1);
        }
        struct Field4328* g = GameResources_GetTouchWalk(ov);
        if (g->active != 0) {
            GameObject_SetFacing((struct Obj02033834*)self, TouchWalk_GetHeading((struct ShortField0x22e_020968c4*)g));
        }
        self->unknown_15d_ = -1;
    }
}
