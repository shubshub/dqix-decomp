#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov006_0215a384_12 = 4, Enum_ov006_0215a384_332 = 0x140 };
#else
enum { Enum_ov006_0215a384_12 = 0xc, Enum_ov006_0215a384_332 = 0x14c };
#endif

#include <Memory/SafeAllocator.h>
#include <Filesystem/BackgroundLoader.h>

struct Record020836e4 {
    void* model_;
    char unk_4[0x1c];
};

struct Struct_ov006_02157a60_2;
struct Struct_02071d60;

struct Struct_ov006_02156f04 {
    Record020836e4 entry_;
    char unk_20[0x50];
    short item_;
};

struct Struct_ov006_021537d0 {
    short id_;
    short item_;
    short ingredients_[3];
    char unk_a[0xa];
    short unknown_14_;
};

struct Struct_ov006_0215ffda {
    short items_[4];
};

struct Struct_ov006_02154614;

struct Struct_ov006_02157a60 {
    char unk_0[Enum_ov006_0215a384_12];
    SafeAllocator* allocators_;
    Struct_ov006_02154614* pot_;
    char unk_14[0x20];
    Struct_ov006_021537d0* unknown_34_;
    char unknown_38_[Enum_ov006_0215a384_332-Enum_ov006_0215a384_12-0x2c];
    char table_[0x17c-Enum_ov006_0215a384_332];
    Struct_ov006_02156f04 results_[4];
    char unknown_34c_[0x8];
    int task_;
    char unknown_358_[0x20];
    short unknown_378_[3];
};

extern "C" void func_ov006_02157c78(Struct_ov006_02157a60_2* ingredient);
extern "C" void ItemRecord_Copy(Record020836e4* destination, Record020836e4* source);
extern "C" Struct_ov006_021537d0* func_02071d60(Struct_02071d60* table, int id);
extern "C" void func_020deef4(int items, int file, int size, short* ids, short count);
extern "C" void func_ov006_02156f04(Struct_ov006_02154614* arg0, Struct_ov006_02156f04* ingredients);

extern "C" const Struct_ov006_0215ffda data_ov006_0215ffda;

// USA: func_ov006_0215a384
extern "C" ARM unsigned char func_ov006_0215a384(Struct_ov006_02157a60* self, int arg1) {
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    if (loader->GetTaskStatus(self->task_)) {
        void* data;
        unsigned int size;
        loader->GetLoadedFileByID(self->task_, &data, &size);
        if (data != 0) {
            self->allocators_[8].Reset();
            Struct_ov006_0215ffda ids = data_ov006_0215ffda;
            Record020836e4 copies[4];
            unsigned char i;
            for (i = 0; i < 4; i++) {
                func_ov006_02157c78((Struct_ov006_02157a60_2*)&self->results_[i]);
                ItemRecord_Copy(&copies[i], &self->results_[i].entry_);
            }
            Struct_ov006_021537d0* var6 = self->unknown_34_;
            if (var6 != 0) {
                if (arg1)
                    var6 = func_02071d60((Struct_02071d60*)self->table_, var6->unknown_14_);
                short item = var6->item_;
                self->results_[0].item_ = item;
                ids.items_[0] = item;
            }
            short var8 = self->unknown_378_[0];
            self->results_[1].item_ = var8;
            ids.items_[1] = var8;
            short var9 = self->unknown_378_[1];
            self->results_[2].item_ = var9;
            ids.items_[2] = var9;
            short var10 = self->unknown_378_[2];
            self->results_[3].item_ = var10;
            ids.items_[3] = var10;
            if (self->unknown_34_ != 0) {
                if (ids.items_[1] < 0) {
                    short ingredient = self->unknown_34_->ingredients_[0];
                    self->results_[1].item_ = ingredient;
                    ids.items_[1] = ingredient;
                }
                if (ids.items_[2] < 0) {
                    short ingredient = self->unknown_34_->ingredients_[1];
                    self->results_[2].item_ = ingredient;
                    ids.items_[2] = ingredient;
                }
                if (ids.items_[3] < 0) {
                    short ingredient = self->unknown_34_->ingredients_[2];
                    self->results_[3].item_ = ingredient;
                    ids.items_[3] = ingredient;
                }
            }
            func_020deef4((int)copies, (int)data, size, ids.items_, 4);
            if (ids.items_[1] == ids.items_[2] && ids.items_[2] > 0)
                ItemRecord_Copy(&copies[2], &copies[1]);
            if (ids.items_[1] == ids.items_[3] && ids.items_[3] > 0)
                ItemRecord_Copy(&copies[3], &copies[1]);
            if (ids.items_[2] == ids.items_[3] && ids.items_[3] > 0)
                ItemRecord_Copy(&copies[3], &copies[2]);
            for (i = 0; i < 4; i++)
                ItemRecord_Copy(&self->results_[i].entry_, &copies[i]);
            func_ov006_02156f04(self->pot_, self->results_);
        }
        loader->RemoveTask(self->task_);
        self->task_ = -1;
    }
    if (self->task_ == -1)
        return 1;
    return 0;
}
