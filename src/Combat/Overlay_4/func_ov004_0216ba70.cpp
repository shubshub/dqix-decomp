#include <globaldefs.h>
#include "NitroSDK/Matrix.h"
#include "GameState/GameState.h"

typedef Vector3i Type_ov004_0216ba70;

class Struct_ov004_0216ba70 {
public:
    virtual void inline_ov004_0216ba70_19(); virtual void inline_ov004_0216ba70_20(); virtual void inline_ov004_0216ba70_21(); virtual void inline_ov004_0216ba70_22();
    virtual void inline_ov004_0216ba70_23(); virtual void inline_ov004_0216ba70_24(); virtual void inline_ov004_0216ba70_25();
    virtual void inline_ov004_0216ba70_26(Type_ov004_0216ba70* arg0);
    virtual Type_ov004_0216ba70 inline_ov004_0216ba70_29();
    virtual void inline_ov004_0216ba70_31(); virtual void inline_ov004_0216ba70_33(); virtual void inline_ov004_0216ba70_37();
    virtual void inline_ov004_0216ba70_39(); virtual void inline_ov004_0216ba70_40(); virtual void inline_ov004_0216ba70_41(); virtual void inline_ov004_0216ba70_42();
    virtual void inline_ov004_0216ba70_43(); virtual void inline_ov004_0216ba70_44(); virtual void inline_ov004_0216ba70_45(); virtual void inline_ov004_0216ba70_46();
    virtual void inline_ov004_0216ba70_47(); virtual void inline_ov004_0216ba70_48(); virtual void inline_ov004_0216ba70_49(); virtual void inline_ov004_0216ba70_50();
    virtual void inline_ov004_0216ba70_51(); virtual void inline_ov004_0216ba70_52(); virtual void inline_ov004_0216ba70_53(); virtual void inline_ov004_0216ba70_54();
    virtual void inline_ov004_0216ba70_55(); virtual void inline_ov004_0216ba70_56(); virtual void inline_ov004_0216ba70_57(); virtual void inline_ov004_0216ba70_58();
    virtual void inline_ov004_0216ba70_59(); virtual void inline_ov004_0216ba70_60(); virtual void inline_ov004_0216ba70_61(); virtual void inline_ov004_0216ba70_62();
    virtual void inline_ov004_0216ba70_63(); virtual void inline_ov004_0216ba70_64(); virtual void inline_ov004_0216ba70_65(); virtual void inline_ov004_0216ba70();
    virtual void inline_ov004_0216ba70_2(); virtual void inline_ov004_0216ba70_3(); virtual void inline_ov004_0216ba70_4(); virtual void inline_ov004_0216ba70_5();
    virtual void inline_ov004_0216ba70_6(); virtual void inline_ov004_0216ba70_7(); virtual void inline_ov004_0216ba70_8(); virtual void inline_ov004_0216ba70_9();
    virtual void inline_ov004_0216ba70_10(); virtual void inline_ov004_0216ba70_11(); virtual void inline_ov004_0216ba70_12(); virtual void inline_ov004_0216ba70_13();
    virtual void inline_ov004_0216ba70_14(); virtual void inline_ov004_0216ba70_15();
    virtual void inline_ov004_0216ba70_16(int arg0);
    virtual void inline_ov004_0216ba70_17();
    virtual void inline_ov004_0216ba70_18(int arg0);
    char unknown_4_[0x1c];
    void* unknown_20_;
};

struct Struct_ov004_0216ba70_2 {
    char unknown_0_[0x30];
    unsigned char unknown_30_;
    unsigned char unknown_31_;
    unsigned short unknown_32_;
};

struct Struct_ov004_0216ba70_3 {
    Struct_ov004_0216ba70_2 unknown_0_[4];
    int unknown_d0_;
    unsigned char unknown_d4_;
    unsigned char unknown_d5_;
    unsigned char unknown_d6_;
    unsigned char unknown_d7_;
};

struct Struct_ov004_0216ba70_4 {
    char unknown_0_[0x4000];
    Struct_ov004_0216ba70_3 unknown_4000_;
};

