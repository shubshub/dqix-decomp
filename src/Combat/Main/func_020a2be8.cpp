#include <globaldefs.h>
#include "GameState/GameState.h"

struct Vec3 { int x, y, z; };
struct Vector3i;
extern "C" void __clear(void* ptr, int size);

struct Struct_020a2be8 { char unk[0x68]; int field; };

struct Struct_020a2be8_2 {
    char pad0[0x10];
    struct Vec3 unknown_10_;
    char pad1[0x21c - 0x1c];
    short unknown_21c_;
    char pad2[0x22c - 0x21e];
    struct Vec3 unknown_22c_;
    char pad3[0x245 - 0x238];
    unsigned char unknown_245_;
};

// USA: func_020a2be8
extern "C" ARM void func_020a2be8(struct Struct_020a2be8_2* obj) {
    GameState* battle = GameState::GetInstance();
    struct Vec3 v;
    __clear(&v, 0xc);
    GameObject* c = battle->GetGameObjectByIndex(obj->unknown_21c_);
    if (c != 0) {
        *(Vector3i*)((int*)&v) = *(Vector3i const*)(&c->obj3D_.position_.x);
        int val = ((Object3D*)((struct Struct_020a2be8*)c))->GetHeight();
        v.y = v.y + (val >> 1);
    }
    struct Vec3 diff;
    Vector3fix_Subtract((const Vector3fix*)&obj->unknown_10_, (const Vector3fix*)&v, (Vector3fix*)&diff);
    *(Vector3i*)((int*)&obj->unknown_22c_) = *(Vector3i const*)((int*)&diff);
    obj->unknown_245_ |= 0x11;
}
