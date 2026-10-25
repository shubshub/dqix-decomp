#include <globaldefs.h>
#include "Combat/ActionDisplay.h"
#include "GameState/GameState.h"
#include "World/Zone3D.h"
#include "NitroSDK/Memory.h"
#include "std_library_functions.h"

#if defined(jpn)
enum { Enum_02024518_2496 = 0x914, Enum_02024518_12 = 0x4c };
#define data_020e7074 data_020e7940
#define data_020e7076 data_020e7942
#define data_020e7056 data_020e7922
#define data_020e7057 data_020e7923
#else
enum { Enum_02024518_2496 = 0x9c0, Enum_02024518_12 = 12 };
#endif

struct Struct_02024518 {
    int unknown_0_;
    int unknown_4_;
    int unknown_8_;
    int unknown_c_;
};

struct Struct_02024518_4 {
    unsigned char unknown_0_[0x18];
    int unknown_18_;
    int unknown_1c_;
    unsigned char unknown_20_[0xc];
    Struct_02024518 *unknown_2c_;
    int unknown_30_;
    unsigned char unknown_34_[4];
    fix32_t unknown_38_;
    unsigned char unknown_3c_[8];
    int unknown_44_;
    int unknown_48_;
    unsigned char unknown_4c_[0x6c - 0x4c];
    int unknown_6c_;
    int unknown_70_;
    int unknown_74_;
    unsigned char unknown_78_[0x55c - 0x78];
    unsigned char unknown_55c_;
    unsigned char unknown_55d_[0x5a4 - 0x55d];
    int unknown_5a4_;
    unsigned char unknown_5a8_[4];
    fix32_t unknown_5ac_;
    fix32_t unknown_5b0_;
    unsigned char unknown_5b4_[Enum_02024518_2496 - 0x5b4];
    unsigned char unknown_9c0_;
};

struct Struct_02024518_2;
struct Struct_02024518_3;
struct Struct_02020fc4_3;
struct Struct_0202441c;
struct Struct_02024d48;

extern short data_020e7074[][2];
extern short data_020e7076[][2];
extern signed char data_020e7056[][2];
extern signed char data_020e7057[][2];

void *GetData02105254_0203b628();
extern "C" Zone3D *Zone3D_GetInstance();
int IsInRange0201b5b0(int id);
extern "C" void func_02027974(void *object, const unsigned char* adjacencyData, int state);
extern "C" void func_0203b8bc(void *data, int mode, int index, int x, int y, int state, int width, int height,
                              unsigned short palette);
void SetArraySlotFlag0203b718(void *owner, int mode, int index, int value);
Entry_02027878 *GetEntryFromList(List_02027878 *list, int index);
void ForwardParamsToB8bc_0203bcb8(Bcb8Params *params, int a, int b);
void AccumulateBattleTimer0202441c(BattleTimer0202441c *receiver);
int CheckCombatantReadyForAction020243b8(void *receiver, int combatantId);
int CheckActionAllowed(CombatActionPosition* entry, int state);
void SetElementFields0202756c(void *receiver, int x, int y, int index, unsigned char type, unsigned char flags,
                              unsigned short palette, unsigned char opacity, int scaleX, int scaleY);

