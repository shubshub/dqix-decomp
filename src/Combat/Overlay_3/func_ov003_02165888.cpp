#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"
#include "Resource/CharacterCreationUI.h"

struct Struct_02080cc0;
struct Struct_02080f8c;
struct Struct_02080fa8;
struct Struct_02081198;
struct Struct_02081164;

int SetSublistEntriesFlag1_02080b54(void* obj, int id);
int SetEntryFlagById02080b2c(void* obj, int id);
int SetEntryFlagById02080b40(void* obj, int id);
void SetEntryHighNibble0x13(struct Container02080cc0* obj, int id, int value);
extern "C" int func_020dcc98(int combatantId);
int* GetFieldAt0x150_02053c6c(unsigned char* p);
void SetEntryFirstField02080f8c(Container02080f8c*, int, int);
void ResolveEntryValueByKey02080fe0(void*, int, int);
void SetEntryFirstField02080fa8(struct Container02080fa8*, int, int);
void SetEntryHalfword0xe_0208103c(void*, int, int);
void GetEntryFieldsAt0x602080828(void*, int, short*, short*);
extern "C" void _Z23GetEntryOutputs020808c8PviPsS0_(void*, short, short*, short*);
void SetEntryFieldsAt0x602080854(void*, int, int, int);
int KeyTable_Get(struct Container020e0310*, int);
void SetEntryNibbleByShortId(struct StatusOwner02081198* owner, int id, int enable);
void SetEntryFlag0x2ByShortId(struct StatusOwner02081164* obj, int id, int value);
extern "C" int func_020813ec(void* obj, int id);
extern "C" void func_ov003_02160678(void* self);
extern "C" void func_ov003_02160794(void* self);

#if defined(jpn)
struct Struct_ov003_02165888_2 {
    char unknown_0_[0x16c];
    unsigned short unknown_16c_;
    char unknown_16e_[0x186 - 0x16e];
    unsigned char unknown_186_0_ : 8;
    char unknown_187_[0x49c - 0x187];
    unsigned char unknown_49c_0_ : 1;
    char unknown_49d_[0x8b8 - 0x49d];
    int unknown_8b8_;
};

struct Struct_ov003_02165888_3 {
    char unknown_0_[0x2a];
    short unknown_2a_;
};

struct Struct_ov003_02165888 {
    char unknown_0_[0x1c4];
    Struct_0201099c_3 unknown_1c4_;
    char unknown_1cc_[0x20c - 0x1cc];
    struct Struct_02080cc0* unknown_20c_;
    char unknown_210_[0x290 - 0x210];
    unsigned char unknown_290_[4];
    char unknown_294_[0x2d5 - 0x294];
    unsigned char unknown_2d5_;
    char unknown_2d6_[0x2e5 - 0x2d6];
    unsigned char unknown_2e5_;
};

