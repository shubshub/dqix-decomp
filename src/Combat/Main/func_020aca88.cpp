#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/FileIO.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "Resource/GameResources.h"
#include "World/Object3D.h"

typedef char PairTable020aca88[0x70];

struct Struct_020aca88 {
    Object3D obj3D;
    char unk_ac[4];
    unsigned short unknown_b0_;
    char unknown_b2_[0xe0 - 0xb2];
    unsigned char unknown_e0_0_ : 1;
    unsigned char unknown_e0_1_ : 7;
    char unknown_e1_[0x154 - 0xe1];
    Vector3i unknown_154_;
    char unknown_160_[0x1b8 - 0x160];
};

struct Struct_ov017_021d82fc_3 {
    SafeAllocator* allocator;
    char* tables;
    char unk_8[0x44 - 8];
};

struct Struct_203dafc;
struct PointerField330_ffd0;
struct Obj02033874;
struct Flags02033fdc;

extern "C" void* GameState_GetStarflight(struct PointerField330_ffd0* obj);
extern "C" void func_020ad59c(void* obj);
extern "C" void func_0203dafc(struct Struct_203dafc* obj);
extern "C" void VramState_Restore(char* tables);
extern "C" void VramState_Save(char* tables);
extern "C" void Zone3D_GetInstance();
extern "C" void GameObject_SnapFacing(struct Obj02033874* obj, int value);
extern "C" void GameObject_ResumeMovement(struct Flags02033fdc* obj);
extern "C" void func_0200fd38(GameState* state, int slot, GameObject* obj);
extern "C" void func_020adfa8(struct Struct_020aca88* prop);
extern "C" void func_020da1ac(void* container);

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

        unsigned int size;
        ObjectArchiveLoadInfo info;
        void* file = LoadFileIntoNewAllocation(data_020f1c08, *alloc, &size);
        if (file == NULL) {
            return;
        }
        struct Struct_020aca88* prop = (struct Struct_020aca88*)alloc->Allocate(0x1b8);
        if (prop == NULL) {
            return;
        }
        func_020ad59c(prop);
        func_0203dafc((struct Struct_203dafc*)&info);
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
        prop->unknown_154_ = pos;
        prop->obj3D.SetScale(&scale);
        GameObject_SnapFacing((struct Obj02033874*)prop, 0x3244);
        prop->unknown_b0_ = 0xc9;
        prop->obj3D.MakeVisible();
        GameObject_ResumeMovement((struct Flags02033fdc*)prop);
        prop->unknown_e0_0_ = 0;
        prop->obj3D.EnableFlag(0x80);
        func_0200fd38(state, 0xca, (GameObject*)prop);
        state->GetGameObjectByIndex(0xcb);

        file = LoadFileIntoNewAllocation(data_020f1c20, *alloc, &size);
        if (file == NULL) {
            return;
        }
        Object3D* obj = (Object3D*)alloc->Allocate(0xac);
        if (obj == NULL) {
            return;
        }
        obj->Initialize();
        func_0203dafc((struct Struct_203dafc*)&info);
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
        func_0200fd38(state, 0xcb, (GameObject*)obj);
        state->GetGameObjectByIndex(0xcc);

        file = LoadFileIntoNewAllocation(data_020f1c38, *alloc, &size);
        if (file == NULL) {
            return;
        }
        obj = (Object3D*)alloc->Allocate(0xac);
        if (obj == NULL) {
            return;
        }
        obj->Initialize();
        func_0203dafc((struct Struct_203dafc*)&info);
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
        func_0200fd38(state, 0xcc, (GameObject*)obj);
        state->GetGameObjectByIndex(0xcd);

        file = LoadFileIntoNewAllocation(data_020f1c51, *alloc, &size);
        if (file == NULL) {
            return;
        }
        obj = (Object3D*)alloc->Allocate(0xac);
        if (obj == NULL) {
            return;
        }
        obj->Initialize();
        func_0203dafc((struct Struct_203dafc*)&info);
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
        func_0200fd38(state, 0xcd, (GameObject*)obj);

        func_020adfa8(prop);
        SafeAllocator* var13 = (SafeAllocator*)alloc->Allocate(0x14);
        var13->ResetAllocatorPointer();
        var13->CreateTypeA(alloc->Allocate(0x3c00), 0x3c00);
        func_020da1ac(&data_ov017_021d82fc);
        data_ov017_021d82fc.allocator = var13;
        data_ov017_021d82fc.tables = tables;
    }
}
