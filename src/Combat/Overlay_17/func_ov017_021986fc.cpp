#include <globaldefs.h>
#include "Combat/LootPointEvent.h"
#include "Combat/LootPickupEvent.h"
#include "GameState/GameState.h"
#include "World/Zone3D.h"
#include "Input/Input.h"



struct Struct_ov017_021986fc_2 {
    unsigned int unknown_0_0_ : 16;
    unsigned int unknown_2_0_ : 7;
    unsigned int unknown_2_7_ : 9;
    unsigned int unknown_4_0_ : 17;
    unsigned int unknown_6_1_ : 4;
    unsigned int unknown_6_5_ : 8;
    unsigned int unknown_7_5_ : 3;
    Struct_0208ec78* unknown_8_;
    Vector3fix unknown_c_[8];
    struct Struct_ov017_021986fc_2* unknown_6c_;
};

struct Struct_0208e7d0 {
    char unknown_0_[4];
    struct Struct_ov017_021986fc_2* unknown_4_;
};

struct Struct_ov017_021986fc_3 {
    unsigned char unknown_0_;
    unsigned char unknown_1_[19];
};

struct Struct_0201bdac_2;
struct Struct_0201bdac;
struct Struct_02015ef4;
struct Struct_0208f3b4;
struct Struct_0202c1a4;

extern "C" Zone3D* Zone3D_GetInstance(void);
extern "C" Obj0208e7d0* func_0208e0a8(void);
int LootPointList_AppliesToMap(void*, char*);
int CheckSubstructByte0x7cPositive_020535c8(signed char*);
Cont0208f3b4* GetData02109020_0208e9e8(void);
void InitObj0219a674(unsigned char*);
extern "C" void func_ov017_0219b33c(void*, Event021986fc*);
int Camera_WorldToScreen(void*, Vec3copy0202ec84*, int*, int*);
extern "C" SearchStruct0202c1a4* func_0202ae18(void);
int GetSearchStructCurrentArrEntry(SearchStruct0202c1a4*);
extern "C" void* Scenario_GetInstance(void);
extern "C" void Scenario_SetFlag(void*, unsigned char*, int, int);
void RemoveNodeByKey0208f3b4(Cont0208f3b4*, int);
int GetRandomTableEntry0208e7d0(Obj0208e7d0*);
void AppendNodeToTail(TailList020469b4*, TailNode020469b4*);

// USA: func_ov017_021986fc
extern "C" ARM void func_ov017_021986fc(GameResources* self) {
    Zone3D* zone = Zone3D_GetInstance();
    Zone3D_StructPtr_8* info = zone->pUnknownStruct_8_;
    Obj0208e7d0* list = func_0208e0a8();
    if (!LootPointList_AppliesToMap(list, info->mapShortName_)) return;
    GameState* gs = GameState::GetInstance();
    GameObject* actor = gs->GetUnknownGameObject();
    if (CheckSubstructByte0x7cPositive_020535c8((signed char*)actor)) return;
    GetData02109020_0208e9e8();
    Node021986fc* node = list->head;
    void* camera = gs->GetCamera();

    int var7 = 0;
    unsigned int var8 = 0;
    unsigned char var9 = 0;
    unsigned char var10 = 0;
    for (; var5 != NULL; var5 = var5->unknown_6c_, var9++) {
        if (var5->unknown_8_ != NULL) {
            for (unsigned int var11 = 0; var11 < var5->unknown_6_1_; var11++) {
                unsigned int var12 = 1 << var11;
                if ((var5->unknown_6_5_ & var12) == 0) continue;
                if (var5->unknown_c_[var11].x - 2867 >= var4->obj3D_.position_.x) continue;
                if (var5->unknown_c_[var11].x + 2867 <= var4->obj3D_.position_.x) continue;
                if (var5->unknown_c_[var11].z - 2867 >= var4->obj3D_.position_.z) continue;
                if (var5->unknown_c_[var11].z + 2867 <= var4->obj3D_.position_.z) continue;
                var10 = var11 + var9 * 8;
                var7 = 1;
                var8 = var12;
                Struct_ov017_021986fc_3 var13;
                func_ov017_0219a674((unsigned char*)&var13);
                var13.unknown_0_ = 3;
                func_ov017_0219b33c(arg0, &var13);
                break;
            }
            if (var7) break;
        }
    }
    if (!var7) return;

    int proceed = 0;
    if (g_keyManager.TestKeysPressed(1)) proceed = 1;
    int cursorX = -1;
    int cursorY = -1;
    if (g_touchInput.released_ && (unsigned int)g_touchInput.prevTimeHeld_ < 10) { cursorX = g_touchInput.prevX_; cursorY = g_touchInput.prevY_; }
    int screenX, screenY;
    Camera_WorldToScreen(camera, (Vec3copy0202ec84*)&actor->obj3D_.position_, &screenX, &screenY);
    if (cursorX > 0x70 && cursorX < 0x90 && cursorY > 0x28 && cursorY < 0x60) proceed = 1;
    else if (screenX - 12 < cursorX && cursorX < screenX + 12 && screenY - 12 < cursorY && cursorY < screenY + 12) proceed = 1;
    if (!proceed) return;

    EnqueueEventTag183_021d38f8(1, GetSearchStructCurrentArrEntry(func_0202ae18()), mask, node->id, node->entry);
    node->entry->fields.flags = ~mask & node->entry->fields.flags;
    node->mask = ~mask & node->mask;
    node->entry->fields.timer = node->entry->fields.count * 30;
    void* base = Scenario_GetInstance();
    Scenario_SetFlag(base, (unsigned char*)base + 0x8c, node->id + 0xc12, 1);
    RemoveNodeByKey0208f3b4(GetData02109020_0208e9e8(), key);
    if (node->id >= 0x62) node->unk0 = GetRandomTableEntry0208e7d0(list);
    ResetHeaderAndAllocator_021ae800(((Obj021ae800*)self->fieldTasks_[11]));
    ((Obj021ae800*)self->fieldTasks_[11])->itemId = node->unk0;
    ((Obj021ae800*)self->fieldTasks_[11])->position = actor->obj3D_.position_;
    ((Obj021ae800*)self->fieldTasks_[11])->angle = 0;
    ((Obj021ae800*)self->fieldTasks_[11])->fade = 0x1f;
    AppendNodeToTail((TailList020469b4*)self->fieldTaskQueue_, (TailNode020469b4*)((Obj021ae800*)self->fieldTasks_[11]));
}
