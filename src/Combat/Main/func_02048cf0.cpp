#include <globaldefs.h>
#include "World/Object3D.h"

struct Struct_02048cf0_3;

struct Struct_02048cf0 { int x; int y; };
struct Struct_020e7b48 { int v[3]; };

struct Struct_02048cf0_2 {
    char unknown_0_[0x20];
    unsigned int unknown_20_;
};

struct Struct_02048cf0_3 {
    char unknown_0_[0x44];
    int vec44[3];
    char unknown_50_[0x6e];
    unsigned char unknown_be_;
    char unknown_bf_[0x7d];
    Struct_02048cf0_2* ptr;
};

extern "C" int func_020493ec(unsigned char*);
extern "C" int func_020493c8(unsigned char*);
extern "C" int func_020493a4(unsigned char*);
extern "C" void func_02049390(unsigned char*, unsigned char);
extern "C" void func_020493b8(unsigned char*, unsigned char);
extern "C" void func_020493dc(unsigned char*, unsigned char);
extern "C" void func_02049bd4(unsigned char*, int*);
struct Bytes02033b88;
extern "C" void GameObject_ForceMotionState(Bytes02033b88*, int);
struct Struct_02048c90;
extern "C" void func_02048c90(Struct_02048c90*);
extern "C" struct Struct_02048cf0 func_ov000_0216f74c(int* in);
struct Vector3i;

extern Struct_020e7b48 data_020e7b48;

// USA: func_02048cf0
extern "C" ARM void func_02048cf0(struct Struct_02048cf0_3* obj, int flag) {
    int cell = func_020493ec((unsigned char*)obj);
    if (cell == 0xff) {
        cell = func_020493c8((unsigned char*)obj);
    }
    if (cell == 0xff) {
        cell = func_020493a4((unsigned char*)obj);
    }
    if (flag != 0) {
        cell = func_020493a4((unsigned char*)obj);
    }
    if (cell != 0xff) {
        struct Struct_02048cf0 pos = func_ov000_0216f74c(&cell);
        struct Struct_020e7b48 fields = data_020e7b48;
        fields.v[0] = pos.x;
        fields.v[2] = pos.y;
        unsigned int var3 = obj->ptr->unknown_20_;
        func_02049bd4((unsigned char*)obj, fields.v);
        obj->ptr->unknown_20_ = var3;
        if (var3 & 0x21) {
            *(Vector3i*)obj->vec44 = *(Vector3i const*)fields.v;
        }
    }
    func_02049390((unsigned char*)obj, cell & 0xff);
    func_020493b8((unsigned char*)obj, 0xff);
    if (flag == 0) {
        func_020493dc((unsigned char*)obj, 0xff);
    }
    if (obj->unknown_be_ == 0) {
        GameObject_ForceMotionState((Bytes02033b88*)obj, 0);
        ((Object3D*)obj)->IsTransitioningAnimations();
    }
    ((Object3D*)obj)->SetAnimationPlaybackSpeed(0x1000, 0);
    func_02048c90((Struct_02048c90*)obj);
}
