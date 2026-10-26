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

struct Foo02048004;
struct Foo0207df50;
struct Vec3Target0203a46c;
struct Struct_ov005_021556e4_2;

struct MenuModel {
    char unk_0[0x80];
    short unknown_80_;
    short unknown_82_;
    char unknown_84_[4];
};

struct Struct_ov005_02155d6c {
    char unk_0[0x70];
};

extern "C" void SprSprite_Unload(Foo02048004* model);
extern "C" void VramState_Rewind(Foo0207df50* state);
extern "C" void VramState_Restore(char* state);
extern "C" void SprSprite_Parse(MenuModel* model, void* file, SafeAllocator* allocator);
extern "C" void VramState_Save(char* state);
extern "C" void SprSprite_SetPosition(Vec3Target0203a46c* model, int x, int y, int z);
extern "C" void func_ov005_02155d38(Struct_ov005_021556e4_2* slot);

struct Struct_ov005_02153ba4 {
    short item_;
    signed char count_;
    unsigned char unknown_3_;
    Struct_ov005_02155d6c* vramState_;
    MenuModel* model_;
    int x_;
    int y_;
    int unknown_14_;
    short unknown_18_;
};

struct EquipmentMenu {
    SafeAllocator allocator_;
    SafeAllocator modelAllocator_;
    SafeAllocator equippedAllocators_[8];
    SafeAllocator itemAllocators_[16];
    SafeAllocator dragAllocator_;
    char unknown_21c_[0xd84 - 0x21c];
    Struct_ov005_02155d6c dragVramState_;
    char unknown_df4_[LOW_REGION(0x2d08 - 0xdf4, 0x2d90 - 0xdf4)];
    Struct_ov005_02153ba4 slots_[24];
    MenuModel slotModels_[24];
    MenuModel dragModel_;
    short dragged_;
    char unknown_3d7a_[0x3d88 - 0x3d7a];
    char* pageFiles_;
    char* dragFile_;
    char* equippedFiles_;
    char* itemFile_;
    short unknown_3d98_[8];
    unsigned char unknown_3da8_;
    unsigned char unknown_3da9_;
    unsigned char unknown_3daa_;
    unsigned char unknown_3dab_;
    unsigned short unk_3dac;
    unsigned short unknown_3dae_;
    unsigned short unknown_3db0_;
    unsigned short unknown_3db2_;
    unsigned short unknown_3db4_;
    char unknown_3db6_;
    unsigned char loading_;
    char unknown_3db8_[0x3dcc - 0x3db8];
    unsigned int flags_;
};

