#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

struct Struct_0201099c_10;
struct Struct_0207c484;
struct Struct_02052e14;
struct Struct_02052e2c;
struct Struct_020a06ec;
struct Struct_020a0258;

struct Struct_ov003_0215582c_8 {
    char unknown_0_[8];
    unsigned int unknown_8_0_ : 4;
    unsigned int unknown_8_4_ : 28;
    char unknown_c_[0x18 - 0xc];
    short unknown_18_;
    char unknown_1a_[0x20 - 0x1a];
};

struct Struct_ov003_0215582c_9 {
    unsigned int unknown_0_;
    unsigned int : 27;
    unsigned int unknown_7_3_ : 1;
    unsigned int unknown_7_4_ : 1;
    unsigned int unknown_7_5_ : 1;
    unsigned int : 2;
};

struct Struct_ov003_0215582c_10 {
    struct Struct_ov003_0215582c_9* unknown_0_;
};

struct Struct_ov003_0215582c_11 {
    int unknown_0_[10];
    short unknown_28_;
    short unknown_2a_;
};

struct Struct_ov003_0215582c_12 {
    char unknown_0_[0x194];
    struct Struct_ov003_0215582c_8 unknown_194_[1];
    char unknown_1b4_[0x49c - 0x1b4];
    unsigned char unknown_49c_0_ : 1;
    unsigned char : 7;
#if defined(jpn)
    char unknown_49d_[0x8b8 - 0x49d];
#else
    char unknown1_49d_[0x950 - 0x49d];
#endif
    int unknown_950_;
};

struct Struct_ov003_0215582c {
    char unknown_0_[0x2f4];
    struct Struct_ov003_0215582c_11 unknown_2f4_[8];
    char unknown_454_[0x4a4 - 0x454];
    short unknown_4a4_[12][8];
};

struct Struct_ov003_0215582c_2 {
    char unknown_0_[4];
    unsigned short unknown_4_;
    unsigned short unknown_6_;
};

struct Struct_ov003_0215582c_3 {
    char unknown_0_[0x30];
    unsigned short unknown_30_;
    unsigned short unknown_32_;
};

struct Struct_ov003_0215582c_4 {
    char unknown_0_[4];
    short unknown_4_;
    char unknown_6_[0x130 - 6];
    struct Struct_ov003_0215582c_2* unknown_130_;
    struct Struct_ov003_0215582c_3* unknown_134_;
#if defined(jpn)
    char unknown_138_[0x144 - 0x138];
#else
    char unknown1_138_[0x150 - 0x138];
#endif
    struct Struct_ov003_0215582c_12* unknown_150_;
};

struct Struct_ov003_0215582c_5 {
    char unknown_0_[0x90];
    char unknown_90_[0xcc - 0x90];
#if defined(jpn)
    char unknown_cc_[0x174 - 0xcc];
#else
    char unknown_cc_[0x178 - 0xcc];
#endif
    char unknown_178_[0x1f7 - 0x178];
    signed char unknown_1f7_;
    char unknown_1f8_[0x1fc - 0x1f8];
    int unknown_1fc_;
    char unknown_200_[0x330 - 0x200];
    float unknown_330_;
    float unknown_334_;
};

struct Struct_ov003_0215582c_6 {
    int unknown_0_;
    int : 19;
    int unknown_6_3_ : 11;
    int : 2;
};

struct Struct_ov003_0215582c_7 {
    char unknown_0_[0x1d4];
    char unknown_1d4_[1];
};

void* GetPtrField0x2a04_02010828(GameState* battleStruct);
struct Stats0215582c* GetFieldAt0x150_02053c6c(unsigned char* obj);
int OffsetByIndexTimes16_02155e14(int base, int idx);
short* GetField150Ptr0x488(struct Field150Holder02052e14* obj);
extern "C" int func_0207c378(void* obj, int value, int amount, int key);
int GetArrayEntryByIndex_02156034(void* obj);
void PartyMember_SetVocation(unsigned char* obj, int index);
int GetField0x3acValue_020100a8(GameState* battleStruct);
int LoadBattleBlock020ac4c0(void* dst);
void AddClamped10BitFieldHighAt0x28_020a06ec(struct S_a06ec* p, unsigned int amount);
void AddClamped10BitFieldAt0x1c_020a0258(struct S_a0258* p, unsigned int amount);
int CopyInBattleField0x7540_020ac494(void* src);
extern "C" int func_0207c7a0(void* map, int value, int key);
struct ItemEntry0215582c* FindElementByKey020dedd0(struct Container020dedd0* c, int key);
extern "C" void func_02052d7c(void* obj, int index, int value);
int DecrementKeyedStackAmount0207c484(struct KeyedList0207c484* obj, int value, int amount, int key);
short* GetField150Ptr0x488_02052e2c(struct Field150Holder02052e2c* obj);
extern "C" void func_02083738(void* o, int a1);
extern "C" void PartyMember_ApplyLevelStats(void* a, void* obj, void* tail);
void PartyMember_LearnSpell(unsigned char* obj, int index);
extern "C" void* func_0202ae18(void);
extern "C" void func_ov017_0218f5a4(void* arg0, int arg1, int arg2, int arg3, int arg4);

