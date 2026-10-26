#include <globaldefs.h>
#include "GameState/GameState.h"
#include "NitroSDK/Matrix.h"

extern "C" void func_ov000_0216d370(void* arg0, int arg1, int arg2, int arg3);

struct Block0202ecc8 { unsigned int v[12]; };
struct Dst0202ecc8;
void CopyBlockToField0xf0(struct Dst0202ecc8* dst, struct Block0202ecc8* src);
void Camera_SetOrbitVector(void* obj, int* vec);

extern "C" void func_ov000_0216d234(void* arg0, void* arg1, void* arg2);

extern Vector3i data_ov000_0218328c;

struct Struct_ov000_0216de00 {
    char unknown_0_[0x10];
    Vector3i unknown_10_;
};

// USA: func_ov000_0216de00
extern "C" ARM void func_ov000_0216de00(struct Struct_ov000_0216de00* arg0, int arg1, int arg2) {
    GameState* var0 = GameState::GetInstance();
    GameObject* var1 = var0->GetGameObjectByIndex(arg1);
    GameObject* var2 = var0->GetGameObjectByIndex(arg2);
    if (var1 == NULL || var2 == NULL) {
        return;
    }
    func_ov000_0216d370(obj, 1, 1, 1);
    Vector3fix posA = a->obj3D_.position_;
    Vector3fix posB = b->obj3D_.position_;
    Vector3fix dir;
    Vector3fix_Subtract(&posA, &posB, &dir);
    Vector3fix_Normalize(&dir, &dir);
    struct Block0202ecc8 block;
    func_ov000_0216d234(&dir, &posB, &block);
    CopyBlockToField0xf0((struct Dst0202ecc8*)obj, &block);
    Vector3i v = data_ov000_0218328c;
    int tail[3];
    tail[0] = 0x3244;
    tail[1] = 0;
    tail[2] = 0x1000;
    obj->field10 = v;
    Camera_SetOrbitVector(obj, tail);
}
