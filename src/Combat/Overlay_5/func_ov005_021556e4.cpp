#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include <Filesystem/FileIO.h>
#include <std_library_functions.h>

struct ItemTable;
struct StructDE234_020de234;
struct Container020e0310;
struct Vec3Target0203a46c;
struct Struct_ov005_021556e4_2;

struct PartEntry {
    void* model_;
    int unk_4;
    unsigned int unk_8;
    unsigned int unk_c;
    unsigned int unknown_10_0_ : 20;
    unsigned int letter_ : 8;
    unsigned int unk_10_28 : 4;
};

extern "C" void __clear(void* buffer, unsigned long size);
extern "C" PartEntry* ItemTable_Find(ItemTable* items, int id);
extern "C" int ItemRecord_GetFileNumber(StructDE234_020de234* item, int a);
extern "C" const char* KeyTable_Get(Container020e0310* texts, int id);
extern "C" void SprSprite_SetPosition(Vec3Target0203a46c* model, int x, int y, int z);
extern "C" void func_ov005_02155d38(Struct_ov005_021556e4_2* slot);

struct Struct_ov005_02153ba4 {
    short item_;
    signed char count_;
    unsigned char unknown_3_;
    void* vramState_;
    void* model_;
    int x_;
    int y_;
    int unknown_14_;
    short unknown_18_;
};

struct EquipmentMenu {
    char unk_0[0xdf4];
    ItemTable* items_;
    char texts_[R(0x2d08, 0x2d90) - 0xdf8];
    Struct_ov005_02153ba4 slots_[24];
    char slotModels_[0x3cf0 - 0x3030];
    char dragModel_[0x88];
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

extern "C" void func_ov005_021553b4(EquipmentMenu* self, int slot, int* x, int* y);

// USA: func_ov005_021556e4
extern "C" ARM void func_ov005_021556e4(EquipmentMenu* self) {
    if (self->flags_ & 0x80) {
        if (self->unknown_3dab_ == 0) {
            memset(self->dragFile_, 0, 0x200);
            Struct_ov005_02153ba4* slot = &self->slots_[self->dragged_];
            slot->unknown_14_ = -1;
            PartEntry* item = ItemTable_Find(self->items_, slot->item_);
            if (item != NULL) {
                char path[0x80];
                __clear(path, sizeof(path));
                int number = ItemRecord_GetFileNumber((StructDE234_020de234*)item, 0);
                sprintf(path, KeyTable_Get((Container020e0310*)self->texts_, 0x7d1), (char)item->letter_, number);
                if (LoadFileIntoMemory(path, self->dragFile_, NULL))
                    slot->unknown_14_ = 0;
                int x;
                int y;
                func_ov005_021553b4(self, self->dragged_, &x, &y);
                SprSprite_SetPosition((Vec3Target0203a46c*)self->dragModel_, x << 12, y << 12, 0x2000);
                self->unknown_3dab_++;
                self->loading_++;
            }
            self->flags_ &= ~0x80;
        }
    } else if (self->flags_ & 0x10) {
        if (self->unknown_3da8_ == 0) {
            memset(self->itemFile_, 0, 0x200);
            Struct_ov005_02153ba4* slot = &self->slots_[self->unk_3dac];
            slot->unknown_14_ = -1;
            PartEntry* item = ItemTable_Find(self->items_, slot->item_);
            if (item != NULL) {
                char path[0x80];
                __clear(path, sizeof(path));
                int number = ItemRecord_GetFileNumber((StructDE234_020de234*)item, 0);
                sprintf(path, KeyTable_Get((Container020e0310*)self->texts_, 0x7d1), (char)item->letter_, number);
                if (LoadFileIntoMemory(path, self->itemFile_, NULL))
                    slot->unknown_14_ = 0;
                self->unknown_3da8_++;
                self->loading_++;
            }
            self->flags_ &= ~0x10;
        }
    } else if (self->flags_ & 0x20) {
        if (self->unknown_3da9_ == 0) {
            for (int i = 0; i < 8; i++) {
                func_ov005_02155d38((Struct_ov005_021556e4_2*)&self->slots_[i]);
                self->slots_[i].unknown_14_ = -1;
            }
            self->unknown_3dae_ = 0;
            self->unknown_3db0_ = 8;
            self->unknown_3da9_++;
            self->loading_++;
        } else if (self->unknown_3da9_ == 2) {
            memset(self->equippedFiles_, 0, 0x800);
            int offset = 0;
            signed char count = 0;
            for (int i = self->unknown_3dae_; i < self->unknown_3db0_; i++) {
                Struct_ov005_02153ba4* slot = &self->slots_[i];
                slot->unknown_14_ = -1;
                PartEntry* item = ItemTable_Find(self->items_, slot->item_);
                if (item != NULL) {
                    unsigned int size = 0;
                    char path[0x80];
                    __clear(path, sizeof(path));
                    int number = ItemRecord_GetFileNumber((StructDE234_020de234*)item, 0);
                    sprintf(path, KeyTable_Get((Container020e0310*)self->texts_, 0x7d1), (char)item->letter_, number);
                    if (LoadFileIntoMemory(path, self->equippedFiles_ + offset, &size)) {
                        slot->unknown_14_ = offset;
                        size = (size + 3) & ~3;
                        offset += size;
                    }
                }
                if (++count == 4)
                    break;
            }
            if (self->unknown_3dae_ == self->unknown_3db0_) {
                self->unknown_3da9_++;
                self->flags_ &= ~0x20;
            }
        }
    } else if (self->flags_ & 0x40) {
        if (self->unknown_3daa_ == 0) {
            for (int i = 8; i < 24; i++) {
                Struct_ov005_02153ba4* slot = &self->slots_[i];
                if (slot->unknown_3_ == 0) {
                    func_ov005_02155d38((Struct_ov005_021556e4_2*)slot);
                    slot->unknown_14_ = -1;
                }
            }
            self->unknown_3db2_ = 8;
            self->unknown_3db4_ = 24;
            self->unknown_3daa_++;
            self->loading_++;
        } else if (self->unknown_3daa_ == 2) {
            memset(self->pageFiles_, 0, 0x800);
            int offset = 0;
            signed char count = 0;
            for (int i = self->unknown_3db2_; i < self->unknown_3db4_; i++) {
                Struct_ov005_02153ba4* slot = &self->slots_[i];
                slot->unknown_14_ = -1;
                if (slot->unknown_3_ != 0)
                    continue;
                PartEntry* item = ItemTable_Find(self->items_, slot->item_);
                if (item != NULL) {
                    unsigned int size = 0;
                    char path[0x80];
                    __clear(path, sizeof(path));
                    int number = ItemRecord_GetFileNumber((StructDE234_020de234*)item, 0);
                    sprintf(path, KeyTable_Get((Container020e0310*)self->texts_, 0x7d1), (char)item->letter_, number);
                    if (LoadFileIntoMemory(path, self->pageFiles_ + offset, &size)) {
                        slot->unknown_14_ = offset;
                        size = (size + 3) & ~3;
                        offset += size;
                    }
                }
                if (++count == 4)
                    break;
            }
            self->unknown_3daa_++;
            if (self->unknown_3db2_ == self->unknown_3db4_) {
                for (int i = 8; i < 24; i++)
                    self->slots_[i].unknown_3_ = 0;
                self->unknown_3daa_ = 4;
                self->flags_ &= ~0x40;
            }
        }
    }
}
