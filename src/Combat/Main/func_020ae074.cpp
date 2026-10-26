#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_020ae074 : Object3D {
    short unknown_ac_, unknown_ae_;
    char unknown_b0_[0x150 - 0xb0];
    int unknown_150_;
    char unknown_154_[0x164 - 0x154];
    Vector3fix unknown_164_;
    int unknown_170_;
    Vector3fix unknown_174_;
    int unknown_180_;
};
struct Fields020407b4;
extern "C" void GameObject_Draw(HeightShiftedObject*, int, int);
void StoreVec3AtField0x50_0203db34(unsigned char*, int, int, int);
void SetupObjFieldsAndResetRenderFlags020ae20c(void*, Fields020407b4*, int*, int);

// USA: func_020ae074
extern "C" ARM void func_020ae074(HeightShiftedObject* self) {
    GameState* game = GameState::GetInstance();
    Vector3fix position = self->position_;
    position.y += self->heightOffset_;
    self->position_ = position;
    GameObject_Draw(self, 1, 0);
    GameObject* object = game->GetGameObjectByIndex(0xcb);
    if (object) {
        self->firstPosition_.y += self->heightOffset_;
        object->obj3D_.position_ = self->firstPosition_;
        StoreVec3AtField0x50_0203db34((unsigned char*)object, 0, self->firstHeading_, 0);
        object->obj3D_.Draw(true);
        self->firstPosition_.y -= self->heightOffset_;
        self->secondPosition_.y += self->heightOffset_;
        object->obj3D_.position_ = self->secondPosition_;
        StoreVec3AtField0x50_0203db34((unsigned char*)object, 0, self->secondHeading_, 0);
        object->obj3D_.Draw(true);
        self->secondPosition_.y -= self->heightOffset_;
    }
    GameObject* var3 = var0->GetGameObjectByIndex(0xcc);
    Vector3fix var4 = arg0->position_;
    func_020ae20c(arg0, (Struct_02040774_2*)var3, &var4.x, arg0->unknown_ae_);
    GameObject* var5 = var0->GetGameObjectByIndex(0xcd);
    func_020ae20c(arg0, (Struct_02040774_2*)var5, &arg0->unknown_164_.x, arg0->unknown_170_);
    func_020ae20c(arg0, (Struct_02040774_2*)var5, &arg0->unknown_174_.x, arg0->unknown_180_);
    var1 = arg0->position_;
    var1.y -= arg0->unknown_150_;
    arg0->position_ = var1;
}
