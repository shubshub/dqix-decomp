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
struct SearchTable;
struct SearchEntry020a6728;
struct PointerField32c_ffc0;
struct Obj02033874;
struct Flags02033fdc;
struct ActorAllocation020a6728 { SafeAllocator* allocator; char* tables; };
SearchTable* GameState_GetZoneTable(void*);
SearchEntry020a6728* ZoneTable_FindEntry(SearchTable*, int);
void* GameState_GetShip(PointerField32c_ffc0*);
void* LoadFileIntoNewAllocation(const char*, SafeAllocator&, unsigned int*);
void InitActor020a75a0(char*);
void VramState_Restore(char*);
void VramState_Save(char*);
extern "C" Zone3D* Zone3D_GetInstance();
void GameObject_SnapFacing(Obj02033874*, int);
void GameObject_ResumeMovement(Flags02033fdc*);
void RegisterCombatantSlot_0200fd38(GameState*, int, GameObject*);
void ResetContainerAndHandleFields020da1ac(void*);
extern "C" void func_020a72ac(Zone3D*, int);
extern char data_020f1b50[];
extern char data_020f1b52[];
extern Struct_ov017_021d82fc data_ov017_021d82fc;

// USA: func_020a6728
// JPN: func_020a84cc
// KEEP-NAME
extern "C" ARM void func_020a6728(GameResources* self, int id) {
    GameState* state = GameState::GetInstance();
    SearchEntry020a6728* entry = ZoneTable_FindEntry(GameState_GetZoneTable(state), id);
    const char* name = 0;
    if (entry != 0) name = (const char*)entry + 5;
    if (id != 10000 && id != 10100) {
        if (id < 20000 || id > 29999 || name == 0 || strstr(name, data_020f1b50) != 0)
            return;
    }
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    SafeAllocator* allocator = &self->allocator_array_38[7];
    char* tables = (char*)&self->vramStates_ + 0x310;
    GameState_GetShip((PointerField32c_ffc0*)state);
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
    loadInfo.fileSize = 0;
    loadInfo.allocator = 0;
    loadInfo.unk_10 = 0;
    loadInfo.unk_14 = 0;
    loadInfo.unk_18 = 0;
    loadInfo.packageID = 0;
    VramState_Restore(tables);
    loadInfo.fileData = file;
    loadInfo.fileSize = length;
    loadInfo.allocator = allocator;
    actor->object.LoadFromCHRArchive(&loadInfo);
    VramState_Save(tables);
    Zone3D* zone = Zone3D_GetInstance();
    state->GetLeader();
    ZoneSavedActorState* saved = zone->GetSavedActorState();
    actor->object.position_ = saved->position;
    saved = zone->GetSavedActorState();
    actor->homePosition = saved->position;
    actor->object.SetScale(0xa0, 0xa0, 0xa0);
    GameObject_SnapFacing((Obj02033874*)actor, zone->savedActor_.rotationY);
    actor->slot = 0xc9;
    actor->field_b4 = 0x106;
    actor->field_b6 = 10;
    actor->object.MakeVisible();
    GameObject_ResumeMovement((Flags02033fdc*)actor);
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
    func_020a72ac(Zone3D_GetInstance(), 0);
}
