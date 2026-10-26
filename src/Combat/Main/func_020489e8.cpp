#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" ARM void func_02048144(void* p);
struct Vector3i;

struct Struct_020489e8 {
    char unk0[0x41];
    unsigned char lo5 : 5;
    unsigned char unknown_41_5_ : 3;
};

struct Struct_020489e8_2 {
    unsigned short field0;
    unsigned short field2;
    float field4;
};

extern "C" void func_02048f64(void* obj);
extern "C" void func_0204956c(void* obj);

struct Struct_020489e8_3;
extern "C" void func_0204a054(struct Struct_020489e8_3* obj);

struct Struct_020489e8_4 {
    char pad0[0x10];
    int vec[3];
    char pad1[0x20 - 0x1c];
    int flags;
};

struct Struct_020489e8_5 {
    char pad0[0x44];
    int unknown_44_[3];
    char pad1[0x54 - 0x50];
    int unknown_54_;
    char pad2[0x13c - 0x58];
    struct Struct_020489e8_4* unknown_13c_;
};

// USA: func_020489e8
extern "C" ARM void func_020489e8(struct Struct_020489e8_5* obj) {
    func_02048144(obj);
    if (obj->unknown_13c_ == NULL) return;
    if (obj->unknown_13c_->flags & 1) {
        *(Vector3i*)obj->unknown_13c_->vec = *(Vector3i const*)obj->unknown_44_;
        obj->unknown_13c_->vec[1] = obj->unknown_54_;
    }
    int var0 = 0.0f != ((struct Struct_020489e8_2*)((char*)obj->unknown_13c_ + 0x60))->field4;
    if (var0) {
        GameState* battleStruct = GameState::GetInstance();
        int threshold = battleStruct->GetEffectiveDeltaTime();
        int bits = ((Object3D*)((struct Struct_020489e8*)obj))->GetOwnAlpha();
        ((AlphaTween*)(&((struct Struct_020489e8_2*)((char*)obj->unknown_13c_ + 0x60))->field0))->SetCurrentValue((float)bits);
        float result = ((AlphaTween*)((struct Struct_020489e8_2*)((char*)obj->unknown_13c_ + 0x60)))->Advance(threshold);
        unsigned char v = (unsigned char)(int)result;
        ((struct Struct_020489e8*)obj)->lo5 = v;
    }
    func_02048f64(obj);
    func_0204956c(obj);
    func_0204a054((struct Struct_020489e8_3*)obj);
}
