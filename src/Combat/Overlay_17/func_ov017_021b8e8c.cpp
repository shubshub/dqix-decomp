#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Memory/AllocatorUnion.h"
#include "Resource/GameResources.h"
#include "Resource/Brightness.h"

#if defined(jpn)
#define func_0205ec34 func_0205ff20
#define data_ov017_021d7c90 data_ov017_021d846c
#define data_ov017_021d7c95 data_ov017_021d8471
enum {
    Enum_ov017_021b8e8c_2112 = 0x860, Enum_ov017_021b8e8c_4 = 0x10, Enum_ov017_021b8e8c_6200 = 0x1708, Enum_ov017_021b8e8c_92 = 0x28, Enum_ov017_021b8e8c_96 = 0x2c,
    Enum_ov017_021b8e8c_2456 = 0x868, Enum_ov017_021b8e8c_2460 = 0x86c, Enum_ov017_021b8e8c_2464 = 0x870, Enum_ov017_021b8e8c_140 = 0x4c, Enum_ov017_021b8e8c_6578 = 0x17e2,
    Enum_ov017_021b8e8c_2400 = 0x800
};
#else
enum {
    Enum_ov017_021b8e8c_2112 = 0x840, Enum_ov017_021b8e8c_4 = 4, Enum_ov017_021b8e8c_6200 = 0x1838, Enum_ov017_021b8e8c_92 = 0x5c, Enum_ov017_021b8e8c_96 = 0x60,
    Enum_ov017_021b8e8c_2456 = 0x998, Enum_ov017_021b8e8c_2460 = 0x99c, Enum_ov017_021b8e8c_2464 = 0x9a0, Enum_ov017_021b8e8c_140 = 0x8c, Enum_ov017_021b8e8c_6578 = 0x19b2,
    Enum_ov017_021b8e8c_2400 = 0x960
};
#endif

struct Obj020397cc;
struct SePlayer;
struct Obj020d7aa0;
struct Vec3_020406f8;
struct Node020406f8;
struct Obj02033834;
struct Owner02040a90;
struct Struct0203cedc;
struct Entry0209854c;
struct TailList020469b4;
struct TailNode020469b4;
struct ListHead02046b60;
struct Obj0208b8c4;

struct Struct_ov017_021b8e8c {
    int unknown_0_;
    int unknown_4_;
    int unknown_8_;
};

struct Struct_ov017_021b8e8c_2 {
    unsigned short unknown_0_;
    unsigned char unknown_2_;
    unsigned char unknown_3_;
};

struct Struct_ov017_021b8e8c_3 {
    unsigned int unknown_0_;
    char unknown_4_[0x10];
    Struct_0203ca24* unknown_14_;
};

struct Struct_ov017_021b8e8c_4 {
    int unknown_0_;
    char unknown_4_[0x10];
    int unknown_14_;
    char unknown_18_[0x1c];
};

struct Struct_ov017_021b8e8c_5 {
    unsigned char unknown_0_;
    unsigned char unknown_1_;
    char unknown_2_[6];
    SafeAllocator unknown_8_;
    SafeAllocator unknown_1c_;
    unsigned char unknown_30_[0xe4];
    Struct_ov017_021b8e8c_2* unknown_114_;
    unsigned char* unknown_118_;
    int unknown_11c_;
    int unknown_120_;
    int unknown_124_;
    unsigned char unknown_128_;
    unsigned char unknown_129_;
    char unknown_12a_[2];
    int unknown_12c_;
    unsigned char unknown_130_;
    char unknown_131_[6];
    unsigned char unknown_137_;
    unsigned char unknown_138_;
    unsigned char unknown_139_;
};

