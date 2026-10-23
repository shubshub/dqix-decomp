#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include <Filesystem/FileIO.h>
#include <std_library_functions.h>

struct Struct_0201099c_10;
struct Struct_02015ef4_4;
struct Struct_0201099c_3;
struct Struct_0203a46c;
struct Struct_ov005_021556e4_2;

struct Struct_ov005_021556e4 {
    void* unknown_0_;
    int unknown_4_;
    unsigned int unknown_8_;
    unsigned int unknown_c_;
    unsigned int unknown_10_0_ : 20;
    unsigned int unknown_12_4_ : 8;
    unsigned int unknown_13_4_ : 4;
};

extern "C" void __clear(void* buffer, unsigned long size);
PartEntry* FindElementByKey020dedd0(Container020dedd0* items, int id);
int GetPreferredPackedField020de234(StructDE234_020de234* item, int a);
const char* KeyTable_Get(Container020e0310* texts, int id);
void SetVec3At0x1c(Vec3Target0203a46c* model, int x, int y, int z);
void RunTwoCallbacksAndReset02155d38(Obj02155d38* slot);

struct Struct_ov005_02153ba4 {
    short unknown_0_;
    signed char unknown_2_;
    unsigned char unknown_3_;
    void* unknown_4_;
    void* unknown_8_;
    int unknown_c_;
    int unknown_10_;
    int unknown_14_;
    short unknown_18_;
};

