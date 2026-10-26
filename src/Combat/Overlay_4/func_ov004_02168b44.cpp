#include "GameState/BattleRecordSnapshot.h"
#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"
#include "GameState/GameState.h"
#include "Resource/Brightness.h"

#if defined(jpn)
enum { Enum_ov004_02168b44_336 = 0x144, Enum_ov004_02168b44_29888 = 0x7280, Enum_ov004_02168b44_420 = 0x24, Enum_ov004_02168b44_29180 = 0x6fbc, fieldOffset = 0x543c, Enum_ov004_02168b44_108 = 0x8c, Enum_ov004_02168b44_15236 = 0x3964, flagOffset = 0x1790, Enum_ov004_02168b44_6500 = 0x1794, Enum_ov004_02168b44_6536 = 0x17b8 };
#else
enum { Enum_ov004_02168b44_336 = 0x150, Enum_ov004_02168b44_29888 = 0x74c0, Enum_ov004_02168b44_420 = 0x1a4, Enum_ov004_02168b44_29180 = 0x71fc, fieldOffset = 0x569c, Enum_ov004_02168b44_108 = 0x6c, Enum_ov004_02168b44_15236 = 0x3b84, flagOffset = 0x1962, Enum_ov004_02168b44_6500 = 0x1964, Enum_ov004_02168b44_6536 = 0x1988 };
#endif

struct S_e830;
extern "C" int func_020a0870(Struct_02061c04* p);
extern "C" int func_020a08a4(Struct_02061c04* p);
extern "C" int func_020a08d8(Struct_02061c04* p);
extern "C" int func_020a090c(Struct_02061c04* p);
extern "C" int func_0201e830(struct S_e830* p);
extern "C" int LinkSession_GetState(int* obj);
extern "C" int GameState_UpdatePlayClocks(int commit);
extern "C" int func_020ac4c0(void* dst);
extern "C" int func_020ac0b4(void* dst);
extern "C" void Set3DClearColor(int color, int alpha, int depth, int polygonId, int fogEnable);
extern "C" int MessageSystem_GetInstance(void);
extern "C" void MessageSystem_Reset(char* obj);
extern "C" void func_020e2d24(int* obj, int a, int b);
extern "C" void* func_ov004_02168ad4(void* a, int id);
extern "C" void* Zone3D_GetInstance(void);
extern "C" void* LinkSession_GetInstance(void);
extern "C" void* func_ov011_021845f8(void* ctx, int v);
extern "C" void func_ov011_021848a0(void* obj, int val);
#if defined(jpn)
extern "C" void* func_ov004_02168f08(void* ctx, int value);
#define NODE_LOOKUP_CALL func_ov004_02168f08
#else
extern "C" void* func_ov023_021f6524(void* ctx, int value);
#define NODE_LOOKUP_CALL func_ov023_021f6524
#endif

struct Struct_ov004_02168b44 {
    char pad[6];
    signed char state;
    unsigned char unknown_7_;
    unsigned char f8;
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
    short f14;
    unsigned char unknown_16_0_ : 1;
};

