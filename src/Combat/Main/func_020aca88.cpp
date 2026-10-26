#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/FileIO.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "Resource/GameResources.h"
#include "World/Object3D.h"

typedef char Type_020aca88[0x70];

struct Struct_020aca88 {
    Object3D unknown_0_;
    char unknown_ac_[4];
    unsigned short unknown_b0_;
    char unknown_b2_[0xe0 - 0xb2];
    unsigned char unknown_e0_0_ : 1;
    unsigned char unknown_e0_1_ : 7;
    char unknown_e1_[0x154 - 0xe1];
    Vector3i unknown_154_;
    char unknown_160_[0x1b8 - 0x160];
};

struct Struct_ov017_021d82fc_3 {
    SafeAllocator* unknown_0_;
    char* unknown_4_;
    char unknown_8_[0x44 - 8];
};

struct Struct_0203d028_11;
struct Struct_0200ffd0;
struct Struct_02033834;
struct Struct_02033fdc;

void* GameState_GetStarflight(struct PointerField330_ffd0* obj);
void InitObj020ad59c(void* obj);
void ClearEightWords_0203dafc(struct Struct_203dafc* obj);
void VramState_Restore(char* tables);
void VramState_Save(char* tables);
extern "C" void Zone3D_GetInstance();
void GameObject_SnapFacing(struct Obj02033874* obj, int value);
void GameObject_ResumeMovement(struct Flags02033fdc* obj);
void RegisterCombatantSlot_0200fd38(GameState* state, int slot, GameObject* obj);
extern "C" void func_020adfa8(struct Prop020aca88* prop);
void ResetContainerAndHandleFields020da1ac(void* container);

extern const char data_020f1c08[];
extern const char data_020f1c20[];
extern const char data_020f1c38[];
extern const char data_020f1c51[];
extern const Vector3i data_020e910c;
extern const Vector3i data_020e9100;
extern struct Struct_ov017_021d82fc_3 data_ov017_021d82fc;

// USA: func_020aca88
extern "C" ARM void func_020aca88(GameResources* res, int message) {
    if (message == 0x2774) {
        GameState* state = GameState::GetInstance();
        BackgroundLoader* loader = BackgroundLoader::GetInstance();
        SafeAllocator* alloc = &res->allocator_array_38[7];
        char* tables = ((PairTable020aca88*)res->vramStates_)[7];
        GameState_GetStarflight((struct PointerField330_ffd0*)state);
        if (loader->GetNumQueuedTasks() > 0) {
            return;
        }

        unsigned int var4;
        ObjectArchiveLoadInfo var5;
        void* var6 = LoadFileIntoNewAllocation(data_020f1c08, *var2, &var4);
        if (var6 == NULL) {
            return;
        }
        struct Struct_020aca88* var7 = (struct Struct_020aca88*)var2->Allocate(0x1b8);
        if (var7 == NULL) {
            return;
        }
        InitObj020ad59c(prop);
        ClearEightWords_0203dafc((struct Struct_203dafc*)&info);
        VramState_Restore(tables);
        info.fileSize = size;
        info.fileData = file;
        info.allocator = alloc;
        prop->obj3D.LoadFromCHRArchive(&info);
        VramState_Save(tables);
        Zone3D_GetInstance();

        GameObject* hero = state->GetLeader();
        Vector3i pos = hero->obj3D_.position_;
        pos.y += 0xa000;
        Vector3i scale = data_020e910c;
        Vector3i rot = data_020e9100;
        prop->obj3D.rotation_ = rot;
        prop->obj3D.position_ = pos;
        prop->homePosition_154 = pos;
        prop->obj3D.SetScale(&scale);
        GameObject_SnapFacing((struct Obj02033874*)prop, 0x3244);
        prop->kind_b0 = 0xc9;
        prop->obj3D.MakeVisible();
        GameObject_ResumeMovement((struct Flags02033fdc*)prop);
        prop->hidden_e0 = 0;
        prop->obj3D.EnableFlag(0x80);
        RegisterCombatantSlot_0200fd38(state, 0xca, (GameObject*)prop);
        state->GetGameObjectByIndex(0xcb);

        var6 = LoadFileIntoNewAllocation(data_020f1c20, *var2, &var4);
        if (var6 == NULL) {
            return;
        }
        Object3D* var12 = (Object3D*)var2->Allocate(0xac);
        if (var12 == NULL) {
            return;
        }
        obj->Initialize();
        ClearEightWords_0203dafc((struct Struct_203dafc*)&info);
        VramState_Restore(tables);
        info.fileSize = size;
        info.fileData = file;
        info.allocator = alloc;
        obj->LoadFromCHRArchive(&info);
        VramState_Save(tables);
        obj->position_ = pos;
        obj->SetScale(&scale);
        obj->MakeVisible();
        obj->EnableFlag(0x180);
        RegisterCombatantSlot_0200fd38(state, 0xcb, (GameObject*)obj);
        state->GetGameObjectByIndex(0xcc);

        var6 = LoadFileIntoNewAllocation(data_020f1c38, *var2, &var4);
        if (var6 == NULL) {
            return;
        }
        var12 = (Object3D*)var2->Allocate(0xac);
        if (var12 == NULL) {
            return;
        }
        obj->Initialize();
        ClearEightWords_0203dafc((struct Struct_203dafc*)&info);
        VramState_Restore(tables);
        info.fileSize = size;
        info.fileData = file;
        info.allocator = alloc;
        obj->LoadFromCHRArchive(&info);
        VramState_Save(tables);
        pos = hero->obj3D_.position_;
        pos.y = 0;
        scale.y = 0x300;
        scale.x = scale.z = 0x96;
        obj->position_ = pos;
        obj->SetScale(&scale);
        obj->MakeVisible();
        obj->EnableFlag(0x180);
        RegisterCombatantSlot_0200fd38(state, 0xcc, (GameObject*)obj);
        state->GetGameObjectByIndex(0xcd);

        var6 = LoadFileIntoNewAllocation(data_020f1c51, *var2, &var4);
        if (var6 == NULL) {
            return;
        }
        var12 = (Object3D*)var2->Allocate(0xac);
        if (var12 == NULL) {
            return;
        }
        obj->Initialize();
        ClearEightWords_0203dafc((struct Struct_203dafc*)&info);
        VramState_Restore(tables);
        info.fileSize = size;
        info.fileData = file;
        info.allocator = alloc;
        obj->LoadFromCHRArchive(&info);
        VramState_Save(tables);
        pos = hero->obj3D_.position_;
        pos.y = 0;
        scale.y = 0x300;
        scale.x = scale.z = 0x96;
        obj->position_ = pos;
        obj->SetScale(&scale);
        obj->MakeVisible();
        obj->EnableFlag(0x180);
        RegisterCombatantSlot_0200fd38(state, 0xcd, (GameObject*)obj);

        func_020adfa8(var7);
        SafeAllocator* var13 = (SafeAllocator*)var2->Allocate(0x14);
        var13->ResetAllocatorPointer();
        var13->CreateTypeA(var2->Allocate(0x3c00), 0x3c00);
        func_020da1ac(&data_ov017_021d82fc);
        data_ov017_021d82fc.unknown_0_ = var13;
        data_ov017_021d82fc.unknown_4_ = var3;
    }
}
