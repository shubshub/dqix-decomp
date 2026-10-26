#include <globaldefs.h>
#include "GameState/GameState.h"

struct HeightShiftedObject : Object3D {
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
extern "C" void func_0203db34(unsigned char*, int, int, int);
extern "C" void func_020ae20c(void*, Fields020407b4*, int*, int);

// USA: func_020ae074
extern "C" ARM void func_020ae074(HeightShiftedObject* self) {
    GameState* game = GameState::GetInstance();
    Vector3fix position = self->position_;
    position.y += self->unknown_150_;
    self->position_ = position;
    GameObject_Draw(self, 1, 0);
    GameObject* object = game->GetGameObjectByIndex(0xcb);
    if (object) {
        self->unknown_164_.y += self->unknown_150_;
        object->obj3D_.position_ = self->unknown_164_;
        func_0203db34((unsigned char*)object, 0, self->unknown_170_, 0);
        object->obj3D_.Draw(true);
        self->unknown_164_.y -= self->unknown_150_;
        self->unknown_174_.y += self->unknown_150_;
        object->obj3D_.position_ = self->unknown_174_;
        func_0203db34((unsigned char*)object, 0, self->unknown_180_, 0);
        object->obj3D_.Draw(true);
        self->unknown_174_.y -= self->unknown_150_;
    }
    GameObject* var3 = game->GetGameObjectByIndex(0xcc);
    Vector3fix var4 = self->position_;
    func_020ae20c(self, (Fields020407b4*)var3, &var4.x, self->unknown_ae_);
    GameObject* var5 = game->GetGameObjectByIndex(0xcd);
    func_020ae20c(self, (Fields020407b4*)var5, &self->unknown_164_.x, self->unknown_170_);
    func_020ae20c(self, (Fields020407b4*)var5, &self->unknown_174_.x, self->unknown_180_);
    position = self->position_;
    position.y -= self->unknown_150_;
    self->position_ = position;
}
