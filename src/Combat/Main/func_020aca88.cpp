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

void* GetPointerAt0x330_0200ffd0(struct PointerField330_ffd0* obj);
void InitObj020ad59c(void* obj);
void ClearEightWords_0203dafc(struct Struct_203dafc* obj);
void VramState_Restore(char* tables);
void VramState_Save(char* tables);
extern "C" void func_02012fe4();
extern "C" void func_02033874(struct Struct_02033834* arg0, int arg1);
extern "C" void func_02033fdc(struct Struct_02033fdc* arg0);
extern "C" void func_0200fd38(GameState* arg0, int arg1, GameObject* arg2);
extern "C" void func_020adfa8(struct Struct_020aca88* arg0);
extern "C" void func_020da1ac(void* arg0);

extern const char data_020f1c08[];
extern const char data_020f1c20[];
extern const char data_020f1c38[];
extern const char data_020f1c51[];
extern const Vector3i data_020e910c;
extern const Vector3i data_020e9100;
extern struct Struct_ov017_021d82fc_3 data_ov017_021d82fc;

// USA: func_020aca88
extern "C" ARM void func_020aca88(GameResources* arg0, int arg1) {
    if (arg1 == 0x2774) {
        GameState* var0 = GameState::GetInstance();
        BackgroundLoader* var1 = BackgroundLoader::GetInstance();
        SafeAllocator* var2 = &arg0->allocator_array_38[7];
        char* var3 = ((Type_020aca88*)arg0->unknown_2cc_)[7];
        func_0200ffd0((struct Struct_0200ffd0*)var0);
        if (var1->GetNumQueuedTasks() > 0) {
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
        info.unk_8 = size;
        info.fileData = file;
        info.allocator = alloc;
        prop->obj3D.LoadFromCHRArchive(&info);
        VramState_Save(tables);
        func_02012fe4();

        GameObject* var8 = var0->GetUnknownGameObject();
        Vector3i var9 = var8->obj3D_.position_;
        var9.y += 0xa000;
        Vector3i var10 = data_020e910c;
        Vector3i var11 = data_020e9100;
        var7->unknown_0_.rotation_ = var11;
        var7->unknown_0_.position_ = var9;
        var7->unknown_154_ = var9;
        var7->unknown_0_.SetScale(&var10);
        func_02033874((struct Struct_02033834*)var7, 0x3244);
        var7->unknown_b0_ = 0xc9;
        var7->unknown_0_.MakeVisible();
        func_02033fdc((struct Struct_02033fdc*)var7);
        var7->unknown_e0_0_ = 0;
        var7->unknown_0_.EnableFlag(0x80);
        func_0200fd38(var0, 0xca, (GameObject*)var7);
        var0->GetGameObjectByIndex(0xcb);

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
        info.unk_8 = size;
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
        info.unk_8 = size;
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
        info.unk_8 = size;
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
