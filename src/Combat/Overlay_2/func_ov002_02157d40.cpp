#include "Resource/ActionDataTables.h"
#include <globaldefs.h>

#include "Combat/ResourceScriptEntry.h"
#include "Combat/Main/BattleList.h"
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

#if defined(jpn)
#define RG(u, j) (j)
#define FMT(a, b, c, d) func_020474a8(a, b, c, d)
#define ST(x) ((x) == 7 ? 8 : (x) == 0x11 ? 0x12 : (x) == 0x14 ? 0x15 : (x) == 0x26 ? 0x29 : (x) == 0x2b ? 0x2e : (x))
extern "C" void func_020474a8(void* arg0, int arg1, int arg2, char* arg3);
extern "C" GameObject* func_0200ff94(GameState* arg0, int arg1);
#else
#define RG(u, j) (u)
#define FMT(a, b, c, d) func_02046608(a, b, c, d, 0xe3, 0, 1)
#define ST(x) (x)
#endif
struct Struct_ov002_02157d40_19 {
    int unknown_0_;
    int unknown_4_;
    struct Struct_ov002_02157d40* unknown_8_[0xe9];
};
struct Struct_ov002_02157634_8 {
    char* unknown_0_;
    int unknown_4_;
    unsigned int unknown_8_0_ : 8;
    unsigned int unknown_9_0_ : 2;
    unsigned int unknown_9_2_ : 2;
    unsigned int unknown_9_4_ : 20;
};
struct Struct_ov002_02157d40 {
    unsigned short unknown_0_;
    char unknown_2_[0x132];
    struct BaseCombatStats* unknown_134_;
    struct ModifiableCombatStats* unknown_138_;
};
struct GameState;

struct Struct_0201099c_3;
struct Struct_ov002_02157d40_2;
struct Struct_ov002_02157d40_3;
struct Struct_ov002_02157634_6 {
    char unknown_0_[0xc];
    unsigned short unknown_c_;
};
struct Struct_ov002_02157d40_4;
struct Struct_ov002_02157d40_5;
struct Struct_ov002_02157d40_6;
struct Struct_ov002_02157d40_7;
struct Struct_ov002_02157d40_8;
struct Struct_ov002_02157d40_9;
struct Struct_ov002_02157d40_10;
struct Struct_ov002_02157d40_11;
struct Struct_ov002_02157d40_12;
struct Struct_ov002_02157d40_13;
struct Struct_02001a40;

extern "C" void* __clear(void* arg0, int arg1);
extern "C" void* func_02012fe4(void);
extern "C" void* func_020e2ff8(void);
extern "C" void* func_02079e2c(char* arg0, int arg1);
extern "C" void* func_0202ae18(void);
extern "C" int func_0202053c(void* arg0);
extern "C" void func_020465f0(unsigned char* arg0, int arg1, unsigned char arg2);
extern "C" void func_ov017_021c2b28(void* arg0, unsigned char arg1, unsigned char arg2);
extern "C" void func_020e3428(void* arg0, int arg1);
extern "C" int func_0201b588(int arg0);
extern "C" int func_0201b5b0(int arg0);
extern "C" void func_020541a4(struct Struct_ov002_02157d40_5* arg0, unsigned char arg1);
extern "C" void func_020465c0(struct Struct_ov002_02157d40_2* arg0, int arg1, int arg2);
extern "C" int func_0202b7d8(int* arg0);
void* LoadFileIntoMemory(const char* path, void* buf, unsigned int* outSize);
extern "C" void func_02048418(unsigned char* arg0, unsigned short arg1);
extern "C" void func_020a8170(struct Struct_ov002_02157634_6* arg0);
extern "C" int func_020114ec(char* arg0, void* arg1);
extern "C" int func_0202663c(unsigned char* arg0);
extern "C" void func_02046a3c(struct Struct_ov002_02157d40_9* arg0, struct Struct_ov002_02157d40_10* arg1);
extern "C" void func_02042058(char* arg0, const char* arg1);
extern "C" void func_02026644(char* arg0);
extern "C" void func_ov017_021c2744(struct Struct_ov002_02157d40_13* arg0);
extern "C" int func_020e0434(struct Struct_0201099c_3* arg0, int arg1);
extern "C" void func_0208247c(void* arg0);
extern "C" void func_02048350(struct Struct_ov002_02157d40_8* arg0, int arg1);
extern "C" void func_ov002_02157ce0(char* arg0);
extern "C" void func_02046574(struct Struct_ov002_02157d40_6* arg0, int arg1, char* arg2);
extern "C" int func_02026a28(struct Struct_ov002_02157d40_11* arg0);
extern "C" int func_02026abc(struct Struct_ov002_02157d40_12* arg0);
extern "C" void func_ov017_021c2688(unsigned char* arg0);
extern "C" void func_02026678(char* arg0);
extern "C" int func_0201bc94(struct Struct_ov002_02157d40_4* arg0);
extern "C" void func_ov017_021d27a0(int, int, int);
extern "C" int func_020421a0(void);
extern "C" void func_ov017_021acd30(char* arg0, unsigned char arg1, unsigned char arg2, unsigned char arg3);
extern "C" int func_02026a78(char* arg0);
extern "C" void func_0205eaa0(struct Struct_ov002_02157d40_7* arg0, int arg1, int arg2);
struct GameObject;
extern "C" void func_020e4c74(void*, GameObject*);
extern "C" void func_020e4bf4(void* arg0, int arg1);
extern "C" int func_02048448(struct Struct_ov002_02157d40_3* arg0, int arg1);

extern "C" void* memcpy(void* arg0, const void* arg1, unsigned int arg2);
extern "C" void* memset(void* arg0, int arg1, unsigned int arg2);
extern "C" int sprintf(char* arg0, const char* arg1, ...);


extern "C" int func_02026780(void* arg0, void* arg1, unsigned int arg2);
extern "C" int func_0202c540(void* arg0);
extern "C" void func_02046380(void* arg0);
extern "C" void func_02046608(void* arg0, int arg1, int arg2, char* arg3, int arg4, int arg5, int arg6);
extern "C" void func_02052d7c(void* arg0, signed char arg1, int arg2);
extern "C" void func_0207c378(void* arg0, short arg1, int arg2, unsigned int arg3);

