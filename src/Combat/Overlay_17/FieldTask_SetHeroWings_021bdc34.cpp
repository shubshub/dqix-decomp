#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Resource/GameResources.h"
#include "Combat/CombatantRecovery.h"

struct Foo0207df50 { unsigned char fields[0x70]; };
struct Struct_ov017_0218f064_6;
struct Struct_ov017_021bdc34 {
    unsigned char unknown_0_[4];
    SafeAllocator primary;
    unsigned char unknown_18_[0xcc - 0x18];
    Foo0207df50 unknown_cc_;
    unsigned char unknown_13c_[0x1ac - 0x13c];
    Foo0207df50 unknown_1ac_;
    unsigned char unknown_21c_[0x52c - 0x21c];
    SafeAllocator unknown_52c_;
};
struct Struct_ov017_021bdc34_2 {
#if defined(jpn)
    unsigned char unknown_0_[0x4114];
#else
    unsigned char unknown1_0_[0x4334];
#endif
    Object3D* first;
    Object3D* second;
    Object3D* third;
    Object3D* unknown_4340_;
};
struct LoadState021bdc34 {
    unsigned char tag;
    unsigned char done;
    unsigned char unknown_2_[6];
    short tasks[4];
    unsigned char stage;
    unsigned char mode;
};
extern "C" Struct_ov017_021bdc34* func_ov017_021a11b4(Struct_ov017_0218f064_6*);
extern "C" void VramState_Rewind(Foo0207df50*);
extern "C" void VramState_Restore(char*);
extern "C" void VramState_Save(char*);
extern "C" void func_ov017_021bdb78(int);
extern "C" void func_ov017_0218fcf8(int, int, int);
extern "C" void func_ov017_0218f5a4(void*, int, int, int, int);
#if defined(jpn)
extern const char data_ov017_021d85ec[], data_ov017_021d8606[], data_ov017_021d861e[];
extern const char data_ov017_021d8639[], data_ov017_021d8644[], data_ov017_021d864d[], data_ov017_021d8653[];
#else
extern const char data_ov017_021d7e14[], data_ov017_021d7e2e[], data_ov017_021d7e46[];
extern const char data_ov017_021d7e61[], data_ov017_021d7e6c[], data_ov017_021d7e75[], data_ov017_021d7e7b[];
#endif

