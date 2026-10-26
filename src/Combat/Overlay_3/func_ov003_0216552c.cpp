#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"

#if defined(jpn)
#define RG(u, j) (j)
#else
#define RG(u, j) (u)
#endif

unsigned char* GetGlobal02109030_020936f8(void);
extern "C" void func_ov003_021612c0(void* obj);
extern "C" int func_ov003_02161344(void* obj);
int CountValidCombatantsMinusField_02160b84(void* obj);
int GameState_GetFollowCamera(char* obj);
struct Vector3i;
void Camera_GetOrbit(unsigned char* obj, int* a, int* b, int* c);
extern "C" void func_ov017_021c37a4(void);
struct GlobalObj0202e6a8;
void AddWrappedField0x70_0202e784(struct GlobalObj0202e6a8* obj, int value);
struct CamState0202e6c0;
void Camera_SetOrbitHeight(struct CamState0202e6c0* obj, int value);
struct Obj0202e71c;
void Camera_SetOrbitDistance(struct Obj0202e71c* obj, int value);
struct Cont0207fe44;
void CallFunc0204c804OverAllElems(struct Cont0207fe44* menu);
void ClearFlag0x3c9Bit0AndCleanup_020939fc(unsigned char* obj);

struct Struct_ov003_0216552c_3 {
    char unknown_0_[0x4];
    int unknown_4_[3];
    int unknown_10_[3];
    char unknown_1c_[0x204];
    int unknown_220_;
};

struct Struct_ov003_0216552c {
    char unknown_0_[RG(0x36, 0x2a)];
    short unknown_36_;
};

struct Struct_ov003_0216552c_2 {
    char unknown_0_[RG(0x324, 0x20c)];
    Struct_ov003_0216552c* unknown_324_;
    char unknown_328_[RG(0x13c, 0x7c)];
    unsigned int unknown_464_;
    char unknown_468_[0xc];
    short unknown_474_;
    char unknown_476_[0xe];
    short unknown_484_[2];
    short unknown_488_;
    short unknown_48a_;
    char unknown_48c_[0x17];
    unsigned char unknown_4a3_;
    unsigned char unknown_4a4_;
};

// USA: func_ov003_0216552c
extern "C" ARM void func_ov003_0216552c(Struct_ov003_0216552c_2* arg0) {
    unsigned char* var0 = func_020936f8();
    Struct_ov003_0216552c* var1 = arg0->unknown_324_;
    short* var2 = arg0->unknown_484_;

    if (arg0->unknown_4a4_ == 0) {
        var2[0] = 0x20;
        arg0->unknown_4a4_++;
    } else if (arg0->unknown_4a4_ == 1) {
        func_ov003_021612c0(arg0);
        arg0->unknown_4a4_++;
    } else if (arg0->unknown_4a4_ == 2) {
        if (BackgroundLoader::GetInstance()->GetNumQueuedTasks() > 0) {
            return;
        }
        int var3 = func_ov003_02161344(arg0);
        if (var3 != -1) {
            if (var3 != 1) {
                return;
            }
            if (func_ov003_02160b84(arg0) != 0) {
                arg0->unknown_488_ = 0x1a;
                arg0->unknown_474_ = arg0->unknown_48a_ = 0xa9;
                var1->unknown_36_ = arg0->unknown_48a_;
                var2[0] = 0x2e;
                var2[1] = 1;
                arg0->unknown_4a3_ = 10;
                arg0->unknown_4a4_ = 1;
                arg0->unknown_464_ |= 0x2000;
            } else {
                int distance;
                int height;
                int angle;
                int position[3];
                int target[3];
                Camera0216552c* camera = (Camera0216552c*)GameState_GetFollowCamera((char*)GameState::GetInstance());
                if (camera != NULL) {
                    *(Vector3i*)position = *(Vector3i const*)camera->position_;
                    *(Vector3i*)target = *(Vector3i const*)camera->target_;
                    Camera_GetOrbit((unsigned char*)camera, &angle, &height, &distance);
                }
                func_ov017_021c37a4();
                if (camera != NULL) {
                    *(Vector3i*)camera->position_ = *(Vector3i const*)position;
                    *(Vector3i*)camera->target_ = *(Vector3i const*)target;
                    AddWrappedField0x70_0202e784((struct GlobalObj0202e6a8*)camera, angle);
                    Camera_SetOrbitHeight((struct CamState0202e6c0*)camera, height);
                    Camera_SetOrbitDistance((struct Obj0202e71c*)camera, distance);
                    camera->angle_ = angle;
                }
                func_0207fe44((struct Struct_0207fe44*)var1);
                var2[0] = 0x21;
                var2[1] = 1;
                arg0->unknown_4a3_ = 10;
                arg0->unknown_4a4_ = 0;
                func_020939fc(var0);
            }
        } else {
            arg0->unknown_488_ = 0x1a;
            arg0->unknown_474_ = arg0->unknown_48a_ = 0xa9;
            var1->unknown_36_ = arg0->unknown_48a_;
            var2[0] = 0x22;
            var2[1] = 1;
            arg0->unknown_4a3_ = 10;
            arg0->unknown_4a4_ = 1;
            arg0->unknown_464_ |= 0x2000;
        }
    }
}
