#include "GameState/BattleRecordSnapshot.h"
#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"
#include "GameState/GameState.h"
#include "Resource/Brightness.h"

#if defined(jpn)
enum { Enum_ov004_02168b44_336 = 0x144, Enum_ov004_02168b44_29888 = 0x7280, Enum_ov004_02168b44_420 = 0x24, Enum_ov004_02168b44_29180 = 0x6fbc, Enum_ov004_02168b44_22172 = 0x543c, Enum_ov004_02168b44_108 = 0x8c, Enum_ov004_02168b44_15236 = 0x3964, Enum_ov004_02168b44_6498 = 0x1790, Enum_ov004_02168b44_6500 = 0x1794, Enum_ov004_02168b44_6536 = 0x17b8 };
#else
enum { Enum_ov004_02168b44_336 = 0x150, Enum_ov004_02168b44_29888 = 0x74c0, Enum_ov004_02168b44_420 = 0x1a4, Enum_ov004_02168b44_29180 = 0x71fc, Enum_ov004_02168b44_22172 = 0x569c, Enum_ov004_02168b44_108 = 0x6c, Enum_ov004_02168b44_15236 = 0x3b84, Enum_ov004_02168b44_6498 = 0x1962, Enum_ov004_02168b44_6500 = 0x1964, Enum_ov004_02168b44_6536 = 0x1988 };
#endif

struct S_e830;
int GetFieldPercentOver307_020a0870(BattleRecordSnapshot* p);
int GetFieldPercentOver232_020a08a4(BattleRecordSnapshot* p);
int GetFieldPercentOver944_020a08d8(BattleRecordSnapshot* p);
int GetFieldPercentOver448_020a090c(BattleRecordSnapshot* p);
int GetFieldAt0x7e_0201e830(struct S_e830* p);
int GetFieldAt0x0_0202ba00(int* obj);
int UpdatePlayClocks020ac4f8(int commit);
int LoadBattleBlock020ac4c0(void* dst);
int CopyOutBattleField0x7ac0_020ac0b4(void* dst);
void Set3DClearColor_020c5588(int color, int alpha, int depth, int polygonId, int fogEnable);
int MessageSystem_GetInstance(void);
void MessageSystem_Reset(char* obj);
void SetFieldsAt0x4And0x8_020e2d24(int* obj, int a, int b);
void* GetNodeIfType11_02168ad4(void* a, int id);
extern "C" void* Zone3D_GetInstance(void);
extern "C" void* func_0202ae18(void);
extern "C" void* func_ov011_021845f8(void* arg0, int arg1);
extern "C" void func_ov011_021848a0(void* arg0, int arg1);
#if defined(jpn)
extern "C" void* func_ov004_02168f08(void* arg0, int arg1);
#define NODE_LOOKUP_CALL func_ov004_02168f08
#else
extern "C" void* func_ov023_021f6524(void* arg0, int arg1);
#define NODE_LOOKUP_CALL func_ov023_021f6524
#endif

struct Struct_ov004_02168b44 {
    char unknown_0_[6];
    signed char unknown_6_;
    unsigned char unknown_7_;
    unsigned char unknown_8_;
    signed char unknown_9_;
};

struct Struct_ov004_02168b44_2 {
    unsigned int unknown_0_0_ : 14;
    unsigned int unknown_1_6_ : 17;
    unsigned int unknown_3_7_ : 1;
    unsigned int unknown_4_0_ : 14;
    unsigned int unknown_5_6_ : 17;
    unsigned int unknown_7_7_ : 1;
    unsigned int unknown_8_0_ : 7;
    unsigned int unknown_8_7_ : 7;
    unsigned int unknown_9_6_ : 7;
    unsigned int unknown_a_5_ : 7;
    unsigned int unknown_b_4_ : 4;
    unsigned int unknown_c_0_ : 10;
    unsigned int unknown_d_2_ : 14;
    unsigned int unknown_f_0_ : 7;
    unsigned int unknown_f_7_ : 1;
    unsigned int unknown_10_0_ : 9;
    unsigned int unknown_11_1_ : 14;
    unsigned int unknown_12_7_ : 7;
    unsigned int unknown_13_6_ : 2;
    short unknown_14_;
    unsigned char unknown_16_0_ : 1;
};