// USA: func_02024518
// JPN: func_02023eec
extern "C" ARM void func_02024518(MapReceiver02024518 *self) {
    int pz;
    int px;
    GameState *gameState  = GameState::GetInstance();
    GameObject *object    = gameState->GetUnknownGameObject();
    void *displayState    = GetData02105254_0203b628();
    Zone3D *zone          = Zone3D_GetInstance();
    int count;
    int zoneId            = zone->currentZoneID_;
    Vector3i position     = object->obj3D_.position_;
    CombatActionPosition entries[17];
    unsigned char groups[32];
    memset(groups, 0, sizeof(groups));
    count = func_020236dc(entries, groups, &position);

    fix32_t var11 = arg0->unknown_38_;
    int var12   = (int) ((float) FIX32_MULTIPLY(arg0->unknown_5ac_, arg0->unknown_38_) / 4096.0f);
    int var13   = (int) ((float) FIX32_MULTIPLY(arg0->unknown_5b0_, var11) / 4096.0f);
    int var14   = (int) ((float) FIX32_MULTIPLY(var8.x, var11) / 4096.0f);
    int var15   = (int) ((float) FIX32_MULTIPLY(var8.z, var11) / 4096.0f);
    if (var14 - var12 > 30 || var12 - var14 > 30) {
        if (var14 > var12) {
            arg0->unknown_5ac_ += fix32_Divide((var14 - var12 - 30) << 12, var11);
        } else {
            arg0->unknown_5ac_ -= fix32_Divide((var12 - var14 - 30) << 12, var11);
        }
    }
    if (var15 - var13 > 10 || var13 - var15 > 20) {
        if (var15 > var13) {
            arg0->unknown_5b0_ += fix32_Divide((var15 - var13 - 10) << 12, arg0->unknown_38_);
        } else {
            arg0->unknown_5b0_ -= fix32_Divide((var13 - var15 - 20) << 12, arg0->unknown_38_);
        }
    }
    var11         = arg0->unknown_38_;
    var12       = (int) ((float) FIX32_MULTIPLY(arg0->unknown_5ac_, var11) / 4096.0f);
    var13       = (int) ((float) FIX32_MULTIPLY(arg0->unknown_5b0_, var11) / 4096.0f);
    arg0->unknown_44_ = var12;
    arg0->unknown_48_ = var13;
    int var16     = var12 < 0 ? var12 / 8 - 1 : var12 / 8;
    int var17     = var13 < 0 ? var13 / 8 - 1 : var13 / 8;

    int var18;
    int var19;
    if (func_0201b5b0(var7)) {
        if (arg0->unknown_6c_ == 0) return;
        if (var5->unknown_424_ == 0) {
            unsigned char *var20 =
                (unsigned char*)&var2->unk_6fc0[Enum_02024518_12] + ((var7 % 20) - 1) * 32;
            fix32_t var21 = fix32_Divide(FIX32_MULTIPLY(var3->obj3D_.rotation_.y, 0xb4000), 0x3243);
            if (var21 > 0xb4000) var21 -= 0x168000;
            var21 >>= 12;
            if (-157 > var21 || var21 > 157) {
                var18 = (int) ((4.0f + (float) var8.x / 4096.0f) / 8.0f);
                var19 = (int) (((float) var8.z / 4096.0f - 2.0f) / 8.0f);
            } else {
                int var22 = 0;
                var1        = var8.x;
                var0        = var8.z;
                for (int var23 = 0; var23 < 7 && !var22; var23++) {
                    if (data_020e7074[var23][0] >= var21 && var21 > data_020e7076[var23][0]) {
                        var18 = (int) (((float) var1 / 4096.0f + (float) data_020e7056[var23][0]) / 8.0f);
                        var19 = (int) (((float) var0 / 4096.0f + (float) data_020e7057[var23][0]) / 8.0f);
                        var22 = 1;
                    }
                }
            }
            if (var18 < 8) {
                var20[var19 * 2] |= 1U << var18;
            } else {
                var20[var19 * 2 + 1] |= 1U << (var18 - 8);
            }
            int var24 = (int) ((4.0f + (float) var8.x / 4096.0f) / 8.0f);
            int var25 = (int) ((4.0f + (float) var8.z / 4096.0f) / 8.0f);
            if (var24 < 8) {
                var20[var25 * 2] |= 1U << var24;
            } else {
                var20[var25 * 2 + 1] |= 1U << (var24 - 8);
            }
            ActiveGrottoClass* var26 = var5->inline_02024518_2();
            func_02027974(arg0, var26->floorMap_.pMapAdjacencyData, arg0->unknown_6c_);
        }
        arg0->unknown_55c_ = 0;
        func_0203b718(var4, 1, 0, arg0->unknown_74_);
        int var27        = arg0->unknown_18_ - var16;
        int var28        = arg0->unknown_1c_ - var17 + 16;
        void *var29  = func_0203b628();
        func_0203b8bc(var29, 1, 0, var27 + 32, var28, arg0->unknown_6c_, 32, 32, arg0->unknown_70_);
    } else {
        arg0->unknown_55c_ = 0;
        func_0203b718(var4, 1, 0, arg0->unknown_74_);
        for (int var30 = 0; var30 < arg0->unknown_30_; var30++) {
            Struct_02024518_3 *var31 = func_02027878((Struct_02024518_2*)arg0, arg0->unknown_2c_[var30].unknown_4_);
            if (var31) {
                func_0203bcb8((Struct_02020fc4_3*)((char*)var31 + 8),
                                    arg0->unknown_18_ + arg0->unknown_2c_[var30].unknown_8_ - var16 + 32,
                                    arg0->unknown_1c_ + arg0->unknown_2c_[var30].unknown_c_ - var17 + 16);
            }
        }
    }
    func_0202441c((Struct_0202441c*)arg0);
    for (int var32 = 0; var32 < var6; var32++) {
        Struct_020236dc *var33 = &var9[var32];
        if (!func_020243b8(arg0, var33->unknown_14_)) continue;
        fix32_t var34 = arg0->unknown_38_;
        int var35 = (int) ((float) FIX32_MULTIPLY(var33->unknown_0_.x, var34) / 4096.0f) - arg0->unknown_44_;
        int var36 = (int) ((float) FIX32_MULTIPLY(var33->unknown_0_.z, var34) / 4096.0f) - arg0->unknown_48_;
        if (var33->unknown_f_ >= 0) {
            int var37 = var10[var33->unknown_10_] - 1;
            var35 += data_020e70f0[var37][var33->unknown_f_][0];
            var36 += data_020e70f4[var37][var33->unknown_f_][0];
        }
        if (arg0->unknown_5a4_ & 1) {
            if (inline_02024518(var33->unknown_e_)) continue;
        }
        if (!func_02024d48(var33, arg0->unknown_9c0_)) continue;
        func_0202756c(arg0, (var35 + 0x7c) << 12, (var36 + 0x5c) << 12, var33->unknown_c_, var33->unknown_e_, 0,
                                 var33->unknown_d_, 0xff, 0x1000, 0x1000);
    }
    func_02023b5c(arg0, arg0->unknown_44_, arg0->unknown_48_, 0x7c, 0x5c, 0);
    func_02023d84(arg0, var9, var6, arg0->unknown_44_, arg0->unknown_48_, 0x7c, 0x5c, 0);
}
