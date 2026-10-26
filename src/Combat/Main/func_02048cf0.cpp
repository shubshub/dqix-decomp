#include <globaldefs.h>
#include "World/Object3D.h"

struct Struct_02048cf0_3;

struct Struct_02048cf0 { int unknown_0_; int unknown_4_; };
struct Struct_020e7b48 { int unknown_0_[3]; };

struct Struct_02048cf0_2 {
    char unknown_0_[0x20];
    unsigned int unknown_20_;
};

struct Struct_02048cf0_3 {
    char unknown_0_[0x44];
    int unknown_44_[3];
    char unknown_50_[0x6e];
    unsigned char unknown_be_;
    char unknown_bf_[0x7d];
    Struct_02048cf0_2* unknown_13c_;
};

int GetSubstructByte0x1e_020493ec(unsigned char*);
int GetSubstructByte0x1d_020493c8(unsigned char*);
int GetSubstructByte0x1c_020493a4(unsigned char*);
void SetSubstructByte0x1c_02049390(unsigned char*, unsigned char);
void SetSubstructByte0x1d_020493b8(unsigned char*, unsigned char);
void SetSubstructByte0x1e_020493dc(unsigned char*, unsigned char);
void SetSubstructFields0x10And0x18ClearFlag0x1_02049bd4(unsigned char*, int*);
struct Bytes02033b88;
void GameObject_ForceMotionState(Bytes02033b88*, int);
struct Obj02048c90;
void ResetInnerState02048c90(Obj02048c90*);
extern "C" struct Vec2_0216f74c func_ov000_0216f74c(int* in);
struct Vector3i;

extern Struct_020e7b48 data_020e7b48;

// USA: func_02048cf0
extern "C" ARM void func_02048cf0(struct Struct_02048cf0_3* arg0, int arg1) {
    int var0 = func_020493ec((unsigned char*)arg0);
    if (var0 == 0xff) {
        var0 = func_020493c8((unsigned char*)arg0);
    }
    if (var0 == 0xff) {
        var0 = func_020493a4((unsigned char*)arg0);
    }
    if (arg1 != 0) {
        var0 = func_020493a4((unsigned char*)arg0);
    }
    if (var0 != 0xff) {
        struct Struct_02048cf0 var1 = func_ov000_0216f74c(&var0);
        struct Struct_020e7b48 var2 = data_020e7b48;
        var2.unknown_0_[0] = var1.unknown_0_;
        var2.unknown_0_[2] = var1.unknown_4_;
        unsigned int var3 = arg0->unknown_13c_->unknown_20_;
        func_02049bd4((unsigned char*)arg0, var2.unknown_0_);
        arg0->unknown_13c_->unknown_20_ = var3;
        if (var3 & 0x21) {
            *(Vector3i*)arg0->unknown_44_ = *(Vector3i const*)var2.unknown_0_;
        }
    }
    func_02049390((unsigned char*)arg0, var0 & 0xff);
    func_020493b8((unsigned char*)arg0, 0xff);
    if (arg1 == 0) {
        func_020493dc((unsigned char*)arg0, 0xff);
    }
    if (obj->b_be == 0) {
        GameObject_ForceMotionState((Bytes02033b88*)obj, 0);
        ((Object3D*)obj)->IsTransitioningAnimations();
    }
    ((Object3D*)arg0)->SetAnimationPlaybackSpeed(0x1000, 0);
    func_02048c90((Struct_02048c90*)arg0);
}