struct Struct_ov004_02168b44_3 {
#if !defined(jpn)
    char unknown_0_[0x180];
#endif
    unsigned int unknown_180_;
    unsigned int unknown_184_;
    unsigned int unknown_188_;
    unsigned short unknown_18c_;
    unsigned short unknown_18e_;
    unsigned char* unknown_190_;
    struct Struct_ov004_02168b44_2* unknown_194_;
    unsigned char unknown_198_;
    char unknown_199_[3];
    void* unknown_19c_;
    unsigned char unknown_1a0_;
};

struct Struct_ov004_02168b44_4 { char unknown_0_[Enum_ov004_02168b44_336]; struct Struct_ov004_02168b44_5* unknown_150_; };
struct Struct_ov004_02168b44_5 { char unknown_0_[0x49c]; unsigned char unknown_49c_0_ : 1; };
struct Struct_ov004_02168b44_6 { unsigned int unknown_0_; unsigned int unknown_4_0_ : 19; signed int unknown_6_3_ : 11; unsigned int unknown_7_6_ : 2; };
struct Struct_ov004_021700d4 { int unknown_0_, unknown_4_, unknown_8_; };
class Struct_ov004_02168b44_7 {
public:
    virtual void inline_ov004_02168b44();
    virtual void inline_ov004_02168b44_2();
    virtual void inline_ov004_02168b44_3();
    virtual void inline_ov004_02168b44_4();
    virtual void inline_ov004_02168b44_5();
    virtual void inline_ov004_02168b44_6();
    virtual void inline_ov004_02168b44_7();
    virtual void inline_ov004_02168b44_8(struct Struct_ov004_021700d4* arg0);
};

extern struct Struct_ov004_02168b44_3* data_ov004_02171030;
extern struct Struct_ov004_021700d4 data_ov004_021700d4;

