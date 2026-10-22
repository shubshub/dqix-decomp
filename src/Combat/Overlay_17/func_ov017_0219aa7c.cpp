#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Input/Input.h"

struct Vec3_020406f8 { int x, y, z; };
struct Vec3copy0202ec84 { int x, y, z; };
struct Node020406f8;
struct S02040538;

struct EntryList_203dce4;
struct Vec3Target0203a46c;
struct ChainRoot;
struct LookupBase;
struct InteractionSelection { unsigned char kind, index; unsigned short id; };
#if defined(jpn)
#define data_ov017_021d64f4 data_ov017_021d6944
#endif
typedef void (GameResources::*FocusAction0219aa7c)();
struct FocusActions0219aa7c { FocusAction0219aa7c entries[15]; };
extern const FocusActions0219aa7c data_ov017_021d64f4;
extern const FocusAction0219aa7c __ptmf_null;
void* GetField0x3b0Value_020100bc(GameState*);
int CheckSubstructByte0x7cPositive_020535c8(signed char*);
EntryList_203dce4* GetGlobalPtr021075f4_0203cf4c();
Node020406f8* GetEntryUnlessFlag0x8000_0203dce4(EntryList_203dce4*, int);
void SelectVec3FromSources020406f8(Vec3_020406f8*, Node020406f8*);
void* GetField0xc02040538(S02040538*);
void ComputeTwoFromVec3_0202ec84(void*, Vec3copy0202ec84*, int*, int*);
void SetVec3At0x1c(Vec3Target0203a46c*, int, int, int);
int IsField0Null_02046b08(void**);
int GetChainedTableByte_020479fc(ChainRoot*);
unsigned char GetLinkedFlagByte_020479b8(LookupBase*);
extern "C" void __clear(void*, unsigned int);

// USA: func_ov017_0219aa7c
extern "C" ARM void func_ov017_0219aa7c(GameResources* self) {
    GameState* game = GameState::GetInstance();
    void* camera = GetField0x3b0Value_020100bc(game);
    GameObject* object = game->GetUnknownGameObject();
    if (object == 0 || CheckSubstructByte0x7cPositive_020535c8((signed char*)object) || ((InteractionSelection*)self->interactionSelection)->index == 18) return;
    Foo02048004* sprite = &self->substruct_array_2b90[((InteractionSelection*)self->interactionSelection)->index];
    Vector3fix position;
    __clear(&position, 12);
    int x = 0;
    int y = 0;
    self->unknown_42e3[3] = 0;
    int fallback = 1;
    if (((InteractionSelection*)self->interactionSelection)->kind == 0) {
        Node020406f8* node = GetEntryUnlessFlag0x8000_0203dce4(GetGlobalPtr021075f4_0203cf4c(), ((InteractionSelection*)self->interactionSelection)->id);
        if (node != 0) {
            Vec3_020406f8 source;
            SelectVec3FromSources020406f8(&source, node);
            position = *(Vector3fix*)&source;
            position.y += 0x1800;
            void* height = GetField0xc02040538((S02040538*)node);
            if (height != 0) position.y += *reinterpret_cast<int*>(static_cast<char*>(height) + 0x60);
            fallback = 0;
        }
    } else if (((InteractionSelection*)self->interactionSelection)->kind == 10 || ((InteractionSelection*)self->interactionSelection)->kind == 13) {
        GameObject* member = game->GetPartyMemberByIndex(((InteractionSelection*)self->interactionSelection)->id);
        if (member != 0) {
            position = member->obj3D_.position_;
            position.y += 0x1800;
            fallback = 0;
        }
    } else if (((InteractionSelection*)self->interactionSelection)->kind == 9) {
        GameObject* member = game->GetMaybeFieldMonsterByIndex(((InteractionSelection*)self->interactionSelection)->id);
        if (member != 0) {
            position = member->obj3D_.position_;
            position.y += member->obj3D_.GetHeight();
            fallback = 0;
        }
    }
    if (fallback) {
        position = object->obj3D_.position_;
        position.y += object->obj3D_.GetHeight();
    }
    ComputeTwoFromVec3_0202ec84(camera, (Vec3copy0202ec84*)&position, &x, &y);
    x -= 12;
    y -= 24;
    SetVec3At0x1c((Vec3Target0203a46c*)sprite, x << 12, y << 12, 0);
    if (!IsField0Null_02046b08(static_cast<void**>(self->unknown_ptr_array_36fc[0]))) return;
    int dispatch = 0;
    if (g_touchInput.released_ && (unsigned int)g_touchInput.prevTimeHeld_ < 10) {
        int width = GetChainedTableByte_020479fc((ChainRoot*)sprite);
        int height = GetLinkedFlagByte_020479b8((LookupBase*)sprite);
        int limit_x = g_touchInput.prevX_;
        int limit_y = g_touchInput.prevY_;
        if (x < limit_x && y < limit_y && limit_x < x + width && limit_y < y + height) dispatch = 1;
    }
    if (g_keyManager.TestKeysPressed(1)) dispatch = 1;
    if (dispatch) {
        FocusActions0219aa7c actions = data_ov017_021d64f4;
        actions.entries[3] = __ptmf_null;
        if (actions.entries[((InteractionSelection*)self->interactionSelection)->kind] != 0) {
            (self->*actions.entries[((InteractionSelection*)self->interactionSelection)->kind])();
            self->unknown_42e3[1] = 0;
        }
    }
}
