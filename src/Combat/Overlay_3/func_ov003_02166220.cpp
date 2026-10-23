#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"
#include "Resource/CharacterCreationUI.h"

struct Struct_02080cc0;
struct Struct_02080f8c;
struct Struct_02080fa8;
struct Struct_02081198;
struct Struct_02081164;
struct Struct_0201099c_16;
struct Struct_ov003_0215f56c_3;
struct Struct_ov003_02165c9c_5;

extern "C" int func_02080b54(void* arg0, int arg1);
extern "C" void* func_02010828(GameState*);
extern "C" void func_ov003_02166164(Struct_ov003_02165c9c_5*, int, int);
extern "C" void func_02042764(void* arg0, void* arg1, int arg2);
#if defined(jpn)
extern "C" short func_020865b0(Struct_0201099c_16*);
#else
extern "C" int func_020865b0(Struct_0201099c_16*);
#endif
int ClassifyRatio_0215f56c(S0215f56c*);
int SetEntryFlagById02080b40(void* obj, int id);
void SetEntryHighNibble0x13(struct Container02080cc0* obj, int id, int value);
int SetEntryFlagById02080b40(void*, int);
extern "C" void _Z22SetEntryHighNibble0x13P17Container02080cc0ii(struct Container02080cc0* obj, short id, int value);
void SetEntryFirstField02080f8c(Container02080f8c*, int, int);
void ResolveEntryValueByKey02080fe0(void*, int, int);
void SetEntryFirstField02080fa8(struct Container02080fa8*, int, int);
void SetEntryHalfword0xe_0208103c(void*, int, int);
void GetEntryFieldsAt0x602080828(void*, int, short*, short*);
extern "C" void _Z23GetEntryOutputs020808c8PviPsS0_(void*, short, short*, short*);
void SetEntryFieldsAt0x602080854(void*, int, int, int);
int KeyTable_Get(struct Container020e0310*, int);
extern "C" void func_ov003_0215f5e8(void* menu, int page, int count);
extern "C" void func_ov003_02160c58(void* self, short* outHigh, short* outLow);
void SetEntryNibbleByShortId(struct StatusOwner02081198* owner, int id, int enable);
void SetEntryFlag0x2ByShortId(struct StatusOwner02081164* obj, int id, int value);
extern "C" int func_020813ec(void* obj, int id);
extern "C" void func_ov003_02160678(void* self);
extern "C" void func_ov003_02160794(void* self);

struct Struct_ov003_02166220 {
    char unknown_0_[2];
    unsigned char unknown_2_[0xd];
    unsigned char unknown_f_[0x140 - 0xf];
    char unknown_140_[0x34];
    unsigned char unknown_174_0_ : 1;
    char unknown_175_[0x23c - 0x175];
};

struct Struct_ov003_02166220_2 {
    char unknown_0_[0xf7c];
    unsigned char unknown_f7c_;
    char unknown_f7d_[0xf80 - 0xf7d];
    Struct_ov003_02166220 unknown_f80_[(0x2c8c - 0xf80) / 0x23c];
    char unknown_2c8c_[0x2c8c - 0xf80 - ((0x2c8c - 0xf80) / 0x23c) * 0x23c];
    unsigned char unknown1_2c8c_;
};

struct Struct_ov003_02166220_3 {
    short unknown_0_[2];
};

struct Struct_ov003_0217f3ec_3 {
#if defined(jpn)
    char unknown_0_[0x14];
#else
    char unknown1_0_[0x20];
#endif
    Struct_ov003_02166220_3 unknown_20_;
};

extern Struct_ov003_0217f3ec_3 data_ov003_0217f3ec;

struct Struct_ov003_02166220_4 {
#if defined(jpn)
    char unknown_0_[0x1c4];
    Struct_0201099c_3 unknown_2dc_;
    char unknown_1cc_[0x20c - 0x1cc];
    struct Struct_02080cc0* unknown_324_;
    char unknown_210_[0x290 - 0x210];
    unsigned char unknown_468_[4];
    char unknown_294_[0x2c7 - 0x294];
    signed char unknown_49f_;
    char unknown_2c8_[0x2e5 - 0x2c8];
    unsigned char unknown_4bd_;
#else
    char unknown1_0_[0x2dc];
    Struct_0201099c_3 unknown_2dc_;
    char unknown_2e4_[0x324 - 0x2e4];
    struct Struct_02080cc0* unknown_324_;
    char unknown_328_[0x39c - 0x328];
    char unknown_39c_[4][0x30];
    char unknown_45c_[0x468 - 0x45c];
    unsigned char unknown_468_[4];
    char unknown_46c_[0x49f - 0x46c];
    signed char unknown_49f_;
    char unknown_4a0_[0x4bd - 0x4a0];
    unsigned char unknown_4bd_;
#endif
};

struct Struct_ov003_02166220_5 {
#if defined(jpn)
    char unknown_0_[0x2a];
#else
    char unknown1_0_[0x36];
#endif
    short unknown_36_;
};

