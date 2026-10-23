#include <globaldefs.h>
#include <GameState/GameState.h>
#include <World/LootableContainer.h>
#include <Filesystem/BackgroundLoader.h>
#include <Resource/GameResources.h>
#include <World/Zone3D.h>

struct Struct_02012fa4;
struct Struct_02015ef4_2;
struct Struct_02015ef4_3;
struct Struct_020159c0_2;
struct Struct_0201099c_10;
struct Struct_02015ef4_4;
struct Struct_02015438;
struct Struct_02015ef4_5;
struct Struct_02015ef4;

#if defined(jpn)
#define data_020e6e88 data_020e772c
#define data_020ef20b data_020ef147
#endif

struct Struct_02015ef4_6 {
    unsigned short unknown_0_;
    short unknown_2_;
    unsigned short unknown_4_0_ : 2;
    unsigned short unknown_4_2_ : 2;
    unsigned short unknown_4_4_ : 12;
};

struct Struct_02015ef4_7 {
    char unknown_0_[0x10];
    unsigned int unknown_10_0_ : 20;
    unsigned int unknown_12_4_ : 8;
    unsigned int unknown_13_4_ : 4;
    short unknown_14_;
    short unknown_16_;
    short unknown_18_;
};

struct Struct_02015ef4_8 {
    Vector3i unknown_0_;
    short unknown_c_;
    unsigned short unknown_e_;
    unsigned short unknown_10_;
    short unknown_12_;
    signed char unknown_14_;
    char unknown_15_;
    unsigned char unknown_16_;
    unsigned char unknown_17_;
    unsigned char unknown_18_;
    unsigned char unknown_19_;
    char unknown_1a_[2];
    unsigned short unknown_1c_;
    char unknown_1e_[2];
    Struct_02012fa4* unknown_20_;
};

extern "C" void func_02047230(Struct_02012fa4*);
extern "C" int func_02015ae4(Struct_02015ef4_8*);
extern "C" int func_02015cd0(Struct_02015ef4_8*);
extern "C" void* func_02094d5c(Struct_02015ef4_3*, int);
extern "C" void func_020159c0(Struct_020159c0_2*, int);
extern "C" void* func_020dedd0(Struct_0201099c_10*, int);
extern "C" int func_020de234(Struct_02015ef4_4*, int);
extern "C" int sprintf(char*, const char*, ...);
extern "C" int func_02046b24(Struct_02015438**);
extern "C" void func_0204719c(void*);
void CopyState0207dfc8(State0207dfc8*, State0207dfc8*);
void VramState_Restore(char*);
void Forward02047b30(void*, int, int, int);
void VramState_Save(char*);
void* GetField0x3b0Value_020100bc(GameState*);
void ComputeTwoFromVec3_0202ec84(void*, Vec3copy0202ec84*, int*, int*);
void RenderFlaggedIndexedEntry(StructAt020473c8*, int);

struct Struct_020e6e88 {
    char unknown_0_[0x20];
};
extern Struct_020e6e88 data_020e6e88;
extern char data_020ef20b[];

