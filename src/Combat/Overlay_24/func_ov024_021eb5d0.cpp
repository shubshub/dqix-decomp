#include <globaldefs.h>
#include "Resource/ActionDataTables.h"

#if defined(jpn)
#define WORK_STRIDE_021eb5d0 0x488
#else
#define WORK_STRIDE_021eb5d0 0x448
#endif
#include "Combat/Overlay_0/GetCombatantByID.h"
struct Struct_0203d028_3 {
    unsigned short unknown_0_;
    char unknown_2_[0x132];
    struct BaseCombatStats* unknown_134_;
    struct ModifiableCombatStats* unknown_138_;
};
struct Struct_0203d028_2 {
    int unknown_0_;
    int unknown_4_;
    struct Struct_0203d028_3* unknown_8_[0xe9];
};

struct Struct_ov024_021eb5d0_15 {
    unsigned char unknown_0_0_ : 1;
    unsigned char unknown_0_1_ : 1;
    unsigned char unknown_0_2_ : 1;
    unsigned char unknown_0_3_ : 1;
    unsigned char unknown_0_4_ : 1;
    unsigned char unknown_0_5_ : 1;
    unsigned char unknown_0_6_ : 1;
    unsigned char unknown_0_7_ : 1;
};

struct Struct_ov024_021eb5d0_17 {
    unsigned int unknown_0_0_ : 12;
    unsigned int unknown_1_4_ : 20;
};

struct Struct_ov024_021eb5d0_18 {
    unsigned int unknown_0_0_ : 8;
    unsigned int unknown_1_0_ : 2;
    unsigned int unknown_1_2_ : 4;
    unsigned int unknown_1_6_ : 8;
    unsigned int unknown_2_6_ : 6;
    unsigned int unknown_3_4_ : 1;
    unsigned int unknown_3_5_ : 3;
};

struct Struct_ov024_021eb5d0 {
    unsigned int unknown_0_0_ : 5;
    unsigned int unknown_0_5_ : 7;
    unsigned int unknown_1_4_ : 4;
    unsigned int unknown_2_0_ : 16;
};

struct Struct_ov024_021eb5d0_2 {
    unsigned int unknown_0_0_ : 19;
    unsigned int unknown_2_3_ : 5;
    unsigned int unknown_3_0_ : 8;
};

struct Struct_ov024_021eb5d0_3 {
    unsigned int unknown_0_0_ : 10;
    unsigned int unknown_1_2_ : 10;
    unsigned int unknown_2_4_ : 10;
    unsigned int unknown_3_6_ : 2;
};

struct Struct_ov024_021eb5d0_4 {
    unsigned int unknown_0_0_ : 10;
    unsigned int unknown_1_2_ : 10;
    unsigned int unknown_2_4_ : 7;
    unsigned int unknown_3_3_ : 5;
};

struct Struct_ov024_021eaa50_2 {
    char unknown_0_[4];
    struct Struct_ov024_021eb5d0_17 unknown_4_;
    struct Struct_ov024_021eb5d0_18 unknown_8_;
    char unknown_c_[4];
    unsigned int unknown_10_;
    char unknown_14_[4];
    struct Struct_ov024_021eb5d0 unknown_18_;
    struct Struct_ov024_021eb5d0_2 unknown_1c_;
    char unknown_20_[8];
    struct Struct_ov024_021eb5d0_3 unknown_28_;
    struct Struct_ov024_021eb5d0_4 unknown_2c_;
};

struct Struct_ov024_021eb5d0_5 {
    char unknown_0_[0xe];
    short unknown_e_;
    unsigned short unknown_10_;
    char unknown_12_[5];
    unsigned char unknown_17_;
    char unknown_18_[4];
    struct Struct_ov024_021eb5d0_15 unknown_1c_;
    unsigned char unknown_1d_;
    char unknown_1e_[2];
    int unknown_20_;
};

struct Struct_ov024_021eb5d0_6 {
    unsigned long long unknown_0_;
    void* unknown_8_;
    char unknown_c_[0x13];
    unsigned char unknown_1f_;
};

struct Struct_ov024_021eb5d0_7 {
    char unknown_0_[0x18];
    float unknown_18_;
    short unknown_1c_;
    short unknown_1e_;
    short unknown_20_;
    unsigned short unknown_22_;
    unsigned short unknown_24_;
};

struct Struct_ov024_021eb5d0_8 {
    char unknown_0_[0x10];
    unsigned short unknown_10_;
};

struct Struct_ov024_021eb5d0_9 {
    short unknown_0_;
    unsigned short unknown_2_;
    char unknown_4_[4];
    unsigned char unknown_8_;
    char unknown_9_;
    unsigned char unknown_a_;
    struct Struct_ov024_021eb5d0_15 unknown_b_;
    struct Struct_ov024_021eb5d0_15 unknown_c_;
    char unknown_d_[3];
    struct Struct_ov024_021eb5d0_7* unknown_10_;
    char unknown_14_[4];
    unsigned short unknown_18_;
    char unknown_1a_[8];
    unsigned short unknown_22_;
    unsigned short unknown_24_;
};

struct Struct_ov024_021eaa50 {
    short unknown_0_;
    unsigned short unknown_2_;
    char unknown_4_[5];
    unsigned char unknown_9_;
};

struct Struct_ov024_021ea4d0 {
    int unknown_0_;
    struct Struct_ov024_021eb5d0_9* unknown_4_;
    struct Struct_ov024_021eb5d0_7* unknown_8_;
    struct Struct_ov024_021eb5d0_5* unknown_c_;
    struct Struct_ov024_021eb5d0_10* unknown_10_;
    int unknown_14_;
    int unknown_18_;
    float unknown_1c_;
    unsigned char unknown_20_[8];
    unsigned char unknown_28_[0x10];
    unsigned char unknown_38_[4];
    unsigned char unknown_3c_[8];
    short unknown_44_;
    char unknown_46_;
    unsigned char unknown_47_;
    char unknown_48_[0x20];
    struct Struct_ov024_021eb5d0_6* unknown_68_;
    unsigned char unknown_6c_;
    unsigned char unknown_6d_;
    unsigned char unknown_6e_;
    unsigned char unknown_6f_;
    unsigned char unknown_70_;
    unsigned char unknown_71_;
    unsigned char unknown_72_;
    unsigned char unknown_73_;
    unsigned char unknown_74_;
    unsigned char unknown_75_;
    unsigned char unknown_76_;
    unsigned char unknown_77_;
    unsigned char unknown_78_;
    unsigned char unknown_79_;
};

struct Struct_ov024_021eb5d0_6;
typedef struct Struct_ov024_021eb5d0_6* (Struct_ov024_021ea4d0::*Type_02000c9c_6)(short a, short b, struct Struct_ov024_021eaa50_2* rec, int dmg, int* flags, int cnt);

struct Struct_ov024_021eb5d0_11 {
    unsigned short unknown_0_;
    unsigned short unknown_2_;
    char unknown_4_[0x10];
    unsigned int unknown_14_;
    char unknown_18_[0xa];
    unsigned short unknown_22_;
    char unknown_24_[0x17];
    struct Struct_ov024_021eb5d0_15 unknown_3b_;
    struct Struct_ov024_021eb5d0_15 unknown_3c_;
};

struct Struct_ov024_021eb5d0_12 {
    char unknown_0_[0x138];
    struct Struct_ov024_021eb5d0_11* unknown_138_;

#if defined(jpn)
    char unknown_13c_[8];
#else
    char unknown1_13c_[0x14];
#endif
    unsigned char* unknown_150_;
};

struct Struct_ov024_021eb5d0_10 {
    char unknown_0_[0x8e01];
    unsigned char unknown_8e01_;
    unsigned char unknown_8e02_;
    char unknown_8e03_;
    short unknown_8e04_;
    signed char unknown_8e06_;
    char unknown_8e07_[0x31];
    int unknown_8e38_;
    float unknown_8e3c_;
    float unknown_8e40_;
    char unknown_8e44_[0x10];
    short unknown_8e54_;
    char unknown_8e56_[0x18];
    unsigned short unknown_8e6e_;
    char unknown_8e70_[0x24];
    unsigned char unknown_8e94_;
};

