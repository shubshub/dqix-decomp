#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "World/Object3D.h"

struct Struct_ov025_021e66cc {
    char unknown_0_[0x20];
    unsigned short unknown_20_;
};

struct Struct_ov025_021e66cc_2 {
    char unknown_0_[0x10];
    struct Struct_ov025_021e66cc* unknown_10_;
};

struct Struct_ov025_021e66cc_3 {
    char unknown_0_[8];
    unsigned int unknown_8_0_ : 4;
    unsigned int unknown_8_4_ : 5;
};

struct Struct_ov025_021e267c_3 {
    unsigned char unknown_0_;
    unsigned char unknown_1_;
    unsigned short unknown_2_;
    unsigned short unknown_4_;
    struct Struct_ov025_021e267c_3* unknown_8_;
};

struct Struct_ov025_021ef988_11 {
#if defined(jpn)
    char unknown_0_[4];
    char* unknown_c_;
    char unknown_8_[0x18];
#else
    char unknown1_0_[0xc];
    char* unknown_c_;
    char unknown_10_[0x10];
#endif
    int unknown_20_;
    int unknown_24_;
    int unknown_28_;
};

struct Struct_ov025_021ef9a8 { int unknown_0_; int unknown_4_; int unknown_8_; int unknown_c_; int unknown_10_; int unknown_14_; };

struct Struct_02054000;
struct Struct_ov025_021e267c_2;
struct Struct_0203d028_11;

extern "C" GameObject* func_0200ff1c(GameState* arg0, int arg1);
extern "C" Struct_ov025_021e66cc_3* func_02054000(struct Struct_02054000* arg0);
extern "C" void func_ov025_021e3158(struct Struct_ov025_021ef9a8* arg0);
extern "C" int func_ov025_021e2628(int arg0, int arg1);
extern "C" SafeAllocator* func_ov025_021e8a54(char* arg0);
extern "C" void func_ov025_021e8bac(struct Struct_ov025_021e267c_2* arg0, struct Struct_ov025_021e267c_3* arg1);
extern "C" void func_0203dafc(struct Struct_0203d028_11* arg0);

extern struct Struct_ov025_021ef988_11 data_ov025_021ef988;
extern struct Struct_ov025_021ef9a8 data_ov025_021ef9a8;
extern char data_ov025_021ef7be[];
extern char data_ov025_021ef811[];
extern char data_ov025_021ef81e[];

// USA: func_ov025_021e66cc
extern "C" ARM int func_ov025_021e66cc(void* arg0, struct Struct_ov025_021e66cc_2* arg1) {
    GameState* var0 = GameState::GetInstance();
    BackgroundLoader* var1 = BackgroundLoader::GetInstance();

    if (data_ov025_021ef988.unknown_20_ == 0) {
        GameObject* var2 = func_0200ff1c(var0, arg1->unknown_10_->unknown_20_);
        if (var2 == NULL) {
            func_ov025_021e3158(&data_ov025_021ef9a8);
            return 1;
        }
        Struct_ov025_021e66cc_3* var3 = func_02054000((struct Struct_02054000*)var2);
        if (var3 == NULL) {
            func_ov025_021e3158(&data_ov025_021ef9a8);
            return 1;
        }
        if (var3->unknown_8_4_ == 4) {
            data_ov025_021ef988.unknown_28_ = func_ov025_021e2628((int)data_ov025_021ef7be, (int)data_ov025_021ef811);
        } else if (var3->unknown_8_4_ == 0xb) {
            data_ov025_021ef988.unknown_28_ = func_ov025_021e2628((int)data_ov025_021ef7be, (int)data_ov025_021ef81e);
        } else {
            func_ov025_021e3158(&data_ov025_021ef9a8);
            return 1;
        }
        data_ov025_021ef988.unknown_20_++;
        return 0;
    }

    if (data_ov025_021ef988.unknown_20_ == 1) {
        int var4 = data_ov025_021ef988.unknown_28_;
        if (var1->GetTaskStatus(var4) == 0) {
            return 0;
        }
        if (var1->GetDetailedTaskStatus(var4) != 2) {
            var1->RemoveTask(var4);
            func_ov025_021e3158(&data_ov025_021ef9a8);
            return 1;
        }

        unsigned int var5;
        void* var6;
        var1->GetLoadedFileByID(var4, &var6, &var5);

        GameObject* var7 = var0->GetGameObjectByIndex(200);
        if (var7 == NULL) {
            var1->RemoveTask(var4);
            func_ov025_021e3158(&data_ov025_021ef9a8);
            return 1;
        }

        SafeAllocator* var8 = func_ov025_021e8a54(data_ov025_021ef988.unknown_c_);
        Struct_ov025_021e267c_3* var9 = (Struct_ov025_021e267c_3*)var8->Allocate(sizeof(Struct_ov025_021e267c_3));
        if (var9 == NULL) {
            var1->RemoveTask(var4);
            func_ov025_021e3158(&data_ov025_021ef9a8);
            return 1;
        }
        var9->unknown_0_ = 0;
        var9->unknown_2_ = 200;
        var9->unknown_4_ = 0;
        func_ov025_021e8bac((struct Struct_ov025_021e267c_2*)data_ov025_021ef988.unknown_c_, var9);

        ObjectArchiveLoadInfo info;
        ClearEightWords_0203dafc((struct Struct_203dafc*)&info);
        info.fileData = fileData;
        info.fileSize = length;
        info.unk_10 = 1;
        info.allocator = allocator;
        holder->obj3D_.LoadFromCCHROrCMOTArchive(&info, NULL);
        loader->RemoveTask(taskId);
        ResetStruct_021e3158(&data_ov025_021ef9a8);
        return 1;
    }

    return 0;
}