struct Struct_ov004_02168b44_3 {
#if !defined(jpn)
    char pad[0x180];
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

struct Struct_ov004_02168b44_4 { char pad[Enum_ov004_02168b44_336]; struct Struct_ov004_02168b44_5* f150; };
struct Struct_ov004_02168b44_5 { char pad[0x49c]; unsigned char bit0 : 1; };
struct Struct_ov004_02168b44_6 { unsigned int unknown_0_; unsigned int lo : 19; signed int val : 11; unsigned int hi : 2; };
struct Struct_ov004_021700d4 { int a, b, c; };
class Struct_ov004_02168b44_7 {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void Apply(struct Struct_ov004_021700d4* t);
};

extern struct Struct_ov004_02168b44_3* data_ov004_02171030;
extern struct Struct_ov004_021700d4 data_ov004_021700d4;

// USA: func_ov004_02168b44
extern "C" ARM int func_ov004_02168b44(void* a) {
    GameState* bs = GameState::GetInstance();
    void* obj = LinkSession_GetInstance();
    struct Struct_ov004_02168b44* slot = (struct Struct_ov004_02168b44*)((char*)bs + Enum_ov004_02168b44_29888);
    int i;
    for (i = 0; i < 3; i++, slot++) {
        if (slot->state >= 4) {
            if (slot->unknown_7_ != 0 || slot->f8 != 0 || slot->unknown_9_ >= 0) return 1;
        }
    }
    int kind = LinkSession_GetState((int*)obj);
    int depth = *((unsigned char*)obj + 0x100d);
    int commit = 0;
    if ((kind == 5 && depth > 1) || kind == 6) commit = 1;
    GameState_UpdatePlayClocks(commit);

    data_ov004_02171030 = 0;
    void* holder = func_ov011_021845f8(a, 0);
    if (!holder) return 0;
    struct Struct_ov004_02168b44_3* ctx =
        (struct Struct_ov004_02168b44_3*)((SafeAllocator*)((char*)holder + 4))->Allocate(Enum_ov004_02168b44_420);
    data_ov004_02171030 = ctx;
    if (!ctx) return 0;
    ctx->unknown_180_ = 0;
    ctx->unknown_184_ = 0;
    ctx->unknown_188_ = 0;
    ctx->unknown_18c_ = 0;
    ctx->unknown_198_ = 0;
    ctx->unknown_190_ = 0;
    ctx->unknown_194_ = 0;
    ctx->unknown_19c_ = 0;
    ctx->unknown_1a0_ = 1;
    data_ov004_02171030->unknown_190_ = (unsigned char*)bs + Enum_ov004_02168b44_29180;

    Struct_02061c04 blk;
    int ok = func_020ac4c0(&blk);
    unsigned int var11 = 0;
    func_020ac0b4(&var11);
    if (var11 > 0x1869f) var11 = 0x1869f;
    int bit = 0;
    struct Struct_ov004_02168b44_4* c =
        (struct Struct_ov004_02168b44_4*)bs->GetProtagonist();
    if (c) bit = c->f150->bit0;
    struct Struct_ov004_02168b44_6* fld = (struct Struct_ov004_02168b44_6*)((char*)bs + fieldOffset);
    data_ov004_02171030->unknown_194_ =
        (struct Struct_ov004_02168b44_2*)((SafeAllocator*)((char*)holder + 4))->Allocate(0x18);
    memset(data_ov004_02171030->unknown_194_, 0, 0x18);

    if (ok) {
        data_ov004_02171030->unknown_194_->unknown_0_0_ = blk.unknown_0_.elapsed.hours;
        data_ov004_02171030->unknown_194_->unknown_8_0_ = blk.unknown_0_.elapsed.minutes;
        data_ov004_02171030->unknown_194_->unknown_4_0_ = blk.unknown_0_.unknown_4_.hours;
        data_ov004_02171030->unknown_194_->unknown_8_7_ = blk.unknown_0_.unknown_4_.minutes;
        data_ov004_02171030->unknown_194_->unknown_5_6_ = blk.unknown_8_0_;
        data_ov004_02171030->unknown_194_->unknown_1_6_ = var11;
        data_ov004_02171030->unknown_194_->unknown_c_0_ = blk.unknown_10_0_;
        data_ov004_02171030->unknown_194_->unknown_10_0_ = blk.unknown_b_0_;
        data_ov004_02171030->unknown_194_->unknown_d_2_ = blk.unknown_d_6_;
        data_ov004_02171030->unknown_194_->unknown_11_1_ = blk.unknown_11_1_;
        data_ov004_02171030->unknown_194_->unknown_9_6_ =
            (unsigned char)func_020a0870(&blk);
        data_ov004_02171030->unknown_194_->unknown_a_5_ =
            (unsigned char)func_020a08a4(&blk);
        data_ov004_02171030->unknown_194_->unknown_f_0_ =
            (unsigned char)func_020a08d8(&blk);
        data_ov004_02171030->unknown_194_->unknown_12_7_ =
            (unsigned char)func_020a090c(&blk);
        data_ov004_02171030->unknown_194_->f14 = fld->val;
        data_ov004_02171030->unknown_194_->unknown_16_0_ = bit;
    }

    data_ov004_02171030->unknown_19c_ = ((SafeAllocator*)((char*)holder + 4))->Allocate(0x800);
    memset(data_ov004_02171030->unknown_19c_, 0, 4);

    void* base = Zone3D_GetInstance();
    if (!base) return 0;
    struct S_e830* rec = (struct S_e830*)((char*)base + Enum_ov004_02168b44_108);
    if (!rec) return 0;
    data_ov004_02171030->unknown_18c_ = func_0201e830(rec);

    unsigned int* w = (unsigned int*)GetGameResources();
    data_ov004_02171030->unknown_180_ = GetFlags00((GameResources*)w);
    data_ov004_02171030->unknown_184_ = GetFlags04((GameResources*)w);
    data_ov004_02171030->unknown_188_ = GetFlags08((GameResources*)w);
    SetFlags00((GameResources*)w, 4);
    SetFlags04((GameResources*)w, 0x8de);
    Set3DClearColor(0, 0, 0x7fff, 0, 0);

    struct Struct_ov004_02168b44_7* node = (struct Struct_ov004_02168b44_7*)NODE_LOOKUP_CALL(a, 0x64);
    if (data_ov004_02171030->unknown_190_[0] <= 8) {
        *(short*)((char*)node + 0x5c) = 0;
        *(short*)((char*)node + 0x5e) = 1;
    } else {
        *(short*)((char*)node + 0x5c) = 0;
        *(short*)((char*)node + 0x5e) = 2;
    }

    unsigned char* tbl = *(unsigned char**)((char*)w + Enum_ov004_02168b44_15236);
    if (data_ov004_02171030->unknown_190_[0] == 0) {
        func_ov011_021848a0(a, 0x65);
    } else if (tbl[9] != 0) {
        func_ov011_021848a0(a, 0x67);
        struct Struct_ov004_02168b44_7* var20 = (struct Struct_ov004_02168b44_7*)func_ov004_02168ad4(a, 2);
        struct Struct_ov004_021700d4 tmp = data_ov004_021700d4;
        var20->Apply(&tmp);
    } else {
        func_ov011_021848a0(a, 0x64);
    }

    char* g = (char*)MessageSystem_GetInstance();
    MessageSystem_Reset(g);
    *(unsigned char*)(g + flagOffset) = 1;
    func_020e2d24((int*)(g + Enum_ov004_02168b44_6500), 9, 1);
    func_020e2d24((int*)(g + Enum_ov004_02168b44_6536), 0x19, 1);
    return 0;
}
