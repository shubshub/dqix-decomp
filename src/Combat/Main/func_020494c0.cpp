#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void GameObject_FaceGameObject(void* obj, int value, int arg2);

struct Struct_020494c0 {
    char pad[0x4c];
    unsigned char unknown_4c_;
    unsigned char unknown_4d_;
};

struct Struct_02048f64_2 {
    char pad[0x13c];
    struct Struct_020494c0* unknown_13c_;
};

// USA: func_020494c0
extern "C" ARM void func_020494c0(struct Struct_02048f64_2* obj) {
    struct Struct_020494c0* p;
    unsigned char v;
    if (obj->unknown_13c_ == NULL) return;
    GameState::GetInstance();
    p = obj->unknown_13c_;
    v = p->unknown_4c_;
    if (v == 0xff) v = p->unknown_4d_;
    GameObject_FaceGameObject(obj, v, 0);
}
