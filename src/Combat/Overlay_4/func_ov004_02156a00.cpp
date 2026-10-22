#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"

#if defined(jpn)
struct Struct_ov004_021707c8 { void* unknown_4_; void* unknown_8_; void* unknown_c_; };
enum { Enum_ov004_02156a00_12 = 16, Enum_ov004_02156a00_0 = -0xc };
#define func_ov004_021561b0 func_ov004_02157594
#else
struct Struct_ov004_021707c8 { void* unknown_0_; void* unknown_4_; void* unknown_8_; void* unknown_c_; };
enum { Enum_ov004_02156a00_12 = 12, Enum_ov004_02156a00_0 = 0 };
#endif
extern Data021707c8 data_ov004_021707c8;
extern int g_sePlayer;

struct FooA1698;
void InitAndBuildList020a1698(struct FooA1698*, void*);
extern "C" void func_020a1614(void* a, int b);
extern "C" void* func_ov011_021845f8(void* a, int b);
extern "C" void* func_ov011_021849c8(void* obj);
extern "C" void* func_ov023_021f6880(void* obj, int a);
extern "C" int func_ov023_021f6f10(void* self);
extern "C" short func_ov023_021f9bc8(void* node);
extern "C" void* func_ov023_021fa598(void* obj);
extern "C" void func_ov023_021f809c(void* obj, void* a);
extern "C" void func_ov004_021561b0(void* a);
extern "C" void __clear(void* dst, int len);
ARM int LoadBattleBlock020ac460(void* dst);
struct Obj021f9bdc;
void DivModField26_021f9bdc(struct Obj021f9bdc*, int);
struct SePlayer;
void SePlayer_Play(struct SePlayer*, int, int);
struct TableA68;
void* FindEntryByKey_02072a68(struct TableA68*, int);

struct Struct_ov004_02156a00 { unsigned int unknown_0_0_ : 9; char unknown_2_[4]; struct Struct_ov004_02156a00* unknown_8_; };
struct Struct_ov004_02156a00_2 { char unknown_0_[8]; struct Struct_ov004_02156a00* unknown_8_; char unknown_c_[4]; unsigned char unknown_10_; };
struct Struct_ov004_02156a00_3 { char unknown_0_[0x5c]; short unknown_5c_; short unknown_5e_; };
struct Struct_ov004_02156a00_4 { char unknown_0_[0x49c]; unsigned char unknown_49c_0_ : 1; };
struct Struct_ov004_02156a00_5 { char unknown_0_[0x150 + Enum_ov004_02156a00_0]; struct Struct_ov004_02156a00_4* unknown_150_; };
struct Struct_ov004_02156a00_6 { char unknown_0_[0x20]; void* unknown_20_; };
struct Struct_ov004_02156a00_7 { char unknown_0_[0x104]; short unknown_104_; short unknown_106_; };

// USA: func_ov004_02156a00
extern "C" ARM int func_ov004_02156a00(void* arg0) {
    int var0[15];

    func_ov011_021845f8(arg0, 4);
    void* var1 = func_ov011_021849c8(arg0);
    short var2;
    struct Struct_ov004_02156a00_3* var3 = (struct Struct_ov004_02156a00_3*)func_ov023_021f6880(var1, 3);
    if (var3 == 0) {
        return 0;
    }
    if (func_ov023_021f6f10(var3) != 7) {
        return 0;
    }

    short var4 = var3->unknown_5c_ * Enum_ov004_02156a00_12;
    var2 = var3->unknown_5e_;
    int var5 = func_ov023_021f9bc8(var3) + var4;
    short var6 = ((short*)data_ov004_021707c8.unknown_8_)[var5];

    struct Struct_ov004_02156a00_5* var7 = (struct Struct_ov004_02156a00_5*)GameState::GetInstance()->GetProtagonist();
    if (((struct Struct_ov004_02156a00_2*)data_ov004_021707c8.unknown_c_)->unknown_10_ == 0 || ((struct Struct_ov004_02156a00_2*)data_ov004_021707c8.unknown_c_)->unknown_10_ == 1) {
        func_020a1698((struct Struct_020a1698*)data_ov004_021707c8.unknown_c_, (void*)(unsigned int)var7->unknown_150_->unknown_49c_0_);
    } else if (((struct Struct_ov004_02156a00_2*)data_ov004_021707c8.unknown_c_)->unknown_10_ == 2) {
        func_020a1614(data_ov004_021707c8.unknown_c_, ((struct Struct_ov004_02156a00_2*)data_ov004_021707c8.unknown_c_)->unknown_10_);
    }

    memset(data_ov004_021707c8.unknown_4_, 0, 0x3c0);
    __clear(var0, 0x3c);
    func_020ac460(var0);

    int var8 = 0;
    for (struct Struct_ov004_02156a00* var9 = ((struct Struct_ov004_02156a00_2*)data_ov004_021707c8.unknown_c_)->unknown_8_; var9 != 0; var9 = var9->unknown_8_) {
        int var10 = var9->unknown_0_0_;
        if (var0[var10 / 32] & (1 << (var10 % 32))) {
            ((short*)data_ov004_021707c8.unknown_4_)[var8++] = (short)var10;
        }
    }

    memcpy(data_ov004_021707c8.unknown_8_, data_ov004_021707c8.unknown_4_, 0x3c0);
    int var11 = 0;
    for (int var12 = 0; var12 < 0x1e0; var12++) {
        if (var6 == ((short*)data_ov004_021707c8.unknown_8_)[var12]) {
            var11 = var12;
            break;
        }
    }

    var3->unknown_5c_ = (short)(var11 / Enum_ov004_02156a00_12);
    var3->unknown_5e_ = var2;
    func_ov023_021f9bdc((struct Struct_ov004_021549e4_5*)var3, (unsigned short)(var11 % Enum_ov004_02156a00_12));

    SePlayer_Play((struct SePlayer*)&g_sePlayer, 1, 0);

    void* var13 = func_ov023_021f6880(var1, 0xa);
    if (var13 == 0) {
        return 0;
    }
    if (func_ov023_021f6f10(var13) != 4) {
        return 0;
    }
    void* var14 = func_ov023_021fa598(var13);

    void* var15 = func_ov023_021f6880(var1, 0x66);
    if (var15 == 0) {
        return 0;
    }
    if (func_ov023_021f6f10(var15) != 8) {
        return 0;
    }
    ((struct Struct_ov004_02156a00_6*)var15)->unknown_20_ = func_02072a68((struct Struct_02072a68_2*)var14, (short)(((struct Struct_ov004_02156a00_2*)data_ov004_021707c8.unknown_c_)->unknown_10_ + 0x3e7));

    void* var16 = func_ov023_021f6880(var1, 0x34);
    if (var16 == 0) {
        return 0;
    }
    if (func_ov023_021f6f10(var16) != 6) {
        return 0;
    }
    ((struct Struct_ov004_02156a00_7*)var16)->unknown_104_ = 0;
    ((struct Struct_ov004_02156a00_7*)var16)->unknown_106_ = 1;
    func_ov023_021f809c(var16, arg0);
    func_ov004_021561b0(arg0);
    return 0;
}
