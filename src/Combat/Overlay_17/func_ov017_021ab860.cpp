#include <globaldefs.h>
#include "Resource/Script.h"
#include "Resource/GameResources.h"
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Combat/Main/CopyRecord0200fbb4.h"

#if defined(jpn)
#define func_0205ec34 func_0205ff20
#endif

#if defined(jpn)
enum { Enum_ov017_021ab860_1276 = 0x4fc, Enum_ov017_021ab860_1260 = 0x4ec,
       Enum_ov017_021ab860_17582 = 0x41fe, Enum_ov017_021ab860_17584 = 0x4200 };
#define data_ov017_021d83bc data_ov017_021d8c7c
#define data_ov017_021d78c4 data_ov017_021d7e2c
#define data_ov017_021d78a4 data_ov017_021d7e0c
#else
enum { Enum_ov017_021ab860_1804 = 0x70c, Enum_ov017_021ab860_1788 = 0x6fc,
       Enum_ov017_021ab860_17582 = 0x44ae, Enum_ov017_021ab860_17584 = 0x44b0 };
#endif

extern "C" void* func_02012fe4(void);
extern "C" void* memset(void* arg0, int arg1, unsigned int arg2);
extern "C" unsigned char* func_0205ec34(void);
extern "C" int func_0206dfb0(int arg0, unsigned char* arg1, int arg2);
extern "C" int func_020117f0(GameState* arg0);
struct Struct_ov017_021ab860;
extern "C" void func_ov017_021abb68(struct Struct_ov017_021ab860* arg0, unsigned char arg1);
struct Struct_02046a3c_2;
struct Struct_02046a3c;
extern "C" void func_02046a3c(struct Struct_02046a3c_2* arg0, struct Struct_02046a3c* arg1);
extern "C" int func_ov017_0219ff58(GameResources* arg0, int arg1, int arg2, int arg3);
extern "C" void* func_0200fd0c(GameState* arg0);
extern "C" void VectorizedMemset(void* dst, int val, int size);
extern "C" void func_ov017_0219e310(unsigned char* arg0, int arg1);
struct Struct_0201bdac_2;
struct Struct_0201bdac;
extern "C" void func_020469b4(struct Struct_0201bdac_2* arg0, struct Struct_0201bdac* arg1);

struct Struct_ov017_021ab860_2 {
    unsigned short unknown_0_;
    unsigned short unknown_2_;
    unsigned short unknown_4_;
    char unknown_6_[2];
    int unknown_8_;
};

struct Struct_ov017_021d83b0_2 {
    int unknown_0_;
    unsigned short unknown_4_;
    unsigned short unknown_6_;
    unsigned short unknown_8_;
    char unknown_a_[2];
    Vector3i unknown_c_;
    short unknown_18_;
};
extern Struct_ov017_021d83b0_2 data_ov017_021d83b0;
extern Vector3i data_ov017_021d83bc;
extern char data_ov017_021d78c4[];
extern Script::OpcodeLookupEntry data_ov017_021d78a4[];

struct Struct_ov017_021ab860_3 {
    char unknown_0_[0xc];
    int unknown_c_;
    Vector3i unknown_10_;
};

struct Struct_ov017_021ab860_4 {
    unsigned short unknown_0_;
    char unknown_2_[2];
    unsigned char unknown_4_;
    char unknown_5_[2];
    unsigned char unknown_7_;
    unsigned char unknown_8_;
    unsigned char unknown_9_;
    char unknown_a_;
    signed char unknown_b_;
    unsigned char unknown_c_;
    char unknown_d_[3];
    Vector3i unknown_10_;
    short unknown_1c_;
    short unknown_1e_;
    int unknown_20_, unknown_24_, unknown_28_, unknown_2c_;
    char unknown_30_[0x6c - 0x30];
    short unknown_6c_;
    char unknown_6e_[2];
};