struct Struct_02000c9c_78 {
    unsigned char unknown_0_;
    char unknown_1_;
    short unknown_2_;
    short unknown_4_;
    short unknown_6_;
};

struct Struct_ov024_021eb5d0_13 {
    int unknown_0_;
    int unknown_4_;
};

struct Struct_ov024_021eb5d0_14 {
    unsigned int unknown_0_0_ : 1;
    unsigned int unknown_0_1_ : 1;
    unsigned int unknown_0_2_ : 30;
};

struct Struct_ov024_021eb5d0_16 {
    char unknown_0_[0x22];
    signed char unknown_22_;
};

#define IN_RANGE_021eb5d0(x) (((x) >= 0 && (x) <= 3) ? 1 : 0)

extern "C" Handler_021eb5d0 data_ov024_021ff508[0x51];
extern "C" Handler_021eb5d0 __ptmf_null;
extern "C" int data_ov024_02200144;
struct Struct_ov024_021fe718 {
    short unknown_0_[8];
};
extern "C" struct Struct_ov024_021fe718 data_ov024_021fe718;
extern "C" float data_ov024_021fe738[4];
extern "C" struct Struct_ov024_021fe718 data_ov024_021fe788;
struct Struct_ov024_021fe8f0 {
    short unknown_0_[32];
};
extern "C" struct Struct_ov024_021fe8f0 data_ov024_021fe8f0;

extern "C" struct Struct_ov024_021eaa50_2* func_02079e2c(char*, int);
extern "C" void* func_02079ee0(void* arg0, int arg1);
extern "C" void* memset(void* arg0, int arg1, unsigned int arg2);
extern "C" int func_ov000_021540c8(void*, void*, int);
extern "C" int func_ov000_0215440c(void* arg0, void* arg1, void* arg2);
extern "C" int func_ov024_021eaa50(struct Struct_ov024_021ea4d0* arg0, struct Struct_ov024_021eaa50* arg1, struct Struct_ov024_021eaa50_2* arg2, int arg3);
extern "C" short func_ov000_0215cda0(void* arg0);
extern "C" int func_ov024_021e8dc0(struct Struct_ov024_021ea4d0* arg0, int arg1, struct Struct_ov024_021eaa50_2* arg2, short* arg3, int arg4);
extern "C" int func_0202053c(void* arg0);
struct Random;
float NextRandomFloatScaled(Random*, float, float, int);
int NextRandomMax(Random*, int);
struct GameObject;
extern "C" int func_ov024_021eadfc(GameObject*);
extern "C" int func_ov000_0215a124(void* arg0, int arg1, int arg2);
extern "C" int func_02083b00(unsigned char* arg0, int arg1);
extern "C" unsigned int func_020dd290(void* arg0, unsigned int arg1);
extern "C" int func_020100a8(GameState*);
extern "C" int func_ov024_021eb47c(Struct_ov024_021ea4d0*, int);
extern "C" void func_020ac4c0(void* arg0);
struct Struct_020a0530;
extern "C" void func_020a0530(Struct_020a0530*, unsigned int);
struct Struct_020a01b8;
extern "C" void func_020a01b8(Struct_020a01b8*, unsigned int);
extern "C" void func_020ac494(void* arg0);
extern "C" int func_ov000_02159c58(void* arg0, int arg1);
struct Struct_020a0674;
extern "C" void func_020a0674(Struct_020a0674*, unsigned int);
struct Struct_020a017c;
extern "C" void func_020a017c(Struct_020a017c*, unsigned int);
struct Struct_ov000_0215440c;
extern "C" struct Struct_ov024_021eb5d0_5* func_ov000_021600f8(Struct_ov000_0215440c*, int);
struct Struct_ov024_021ea4d0_2;
extern "C" int func_ov024_021ea4d0(Struct_ov024_021ea4d0*, Struct_ov024_021ea4d0_2*);
extern "C" int func_ov024_021ea500(struct Struct_ov024_021ea4d0* arg0, struct Struct_ov024_021eaa50_2* arg1, int arg2);
extern "C" int func_ov000_02156cc4(void* arg0, int arg1, struct Struct_ov024_021eaa50_2* arg2, int arg3);
struct Struct_02010088;
extern "C" int func_02010088(Struct_02010088*);
extern "C" int func_ov024_021e6798(GameObject*);
extern "C" struct Struct_ov024_021eb5d0_5* func_ov000_0215e938(void* arg0);
struct Struct_ov000_0215fef0;
extern "C" void func_ov000_0215fef0(Struct_ov000_0215fef0*);
extern "C" short func_ov000_02154c68(void* arg0, int arg1, struct Struct_ov024_021eaa50_2* arg2);
extern "C" int func_ov024_021e9b74(struct Struct_ov024_021ea4d0* arg0, int arg1, short* arg2, struct Struct_ov024_021eaa50_2* arg3);
extern "C" int func_ov024_021e9f68(struct Struct_ov024_021ea4d0* arg0, short* arg1, short* arg2, struct Struct_ov024_021eaa50_2* arg3, unsigned char* arg4);
extern "C" int func_ov024_021ea584(struct Struct_ov024_021ea4d0* arg0, int arg1, int arg2, struct Struct_ov024_021eaa50_2* arg3);
extern "C" void func_ov000_0215cd80(void* arg0);
extern "C" int func_ov000_02156f98(void* arg0, int arg1, struct Struct_ov024_021eaa50_2* arg2);
extern "C" int func_ov000_02156e30(void* arg0, int arg1, int arg2, struct Struct_ov024_021eaa50_2* arg3);
extern "C" int func_ov000_02156648(void* arg0, int arg1, int arg2, struct Struct_ov024_021eb5d0_5* arg3, struct Struct_ov024_021eaa50_2* arg4, struct Struct_ov024_021eb5d0_9* arg5, int arg6);
int GetAttackBaseDamage(int*, int, int, int*, int*);
extern "C" void func_ov024_021da550(int* arg0);
extern "C" int func_ov024_021da55c(int* arg0, void* arg1, unsigned short arg2, unsigned short arg3, int arg4, struct Struct_ov024_021eaa50_2* arg5, int arg6);
extern "C" unsigned char* func_02053c6c(unsigned char*);
extern "C" float func_02074948(int arg0);
extern "C" int func_ov024_021e67c8(struct Struct_ov024_021ea4d0* arg0, int arg1, int arg2);
extern "C" int func_ov024_021e6948(struct Struct_ov024_021ea4d0* arg0, int arg1, int arg2, int arg3);
extern "C" int func_ov024_021e6a90(struct Struct_ov024_021ea4d0* arg0, int arg1, int arg2, struct Struct_ov024_021eaa50_2* arg3, unsigned short arg4);
struct Struct_02048150;
extern "C" int func_02086ef0(Struct_02048150*, int);
extern "C" void func_ov000_0215a8d4(unsigned char*, int);
struct Struct_ov024_021da670_6;
extern "C" int func_ov024_021da998(Struct_ov024_021da670_6*);
struct Struct_ov024_021dd028_5;
extern "C" int func_ov024_021dd260(Struct_ov024_021dd028_5*);
extern "C" void func_ov000_02159eac(void* arg0, void* arg1, unsigned char arg2);
extern "C" void func_ov000_0215a88c(void*, void*, int);
extern "C" void func_ov000_0215ffc4(void* arg0, void* arg1, int arg2);
extern "C" int func_ov000_021573a8(void* arg0, int arg1, int arg2, int arg3);
extern "C" struct Struct_ov024_021eb5d0_6* func_ov000_0215e958(void* arg0);
extern "C" void func_ov000_0215ccbc(void* arg0, struct Struct_ov024_021eb5d0_6* arg1, void* arg2, short arg3, short arg4, int arg5, unsigned long long arg6, unsigned char arg7);
extern "C" struct Struct_ov024_021eb5d0_8* func_ov000_0215fff4(void* arg0, int arg1, int arg2);
extern "C" int func_ov000_02157288(void* arg0, int arg1, struct Struct_ov024_021eaa50_2* arg2);
extern "C" void func_ov000_0215cd44(void* arg0, void* arg1, void* arg2, int arg3, unsigned long long arg4, int arg5);
struct Struct_ov024_021da9e0_4;
extern "C" void func_ov024_021eb4e4(Struct_ov024_021da9e0_4*, int);
extern "C" short func_ov000_0215a1d4(void* arg0, int arg1, int arg2, short* arg3);
extern "C" unsigned short func_ov024_021da644(int arg0, int arg1, int arg2);
extern "C" void func_ov000_0215fe84(void* arg0, void* arg1, int arg2);
extern "C" void func_ov024_021e4c04(struct Struct_ov024_021ea4d0* arg0, int arg1, int arg2, struct Struct_ov024_021eaa50_2* arg3, int arg4);
extern "C" void func_ov024_021e556c(struct Struct_ov024_021ea4d0* arg0, int arg1, int arg2, struct Struct_ov024_021eaa50_2* arg3, int arg4);
struct Struct_ov000_0215767c_4;
struct Struct_ov000_0215767c_5;
extern "C" void func_ov000_021600cc(Struct_ov000_0215767c_5*, Struct_ov000_0215767c_4*);
extern "C" int func_ov024_021eb1ec(void*, int);
extern "C" int func_ov024_021eb2b4(struct Struct_ov024_021ea4d0* arg0);
extern "C" int func_ov024_021eb344(struct Struct_ov024_021ea4d0* arg0, int arg1, int arg2);
extern "C" int func_ov000_0215fc60(char*);
extern "C" void func_ov024_021eb3e0(struct Struct_ov024_021ea4d0* arg0, int arg1);
extern "C" void func_ov000_0215af54(void* arg0, int arg1, int arg2);
struct Struct_0208978c;
extern "C" void func_0208978c(Struct_0208978c*, short);
extern "C" int func_ov000_0215eb1c(void* arg0, short* arg1, int arg2, int arg3);
extern "C" int func_ov024_021eb08c(struct Struct_ov024_021ea4d0* arg0, int arg1, int arg2, int arg3);
extern "C" void func_ov000_0215a908(void* arg0, int arg1);
extern "C" int func_ov000_02155f9c(void* arg0, int arg1, int arg2);
extern "C" void func_ov024_021e6060(struct Struct_ov024_021ea4d0* arg0, int arg1, struct Struct_ov024_021eaa50_2* arg2, int arg3);
extern "C" void func_ov024_021e6104(struct Struct_ov024_021ea4d0* arg0, int arg1, struct Struct_ov024_021eaa50_2* arg2);
extern "C" void func_ov024_021e62cc(struct Struct_ov024_021ea4d0* arg0, int arg1, struct Struct_ov024_021eaa50_2* arg2);
extern "C" int func_02085038(char*);
extern "C" int func_ov000_02159d24(void* arg0, int arg1);
struct Struct_ov000_0215440c_2;
extern "C" struct Struct_ov024_021eb5d0_7* func_ov000_02160094(Struct_ov000_0215440c_2*, int);
extern "C" void func_020881ac(void* arg0);
extern "C" void func_02088234(void* arg0);
extern "C" void func_ov024_021e80e4(struct Struct_ov024_021ea4d0* arg0, struct Struct_ov024_021eb5d0_9* arg1, struct Struct_ov024_021eaa50_2* arg2, int arg3, int arg4, struct Struct_ov024_021eaa50_2* arg5);
extern "C" unsigned short func_ov024_021e99d8(struct Struct_ov024_021ea4d0* arg0, struct Struct_ov024_021eb5d0_9* arg1, struct Struct_ov024_021eaa50_2* arg2);
extern "C" void* func_ov000_02160130();
extern "C" char* func_ov000_02160f08(void* arg0);
extern "C" int func_020ddb38(int arg0, int arg1, void* arg2, void* arg3);
extern "C" int func_ov000_0215fd24(int, int);
extern "C" void func_ov017_021c3fb4(unsigned short arg0, int arg1);
extern "C" void func_ov000_021584e8(void* arg0, void* arg1, void* arg2, void* arg3, int arg4, int arg5);
extern "C" void func_02083e28(unsigned char* arg0, int arg1);
void ApplyCombatantBuffs(int, int);
struct GameState;
extern "C" void* func_02010828(GameState*);

