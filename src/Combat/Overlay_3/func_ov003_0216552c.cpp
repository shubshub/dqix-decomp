#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"

#if defined(jpn)
#define RG(u, j) (j)
#else
#define RG(u, j) (u)
#endif

extern "C" unsigned char* func_020936f8(void);
extern "C" void func_ov003_021612c0(void* obj);
extern "C" int func_ov003_02161344(void* obj);
extern "C" int func_ov003_02160b84(void* obj);
extern "C" int GameState_GetFollowCamera(char* obj);
struct Vector3i;
extern "C" void Camera_GetOrbit(unsigned char* obj, int* a, int* b, int* c);
extern "C" void func_ov017_021c37a4(void);
struct GlobalObj0202e6a8;
extern "C" void func_0202e784(struct GlobalObj0202e6a8* obj, int value);
struct CamState0202e6c0;
extern "C" void Camera_SetOrbitHeight(struct CamState0202e6c0* obj, int value);
struct Obj0202e71c;
extern "C" void Camera_SetOrbitDistance(struct Obj0202e71c* obj, int value);
struct Struct_0207fe44;
extern "C" void func_0207fe44(struct Struct_0207fe44* menu);
extern "C" void func_020939fc(unsigned char* obj);

struct Camera0216552c {
    char unk_0[0x4];
    int position_[3];
    int unknown_10_[3];
    char unk_1c[0x204];
    int angle_;
};

struct Struct_ov003_0216552c {
    char unk_0[RG(0x36, 0x2a)];
    short unknown_36_;
};

struct Struct_ov003_0216552c_2 {
    char unk_0[RG(0x324, 0x20c)];
    Struct_ov003_0216552c* window_;
    char unknown_328_[RG(0x13c, 0x7c)];
    unsigned int flags_;
    char unknown_468_[0xc];
    short unknown_474_;
    char unknown_476_[0xe];
    short unknown_484_[2];
    short unknown_488_;
    short unknown_48a_;
    char unknown_48c_[0x17];
    unsigned char unknown_4a3_;
    unsigned char step_;
};

// USA: func_ov003_0216552c
extern "C" ARM void func_ov003_0216552c(Struct_ov003_0216552c_2* self) {
    unsigned char* global = func_020936f8();
    Struct_ov003_0216552c* window = self->window_;
    short* nextState = self->unknown_484_;

    if (self->step_ == 0) {
        nextState[0] = 0x20;
        self->step_++;
    } else if (self->step_ == 1) {
        func_ov003_021612c0(self);
        self->step_++;
    } else if (self->step_ == 2) {
        if (BackgroundLoader::GetInstance()->GetNumQueuedTasks() > 0) {
            return;
        }
        int result = func_ov003_02161344(self);
        if (result != -1) {
            if (result != 1) {
                return;
            }
            if (func_ov003_02160b84(self) != 0) {
                self->unknown_488_ = 0x1a;
                self->unknown_474_ = self->unknown_48a_ = 0xa9;
                window->unknown_36_ = self->unknown_48a_;
                nextState[0] = 0x2e;
                nextState[1] = 1;
                self->unknown_4a3_ = 10;
                self->step_ = 1;
                self->flags_ |= 0x2000;
            } else {
                int distance;
                int height;
                int angle;
                int position[3];
                int target[3];
                Camera0216552c* camera = (Camera0216552c*)GameState_GetFollowCamera((char*)GameState::GetInstance());
                if (camera != NULL) {
                    *(Vector3i*)position = *(Vector3i const*)camera->position_;
                    *(Vector3i*)target = *(Vector3i const*)camera->unknown_10_;
                    Camera_GetOrbit((unsigned char*)camera, &angle, &height, &distance);
                }
                func_ov017_021c37a4();
                if (camera != NULL) {
                    *(Vector3i*)camera->position_ = *(Vector3i const*)position;
                    *(Vector3i*)camera->unknown_10_ = *(Vector3i const*)target;
                    func_0202e784((struct GlobalObj0202e6a8*)camera, angle);
                    Camera_SetOrbitHeight((struct CamState0202e6c0*)camera, height);
                    Camera_SetOrbitDistance((struct Obj0202e71c*)camera, distance);
                    camera->angle_ = angle;
                }
                func_0207fe44((struct Struct_0207fe44*)window);
                nextState[0] = 0x21;
                nextState[1] = 1;
                self->unknown_4a3_ = 10;
                self->step_ = 0;
                func_020939fc(global);
            }
        } else {
            self->unknown_488_ = 0x1a;
            self->unknown_474_ = self->unknown_48a_ = 0xa9;
            window->unknown_36_ = self->unknown_48a_;
            nextState[0] = 0x22;
            nextState[1] = 1;
            self->unknown_4a3_ = 10;
            self->step_ = 1;
            self->flags_ |= 0x2000;
        }
    }
}
