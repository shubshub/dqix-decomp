#include <globaldefs.h>

#if defined(jpn)
#define func_ov005_02155d6c func_ov005_0215735c
#endif

#if defined(jpn)
#define LOW_REGION(j, u) (j)
#else
#define LOW_REGION(j, u) (u)
#endif
#include "World/ZoneLootableRecord.h"
#include <Memory/SafeAllocator.h>
#include <std_library_functions.h>

struct Struct_02012fa4;
struct Struct_0203d028;
struct Struct_0203a46c;
struct Struct_ov005_021556e4_2;

struct Struct_ov005_02155d6c_2 {
    char unknown_0_[0x80];
    short unknown_80_;
    short unknown_82_;
    char unknown_84_[4];
};

struct Struct_ov005_02155d6c {
    char unknown_0_[0x70];
};

void MaybeInvoke0204719c_02047230(Foo02048004* model);
void CopyInternalFields0207df50(Foo0207df50* state);
void VramState_Restore(char* state);
extern "C" void func_02047b40(MenuModel* model, void* file, SafeAllocator* allocator);
void VramState_Save(char* state);
void SetVec3At0x1c(Vec3Target0203a46c* model, int x, int y, int z);
void RunTwoCallbacksAndReset02155d38(Obj02155d38* slot);

struct Struct_ov005_02153ba4 {
    short unknown_0_;
    signed char unknown_2_;
    unsigned char unknown_3_;
    Struct_ov005_02155d6c* unknown_4_;
    Struct_ov005_02155d6c_2* unknown_8_;
    int unknown_c_;
    int unknown_10_;
    int unknown_14_;
    short unknown_18_;
};

struct Struct_ov005_02153954 {
    SafeAllocator unknown_0_;
    SafeAllocator unknown_14_;
    SafeAllocator unknown_28_[8];
    SafeAllocator unknown_c8_[16];
    SafeAllocator unknown_208_;
    char unknown_21c_[0xd84 - 0x21c];
    Struct_ov005_02155d6c unknown_d84_;
    char unknown_df4_[LOW_REGION(0x2d08 - 0xdf4, 0x2d90 - 0xdf4)];
    Struct_ov005_02153ba4 unknown_2d90_[24];
    Struct_ov005_02155d6c_2 unknown_3030_[24];
    Struct_ov005_02155d6c_2 unknown_3cf0_;
    short unknown_3d78_;
    char unknown_3d7a_[0x3d88 - 0x3d7a];
    char* unknown_3d88_;
    char* unknown_3d8c_;
    char* unknown_3d90_;
    char* unknown_3d94_;
    short unknown_3d98_[8];
    unsigned char unknown_3da8_;
    unsigned char unknown_3da9_;
    unsigned char unknown_3daa_;
    unsigned char unknown_3dab_;
    unsigned short unknown_3dac_;
    unsigned short unknown_3dae_;
    unsigned short unknown_3db0_;
    unsigned short unknown_3db2_;
    unsigned short unknown_3db4_;
    char unknown_3db6_;
    unsigned char unknown_3db7_;
    char unknown_3db8_[0x3dcc - 0x3db8];
    unsigned int unknown_3dcc_;
};

