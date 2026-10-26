#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "std_library_functions.h"
#include "Resource/GameResources.h"

#if defined(jpn)
struct Struct_020d3c28 { char storage[0xa4]; };
#else
struct Struct_020d3c28 { char storage[0xb8]; };
#endif
struct StreamHeader;
struct Struct_020d3d90;
struct Foo0207df50;
struct Struct_02054664;
struct Struct_02059cfc_2;
struct Struct_02059cfc_3;
struct Obj02033874;
struct Bytes02033b88;
#if defined(jpn)
struct Struct_ov017_021c1e6c_7 { char name[0xb]; unsigned char kind:3, special:1, flags:4; unsigned char effect; char unknown_d_[0x13]; };
#else
struct Struct_ov017_021c1e6c_7 { char name[0x10]; unsigned char kind:3, special:1, flags:4; unsigned char effect; char unknown_12_[0x12]; };
#endif
struct Struct_01ff8b48_14 {
    char unknown_0_[0x56b]; unsigned char mode:4, flags:4;
    void SetMode(int value) { unsigned char var0 = value; mode = var0; }
};
#if defined(jpn)
struct Struct_ov017_021c1e6c { GameObject object; char unknown_13c_[0x144 - 0x13c]; Struct_01ff8b48_14* status; char unknown_148_[0x1c4 - 0x154]; Struct_ov017_021c1e6c_7* record; };
#else
struct Struct_ov017_021c1e6c { GameObject object; char unknown_13c_[0x150 - 0x13c]; Struct_01ff8b48_14* status; char unknown_154_[0x1c4 - 0x154]; Struct_ov017_021c1e6c_7* record; };
#endif
struct Global021c1e6c { char unknown_0_[0xf7d]; unsigned char selection; };
#if defined(jpn)
struct GamePosition021c1e6c { char unknown_0_[0x7c88]; int height; Vector3i position; };
#else
struct GamePosition021c1e6c { char unknown_0_[0x7f5c]; int height; Vector3i position; };
#endif
#if defined(jpn)
struct Struct_ov017_021c1e6c_4 { char storage[0xc00]; };
#else
struct Struct_ov017_021c1e6c_4 { char storage[0x1000]; };
#endif
struct Struct_ov017_021c1e6c_5 {
#if defined(jpn)
    char unknown_0_[0x3c4]; Struct_ov017_021c1e6c_4 unknown_1d4_[2];
#else
    char unknown1_0_[0x1d4]; Struct_ov017_021c1e6c_4 unknown_1d4_[2];
#endif
    Struct_ov017_021c1e6c_4* inline_ov017_021c1e6c(int index) { return &unknown_1d4_[index]; }
};
struct Summon021c1e6c { char unknown_0_; unsigned char done; char unknown_2_[6]; short task; unsigned char state, kind; };
extern "C" unsigned short* Zone3D_GetInstance();
extern "C" void func_020d3c08(char*);
extern "C" void func_020d3c84(Struct_020d3c28*, StreamHeader*, int);
extern "C" Struct_ov017_021c1e6c_7* func_020d3d90(Struct_020d3d90*, int);
extern "C" void func_ov017_0218f064(GameResources*, int, int, int, int);
extern "C" unsigned char func_ov017_02191764(int, int);
extern "C" void* LinkSession_GetInstance();
extern "C" int LinkSession_IsHostOrSolo(void*);
extern "C" void VramState_Rewind(Foo0207df50*);
extern "C" void func_02082828(void*);
extern "C" void func_02054664(Struct_02054664*);
extern "C" void func_02053c4c(char*, char*);
extern "C" void func_0200fd38(GameState*, int, GameObject*);
extern "C" GameObject* func_0200ff58(GameState*, int);
extern "C" void func_020546a0(void*, int);
extern "C" void func_020546b4(void*, int);
extern "C" void func_02059f38(Struct_02059cfc_2*, Struct_02059cfc_3*);
extern "C" void GameObject_SnapFacing(Obj02033874*, int);
extern "C" void func_ov017_02191508(int, Struct_ov017_021c1e6c_7*);
extern "C" void GameObject_ApplyPendingControl(void*);
extern "C" void Party_ReformLine(GameResources*, int, int, int, int);
extern "C" void func_ov017_02191234(GameResources*);
extern "C" int LinkSession_IsGuest(void*);
extern "C" void func_ov017_021907dc(int, int, int, int, int);
extern "C" void VramState_Restore(char*);
extern "C" void VramState_Save(char*);
extern "C" void GameObject_ForceMotionState(Bytes02033b88*, int);
extern "C" void GameObject_ClearHidden(unsigned char*);
extern "C" int GameObject_IsHidden(unsigned char*);
extern "C" void func_02039d48(unsigned char*);
#if defined(jpn)
extern char data_ov017_021d87c4[], data_ov017_021d87d8[];
#else
extern char data_ov017_021d7f2c[], data_ov017_021d7f40[], data_ov017_021d7f50[];
#endif