extern "C" ARM void func_ov003_02165888(Struct_ov003_02165888* arg0) {
    struct Struct_02080cc0* var0 = arg0->unknown_20c_;
    int var1;
    int var2;
    int var3;
    int var4;
    int var5;
    GameState* var6;
    GameObject* var7;
    char* var8;
    unsigned char* var9;
    unsigned char var10;
    short var11, var12, var13, var14;
    unsigned char var15;

    func_02080b54(var0, 0x13);
    var6 = GameState::GetInstance();

    var9 = (unsigned char*)arg0 + 0xd1 + 0x200;
    var1 = 0x55;
    arg0->unknown_2e5_ = (unsigned char)var1;
    var10 = arg0->unknown_2d5_;
    var3 = 0xcf;
    memset((unsigned char*)arg0 + 0x290, 0, 4);

    for (var15 = 0; var15 < 4; var15++) {
        var2 = 0xf;
        func_02080b2c(var0, var3);

        if (var15 < var10) {
            int var16;
            struct Struct_ov003_02165888_2* var17;
            var7 = var6->GetPartyMemberByIndex(var9[var15]);
            if (var7 == 0) continue;

            for (var2 = 0; var2 < 3; var2++) {
                func_02080b40(var0, (short)(var1 + var2 * 4));
            }

            var2 = func_020dcc98((signed char)var9[var15]);
            if (var1 == ((struct Struct_ov003_02165888_3*)var0)->unknown_2a_ && var2 == 0xf) {
                var2 = 0xa;
            }
            for (var16 = 0; var16 < 3; var16++) {
                func_02080cc0(var0, (short)(var1 + var16 * 4), var2);
            }

            var4 = -1;
            var17 = (struct Struct_ov003_02165888_2*)func_02053c6c((unsigned char*)var7);
            ((unsigned char*)arg0 + var15)[0x290] = (unsigned char)(var17->unknown_49c_0_ + 1);
            var8 = (char*)var7->baseStats_;
            func_02080f8c((struct Struct_02080f8c*)var0, var1, (int)var8);
            if (var17->unknown_8b8_ != 0) {
                var4 = (short)(var17->unknown_8b8_ + 0x11);
            }
            func_02080fe0(var0, (short)(var1 + 4), var4);
            func_02080fa8(
                (struct Struct_02080fa8*)var0, (short)(var1 + 8),
                *(unsigned short*)((char*)var17 + var17->unknown_8b8_ * 2 + 0x16c));

            {
                struct Struct_ov003_02165888_2* var18 = *(struct Struct_ov003_02165888_2**)((char*)var7 + 0x144);
                unsigned char* var19 = (unsigned char*)var18 + var18->unknown_8b8_;
                unsigned char var20 = var19[0x186];
                func_0208103c(var0, var3, (short)(var20 + 0x64));
                if (var20 != 0) {
                    var2 = 5;
                    if (var20 == 0xa) {
                        var2 = 0xd;
                    }
                    func_02080cc0(var0, var3, var2);
                    func_02080b40(var0, var3);
                    var5 = var15 + 0x59;
                    func_02080828(var0, (short)var5, &var11, &var12);
                    func_020808c8(var0, var5, &var13, &var14);
                    func_02080854(var0, var3, (short)(var11 + var13 + 1), (short)(var12 + 2));
                    func_02080cc0(var0, var3, var2);
                    func_02080b40(var0, var3);
                }
            }
        } else {
            if (var1 == ((struct Struct_ov003_02165888_3*)var0)->unknown_2a_) {
                var2 = 0xa;
            }
            SetEntryFlagById02080b40(elementObj, idA);
            nm = (char*)KeyTable_Get(&self->cont1c4, 0x7530);
            SetEntryFirstField02080f8c((struct Container02080f8c*)elementObj, idA, (int)nm);
            SetEntryHighNibble0x13(elementObj, idA, color);
        }

        var1 = (short)(var1 + 1);
        var3 = (short)(var3 + 1);
    }

    func_02081198((struct Struct_02081198*)var0, 0x13, 1);
    func_02081164((struct Struct_02081164*)var0, 0x13, 1);
    func_020813ec(var0, 0x13);
    func_ov003_02160678(arg0);
    func_ov003_02160794(arg0);
}
#else
struct Struct_ov003_02154af4_4 {
    char unknown_0_[0x16c];
    unsigned short unknown_16c_;
    char unknown_16e_[0x186 - 0x16e];
    unsigned char unknown_186_0_ : 8;
    char unknown_187_[0x49c - 0x187];
    unsigned char unknown_49c_0_ : 1;
    char unknown_49d_[0x950 - 0x49d];
    int unknown_950_;
};

struct Struct_ov003_02158334_2 {
    char unknown_0_[0x36];
    short unknown_36_;
};

struct Struct_ov003_02165888 {
    char unknown_0_[0x2dc];
    Struct_0201099c_3 unknown_2dc_;
    char unknown_2e4_[0x324 - 0x2e4];
    struct Struct_02080cc0* unknown_324_;
    char unknown_328_[0x468 - 0x328];
    unsigned char unknown_468_[4];
    char unknown_46c_[0x4ad - 0x46c];
    unsigned char unknown_4ad_;
    char unknown_4ae_[0x4bd - 0x4ae];
    unsigned char unknown_4bd_;
};