// USA: func_ov005_02155d6c
extern "C" ARM void func_ov005_02155d6c(EquipmentMenu* self) {
    unsigned char loading = self->loading_;
    if (loading != 0) {
        if (self->dragStep_ == 1) {
            EquipmentSlot* slot = &self->slots_[self->dragged_];
            if (slot->offset_ == 0) {
                MaybeInvoke0204719c_02047230((Foo02048004*)&self->dragModel_);
                CopyInternalFields0207df50((Foo0207df50*)&self->dragVramState_);
                VramState_Restore((char*)&self->dragVramState_);
                self->dragAllocator_.Reset();
                func_02047b40(&self->dragModel_, self->dragFile_, &self->dragAllocator_);
                VramState_Save((char*)&self->dragVramState_);
            }
            slot->offset_ = -1;
            slot->equipped_ = 0;
            memset(self->dragFile_, 0, 0x200);
            self->loading_--;
            self->dragStep_ = 0;
        } else if (self->unk_3da8 == 1) {
            EquipmentSlot* slot = &self->slots_[self->unk_3dac];
            VRAMManagerState* vramState = slot->vramState_;
            MenuModel* model = slot->model_;
            if (slot->offset_ == 0) {
                RunTwoCallbacksAndReset02155d38((Obj02155d38*)slot);
                VramState_Restore((char*)vramState);
                self->equippedAllocators_[self->unk_3dac].Reset();
                func_02047b40(model, self->itemFile_, &self->equippedAllocators_[self->unk_3dac]);
                slot->loadedItem_ = slot->item_;
                VramState_Save((char*)vramState);
            }
            var4->unknown_82_ = 0x1f;
            var4->unknown_80_ = 0x7fff;
            func_0203a46c((Struct_0203a46c*)var4, var2->unknown_c_, var2->unknown_10_, 0);
            var2->unknown_14_ = -1;
            var2->unknown_3_ = 0;
            memset(arg0->unknown_3d94_, 0, 0x200);
            arg0->unknown_3db7_--;
            arg0->unknown_3da8_ = 0;
        } else if (arg0->unknown_3da9_ == 1) {
            for (int var5 = 0; var5 < 8; var5++)
                arg0->unknown_28_[var5].Reset();
            arg0->unknown_3da9_++;
        } else if (arg0->unknown_3da9_ == 2) {
            signed char var6 = 0;
            int var7 = arg0->unknown_3dae_;
            for (; var7 < arg0->unknown_3db0_; var7++) {
                if (var6 == 4)
                    break;
                EquipmentSlot* slot = &self->slots_[i];
                VRAMManagerState* vramState = slot->vramState_;
                int offset = slot->offset_;
                MenuModel* model = slot->model_;
                if (offset >= 0) {
                    RunTwoCallbacksAndReset02155d38((Obj02155d38*)slot);
                    VramState_Restore((char*)vramState);
                    self->equippedAllocators_[i].Reset();
                    func_02047b40(model, self->equippedFiles_ + offset, &self->equippedAllocators_[i]);
                    slot->loadedItem_ = slot->item_;
                    VramState_Save((char*)vramState);
                }
                var11->unknown_82_ = 0x1f;
                var11->unknown_80_ = 0x7fff;
                func_0203a46c((Struct_0203a46c*)var11, var8->unknown_c_, var8->unknown_10_, 0);
                var8->unknown_14_ = -1;
                var8->unknown_3_ = 0;
                var6++;
            }
            memset(arg0->unknown_3d90_, 0, 0x800);
            arg0->unknown_3dae_ += var6;
        } else if (arg0->unknown_3da9_ == 3) {
            arg0->unknown_3db7_ = var0 - 1;
            arg0->unknown_3da9_ = 0;
        } else if (arg0->unknown_3daa_ == 1) {
            for (int var12 = 0; var12 < 16; var12++) {
                if (arg0->unknown_2d90_[var12 + 8].unknown_3_ == 0)
                    arg0->unknown_c8_[var12].Reset();
            }
            arg0->unknown_3daa_++;
        } else if (arg0->unknown_3daa_ == 3) {
            signed char var13 = 0;
            int var14 = arg0->unknown_3db2_;
            for (; var14 < arg0->unknown_3db4_; var14++) {
                if (var13 == 4)
                    break;
                Struct_ov005_02153ba4* var15 = &arg0->unknown_2d90_[var14];
                Struct_ov005_02155d6c* var16 = var15->unknown_4_;
                Struct_ov005_02155d6c_2* var17 = var15->unknown_8_;
                if (var15->unknown_3_ != 0) {
                    var13++;
                    continue;
                }
                int offset = slot->offset_;
                if (offset >= 0) {
                    RunTwoCallbacksAndReset02155d38((Obj02155d38*)slot);
                    VramState_Restore((char*)vramState);
                    self->itemAllocators_[i - 8].Reset();
                    func_02047b40(model, self->pageFiles_ + offset, &self->itemAllocators_[i - 8]);
                    slot->loadedItem_ = slot->item_;
                    VramState_Save((char*)vramState);
                }
                var17->unknown_82_ = 0x1f;
                var17->unknown_80_ = 0x7fff;
                func_0203a46c((Struct_0203a46c*)var17, var15->unknown_c_, var15->unknown_10_, 0);
                var15->unknown_14_ = -1;
                var15->unknown_3_ = 0;
                var13++;
            }
            memset(arg0->unknown_3d88_, 0, 0x800);
            arg0->unknown_3db2_ += var13;
            arg0->unknown_3daa_ = 2;
        } else if (arg0->unknown_3daa_ == 4) {
            arg0->unknown_3db7_ = var0 - 1;
            arg0->unknown_3daa_ = 0;
        }
        arg0->unknown_3dcc_ |= 2;
        return;
    }
    arg0->unknown_3dcc_ &= ~2;
}
