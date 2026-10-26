#include <globaldefs.h>
#include "Combat/LootPointEvent.h"
#include "Combat/LootPickupEvent.h"
#include "GameState/GameState.h"
#include "World/Zone3D.h"
#include "Input/Input.h"



struct Struct_ov017_021986fc_2 {
    unsigned int unk0 : 16;
    unsigned int id : 7;
    unsigned int unknown_2_7_ : 9;
    unsigned int unknown_4_0_ : 17;
    unsigned int count : 4;
    unsigned int mask : 8;
    unsigned int unknown_7_5_ : 3;
    Struct_0208ec78* entry;
    Vector3fix pos[8];
    struct Struct_ov017_021986fc_2* next;
};

struct Obj0208e7d0 {
    char pad0[4];
    struct Struct_ov017_021986fc_2* head;
};

struct Struct_ov017_021986fc_3 {
    unsigned char kind;
    unsigned char padding1[19];
};

struct TailList020469b4;
struct TailNode020469b4;
struct Vec3copy0202ec84;
struct Struct_0208f3b4;
struct SearchStruct0202c1a4;

extern "C" Zone3D* Zone3D_GetInstance(void);
extern "C" Obj0208e7d0* LootPointList_GetInstance(void);
extern "C" int LootPointList_AppliesToMap(void*, char*);
extern "C" int GameObject_IsGesturing(signed char*);
extern "C" Struct_0208f3b4* func_0208e9e8(void);
extern "C" void func_ov017_0219a674(unsigned char*);
extern "C" void func_ov017_0219b33c(void*, Struct_ov017_021986fc_3*);
extern "C" int Camera_WorldToScreen(void*, Vec3copy0202ec84*, int*, int*);
extern "C" SearchStruct0202c1a4* LinkSession_GetInstance(void);
extern "C" int LinkSession_GetOwnSlot(SearchStruct0202c1a4*);
extern "C" void* Scenario_GetInstance(void);
extern "C" void Scenario_SetFlag(void*, unsigned char*, int, int);
extern "C" void func_0208f3b4(Struct_0208f3b4*, int);
extern "C" int func_0208e7d0(Obj0208e7d0*);
extern "C" void func_020469b4(TailList020469b4*, TailNode020469b4*);

// USA: func_ov017_021986fc
extern "C" ARM void func_ov017_021986fc(GameResources* self) {
    Zone3D* zone = Zone3D_GetInstance();
    Zone3D_StructPtr_8* info = zone->pUnknownStruct_8_;
    Obj0208e7d0* list = LootPointList_GetInstance();
    if (!LootPointList_AppliesToMap(list, info->mapShortName_)) return;
    GameState* gs = GameState::GetInstance();
    GameObject* actor = gs->GetLeader();
    if (GameObject_IsGesturing((signed char*)actor)) return;
    func_0208e9e8();
    Struct_ov017_021986fc_2* node = list->head;
    void* camera = gs->GetCamera();

    int found = 0;
    unsigned int mask = 0;
    unsigned char idx = 0;
    unsigned char key = 0;
    for (; node != NULL; node = node->next, idx++) {
        if (node->entry != NULL) {
            for (unsigned int i = 0; i < node->count; i++) {
                unsigned int bit = 1 << i;
                if ((node->mask & bit) == 0) continue;
                if (node->pos[i].x - 2867 >= actor->obj3D_.position_.x) continue;
                if (node->pos[i].x + 2867 <= actor->obj3D_.position_.x) continue;
                if (node->pos[i].z - 2867 >= actor->obj3D_.position_.z) continue;
                if (node->pos[i].z + 2867 <= actor->obj3D_.position_.z) continue;
                key = i + idx * 8;
                found = 1;
                mask = bit;
                Struct_ov017_021986fc_3 event;
                func_ov017_0219a674((unsigned char*)&event);
                event.kind = 3;
                func_ov017_0219b33c(self, &event);
                break;
            }
            if (found) break;
        }
    }
    if (!found) return;

    int var14 = 0;
    if (g_keyManager.TestKeysPressed(1)) var14 = 1;
    int cursorX = -1;
    int cursorY = -1;
    if (g_touchInput.released_ && (unsigned int)g_touchInput.prevTimeHeld_ < 10) { cursorX = g_touchInput.prevX_; cursorY = g_touchInput.prevY_; }
    int screenX, screenY;
    Camera_WorldToScreen(camera, (Vec3copy0202ec84*)&actor->obj3D_.position_, &screenX, &screenY);
    if (cursorX > 0x70 && cursorX < 0x90 && cursorY > 0x28 && cursorY < 0x60) var14 = 1;
    else if (screenX - 12 < cursorX && cursorX < screenX + 12 && screenY - 12 < cursorY && cursorY < screenY + 12) var14 = 1;
    if (!var14) return;

    func_ov017_021d38f8(1, LinkSession_GetOwnSlot(LinkSession_GetInstance()), mask, node->id, node->entry);
    node->entry->fields.flags = ~mask & node->entry->fields.flags;
    node->mask = ~mask & node->mask;
    node->entry->fields.timer = node->entry->fields.count * 30;
    void* base = Scenario_GetInstance();
    Scenario_SetFlag(base, (unsigned char*)base + 0x8c, node->id + 0xc12, 1);
    func_0208f3b4(func_0208e9e8(), key);
    if (node->id >= 0x62) node->unk0 = func_0208e7d0(list);
    func_ov017_021ae800(((Obj021ae800*)self->fieldTasks_[11]));
    ((Obj021ae800*)self->fieldTasks_[11])->itemId = node->unk0;
    ((Obj021ae800*)self->fieldTasks_[11])->position = actor->obj3D_.position_;
    ((Obj021ae800*)self->fieldTasks_[11])->angle = 0;
    ((Obj021ae800*)self->fieldTasks_[11])->fade = 0x1f;
    func_020469b4((TailList020469b4*)self->fieldTaskQueue_, (TailNode020469b4*)((Obj021ae800*)self->fieldTasks_[11]));
}