extern "C" void func_020a818c(void* arg0, void* arg1);
extern "C" void func_020a8304(void* arg0);
extern "C" void func_ov002_021536e0(void* arg0);
extern "C" int func_ov002_021536ec(void* arg0, void* arg1, int arg2);
extern "C" void func_ov002_0216c42c(void* arg0, void* arg1, void* arg2);
extern "C" void func_ov016_0218b5c0(int arg0, int arg1);
extern "C" void func_ov017_0218f5a4(void* arg0, int arg1, int arg2, int arg3, int arg4);
extern "C" int func_ov017_0219ff58(int arg0, int arg1, int arg2, int arg3);
extern "C" int func_ov017_021ab860(signed char arg0);
extern "C" void func_ov017_021c12fc(void* arg0, int arg1, int arg2);
static inline short* inline_ov002_02157d40(char* arg0) {
    int* var0 = *(int**)(arg0 + 0x3000 + RG(0x71c, 0x50c));
    return (short*)((char*)var0 + 0x22);
}
extern "C" void func_ov017_021c3fb4(signed char arg0, int arg1);
extern "C" void func_ov017_021c4418(signed char arg0, int arg1);
extern "C" void func_ov017_021c9e00(signed char arg0, int arg1, int arg2, int arg3);

extern int data_02108760;
extern unsigned char data_ov002_0216c992;
extern int data_ov002_0216cf51;
extern int data_0211e33c;
extern int data_ov002_0216cf66;

struct Struct_ov002_02157d40_14 {
    unsigned char unknown_0_0_ : 4;
    unsigned char unknown_0_4_ : 4;
};
struct Struct_ov002_02157d40_15 {
    int unknown_0_;
    int unknown_4_;
    unsigned int unknown_8_0_ : 4;
    unsigned int unknown_8_4_ : 14;
    unsigned int unknown_a_2_ : 1;
    unsigned int unknown_a_3_ : 13;
    int unknown_c_;
    int unknown_10_;
    int unknown_14_;
    short unknown_18_;
    short unknown_1a_;
    int unknown_1c_;
};
struct Struct_ov002_02157d40_16 {
    char unknown_0_[0x138];
    int unknown_138_[0x17];
    struct Struct_ov002_02157d40_15 unknown_194_[11];
    char unknown_2f4_[0x277];
    struct Struct_ov002_02157d40_14 unknown_56b_;
    char unknown_56c_[RG(0x3e4, 0x34c)];
    int unknown_950_;
};
struct Struct_ov002_02157d40_17 {
    unsigned short unknown_0_;
    short unknown_2_;
    short unknown_4_;
    char unknown_6_[0x12a];
    int* unknown_130_;
    char* unknown_134_;
    char unknown_138_[RG(0x18, 0xc)];
    struct Struct_ov002_02157d40_16* unknown_150_;
};
struct Struct_ov002_02157d40_18 {
    char unknown_0_[0xf78];
    unsigned char unknown_f78_[4];
    unsigned char unknown_f7c_;
};
struct Struct_ov002_02157634_2 {
    char unknown_0_[8];
#if !defined(jpn)
    char unknown_8_[0xc];
    char unknown_14_[0xc];
#endif
    char unknown_20_[RG(0x880, 0x7fc)];
    char unknown_8a0_[RG(0x1318, 0x127c)];
    int unknown_1bb8_;
    int unknown_1bbc_;
    int unknown_1bc0_;
    char unknown_1bc4_[0xc];
    char* unknown_1bd0_;
    char* unknown_1bd4_;
    char unknown_1bd8_[0x48];
    signed char unknown_1c20_;
    signed char unknown_1c21_;
    char unknown_1c22_[4];
    short unknown_1c26_;
    short unknown_1c28_;
    short unknown_1c2a_;
    char unknown_1c2c_[5];
    unsigned char unknown_1c31_;
    char unknown_1c32_[RG(6, 2)];
    int unknown_1c38_;
    int unknown_1c3c_[0xe];
    int unknown_1c74_;
    char unknown_1c78_[2];
    unsigned char unknown_1c7a_;
    unsigned char unknown_1c7b_;
    char unknown_1c7c_[0x4a];
    unsigned char unknown_1cc6_;
    unsigned char unknown_1cc7_;
    char unknown_1cc8_[0x3c];
    char unknown_1d04_[RG(0x770, 0x6dc)];
    struct Struct_ov002_02157634_6* unknown_2474_;
    char unknown_2478_[0x10];
    short unknown_2488_;
    unsigned char unknown_248a_;
    unsigned char unknown_248b_;
    unsigned char unknown_248c_;
    char unknown_248d_[3];
    int unknown_2490_;
    int unknown_2494_;
    char unknown_2498_[0x8a];
    unsigned char unknown_2522_;
    unsigned char unknown_2523_;
    char unknown_2524_[0xc];
    int unknown_2530_;
};
struct Struct_ov002_02157634_3 {
    unsigned char unknown_0_[4];
    unsigned char unknown_4_;
    unsigned char unknown_5_;
};
struct Struct_ov002_02157634_4 {
    short unknown_0_;
    signed char unknown_2_;
    unsigned char unknown_3_;
    signed char unknown_4_[4];
    struct Struct_ov002_02157634_3 unknown_8_[4];
    struct Struct_ov002_02157634_3 unknown_20_[4];
    int unknown_38_;
};
struct Struct_ov002_02157d40_20 {
    signed char unknown_0_[11];
};
struct Struct_ov002_02157d40_21 {
    void* unknown_0_;
    void* unknown_4_;
    unsigned int unknown_8_;
    unsigned int unknown_c_;
    unsigned char unknown_10_[4];
    void* unknown_14_;
    unsigned char unknown_18_[4];
    struct Struct_ov002_02157d40_20 unknown_1c_;
    struct Struct_ov002_02157634_4 unknown_28_;
    struct Struct_ov002_02157634_4 unknown_64_;
    char unknown_a0_[0x28];
    struct Struct_ov002_02157634_4 unknown_c8_;
    int unknown_104_[0x15];
};

