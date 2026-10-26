#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Input/Input.h"

struct Struct_0203de84 { int unknown_0_, unknown_4_, unknown_8_; };
struct Struct_02015ef4 { int unknown_0_, unknown_4_, unknown_8_; };
struct Struct_0203de84_2;
struct Struct_0203e0a0;

struct EntryList_203dce4;
struct Vec3Target0203a46c;
struct ChainRoot;
struct LookupBase;
#if defined(jpn)
#define data_ov017_021d64f4 data_ov017_021d6944
#endif
typedef void (GameResources::*FocusAction0219aa7c)();
struct FocusActions0219aa7c { FocusAction0219aa7c entries[15]; };
extern const FocusActions0219aa7c data_ov017_021d64f4;
extern const FocusAction0219aa7c __ptmf_null;
int GameObject_IsGesturing(signed char*);
EntryList_203dce4* GetGlobalPtr021075f4_0203cf4c();
Node020406f8* GetEntryUnlessFlag0x8000_0203dce4(EntryList_203dce4*, int);
void SelectVec3FromSources020406f8(Vec3_020406f8*, Node020406f8*);
void* GetField0xc02040538(S02040538*);
void Camera_WorldToScreen(void*, Vec3copy0202ec84*, int*, int*);
void SprSprite_SetPosition(Vec3Target0203a46c*, int, int, int);
int FieldTaskQueue_IsEmpty(void**);
int GetChainedTableByte_020479fc(ChainRoot*);
unsigned char GetLinkedFlagByte_020479b8(LookupBase*);
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
    int fallback = 1;
    if (self->interactionSelection.kind == 0) {
        Node020406f8* node = GetEntryUnlessFlag0x8000_0203dce4(GetGlobalPtr021075f4_0203cf4c(), self->interactionSelection.targetIndex);
        if (node != 0) {
            Vec3_020406f8 source;
            SelectVec3FromSources020406f8(&source, node);
            position = *(Vector3fix*)&source;
            position.y += 0x1800;
            void* height = GetField0xc02040538((S02040538*)node);
            if (height != 0) position.y += *reinterpret_cast<int*>(static_cast<char*>(height) + 0x60);
            fallback = 0;
        }
    } else if (self->interactionSelection.kind == 10 || self->interactionSelection.kind == 13) {
        GameObject* member = game->GetPartyMemberByIndex(self->interactionSelection.targetIndex);
        if (member != 0) {
            position = member->obj3D_.position_;
            position.y += 0x1800;
            fallback = 0;
        }
    } else if (self->interactionSelection.kind == 9) {
        GameObject* member = game->GetFieldMonsterByIndex(self->interactionSelection.targetIndex);
        if (member != 0) {
            position = member->obj3D_.position_;
            position.y += member->obj3D_.GetHeight();
            fallback = 0;
        }
    }
    if (var7) {
        var4 = var2->obj3D_.position_;
        var4.y += var2->obj3D_.GetHeight();
    }
    Camera_WorldToScreen(camera, (Vec3copy0202ec84*)&position, &x, &y);
    x -= 12;
    y -= 24;
    SprSprite_SetPosition((Vec3Target0203a46c*)sprite, x << 12, y << 12, 0);
    if (!FieldTaskQueue_IsEmpty((void**)self->fieldTaskQueue_)) return;
    int dispatch = 0;
    if (g_touchInput.released_ && (unsigned int)g_touchInput.prevTimeHeld_ < 10) {
        int var14 = func_020479fc((Struct_020479fc*)var3);
        int var15 = func_020479b8((Struct_020479b8_3*)var3);
        int var16 = g_touchInput.prevX_;
        int var17 = g_touchInput.prevY_;
        if (var5 < var16 && var6 < var17 && var16 < var5 + var14 && var17 < var6 + var15) var13 = 1;
    }
    if (g_keyManager.TestKeysPressed(1)) dispatch = 1;
    if (dispatch) {
        FocusActions0219aa7c actions = data_ov017_021d64f4;
        actions.entries[3] = __ptmf_null;
        if (actions.entries[self->interactionSelection.kind] != 0) {
            (self->*actions.entries[self->interactionSelection.kind])();
            self->unknown_42e3[1] = 0;
        }
    }
}
