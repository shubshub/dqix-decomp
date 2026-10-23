#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "World/Object3D.h"
#include "World/Zone3D.h"
#include "std_library_functions.h"

#if defined(jpn)
#define data_020f1b50 data_020f1cc8
#define data_020f1b52 data_020f1cca
#endif

struct Struct_020a6728 {
    Object3D unknown_0_;
    char unknown_ac_[4];
    unsigned short unknown_b0_;
    unsigned short unknown_b2_;
    unsigned short unknown_b4_;
    unsigned short unknown_b6_;
    char unknown_b8_[0x28];
    unsigned char unknown_e0_;
    char unknown_e1_[0x63];
    Vector3i unknown_144_;
    char unknown_150_[0x20];
};
struct Struct_02095924_2;
struct Struct_020a6728_2;
struct Struct_0200ffc0;
struct Struct_02033834;
struct Struct_02033fdc;
struct Struct_ov017_021d82fc { SafeAllocator* unknown_0_; char* unknown_4_; };
extern "C" Struct_02095924_2* func_02011584(void*);
extern "C" Struct_020a6728_2* func_02099950(Struct_02095924_2*, int);
extern "C" void* func_0200ffc0(Struct_0200ffc0*);
void* LoadFileIntoNewAllocation(const char*, SafeAllocator&, unsigned int*);
void InitActor020a75a0(char*);
void VramState_Restore(char*);
void VramState_Save(char*);
extern "C" Zone3D* func_02012fe4();
extern "C" void func_02033874(Struct_02033834*, int);
extern "C" void func_02033fdc(Struct_02033fdc*);
extern "C" void func_0200fd38(GameState*, int, GameObject*);
extern "C" void func_020da1ac(void*);
extern "C" void func_020a72ac(Zone3D*, int);
extern char data_020f1b50[];
extern char data_020f1b52[];
extern Struct_ov017_021d82fc data_ov017_021d82fc;

// USA: func_020a6728
// JPN: func_020a84cc
// KEEP-NAME
extern "C" ARM void func_020a6728(GameResources* arg0, int arg1) {
    GameState* var0 = GameState::GetInstance();
    Struct_020a6728_2* var1 = func_02099950(func_02011584(var0), arg1);
    const char* var2 = 0;
    if (var1 != 0) var2 = (const char*)var1 + 5;
    if (arg1 != 10000 && arg1 != 10100) {
        if (arg1 < 20000 || arg1 > 29999 || var2 == 0 || strstr(var2, data_020f1b50) != 0)
            return;
    }
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    SafeAllocator* allocator = &self->allocator_array_38[7];
    char* tables = (char*)&self->unknown_2cc + 0x310;
    GetPointerAt0x32c_0200ffc0((PointerField32c_ffc0*)state);
    if (loader->GetNumQueuedTasks() > 0) return;
    unsigned int length;
    void* file = LoadFileIntoNewAllocation(data_020f1b52, *allocator, &length);
    if (file == 0) return;
    Actor020a6728* actor = (Actor020a6728*)allocator->Allocate(0x170);
    if (actor == 0) return;
    InitActor020a75a0((char*)actor);
    ObjectArchiveLoadInfo loadInfo;
    loadInfo.unk_0 = 0;
    loadInfo.fileData = 0;
    loadInfo.unk_8 = 0;
    loadInfo.allocator = 0;
    loadInfo.unk_10 = 0;
    loadInfo.unk_14 = 0;
    loadInfo.unk_18 = 0;
    loadInfo.packageID = 0;
    VramState_Restore(tables);
    loadInfo.fileData = file;
    loadInfo.unk_8 = length;
    loadInfo.allocator = allocator;
    actor->object.LoadFromCHRArchive(&loadInfo);
    VramState_Save(tables);
    Zone3D* zone = func_02012fe4();
    state->GetUnknownGameObject();
    ZoneSavedActorState* saved = zone->GetSavedActorState();
    actor->object.position_ = saved->position;
    saved = zone->GetSavedActorState();
    actor->homePosition = saved->position;
    actor->object.SetScale(0xa0, 0xa0, 0xa0);
    SetVecYFromValue02033874((Obj02033874*)actor, zone->savedActor_.rotationY);
    actor->slot = 0xc9;
    actor->field_b4 = 0x106;
    actor->field_b6 = 10;
    actor->object.MakeVisible();
    ClearFlag0x4At0xe0((Flags02033fdc*)actor);
    actor->flags &= ~1;
    actor->object.DisableFlag(0x180);
    actor->object.EnableFlag(0x400000);
    RegisterCombatantSlot_0200fd38(state, 0xc9, (GameObject*)actor);
    if (id == 10000) {
        SafeAllocator* extraAllocator = (SafeAllocator*)allocator->Allocate(0x14);
        extraAllocator->ResetAllocatorPointer();
        void* buffer = allocator->Allocate(0x3c00);
        extraAllocator->CreateTypeA(buffer, 0x3c00);
        ResetContainerAndHandleFields020da1ac(&data_ov017_021d82fc);
        data_ov017_021d82fc.allocator = extraAllocator;
        data_ov017_021d82fc.tables = tables;
    }
    func_020a72ac(func_02012fe4(), 0);
}
