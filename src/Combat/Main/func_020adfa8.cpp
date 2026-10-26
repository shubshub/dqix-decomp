#include <globaldefs.h>
#include "NitroSDK/Matrix.h"

short fix32cos(int x);
short fix32sin(int x);

struct Struct_020acecc_7;
extern "C" void func_020ad1f0(struct Struct_020acecc_7* obj, int x, int y, int z);

void Vector3fixMultiplyScalar(Vector3i const*, int, Vector3i*);

struct Struct_020adfa8 {
    char pad0[0x44];
    Vector3i unknown_44_;
    char unknown_50_[0xae - 0x50];
    short unknown_ae_;
    char unknown_b0_[0x164 - 0xb0];
    Vector3i unknown_164_;
    int unknown_170_;
    Vector3i unknown_174_;
    int unknown_180_;
};

// USA: func_020adfa8
extern "C" ARM void func_020adfa8(Struct_020adfa8* obj) {
    Vector3i v = obj->unknown_44_;
    int angle = obj->unknown_ae_;
    Vector3i dir;
    int var3 = fix32cos(angle);
    dir.x = fix32sin(angle);
    dir.y = 0;
    dir.z = var3;
    Vector3fix_Normalize(&dir, &dir);
    Vector3i var4;
    func_020ad1f0((struct Struct_020acecc_7*)&var4, -dir.x, -dir.y, -dir.z);
    Vector3i var5;
    Vector3fixMultiplyScalar(&var4, 0x1ccc, &var5);
    Vector3i var6;
    Vector3fix_Add(&v, &var5, &var6);
    obj->unknown_164_ = var6;
    Vector3i var7;
    Vector3fix_Add(&var6, &var5, &var7);
    obj->unknown_174_ = var7;
    obj->unknown_170_ = angle;
    obj->unknown_180_ = angle;
}
