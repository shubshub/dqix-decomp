#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* func_ov011_021849c8(void* arg0);
struct GameState;
extern int GetFieldAt0x150_02053c6c(unsigned char* obj);
void ClearField00209a804(int* field);
struct Ctx0209a810 { void* field0; };
void SpellTable_Load(Ctx0209a810* ctx, void* value);
void SetField38IfState8_0215e49c(void*, int, int);
int CheckAfterTwoCalls_0215e460(void);
extern "C" void func_ov004_0215e574(void* a, int key, int c, int d, int e);
void SetNodeFieldsAndMaybeNotify_0215f6f4(void* a, short v1, short v2, int flag);

struct Struct_ov004_02161514_3 {
    char unknown_0_[0xc];
    unsigned char unknown_c_;
};
extern "C" Struct_ov004_02161514_3* func_ov004_0215e47c(void* arg0, int arg1);

class Struct_ov004_02161514_4 {
public:
    virtual void inline_ov004_02161514_45(); virtual void inline_ov004_02161514_46(); virtual void inline_ov004_02161514_47(); virtual void inline_ov004_02161514_48();
    virtual void inline_ov004_02161514_49(); virtual void inline_ov004_02161514_50(); virtual void inline_ov004_02161514_51(); virtual void inline_ov004_02161514_52();
    virtual void inline_ov004_02161514_53(); virtual void inline_ov004_02161514_54(); virtual void inline_ov004_02161514_55(); virtual void inline_ov004_02161514();
    virtual void inline_ov004_02161514_2(); virtual void inline_ov004_02161514_3(); virtual void inline_ov004_02161514_4(); virtual void inline_ov004_02161514_5();
    virtual void inline_ov004_02161514_6(); virtual void inline_ov004_02161514_7(); virtual void inline_ov004_02161514_8(); virtual void inline_ov004_02161514_9();
    virtual void inline_ov004_02161514_10(); virtual void inline_ov004_02161514_11(); virtual void inline_ov004_02161514_12(); virtual void inline_ov004_02161514_13();
    virtual void inline_ov004_02161514_14(); virtual void inline_ov004_02161514_15(); virtual void inline_ov004_02161514_16(); virtual void inline_ov004_02161514_17();
    virtual void inline_ov004_02161514_18(); virtual void inline_ov004_02161514_19(); virtual void inline_ov004_02161514_20(); virtual void inline_ov004_02161514_21();
    virtual void inline_ov004_02161514_22(); virtual void inline_ov004_02161514_23(); virtual void inline_ov004_02161514_24(); virtual void inline_ov004_02161514_25();
    virtual void inline_ov004_02161514_26(); virtual void inline_ov004_02161514_27(); virtual void inline_ov004_02161514_28(); virtual void inline_ov004_02161514_29();
    virtual void inline_ov004_02161514_30(); virtual void inline_ov004_02161514_31(); virtual void inline_ov004_02161514_32(); virtual void inline_ov004_02161514_33();
    virtual void inline_ov004_02161514_34(); virtual void inline_ov004_02161514_35(); virtual void inline_ov004_02161514_36(); virtual void inline_ov004_02161514_37();
    virtual void inline_ov004_02161514_38(); virtual void inline_ov004_02161514_39(); virtual void inline_ov004_02161514_40(); virtual void inline_ov004_02161514_41();
    virtual void inline_ov004_02161514_42(); virtual void inline_ov004_02161514_43();
    virtual void inline_ov004_02161514_44(int arg0);
};
extern "C" Struct_ov004_02161514_4* func_ov023_021f6880(void* arg0, int arg1);

struct Struct_ov004_02161514 {
    unsigned short unknown_0_;
    unsigned short unknown_2_;
};
struct Struct_ov004_02161514_2 {
    char unknown_0_[0x10c];
    Struct_ov004_02161514 unknown_10c_[13][20];
    int unknown_51c_[13];
};

struct Struct_ov004_021707e8_3 {
    unsigned char unknown_0_[2];
    unsigned char unknown_2_;
#if defined(jpn)
    unsigned char unknown_3_;
    signed char unknown_6_;
    unsigned char unknown_5_;
#else
    unsigned char unknown1_3_[3];
    signed char unknown_6_;
#endif
    unsigned char unknown_7_;
    unsigned char unknown_8_;
#if !defined(jpn)
    unsigned char unknown_9_[2];
#endif
    signed char unknown_b_;
#if defined(jpn)
    unsigned char unknown1_9_[0x1c - 9];
#else
    unsigned char unknown_c_[0x1c - 0xc];
#endif
    int unknown_1c_;
};
extern Struct_ov004_021707e8_3 data_ov004_021707e8;
extern int data_ov004_02170854[];
#if defined(jpn)
extern unsigned char data_ov004_02170568[];
extern unsigned char data_ov004_021710b0[];
#else
extern unsigned char data_ov004_0216fde8[];
#endif
extern unsigned char data_ov004_02170838[];
extern unsigned char data_ov004_02170820[];

