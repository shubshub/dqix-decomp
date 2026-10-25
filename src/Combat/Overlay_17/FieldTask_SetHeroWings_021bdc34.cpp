#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Resource/GameResources.h"
#include "Combat/CombatantRecovery.h"

struct Struct_0203d028 { unsigned char unknown_0_[0x70]; };
struct Struct_ov017_0218f064_6;
struct Struct_ov017_021bdc34 {
    unsigned char unknown_0_[4];
    SafeAllocator unknown_4_;
    unsigned char unknown_18_[0xcc - 0x18];
    Struct_0203d028 unknown_cc_;
    unsigned char unknown_13c_[0x1ac - 0x13c];
    Struct_0203d028 unknown_1ac_;
    unsigned char unknown_21c_[0x52c - 0x21c];
    SafeAllocator unknown_52c_;
};
struct Struct_ov017_021bdc34_2 {
#if defined(jpn)
    unsigned char unknown_0_[0x4114];
#else
    unsigned char unknown1_0_[0x4334];
#endif
    Object3D* unknown_4334_;
    Object3D* unknown_4338_;
    Object3D* unknown_433c_;
    Object3D* unknown_4340_;
};
struct Struct_ov017_021bdc34_3 {
    unsigned char unknown_0_;
    unsigned char unknown_1_;
    unsigned char unknown_2_[6];
    short unknown_8_[4];
    unsigned char unknown_10_;
    unsigned char unknown_11_;
};
LoadEntry021bdc34* FindNegativeEntry_021a11b4(S021a11b4*);
void VramState_Rewind(Foo0207df50*);
void VramState_Restore(char*);
void VramState_Save(char*);
void SetFieldndDispatch_021bdb78_021bdb78(int);
void CallHelperIfCheckPasses_0218fcf8(int, int, int);
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
    LoadGlobals021bdc34* globals = (LoadGlobals021bdc34*)GetGameResources();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    CombatantRecovery* actor = (CombatantRecovery*)GetCombatantWithFlag0x100_0200ff1c(game, 0);
    if (actor == 0) return;
    LoadEntry021bdc34* entry = FindNegativeEntry_021a11b4((S021a11b4*)globals);
    if (entry == 0) {
        self->done = 1;
        return;
    }
    SafeAllocator* var5[4] = {&var4->unknown_4_, &var4->unknown_4_, &var4->unknown_52c_, &var4->unknown_4_};
    Struct_0203d028* var6[4] = {&var4->unknown_cc_, &var4->unknown_cc_, &var4->unknown_1ac_, &var4->unknown_cc_};
    if (arg0->unknown_10_ == 0) {
        if (arg0->unknown_11_ == 1 && var1->unknown_4334_ != 0 && var1->unknown_4338_ != 0) {
            if (var3->unknown_18c_ & 0x40) { arg0->unknown_1_ = 1; return; }
        }
        if (arg0->unknown_11_ == 2 && var1->unknown_4334_ != 0 && var1->unknown_4338_ != 0) {
            if (!(var3->unknown_18c_ & 0x40)) { arg0->unknown_1_ = 1; return; }
        }
        if (arg0->unknown_11_ == 0 && var1->unknown_4334_ == 0 && var1->unknown_4338_ == 0) {
            if (!(var3->unknown_18c_ & 0x40)) { arg0->unknown_1_ = 1; return; }
        }
        if (arg0->unknown_11_ == 1 || arg0->unknown_11_ == 2) {
            if (var1->unknown_4334_ == 0) {
#if defined(jpn)
                arg0->unknown_8_[0] = var2->QueueLoadFile(data_ov017_021d85ec, 0);
                arg0->unknown_8_[1] = var2->QueueLoadFile(data_ov017_021d8606, 0);
                arg0->unknown_8_[2] = var2->QueueLoadFileInGP2(data_ov017_021d861e, data_ov017_021d8639, 0);
                arg0->unknown_8_[3] = var2->QueueLoadFileInGP2(data_ov017_021d861e, data_ov017_021d8644, 0);
#else
                arg0->unknown_8_[0] = var2->QueueLoadFile(data_ov017_021d7e14, 0);
                arg0->unknown_8_[1] = var2->QueueLoadFile(data_ov017_021d7e2e, 0);
                arg0->unknown_8_[2] = var2->QueueLoadFileInGP2(data_ov017_021d7e46, data_ov017_021d7e61, 0);
                arg0->unknown_8_[3] = var2->QueueLoadFileInGP2(data_ov017_021d7e46, data_ov017_021d7e6c, 0);
#endif
                for (int i = 0; i < 4; i++) {
                    allocators[i]->Reset();
                    VramState_Rewind(pairs[i]);
                }
            } else {
                for (int var8 = 0; var8 < 4; var8++) arg0->unknown_8_[var8] = -1;
            }
            if (arg0->unknown_11_ == 1) var3->unknown_18c_ |= 0x40;
            else var3->unknown_18c_ &= ~0x40;
            func_ov017_0218f5a4(var1, 0, 1, 0, 0);
            arg0->unknown_10_ = 1;
        } else {
            var1->unknown_4334_ = 0;
            var1->unknown_4338_ = 0;
            var1->unknown_433c_ = 0;
            var1->unknown_4340_ = 0;
            if (var3 != 0) var3->unknown_18c_ &= ~0x40;
            func_ov017_0218f5a4(var1, 0, 1, 0, 0);
            arg0->unknown_10_ = 2;
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
                    case 3: globals->fourth = object; break;
                    }
                }
                var2->RemoveTask(arg0->unknown_8_[var10]);
                arg0->unknown_8_[var10] = -1;
            } else var9 = 1;
        }
        if (!var9) arg0->unknown_10_ = 2;
    } else if (arg0->unknown_10_ == 2) {
        if (arg0->unknown_11_ == 1) func_ov017_021bdb78(0);
        else {
            var3->obj3D_.unknown_9c_ = 0;
            func_ov017_0218fcf8((int)var1, 0, 0);
        }
        if (var1->unknown_4334_ != 0) {
#if defined(jpn)
            if (self->mode == 1) globals->first->SetAnimationByName(data_ov017_021d864d, 0);
            else globals->first->SetAnimationByName(data_ov017_021d8653, 0);
#else
            if (self->mode == 1) globals->first->SetAnimationByName(data_ov017_021d7e75, 0);
            else globals->first->SetAnimationByName(data_ov017_021d7e7b, 0);
#endif
        }
        arg0->unknown_1_ = 1;
    }
}