struct Struct_ov004_0216ba70_5 {
    char unknown_0_[0x3e80];
    Struct_ov004_0216ba70_4 unknown_3e80_;
};

struct Struct_ov004_02171034 {
    char unknown_0_[6];
    unsigned char unknown_6_;
    unsigned char unknown_7_;
    unsigned short unknown_8_;
    char unknown_a_[2];
    int unknown_c_;
};

struct Struct0200fb08;
extern unsigned char GameState_GetLanguage(struct Struct0200fb08* obj);
extern int StandardStrings_Get(int value);
struct Obj_02184ad8;
extern void SetField1c8True_02184ad8(struct Obj_02184ad8* obj);
void* GetNodeIfType6_0216ae9c(void* a, int id);

extern "C" void* func_ov011_021849c8(void*);
extern "C" Struct_ov004_0216ba70* func_ov023_021f6880(void* arg0, int arg1);
extern "C" void func_ov023_021f8120(void* arg0);
extern "C" void func_ov023_021f7eb8(void* arg0, void* arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9);

extern "C" void func_ov004_0216afb0(void* arg0, int arg1, int arg2, int arg3,
    int arg4, int arg5, int arg6, int arg7, unsigned char arg8);
extern "C" void func_ov004_0216b06c(void* arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, unsigned char arg8);
extern "C" void func_ov004_0216b120(void* arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7);
extern "C" int func_ov004_0216aed0(void* arg0, int arg1, int arg2, int arg3);
extern "C" int func_ov004_0216af24(void* arg0, short arg1);

extern Struct_ov004_02171034 data_ov004_02171034;

static inline Struct_ov004_0216ba70_3* inline_ov004_0216ba70_27(GameState* arg0) {
    return &((Struct_ov004_0216ba70_5*)arg0)->unknown_3e80_.unknown_4000_;
}
struct Struct_ov004_0217017a { short unknown_0_; short unknown_2_; };
extern Struct_ov004_0217017a data_ov004_0217017a[];

static inline void inline_ov004_0216ba70_28(Struct_ov004_0216ba70* arg0, int arg1) {
    const Type_ov004_0216ba70& var0 = arg0->inline_ov004_0216ba70_29();
    Type_ov004_0216ba70 var1;
    *(Vector3i*)((int*)&var1) = *(Vector3i const*)((int*)&var0);
    var1.x = arg1;
    arg0->inline_ov004_0216ba70_26(&var1);
}

static inline void inline_ov004_0216ba70_30(Struct_ov004_0216ba70* arg0, Type_ov004_0216ba70 arg1, int arg2) {
    arg1.x = arg1.x + arg2;
    arg0->inline_ov004_0216ba70_26(&arg1);
}

static inline void inline_ov004_0216ba70_32(void* arg0, Struct_ov004_0216ba70* arg1, Type_ov004_0216ba70 arg2) {
    inline_ov004_0216ba70_30(arg1, arg2, 0x4000);
    func_ov004_0216afb0(arg0, 0x5a, 2, 0xd3, 31, 60, 5, 8, 1);
}

static inline Type_ov004_0216ba70 inline_ov004_0216ba70_34(const Type_ov004_0216ba70& arg0) {
    Type_ov004_0216ba70 var0 = arg0;
    return var0;
}

static inline Type_ov004_0216ba70 inline_ov004_0216ba70_35(const Type_ov004_0216ba70& arg0) {
    Type_ov004_0216ba70 var0 = inline_ov004_0216ba70_34(arg0);
    return var0;
}

static inline Type_ov004_0216ba70 inline_ov004_0216ba70_36(const Type_ov004_0216ba70& arg0) {
    return inline_ov004_0216ba70_35(arg0);
}

static inline Type_ov004_0216ba70 inline_ov004_0216ba70_38(Struct_ov004_0216ba70* arg0) {
    const Type_ov004_0216ba70& var0 = arg0->inline_ov004_0216ba70_29();
    return inline_ov004_0216ba70_36(var0);
}