extern const unsigned char data_ov003_0217f2c4[];
extern const unsigned char data_ov003_0217f2b4[];
extern const unsigned char data_ov003_0217f2bc[];

static inline int inline_ov003_0215582c(unsigned int arg0) {
    return arg0 <= 7;
}

// USA: func_ov003_0215582c
extern "C" ARM void func_ov003_0215582c(struct Struct_ov003_0215582c_5* arg0) {
    GameState* var0 = GameState::GetInstance();
    struct Struct_ov003_0215582c_7* var1 = (struct Struct_ov003_0215582c_7*)func_02010828(var0);
    struct Struct_ov003_0215582c_4* var2 = (struct Struct_ov003_0215582c_4*)var0->GetPartyMemberByIndex(arg0->unknown_1f7_);
    if (var2 == NULL) {
        return;
    }
    struct Struct_ov003_0215582c* var3 = func_02053c6c((unsigned char*)var2);
    if (var3 == NULL) {
        return;
    }

    short (*var4)[8] = var3->unknown_4a4_;
    int var5;
    if (arg0->unknown_1fc_ & 1) {
        var5 = var2->unknown_134_->unknown_30_;
        int var6 = var2->unknown_130_->unknown_4_;
        arg0->unknown_330_ = (float)var6 / (float)var5;
        var5 = var2->unknown_134_->unknown_32_;
        int var7 = var2->unknown_130_->unknown_6_;
        arg0->unknown_334_ = (float)var7 / (float)var5;
    }

    short* var8 = (short*)func_ov003_02155e14((int)var4, var2->unknown_150_->unknown_950_);
    short* var9 = func_02052e14((struct Struct_02052e14*)var2);
    if (var8 != NULL && var9 != NULL) {
        var8[0] = var9[7];
        var8[1] = var9[0];
        var8[2] = var9[8];
        var8[3] = var9[6];
        var8[4] = var9[4];
        var8[5] = var9[1];
        var8[6] = var9[5];
        var8[7] = var9[9];
    }

    for (unsigned short var10 = 0; data_ov003_0217f2c4[var10] != 0xff; var10++) {
        struct Struct_ov003_0215582c_8* var11 = &var2->unknown_150_->unknown_194_[data_ov003_0217f2c4[var10]];
        if (var11 != NULL && inline_ov003_0215582c(var11->unknown_8_0_)) {
            func_0207c378(var1->unknown_1d4_, var11->unknown_18_, 1, var11->unknown_8_0_);
        }
    }

    PartyMember_SetVocation((unsigned char*)stats, GetArrayEntryByIndex_02156034(self));

    var5 = func_020100a8(var0);
    if (var5 == var2->unknown_4_) {
        GameState* var12 = GameState::GetInstance();
#if defined(jpn)
        struct Struct_ov003_0215582c_6* var13 = (struct Struct_ov003_0215582c_6*)((char*)var12 + 0x3c + 0x5400);
#else
        struct Struct_ov003_0215582c_6* var13 = (struct Struct_ov003_0215582c_6*)((char*)var12 + 0x29c + 0x5400);
#endif
        short var14 = var13->unknown_6_3_;
        if (var14 >= 700 && var14 < 800) {
            struct Struct_ov003_0215582c_4* var15 = (struct Struct_ov003_0215582c_4*)var12->GetProtagonist();
            int var16 = var15->unknown_150_->unknown_950_;
#if defined(jpn)
            var13->unknown_6_3_ = var16 + 700;
#else
            int var17 = 20700;
            if (var15->unknown_150_->unknown_49c_0_ == 1) {
                var17 += 50;
            }
            var13->unknown_6_3_ = var17 - 20000 + var16;
#endif
        }
        int var18[0x2c];
        func_020ac4c0(var18);
        func_020a06ec((struct Struct_020a06ec*)var18, 1);
        func_020a0258((struct Struct_020a0258*)(var18 + 0x1a), 1);
        func_020ac494(var18);
    }

    int var19 = 0;
    var8 = (short*)func_ov003_02155e14((int)var4, func_ov003_02156034(arg0));
    if (var8 != NULL) {
        if (var8[0] == var9[7] && var8[1] == var9[0] && var8[2] == var9[8] && var8[3] == var9[6] &&
            var8[4] == var9[4] && var8[5] == var9[1] && var8[6] == var9[5] && var8[7] == var9[9]) {
            var19 = 1;
        }
    }

    if (var8[7] == 0x4680 && func_0207c7a0(var1->unknown_1d4_, 0x4680, 7) == 0) {
        bool var20[2];
        for (int var21 = 0; var21 < 7; var21++) {
            struct Struct_ov003_0215582c_10* var22 = func_020dedd0((struct Struct_0201099c_10*)arg0->unknown_178_, var8[var21]);
            struct Struct_ov003_0215582c_9* var23;
            if (var22 != NULL && (var23 = var22->unknown_0_) != NULL) {
                var20[0] = var23->unknown_7_3_;
                var20[1] = var23->unknown_7_4_;
                if (var20[var2->unknown_150_->unknown_49c_0_] == 0) {
                    if (var23->unknown_7_5_ == 0) {
                        var8[var21] = -1;
                    }
                }
            }
        }
    }

    for (unsigned char var24 = 0; var24 < 8; var24++) {
        int var25 = 0;
        int var26 = var8[var24];
        int var27 = data_ov003_0217f2b4[var24];
        if (var26 > 0 && func_0207c7a0(var1->unknown_1d4_, var26, var27) >= 1) {
            if (data_ov003_0217f2bc[var24] != 0xff) {
                func_02052d7c(var2, data_ov003_0217f2bc[var24], var26);
            }
            func_0207c484((struct Struct_0207c484*)var1->unknown_1d4_, var26, 1, var27);
            var25 = 1;
            if (data_ov003_0217f2bc[var24] == 4) {
                short* var28 = func_02052e2c((struct Struct_02052e2c*)var2);
                var28[0xb] = -1;
                if (var9[0] > 0) {
                    var28[0xb] = var9[0] % 1000 + 14000;
                }
            }
        }
        if (var25 == 0) {
            if (data_ov003_0217f2bc[var24] != 0xff) {
                if (data_ov003_0217f2bc[var24] == 0) {
                    func_02052e2c((struct Struct_02052e2c*)var2)[0xb] = -1;
                }
                if (data_ov003_0217f2bc[var24] == 4) {
                    short* var29 = func_02052e2c((struct Struct_02052e2c*)var2);
                    var29[0xb] = -1;
                    if (var9[0] > 0) {
                        var29[0xb] = var9[0] % 1000 + 14000;
                    }
                }
                if (var9[data_ov003_0217f2bc[var24]] != -1) {
                    struct Struct_ov003_0215582c* var30 = func_02053c6c((unsigned char*)var2);
                    func_02083738(var30, var27);
                    var30->unknown_2f4_[var24].unknown_0_[0] = 0;
                    var30->unknown_2f4_[var24].unknown_0_[1] = 0;
                    var30->unknown_2f4_[var24].unknown_0_[2] = 0;
                    var30->unknown_2f4_[var24].unknown_0_[3] = 0;
                    var30->unknown_2f4_[var24].unknown_0_[4] = 0;
                    var30->unknown_2f4_[var24].unknown_0_[5] = 0;
                    var30->unknown_2f4_[var24].unknown_0_[6] = 0;
                    var30->unknown_2f4_[var24].unknown_0_[7] = 0;
                    var30->unknown_2f4_[var24].unknown_0_[8] = 0;
                    var30->unknown_2f4_[var24].unknown_0_[9] = 0;
                    var30->unknown_2f4_[var24].unknown_28_ = -1;
                }
                func_02052d7c(var2, data_ov003_0217f2bc[var24], -1);
            }
        }
    }

    PartyMember_ApplyLevelStats(stats, self->f90, self->fcc);
    switch (GetArrayEntryByIndex_02156034(self)) {
    case 2:
        PartyMember_LearnSpell((unsigned char*)stats, 0x1a);
        break;
    case 3:
        PartyMember_LearnSpell((unsigned char*)stats, 0);
        break;
    }

    if (var19 == 0) {
        GameResources* var31 = GetGameResources();
        func_0202ae18();
        func_ov017_0218f5a4(var31, arg0->unknown_1f7_, 1, 0, 0);
    }
}