extern "C" int func_ov017_021959b4(void);
extern "C" void func_ov017_021b8d80(Struct_ov017_021b8e8c_5* arg0);
extern "C" unsigned short* func_02012fe4(void);
extern "C" char* func_020421a0(void);
extern "C" void* func_0203cf4c(void);
extern "C" void* func_0205ec34(void);
int GetFieldIfFlag4_020100f8(char* obj);
void ReinitController02043204(char* obj);
extern "C" void func_02043124(char* obj);
void SetField0x23cTrue_020a27ac(void* obj);
void CancelPendingAction020397cc(Obj020397cc* obj, int arg1);
void SePlayer_Play(struct SePlayer* obj, int a, int b);
void* FindEntryPointerByKey0203df78(void* base, int key);
void SetByteField0x253_020397c0(void* obj);
Obj020d7aa0* GetGlobalResetObj020d7a50(void);
void TeardownAndResetState020d7aa0(struct Obj020d7aa0* obj);
int IsIdInRange020981e4(int a, int id);
int IsInRange1To63_02098268(int a, int x);
extern "C" Vec3_021b8e8c _Z29SelectVec3FromSources020406f8P13Vec3_020406f8P12Node020406f8(struct Node020406f8* n);
void SetVecYByMode02033834(struct Obj02033834* obj, int arg);
int FindEntryByKey0203dfdc(void* base, int key);
int GetFieldFromActiveChild(struct Owner02040a90* obj);
int GetField0x8_02040528(int* obj);
void SetCombatFlags0x5c(struct Struct0203cedc* obj, int b, int c);
int GetField5cb0Value_0201079c(char* obj);
int GetField5cb4Value_020107d0(char* obj);
Entry0209854c* FindEntryByFieldC0209854c(struct Entry0209854c* list, int target);
extern "C" void func_ov017_021a967c(TailNode020469b4* node, int id);
void AppendNodeToTail(TailList020469b4* list, TailNode020469b4* node);
int GetTableEntryOrZero_0218d2c4(int id);
void ClearIntAt0x23c_020a27b8(unsigned char* obj);
extern "C" void func_ov008_02184754(void* obj);
int GetNibble0206ec1c(int a, int b, unsigned char* c, unsigned int d);
void IncrementNibble0206ec64(int a, int b, unsigned char* c, unsigned int d);
extern "C" int func_ov017_021ba810(const void* code, unsigned int length, int id, int a3, int a4, int a5, int a6);
int AppendString02042058(char* dst, const char* src);
unsigned char* GetData02108d18_0206f504(void);
void Init0206f510(char* obj);
extern "C" int func_0206f550(unsigned char* s, char* in, char* out);
int CommandDispatch0206f6cc(unsigned char* obj, int arg);
int ListContainsId(ListHead02046b60* list, int id);
extern "C" void func_020a0cc4(unsigned int size);
void* AllocateAligned4_02012d88(AllocatorUnion* alloc, unsigned int size);
void InitAllocatorsAndBuffers0208b8c4(struct Obj0208b8c4* obj, SafeAllocator* allocator);
#if defined(jpn)
extern "C" void func_0204500c(void* arg0, char* arg1, int arg2);
#else
extern "C" void func_0204500c(void* arg0, char* arg1, int arg2, int arg3);
#endif
extern "C" void func_0208bb78(void* arg0, unsigned int arg1);
extern "C" int func_020649b0(void* arg0, int arg1, void* arg2);
extern "C" void func_0206f81c(void* arg0);
extern "C" void func_ov008_02184a3c(char* arg0, unsigned char arg1);
extern "C" void func_0208beb4(unsigned char* arg0);
extern "C" void func_ov017_021bd38c(void* arg0, int arg1, int arg2);

extern "C" void __clear(void* arg0, int arg1);

extern char g_sePlayer;
extern char data_ov017_021d7c90;
extern char data_ov017_021d7c95;
extern char data_ov017_021d7cad;
extern AllocatorUnion data_02114e20;