// USA: func_ov005_02155d6c
extern "C" ARM void func_ov005_02155d6c(EquipmentMenu* self) {
    unsigned char loading = self->loading_;
    if (loading != 0) {
        if (self->unknown_3dab_ == 1) {
            Struct_ov005_02153ba4* slot = &self->slots_[self->dragged_];
            if (slot->unknown_14_ == 0) {
                SprSprite_Unload((Foo02048004*)&self->dragModel_);
                VramState_Rewind((Foo0207df50*)&self->dragVramState_);
                VramState_Restore((char*)&self->dragVramState_);
                self->dragAllocator_.Reset();
                SprSprite_Parse(&self->dragModel_, self->dragFile_, &self->dragAllocator_);
                VramState_Save((char*)&self->dragVramState_);
            }
            slot->unknown_14_ = -1;
            slot->unknown_3_ = 0;
            memset(self->dragFile_, 0, 0x200);
            self->loading_--;
            self->unknown_3dab_ = 0;
        } else if (self->unknown_3da8_ == 1) {
            Struct_ov005_02153ba4* slot = &self->slots_[self->unk_3dac];
            Struct_ov005_02155d6c* vramState = slot->vramState_;
            MenuModel* model = slot->model_;
            if (slot->unknown_14_ == 0) {
                func_ov005_02155d38((Struct_ov005_021556e4_2*)slot);
                VramState_Restore((char*)vramState);
                self->equippedAllocators_[self->unk_3dac].Reset();
                SprSprite_Parse(model, self->itemFile_, &self->equippedAllocators_[self->unk_3dac]);
                slot->unknown_18_ = slot->item_;
                VramState_Save((char*)vramState);
            }
            model->unknown_82_ = 0x1f;
            model->unknown_80_ = 0x7fff;
            SprSprite_SetPosition((Vec3Target0203a46c*)model, slot->x_, slot->y_, 0);
            slot->unknown_14_ = -1;
            slot->unknown_3_ = 0;
            memset(self->itemFile_, 0, 0x200);
            self->loading_--;
            self->unknown_3da8_ = 0;
        } else if (self->unknown_3da9_ == 1) {
            for (int i = 0; i < 8; i++)
                self->equippedAllocators_[i].Reset();
            self->unknown_3da9_++;
        } else if (self->unknown_3da9_ == 2) {
            signed char count = 0;
            int i = self->unknown_3dae_;
            for (; i < self->unknown_3db0_; i++) {
                if (count == 4)
                    break;
                Struct_ov005_02153ba4* slot = &self->slots_[i];
                Struct_ov005_02155d6c* vramState = slot->vramState_;
                int offset = slot->unknown_14_;
                MenuModel* model = slot->model_;
                if (offset >= 0) {
                    func_ov005_02155d38((Struct_ov005_021556e4_2*)slot);
                    VramState_Restore((char*)vramState);
                    self->equippedAllocators_[i].Reset();
                    SprSprite_Parse(model, self->equippedFiles_ + offset, &self->equippedAllocators_[i]);
                    slot->unknown_18_ = slot->item_;
                    VramState_Save((char*)vramState);
                }
                model->unknown_82_ = 0x1f;
                model->unknown_80_ = 0x7fff;
                SprSprite_SetPosition((Vec3Target0203a46c*)model, slot->x_, slot->y_, 0);
                slot->unknown_14_ = -1;
                slot->unknown_3_ = 0;
                count++;
            }
            memset(self->equippedFiles_, 0, 0x800);
            self->unknown_3dae_ += count;
        } else if (self->unknown_3da9_ == 3) {
            self->loading_ = loading - 1;
            self->unknown_3da9_ = 0;
        } else if (self->unknown_3daa_ == 1) {
            for (int i = 0; i < 16; i++) {
                if (self->slots_[i + 8].unknown_3_ == 0)
                    self->itemAllocators_[i].Reset();
            }
            self->unknown_3daa_++;
        } else if (self->unknown_3daa_ == 3) {
            signed char count = 0;
            int i = self->unknown_3db2_;
            for (; i < self->unknown_3db4_; i++) {
                if (count == 4)
                    break;
                Struct_ov005_02153ba4* slot = &self->slots_[i];
                Struct_ov005_02155d6c* vramState = slot->vramState_;
                MenuModel* model = slot->model_;
                if (slot->unknown_3_ != 0) {
                    count++;
                    continue;
                }
                int offset = slot->unknown_14_;
                if (offset >= 0) {
                    func_ov005_02155d38((Struct_ov005_021556e4_2*)slot);
                    VramState_Restore((char*)vramState);
                    self->itemAllocators_[i - 8].Reset();
                    SprSprite_Parse(model, self->pageFiles_ + offset, &self->itemAllocators_[i - 8]);
                    slot->unknown_18_ = slot->item_;
                    VramState_Save((char*)vramState);
                }
                model->unknown_82_ = 0x1f;
                model->unknown_80_ = 0x7fff;
                SprSprite_SetPosition((Vec3Target0203a46c*)model, slot->x_, slot->y_, 0);
                slot->unknown_14_ = -1;
                slot->unknown_3_ = 0;
                count++;
            }
            memset(self->pageFiles_, 0, 0x800);
            self->unknown_3db2_ += count;
            self->unknown_3daa_ = 2;
        } else if (self->unknown_3daa_ == 4) {
            self->loading_ = loading - 1;
            self->unknown_3daa_ = 0;
        }
        self->flags_ |= 2;
        return;
    }
    self->flags_ &= ~2;
}
