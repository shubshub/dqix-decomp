#include "Resource/ActionDataTables.h"
#include "GameState/GameState.h"
#include <globaldefs.h>

#if defined(jpn)
#define RG(u, j) (j)
#else
#define RG(u, j) (u)
#endif

struct SePlayer;
struct Obj02048350;
void *SearchBothTables02079e2c(char *p, int key);
GameObject *GetCombatantChecked_0200ff94(GameState *gs, int id);
extern "C" int *func_0202ae18(void);
extern "C" void *__clear(void *dst, int count);
int CopyOutRegion0x571d_020114ec(char *dst, void *src);
void ConsumeCounter02048350(struct Obj02048350 *p, int a);
int CheckField0NonZero_0202b7d8(int *p);
void SePlayer_Play(struct SePlayer *p, int a, int b);
void InitStateArray02157ce0(char *p);
extern "C" void func_ov002_021536e0(void *p);
extern "C" int func_ov002_021536ec(void *a, void *b, int c);
extern "C" void func_ov016_0218b5c0(int a, int b);
extern "C" void func_ov017_021c9e00(signed char a, int b, int c, int d);
extern "C" int g_sePlayer;

struct Struct_ov002_021594e8_3 {
    char *unknown_0_;
    int unknown_4_;
    unsigned int unknown_8_0_ : 8;
    unsigned int unknown_9_0_ : 2;
    unsigned int unknown_9_2_ : 2;
    unsigned int unknown_9_4_ : 20;
};
struct Struct_01ff91ac_26 {
    unsigned char unknown_0_[4];
    unsigned char unknown_4_;
    unsigned char unknown_5_;
};
struct Struct_ov002_021594e8 {
    short unknown_0_;
    signed char unknown_2_;
    unsigned char unknown_3_;
    signed char unknown_4_[4];
    struct Struct_01ff91ac_26 unknown_8_[4];
    struct Struct_01ff91ac_26 unknown_20_[4];
    int unknown_38_;
};
struct Struct_ov002_021594e8_2 {
#if defined(jpn)
    char unknown_0_[0x1a80];
    int unknown_1bb8_;
    int unknown_1bbc_;
    char unknown_1a88_[0x1aee - 0x1a88];
#else
    char unknown1_0_[0x1bb8];
    int unknown_1bb8_;
    int unknown_1bbc_;
    char unknown_1bc0_[0x1c26 - 0x1bc0];
#endif
    short unknown_1c26_;
    short unknown_1c28_;
    short unknown_1c2a_;
};

// USA: func_ov002_021594e8
extern "C" ARM void func_ov002_021594e8(struct Struct_ov002_021594e8_2 *arg0, short arg1, signed char arg2, int arg3) {
    struct Struct_ov002_021594e8 var0;
    struct Struct_ov002_021594e8 var1;
    unsigned char var2[4];
    void *var3;
    void *var4;

    arg0->unknown_1c26_                        = arg1;
    GameState *var5                     = GameState::GetInstance();
    Struct_02108e10* var6                         = func_020797dc();
    struct Struct_ov002_021594e8_3 *var7 = (struct Struct_ov002_021594e8_3 *) func_02079e2c((char*)var6, arg0->unknown_1c26_);
    GameObject *var8                  = func_0200ff94(var5, arg2);
    int *var9                     = func_0202ae18();
    int var10                         = 0;
    if (arg0->unknown_1bb8_ == RG(0x17, 0x18)) {
        arg0->unknown_1c28_  = 0x232d;
        arg0->unknown_1c2a_ = 0x232b;
        int var11   = 0;
        if (arg0->unknown_1c26_ == 0x22) {
            func_ov002_02157ce0((char *) &var0);
            func_ov002_02157ce0((char *) &var0);
            struct Struct_ov002_021594e8_3 *var12 = (struct Struct_ov002_021594e8_3 *) func_02079e2c((char*)var6, arg0->unknown_1c26_);
            if (var12 != NULL) {
                __clear(var2, 4);
                int var13 = func_020114ec((char *) var5, var2);
                if (var12->unknown_9_2_ & 1) {
                    var0.unknown_0_    = arg0->unknown_1c26_;
                    var0.unknown_2_ = arg2;
                    var0.unknown_3_ = var13;
                    for (int var14 = 0; var14 < var13; var14++) {
                        var0.unknown_4_[var14] = var2[var14];
                    }
                    func_ov002_021536e0(&var3);
                    var3 = var6;
                    var11 = func_ov002_021536ec(&var3, &var0, 0);
                }
            }
        } else {
            struct Struct_ov002_021594e8_3 *var15 = (struct Struct_ov002_021594e8_3 *) func_02079e2c((char*)var6, arg0->unknown_1c26_);
            if (var15 != NULL && (var15->unknown_9_2_ & 1)) {
                func_ov016_0218b5c0(var11, -1);
                func_ov002_02157ce0((char *) &var1);
                func_ov002_02157ce0((char *) &var1);
                var1.unknown_0_     = arg0->unknown_1c26_;
                var1.unknown_2_  = arg2;
                var1.unknown_3_  = 1;
                var1.unknown_4_[0] = arg3;
                func_ov002_021536e0(&var4);
                var4 = var6;
                var11  = func_ov002_021536ec(&var4, &var1, var11);
            }
        }
        if (var11 != 0) {
            if (arg0->unknown_1c26_ == 0x1f || arg0->unknown_1c26_ == 0x1e || arg0->unknown_1c26_ == 0x20 || arg0->unknown_1c26_ == 0x21) {
                arg0->unknown_1c2a_ = 0x2339;
                var10     = 1;
            } else if (arg0->unknown_1c26_ == 0x23) {
                arg0->unknown_1c2a_ = 0x794c;
                var10     = 1;
            } else if (arg0->unknown_1c26_ == 0x22) {
                arg0->unknown_1c2a_ = 0x2339;
                var10     = 1;
            }
        }
        SePlayer_Play((struct SePlayer *) &g_sePlayer, 0x64, 0);
        p->state     = RG(0x26, 0x29);
        p->nextState = RG(0x17, 0x18);
    }
    if (var10 != 0) {
        func_02048350((struct Struct_02048350_2 *) var8, var7->unknown_8_0_);
        if (func_0202b7d8(var9) != 0) {
            func_ov017_021c9e00(arg2, 0, 0, 1);
        }
    }
}