struct Struct_ov002_02157d40_22 {
    char unknown_0_[RG(0x20, 0xe8)];
    signed char unknown_20_;
    signed char unknown_21_;
    char unknown_22_[4];
    short unknown_26_;
    short unknown_28_;
    short unknown_2a_;
};
static inline struct Struct_ov002_02157d40_22* inline_ov002_02157d40_2(struct Struct_ov002_02157634_2* arg0) {
    struct Struct_ov002_02157d40_22* var0 = (struct Struct_ov002_02157d40_22*)((char*)arg0 + RG(0x1c00, 0x1a00));
    return var0;
}
static inline int inline_ov002_02157d40_3(struct Struct_ov002_02157d40_16* arg0) {
    return arg0->unknown_138_[arg0->unknown_950_];
}

static inline int inline_ov002_02157d40_4(struct Struct_ov002_02157d40_17* arg0) { SDK_NULL_ASSERT(arg0); return arg0->unknown_4_; }
static inline char* inline_ov002_02157d40_5(struct Struct_ov002_02157d40_17* arg0) { SDK_NULL_ASSERT(arg0); return arg0->unknown_134_; }

enum Enum_ov002_02157d40 { Enum_ov002_02157d40_m1 = -1, Enum_ov002_02157d40_9004 = 0x232c, Enum_ov002_02157d40_9018 = 0x233a };