// USA: func_ov003_02165888
extern "C" ARM void func_ov003_02165888(Struct_ov003_02165888* arg0) {
    struct Struct_02080cc0* var21 = arg0->unknown_324_;
    int var22;
    int var23;
    int var24;
    int var25;
    int var26;
    GameState* var27;
    GameObject* var28;
    char* var29;
    unsigned char* var30;
    unsigned char var31;
    short var32, var33, var34, var35;
    unsigned char var36;
    int var37;

    func_02080b54(var21, 0x13);
    var27 = GameState::GetInstance();

    var30 = (unsigned char*)arg0 + 0xa9 + 0x400;
    var22 = 0x55;
    arg0->unknown_4bd_ = (unsigned char)var22;
    var31 = arg0->unknown_4ad_;
    var37 = 0x68;
    var24 = 0xcf;
    memset((unsigned char*)arg0 + 0x68 + 0x400, 0, 4);

    for (var36 = 0; var36 < 4; var36++) {
        var23 = 0xf;
        func_02080b2c(var21, var24);

        if (var36 < var31) {
            int var38;
            struct Struct_ov003_02154af4_4* var39;
            var28 = var27->GetPartyMemberByIndex(var30[var36]);
            if (var28 == 0) continue;

            for (var23 = 0; var23 < 3; var23++) {
                func_02080b40(var21, (short)(var22 + var23 * 4));
            }
            func_02080b40(var21, var37);

            var23 = func_020dcc98((signed char)var30[var36]);
            if (var22 == ((struct Struct_ov003_02158334_2*)var21)->unknown_36_ && var23 == 0xf) {
                var23 = 0xa;
            }
            for (var38 = 0; var38 < 3; var38++) {
                func_02080cc0(var21, (short)(var22 + var38 * 4), var23);
            }
            func_02080cc0(var21, var37, var23);

            var25 = -1;
            var39 = (struct Struct_ov003_02154af4_4*)func_02053c6c((unsigned char*)var28);
            ((unsigned char*)arg0 + var36)[0x468] = (unsigned char)(var39->unknown_49c_0_ + 1);
            var29 = (char*)var28->baseStats_;
            func_02080f8c((struct Struct_02080f8c*)var21, var22, (int)var29);
            if (var39->unknown_950_ != 0) {
                var25 = (short)(var39->unknown_950_ + 0x11);
            }
            func_02080fe0(var21, (short)(var22 + 4), var25);
            func_02080fa8(
                (struct Struct_02080fa8*)var21, (short)(var22 + 8),
                *(unsigned short*)((char*)var39 + var39->unknown_950_ * 2 + 0x16c));

            {
                struct Struct_ov003_02154af4_4* var40 = *(struct Struct_ov003_02154af4_4**)((char*)var28 + 0x150);
                unsigned char* var41 = (unsigned char*)var40 + var40->unknown_950_;
                unsigned char var42 = var41[0x186];
                func_0208103c(var21, var24, (short)(var42 + 0x64));
                if (var42 != 0) {
                    var23 = 5;
                    if (var42 == 0xa) {
                        var23 = 0xd;
                    }
                    func_02080cc0(var21, var24, var23);
                    func_02080b40(var21, var24);
                    var26 = var36 + 0x59;
                    func_02080828(var21, (short)var26, &var32, &var33);
                    func_020808c8(var21, var26, &var34, &var35);
                    func_02080854(var21, var24, (short)(var32 + var34 + 1), var33);
                    func_02080cc0(var21, var24, var23);
                    func_02080b40(var21, var24);
                }
            }
        } else {
            if (var22 == ((struct Struct_ov003_02158334_2*)var21)->unknown_36_) {
                var23 = 0xa;
            }
            SetEntryFlagById02080b40(elementObj, idA);
            nm = (char*)KeyTable_Get(&self->cont2dc, 0x7530);
            SetEntryFirstField02080f8c((struct Container02080f8c*)elementObj, idA, (int)nm);
            SetEntryHighNibble0x13(elementObj, idA, color);
        }

        var22 = (short)(var22 + 1);
        var24 = (short)(var24 + 1);
        var37 = (short)(var37 + 1);
    }

    func_02081198((struct Struct_02081198*)var21, 0x13, 1);
    func_02081164((struct Struct_02081164*)var21, 0x13, 1);
    func_020813ec(var21, 0x13);
    func_ov003_02160678(arg0);
    func_ov003_02160794(arg0);
}
#endif
