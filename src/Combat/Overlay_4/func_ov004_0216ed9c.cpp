#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

#if defined(jpn)
enum { Enum_ov004_0216ed9c_1788 = 0x4ec, Enum_ov004_0216ed9c_2888 = 0x928, Enum_ov004_0216ed9c_1172 = 0x1e4, Enum_ov004_0216ed9c_9088 = 0x120, Enum_ov004_0216ed9c_16384 = 0x6000 };
#else
enum { Enum_ov004_0216ed9c_1788 = 0x6fc, Enum_ov004_0216ed9c_2888 = 0xb48, Enum_ov004_0216ed9c_1172 = 0x494, Enum_ov004_0216ed9c_9088 = 0x2380, Enum_ov004_0216ed9c_16384 = 0x4000 };
#endif

extern "C" int rand(void);

struct Struct_ov004_0216ed9c_2 { int unknown_0_, unknown_4_, unknown_8_; };

class Struct_ov004_0216ed9c_3 {
public:
    virtual void inline_ov004_0216ed9c_2(); virtual void inline_ov004_0216ed9c_3(); virtual void inline_ov004_0216ed9c_4(); virtual void inline_ov004_0216ed9c_5();
    virtual void inline_ov004_0216ed9c_6(); virtual void inline_ov004_0216ed9c_7(); virtual void inline_ov004_0216ed9c_8();
    virtual void inline_ov004_0216ed9c_9(const Struct_ov004_0216ed9c_2* arg0);
};

struct Struct_ov004_021589e8 {
    unsigned int unknown_0_0_ : 12;
    unsigned int unknown_1_4_ : 4;
    unsigned int unknown_2_0_ : 5;
    unsigned int unknown_2_5_ : 5;
    unsigned int unknown_3_2_ : 6;
};

struct Struct_ov004_0216ed9c_4 {
    unsigned int unknown_0_;
    unsigned int unknown_4_;
    unsigned int unknown_8_;
    unsigned short unknown_c_;
    unsigned char unknown_e_[0x20];
    unsigned char unknown_2e_[6];
    signed char unknown_34_;
    Struct_ov004_021589e8 unknown_38_;
    unsigned char unknown_3c_[12];
    int unknown_48_;
};

struct Struct_ov004_02171048_3 {
    unsigned char unknown_0_;
    unsigned char unknown_1_;
    char unknown_2_[2];
    Struct_ov004_0216ed9c_4* unknown_4_;
};
extern Struct_ov004_02171048_3 data_ov004_02171048;

struct Struct_ov004_0217028c { unsigned int unknown_0_[12]; };
extern Struct_ov004_0217028c data_ov004_0217028c;

struct Struct_ov004_0216ed9c {
    unsigned char unknown_0_[0x44];
    Struct_ov004_021589e8 unknown_44_;
};

struct Struct_02072a68_2;
struct Struct_020465c0;
struct Struct_ov004_021583a8_4;
struct Struct_ov004_021583a8_5;
struct Struct_ov004_0215883c_3;
struct Struct_ov004_021583a8;
struct Struct_ov004_021583a8_2;

extern "C" void* func_ov004_0216ea38(void* ctx, int key);
int MessageSystem_GetInstance(void);
int GetBattleSubField0xbcForState_020d4ac8(void);
extern "C" void* func_ov011_021849c8(void*);
extern "C" Struct_ov004_0216ed9c_3* func_ov023_021f6880(void*, int);
extern "C" int func_ov023_021f6f10(void*);
extern "C" void func_ov023_021fb27c(void* node, unsigned short v);
extern "C" void FieldTask_ConnectWifi(void* a, void* b);
int GetFieldromField_021b1fd4_021b1fd4(void* obj);
extern "C" void func_ov023_021fa078(void* obj, void* ctx, unsigned short val, Vec3_0216ed9c* srcVec, int p5, int p6);
unsigned char GetSubByteField34_021b2024(Obj24_021b2024* obj);
unsigned char GetSubByteField35_021b2038(Obj24_021b2038* obj);
void* FindEntryByKey_02072a68(TableA68* table, int key);
#if defined(jpn)
extern "C" void func_0204500c(void* arg0, void* arg1, int arg2);
#define FUNC_0204500C(g, b) func_0204500c(g, b, 0)
enum { Enum_ov004_0216ed9c_2456 = 0x868, Enum_ov004_0216ed9c_2464 = 0x870, Enum_ov004_0216ed9c_92 = 0x28, Enum_ov004_0216ed9c_2400 = 0x800 };
#else
extern "C" void func_0204500c(void* arg0, void* arg1, int arg2, int arg3);
#define FUNC_0204500C(g, b) func_0204500c(g, b, 0, 0xe3)
enum { Enum_ov004_0216ed9c_2456 = 0x998, Enum_ov004_0216ed9c_2464 = 0x9a0, Enum_ov004_0216ed9c_92 = 0x5c, Enum_ov004_0216ed9c_2400 = 0x960 };
#endif
extern "C" unsigned char func_ov017_021b204c(Struct_ov004_0215883c_3* arg0);
extern "C" unsigned char func_ov017_021b1fe8(Struct_ov004_021583a8* arg0);
extern "C" void* func_ov017_021b1fc0(void* arg0);
extern "C" void func_ov011_021848a0(void* arg0, int arg1);
extern "C" int func_020ac7b4(int arg0);
extern "C" int func_ov017_021b1ffc(Struct_ov004_021583a8_2* arg0);
extern "C" void func_02046380(void* arg0);
extern "C" void func_020465c0(Struct_020465c0* arg0, int arg1, int arg2);