// USA: func_ov024_021eb5d0
extern "C" ARM void func_ov024_021eb5d0(struct Act_021eb5d0* self, struct World_021eb5d0* world, struct List_021eb5d0* list, struct Src_021eb5d0* src, unsigned char noCost) {
    struct Res_021eb5d0 res;
    unsigned long long pairA;
    unsigned long long pairB;
    short s6;
    short s4;
    short s2;
    unsigned char c0;
    struct Targets_021eb5d0 tgt32;
    struct Ids8_021eb5d0 ids1;
    struct Ids8_021eb5d0 ids2;
    unsigned char blkA[0xb0];
    unsigned char blkB[0xb0];
    int guard = data_ov024_02200144;
    if ((guard & 1) == 0) {
        data_ov024_021ff508[0x1e] = __ptmf_null;
        data_ov024_021ff508[0x22] = __ptmf_null;
        data_ov024_021ff508[0x3b] = __ptmf_null;
        data_ov024_021ff508[0x3c] = __ptmf_null;
        data_ov024_02200144 = guard | 1;
    }
    arg0->unknown_10_ = arg1;
    arg0->unknown_4_ = arg2;
    arg0->unknown_8_ = arg2->unknown_10_;
    struct Struct_0203d028_2* var13 = (Struct_0203d028_2*)GameState::GetInstance();
    Struct_02108e10* var14 = func_020797dc();
    struct Struct_ov024_021eaa50_2* var15 = func_02079e2c((char*)var14, arg0->unknown_4_->unknown_0_);
    if (var15 == 0) return;
    arg0->unknown_6d_ = 1;
    arg0->unknown_6e_ = 0;
    arg0->unknown_1c_ = 1.0f;
    arg0->unknown_47_ = 0;
    memset(arg0->unknown_20_, -1, 8);
    memset(arg0->unknown_28_, -1, 0x10);
    memset(arg0->unknown_38_, 0, 4);
    memset(arg0->unknown_3c_, 0, 8);
    arg0->unknown_4_->unknown_b_.unknown_0_3_ = 1;
    arg1->unknown_8e04_ = -1;
    arg1->unknown_8e06_ = -1;
    int var16 = var15->unknown_18_.unknown_0_5_;
    if (var16 >= 0x51) var16 = 0;
    if (data_ov024_021ff508[var16] == 0) var16 = 0;
    void* var17 = arg0->unknown_10_;
    const short var18 = arg0->unknown_4_->unknown_10_->unknown_20_;
    struct Struct_ov024_021eb5d0_12* var19 = (struct Struct_ov024_021eb5d0_12*)GetCombatantByID((int)var17, var18);
    short var20 = -1;
    if (data_ov024_021ff508[var16] == 0) return;
    arg0->unknown_4_->unknown_0_ = func_ov024_021eaa50(arg0, arg3, var15, arg4);
    arg0->unknown_4_->unknown_2_ = arg3->unknown_2_;
    var15 = func_02079e2c((char*)var14, arg0->unknown_4_->unknown_0_);
    if (var15 == 0) return;
    var16 = var15->unknown_18_.unknown_0_5_;
    if (var16 >= 0x51) var16 = 0;
    if (data_ov024_021ff508[var16] == 0) var16 = 0;
    void* var21 = func_02079ee0(var14, var15->unknown_8_.unknown_1_6_);
    var7 = data_ov024_021fe8f0;
    unsigned char var22;
    if (IN_RANGE_021eb5d0(var18)) var22 = func_ov000_021540c8(arg0->unknown_10_, arg3, (int)var7.unknown_0_);
    else var22 = func_ov000_0215440c(arg0->unknown_10_, arg3, var7.unknown_0_);
    if (var15->unknown_4_.unknown_0_0_ == 0xa8 || var15->unknown_4_.unknown_0_0_ == 0x14a) {
        if (var18 == var7.unknown_0_[0]) {
            arg3->unknown_0_ = 0x3ac;
            arg3->unknown_9_ = 1;
            arg0->unknown_4_->unknown_2_ = var15->unknown_4_.unknown_0_0_;
            arg0->unknown_4_->unknown_0_ = 0x3ac;
            var15 = func_02079e2c((char*)var14, arg0->unknown_4_->unknown_0_);
            if (var15 == 0) return;
            var16 = var15->unknown_18_.unknown_0_5_;
            if (var16 >= 0x51) var16 = 0;
            if (data_ov024_021ff508[var16] == 0) var16 = 0;
        }
    }
    if (var15->unknown_4_.unknown_0_0_ == 0xb7 || var15->unknown_4_.unknown_0_0_ == 0xb8) {
        if (var18 == var7.unknown_0_[0]) {
            arg3->unknown_0_ = 0x3ad;
            arg3->unknown_9_ = 1;
            arg0->unknown_4_->unknown_2_ = var15->unknown_4_.unknown_0_0_;
            arg0->unknown_4_->unknown_0_ = 0x3ad;
            var15 = func_02079e2c((char*)var14, arg0->unknown_4_->unknown_0_);
            if (var15 == 0) return;
            var16 = var15->unknown_18_.unknown_0_5_;
            if (var16 >= 0x51) var16 = 0;
            if (data_ov024_021ff508[var16] == 0) var16 = 0;
        }
    }
    if (var15->unknown_4_.unknown_0_0_ == 0x61) {
        var22 = 2;
        var7.unknown_0_[1] = var7.unknown_0_[0];
    }
    if (var15->unknown_4_.unknown_0_0_ == 0x79) {
        var7.unknown_0_[var22] = func_ov000_0215cda0(arg0->unknown_10_);
        var22 = var22 + 1;
    }
    arg0->unknown_78_ = 0;
    var22 = func_ov024_021e8dc0(arg0, var18, var15, var7.unknown_0_, var22);
    var0.unknown_4_ = 0;
    arg0->unknown_14_ = 0;
    arg0->unknown_44_ = -1;
    arg0->unknown_10_->unknown_8e38_ = 0;
    if (var15->unknown_4_.unknown_0_0_ == 0x200 || var15->unknown_4_.unknown_0_0_ == 0x20c) {
        struct Struct_ov024_021eb5d0_12* var23 = (struct Struct_ov024_021eb5d0_12*)(void*)func_0200ff1c((GameState*)var13, var18);
        switch (var15->unknown_4_.unknown_0_0_) {
        case 0x200:
            if (var23 != 0) {
                int var24 = func_0202053c(var23);
                float var25 = 1.0f + 0.01f * (11.0f + (float)(unsigned int)var24);
                if (var25 > 2.0f) var25 = 2.0f;
                arg0->unknown_10_->unknown_8e3c_ = NextRandomFloatScaled((Random*)var17, 1.1f, var25, 1);
                arg0->unknown_4_->unknown_10_->unknown_18_ = arg0->unknown_10_->unknown_8e3c_;
            }
            break;
        case 0x20c:
            arg0->unknown_10_->unknown_8e3c_ = NextRandomFloatScaled((Random*)var17, 1.5f, 3.0f, 1);
            arg0->unknown_10_->unknown_8e40_ = arg0->unknown_10_->unknown_8e3c_;
            break;
        }
    }
    arg0->unknown_6c_ = 0;
    if (var15->unknown_4_.unknown_0_0_ == 0x1ff || var15->unknown_4_.unknown_0_0_ == 0x20b) {
        int var26 = NextRandomMax((Random*)arg0->unknown_10_, 0x64);
        int var27 = 0;
        switch (var15->unknown_4_.unknown_0_0_) {
        case 0x1ff:
            var27 = 0x32;
            break;
        case 0x20b:
            var27 = 0x46;
            break;
        }
        if (var26 < var27) arg0->unknown_6c_ = 1;
    }
    unsigned char var28 = 0;
    arg0->unknown_71_ = var28;
    arg0->unknown_72_ = var28;
    arg0->unknown_73_ = var28;
    arg0->unknown_10_->unknown_8e54_ = var28;
    if (var19 != 0) {
        arg0->unknown_10_->unknown_8e54_ = var19->unknown_138_->unknown_2_;
        if (!IN_RANGE_021eb5d0(var18)) {
            if (var19->unknown_138_->unknown_2_ >= 0xff) arg0->unknown_6d_ = 0;
        }
        if (func_ov024_021eadfc((GameObject*)var19) != 0) arg0->unknown_6d_ = 0;
        if (arg4 != 0) arg0->unknown_6d_ = 0;
        if (var15->unknown_8_.unknown_3_4_ != 0) arg0->unknown_6d_ = 0;
        if (arg0->unknown_6d_ != 0) {
            var28 = 1;
            unsigned int var29 = var15->unknown_8_.unknown_0_0_;
            if (var29 >= 0xff) {
                var29 = var19->unknown_138_->unknown_2_;
                func_ov000_0215a124(arg0->unknown_10_, var18, var29);
            } else {
                if (IN_RANGE_021eb5d0(var18)) {
                    struct Struct_ov024_021eb5d0_12* var30 = (struct Struct_ov024_021eb5d0_12*)(void*)func_0200ff1c((GameState*)var13, var18);
                    if (var30 != 0 && func_02083b00(var30->unknown_150_, 0x106) != 0) var29 = func_020dd290(var30, var29);
                }
                func_ov000_0215a124(arg0->unknown_10_, var18, var29);
            }
        }
    }
    if (var18 == func_020100a8((GameState*)var13)) {
        if (func_ov024_021eb47c(arg0, var15->unknown_4_.unknown_0_0_) != 0) {
            func_020ac4c0(var10);
            func_020a0530((Struct_020a0530*)var10, 1);
            func_020a01b8((Struct_020a01b8*)(var10 + 0x68), 1);
            func_020ac494(var10);
        }
        if (func_ov000_02159c58(arg0->unknown_10_, (unsigned short)var15->unknown_4_.unknown_0_0_) != 0) {
            func_020ac4c0(var11);
            func_020a0674((Struct_020a0674*)var11, 1);
            func_020a017c((Struct_020a017c*)(var11 + 0x68), 1);
            func_020ac494(var11);
        }
    }
    if (arg4 != 0) {
        var22 = arg3->unknown_9_;
        for (int var31 = 0; var31 < arg3->unknown_9_; var31++) {
            var7.unknown_0_[var31] = func_ov000_021600f8((Struct_ov000_0215440c*)arg3, var31)->unknown_e_;
        }
    }
    int var32 = 0;
    arg0->unknown_18_ = 0;
    int var33 = 0;
    unsigned char var34 = 1;
    unsigned char var35 = var32;
    int var36 = var32;
    struct Struct_ov024_021eaa50_2* var37 = var15;
    if (func_ov024_021ea4d0(arg0, (Struct_ov024_021ea4d0_2*)var15) != 0) var36 = 1;
    if (func_ov024_021ea500(arg0, var15, var18) != 0) var36 = 1;
    if (var36 != 0) {
        var34 = 0;
        if (func_ov000_02156cc4(arg0->unknown_10_, var18, var15, var22) != 0) {
            var35 = 1;
            arg0->unknown_4_->unknown_a_ |= 1;
        }
    }
    int var38;
    short var39;
    unsigned char var40 = 0;
    arg0->unknown_79_ = 0;
    var39 = var40 - 1;
    for (var38 = var40; var38 < var22; var38++, arg0->unknown_18_ = arg0->unknown_18_ + 1) {
        if (func_02010088((Struct_02010088*)var19) != 0) break;
        if (func_ov024_021e6798((GameObject*)var19) != 0) break;
        if (var16 == 0x21 && var18 == var7.unknown_0_[var38]) continue;
        arg0->unknown_c_ = func_ov000_0215e938(arg0->unknown_10_);
        struct Struct_ov024_021eb5d0_5* var41 = arg0->unknown_c_;
        if (var41 == 0) return;
        func_ov000_0215fef0((Struct_ov000_0215fef0*)var41);
        var41->unknown_20_ = 0;
        arg0->unknown_c_->unknown_e_ = var7.unknown_0_[var38];
        int var42 = 0;
        arg0->unknown_c_->unknown_17_ = arg0->unknown_c_->unknown_17_ + 1;
        arg0->unknown_70_ = 1;
        arg0->unknown_6f_ = 1;
        arg0->unknown_74_ = 0;
        arg0->unknown_10_->unknown_8e6e_ = NextRandomMax((Random*)arg0->unknown_10_, 0x64);
        var7.unknown_0_[var38] = func_ov000_02154c68(arg0->unknown_10_, var7.unknown_0_[var38], var15);
        arg0->unknown_c_->unknown_e_ = var7.unknown_0_[var38];
        if (var15->unknown_4_.unknown_0_0_ == 0x79 && arg0->unknown_18_ == (var22 - 1)) {
            struct Struct_ov024_021eb5d0_12* var43 = (struct Struct_ov024_021eb5d0_12*)GetCombatantByID((int)arg0->unknown_10_, var7.unknown_0_[var38]);
            if (var43 == 0 || func_02010088((Struct_02010088*)var43) != 0 ||
                func_ov024_021e6798((GameObject*)var43) != 0) {
                var7.unknown_0_[var38] = func_ov000_0215cda0(arg0->unknown_10_);
                if (var7.unknown_0_[var38] < 0) continue;
                arg0->unknown_c_->unknown_e_ = var7.unknown_0_[var38];
            }
        }
        if (var16 != 0x12 && var16 != 0x21) {
            struct Struct_ov024_021eb5d0_12* var44 = (struct Struct_ov024_021eb5d0_12*)GetCombatantByID((int)arg0->unknown_10_, var7.unknown_0_[var38]);
            if (var44 == 0) continue;
            if (func_02010088((Struct_02010088*)var44) != 0) continue;
        }
        int var45 = 0;
        var3 = var18;
        var4 = var7.unknown_0_[var38];
        if (var39 != var7.unknown_0_[var38]) {
            arg0->unknown_79_ = 0;
            var39 = var4;
        }
        struct Struct_ov024_021eaa50_2* var46 = var15;
        int var47 = func_ov024_021e9b74(arg0, var3, &var4, var15);
        if (var47 != 0) {
            if (IN_RANGE_021eb5d0(var4)) arg0->unknown_4_->unknown_c_.unknown_0_2_ = 1;
            else arg0->unknown_4_->unknown_c_.unknown_0_5_ = 1;
        }
        if (arg0->unknown_79_ != 0 && var47 == 0) continue;
        arg0->unknown_76_ = 1;
        arg0->unknown_77_ = 0;
        var6 = 0;
        int var48 = var4;
        int var49 = func_ov024_021e9f68(arg0, &var3, &var4, var15, &var6);
        if (var49 != 0) var40 = 1;
        if (var3 != var18) {
            var37 = var15;
            if (IN_RANGE_021eb5d0(var48)) arg0->unknown_4_->unknown_c_.unknown_0_2_ = 1;
            else arg0->unknown_4_->unknown_c_.unknown_0_5_ = 1;
        }
        if (var49 == 0 && arg0->unknown_77_ == 0) func_ov024_021ea584(arg0, var3, var4, var15);
        else func_ov000_0215cd80(arg0->unknown_10_);
        if (var16 != 0x12 && var16 != 0x21) {
            struct Struct_ov024_021eb5d0_12* var50 = (struct Struct_ov024_021eb5d0_12*)GetCombatantByID((int)arg0->unknown_10_, var4);
            if (var50 == 0) continue;
            if (func_02010088((Struct_02010088*)var50) != 0) continue;
        }
        if (var49 != 0) {
            var46 = func_02079e2c((char*)var14, 1);
            var37 = var46;
            arg0->unknown_c_->unknown_1d_ = (arg0->unknown_c_->unknown_1d_ & ~1u) | 1;
            if (var46 != 0) var21 = func_02079ee0(var14, var46->unknown_8_.unknown_1_6_);
        }
        if (var46 == 0) var46 = var15;
        if (var49 != 0 || arg0->unknown_77_ != 0 || var6 != 0) {
            if (var34 != 0) {
                if (var15->unknown_4_.unknown_0_0_ == 0x70 || var15->unknown_4_.unknown_0_0_ == 0x48) {
                    if (NextRandomMax((Random*)arg0->unknown_10_, 2) == 0) arg0->unknown_4_->unknown_a_ |= 1;
                } else {
                    if (func_ov000_02156cc4(arg0->unknown_10_, var18, var15, var22) != 0) arg0->unknown_4_->unknown_a_ |= 1;
                }
            } else {
                if (var35 != 0) arg0->unknown_4_->unknown_a_ |= 1;
            }
            if (func_ov000_02156cc4(arg0->unknown_10_, var3, var46, var22) != 0) {
                arg0->unknown_c_->unknown_1c_.unknown_0_7_ = 1;
                if (var6 != 0) arg0->unknown_4_->unknown_a_ |= 0x40;
                else arg0->unknown_4_->unknown_a_ |= 0x20;
                if (var20 < 0) var20 = var3;
            }
        } else {
            if (var34 != 0) {
                if (func_ov000_02156cc4(arg0->unknown_10_, var3, var46, var22) != 0) {
                    arg0->unknown_c_->unknown_1c_.unknown_0_7_ = 1;
                    arg0->unknown_4_->unknown_a_ |= 1;
                }
            } else {
                arg0->unknown_c_->unknown_1c_.unknown_0_7_ = var35;
            }
        }
        unsigned char var51 = 0;
        if (func_ov000_02156f98(arg0->unknown_10_, var4, var46) != 0) {
            arg0->unknown_4_->unknown_a_ |= 4;
            arg0->unknown_c_->unknown_1c_.unknown_0_1_ = 1;
        } else if (func_ov000_02156e30(arg0->unknown_10_, var3, var4, var46) != 0) {
            arg0->unknown_4_->unknown_a_ |= 2;
            arg0->unknown_c_->unknown_1c_.unknown_0_2_ = 1;
        }
        arg0->unknown_10_->unknown_8e94_ = 0;
        unsigned char var52 = 0;
        if (var46->unknown_4_.unknown_0_0_ == 0x61 && arg0->unknown_18_ > 0) {
            var52 = 1;
            arg0->unknown_c_->unknown_1c_.unknown_0_1_ = 0;
            arg0->unknown_c_->unknown_1c_.unknown_0_2_ = 0;
            arg0->unknown_c_->unknown_1c_.unknown_0_7_ = 0;
        }
        unsigned char var53 = 0;
        if (var46->unknown_4_.unknown_0_0_ == 0x79 && arg0->unknown_18_ == (var22 - 1)) var53 = 1;
        if (func_ov000_02156648(arg0->unknown_10_, var3, var4, arg0->unknown_c_, var46, arg0->unknown_4_, var52) != 0) {
            int var54 = GetAttackBaseDamage((int*)arg0, var3, var4, (int*)var46, (int*)var21);
            func_ov024_021da550(&var0.unknown_0_);
            var45 = func_ov024_021da55c(&var0.unknown_0_, arg1, var3, var4, var22, var46, var54);
            if (var46->unknown_4_.unknown_0_0_ == 0x70 || var46->unknown_4_.unknown_0_0_ == 0x48) {
                if (var45 > 0) {
                    if (var49 != 0 || arg0->unknown_77_ != 0) arg0->unknown_4_->unknown_a_ |= 0x20;
                    else arg0->unknown_4_->unknown_a_ |= 1;
                    if (var20 < 0) var20 = var3;
                    arg0->unknown_c_->unknown_1c_.unknown_0_7_ = 1;
                    if (IN_RANGE_021eb5d0(var4)) {
                        struct Struct_ov024_021eb5d0_12* var55 = (struct Struct_ov024_021eb5d0_12*)(void*)func_0200ff1c((GameState*)var13, var4);
                        unsigned char* var56 = func_02053c6c((unsigned char*)var55);
                        if (var55 != 0 && var56 != 0) {
                            if (*(short*)(var56 + 0x2cc) > 0) {
                                if (func_02083b00(var55->unknown_150_, 0x28) != 0) {
                                    arg0->unknown_4_->unknown_a_ |= 2;
                                    arg0->unknown_c_->unknown_1c_.unknown_0_2_ = 1;
                                }
                            }
                        }
                    }
                } else {
                    var45 = 0;
                }
            }
            if ((var46->unknown_10_ & 0x20000) != 0) {
                unsigned char var57 = 1;
                if (var46->unknown_4_.unknown_0_0_ == 1 || var46->unknown_4_.unknown_0_0_ == 2) {
                    if (IN_RANGE_021eb5d0(var3)) {
                        struct Struct_ov024_021eb5d0_12* var58 = (struct Struct_ov024_021eb5d0_12*)(void*)func_0200ff1c((GameState*)var13, var3);
                        if (var58 != 0) {
                            struct Struct_ov024_021eb5d0_14* var59 = (struct Struct_ov024_021eb5d0_14*)(var58->unknown_150_ + 0x2f4);
                            if (var59 != 0) {
                                if (var59->unknown_0_1_ == 0) {
                                    if (var59->unknown_0_0_ == 0) var57 = 0;
                                }
                            }
                        }
                    } else {
                        var57 = 0;
                    }
                }
                if (var57 != 0) {
                    float var60 = func_02074948((signed char)var38);
                    var45 = (int)((float)var45 * var60);
                }
                if (var46->unknown_4_.unknown_0_0_ == 0x79) var45 = (int)(0.8f * (float)var45);
            }
            if (var52 != 0) {
                var45 = func_ov024_021e67c8(arg0, var3, var4);
            } else if (var53 != 0) {
                var45 = func_ov024_021e6948(arg0, var4, var33, (var22 - 1));
            } else {
                var45 = func_ov024_021e6a90(arg0, var3, var4, var46, (unsigned short)var45);
            }
            if (var46->unknown_4_.unknown_0_0_ == 0x79 && arg0->unknown_18_ != (var22 - 1) && var45 > 0) {
                if (var33 <= 0) var33 = var45;
            }
            var51 = 1;
            if (arg0->unknown_c_->unknown_1c_.unknown_0_1_ != 0 || arg0->unknown_c_->unknown_1c_.unknown_0_2_ != 0) {
                var51 = 0;
                var45 = 0;
                func_ov000_0215cd80(arg0->unknown_10_);
                void* var61 = func_02010828((GameState*)(Struct_0203d028_2*)GameState::GetInstance());
                if (arg0->unknown_c_->unknown_1c_.unknown_0_2_ != 0) {
                    if (func_02086ef0((Struct_02048150*)var61, var4) != 0) {
                        func_ov000_0215a8d4((unsigned char*)arg0->unknown_10_, 6);
                    }
                }
            }
        } else {
            if (arg0->unknown_76_ != 0 && (var46->unknown_10_ & 0x2000) != 0) {
                struct Struct_ov024_021eb5d0_12* var62 = (struct Struct_ov024_021eb5d0_12*)GetCombatantByID((int)arg0->unknown_10_, var3);
                if (var62 != 0) {
                    if (func_ov024_021da998((Struct_ov024_021da670_6*)var62) != 0 ||
                        func_ov024_021dd260((Struct_ov024_021dd028_5*)var62) != 0) {
                        arg0->unknown_47_ = 1;
                        if (func_ov024_021dd260((Struct_ov024_021dd028_5*)var62) != 0) arg0->unknown_47_ = 2;
                    }
                }
            }
            func_ov000_0215cd80(arg0->unknown_10_);
        }
        arg0->unknown_75_ = 1;
        struct Struct_ov024_021eb5d0_6* var63 = (arg0->*data_ov024_021ff508[var16])(var3, var4, var46, var45, &var0.unknown_4_, var51);
        if (var63 != 0) {
            int var64 = 0;
            int var65 = 0;
            if (arg0->unknown_c_->unknown_1c_.unknown_0_2_) { var64 = 6; var65 = 0x96; }
            if (arg0->unknown_c_->unknown_1c_.unknown_0_6_) { var64 = 0xc; var65 = 0x255; }
            if (arg0->unknown_c_->unknown_1c_.unknown_0_1_) { var64 = 5; var65 = 0x97; }
            if (arg0->unknown_c_->unknown_1c_.unknown_0_4_) { var64 = 0xa; var65 = 0x1b9; }
            if (arg0->unknown_c_->unknown_1c_.unknown_0_5_) { var64 = 0x26; var65 = 0x24d; }
            if (arg0->unknown_c_->unknown_1c_.unknown_0_3_) { var64 = 9; var65 = 0x2b; }
            if (var64 > 0) func_ov000_02159eac(arg0->unknown_10_, var63, var64);
            if (var65 > 0) func_ov000_0215a88c(arg0->unknown_10_, var63, (unsigned short)var65);
            func_ov000_0215ffc4(arg0->unknown_c_, var63, 0);
            arg0->unknown_10_->unknown_8e02_ = arg0->unknown_10_->unknown_8e02_ + 1;
            var42 = var42 + var45;
            arg0->unknown_74_ = 1;
            if (var49 == 0) var32 = var32 + var45;
        }
        if (var42 > 0 && var49 == 0) {
            struct Struct_ov024_021eb5d0_12* var66 = (struct Struct_ov024_021eb5d0_12*)GetCombatantByID((int)arg0->unknown_10_, var4);
            if (var66 != 0) {
                if (var46->unknown_18_.unknown_0_5_ == 1 || var46->unknown_18_.unknown_0_5_ == 0x23) {
                    if ((var66->unknown_138_->unknown_14_ & 0x10000000) != 0) var66->unknown_138_->unknown_22_ = var66->unknown_138_->unknown_22_ | 0x4000;
                }
            }
            int var67 = 0;
            if (var46->unknown_4_.unknown_0_0_ == 1 || var46->unknown_4_.unknown_0_0_ == 2) {
                var67 = func_ov000_021573a8(arg0->unknown_10_, var18, var4, var42);
                if (var67 > 0) {
                    struct Struct_ov024_021eb5d0_12* var68 = (struct Struct_ov024_021eb5d0_12*)GetCombatantByID((int)arg0->unknown_10_, var4);
                    int var69 = 0;
                    if (var68 != 0) {
                        if (!IN_RANGE_021eb5d0(var4)) {
                            if (var68->unknown_138_->unknown_2_ < 0xff) var69 = func_ov000_0215a124(arg0->unknown_10_, var4, var67);
                        } else {
                            var69 = func_ov000_0215a124(arg0->unknown_10_, var4, var67);
                        }
                    }
                    struct Struct_ov024_021eb5d0_6* var70 = func_ov000_0215e958(arg0->unknown_10_);
                    if (var70 != 0) {
                        struct Struct_ov024_021eb5d0_12* var71 = (struct Struct_ov024_021eb5d0_12*)GetCombatantByID((int)arg0->unknown_10_, var4);
                        func_ov000_02159eac(arg0->unknown_10_, var70, 1);
                        func_ov000_02159eac(arg0->unknown_10_, var70, 0x2a);
                        func_ov000_0215ccbc(
                            arg0->unknown_10_, var70, var71, var67, var71->unknown_138_->unknown_0_, var69, var70->unknown_0_, 0);
                        func_ov000_0215ffc4(arg0->unknown_c_, var70, 1);
                        arg0->unknown_10_->unknown_8e02_ = arg0->unknown_10_->unknown_8e02_ + 1;
                        if (arg0->unknown_68_ != 0) {
                            var70->unknown_8_ = arg0->unknown_68_->unknown_8_;
                            var70->unknown_1f_ = arg0->unknown_68_->unknown_1f_;
                            arg0->unknown_68_->unknown_8_ = 0;
                            arg0->unknown_68_->unknown_1f_ = 0;
                            arg0->unknown_68_ = var70;
                        }
                    }
                    struct Struct_ov024_021eb5d0_8* var72 = func_ov000_0215fff4(arg0->unknown_c_, 0, 0);
                    if (var72 != 0) var72->unknown_10_ = var69;
                }
            }
            if (arg0->unknown_70_ != 0) {
                int var73 = func_ov000_02157288(arg0->unknown_10_, var4, var46);
                if (var73 > 0) {
                    struct Struct_ov024_021eb5d0_6* var74 = func_ov000_0215e958(arg0->unknown_10_);
                    if (var74 != 0) {
                        struct Struct_ov024_021eb5d0_12* var75 = (struct Struct_ov024_021eb5d0_12*)GetCombatantByID((int)arg0->unknown_10_, var4);
                        func_ov000_02159eac(arg0->unknown_10_, var74, 0x10);
                        func_ov000_02159eac(arg0->unknown_10_, var74, 0x19);
                        func_ov000_0215cd44(arg0->unknown_10_, var74, var75, 0, 0, 0);
                        func_ov000_0215a88c(arg0->unknown_10_, var74, (unsigned short)var73);
                        func_ov000_0215ffc4(arg0->unknown_c_, var74, 1);
                        arg0->unknown_10_->unknown_8e02_ = arg0->unknown_10_->unknown_8e02_ + 1;
                        func_ov024_021eb4e4((Struct_ov024_021da9e0_4*)arg0, (int)arg0->unknown_c_);
                    }
                }
            }
            if (var67 > 0 && var4 != var18) {
                GetCombatantByID((int)arg0->unknown_10_, var4);
                struct Struct_ov024_021eb5d0_12* var76 = (struct Struct_ov024_021eb5d0_12*)GetCombatantByID((int)arg0->unknown_10_, var18);
                var5 = 0;
                short var77 = func_ov000_0215a1d4(arg0->unknown_10_, var18, var67, &var5);
                arg2->unknown_10_->unknown_24_ = var77;
                if (!IN_RANGE_021eb5d0(var18)) {
                    if (var76->unknown_138_->unknown_2_ >= 0xff) var5 = var67;
                }
                if (var5 > 0) {
                    unsigned short var78 = func_ov024_021da644(var18, 0x25f, 0x238);
                    struct Struct_ov024_021eb5d0_6* var79 = func_ov000_0215e958(arg0->unknown_10_);
                    if (var79 != 0) {
                        func_ov000_0215a88c(arg0->unknown_10_, var79, (unsigned short)var78);
                        var1 = 0;
                        func_ov000_02159eac(arg0->unknown_10_, &var1, 0x22);
                        func_ov000_0215ccbc(
                            arg0->unknown_10_, var79, var76, -var5, var76->unknown_138_->unknown_0_, var77, var1, 0);
                        func_ov000_0215fe84(arg0->unknown_8_, var79, 5);
                        arg0->unknown_8_->unknown_1c_ = var4;
                        arg0->unknown_8_->unknown_1e_ = 0;
                        arg0->unknown_10_->unknown_8e02_ = arg0->unknown_10_->unknown_8e02_ + 1;
                    }
                }
            }
            if (var49 == 0) func_ov024_021e4c04(arg0, var18, var4, var15, var42);
        }
        if (var49 == 0 && arg0->unknown_79_ == 0) func_ov024_021e556c(arg0, var18, var4, var15, var42);
        if (arg0->unknown_74_ != 0 && arg0->unknown_6f_ != 0) {
            func_ov000_021600cc((Struct_ov000_0215767c_5*)arg2, (Struct_ov000_0215767c_4*)arg0->unknown_c_);
            arg0->unknown_10_->unknown_8e01_ = arg0->unknown_10_->unknown_8e01_ + 1;
        }
        if (IN_RANGE_021eb5d0(var4)) {
            struct Struct_ov024_021eb5d0_12* var80 = (struct Struct_ov024_021eb5d0_12*)(void*)func_0200ff1c((GameState*)var13, var4);
            if (var80 != 0 && func_ov024_021eb1ec(arg0, var4) != 0) {
                int var81 = var42;
                if (var15->unknown_18_.unknown_0_5_ != 1 && var15->unknown_18_.unknown_0_5_ != 0x23) var81 = 0;
                int var82 = NextRandomMax((Random*)arg0->unknown_10_, 0x64);
                unsigned int var83 = func_ov024_021eb2b4(arg0) & 0xff;
                if (var83 >= 4) var83 = 3;
                float var84 = data_ov024_021fe738[var83];
                int var85 = (int)(var84 * (float)(unsigned int)(func_ov024_021eb344(arg0, var4, var81) + var15->unknown_2c_.unknown_2_4_));
                if (func_ov000_0215fc60((char*)arg0->unknown_10_) != 0) var85 = 0;
                if (var82 < var85) {
                    var80->unknown_138_->unknown_3b_.unknown_0_3_ = 1;
                    func_ov024_021eb3e0(arg0, var4);
                    func_ov000_0215af54(arg0->unknown_10_, var4, 1);
                }
            }
        }
        if (!IN_RANGE_021eb5d0(var18)) continue;
        if (IN_RANGE_021eb5d0(var4)) continue;
        struct Struct_ov024_021eb5d0_12* var86 = (struct Struct_ov024_021eb5d0_12*)GetCombatantByID((int)arg0->unknown_10_, var4);
        if (var86 == 0) continue;
        func_0208978c((Struct_0208978c*)var86->unknown_138_, var18);
        if (var15->unknown_18_.unknown_1_4_ == 2) var86->unknown_138_->unknown_3c_.unknown_0_1_ = 1;
    }
    if (IN_RANGE_021eb5d0(var18)) {
        var8 = data_ov024_021fe788;
        int var87 = func_ov000_0215eb1c(arg0->unknown_10_, var8.unknown_0_, 8, 1);
        for (int var88 = 0; var88 < var87; var88++) {
            unsigned char var89 = 0;
            if (var15->unknown_1c_.unknown_2_3_ == 5) {
                if (func_ov024_021eb08c(arg0, var18, var8.unknown_0_[var88], 0x13) != 0) var89 = 1;
            }
            if (var15->unknown_1c_.unknown_2_3_ == 0xc) {
                if (func_ov024_021eb08c(arg0, var18, var8.unknown_0_[var88], 0x14) != 0) var89 = 1;
            }
            if ((arg2->unknown_a_ & 1) != 0) {
                if (func_ov024_021eb08c(arg0, var18, var8.unknown_0_[var88], 0x18) != 0) var89 = 1;
            }
            if (var89 != 0) func_ov000_0215a908(arg0->unknown_10_, var8.unknown_0_[var88]);
        }
    }
    if (GetCombatantByID((int)arg0->unknown_10_, var18) != 0 && func_ov000_02155f9c(arg0->unknown_10_, var18, 0) == 0) {
        if (var40 == 0) {
            func_ov024_021e6060(arg0, var18, var15, var32);
            func_ov024_021e6104(arg0, var18, var15);
        }
        func_ov024_021e62cc(arg0, var18, var15);
    }
    if (IN_RANGE_021eb5d0(var18)) {
        var9 = data_ov024_021fe718;
        int var90 = func_ov000_0215eb1c(arg0->unknown_10_, var9.unknown_0_, 8, 1);
        struct Struct_ov024_021eb5d0_12* var91 = (struct Struct_ov024_021eb5d0_12*)(void*)func_0200ff1c((GameState*)var13, var18);
        if (var91 != 0 && var90 > 0 && func_ov024_021eb1ec(arg0, var18) != 0) {
            int var92 = NextRandomMax((Random*)arg0->unknown_10_, 0x64);
            unsigned int var93 = func_ov024_021eb2b4(arg0) & 0xff;
            if (var93 >= 4) var93 = 3;
            float var94 = data_ov024_021fe738[var93];
            int var95 = func_02085038((char*)var91->unknown_150_);
            int var96 = func_ov000_02159d24(arg0->unknown_10_, var18) + var15->unknown_2c_.unknown_2_4_;
            int var97 = (int)(var94 * (float)(unsigned int)(var96 + var95));
            if (func_ov000_0215fc60((char*)arg0->unknown_10_) != 0) var97 = 0;
            if (var92 < var97) {
                var91->unknown_138_->unknown_3b_.unknown_0_3_ = 1;
                func_ov024_021eb3e0(arg0, var18);
                func_ov000_0215af54(arg0->unknown_10_, var18, 1);
            }
        }
    }
    if (func_ov024_021eb47c(arg0, var15->unknown_4_.unknown_0_0_) != 0) {
        struct Struct_ov024_021eb5d0_12* var98 = (struct Struct_ov024_021eb5d0_12*)GetCombatantByID((int)arg0->unknown_10_, var18);
        if (var98 != 0) var98->unknown_138_->unknown_3b_.unknown_0_3_ = 0;
    }
    if (func_ov000_02159c58(arg0->unknown_10_, (unsigned short)var15->unknown_4_.unknown_0_0_) != 0) {
        for (int var99 = 0; var99 < arg2->unknown_8_; var99++) {
            struct Struct_ov024_021eb5d0_7* var100 = func_ov000_02160094((Struct_ov000_0215440c_2*)arg2, var99);
            if (var100 != 0) {
                struct Struct_ov024_021eb5d0_12* var101 = (struct Struct_ov024_021eb5d0_12*)GetCombatantByID((int)arg0->unknown_10_, var100->unknown_20_);
                if (var101 != 0) {
                    var101->unknown_138_->unknown_3b_.unknown_0_2_ = 1;
                    var101->unknown_138_->unknown_3b_.unknown_0_3_ = 0;
                }
            }
        }
    }
    if (arg0->unknown_47_ != 0) {
        struct Struct_ov024_021eb5d0_12* var102 = (struct Struct_ov024_021eb5d0_12*)GetCombatantByID((int)arg0->unknown_10_, var18);
        if (var102 != 0) {
            if (func_02010088((Struct_02010088*)var102) == 0 &&
                func_ov024_021e6798((GameObject*)var102) == 0) {
                struct Struct_ov024_021eb5d0_6* var103 = func_ov000_0215e958(arg0->unknown_10_);
                if (var103 != 0) {
                    func_ov000_0215a88c(arg0->unknown_10_, var103, (unsigned short)0x1f1);
                    var2 = 0;
                    if (arg0->unknown_47_ > 1) func_ov000_02159eac(arg0->unknown_10_, &var2, 8);
                    func_ov000_0215cd44(arg0->unknown_10_, var103, var102, 0, var2, 0);
                    func_ov000_0215fe84(arg2->unknown_10_, var103, 1);
                    arg0->unknown_10_->unknown_8e02_ = arg0->unknown_10_->unknown_8e02_ + 1;
                }
            }
            func_020881ac(var102->unknown_138_);
            func_02088234(var102->unknown_138_);
        }
    }
    if (arg0->unknown_6e_ == 0) {
        func_ov024_021e80e4(arg0, arg2, var15, (var0.unknown_4_ & 2) != 0, var40, var37);
    }
    arg2->unknown_18_ = func_ov024_021e99d8(arg0, arg2, var15);
    if ((arg2->unknown_a_ & 1) != 0) {
        arg2->unknown_22_ = func_ov024_021da644(arg2->unknown_10_->unknown_20_, var15->unknown_28_.unknown_2_4_, var15->unknown_2c_.unknown_0_0_);
    }
    if ((arg2->unknown_a_ & 0x20) != 0) {
        arg2->unknown_24_ = func_ov024_021da644(var20, var37->unknown_28_.unknown_2_4_, var37->unknown_2c_.unknown_0_0_);
    }
    if ((arg2->unknown_a_ & 0x40) != 0) {
        arg2->unknown_24_ = func_ov024_021da644(var20, var37->unknown_28_.unknown_2_4_, var37->unknown_2c_.unknown_0_0_);
    }
    struct Struct_ov024_021eb5d0_12* var104 = (struct Struct_ov024_021eb5d0_12*)GetCombatantByID((int)arg0->unknown_10_, arg2->unknown_10_->unknown_20_);
    if (var104 != 0) {
        if (arg0->unknown_6d_ == 0 && var28 != 0) {
            short var105 = arg0->unknown_10_->unknown_8e54_;
            if (var105 > 0) var104->unknown_138_->unknown_2_ = var105;
        }
        for (int var106 = 0; var106 < arg2->unknown_8_; var106++) {
            struct Struct_ov024_021eb5d0_7* var107 = func_ov000_02160094((Struct_ov000_0215440c_2*)arg2, var106);
            if (var107 != 0) {
                struct Struct_ov024_021eb5d0_12* var108 = (struct Struct_ov024_021eb5d0_12*)GetCombatantByID((int)arg0->unknown_10_, var107->unknown_20_);
                if (var108 != 0) {
                    var107->unknown_22_ = var108->unknown_138_->unknown_0_;
                    var107->unknown_24_ = var108->unknown_138_->unknown_2_;
                }
            }
        }
    }
    if (!IN_RANGE_021eb5d0((unsigned short)arg2->unknown_10_->unknown_20_)) return;
    if (var15->unknown_18_.unknown_1_4_ != 3) return;
    unsigned char var109 = 1;
    if (var15->unknown_8_.unknown_1_0_ != 1 && arg0->unknown_14_ <= 0) var109 = 0;
    if (var109 == 0) return;
    char* var110 = func_ov000_02160f08(func_ov000_02160130());
    int var111 = (unsigned short)arg2->unknown_10_->unknown_20_;
    struct Struct_ov024_021eb5d0_16* var112;
    if (IN_RANGE_021eb5d0(var111)) {
        for (int var113 = 0; var113 < 4; var113++) {
            if (var111 == *(int*)(var110 + var113 * WORK_STRIDE_021eb5d0 + 0x9a4)) {
                var112 = (struct Struct_ov024_021eb5d0_16*)(var110 + 0x158 + 0x800 + var113 * WORK_STRIDE_021eb5d0);
                goto found;
            }
        }
    }
    var112 = 0;
found:
    var110 = var110 + 0xd0;
    if (var110 == 0) return;
    if (func_020ddb38(var111, var112->unknown_22_, var112, arg0->unknown_10_) != 2) return;
    if (func_ov000_0215fd24((int)arg0->unknown_10_, arg2->unknown_10_->unknown_20_) != 0) {
        func_ov017_021c3fb4(arg2->unknown_10_->unknown_20_, 1);
    }
    struct Struct_ov024_021eb5d0_6* var114 = func_ov000_0215e958(arg0->unknown_10_);
    struct Struct_ov024_021eb5d0_12* var115 = (struct Struct_ov024_021eb5d0_12*)GetCombatantByID((int)arg0->unknown_10_, arg2->unknown_10_->unknown_20_);
    if (var114 == 0 || var115 == 0) return;
    func_ov000_021584e8(arg0->unknown_10_, var114, var115, arg2->unknown_10_, 0x258, 0);
    func_02083e28(var115->unknown_150_, 0);
    ApplyCombatantBuffs((int)arg0->unknown_10_, arg2->unknown_10_->unknown_20_);
}
