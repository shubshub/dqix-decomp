#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Resource/GameResources.h"

struct Struct_ov025_021e63b0_2 { unsigned char unknown_0_[0x20]; unsigned short unknown_20_; };
struct Struct_ov025_021e63b0_3 { unsigned char unknown_0_[0x10]; Struct_ov025_021e63b0_2* unknown_10_; };
struct Struct_ov025_021ef988_23 {
#if defined(jpn)
    unsigned char unknown_0_[4];
    char* unknown_c_;
    unsigned char unknown_8_[4];
    unsigned int unknown_1c_;
    unsigned char unknown_10_[0x10];
#else
    unsigned char unknown1_0_[0xc];
    char* unknown_c_;
    unsigned char unknown1_10_[0xc];
    unsigned int unknown_1c_;
#endif
    int unknown_20_;
    int unknown_24_;
    int unknown_28_;
};
struct Struct_ov025_021ef9a8;
struct Struct_02054000;
struct Struct_ov025_021e267c_2;
struct Struct_ov025_021e267c_3 {
    unsigned char unknown_0_;
    unsigned char unknown_1_;
    unsigned short unknown_2_;
    unsigned int unknown_4_;
    Struct_ov025_021e267c_3* unknown_8_;
};
#if defined(jpn)
struct Struct_ov025_021e63b0_4 { unsigned char unknown_0_[0x71c6]; unsigned short unknown_6fd6_; };
#else
struct Struct_ov025_021e63b0_4 { unsigned char unknown_0_[0x6fd6]; unsigned short unknown_6fd6_; };
#endif
struct Struct_ov025_021e63b0 { unsigned char unknown_0_[0x14]; unsigned int unknown_14_; };
extern Struct_ov025_021ef988_23 data_ov025_021ef988;
extern Struct_ov025_021ef9a8 data_ov025_021ef9a8;
extern char data_ov025_021ef809[];
extern char data_ov025_021ef791[];
extern "C" void func_ov025_021e3158(Struct_ov025_021ef9a8*);
extern "C" void* func_02054000(Struct_02054000*);
extern "C" void func_02072e94(char*, int, int, void*, int);
int SetFlagAndDispatch_021e2628(int, int);
SafeAllocator* GetArrayEntry_021e8a54_021e8a54(char*);
char* GetArrayEntry_021e8a64_021e8a64(char*);
void PushLogNode021e8bac(Obj021e8bac*, Node021e8bac*);
void VramState_Restore(char*);
void VramState_Save(char*);
void RegisterCombatantSlot_0200fd38(GameState*, int, GameObject*);
CloneWork* GetActiveCombatWork_ov000_02160130();
extern "C" void func_ov017_02191aac(GameResources*, int, int, int);

// USA: func_ov025_021e63b0
extern "C" ARM int func_ov025_021e63b0(void* arg0, Struct_ov025_021e63b0_3* arg1) {
    GameState* var0 = GameState::GetInstance();
    BackgroundLoader* var1 = BackgroundLoader::GetInstance();
    if (data_ov025_021ef988.unknown_20_ == 0) {
        if (!arg1->unknown_10_) return 1;
        int var2 = arg1->unknown_10_->unknown_20_;
        GameObject* var3 = func_0200ff1c(var0, var2);
        if (!var3) {
            func_ov025_021e3158(&data_ov025_021ef9a8);
            return 1;
        }
        void* var4 = func_02054000((Struct_02054000*)var3);
        if (!var4) {
            func_ov025_021e3158(&data_ov025_021ef9a8);
            return 1;
        }
        char var5[0x50];
        func_02072e94(var5, var2, 8, var4, 0);
        char* var6 = strrchr(var5, '.');
        if (var6) sprintf(var6, data_ov025_021ef809);
        if (!(data_ov025_021ef988.unknown_1c_ & 0x2000)) {
            var1->AddFence();
            data_ov025_021ef988.unknown_1c_ |= 0x2000;
        }
        data_ov025_021ef988.unknown_28_ = func_ov025_021e2628((int)data_ov025_021ef791, (int)var5);
        data_ov025_021ef988.unknown_20_++;
    } else if (data_ov025_021ef988.unknown_20_ == 1) {
        int var7 = data_ov025_021ef988.unknown_28_;
        if (!var1->GetTaskStatus(var7)) return 0;
        if (var1->GetDetailedTaskStatus(var7) != 2) {
            var1->RemoveTask(var7);
            func_ov025_021e3158(&data_ov025_021ef9a8);
            return 1;
        }
        unsigned int var8;
        void* var9;
        var1->GetLoadedFileByID(var7, &var9, &var8);
        SafeAllocator* var10 = func_ov025_021e8a54(data_ov025_021ef988.unknown_c_);
        char* var11 = func_ov025_021e8a64(data_ov025_021ef988.unknown_c_);
        Object3D* var12 = (Object3D*)var10->Allocate(sizeof(Object3D));
        if (!var12) {
            var1->RemoveTask(var7);
            func_ov025_021e3158(&data_ov025_021ef9a8);
            return 1;
        }
        Struct_ov025_021e267c_3* var13 = (Struct_ov025_021e267c_3*)var10->Allocate(sizeof(Struct_ov025_021e267c_3));
        if (!var13) {
            var1->RemoveTask(var7);
            func_ov025_021e3158(&data_ov025_021ef9a8);
            return 1;
        }
        node->kind = 4;
        node->id = 0xc8;
        PushLogNode021e8bac((Obj021e8bac*)data_ov025_021ef988.context, node);
        clone->Initialize();
        VramState_Restore(tables);
        clone->SetModelFromFileCopy(allocator, file, size, Model3D::TextureStagingMode_Normal);
        VramState_Save(tables);
        RegisterCombatantSlot_0200fd38(game, 0xc8, (GameObject*)clone);
        clone->MakeHidden();
        int sourceId = targets->head->id;
        CloneWork* work = GetActiveCombatWork_ov000_02160130();
        if (work) work->source = sourceId;
        GameObject* source = GetCombatantWithFlag0x100_0200ff1c(game, sourceId);
        if (source) {
            clone->position_ = source->obj3D_.position_;
            clone->rotation_ = source->obj3D_.rotation_;
            clone->SetScale(&source->obj3D_.GetScale());
            clone->unknown_2_ = sourceId;
            if (((CloneStats*)source->currentStats_)->flags & 0x8000000) {
                GameResources* resources = GetGameResources();
                clone->SetAlphaScaleFactor(0);
                func_ov017_02191aac(resources, 1, sourceId, 2);
            }
        }
        var1->RemoveTask(var7);
        func_ov025_021e3158(&data_ov025_021ef9a8);
        return 1;
    }
    return 0;
}