// USA: func_ov003_02166220
extern "C" ARM void func_ov003_02166220(Struct_ov003_02166220_4* arg0) {
    struct Struct_02080cc0* var0 = arg0->unknown_324_;
    Struct_ov003_02166220_2* var1;
    short var2;
    Struct_ov003_02166220* var3;
    short var4;
#if defined(jpn)
    short var5;
#else
    int var5;
#endif
    int var6;
    short var7;
    int var8;
    int var9;
    int var10;
    short var11;
    int var12;
    short var13;
    int var14;
    unsigned char var15;
    short var16, var17, var18, var19;
    short var20, var21;
    Struct_ov003_02166220_3 var22;

    func_02080b54(var0, 6);
    var1 = (Struct_ov003_02166220_2*)func_02010828(GameState::GetInstance());
    var2 = var1->unknown1_2c8c_;
    var8 = 0x15;
    var4 = 100;
    var7 = arg0->unknown_49f_ * 4;
    arg0->unknown_4bd_ = (unsigned char)var8;
    var5 = -1;
    var10 = 0xcb;
    memset(arg0->unknown_468_, 0, 4);
    func_ov003_02166164((Struct_ov003_02165c9c_5*)arg0, var2 > 4, 1);
#if !defined(jpn)
    memset(arg0->unknown_39c_, 0, sizeof(arg0->unknown_39c_));
#endif

    for (var11 = 0; var11 < 4; var11++) {
        var3 = &var1->unknown_f80_[var7];
#if defined(jpn)
        func_02080f8c((struct Struct_02080f8c*)var0, var8, (int)var3->unknown_140_);
#else
        var12 = var11 * 0x30;
        func_02042764(var3->unknown_140_, (char*)arg0->unknown_39c_ + var12, 1);
        func_02080f8c((struct Struct_02080f8c*)var0, var8, (int)&arg0->unknown_39c_[0][var12]);
#endif
        if (func_020865b0((Struct_0201099c_16*)var3) != 0) {
            var5 = (short)(func_020865b0((Struct_0201099c_16*)var3) + 0x11);
        }
        func_02080fe0(var0, (short)(var8 + 4), var5);
        func_02080fa8((struct Struct_02080fa8*)var0, (short)(var8 + 8),
                                                             var3->unknown_2_[func_020865b0((Struct_0201099c_16*)var3)]);
        var9 = func_ov003_0215f56c((Struct_ov003_0215f56c_3*)var3);
        if (var8 == ((struct Struct_ov003_02166220_5*)var0)->unknown_36_ && var9 == 0xf) {
            var9 = 0xa;
        }
        if (var7 < var2) {
            for (var13 = 0; var13 < 3; var13++) {
                var6 = var8 + var13 * 4;
                ((void (*)(struct Struct_02080cc0*, short, int))func_02080cc0)(var0, var6, var9);
                func_02080b40(var0, (short)var6);
            }
#if !defined(jpn)
            func_02080cc0(var0, var4, var9);
            func_02080b40(var0, var4);
#endif
            arg0->unknown_468_[var11] = var3->unknown_174_0_ + 1;
            var15 = var3->unknown_f_[func_020865b0((Struct_0201099c_16*)var3)];
            func_0208103c(var0, var10, (short)(var15 + 100));
            if (var15 != 0) {
                var9 = 5;
                if (var15 == 0xa) {
                    var9 = 0xd;
                }
                var14 = var11 + 0x19;
                func_02080828(var0, (short)var14, &var16, &var17);
                func_020808c8(var0, var14, &var18, &var19);
#if defined(jpn)
                func_02080854(var0, var10, (short)(var16 + var18 + 1), (short)(var17 + 2));
#else
                func_02080854(var0, var10, (short)(var16 + var18 + 1), var17);
#endif
                func_02080cc0(var0, var10, var9);
                func_02080b40(var0, var10);
            }
        } else {
            SetEntryHighNibble0x13(elementObj, idA, color);
            SetEntryFlagById02080b40(elementObj, idA);
            SetEntryFirstField02080f8c((struct Container02080f8c*)elementObj, idA, (int)KeyTable_Get(&self->cont2dc, 0x7530));
        }
        var7++;
        var8 = (short)(var8 + 1);
        var10 = (short)(var10 + 1);
#if !defined(jpn)
        var4++;
#endif
    }

    func_ov003_0215f5e8(var0, arg0->unknown_49f_, var2);
    func_ov003_02160c58(arg0, &var20, &var21);
    var1 = (Struct_ov003_02166220_2*)func_02010828(GameState::GetInstance());
    var21 = var21 - (var1->unknown_f7c_ - 1);
    func_02080fa8((struct Struct_02080fa8*)var0, 0x23, var21);
    func_02080fa8((struct Struct_02080fa8*)var0, 0x24, var20);

    var22 = data_ov003_0217f3ec.unknown_20_;
    for (int var23 = 0; var23 < 2; var23++) {
        short var24 = var22.unknown_0_[var23];
        func_02081198((struct Struct_02081198*)var0, var24, 1);
        func_02081164((struct Struct_02081164*)var0, var24, 1);
        func_020813ec(var0, var24);
    }
    func_ov003_02160678(arg0);
    func_ov003_02160794(arg0);
}