// Overlay 17, originally func_ov017_021c1e6c (USA/EUR 0x021c1e6c, JPN 0x021c23e0)
extern "C" ARM void FieldTask_SpawnFollower(Summon021c1e6c* self) {
    GameState* game = GameState::GetInstance();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    GameResources* resources = GetGameResources();
    unsigned short* data = Zone3D_GetInstance();
    if (self->state == 0) {
#if defined(jpn)
        self->task = loader->QueueLoadFile(data_ov017_021d87c4, 0);
#else
        self->task = loader->QueueLoadFileInGP2(data_ov017_021d7f2c, data_ov017_021d7f40, 0);
#endif
        self->state = 1;
    } else if (self->state == 1) {
        if (!loader->GetTaskStatus(self->task)) return;
        Struct_ov017_021c1e6c_7* entry = 0;
        if (loader->GetDetailedTaskStatus(self->task) == 2) {
            void* file;
            unsigned int length;
            loader->GetLoadedFileByID(self->task, &file, &length);
            if (file) {
                Struct_020d3c28 handlers;
                func_020d3c08((char*)&handlers);
                func_020d3c84(&handlers, (StreamHeader*)file, length);
                entry = func_020d3d90((Struct_020d3d90*)&handlers, self->kind);
            }
        }
        loader->RemoveTask(self->task);
        self->task = -1;
        if (!entry) { self->done = 1; return; }
        int combatantId;
        unsigned char slot;
        if (entry->special) {
            int kind = entry->kind;
            combatantId = 3;
            func_ov017_0218f064(resources, combatantId, 4, 1, kind);
            slot = func_ov017_02191764(combatantId, 0);
            self->done = 1;
        } else {
            if (LinkSession_IsHostOrSolo(LinkSession_GetInstance())) ((Global021c1e6c*)GameState_GetParty(game))->selection = self->kind;
            combatantId = 0xce;
            slot = 4;
            Struct_ov017_021c1e6c_4* initialBank = ((Struct_ov017_021c1e6c_5*)resources)->inline_ov017_021c1e6c(1);
            resources->allocator_11c0.Reset();
            VramState_Rewind((Foo0207df50*)initialBank);
            Struct_ov017_021c1e6c_7* saved = (Struct_ov017_021c1e6c_7*)resources->allocator_11c0.Allocate(sizeof(Struct_ov017_021c1e6c_7));
            if (!saved) goto configureCombatant;
            memcpy(saved, entry, sizeof(Struct_ov017_021c1e6c_7));
#if defined(jpn)
            void* stats = resources->allocator_11c0.Allocate(0x8cc);
#else
            void* stats = resources->allocator_11c0.Allocate(0x964);
#endif
            if (!stats) goto configureCombatant;
            func_02082828(stats);
#if defined(jpn)
            Struct_ov017_021c1e6c* combatant = (Struct_ov017_021c1e6c*)resources->allocator_11c0.Allocate(0x2c8);
#else
            Struct_ov017_021c1e6c* combatant = (Struct_ov017_021c1e6c*)resources->allocator_11c0.Allocate(0x2d4);
#endif
            if (!combatant) goto configureCombatant;
            func_02054664((Struct_02054664*)combatant);
            func_02053c4c((char*)combatant, (char*)stats);
            unsigned char kind = saved->kind;
            if (combatant->status) combatant->status->SetMode(kind);
            combatant->record = saved;
            func_0200fd38(game, 0xce, &combatant->object);
            char filename[0x50];
#if defined(jpn)
            sprintf(filename, data_ov017_021d87d8, entry->effect);
#else
            sprintf(filename, data_ov017_021d7f50, entry->effect);
#endif
            self->task = loader->QueueLoadFile(filename, &resources->allocator_11c0);
            self->state = 2;
        }
configureCombatant:
        GameObject* combatant = func_0200ff58(game, combatantId);
        if (combatant) {
            func_020546a0(combatant, 0);
            func_020546b4(combatant, slot);
            combatant->obj3D_.SetField06(*data);
            if (game->GetLeader()) {
                func_02059f38((Struct_02059cfc_2*)combatant, (Struct_02059cfc_3*)&((GamePosition021c1e6c*)game)->position);
                GameObject_SnapFacing((Obj02033874*)combatant, ((GamePosition021c1e6c*)game)->height);
            }
            if (entry->special) func_ov017_02191508(combatantId, entry);
            GameObject* leader = game->GetLeader();
            if (leader) GameObject_ApplyPendingControl(leader);
            Party_ReformLine(resources, 1, 1, 1, 1);
            func_ov017_02191234(resources);
            if (LinkSession_IsGuest(LinkSession_GetInstance())) func_ov017_021907dc((int)resources, 0, 1, 1, 1);
        } else self->done = 1;
    } else if (self->state == 2) {
        if (!loader->GetTaskStatus(self->task)) return;
        if (loader->GetDetailedTaskStatus(self->task) == 2) {
            void* file;
            unsigned int length;
            loader->GetLoadedFileByID(self->task, &file, &length);
            if (file) {
                ObjectArchiveLoadInfo info;
                info.allocator = &resources->allocator_11c0;
                info.unk_0 = 0;
                info.unk_10 = 0; info.unk_14 = 0; info.unk_18 = 0; info.packageID = 0;
                info.fileData = file;
                info.fileSize = length;
                char* pairTables = resources->unknown_11d4_;
                GameObject* combatant = func_0200ff58(game, 0xce);
                if (combatant) {
                    VramState_Restore(pairTables);
                    combatant->obj3D_.LoadFromCCHROrCMOTArchive(&info, 0);
                    VramState_Save(pairTables);
                    combatant->obj3D_.SetScale(0x10a, 0x10a, 0x10a);
                    func_020546a0(combatant, 0);
                    GameObject_ForceMotionState((Bytes02033b88*)combatant, 0);
                    GameObject_ClearHidden((unsigned char*)combatant);
                    for (int i = 0; i < 4; i++) {
                        GameObject* member = func_0200ff58(game, i);
                        if (member && GameObject_IsHidden((unsigned char*)member)) func_02039d48((unsigned char*)combatant);
                    }
                    GameObject* leader = game->GetGameObjectByIndex(0);
                    if (leader) {
                        func_02059f38((Struct_02059cfc_2*)combatant, (Struct_02059cfc_3*)&((GamePosition021c1e6c*)game)->position);
                        GameObject_SnapFacing((Obj02033874*)combatant, ((GamePosition021c1e6c*)game)->height);
                        combatant->obj3D_.SetField06(leader->obj3D_.GetField06());
                    }
                }
            }
        }
        loader->RemoveTask(self->task);
        self->task = -1;
        self->done = 1;
    }
}
