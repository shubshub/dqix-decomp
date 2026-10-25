#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov006_0215a384_12 = 4, Enum_ov006_0215a384_332 = 0x140 };
#else
enum { Enum_ov006_0215a384_12 = 0xc, Enum_ov006_0215a384_332 = 0x14c };
#endif

#include <Memory/SafeAllocator.h>
#include <Filesystem/BackgroundLoader.h>

struct Struct_0208358c_2 {
    void* unknown_0_;
    char unknown_4_[0x1c];
};

struct Struct_ov006_02157a60_2;
struct Struct_02071d60;

struct Struct_ov006_02156f04 {
    Struct_0208358c_2 unknown_0_;
    char unknown_20_[0x50];
    short unknown_70_;
};

struct Struct_ov006_021537d0 {
    short unknown_0_;
    short unknown_2_;
    short unknown_4_[3];
    char unknown_a_[0xa];
    short unknown_14_;
};

struct Struct_ov006_0215ffda {
    short unknown_0_[4];
};

struct Struct_ov006_02154614;

struct Struct_ov006_02157a60 {
    char unknown_0_[Enum_ov006_0215a384_12];
    SafeAllocator* unknown_c_;
    Struct_ov006_02154614* unknown_10_;
    char unknown_14_[0x20];
    Struct_ov006_021537d0* unknown_34_;
    char unknown_38_[Enum_ov006_0215a384_332-Enum_ov006_0215a384_12-0x2c];
    char unknown_14c_[0x17c-Enum_ov006_0215a384_332];
    Struct_ov006_02156f04 unknown_17c_[4];
    char unknown_34c_[0x8];
    int unknown_354_;
    char unknown_358_[0x20];
    short unknown_378_[3];
};

void InitObj_02157c78(Obj02157c78* ingredient);
void ItemRecord_Copy(Record020836e4* destination, Record020836e4* source);
Recipe* FindEntryByKey02071d60(List02071d60* table, int id);
void InitAndDispatch020deef4(int items, int file, int size, short* ids, short count);
extern "C" void func_ov006_02156f04(AlchemyPot* pot, PotIngredient* ingredients);

extern "C" const Struct_ov006_0215ffda data_ov006_0215ffda;

// USA: func_ov006_0215a384
extern "C" ARM unsigned char func_ov006_0215a384(AlchemyMenu* self, int great) {
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    if (loader->GetTaskStatus(self->task_)) {
        void* data;
        unsigned int size;
        loader->GetLoadedFileByID(self->task_, &data, &size);
        if (data != 0) {
            self->allocators_[8].Reset();
            ResultItems ids = data_ov006_0215ffda;
            Record020836e4 copies[4];
            unsigned char i;
            for (i = 0; i < 4; i++) {
                InitObj_02157c78((Obj02157c78*)&self->results_[i]);
                ItemRecord_Copy(&copies[i], &self->results_[i].entry_);
            }
            Struct_ov006_021537d0* var6 = arg0->unknown_34_;
            if (var6 != 0) {
                if (arg1)
                    var6 = func_02071d60((Struct_02071d60*)arg0->unknown_14c_, var6->unknown_14_);
                short var7 = var6->unknown_2_;
                arg0->unknown_17c_[0].unknown_70_ = var7;
                var3.unknown_0_[0] = var7;
            }
            short var8 = arg0->unknown_378_[0];
            arg0->unknown_17c_[1].unknown_70_ = var8;
            var3.unknown_0_[1] = var8;
            short var9 = arg0->unknown_378_[1];
            arg0->unknown_17c_[2].unknown_70_ = var9;
            var3.unknown_0_[2] = var9;
            short var10 = arg0->unknown_378_[2];
            arg0->unknown_17c_[3].unknown_70_ = var10;
            var3.unknown_0_[3] = var10;
            if (arg0->unknown_34_ != 0) {
                if (var3.unknown_0_[1] < 0) {
                    short var11 = arg0->unknown_34_->unknown_4_[0];
                    arg0->unknown_17c_[1].unknown_70_ = var11;
                    var3.unknown_0_[1] = var11;
                }
                if (var3.unknown_0_[2] < 0) {
                    short var12 = arg0->unknown_34_->unknown_4_[1];
                    arg0->unknown_17c_[2].unknown_70_ = var12;
                    var3.unknown_0_[2] = var12;
                }
                if (var3.unknown_0_[3] < 0) {
                    short var13 = arg0->unknown_34_->unknown_4_[2];
                    arg0->unknown_17c_[3].unknown_70_ = var13;
                    var3.unknown_0_[3] = var13;
                }
            }
            InitAndDispatch020deef4((int)copies, (int)data, size, ids.items_, 4);
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
        var0->RemoveTask(arg0->unknown_354_);
        arg0->unknown_354_ = -1;
    }
    if (arg0->unknown_354_ == -1)
        return 1;
    return 0;
}
