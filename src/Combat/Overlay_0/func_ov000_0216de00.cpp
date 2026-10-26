#include <globaldefs.h>
#include "GameState/GameState.h"
#include "NitroSDK/Matrix.h"

extern "C" void func_ov000_0216d370(void* obj, int flagA, int arg2, int flagC);

struct Struct_0202ecc8 { unsigned int v[12]; };
struct Struct_0202ecc8_2;
extern "C" void func_0202ecc8(struct Struct_0202ecc8_2* dst, struct Struct_0202ecc8* src);
extern "C" void Camera_SetOrbitVector(void* obj, int* vec);

extern "C" void func_ov000_0216d234(void* forward, void* position, void* dest);

extern Vector3i data_ov000_0218328c;

struct Struct_ov000_0216de00 {
    char pad0[0x10];
    Vector3i field10;
};

// USA: func_ov000_0216de00
extern "C" ARM void func_ov000_0216de00(struct Struct_ov000_0216de00* obj, int arg1, int arg2) {
    GameState* gs = GameState::GetInstance();
    GameObject* a = gs->GetGameObjectByIndex(arg1);
    GameObject* b = gs->GetGameObjectByIndex(arg2);
    if (a == NULL || b == NULL) {
        return;
    }
    func_ov000_0216d370(obj, 1, 1, 1);
    Vector3fix var3 = a->obj3D_.position_;
    Vector3fix var4 = b->obj3D_.position_;
    Vector3fix dir;
    Vector3fix_Subtract(&var3, &var4, &dir);
    Vector3fix_Normalize(&dir, &dir);
    struct Struct_0202ecc8 block;
    func_ov000_0216d234(&dir, &var4, &block);
    func_0202ecc8((struct Struct_0202ecc8_2*)obj, &block);
    Vector3i v = data_ov000_0218328c;
    int tail[3];
    tail[0] = 0x3244;
    tail[1] = 0;
    tail[2] = 0x1000;
    obj->field10 = v;
    Camera_SetOrbitVector(obj, tail);
}