// USA: func_ov017_021b8e8c
extern "C" ARM void func_ov017_021b8e8c(Struct_ov017_021b8e8c_5* arg0, Struct_02038598_5* arg1) {
    if (arg0->unknown_114_ == NULL) {
        arg0->unknown_1_ = 1;
        return;
    }

    GameState* var0 = GameState::GetInstance();
    GameResources* var1 = GetGameResources();
    BackgroundLoader* var2 = BackgroundLoader::GetInstance();
    unsigned short* var3 = func_02012fe4();
    char* var4 = func_020421a0();
    void* var5 = func_0203cf4c();
    GameObject* var6 = var0->GetUnknownGameObject();
    void* var7 = func_0205ec34();
    void* var8;
    unsigned short var9 = *var3;
    var8 = (void*)func_020100f8((char*)var0);
    unsigned char* var10 = (unsigned char*)var1->unknown_ptr_44c4;

    if (func_ov017_021959b4() != 0) {
        func_ov017_021b8d80(arg0);
        func_02043204(var4);
        func_02043124(var4);
        func_020a27ac(var8);
        ClearFlags00(var1, 0x2000);
        arg0->unknown_1_ = 1;
        return;
    }

    func_020397cc((Struct_02018300_3*)var6, 1);

    switch (arg0->unknown_11c_) {
    case 0: {
        if (self->quiet == 0) {
            SePlayer_Play((SePlayer*)&g_sePlayer, 1, 0);
        }
        *(short*)((char*)var6 + 0xb2) = 0;
        Struct_ov017_021b8e8c var11 = *(Struct_ov017_021b8e8c*)((char*)var6 + 0x44);
        Struct_ov017_021b8e8c_3* var12 = (Struct_ov017_021b8e8c_3*)func_0203df78(var5, arg0->unknown_114_->unknown_0_);
        if (var12 == NULL) {
            func_020397c0(var6);
            if (var8 != NULL) {
                func_020a27ac(var8);
            }
            arg0->unknown_1_ = 1;
            break;
        }
        func_020d7aa0(func_020d7a50());
        arg0->unknown_12c_ = arg0->unknown_114_->unknown_0_;
        if (func_020981e4((int)((char*)var3 + Enum_ov017_021b8e8c_2112), var9) &&
            func_02098268((int)((char*)var3 + Enum_ov017_021b8e8c_2112), arg0->unknown_114_->unknown_0_)) {
            arg0->unknown_128_ = 1;
        }
        Struct_ov017_021b8e8c var13 = func_020406f8((Struct_0203de84_2*)var12);
        func_02033834((Struct_02033834_2*)var6, fix32ReduceAngle0To2Pi(fix32_Atan2(var13.unknown_0_ - var11.unknown_0_, var13.unknown_8_ - var11.unknown_8_)));
        *(int*)(var4 + Enum_ov017_021b8e8c_6200) = func_0203dfdc(var5, arg0->unknown_114_->unknown_0_);
        *(int*)(var4 + Enum_ov017_021b8e8c_6200 + 4) = func_02040a90((Struct_02040a90*)var12);
        char* var14 = (char*)func_02040528((int*)var12);
        if (var14 != NULL && strstr(var14 + Enum_ov017_021b8e8c_4, &data_ov017_021d7c90) != NULL && !(var12->unknown_0_ & 0x4000) &&
            var12->unknown_14_ != NULL) {
            func_0203cedc(var12->unknown_14_, 1, 0);
        }
        int var15 = func_0201079c((char*)var0);
        char var16[0xc];
        strcpy(var16, *(char**)((char*)var3 + 8) + 5);
        var16[3] = 0;
        func_020397cc((Struct_02018300_3*)var6, 1);
        if (arg0->unknown_128_ != 0) {
            Struct_0201bdac_2* var17;
            Struct_0201bdac* var18 = (Struct_0201bdac*)var1->unknown_ptr_array_3afc[0x22];
            var17 = (Struct_0201bdac_2*)var1->unknown_ptr_array_36fc[0];
            Struct_0203d028_12* var19 = func_0209854c((Struct_0203d028_12*)((char*)var3 + Enum_ov017_021b8e8c_2112), *(unsigned short*)var14);
            func_ov017_021a967c(var18, -1);
            *(Struct_0203d028_12**)((char*)var18 + 0x54) = var19;
            func_020469b4(var17, var18);
            arg0->unknown_1_ = 1;
            break;
        }
        char var20[0x50];
        sprintf(var20, &data_ov017_021d7c95, var16, func_ov017_0218d2c4(var15));
        if (var8 != NULL) {
            func_020a27b8((unsigned char*)var8);
        }
#if defined(jpn)
        arg0->unknown_120_ = var2->QueueLoadFile(var20, NULL);
#else
        char var21[0x10];
        __clear(var21, sizeof(var21));
        sprintf(var21, &data_ov017_021d7cad, *(unsigned short*)var14);
        arg0->unknown_120_ = var2->QueueLoadFileInGP2(var20, var21, NULL);
#endif
        arg0->unknown_11c_ = 1;
        break;
    }
    case 1: {
        if (arg0->unknown_128_ != 0) {
            func_ov008_02184754(arg0->unknown_118_);
        }
        if (var2->GetTaskStatus(arg0->unknown_120_) == 0) {
            break;
        }
        if (var2->GetDetailedTaskStatus(arg0->unknown_120_) != 2) {
            var2->RemoveTask(arg0->unknown_120_);
            arg0->unknown_120_ = -1;
            func_020397c0(var6);
            if (var8 != NULL) {
                func_020a27ac(var8);
            }
            arg0->unknown_1_ = 1;
            func_02043204(var4);
            func_02043124(var4);
            break;
        }
        void* var22;
        unsigned int var23;
        var2->GetLoadedFileByID(arg0->unknown_120_, &var22, &var23);
        int var24 = func_020107d0((char*)var0);
        unsigned short var25 = arg0->unknown_114_->unknown_0_;
        int var26 = func_0206ec1c((int)var10, var25, var10, 0x80);
        int var27 = func_0206ec1c((int)var10, var25, var10 + 0x80, 0x80);
        char* var28 = (char*)func_ov017_021ba810(var22, var23, var25, var24, arg0->unknown_124_, var26, var27);
        if (var28 == NULL) {
            var2->RemoveTask(arg0->unknown_120_);
            arg0->unknown_120_ = -1;
            func_020397c0(var6);
            if (var8 != NULL) {
                func_020a27ac(var8);
            }
            arg0->unknown_1_ = 1;
            func_02043204(var4);
            func_02043124(var4);
            break;
        }
        func_0206ec64((int)var10, var25, var10, 0x80);
        func_0206ec64((int)var10, var25, var10 + 0x80, 0x80);
        *(int*)(var4 + Enum_ov017_021b8e8c_2460) = arg0->unknown_114_->unknown_3_;
        char* var29 = *(char**)(var4 + Enum_ov017_021b8e8c_92);
        char* var30 = *(char**)(var4 + Enum_ov017_021b8e8c_96);
        memset(var29, 0, Enum_ov017_021b8e8c_2400);
        memset(var30, 0, Enum_ov017_021b8e8c_2400);
#if defined(jpn)
        Struct_ov017_021b8e8c_2* var31 = arg0->unknown_114_;
        if (strlen(var28) + strlen((char*)var31 + 4) >= Enum_ov017_021b8e8c_2400) {
            var28[Enum_ov017_021b8e8c_2400 - 1 - strlen((char*)var31 + 4)] = 0;
        }
#else
        if (strlen(var28) >= Enum_ov017_021b8e8c_2400) {
            var28[Enum_ov017_021b8e8c_2400 - 1] = 0;
        }
#endif
        func_02042058(var30, var28);
        var2->RemoveTask(arg0->unknown_120_);
        arg0->unknown_120_ = -1;
        unsigned char* var32 = func_0206f504();
        func_0206f510((char*)var32);
        if (func_0206f550(var32, var30, var29) != 0 && func_0206f6cc(var32, 0) == 0) {
            arg0->unknown_11c_ = 8;
            func_02094b34(func_02094a00(), 0x6f, 0x1388, 1, 1);
            break;
        }
        arg0->unknown_11c_ = 3;
        break;
    }
    case 8:
        if (func_02094b4c(func_02094a00()) != 0) {
            if (var8 != NULL) {
                func_020a27ac(var8);
            }
            if (func_02046b60(arg1, 0x2b) != 0 && var8 != NULL) {
                func_020a27b8((unsigned char*)var8);
            }
            arg0->unknown_11c_ = -1;
            arg0->unknown_1_ = 1;
        }
        break;
    case 3: {
        if (arg0->unknown_128_ != 0) {
            func_ov008_02184754(arg0->unknown_118_);
        }
        Struct_0208cb08* var33 = func_02094a00();
        if (arg0->unknown_128_ != 0) {
            func_02094b40(var33);
            func_02094b34(var33, 0x6e, 0x1ff, 0, 0);
        } else {
            func_02094b34(var33, 0x6f, 0x1388, 1, 1);
        }
        arg0->unknown_11c_ = 4;
        break;
    }
    case 4:
        if (arg0->unknown_128_ != 0) {
            func_ov008_02184754(arg0->unknown_118_);
        }
        if (func_02094b4c(func_02094a00()) != 0) {
            arg0->unknown_11c_ = 2;
        }
        break;
    case 2: {
        func_020a0cc4(0xa000);
        arg0->unknown_8_.CreateTypeA(func_02012d88(&data_02114e20, 0xa000), 0xa000);
        func_0208b8c4((Struct_0208b8c4*)arg0->unknown_30_, &arg0->unknown_8_);
        char* var34 = *(char**)(var4 + Enum_ov017_021b8e8c_92);
        int var35 = 1;
        switch (var9) {
        case 1:
            if (arg0->unknown_114_->unknown_0_ == 0xc8) {
                var35 = 0;
            }
            break;
        case 0xc3b5:
        case 0xc419:
        case 0xc47d:
        case 0xc4e1: {
            unsigned short var36 = arg0->unknown_114_->unknown_0_;
            if (var36 == 0xd0 || var36 == 0x63 || var36 == 0xd3) {
                var35 = 0;
            }
            break;
        }
        }
#if defined(jpn)
        func_0204500c(var4, var34, var35);
#else
        func_0204500c(var4, var34, var35, 0xe3);
#endif
        *(int*)(var4 + Enum_ov017_021b8e8c_2456) = 1;
        *(unsigned char*)(var4 + Enum_ov017_021b8e8c_6578) = 1;
        *(void**)(var4 + Enum_ov017_021b8e8c_140) = arg0->unknown_30_;
        *(int*)(var4 + Enum_ov017_021b8e8c_2460) = arg0->unknown_114_->unknown_3_;
        arg0->unknown_11c_ = 5;
        func_0208bb78(arg0->unknown_30_, var0->GetTickCount());
        if (func_02046b60((Struct_02038598_5*)var1->unknown_ptr_array_36fc[0], 0x17) == 0) {
            break;
        }
        if (var8 != NULL) {
            func_020a27ac(var8);
        }
        arg0->unknown_1_ = 1;
        func_ov017_021b8d80(arg0);
        if (func_0203df78(var5, arg0->unknown_114_->unknown_0_) == NULL) {
            break;
        }
        Struct_ov017_021b8e8c_4 var37;
        var37.unknown_0_ = arg0->unknown_114_->unknown_0_;
        var37.unknown_14_ = arg0->unknown_124_;
        if (func_020649b0(var7, 1, &var37) != 0) {
            func_0206f81c(&var37);
        }
        break;
    }
    case 5: {
        if (arg0->unknown_130_ != 0) {
            break;
        }
        func_0208bb78(arg0->unknown_30_, var0->GetTickCount());
        if (arg0->unknown_128_ != 0) {
            func_ov008_02184754(arg0->unknown_118_);
        }
        if (*(int*)(var4 + Enum_ov017_021b8e8c_2464) == 3) {
            func_02043204(var4);
            func_02043124(var4);
        }
        if (*(int*)(var4 + Enum_ov017_021b8e8c_2456) != 0) {
            break;
        }
        if (arg0->unknown_128_ != 0) {
            if (arg0->unknown_129_ == 0) {
                func_ov008_02184a3c((char*)arg0->unknown_118_, 0xd);
                arg0->unknown_129_++;
                break;
            }
            if (arg0->unknown_118_[0xb10] != 0xe) {
                break;
            }
            arg0->unknown_129_ = 0;
        }
        Struct_ov017_021b8e8c_3* var38 = (Struct_ov017_021b8e8c_3*)func_0203df78(var5, arg0->unknown_114_->unknown_0_);
        if (var38 == NULL) {
            break;
        }
        char* var39 = (char*)func_02040528((int*)var38);
        if (var39 != NULL && strstr(var39 + Enum_ov017_021b8e8c_4, &data_ov017_021d7c90) != NULL && !(var38->unknown_0_ & 0x4000) &&
            var38->unknown_14_ != NULL) {
            func_0203cedc(var38->unknown_14_, 1, 1);
        }
        arg0->unknown_11c_ = 6;
        break;
    }
    case 6: {
        if (*(short*)(arg0->unknown_30_ + 0xd2) < 0) {
            func_020397c0(var6);
            if (var8 != NULL) {
                func_020a27ac(var8);
            }
            arg0->unknown_1_ = 1;
            func_ov017_021b8d80(arg0);
        } else {
            arg0->unknown_11c_ = 7;
        }
        int var40;
        unsigned char* var41 = (unsigned char*)var1->unknown_ptr_array_36fc[14];
        var40 = 0;
        if (var41[2] != 0) {
            var40 = 1;
        }
        Struct_ov017_021b8e8c_4 var42;
        var42.unknown_0_ = arg0->unknown_114_->unknown_0_;
        var42.unknown_14_ = arg0->unknown_124_;
        if (func_020649b0(var7, 1, &var42) != 0) {
            func_0206f81c(&var42);
        }
        if (var40 == 0 && var41[2] != 0) {
            arg0->unknown_138_ = 1;
        }
        break;
    }
    case 7:
        func_0208bb78(arg0->unknown_30_, var0->GetTickCount());
        if (*(short*)(arg0->unknown_30_ + 0xd2) >= 0) {
            if (arg0->unknown_138_ == 0) {
                func_0208beb4(arg0->unknown_30_);
                break;
            }
            func_ov017_021bd38c(var1->unknown_ptr_array_36fc[14], (int)arg0->unknown_30_, (int)&arg0->unknown_8_);
            arg0->unknown_137_ = 1;
        }
        func_020397c0(var6);
        if (var8 != NULL) {
            func_020a27ac(var8);
        }
        arg0->unknown_1_ = 1;
        func_ov017_021b8d80(arg0);
        break;
    }
}