// USA: func_02015ef4
extern "C" ARM int func_02015ef4(Zone3D* arg0, int arg1) {
    GameState* var0 = GameState::GetInstance();
    Struct_02015ef4_8* var1 = &reinterpret_cast<Struct_02015ef4_8*>(arg0->unknown_47c_)[arg1];
    LootableContainerManager* var2 = LootableContainerManager::GetMainInstance();
    BackgroundLoader* var3 = BackgroundLoader::GetInstance();
    int var4 = var0->GetProtagonist()->obj3D_.unknown_4_;
    int var5 = var0->GetUnknownGameObject()->obj3D_.unknown_4_;
    int var6 = 0;
    arg0->unk_23bc[1] = 0;
    if (var1->unknown_16_ == 0 || var1->unknown_16_ == 8) {
        if (var1->unknown_20_) {
            func_02047230((Struct_02012fa4*)var1->unknown_20_);
            var1->unknown_20_ = 0;
        }
        return -1;
    }
    unsigned int var7 = var0->GetEffectiveDeltaTime();
    int var8 = var0->GetTickCount() + 1;
    if (var1->unknown_16_ == 2) {
        arg0->unk_23bc[1] = 1;
        func_02015ae4(var1);
        Struct_02015ef4_6* var9 = 0;
        if (var1->unknown_17_ == 0 || var1->unknown_17_ == 1) {
            var9 = (Struct_02015ef4_6*)var2->GetContainerByID(var1->unknown_1c_, 0);
        } else if (var1->unknown_17_ == 2) {
            var9 = (Struct_02015ef4_6*)func_02094d5c((Struct_02015ef4_3*)arg0->unknown_struct_2724_, var1->unknown_1c_);
        }
        if (!var9) {
            var1->unknown_16_ = 8;
            return 0;
        }
        func_020159c0((Struct_020159c0_2*)arg0, (signed char)var4);
        if (var1->unknown_14_ == var5) {
            if (var9->unknown_4_2_ == 1) {
                Struct_020e6e88 var10 = data_020e6e88;
                var1->unknown_12_ = var3->QueueLoadFile(var10.unknown_0_, 0);
                var1->unknown_16_ = 4;
                return 0;
            } else if (var9->unknown_4_2_ == 2) {
                Struct_02015ef4_7* var11 = (Struct_02015ef4_7*)func_020dedd0((Struct_0201099c_10*)arg0->unknown_struct_2754_, var9->unknown_2_);
                if (var11 && var11->unknown_18_ != 0x5617) {
                    int var12 = func_020de234((Struct_02015ef4_4*)var11, 0);
                    char var13[0x50];
                    sprintf(var13, data_020ef20b, (signed char)var11->unknown_12_4_, var12);
                    var1->unknown_12_ = var3->QueueLoadFile(var13, 0);
                    var1->unknown_16_ = 4;
                    return 0;
                }
            }
        }
        entry->object = 0;
        entry->state = 5;
    } else if (entry->state == 4) {
        self->unk_23bc[1] = 1;
        func_02015ae4(entry);
        if (loader->GetTaskStatus(entry->taskID) == 0) return 0;
        void* file = 0;
        unsigned int size = 0;
        loader->GetLoadedFileByID(entry->taskID, &file, &size);
        GameResources* root = GetGameResources();
        HeadNode02046b24** head = (HeadNode02046b24**)root->unknown_ptr_array_36fc[0];
        if (file && GetHeadNodeIdOrMinusOne(head) != 4) {
            Foo02048004* slot = &reinterpret_cast<Foo02048004*>(self->unk_600)[entry->owner];
            entry->object = slot;
            func_0204719c(slot);
            entry->object->bit2 = 1;
            char saved[0x70];
            CopyState0207dfc8((State0207dfc8*)self->unknown_ptr_50_, (State0207dfc8*)saved);
            VramState_Restore(saved);
            Forward02047b30(entry->object, (int)file, size, (int)self->pAllocator_68_);
            VramState_Save(saved);
            *reinterpret_cast<int*>(self->unk_600 + 0x220) = 0x1f;
            entry->delay = 0;
        } else {
            var1->unknown_20_ = 0;
        }
        var3->RemoveTask(var1->unknown_12_);
        var1->unknown_12_ = -1;
        var1->unknown_16_ = 5;
    } else if (var1->unknown_16_ == 5) {
        arg0->unk_23bc[1] = 1;
        if (var1->unknown_10_ > 0xd) var6 = 1;
        if (func_02015ae4(var1)) {
            var1->unknown_10_ = 0;
            var1->unknown_16_ = 6;
        }
    } else if (var1->unknown_16_ == 6) {
        arg0->unk_23bc[1] = 1;
        var6 = 1;
        var1->unknown_10_ += var7;
        if (var1->unknown_10_ > 500) {
            var1->unknown_16_ = 7;
            var1->unknown_10_ = 0;
        }
    } else if (var1->unknown_16_ == 7) {
        arg0->unk_23bc[1] = 1;
        var6 = 1;
        if (var1->unknown_18_ == 1) {
            if (func_02015cd0(var1)) {
                var1->unknown_e_ = 0x647a;
                var1->unknown_16_ = 1;
                if (var1->unknown_20_) {
                    func_02047230((Struct_02012fa4*)var1->unknown_20_);
                    var1->unknown_20_ = 0;
                }
            }
        } else if (func_02015cd0(var1)) {
            var1->unknown_e_ = 0x4000;
            var1->unknown_16_ = 8;
            if (var1->unknown_20_) {
                func_02047230((Struct_02012fa4*)var1->unknown_20_);
                var1->unknown_20_ = 0;
            }
        }
    }
    if (static_cast<unsigned char*>(GetGameResources()->unknown_ptr_array_3afc[0x22])[3] != 0) var6 = 0;
    if (var1->unknown_20_ && var6) {
        arg0->unk_23bc[1] = 1;
        int var20 = 0;
        int var21 = 0;
        void* var22 = func_020100bc(var0);
        if (var22) func_0202ec84(var22, (Struct_02015ef4*)var1, &var20, &var21);
        var20 -= 12;
        var21 -= 0x28;
        if (var1->unknown_19_ < 10) var1->unknown_19_++;
        if (var1->unknown_16_ == 7 && var1->unknown_20_) {
            if (var8 < *reinterpret_cast<int*>(arg0->unknown_600_ + 0x220)) {
                *reinterpret_cast<int*>(arg0->unknown_600_ + 0x220) -= var8;
            } else {
                *reinterpret_cast<int*>(arg0->unknown_600_ + 0x220) = 0;
                var1->unknown_20_ = 0;
                return 0;
            }
        }
        if (var20 >= -24 && var20 < 256 && var21 >= -24 && var21 < 192) {
            int var23 = *reinterpret_cast<int*>(arg0->unknown_600_ + 0x220);
            var1->unknown_20_->unknown_82_ = var23;
            int var24 = var20;
            int var25 = var21 - var1->unknown_19_;
            Struct_02012fa4* var26 = var1->unknown_20_;
            var26->unknown_1c_[0] = var24 << 12;
            var26->unknown_1c_[1] = var25 << 12;
            var26->unknown_1c_[2] = 0;
            func_020473c8((Struct_02015ef4_2*)var1->unknown_20_, 1);
        }
    }
    return 0;
}