// USA: func_ov004_0216ba70
extern "C" ARM int func_ov004_0216ba70(void* arg0) {
    int var0;
    int var1;
    int var2;
    int var3;
    Struct_ov004_0216ba70_3* var4;
    GameState* var5;
    Struct_ov004_0216ba70_3* var6;
    Type_ov004_0216ba70 var7;

    var4 = &((Struct_ov004_0216ba70_5*)GameState::GetInstance())->unknown_3e80_.unknown_4000_;
    var0 = var4->unknown_d4_;

    var5 = GameState::GetInstance();
    var6 = inline_ov004_0216ba70_27(var5);

    func_ov004_0216afb0(arg0, 0x37, 2, 0xd3, 6, 0x46, 4, 0xa, 1);

    var2 = func_ov004_0216af24(arg0, 0x37);

    Struct_ov004_0216ba70* var8 = func_ov023_021f6880(func_ov011_021849c8(arg0), 0x37);
    if (var8) {
        inline_ov004_0216ba70_28(var8, ((0xd0 - var2) >> 1) << 12);
    }

    if (var6->unknown_d5_ != 0) {
        Struct_ov004_0216ba70* var9 = func_ov023_021f6880(func_ov011_021849c8(arg0), 0x37);
        Type_ov004_0216ba70 var10 = inline_ov004_0216ba70_38(var9);
        inline_ov004_0216ba70_32(arg0, var9, var10);
        Struct_ov004_0216ba70* var11 = func_ov023_021f6880(func_ov011_021849c8(arg0), 0x5a);
        if (var11) {
            var11->inline_ov004_0216ba70_16(0xd);
            inline_ov004_0216ba70_30(var11, var10, -0x5000);
        }
    }

    func_ov004_0216b120(arg0, 0x28, 2, 0xd3, 2, 0x10, 0xcb, 1);

    {
    int flag = 0;
    if (GameState_GetLanguage((struct Struct0200fb08*)bs2) == 4 ||
        GameState_GetLanguage((struct Struct0200fb08*)bs2) == 2) {
        flag = 2;
    }
    var3 = 0;

    func_ov004_0216afb0(arg0, 0x38, 2, 0xd3, 0x3e7, 7, var3 + 0x13, 0xa, 1);
    func_ov004_0216afb0(arg0, 0x39, 2, 0xd3, 0x3e7, 0x57, var3 + 0x13, 0xa, 1);
    func_ov004_0216afb0(arg0, 0x3a, 2, 0xd3, 0x15, 0xa8 - var12, var3 + 0x13, 0xa, 1);

    VObjNode* node4 = func_ov023_021f6880(func_ov011_021849c8(a), 0x3a);
    if (node4) {
        node4->field20 = (void*)StandardStrings_Get(0x3f3);
    }

    func_ov004_0216afb0(arg0, 0x47, 2, 0xd3, 0x3e7, 0xa1, var3 + 0x13, 8, 1);
    func_ov004_0216b06c(arg0, 0x96, 2, 0xd3, 0xbe, var3 + 0x13, 8, 2, 0);

    var3 += 0xc;
    if (var0 > 1) {
        switch (var0) {
        case 2: var3 += 2; break;
        case 3: var3 += 1; break;
        }

        int var14 = 0x3f3 - 0xc;
        for (var1 = 1; var1 < var0; var1++) {
            int var15 = var1 + var1 * 2;
            func_ov004_0216afb0(arg0, var15 + 0x38, 2, 0xd3, var14, 7, var3 + 0x13, 0xa, 1);
            func_ov004_0216afb0(arg0, var15 + 0x39, 2, 0xd3, var14, 0x57, var3 + 0x13, 0xa, 1);
            func_ov004_0216afb0(arg0, var15 + 0x3a, 2, 0xd3, 0x15, 0xa8 - var12, var3 + 0x13, 0xa, 1);

            VObjNode* node5 = func_ov023_021f6880(func_ov011_021849c8(a), idx3 + 0x3a);
            if (node5) {
                node5->field20 = (void*)StandardStrings_Get(0x3f3);
            }

            func_ov004_0216afb0(arg0, var1 + 0x47, 2, 0xd3, var14, 0xa1, var3 + 0x13, 8, 1);
            func_ov004_0216b06c(arg0, var1 + 0x96, 2, 0xd3, 0xbe, var3 + 0x13, 8, 2, 0);

            var3 += 0xc;
        }
        if (var0 == 4) var3 -= 1;
    }

    func_ov004_0216b120(arg0, 0x29, 2, 0xd3, 2, var3 + 0x14, 0xcb, 1);
    func_ov004_0216afb0(arg0, 0x44, 2, 0xd3, 0x13, 7, var3 + 0x17, 0xa, 1);

    if (data_ov004_02171034.unknown_8_ != 0) {
        func_ov004_0216b06c(arg0, 0x9a, 2, 0xd3, 0x92, var3 + 0x18, 8, 4, 0);
        func_ov004_0216afb0(arg0, 0x4f, 2, 0xd3, 0x34, 0x98, var3 + 0x18, 0xa, 1);
    }
    func_ov004_0216b06c(arg0, 0x9b, 2, 0xd3, 0xa8, var3 + 0x18, 8, 2, 1);
    func_ov004_0216afb0(arg0, 0x50, 2, 0xd3, 0x34, 0xad, var3 + 0x18, 0xa, 1);
    func_ov004_0216b06c(arg0, 0x9c, 2, 0xd3, 0xbd, var3 + 0x18, 8, 2, 1);
    func_ov004_0216afb0(arg0, 0x45, 2, 0xd3, 0x14, 7, var3 + 0x22, 0xa, 1);
    func_ov004_0216afb0(arg0, 0x46, 2, 0xd3, 0x3e7, 0xbd, var3 + 0x22, 0xa, 1);
    }

    for (int var17 = 0; var17 < var0; var17++) {
        void* var18 = func_ov011_021849c8(arg0);
        Struct_ov004_0216ba70* var19 = func_ov023_021f6880(var18, var17 * 3 + 0x38);
        if (var19) {
            var19->unknown_20_ = &var4->unknown_0_[var17];
        }

        int var20 = var4->unknown_0_[var17].unknown_30_;
        if (var20 >= 0 && var20 < 0xd) {
            int var21 = 0x3e7;
            if (var20 != 0) var21 = (short)(var20 + 6);
            unsigned char var22 = inline_ov004_0216ba70_27(GameState::GetInstance())->unknown_d6_;
            if (var22 == 1) var21 = 0x46;
            func_ov004_0216aed0(arg0, var17 * 3 + 0x39, var21, 0);
        }

        int var23 = var4->unknown_0_[var17].unknown_31_;
        if (var23 >= 0 && var23 <= 0xa) {
            int var24 = 0x3e7;
            if (var23 != 0) var24 = (short)(var23 + 0x15);
            func_ov004_0216aed0(arg0, var17 + 0x47, var24, 0);
        }

        int var25 = (unsigned int)var17 * 3 + 0x39;
        int var26 = func_ov004_0216af24(arg0, var25);
        Struct_ov004_0216ba70* var27 = func_ov023_021f6880(func_ov011_021849c8(arg0), var25);
        if (var27) {
            const Type_ov004_0216ba70& var28 = var27->inline_ov004_0216ba70_29();
            *(Vector3i*)((int*)&var7) = *(Vector3i const*)((int*)&var28);
            var7.x = var7.x + ((var26 + 2) << 12);

            Struct_ov004_0216ba70* var29 = func_ov023_021f6880(func_ov011_021849c8(arg0), var17 + 0x47);
            if (var29) {
                var29->inline_ov004_0216ba70_26(&var7);
                unsigned char var30 = var4->unknown_0_[var17].unknown_31_;
                if (var30 == 0xa) {
                    var29->inline_ov004_0216ba70_16(0xd);
                } else if (var30 != 0) {
                    var29->inline_ov004_0216ba70_16(5);
                }
            }
        }

        unsigned short var31 = var4->unknown_0_[var17].unknown_32_;
        Struct_ov004_0216ba70* var32 = func_ov023_021f6880(func_ov011_021849c8(arg0), var17 + 0x96);
        if (var32) {
            var32->inline_ov004_0216ba70_18(var31);
        }
    }

    int var33 = var4->unknown_d0_;
    int var34 = 0;
    if (var33 >= 1100 && var33 < 1200) var34 = 1;
    else if (var33 >= 100 && var33 < 200) var34 = 2;
    else if (var33 >= 1200 && var33 < 1300) var34 = 3;
    else if (var33 >= 1300 && var33 < 1400) var34 = 4;
    else if (var33 >= 4200 && var33 < 4300) var34 = 5;
    else if (var33 >= 1500 && var33 < 1600) var34 = 6;
    else if (var33 >= 5800 && var33 < 5900) var34 = 7;
    else if (var33 >= 1800 && var33 < 1900) var34 = 8;
    else if (var33 >= 1900 && var33 < 2000) var34 = 9;
    else if (var33 >= 200 && var33 < 300) var34 = 0xa;
    else if (var33 >= 2100 && var33 < 2200) var34 = 0xb;
    else if (var33 >= 2000 && var33 < 2100) var34 = 0xc;
    else if (var33 >= 2200 && var33 < 2300) var34 = 0xd;
    else if (var33 >= 2300 && var33 < 2400) var34 = 0xe;
    else if (var33 >= 5700 && var33 < 5800) var34 = 0xf;
    else if (var33 >= 400 && var33 < 500) var34 = 0x10;

    int var35 = -1;
    switch (var34) {
    case 0: var35 = 0x24; break;
    case 1: var35 = 0x25; break;
    case 2: var35 = 0x26; break;
    case 3: var35 = 0x27; break;
    case 4: var35 = 0x28; break;
    case 5: var35 = 0x29; break;
    case 6: var35 = 0x2a; break;
    case 7: var35 = 0x2b; break;
    case 8: var35 = 0x2c; break;
    case 9: var35 = 0x2d; break;
    case 0xa: var35 = 0x2e; break;
    case 0xb: var35 = 0x2f; break;
    case 0xc: var35 = 0x30; break;
    case 0xd: var35 = 0x31; break;
    case 0xe: var35 = 0x32; break;
    case 0xf: var35 = 0x33; break;
    case 0x10: var35 = 0x47; break;
    }

    if (inline_ov004_0216ba70_27(GameState::GetInstance())->unknown_d7_ != 0) {
        var35 = 0x2bc;
    }
    if (var35 >= 0) {
        func_ov004_0216aed0(arg0, 0x46, var35, 1);
    }

    unsigned char var36;
    unsigned char var37;
    unsigned short var38;
    var38 = data_ov004_02171034.unknown_8_;
    var36 = data_ov004_02171034.unknown_6_;
    var37 = data_ov004_02171034.unknown_7_;
    if (var38 != 0) {
        Struct_ov004_0216ba70* var39 = func_ov023_021f6880(func_ov011_021849c8(arg0), 0x9a);
        if (var39) var39->inline_ov004_0216ba70_18(var38);
    }
    Struct_ov004_0216ba70* var40 = func_ov023_021f6880(func_ov011_021849c8(arg0), 0x9b);
    if (var40) var40->inline_ov004_0216ba70_18(var37);
    Struct_ov004_0216ba70* var41 = func_ov023_021f6880(func_ov011_021849c8(arg0), 0x9c);
    if (var41) var41->inline_ov004_0216ba70_18(var36);

    void* var42 = func_ov004_0216ae9c(arg0, 0xd3);
    func_ov023_021f8120(var42);

    int var43 = data_ov004_02171034.unknown_c_;
    if (var0 >= 1 && var0 <= 4) {
        Struct_ov004_0217017a* var44 = &data_ov004_0217017a[var0 - 1];
        func_ov023_021f7eb8(var42, arg0, var43, 6, var44->unknown_0_, 0x1a, var44->unknown_2_, 0, 1, 0);
    }

    func_ov011_02184ad8((struct Struct_ov004_0216b7bc*)arg0);
    return 0;
}