// USA: func_ov017_021ab860
extern "C" ARM int func_ov017_021ab860(int arg0, unsigned char arg1) {
    GameState* gs = GameState::GetInstance();
    gs->GetResources();
    data_ov017_021d83b0.header = ((Active021ab860*)func_02012fe4())->header;
    data_ov017_021d83b0.key = 0;
    data_ov017_021d83b0.group = 0;
    data_ov017_021d83b0.entryId = 0;
    memset(&data_ov017_021d83bc, 0, sizeof(Vector3i));
    data_ov017_021d83b0.unknown_18_ = 0;
    unsigned char* var1 = func_0205ec34();
    if (func_0206dfb0((int)var1, var1 + 0x8c, 0x113a) != 0) {
        return 1;
    }
    if (func_020117f0(var0) != 0) {
        int var2;
        GameState* var3 = GameState::GetInstance();
        Struct_ov017_021ab860_2* var4 = (Struct_ov017_021ab860_2*)func_02012fe4();
        Struct_ov017_021ab860_3* var5 = (Struct_ov017_021ab860_3*)var3->GetGrottoStruct();
        if (var5 == NULL) {
            var2 = 0;
        } else {
            data_ov017_021d83b0.unknown_4_ = var4->unknown_4_;
            data_ov017_021d83b0.unknown_6_ = var4->unknown_0_;
            data_ov017_021d83b0.unknown_8_ = var5->unknown_c_;
            data_ov017_021d83b0.unknown_18_ = 0;
            data_ov017_021d83bc = var5->unknown_10_;
            data_ov017_021d83b0.unknown_c_.z += 0x2000;
            var2 = 4;
        }
        if (var2 == 0) {
            return 0;
        }
    } else {
        int var6;
        int var7;
        BackgroundLoader* var8 = BackgroundLoader::GetInstance();
        var8->MaybeFreeAllocations();
        var7 = var8->QueueLoadFile(data_ov017_021d78c4, NULL);
        if (var7 < 0) {
            var6 = 0;
        } else {
            while (var8->GetTaskStatus(var7) == 0) {
                var8->RemoveAllLocks();
            }
            if (var8->GetDetailedTaskStatus(var7) != 2) {
                var8->RemoveTask(var7);
                var6 = 0;
            } else {
                unsigned int var9;
                void* var10;
                var8->GetLoadedFileByID(var7, &var10, &var9);
                Script var11;
                var11.Initialize();
                var11.SetOpcodeLookup(data_ov017_021d78a4);
                var11.Load(var10, var9);
                var11.Execute();
                var8->RemoveTask(var7);
                var6 = 4;
            }
        }
        if (var6 == 0) {
            return 0;
        }
    }
    if (data_ov017_021d83b0.unknown_8_ != 0) {
        GameResources* var12 = GetGameResources();
        func_ov017_021abb68((struct Struct_ov017_021ab860*)var12->unknown_ptr_array_3afc[6], arg1);
        func_02046a3c((struct Struct_02046a3c_2*)var12->unknown_ptr_array_36fc[0],
                            (struct Struct_02046a3c*)var12->unknown_ptr_array_3afc[6]);
        int var13 = func_ov017_0219ff58(var12, 1, 0, 0);
        if (var13 != 0) {
            return 3;
        }
        if (var13 == 0) {
            Struct_ov017_021ab860_4* var14 = (Struct_ov017_021ab860_4*)func_0200fd0c(var0);
            VectorizedMemset(var14, 0, sizeof(Struct_ov017_021ab860_4));
            var14->unknown_4_ = 1;
            var14->unknown_8_ = 1;
            var14->unknown_9_ = 1;
            var14->unknown_b_ = -1;
            var14->unknown_20_ = -1;
            var14->unknown_24_ = -1;
            var14->unknown_28_ = -1;
            var14->unknown_2c_ = -1;
            var14->unknown_1e_ = -1;
            var14->unknown_c_ = 0;
            var14->unknown_6c_ = -1;
            var14->unknown_0_ = data_ov017_021d83b0.unknown_8_;
            var14->unknown_10_ = data_ov017_021d83bc;
            var14->unknown_1c_ = data_ov017_021d83b0.unknown_18_;
            var14->unknown_7_ = 1;
            func_0200fcfc(var0, var14);
        }
        struct Struct_0201bdac_2* var15;
        unsigned char* var16 = (unsigned char*)var12->unknown_ptr_array_36fc[4];
        var15 = (struct Struct_0201bdac_2*)var12->unknown_ptr_array_36fc[0];
        func_ov017_0219e310(var16, 0);
        func_020469b4(var15, (struct Struct_0201bdac*)var16);
        *(short*)((unsigned char*)var12 + Enum_ov017_021ab860_17582) = 0;
        *(short*)((unsigned char*)var12 + Enum_ov017_021ab860_17584) = 0;
        return 3;
    }
    return 0;
}