// USA: func_ov002_02157d40
extern "C" ARM void func_ov002_02157d40(struct BattleMenu* p) {
    struct Frame f;
    char* tbl;
    struct BattleStruct* gs = (BattleStruct*)GameState::GetInstance();
    int word = (int)((GameState*)gs)->GetResources();
    unsigned short* obj = (unsigned short*)func_02012fe4();
    ActionDataTables* actionTables = GetData02108e10_020797dc();
    tbl = (char*)actionTables;
    struct TableEntry* entryA = (struct TableEntry*)SearchBothTables02079e2c(tbl, p->command);
    #if defined(jpn)
    struct Struct_ov002_02157d40_17* var7 = (struct Struct_ov002_02157d40_17*)(Struct_ov002_02157d40*)func_0200ff94((GameState*)var2, arg0->unknown_1c20_);
#else
    struct Struct_ov002_02157d40_17* var7 = (struct Struct_ov002_02157d40_17*)(Struct_ov002_02157d40*)func_0200ff1c((GameState*)var2, arg0->unknown_1c20_);
#endif
    int* var8 = (int*)func_0202ae18();
    int var9 = 0;
    int var10;
    bool var11;

    if (arg0->unknown_1bb8_ == ST(0x11)) {

        arg0->unknown_1c28_ = 0x232d;
        arg0->unknown_1c2a_ = -1;
        var10 = 0;
        var11 = 0;
        if (arg0->unknown_1c26_ == 0xd7) {
            arg0->unknown_1c28_ = 0x233b;
        }
        if (func_02048448((struct Struct_ov002_02157d40_3*)var7, (unsigned short)var6->unknown_8_0_) == 0) {
            arg0->unknown_1c28_ = 0x232f;
            arg0->unknown_1c2a_ = -1;
            arg0->unknown_248a_ = 0;
            arg0->unknown_2488_ = -1;
            arg0->unknown_1bb8_ = ST(0x26);
            arg0->unknown_1bbc_ = ST(0x11);
            return;
        }
        if (arg0->unknown_1c26_ == 0xd7) {
            var9 = 1;
            var10 = 1;
            char* var12 = (char*)GetGameResources();
            *inline_ov002_02157d40(var12) = arg0->unknown_1c20_;
            func_ov017_021c12fc(var12, 1, 0);
        } else if (arg0->unknown_1c26_ == 0xd9) {
            var9 = 1;
            if (func_0201bc94((struct Struct_ov002_02157d40_4*)func_02012fe4()) != 0) {
                func_ov016_0218b5c0(0, -1);
                arg0->unknown_1c21_ = arg0->unknown_1c20_;
                arg0->unknown_1c28_ = 0x754a;
                var10 = 1;
                struct Struct_ov002_02157d40_18* var13 = (struct Struct_ov002_02157d40_18*)func_02010828((GameState*)var2);
                for (int var14 = 0; var14 < var13->unknown_f7c_; var14++) {
                    func_020541a4((struct Struct_ov002_02157d40_5*)(Struct_ov002_02157d40*)((GameState*)var2)->GetPartyMemberByIndex(var13->unknown_f78_[var14]), 0);
                }
            } else {
                arg0->unknown_1c28_ = 0x754e;
                arg0->unknown_248a_ = 1;
                arg0->unknown_2488_ = 0x754f;
                var9 = 0;
            }
        } else if (arg0->unknown_1c26_ == 0xcd) {
            inline_ov002_02157d40_2(arg0)->unknown_2a_ = -1;
            arg0->unknown_248a_ = 1;
            int var15 = func_ov017_021ab860(arg0->unknown_1c20_);
            if (var15 == 0) {
                arg0->unknown_2488_ = 0x232b;
            } else if (var15 == 1) {
                arg0->unknown_2488_ = 0x2338;
            } else if (var15 == 3) {
                arg0->unknown_1c28_ = 0x233c;
                arg0->unknown_1c21_ = arg0->unknown_1c20_;
                var10 = 1;
                arg0->unknown_248a_ = 0;
                var9 = 1;
                arg0->unknown_2488_ = -1;
            }
        } else if (arg0->unknown_1c26_ == 0x1e || arg0->unknown_1c26_ == 0x1f || arg0->unknown_1c26_ == 0x20 || arg0->unknown_1c26_ == 0x21 || arg0->unknown_1c26_ == 0x23 || arg0->unknown_1c26_ == 0x26 || arg0->unknown_1c26_ == 0x27) {
            arg0->unknown_1bb8_ = ST(7);
            var11 = 1;
        } else if (arg0->unknown_1c26_ == 0x22 || arg0->unknown_1c26_ == 0x310) {
            func_ov002_02157ce0((char*)&var0.unknown_c8_);
            func_ov002_02157ce0((char*)&var0.unknown_c8_);
            int var16 = 0;
            struct Struct_ov002_02157634_8* var17 = (struct Struct_ov002_02157634_8*)func_02079e2c(var1, arg0->unknown_1c26_);
            if (var17 != 0) {
                __clear(var0.unknown_18_, 4);
                int var18 = func_020114ec((char*)var2, var0.unknown_18_);
                if (var17->unknown_9_2_ & 1) {
                    func_ov016_0218b5c0(0, -1);
                    var0.unknown_c8_.unknown_0_ = arg0->unknown_1c26_;
                    var0.unknown_c8_.unknown_2_ = arg0->unknown_1c20_;
                    var0.unknown_c8_.unknown_3_ = var18;
                    for (int var19 = 0; var19 < var18; var19++) {
                        var0.unknown_c8_.unknown_4_[var19] = var0.unknown_18_[var19];
                    }
                    func_ov002_021536e0(&var0.unknown_14_);
                    var0.unknown_14_ = var1;
                    var16 = func_ov002_021536ec(&var0.unknown_14_, &var0.unknown_c8_, 0);
                }
                int var20 = 0;
                struct Struct_ov002_02157634_3* var21 = var0.unknown_c8_.unknown_8_;
                struct Struct_ov002_02157634_3* var22 = var0.unknown_c8_.unknown_20_;
                int var23;
                for (var23 = 0; var23 < var0.unknown_c8_.unknown_3_; var23++) {
                    struct Struct_ov002_02157634_3* var24 = &var21[var23];
                    struct Struct_ov002_02157634_3* var25;
                    if (var24->unknown_4_ != 0 || (var25 = &var22[var23])->unknown_4_ != 0) {
                        var20 = 1;
                        break;
                    }
                }
                if (var20) {
                    func_ov002_0216c42c(arg0, &var0.unknown_c8_, var17);
                    arg0->unknown_1cc6_ = 0;
                    arg0->unknown_1cc7_ = 1;
                    func_ov002_02157ce0((char*)(arg0->unknown_1cc8_));
                    memcpy(arg0->unknown_1cc8_, &var0.unknown_c8_, 0x3c);
                    arg0->unknown_1c28_ = -1;
                    arg0->unknown_1c2a_ = -1;
                    arg0->unknown_1bb8_ = ST(0x26);
                    arg0->unknown_1bbc_ = ST(0x26);
                    arg0->unknown_2488_ = -1;
                    arg0->unknown_248a_ = 0;
                    arg0->unknown_1c7a_ = 1;
                    arg0->unknown_1c7b_ = 0x14;
                    arg0->unknown_1c74_ = 0x1e;
                    arg0->unknown_1bc0_ = 0;
                    return;
                }
                unsigned char* var26 = (unsigned char*)func_020421a0();
                func_02046380(var26);
                memset(arg0->unknown_1bd0_, 0, RG(0x960, 0x800));
                var1 = arg0->unknown_1bd0_;
                if (var7 != 0) {
                    func_02046574((struct Struct_ov002_02157d40_6*)var26, 0, var7->unknown_134_);
#if !defined(jpn)
                    func_020e4bf4(arg0->unknown_8_, inline_ov002_02157d40_4(var7));
                    *(void**)var26 = arg0->unknown_8_;
#endif
                }
                func_02046574((struct Struct_ov002_02157d40_6*)var26, 1, var17->unknown_0_);
                if (var16 != 0) {
                    FMT(var26, 0xc, func_020e0434((struct Struct_0201099c_3*)(arg0->unknown_20_), 0x232d), (char*)(var1 + RG(0x860, 0x700)));
                    func_02042058(arg0->unknown_1bd0_, (const char*)(var1 + RG(0x860, 0x700)));
                    struct Struct_ov002_02157634_3* var27 = var0.unknown_c8_.unknown_8_;
                    for (int var28 = 0; var28 < var0.unknown_c8_.unknown_3_; var28++) {
                        Enum_ov002_02157d40 var29;
                        if (var27[var28].unknown_0_[0] == 3) {
                            var29 = Enum_ov002_02157d40_9004;
                        } else {
                            var29 = Enum_ov002_02157d40_9018;
                        }
                        if (var29 < 0) {
                            continue;
                        }
                        struct Struct_ov002_02157d40_17* var30 = (struct Struct_ov002_02157d40_17*)(Struct_ov002_02157d40*)func_0200ff1c((GameState*)var2, var0.unknown_c8_.unknown_4_[var28]);
                        if (var30 == 0) {
                            continue;
                        }
                        func_02046380(var26);
                        func_02046574((struct Struct_ov002_02157d40_6*)var26, 2, inline_ov002_02157d40_5(var30));
#if !defined(jpn)
                        func_020e4bf4(arg0->unknown_14_, var0.unknown_c8_.unknown_4_[var28]);
                        *(void**)(var26 + 0x10) = arg0->unknown_14_;
#endif
                        func_020465c0((struct Struct_ov002_02157d40_2*)var26, 9, var30->unknown_4_);
                        FMT(var26, 0xc, func_020e0434((struct Struct_0201099c_3*)(arg0->unknown_20_), var29), (char*)(var1 + RG(0x860, 0x700)));
                        func_02042058(arg0->unknown_1bd0_, (const char*)func_020e0434((struct Struct_0201099c_3*)(arg0->unknown_20_), 8));
                        func_02042058(arg0->unknown_1bd0_, (const char*)(var1 + RG(0x860, 0x700)));
                    }
                    func_02048350((struct Struct_ov002_02157d40_8*)var7, var17->unknown_8_0_);
                    if (func_0202b7d8(var8) != 0) {
                        func_ov017_021c9e00(arg0->unknown_1c20_, 0, 0, 1);
                    }
                } else {
                    struct Struct_ov002_02157d40* var31 = (Struct_ov002_02157d40*)((GameState*)var2)->GetUnknownGameObject();
                    if (var31 != 0) {
                        func_02046574((struct Struct_ov002_02157d40_6*)var26, 2, ((struct Struct_ov002_02157d40_17*)var31)->unknown_134_);
#if !defined(jpn)
                        func_020e4c74(arg0->unknown_14_, (GameObject*)(Struct_ov002_02157d40*)((GameState*)var2)->GetUnknownGameObject());
                        *(void**)(var26 + 0x10) = arg0->unknown_14_;
#endif
                    }
                    func_02042058((char*)(var1 + RG(0x860, 0x700)), (const char*)func_020e0434((struct Struct_0201099c_3*)(arg0->unknown_20_), 0x2333));
                    func_02042058((char*)(var1 + RG(0x860, 0x700)), (const char*)func_020e0434((struct Struct_0201099c_3*)(arg0->unknown_20_), 8));
                    if (var18 == 1) {
                        func_02042058((char*)(var1 + RG(0x860, 0x700)), (const char*)func_020e0434((struct Struct_0201099c_3*)(arg0->unknown_20_), 0x2334));
                    } else {
                        func_02042058((char*)(var1 + RG(0x860, 0x700)), (const char*)func_020e0434((struct Struct_0201099c_3*)(arg0->unknown_20_), 0x2335));
                    }
                    FMT(var26, 0xc, (int)(var1 + RG(0x860, 0x700)), arg0->unknown_1bd0_);
                }
                arg0->unknown_1c31_ = 1;
                memcpy(arg0->unknown_1bd4_, arg0->unknown_1bd0_, RG(0x960, 0x800));
                arg0->unknown_2488_ = -1;
                arg0->unknown_248a_ = 0;
            }
        } else if (arg0->unknown_1c26_ == 0xca) {
            if (func_ov017_0219ff58(var3, 1, 0, 0) != 0) {
                var10 = 1;
                func_ov017_021acd30((char*)var3, 0, 0, 0);
            } else {
                ((SafeAllocator*)arg0->unknown_8a0_)->Reset();
                arg0->unknown_2474_ = (struct Struct_ov002_02157634_6*)((SafeAllocator*)arg0->unknown_8a0_)->Allocate(0x10);
                func_020a8170(arg0->unknown_2474_);
                func_020a818c(arg0->unknown_2474_, arg0->unknown_8a0_);
                func_020a8304(arg0->unknown_2474_);
                if (arg0->unknown_2474_->unknown_c_ == 0) {
                    arg0->unknown_1c2a_ = -1;
                    arg0->unknown_248a_ = 1;
                    arg0->unknown_2488_ = 0x2338;
                    ((SafeAllocator*)arg0->unknown_8a0_)->Reset();
                    arg0->unknown_2474_ = 0;
                } else {
                    arg0->unknown_1bb8_ = ST(0x14);
                    arg0->unknown_1bc0_ = 0;
                    return;
                }
            }
        } else if (arg0->unknown_1c26_ == 0xcf) {
            unsigned char* var32 = (unsigned char*)GetGameResources();
            unsigned char* var33;
            unsigned char* var34 = *(unsigned char**)(var32 + RG(0x3bac, 0x398c));
            var33 = *(unsigned char**)(var32 + RG(0x36fc, 0x34ec));
            if (var34[2] == 0) {
                func_ov017_021c2744((struct Struct_ov002_02157d40_13*)var34);
                *(int*)(var34 + 0x14) = var7->unknown_4_;
                func_02046a3c((struct Struct_ov002_02157d40_9*)var33, (struct Struct_ov002_02157d40_10*)var34);
            }
            arg0->unknown_1bb8_ = ST(0x2b);
            arg0->unknown_1bbc_ = ST(0x2b);
            return;
        } else if (arg0->unknown_1c26_ == 0xd0) {
            unsigned char* var35 = (unsigned char*)func_020421a0();
            memset(arg0->unknown_1bd0_, 0, RG(0x960, 0x800));
            var1 = arg0->unknown_1bd0_;
            struct Struct_ov002_02157d40_17* var36 = (struct Struct_ov002_02157d40_17*)(Struct_ov002_02157d40*)func_0200ff1c((GameState*)var2, arg0->unknown_1c20_);
            if (var36 != 0) {
                func_02046380(var35);
                func_02046574((struct Struct_ov002_02157d40_6*)var35, 0, var36->unknown_134_);
#if !defined(jpn)
                func_020e4bf4(arg0->unknown_8_, arg0->unknown_1c20_);
                *(void**)var35 = arg0->unknown_8_;
#endif
                FMT(var35, 0xc, func_020e0434((struct Struct_0201099c_3*)(arg0->unknown_20_), 0x7537), (char*)(var1 + RG(0x860, 0x700)));
                func_02042058(arg0->unknown_1bd0_, (const char*)(var1 + RG(0x860, 0x700)));
            }
            __clear(var0.unknown_10_, 4);
            int var37 = func_020114ec((char*)var2, var0.unknown_10_);
            int* var38 = var0.unknown_104_;
            int var39;
            for (var39 = 0; var39 < var37; var39++) {
                struct Struct_ov002_02157d40_17* var40 = (struct Struct_ov002_02157d40_17*)(Struct_ov002_02157d40*)func_0200ff1c((GameState*)var2, var0.unknown_10_[var39]);
                if (var40 == 0) {
                    continue;
                }
                struct Struct_ov002_02157d40_16* var41 = var40->unknown_150_;
                int var42;
                if (var41 != 0) {
                    var42 = var41->unknown_56b_.unknown_0_0_ != 0;
                } else {
                    var42 = 0;
                }
                if (var42) {
                    continue;
                }
                func_02046380(var35);
                func_02046574((struct Struct_ov002_02157d40_6*)var35, 0, var40->unknown_134_);
#if !defined(jpn)
                func_020e4bf4(arg0->unknown_8_, var0.unknown_10_[var39]);
                *(void**)var35 = arg0->unknown_8_;
#endif
                int var43;
                if (func_0202053c((void*)var40) == 0x63) {
                    var43 = 0x7539;
                } else {
                    BackgroundLoader::AddLockGlobal();
                    var41 = var40->unknown_150_;
                    sprintf(var0.unknown_a0_, (const char*)&data_ov002_0216cf51, var41->unknown_950_);
                    void* var44 = LoadFileIntoMemory(var0.unknown_a0_, &data_0211e33c, &var0.unknown_c_);
                    func_0208247c(var0.unknown_104_);
                    if (var44 != 0) {
                        func_02082490(var0.unknown_104_, var44, var0.unknown_c_, func_0202053c((void*)var40) + 1, 0);
                    }
                    BackgroundLoader::RemoveLockGlobal();
                    int var45 = *var38 - inline_ov002_02157d40_3(var40->unknown_150_);
                    if (var45 <= 0) {
                        var43 = 0x753a;
                    } else {
                        func_020465c0((struct Struct_ov002_02157d40_2*)var35, 0, var45);
                        func_020465f0(var35, 0, 0);
                        var43 = 0x7538;
                    }
                }
                memset(var1 + RG(0x860, 0x700), 0, 0x100);
                FMT(var35, 0xc, func_020e0434((struct Struct_0201099c_3*)(arg0->unknown_20_), var43), (char*)(var1 + RG(0x860, 0x700)));
                func_02042058(arg0->unknown_1bd0_, (const char*)func_020e0434((struct Struct_0201099c_3*)(arg0->unknown_20_), 8));
                func_02042058(arg0->unknown_1bd0_, (const char*)(var1 + RG(0x860, 0x700)));
            }
            arg0->unknown_1c31_ = 1;
            memcpy(arg0->unknown_1bd4_, arg0->unknown_1bd0_, RG(0x960, 0x800));
            arg0->unknown_2488_ = -1;
            arg0->unknown_248a_ = 0;
            var10 = 1;
        } else if (arg0->unknown_1c26_ == 0xd1) {
            arg0->unknown_1bb8_ = ST(7);
            var11 = 1;
        } else if (arg0->unknown_1c26_ == 0xd2) {
            arg0->unknown_248b_ = 1;
            unsigned char* var46;
            unsigned char* var47 = *(unsigned char**)((unsigned char*)var3 + RG(0x3ba8, 0x3988));
            var46 = *(unsigned char**)((unsigned char*)var3 + RG(0x36fc, 0x34ec));
            func_ov017_021c2688(var47);
            var47[0xc] = arg0->unknown_1c20_;
            func_02046a3c((struct Struct_ov002_02157d40_9*)var46, (struct Struct_ov002_02157d40_10*)var47);
            arg0->unknown_1bb8_ = ST(0x2b);
            arg0->unknown_1bbc_ = ST(0x2b);
            return;
        } else if (arg0->unknown_1c26_ == 0xd5) {
            unsigned char* var48 = *(unsigned char**)((unsigned char*)GetGameResources() + RG(0x36d0, 0x34c0));
            arg0->unknown_1c28_ = 0x7543;
            var9 = 1;
            if (func_0202c540(var8) != 0 && func_0201b588(*var4) == 0) {
                arg0->unknown_248a_ = 1;
                arg0->unknown_2488_ = 0x7548;
                var9 = 0;
            } else if (func_0202663c(var48) == 0) {
                func_ov016_0218b5c0(0, -1);
                arg0->unknown_1c21_ = arg0->unknown_1c20_;
                func_02026678((char*)var48);
            } else {
                arg0->unknown_248a_ = 1;
                arg0->unknown_2488_ = 0x232b;
                arg0->unknown_1bb8_ = ST(0x26);
                arg0->unknown_1bbc_ = ST(0x11);
                var9 = 0;
            }
            var10 = 1;
        } else if (arg0->unknown_1c26_ == 0xd3) {
            int var49 = 1;
            unsigned char* var50 = *(unsigned char**)((unsigned char*)GetGameResources() + RG(0x36d0, 0x34c0));
            arg0->unknown_2490_ = 0;
            arg0->unknown_2494_ = 0;
            var9 = var49;
            arg0->unknown_248a_ = var9;
            arg0->unknown_1c28_ = 0x7544;
            if (func_0202c540(var8) != 0) {
                arg0->unknown_2488_ = 0x7549;
                var9 = 0;
            } else {
                if (func_0201b5b0(*var4) != 0) {
                    var49 = 0;
                } else if (func_0202663c(var50) != 0) {
                    arg0->unknown_2490_ = func_02026a28((struct Struct_ov002_02157d40_11*)var50);
                    arg0->unknown_2494_ = func_02026abc((struct Struct_ov002_02157d40_12*)var50);
                } else {
                    func_02026644((char*)var50);
                    BackgroundLoader::AddLockGlobal();
                    var0.unknown_8_ = 0;
                    void* var51 = LoadFileIntoMemory((const char*)&data_ov002_0216cf66, &data_0211e33c, &var0.unknown_8_);
                    if (func_02026780(var50, var51, var0.unknown_8_) == 0) {
                        var49 = 0;
                    } else {
                        func_02026a78((char*)var50);
                        arg0->unknown_2490_ = func_02026a28((struct Struct_ov002_02157d40_11*)var50);
                        arg0->unknown_2494_ = func_02026abc((struct Struct_ov002_02157d40_12*)var50);
                    }
                    BackgroundLoader::RemoveLockGlobal();
                }
                if (var49) {
                    if (arg0->unknown_2490_ > 0 && arg0->unknown_2494_ == 0) {
                        arg0->unknown_2488_ = 0x7546;
                        var10 = 1;
                    } else if (*(int*)&arg0->unknown_2490_ > 0) {
                        arg0->unknown_2488_ = 0x7545;
                        var10 = 1;
                    } else {
                        arg0->unknown_2488_ = 0x7547;
                    }
                } else {
                    arg0->unknown_2488_ = 0x232b;
                    var9 = 0;
                }
            }
            arg0->unknown_1bb8_ = ST(0x26);
            arg0->unknown_1bbc_ = ST(0x26);
        } else if (arg0->unknown_1c26_ == 0xce) {
            unsigned char* var52 = (unsigned char*)GetGameResources();
            unsigned char* var53;
            unsigned char* var54 = *(unsigned char**)(var52 + RG(0x3bb0, 0x3990));
            var53 = *(unsigned char**)(var52 + RG(0x36fc, 0x34ec));
            if (var54[2] == 0) {
                func_ov017_021c2b28(var54, 0, var7->unknown_4_);
                func_02046a3c((struct Struct_ov002_02157d40_9*)var53, (struct Struct_ov002_02157d40_10*)var54);
            }
            arg0->unknown_1c28_ = 0x233c;
            var9 = 1;
            var10 = 1;
            arg0->unknown_1c21_ = arg0->unknown_1c20_;
        } else if (arg0->unknown_1c26_ == 0xa2 || arg0->unknown_1c26_ == 0xa4) {
            arg0->unknown_1c21_ = arg0->unknown_1c20_;
            int var55 = 0;
            struct Struct_ov002_02157634_8* var56 = (struct Struct_ov002_02157634_8*)func_02079e2c(var1, arg0->unknown_1c26_);
            if (var56 != 0 && (var56->unknown_9_2_ & 1)) {
                func_ov016_0218b5c0(var55, -1);
                func_ov002_02157ce0((char*)&var0.unknown_64_);
                func_ov002_02157ce0((char*)&var0.unknown_64_);
                var0.unknown_64_.unknown_0_ = arg0->unknown_1c26_;
                var0.unknown_64_.unknown_2_ = arg0->unknown_1c20_;
                var0.unknown_64_.unknown_3_ = 1;
                var0.unknown_64_.unknown_4_[0] = arg0->unknown_1c21_;
                func_ov002_021536e0(&var0.unknown_4_);
                var0.unknown_4_ = var1;
                var55 = func_ov002_021536ec(&var0.unknown_4_, &var0.unknown_64_, var55);
            }
            if (arg0->unknown_1c26_ == 0xa2) {
                arg0->unknown_1c28_ = 0x754c;
            } else if (arg0->unknown_1c26_ == 0xa4) {
                arg0->unknown_1c28_ = 0x754b;
            }
            arg0->unknown_1c2a_ = -1;
            if (var55 != 0) {
                arg0->unknown_248a_ = 1;
                if (arg0->unknown_1c26_ == 0xa2) {
                    arg0->unknown_2488_ = 0x754d;
                    arg0->unknown_248c_ = 1;
                } else if (arg0->unknown_1c26_ == 0xa4) {
                    arg0->unknown_2488_ = 0x232c;
                    arg0->unknown_248c_ = 1;
                }
                func_02048350((struct Struct_ov002_02157d40_8*)var7, var56->unknown_8_0_);
                if (func_0202b7d8(var8) != 0) {
                    func_ov017_021c9e00(arg0->unknown_1c20_, 0, 0, 1);
                }
            } else {
                arg0->unknown_248a_ = 1;
                arg0->unknown_2488_ = 0x232b;
            }
        } else {
            arg0->unknown_1c2a_ = -1;
            arg0->unknown_248a_ = 1;
            arg0->unknown_2488_ = 0x232b;
        }
        arg0->unknown_1bc0_ = 0;
        if (var10 != 0) {
            func_0205eaa0((struct Struct_ov002_02157d40_7*)&data_02108760, 0x64, 0);
            arg0->unknown_1bb8_ = ST(0x26);
            arg0->unknown_1bbc_ = ST(0x2b);
            if (arg0->unknown_1c26_ == 0xd7) {
                arg0->unknown_1bb8_ = ST(0x2b);
            }
        } else if (var11 == 0) {
            func_0205eaa0((struct Struct_ov002_02157d40_7*)&data_02108760, 0x64, 0);
            arg0->unknown_1bb8_ = ST(0x26);
            arg0->unknown_1bbc_ = ST(0x11);
        }
    } else if (arg0->unknown_1bb8_ == ST(7)) {
        arg0->unknown_2522_ = 0;
        arg0->unknown_2523_ = 0;
        memset(arg0->unknown_2524_, 0, 0xc);
        int var57 = 0;
        arg0->unknown_2530_ = var57;
        arg0->unknown_248a_ = 1;
        arg0->unknown_2488_ = -1;
        arg0->unknown_1c2a_ = -1;
        func_ov002_02157ce0((char*)&var0.unknown_28_);
        func_ov002_02157ce0((char*)&var0.unknown_28_);
        var0.unknown_28_.unknown_0_ = arg0->unknown_1c26_;
        var0.unknown_28_.unknown_2_ = arg0->unknown_1c20_;
        var0.unknown_28_.unknown_3_ = 1;
        var0.unknown_28_.unknown_4_[0] = arg0->unknown_1c21_;
        struct Struct_ov002_02157634_8* var58 = (struct Struct_ov002_02157634_8*)func_02079e2c(var1, arg0->unknown_1c26_);
        if (var58 != 0 && (var58->unknown_9_2_ & 1)) {
            func_ov016_0218b5c0(0, -1);
            func_ov002_021536e0(&var0.unknown_0_);
            var0.unknown_0_ = var1;
            var57 = func_ov002_021536ec(&var0.unknown_0_, &var0.unknown_28_, 0);
        }
        int var59 = 0;
        struct Struct_ov002_02157634_3* var60 = var0.unknown_28_.unknown_8_;
        struct Struct_ov002_02157634_3* var61 = var0.unknown_28_.unknown_20_;
        int var62;
        for (var62 = 0; var62 < var0.unknown_28_.unknown_3_; var62++) {
            struct Struct_ov002_02157634_3* var63 = &var60[var62];
            struct Struct_ov002_02157634_3* var64;
            if (var63->unknown_4_ != 0 || (var64 = &var61[var62])->unknown_4_ != 0) {
                var59 = 1;
                break;
            }
        }
        if (var59) {
            func_ov002_0216c42c(arg0, &var0.unknown_28_, var58);
            arg0->unknown_1cc6_ = 0;
            arg0->unknown_1cc7_ = 1;
            func_ov002_02157ce0((char*)(arg0->unknown_1cc8_));
            memcpy(arg0->unknown_1cc8_, &var0.unknown_28_, 0x3c);
            arg0->unknown_1c28_ = -1;
            arg0->unknown_1c2a_ = -1;
            arg0->unknown_1bb8_ = ST(0x26);
            arg0->unknown_1bbc_ = ST(0x26);
            arg0->unknown_2488_ = -1;
            arg0->unknown_248a_ = 0;
            arg0->unknown_1c7a_ = 1;
            arg0->unknown_1c7b_ = 0x14;
            arg0->unknown_1c74_ = 0x1e;
            arg0->unknown_1bc0_ = 0;
            return;
        }
        if (arg0->unknown_1c26_ == 0xd1) {
            if (func_0202b7d8((int*)func_0202ae18()) != 0) {
                int var65 = 1;
                int var66;
                for (var66 = 0; var66 < arg0->unknown_1c38_; var66++) {
                    if (arg0->unknown_1c21_ == arg0->unknown_1c3c_[var66]) {
                        var65 = 0;
                    }
                }
                if (var65) {
                    func_ov016_0218b5c0(0, -1);
                    func_ov017_021d27a0(1, arg0->unknown_1c20_, arg0->unknown_1c21_);
                    func_0205eaa0((struct Struct_ov002_02157d40_7*)&data_02108760, 0x64, 0);
                    arg0->unknown_1c28_ = 0x7536;
                    arg0->unknown_1c2a_ = -1;
                    arg0->unknown_1bb8_ = ST(0x26);
                    arg0->unknown_1bbc_ = ST(0x26);
                    arg0->unknown_2488_ = -1;
                    arg0->unknown_248a_ = 0;
                    arg0->unknown_1c7a_ = 1;
                    arg0->unknown_1c7b_ = 0xa;
                    arg0->unknown_1c74_ = 0x12c;
                    arg0->unknown_1bc0_ = 0;
                    return;
                }
            }
            func_020e3428(func_020e2ff8(), 1);
            arg0->unknown_1c28_ = 0x7535;
            arg0->unknown_1c2a_ = -1;
            int var67 = 0;
            struct Struct_ov002_02157d40_17* var68 = (struct Struct_ov002_02157d40_17*)(Struct_ov002_02157d40*)func_0200ff1c((GameState*)var2, arg0->unknown_1c21_);
            if (var68 != 0 && (*var68->unknown_130_ & 4)) {
                var67 = 1;
            }
            if (var67) {
                int* var69 = (int*)func_0202ae18();
                func_02048418((unsigned char*)var68, 4);
                if (func_0202b7d8(var69) != 0) {
                    func_ov017_021c9e00(arg0->unknown_1c21_, 0, 0, 1);
                }
                unsigned char* var70 = (unsigned char*)func_02010828((GameState*)var2);
                var0.unknown_1c_ = *(struct Struct_ov002_02157d40_20*)&data_ov002_0216c992;
                int var71 = 0;
                int var72;
                for (var72 = 0; var72 < 0xb; var72++) {
                    if (var72 == 2 || var72 == 3 || var72 == 4) {
                        continue;
                    }
                    struct Struct_ov002_02157d40_15* var73 = &var68->unknown_150_->unknown_194_[(unsigned char)var72];
                    if (var73 == 0) {
                        continue;
                    }
                    if (var73->unknown_a_2_ == 0) {
                        continue;
                    }
                    func_0207c378(var70 + 0x1d4, var73->unknown_18_, 1, var73->unknown_8_0_);
                    func_02052d7c((void*)var68, var0.unknown_1c_.unknown_0_[var72], -1);
                    var71 = 1;
                }
                if (var71) {
                    if (func_0202b7d8(var69) != 0) {
                        func_ov017_021c3fb4(arg0->unknown_1c21_, 1);
                        func_ov017_021c4418(arg0->unknown_1c21_, -1);
                    }
                    void* var74 = GetGameResources();
                    BackgroundLoader::GetInstance();
                    func_ov017_0218f5a4(var74, arg0->unknown_1c21_, 1, 0, 0);
                }
                arg0->unknown_2488_ = -1;
                arg0->unknown_248a_ = 0;
                var9 = 1;
            } else {
                arg0->unknown_2488_ = 0x232b;
                arg0->unknown_248a_ = 1;
            }
        } else {
            func_020e3428(func_020e2ff8(), 1);
            struct Struct_ov002_02157d40_17* var75 = (struct Struct_ov002_02157d40_17*)(Struct_ov002_02157d40*)((GameState*)var2)->GetPartyMemberByIndex(arg0->unknown_1c21_);
            if (var57 != 0) {
                if (arg0->unknown_1c26_ == 0x1e || arg0->unknown_1c26_ == 0x1f || arg0->unknown_1c26_ == 0x20 || arg0->unknown_1c26_ == 0x21) {
                    arg0->unknown_2488_ = 0x232c;
                    var9 = 1;
                } else if (arg0->unknown_1c26_ == 0x23) {
                    arg0->unknown_2488_ = 0x794b;
                    var9 = 1;
                } else if (arg0->unknown_1c26_ == 0x27 || arg0->unknown_1c26_ == 0x26) {
                    arg0->unknown_2488_ = 0x2336;
                    var9 = 1;
                }
            } else {
                int var76 = (*var75->unknown_130_ & 1) != 0;
                if (var76) {
                    if (arg0->unknown_1c26_ == 0x26) {
                        arg0->unknown_2488_ = 0x2337;
                        var9 = 1;
                    } else {
                        arg0->unknown_2488_ = 0x232b;
                    }
                } else {
                    arg0->unknown_1c28_ = 0x2333;
                    arg0->unknown_2488_ = 0x2334;
                }
            }
        }
        func_0205eaa0((struct Struct_ov002_02157d40_7*)&data_02108760, 0x64, 0);
        arg0->unknown_1bb8_ = ST(0x26);
        arg0->unknown_1bbc_ = ST(0x11);
        arg0->unknown_1bc0_ = 0;
    }
    if (var9 != 0) {
        func_02048350((struct Struct_ov002_02157d40_8*)var7, var6->unknown_8_0_);
        if (func_0202b7d8(var8) != 0) {
            func_ov017_021c9e00(arg0->unknown_1c20_, 0, 0, 1);
        }
    }
}