// USA: FieldTask_SetHeroWings
// JPN: func_ov017_021be22c
// Overlay 17, originally func_ov017_021bdc34 (USA/EUR 0x021bdc34, JPN 0x021be22c)
extern "C" ARM void FieldTask_SetHeroWings(LoadState021bdc34* self) {
    GameState* game = GameState::GetInstance();
    Struct_ov017_021bdc34_2* globals = (Struct_ov017_021bdc34_2*)GetGameResources();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    CombatantRecovery* actor = (CombatantRecovery*)func_0200ff1c(game, 0);
    if (actor == 0) return;
    Struct_ov017_021bdc34* entry = func_ov017_021a11b4((Struct_ov017_0218f064_6*)globals);
    if (entry == 0) {
        self->done = 1;
        return;
    }
    SafeAllocator* allocators[4] = {&entry->primary, &entry->primary, &entry->unknown_52c_, &entry->primary};
    Foo0207df50* pairs[4] = {&entry->unknown_cc_, &entry->unknown_cc_, &entry->unknown_1ac_, &entry->unknown_cc_};
    if (self->stage == 0) {
        if (self->mode == 1 && globals->first != 0 && globals->second != 0) {
            if (actor->recoveryFlags & 0x40) { self->done = 1; return; }
        }
        if (self->mode == 2 && globals->first != 0 && globals->second != 0) {
            if (!(actor->recoveryFlags & 0x40)) { self->done = 1; return; }
        }
        if (self->mode == 0 && globals->first == 0 && globals->second == 0) {
            if (!(actor->recoveryFlags & 0x40)) { self->done = 1; return; }
        }
        if (self->mode == 1 || self->mode == 2) {
            if (globals->first == 0) {
#if defined(jpn)
                self->tasks[0] = loader->QueueLoadFile(data_ov017_021d85ec, 0);
                self->tasks[1] = loader->QueueLoadFile(data_ov017_021d8606, 0);
                self->tasks[2] = loader->QueueLoadFileInGP2(data_ov017_021d861e, data_ov017_021d8639, 0);
                self->tasks[3] = loader->QueueLoadFileInGP2(data_ov017_021d861e, data_ov017_021d8644, 0);
#else
                self->tasks[0] = loader->QueueLoadFile(data_ov017_021d7e14, 0);
                self->tasks[1] = loader->QueueLoadFile(data_ov017_021d7e2e, 0);
                self->tasks[2] = loader->QueueLoadFileInGP2(data_ov017_021d7e46, data_ov017_021d7e61, 0);
                self->tasks[3] = loader->QueueLoadFileInGP2(data_ov017_021d7e46, data_ov017_021d7e6c, 0);
#endif
                for (int i = 0; i < 4; i++) {
                    allocators[i]->Reset();
                    VramState_Rewind(pairs[i]);
                }
            } else {
                for (int i = 0; i < 4; i++) self->tasks[i] = -1;
            }
            if (self->mode == 1) actor->recoveryFlags |= 0x40;
            else actor->recoveryFlags &= ~0x40;
            func_ov017_0218f5a4(globals, 0, 1, 0, 0);
            self->stage = 1;
        } else {
            globals->first = 0;
            globals->second = 0;
            globals->third = 0;
            globals->unknown_4340_ = 0;
            if (actor != 0) actor->recoveryFlags &= ~0x40;
            func_ov017_0218f5a4(globals, 0, 1, 0, 0);
            self->stage = 2;
        }
    } else if (self->stage == 1) {
        int pending = 0;
        for (int i = 0; i < 4; i++) {
            if (self->tasks[i] < 0) continue;
            if (loader->GetTaskStatus(self->tasks[i]) != 0 && loader->GetDetailedTaskStatus(self->tasks[i]) == 2) {
                void* file;
                unsigned int length;
                loader->GetLoadedFileByID(self->tasks[i], &file, &length);
                SafeAllocator* allocator = allocators[i];
                Object3D* object = (Object3D*)allocator->Allocate(0xac);
                if (file != 0 && object != 0) {
                    ObjectArchiveLoadInfo info;
                    info.fileData = file;
                    info.unk_0 = 0;
                    info.unk_14 = 0;
                    info.unk_18 = 0;
                    info.packageID = 0;
                    info.unk_10 = 1;
                    info.allocator = allocator;
                    info.fileSize = length;
                    Foo0207df50* pair = pairs[i];
                    VramState_Restore((char*)pair);
                    object->Initialize();
                    object->LoadFromCCHROrCMOTArchive(&info, 0);
                    VramState_Save((char*)pair);
                    switch (i) {
                    case 0: globals->first = object; break;
                    case 1: globals->second = object; break;
                    case 2: globals->third = object; break;
                    case 3: globals->unknown_4340_ = object; break;
                    }
                }
                loader->RemoveTask(self->tasks[i]);
                self->tasks[i] = -1;
            } else pending = 1;
        }
        if (!pending) self->stage = 2;
    } else if (self->stage == 2) {
        if (self->mode == 1) func_ov017_021bdb78(0);
        else {
            actor->obj3D_.unknown_9c_ = 0;
            func_ov017_0218fcf8((int)globals, 0, 0);
        }
        if (globals->first != 0) {
#if defined(jpn)
            if (self->mode == 1) globals->first->SetAnimationByName(data_ov017_021d864d, 0);
            else globals->first->SetAnimationByName(data_ov017_021d8653, 0);
#else
            if (self->mode == 1) globals->first->SetAnimationByName(data_ov017_021d7e75, 0);
            else globals->first->SetAnimationByName(data_ov017_021d7e7b, 0);
#endif
        }
        self->done = 1;
    }
}