// JPN: func_ov004_02161514 (02161ea4)
// USA: func_ov004_02161514
extern "C" ARM int func_ov004_02161514(void* arg0) {
    Struct_0201099c_18 var0;
    Struct_ov004_02161514_2 var1;
    void* var2;
    int var3;
    unsigned char var4;
    int var5;
    unsigned char* var6;
    unsigned int var7;
    int var8;
    Struct_ov004_02161514* var9;
    unsigned char var10;
    int var11;
    int var12;
    unsigned char var13;
    int var14;
    Struct_ov004_02161514_4* var15;

    data_ov004_021707e8.unknown_7_ = 0x65;
    var2 = func_ov011_021849c8(arg0);
    var3 = 0;
    var4 = 0;
    if (data_ov004_021707e8.unknown_2_ != data_ov004_02170854[data_ov004_021707e8.unknown_8_]) var4 = 1;

#if defined(jpn)
    if (data_ov004_021707e8.unknown_6_ == 0) {
        func_ov004_0215e47c(arg0, 3)->unknown_c_ &= ~4;
    } else {
        func_ov004_0215e47c(arg0, 3)->unknown_c_ |= 4;
    }
#else
    func_ov004_0215e47c(arg0, 3)->unknown_c_ |= 4;
#endif

    t = data_ov004_02170854[data_ov004_021707e8.selectedCategory];
    if (t != 1 && t != 4 && t != 7) {
        unsigned char* combatant = (unsigned char*)GetCombatantWithFlag0x100_0200ff1c((GameState*)(void*)GameState::GetInstance(), data_ov004_021707e8.combatant);
        if (!combatant) return 0;
        field = (unsigned char*)GetFieldAt0x150_02053c6c(combatant);
        if (!field) return 0;
        limit = *(unsigned short*)(field + data_ov004_02170854[data_ov004_021707e8.selectedCategory] * 2 + 0x16c);
        ClearField00209a804((int*)&ctx);
        SpellTable_Load(&ctx, &buf);
        count = buf.counts[data_ov004_02170854[data_ov004_021707e8.selectedCategory]];
        rows = buf.rows[data_ov004_02170854[data_ov004_021707e8.selectedCategory]];
        cnt = 0;

        for (var11 = 0xc; var11 < 0x30; var11++) func_ov004_0215e49c(arg0, var11, 0x3a);
        func_ov004_0215e49c(arg0, 0x31, 0x3a);
        func_ov004_0215e49c(arg0, 0x32, 0x3a);
        func_ov004_0215e49c(arg0, 0xc, 0x3b);
        func_ov004_0215e49c(arg0, 0xd, 1);
        if (func_ov004_0215e460()) {
            func_ov004_0215e49c(arg0, 0xe, 4);
        } else {
            func_ov004_0215e49c(arg0, 0xe, data_ov004_02170854[data_ov004_021707e8.unknown_8_] + 4);
        }

        if (data_ov004_021707e8.unknown_2_ != data_ov004_02170854[data_ov004_021707e8.unknown_8_]) {
            for (var13 = 0; var13 < 3; var13++) {
                var15 = func_ov023_021f6880(var2, var13 + 0xc);
                if (var15) var15->inline_ov004_02161514_44(3);
            }
            var15 = func_ov023_021f6880(var2, 0x64);
            if (var15) var15->inline_ov004_02161514_44(3);
        } else {
            for (var13 = 0; var13 < 3; var13++) {
                var15 = func_ov023_021f6880(var2, var13 + 0xc);
                if (var15) var15->inline_ov004_02161514_44(0xf);
            }
            var15 = func_ov023_021f6880(var2, 0x64);
            if (var15) var15->inline_ov004_02161514_44(0xf);
        }

        for (var11 = 0; var11 < var8; var11++) {
            unsigned short var17 = var9[var11].unknown_0_;
            unsigned short var18 = var9[var11].unknown_2_;
            if (var18 != 0 && var18 <= var7) {
                int var19;
                func_ov004_0215e49c(arg0, var10 + 0xf, var17 + 0x3f);
                var19 = 0xf;
                if (data_ov004_021707e8.unknown_2_ != data_ov004_02170854[data_ov004_021707e8.unknown_8_]) var19 = 3;
                var15 = func_ov023_021f6880(var2, var10 + 0xf);
                if (var15) var15->inline_ov004_02161514_44(var19);
                var10++;
            }
        }

        if (var10 == 0) {
            var3 = 1;
            for (var12 = 0xc; var12 < 0x30; var12++) func_ov004_0215e49c(arg0, var12, 0x3a);
            func_ov004_0215e49c(arg0, 0x31, 0x1e1);
            func_ov004_0215e49c(arg0, 0x32, 0x1e3);
#if !defined(jpn)
            func_ov004_0215e574(arg0, 0x31, 0xff, 0, 0);
#endif
#if !defined(jpn)
            func_ov004_0215e574(arg0, 0x32, 0xff, 0, 0);
#endif
            func_ov004_0215e49c(arg0, 0xc, 0x3b);
            func_ov004_0215e49c(arg0, 0xd, 1);
            if (func_ov004_0215e460()) {
                func_ov004_0215e49c(arg0, 0xe, 4);
            } else {
                func_ov004_0215e49c(arg0, 0xe, data_ov004_02170854[data_ov004_021707e8.unknown_8_] + 4);
            }
            var14 = 1;
            if (data_ov004_021707e8.unknown_2_ != data_ov004_02170854[data_ov004_021707e8.unknown_8_]) var14 = 0;
            for (int var20 = 0; var20 < 5; var20++) {
#if defined(jpn)
                var15 = func_ov023_021f6880(var2, data_ov004_02170568[var20]);
#else
                var15 = func_ov023_021f6880(var2, data_ov004_0216fde8[var20]);
#endif
                if (var15) {
                    if (var14) var15->inline_ov004_02161514_44(0xf);
                    else var15->inline_ov004_02161514_44(3);
                }
            }
        }
    } else {
        int var21;
        var3 = 1;
        for (var12 = 0xc; var12 < 0x30; var12++) func_ov004_0215e49c(arg0, var12, 0x3a);
        func_ov004_0215e49c(arg0, 0x31, 0x1e1);
        func_ov004_0215e49c(arg0, 0x32, 0x1e3);
#if !defined(jpn)
        func_ov004_0215e574(arg0, 0x31, 0xff, 0, 0);
#endif
#if !defined(jpn)
        func_ov004_0215e574(arg0, 0x32, 0xff, 0, 0);
#endif
        func_ov004_0215e49c(arg0, 0xc, 0x3b);
        func_ov004_0215e49c(arg0, 0xd, 1);
        if (func_ov004_0215e460()) {
            func_ov004_0215e49c(arg0, 0xe, 4);
        } else {
            func_ov004_0215e49c(arg0, 0xe, data_ov004_02170854[data_ov004_021707e8.unknown_8_] + 4);
        }
        var14 = 1;
        if (data_ov004_021707e8.unknown_2_ != data_ov004_02170854[data_ov004_021707e8.unknown_8_]) var14 = 0;
        for (int var22 = 0; var22 < 5; var22++) {
#if defined(jpn)
            var15 = func_ov023_021f6880(var2, data_ov004_02170568[var22]);
#else
            var15 = func_ov023_021f6880(var2, data_ov004_0216fde8[var22]);
#endif
            if (var15) {
                if (var14) var15->inline_ov004_02161514_44(0xf);
                else var15->inline_ov004_02161514_44(3);
            }
        }
        var21 = 0xf;
        if (!var14) var21 = 3;
        var15 = func_ov023_021f6880(var2, 0x64);
        if (var15) var15->inline_ov004_02161514_44(var21);
        if (data_ov004_021707e8.unknown_6_ == 0) {
            Struct_ov004_02161514_3* var23 = func_ov004_0215e47c(arg0, 3);
            if (var23) var23->unknown_c_ &= ~4;
        }
    }

#if !defined(jpn)
    if (var3) {
        unsigned char var24 = 0;
        int var25;
        for (var25 = 1; var25 < 0xd; var25++) {
            if (data_ov004_02170838[var25]) var24++;
            if (var24 > 1) break;
        }
        if (var24 <= 1) func_ov004_0215e47c(arg0, 3)->unknown_c_ &= ~4;
    }

#endif

    {
        int var26;
#if defined(jpn)
        data_ov004_021707e8.unknown_b_ = data_ov004_021710b0[data_ov004_02170854[data_ov004_021707e8.unknown_8_] - 1];
        var26 = data_ov004_021707e8.unknown_b_ - data_ov004_021710b0[data_ov004_021707e8.unknown_2_ - 1];
#else
        data_ov004_021707e8.unknown_b_ = data_ov004_02170820[data_ov004_02170854[data_ov004_021707e8.unknown_8_] - 1];
        var26 = data_ov004_021707e8.unknown_b_ - data_ov004_02170820[data_ov004_021707e8.unknown_2_ - 1];
#endif
        if (var26 < 0) var26 += data_ov004_021707e8.unknown_6_;
        data_ov004_021707e8.unknown_b_ = var26;
    }
    func_ov004_0215f6f4(arg0, data_ov004_021707e8.unknown_b_, data_ov004_021707e8.unknown_6_, var4);
    return 0;
}
