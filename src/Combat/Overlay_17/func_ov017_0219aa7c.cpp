#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Input/Input.h"

struct Struct_0203de84 { int x, y, z; };
struct Vec3copy0202ec84 { int x, y, z; };
struct Node020406f8;
struct Struct_0203e0a0;

struct Struct_0203dce4_2;
struct Vec3Target0203a46c;
struct Struct_020479fc;
struct Struct_020479b8_3;
#if defined(jpn)
#define data_ov017_021d64f4 data_ov017_021d6944
#endif
typedef void (GameResources::*Type_02000c9c_15)();
struct Struct_ov017_021d64f4 { Type_02000c9c_15 entries[15]; };
extern const Struct_ov017_021d64f4 data_ov017_021d64f4;
extern const Type_02000c9c_15 __ptmf_null;
extern "C" int GameObject_IsGesturing(signed char*);
extern "C" Struct_0203dce4_2* func_0203cf4c();
extern "C" Node020406f8* func_0203dce4(Struct_0203dce4_2*, int);
extern "C" void func_020406f8(Struct_0203de84*, Node020406f8*);
extern "C" void* func_02040538(Struct_0203e0a0*);
extern "C" void Camera_WorldToScreen(void*, Vec3copy0202ec84*, int*, int*);
extern "C" void SprSprite_SetPosition(Vec3Target0203a46c*, int, int, int);
extern "C" int FieldTaskQueue_IsEmpty(void**);
extern "C" int func_020479fc(Struct_020479fc*);
extern "C" unsigned char func_020479b8(Struct_020479b8_3*);
extern "C" void __clear(void*, unsigned int);

// USA: func_ov017_0219aa7c
extern "C" ARM void func_ov017_0219aa7c(GameResources* self) {
    GameState* game = GameState::GetInstance();
    void* camera = game->GetCamera();
    GameObject* object = game->GetLeader();
    if (object == 0 || GameObject_IsGesturing((signed char*)object) || self->interactionSelection.spriteIndex == 18) return;
    Foo02048004* sprite = &self->substruct_array_2b90[self->interactionSelection.spriteIndex];
    Vector3fix position;
    __clear(&position, 12);
    int x = 0;
    int y = 0;
    self->unknown_42e3[3] = 0;
    int var7 = 1;
    if (self->interactionSelection.kind == 0) {
        Node020406f8* node = func_0203dce4(func_0203cf4c(), self->interactionSelection.targetIndex);
        if (node != 0) {
            Struct_0203de84 source;
            func_020406f8(&source, node);
            position = *(Vector3fix*)&source;
            position.y += 0x1800;
            void* height = func_02040538((Struct_0203e0a0*)node);
            if (height != 0) position.y += *reinterpret_cast<int*>(static_cast<char*>(height) + 0x60);
            var7 = 0;
        }
    } else if (self->interactionSelection.kind == 10 || self->interactionSelection.kind == 13) {
        GameObject* member = game->GetPartyMemberByIndex(self->interactionSelection.targetIndex);
        if (member != 0) {
            position = member->obj3D_.position_;
            position.y += 0x1800;
            var7 = 0;
        }
    } else if (self->interactionSelection.kind == 9) {
        GameObject* member = game->GetFieldMonsterByIndex(self->interactionSelection.targetIndex);
        if (member != 0) {
            position = member->obj3D_.position_;
            position.y += member->obj3D_.GetHeight();
            var7 = 0;
        }
    }
    if (var7) {
        position = object->obj3D_.position_;
        position.y += object->obj3D_.GetHeight();
    }
    Camera_WorldToScreen(camera, (Vec3copy0202ec84*)&position, &x, &y);
    x -= 12;
    y -= 24;
    SprSprite_SetPosition((Vec3Target0203a46c*)sprite, x << 12, y << 12, 0);
    if (!FieldTaskQueue_IsEmpty((void**)self->fieldTaskQueue_)) return;
    int dispatch = 0;
    if (g_touchInput.released_ && (unsigned int)g_touchInput.prevTimeHeld_ < 10) {
        int width = func_020479fc((Struct_020479fc*)sprite);
        int height = func_020479b8((Struct_020479b8_3*)sprite);
        int var16 = g_touchInput.prevX_;
        int var17 = g_touchInput.prevY_;
        if (x < var16 && y < var17 && var16 < x + width && var17 < y + height) dispatch = 1;
    }
    if (g_keyManager.TestKeysPressed(1)) dispatch = 1;
    if (dispatch) {
        Struct_ov017_021d64f4 actions = data_ov017_021d64f4;
        actions.entries[3] = __ptmf_null;
        if (actions.entries[self->interactionSelection.kind] != 0) {
            (self->*actions.entries[self->interactionSelection.kind])();
            self->unknown_42e3[1] = 0;
        }
    }
}