struct Struct_ov005_02153954 {
    char unknown_0_[0xdf4];
    Struct_0201099c_10* unknown_df4_;
    char unknown_df8_[R(0x2d08, 0x2d90) - 0xdf8];
    Struct_ov005_02153ba4 unknown_2d90_[24];
    char unknown_3030_[0x3cf0 - 0x3030];
    char unknown_3cf0_[0x88];
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

extern "C" void func_ov005_021553b4(Struct_ov005_02153954* arg0, int arg1, int* arg2, int* arg3);

// USA: func_ov005_021556e4
extern "C" ARM void func_ov005_021556e4(EquipmentMenu* self) {
    if (self->flags_ & 0x80) {
        if (self->dragStep_ == 0) {
            memset(self->dragFile_, 0, 0x200);
            EquipmentSlot* slot = &self->slots_[self->dragged_];
            slot->offset_ = -1;
            PartEntry* item = FindElementByKey020dedd0(self->items_, slot->item_);
            if (item != NULL) {
                char path[0x80];
                __clear(path, sizeof(path));
                int number = GetPreferredPackedField020de234((StructDE234_020de234*)item, 0);
                sprintf(path, KeyTable_Get((Container020e0310*)self->texts_, 0x7d1), (char)item->letter_, number);
                if (LoadFileIntoMemory(path, self->dragFile_, NULL))
                    slot->offset_ = 0;
                int x;
                int y;
                func_ov005_021553b4(self, self->dragged_, &x, &y);
                SetVec3At0x1c((Vec3Target0203a46c*)self->dragModel_, x << 12, y << 12, 0x2000);
                self->dragStep_++;
                self->loading_++;
            }
            arg0->unknown_3dcc_ &= ~0x80;
        }
    } else if (self->flags_ & 0x10) {
        if (self->unk_3da8 == 0) {
            memset(self->itemFile_, 0, 0x200);
            EquipmentSlot* slot = &self->slots_[self->unk_3dac];
            slot->offset_ = -1;
            PartEntry* item = FindElementByKey020dedd0(self->items_, slot->item_);
            if (item != NULL) {
                char path[0x80];
                __clear(path, sizeof(path));
                int number = GetPreferredPackedField020de234((StructDE234_020de234*)item, 0);
                sprintf(path, KeyTable_Get((Container020e0310*)self->texts_, 0x7d1), (char)item->letter_, number);
                if (LoadFileIntoMemory(path, self->itemFile_, NULL))
                    slot->offset_ = 0;
                self->unk_3da8++;
                self->loading_++;
            }
            arg0->unknown_3dcc_ &= ~0x10;
        }
    } else if (arg0->unknown_3dcc_ & 0x20) {
        if (arg0->unknown_3da9_ == 0) {
            for (int var10 = 0; var10 < 8; var10++) {
                func_ov005_02155d38((Struct_ov005_021556e4_2*)&arg0->unknown_2d90_[var10]);
                arg0->unknown_2d90_[var10].unknown_14_ = -1;
            }
            self->equippedStart_ = 0;
            self->equippedEnd_ = 8;
            self->equippedStep_++;
            self->loading_++;
        } else if (self->equippedStep_ == 2) {
            memset(self->equippedFiles_, 0, 0x800);
            int offset = 0;
            signed char count = 0;
            for (int i = self->equippedStart_; i < self->equippedEnd_; i++) {
                EquipmentSlot* slot = &self->slots_[i];
                slot->offset_ = -1;
                PartEntry* item = FindElementByKey020dedd0(self->items_, slot->item_);
                if (item != NULL) {
                    unsigned int size = 0;
                    char path[0x80];
                    __clear(path, sizeof(path));
                    int number = GetPreferredPackedField020de234((StructDE234_020de234*)item, 0);
                    sprintf(path, KeyTable_Get((Container020e0310*)self->texts_, 0x7d1), (char)item->letter_, number);
                    if (LoadFileIntoMemory(path, self->equippedFiles_ + offset, &size)) {
                        slot->offset_ = offset;
                        size = (size + 3) & ~3;
                        offset += size;
                    }
                }
                if (++var12 == 4)
                    break;
            }
            if (arg0->unknown_3dae_ == arg0->unknown_3db0_) {
                arg0->unknown_3da9_++;
                arg0->unknown_3dcc_ &= ~0x20;
            }
        }
    } else if (arg0->unknown_3dcc_ & 0x40) {
        if (arg0->unknown_3daa_ == 0) {
            for (int var19 = 8; var19 < 24; var19++) {
                Struct_ov005_02153ba4* var20 = &arg0->unknown_2d90_[var19];
                if (var20->unknown_3_ == 0) {
                    func_ov005_02155d38((Struct_ov005_021556e4_2*)var20);
                    var20->unknown_14_ = -1;
                }
            }
            arg0->unknown_3db2_ = 8;
            arg0->unknown_3db4_ = 24;
            arg0->unknown_3daa_++;
            arg0->unknown_3db7_++;
        } else if (arg0->unknown_3daa_ == 2) {
            memset(arg0->unknown_3d88_, 0, 0x800);
            int var21 = 0;
            signed char var22 = 0;
            for (int var23 = arg0->unknown_3db2_; var23 < arg0->unknown_3db4_; var23++) {
                Struct_ov005_02153ba4* var24 = &arg0->unknown_2d90_[var23];
                var24->unknown_14_ = -1;
                if (var24->unknown_3_ != 0)
                    continue;
                PartEntry* item = FindElementByKey020dedd0(self->items_, slot->item_);
                if (item != NULL) {
                    unsigned int size = 0;
                    char path[0x80];
                    __clear(path, sizeof(path));
                    int number = GetPreferredPackedField020de234((StructDE234_020de234*)item, 0);
                    sprintf(path, KeyTable_Get((Container020e0310*)self->texts_, 0x7d1), (char)item->letter_, number);
                    if (LoadFileIntoMemory(path, self->pageFiles_ + offset, &size)) {
                        slot->offset_ = offset;
                        size = (size + 3) & ~3;
                        offset += size;
                    }
                }
                if (++var22 == 4)
                    break;
            }
            arg0->unknown_3daa_++;
            if (arg0->unknown_3db2_ == arg0->unknown_3db4_) {
                for (int var29 = 8; var29 < 24; var29++)
                    arg0->unknown_2d90_[var29].unknown_3_ = 0;
                arg0->unknown_3daa_ = 4;
                arg0->unknown_3dcc_ &= ~0x40;
            }
        }
    }
}