// USA: func_ov004_02168b44
extern "C" ARM int func_ov004_02168b44(void* arg0) {
    GameState* var0 = GameState::GetInstance();
    void* var1 = func_0202ae18();
    struct Struct_ov004_02168b44* var2 = (struct Struct_ov004_02168b44*)((char*)var0 + Enum_ov004_02168b44_29888);
    int var3;
    for (var3 = 0; var3 < 3; var3++, var2++) {
        if (var2->unknown_6_ >= 4) {
            if (var2->unknown_7_ != 0 || var2->unknown_8_ != 0 || var2->unknown_9_ >= 0) return 1;
        }
    }
    int var4 = func_0202ba00((int*)var1);
    int var5 = *((unsigned char*)var1 + 0x100d);
    int var6 = 0;
    if ((var4 == 5 && var5 > 1) || var4 == 6) var6 = 1;
    func_020ac4f8(var6);

    data_ov004_02171030 = 0;
    void* var7 = func_ov011_021845f8(arg0, 0);
    if (!var7) return 0;
    struct Struct_ov004_02168b44_3* var8 =
        (struct Struct_ov004_02168b44_3*)((SafeAllocator*)((char*)var7 + 4))->Allocate(Enum_ov004_02168b44_420);
    data_ov004_02171030 = var8;
    if (!var8) return 0;
    var8->unknown_180_ = 0;
    var8->unknown_184_ = 0;
    var8->unknown_188_ = 0;
    var8->unknown_18c_ = 0;
    var8->unknown_198_ = 0;
    var8->unknown_190_ = 0;
    var8->unknown_194_ = 0;
    var8->unknown_19c_ = 0;
    var8->unknown_1a0_ = 1;
    data_ov004_02171030->unknown_190_ = (unsigned char*)var0 + Enum_ov004_02168b44_29180;

    Struct_02061c04 var9;
    int var10 = func_020ac4c0(&var9);
    unsigned int var11 = 0;
    func_020ac0b4(&var11);
    if (var11 > 0x1869f) var11 = 0x1869f;
    int var12 = 0;
    struct Struct_ov004_02168b44_4* var13 =
        (struct Struct_ov004_02168b44_4*)var0->GetProtagonist();
    if (var13) var12 = var13->unknown_150_->unknown_49c_0_;
    struct Struct_ov004_02168b44_6* var14 = (struct Struct_ov004_02168b44_6*)((char*)var0 + Enum_ov004_02168b44_22172);
    data_ov004_02171030->unknown_194_ =
        (struct Struct_ov004_02168b44_2*)((SafeAllocator*)((char*)var7 + 4))->Allocate(0x18);
    memset(data_ov004_02171030->unknown_194_, 0, 0x18);

    if (var10) {
        data_ov004_02171030->unknown_194_->unknown_0_0_ = var9.unknown_0_.unknown_0_.unknown_0_;
        data_ov004_02171030->unknown_194_->unknown_8_0_ = var9.unknown_0_.unknown_0_.unknown_2_;
        data_ov004_02171030->unknown_194_->unknown_4_0_ = var9.unknown_0_.unknown_4_.unknown_0_;
        data_ov004_02171030->unknown_194_->unknown_8_7_ = var9.unknown_0_.unknown_4_.unknown_2_;
        data_ov004_02171030->unknown_194_->unknown_5_6_ = var9.unknown_8_0_;
        data_ov004_02171030->unknown_194_->unknown_1_6_ = var11;
        data_ov004_02171030->unknown_194_->unknown_c_0_ = var9.unknown_10_0_;
        data_ov004_02171030->unknown_194_->unknown_10_0_ = var9.unknown_b_0_;
        data_ov004_02171030->unknown_194_->unknown_d_2_ = var9.unknown_d_6_;
        data_ov004_02171030->unknown_194_->unknown_11_1_ = var9.unknown_11_1_;
        data_ov004_02171030->unknown_194_->unknown_9_6_ =
            (unsigned char)func_020a0870(&var9);
        data_ov004_02171030->unknown_194_->unknown_a_5_ =
            (unsigned char)func_020a08a4(&var9);
        data_ov004_02171030->unknown_194_->unknown_f_0_ =
            (unsigned char)func_020a08d8(&var9);
        data_ov004_02171030->unknown_194_->unknown_12_7_ =
            (unsigned char)func_020a090c(&var9);
        data_ov004_02171030->unknown_194_->unknown_14_ = var14->unknown_6_3_;
        data_ov004_02171030->unknown_194_->unknown_16_0_ = var12;
    }

    data_ov004_02171030->unknown_19c_ = ((SafeAllocator*)((char*)var7 + 4))->Allocate(0x800);
    memset(data_ov004_02171030->unknown_19c_, 0, 4);

    void* base = Zone3D_GetInstance();
    if (!base) return 0;
    struct S_e830* rec = (struct S_e830*)((char*)base + entryOffset);
    if (!rec) return 0;
    data_ov004_02171030->f18c = GetFieldAt0x7e_0201e830(rec);

    unsigned int* var17 = (unsigned int*)GetGameResources();
    data_ov004_02171030->unknown_180_ = GetFlags00((GameResources*)var17);
    data_ov004_02171030->unknown_184_ = GetFlags04((GameResources*)var17);
    data_ov004_02171030->unknown_188_ = GetFlags08((GameResources*)var17);
    SetFlags00((GameResources*)var17, 4);
    SetFlags04((GameResources*)var17, 0x8de);
    func_020c5588(0, 0, 0x7fff, 0, 0);

    struct Struct_ov004_02168b44_7* var18 = (struct Struct_ov004_02168b44_7*)NODE_LOOKUP_CALL(arg0, 0x64);
    if (data_ov004_02171030->unknown_190_[0] <= 8) {
        *(short*)((char*)var18 + 0x5c) = 0;
        *(short*)((char*)var18 + 0x5e) = 1;
    } else {
        *(short*)((char*)var18 + 0x5c) = 0;
        *(short*)((char*)var18 + 0x5e) = 2;
    }

    unsigned char* var19 = *(unsigned char**)((char*)var17 + Enum_ov004_02168b44_15236);
    if (data_ov004_02171030->unknown_190_[0] == 0) {
        func_ov011_021848a0(arg0, 0x65);
    } else if (var19[9] != 0) {
        func_ov011_021848a0(arg0, 0x67);
        struct Struct_ov004_02168b44_7* var20 = (struct Struct_ov004_02168b44_7*)func_ov004_02168ad4(arg0, 2);
        struct Struct_ov004_021700d4 var21 = data_ov004_021700d4;
        var20->inline_ov004_02168b44_8(&var21);
    } else {
        func_ov011_021848a0(arg0, 0x64);
    }

    char* g = (char*)MessageSystem_GetInstance();
    MessageSystem_Reset(g);
    *(unsigned char*)(g + flagOffset) = 1;
    SetFieldsAt0x4And0x8_020e2d24((int*)(g + firstOffset), 9, 1);
    SetFieldsAt0x4And0x8_020e2d24((int*)(g + secondOffset), 0x19, 1);
    return 0;
}