static inline char* inline_ov004_0216ed9c(char* arg0) {
    return *(char**)(arg0 + 0x3000 + Enum_ov004_0216ed9c_2888);
}

// USA: func_ov004_0216ed9c
extern "C" ARM int func_ov004_0216ed9c(void* self) {
    Node0216ed9c* node;
    GameState* gs = GameState::GetInstance();
    char* actor = (char*)GetGameResources();
    void* list = *(void**)(actor + 0x3000 + listOffset);
    char* five = GetFive(actor);
    TableA68* table = (TableA68*)func_ov004_0216ea38(self, 4);
    int g = MessageSystem_GetInstance();
    unsigned char state = data_ov004_02171048.ptr->flags2e[0];

    if (var7 == 2) {
        int var8 = func_020d4ac8();
        var0 = func_ov023_021f6880(func_ov011_021849c8(arg0), 0x97);
        if (var0 == 0 || func_ov023_021f6f10(var0) != 1) {
            var0 = 0;
        }
        func_ov023_021fb27c(node, v + 8);
        FieldTask_ConnectWifi(five, list);
        {
            int var9;
            Struct_ov004_0216ed9c_4* var10;
            Struct_ov004_0216ed9c_4* var11;
            int var12;
            int var13;
            Struct_ov004_0216ed9c_3* var14;
            int var15;
            int var16 = func_ov017_021b1fd4(var4) >> 12;
            int var17 = var16 - data_ov004_02171048.unknown_4_->unknown_48_;
            if (var17 == 0) goto spawned;

            for (var13 = 0; var13 < var17; var13++) {
                var9 = rand() % 12;
                var10 = data_ov004_02171048.unknown_4_;
                while (var10->unknown_3c_[var9] >= 10) {
                    var9 = (var9 + 1) % 12;
                }
                var10->unknown_3c_[var9]++;

                var11 = data_ov004_02171048.unknown_4_;
                var12 = var11->unknown_3c_[var9];
                var15 = var11->unknown_48_ + 0x578 + var13;

                var14 = func_ov023_021f6880(func_ov011_021849c8(arg0), var15);
                if (var14 == 0 || func_ov023_021f6f10(var14) != 0) {
                    var14 = 0;
                }
                if (!var14) goto spawned;

                Struct_ov004_0216ed9c_2 var18;
                Struct_ov004_0216ed9c_2 var19;
                var19.unknown_0_ = (var9 * 21) << 12;
                var19.unknown_4_ = (var12 * -19) << 12;
                var19.unknown_8_ = 0;
                var14->inline_ov004_0216ed9c_9(&var19);

                var18.unknown_0_ = (var9 * 21) << 12;
                var18.unknown_4_ = (0xc0 - var12 * 19) << 12;
                var18.unknown_8_ = 0;

                void* var20 = func_ov023_021f6880(func_ov011_021849c8(arg0), 0xffff);
                if (!var20) goto spawned;
                func_ov023_021fa078(var20, arg0, var15, &var18, 0xd000, 0xd000);
            }
            data_ov004_02171048.unknown_4_->unknown_48_ = var16;
        }
spawned:

        unsigned char var21 = func_ov017_021b2024((Struct_ov004_021583a8_4*)var4);
        unsigned char var22 = func_ov017_021b2038((Struct_ov004_021583a8_5*)var4);
        if (data_ov004_02171048.unknown_1_ == 0 && var21 == 5 && var22 == 0) {
            FUNC_0204500C((void*)var6, func_02072a68(var5, 0xcc));
            *(int*)(var6 + Enum_ov004_0216ed9c_2456) = 1;
            data_ov004_02171048.unknown_1_ = 1;
        }
        if (data_ov004_02171048.unknown_0_ == 0 && var21 == 5 && var22 == 5) {
            FUNC_0204500C((void*)var6, func_02072a68(var5, 0xcd));
            *(int*)(var6 + Enum_ov004_0216ed9c_2456) = 1;
            data_ov004_02171048.unknown_0_ = 1;
        }
        if (*(int*)(var2 + 0x4000 + Enum_ov004_0216ed9c_1172) == 0) {
            data_ov004_02171048.unknown_4_->unknown_2e_[0]++;
            GameState::GetInstance();
        }
    } else if (var7 == 3) {
        if (*(int*)(var6 + Enum_ov004_0216ed9c_2464) != 3) return 1;

        Struct_ov004_0216ed9c_3* var23 = func_ov023_021f6880(func_ov011_021849c8(arg0), 0x97);
        if (var23) {
            *((unsigned char*)var23 + 0xc) |= 8;
        }
        char* var24 = *(char**)(var6 + Enum_ov004_0216ed9c_92);
        memset(var24, 0, Enum_ov004_0216ed9c_2400);

        if (func_ov017_021b204c((Struct_ov004_0215883c_3*)var4)) {
            const char* var25 = (const char*)func_02072a68(var5, 0x71);
            memcpy(var24, var25, strlen(var25));
        } else if (func_ov017_021b1fe8((Struct_ov004_021583a8*)var4) & 2) {
            func_ov017_021b1fc0(var4);
            data_ov004_02171048.unknown_4_->unknown_2e_[1] = 1;
            const char* var26 = (const char*)func_02072a68(var5, 0xca);
            int var27 = strlen(var26);
            memcpy(var24, var26, var27);
            if (data_ov004_02171048.unknown_4_->unknown_2e_[3]) {
                const char* var28 = (const char*)func_02072a68(var5, 0xd6);
                memcpy(var24 + var27, var28, strlen(var28));
            }
            func_ov011_021848a0(arg0, 0xca);

            Struct_ov004_0216ed9c_4* var29 = data_ov004_02171048.unknown_4_;
            Struct_ov004_021589e8* var30 = &var29->unknown_38_;
            var30->unknown_2_0_++;
            if (var30->unknown_2_0_ == 0) var30->unknown_2_0_ = 1;
            Struct_ov004_0217028c var31 = data_ov004_0217028c;
            if ((&var31.unknown_0_[-1])[var30->unknown_1_4_] < var30->unknown_2_0_ || var30->unknown_2_0_ == 0) {
                var30->unknown_2_0_ = 1;
                var30->unknown_1_4_++;
                if (var30->unknown_1_4_ > 12) {
                    var30->unknown_1_4_ = 1;
                    var30->unknown_0_0_++;
                }
            }
            memcpy(&((Struct_ov004_0216ed9c*)((char*)var1 + Enum_ov004_0216ed9c_9088 + Enum_ov004_0216ed9c_16384))->unknown_44_, &data_ov004_02171048.unknown_4_->unknown_38_, 4);
            if (!func_020ac7b4(0)) return 0;
            if (!func_020ac7b4(1)) return 0;
        } else {
            const char* var32 = (const char*)func_02072a68(var5, 0xcb);
            memcpy(var24, var32, strlen(var32));
            int var33 = func_ov017_021b1ffc((Struct_ov004_021583a8_2*)var4);
            func_02046380((void*)var6);
            func_020465c0((Struct_020465c0*)var6, 0, var33);
            func_ov011_021848a0(arg0, 0xcb);
            data_ov004_02171048.unknown_4_->unknown_2e_[1] = 0;
        }

        FUNC_0204500C((void*)var6, *(char**)(var6 + Enum_ov004_0216ed9c_92));
        *(int*)(var6 + Enum_ov004_0216ed9c_2456) = 1;
        var4[1] = 1;
        data_ov004_02171048.unknown_4_->unknown_2e_[0] = 0;
        Struct_ov004_0216ed9c_4* var34 = data_ov004_02171048.unknown_4_;
        memset(var34->unknown_3c_, 0, 0xc);
        var34->unknown_48_ = 0;
        return 0;
    }
    return 1;
}
