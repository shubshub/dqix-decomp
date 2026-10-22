#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_02108760_2;
struct Struct_0209c3b4_2;
struct Struct_02072a68_2;
struct Struct_02000c9c_8;
struct Struct_ov004_0216b7bc;

extern "C" void func_0209ca70(void* arg0, int arg1);
extern "C" void func_0205e9f4(struct Struct_02108760_2* arg0, int arg1);
extern "C" void func_0209c3b4(struct Struct_0209c3b4_2* arg0, int arg1);
extern "C" void func_02012028(void* arg0, unsigned char arg1);
extern "C" void* func_ov004_0216b1c4(void* arg0, int arg1);
extern "C" void* func_ov004_0216ae9c(void* arg0, int arg1);
extern "C" unsigned char func_0200fb08(struct Struct_02000c9c_8* arg0);
extern "C" void func_ov011_02184ad8(struct Struct_ov004_0216b7bc* arg0);
extern "C" void* func_02072a68(struct Struct_02072a68_2* arg0, int arg1);

class Struct_ov004_0216c810_3 {
public:
    virtual void inline_ov004_0216c810_22(); virtual void inline_ov004_0216c810_23(); virtual void inline_ov004_0216c810_24(); virtual void inline_ov004_0216c810_25();
    virtual void inline_ov004_0216c810_26(); virtual void inline_ov004_0216c810_27(); virtual void inline_ov004_0216c810_28(); virtual void inline_ov004_0216c810_29();
    virtual void inline_ov004_0216c810_30(); virtual void inline_ov004_0216c810_31(); virtual void inline_ov004_0216c810_32(); virtual void inline_ov004_0216c810();
    virtual void inline_ov004_0216c810_2(); virtual void inline_ov004_0216c810_3(); virtual void inline_ov004_0216c810_4(); virtual void inline_ov004_0216c810_5();
    virtual void inline_ov004_0216c810_6();
    virtual void inline_ov004_0216c810_7(int arg0);
    virtual void inline_ov004_0216c810_8(); virtual void inline_ov004_0216c810_9(); virtual void inline_ov004_0216c810_10(); virtual void inline_ov004_0216c810_11();
    virtual void inline_ov004_0216c810_12(); virtual void inline_ov004_0216c810_13(); virtual void inline_ov004_0216c810_14(); virtual void inline_ov004_0216c810_15();
    virtual void inline_ov004_0216c810_16(); virtual void inline_ov004_0216c810_17(); virtual void inline_ov004_0216c810_18(); virtual void inline_ov004_0216c810_19();
    virtual void inline_ov004_0216c810_20();
    virtual void inline_ov004_0216c810_21(int arg0);
    char unknown_4_[8];
    unsigned char unknown_c_;
};

struct Struct_ov004_0216c810 {
    char unknown_0_[0x998];
    int unknown_998_;
    char unknown_99c_[0x19af - 0x99c];
    unsigned char unknown_19af_;
    char unknown_19b0_[0x19ca - 0x19b0];
    unsigned char unknown_19ca_;
};

struct Struct_ov004_0216c810_2 {
    char unknown_0_[0x7f73];
    unsigned char unknown_7f73_;
};

struct Struct_ov004_02170174 {
    unsigned char unknown_0_[6];
};

struct Struct_ov004_02171034_2 {
    unsigned char unknown_0_;
    unsigned char unknown_1_;
    unsigned char unknown_2_;
    unsigned char unknown_3_;
    unsigned char unknown_4_;
    char unknown_5_[5];
    unsigned short unknown_a_;
    int unknown_c_;
};

extern "C" void* func_ov011_021849c8(void* arg0);
extern "C" Struct_ov004_0216c810_3* func_ov023_021f6880(void* arg0, int arg1);
extern "C" int func_ov023_021f6f10(void* arg0);
extern "C" void func_ov011_021848a0(void* arg0, int arg1);
extern "C" void func_ov004_0216b498(void* arg0, int arg1, int arg2);
extern "C" int func_ov004_0216b2c8(void* arg0, int arg1, int arg2, int arg3);
extern "C" void func_ov004_0216b20c(void* arg0, int arg1, int arg2, int arg3);
extern "C" void func_ov023_021f9ba8(void* arg0, unsigned short arg1);
extern "C" struct Struct_02072a68_2* func_ov023_021fa598(void* arg0);
extern "C" Struct_ov004_0216c810* func_020421a0();
extern "C" void func_0204500c(Struct_ov004_0216c810* arg0, void* arg1, int arg2, int arg3);
extern "C" void func_ov023_021f8120(void* arg0);
extern "C" void func_ov023_021f7eb8(void* arg0, void* arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9);
extern "C" void func_ov004_0216ba70(void* arg0);

extern char data_02109bf4[];
extern struct Obj0205e9f4 g_sePlayer;
extern MenuState02171034 data_ov004_02171034;
extern Bytes6 data_ov004_02170174;

// USA: func_ov004_0216c810
extern "C" ARM int func_ov004_0216c810(void* arg0) {
    GameState* var0;
    Struct_ov004_0216c810_2* var1;
    int var2;
    int var3;
    int var4;
    Struct_ov004_0216c810_3* var5;

    SetModeClamped0209ca70(data_02109bf4, 3);
    SetStateAndDispatch0205e9f4(&g_sePlayer, 3);
    data_ov004_02171034.byte4 = 3;
    data_ov004_02171034.byte1 = 3;
    data_ov004_02171034.messageId = 0;
    if (data_ov004_02171034.state3 != 4) {
        SetStateAndDispatch0209c3b4((struct Actor0209c3b4*)data_02109bf4, 2);
    }
    var0 = GameState::GetInstance();
    func_02010828(var0);
    var2 = 0;
    var3 = 0;
    data_ov004_02171034.unknown_2_ = 0;
    func_ov023_021f6880(func_ov011_021849c8(arg0), 0xb)->unknown_c_ |= 8;

    if (data_ov004_02171034.unknown_3_ == 0) {
        func_ov023_021f6880(func_ov011_021849c8(arg0), 1)->unknown_c_ |= 8;
        func_ov011_021848a0(arg0, 0xc9);
        return 0;
    } else if (data_ov004_02171034.unknown_3_ == 1) {
        var5 = func_ov023_021f6880(func_ov011_021849c8(arg0), 0xc);
        if (var5) var5->unknown_c_ &= ~8;
        var2 = 1;
        var3 = 0;
        var4 = 0x12e;
        func_ov004_0216b1c4(arg0, var4);
        data_ov004_02171034.unknown_a_ = var4;
        func_ov004_0216b498(arg0, var2, var3);
        for (int var6 = 0; var6 < 3; var6++) {
            func_ov004_0216b2c8(arg0, var4, var6 + 0x32, var6);
        }
        var5 = func_ov023_021f6880(func_ov011_021849c8(arg0), 0x32);
        if (var5) {
            var5->inline_ov004_0216c810_7(8);
            var5->inline_ov004_0216c810_21(8);
        }
        func_ov004_0216b20c(arg0, 0x33, 0x96, 0);
        var5 = func_ov023_021f6880(func_ov011_021849c8(arg0), 0x34);
        if (var5) {
            var5->inline_ov004_0216c810_7(0xa);
            var5->inline_ov004_0216c810_21(0xa);
        }
        var1 = (Struct_ov004_0216c810_2*)var0;
        int var7 = var1->unknown_7f73_;
        if (var7 > 0) {
            Struct_ov004_0216c810_3* var8 = func_ov023_021f6880(func_ov011_021849c8(arg0), 0x12e);
            Struct_ov004_0216c810_3* var9;
            if (var8 == 0) {
                var9 = 0;
            } else if (func_ov023_021f6f10(var8) != 7) {
                var9 = 0;
            } else {
                var9 = var8;
            }
            if (var9) {
                func_ov023_021f9ba8(var9, var7);
            }
            var1->unknown_7f73_ = 0;
        }
    } else if (data_ov004_02171034.unknown_3_ == 2) {
        var5 = func_ov023_021f6880(func_ov011_021849c8(arg0), 0xc);
        if (var5) var5->unknown_c_ &= ~8;
        var2 = 2;
        var3 = 0;
        var4 = 0x12d;
        func_ov004_0216b1c4(arg0, var4);
        data_ov004_02171034.unknown_a_ = var4;
        func_ov004_0216b498(arg0, var2, var3);
        for (int var10 = 0; var10 < 2; var10++) {
            func_ov004_0216b2c8(arg0, var4, var10 + 0x32, var10);
        }
        var5 = func_ov023_021f6880(func_ov011_021849c8(arg0), 0x32);
        if (var5) {
            var5->inline_ov004_0216c810_7(5);
            var5->inline_ov004_0216c810_21(5);
        }
        var5 = func_ov023_021f6880(func_ov011_021849c8(arg0), 0x33);
        if (var5) {
            var5->inline_ov004_0216c810_7(0xa);
            var5->inline_ov004_0216c810_21(0xa);
        }
    } else if (data_ov004_02171034.unknown_3_ == 3) {
        var2 = 3;
        var4 = 0x12c;
        func_ov004_0216b1c4(arg0, var4);
        data_ov004_02171034.unknown_a_ = var4;
        func_ov004_0216b498(arg0, var2, var3);
        func_ov004_0216b2c8(arg0, var4, 0x32, var3);
        var5 = func_ov023_021f6880(func_ov011_021849c8(arg0), 0x32);
        if (var5) {
            var5->inline_ov004_0216c810_7(8);
            var5->inline_ov004_0216c810_21(8);
        }
    } else if (data_ov004_02171034.unknown_3_ == 4) {
        func_02012028(var0, 0);
        func_ov011_021848a0(arg0, 0x190);
        return 0;
    } else if (data_ov004_02171034.unknown_3_ == 5) {
        var5 = func_ov023_021f6880(func_ov011_021849c8(arg0), 0xc);
        if (var5) var5->unknown_c_ &= ~8;
        var2 = 1;
        var3 = 0;
        var4 = 0x12e;
        func_ov004_0216b1c4(arg0, var4);
        data_ov004_02171034.unknown_a_ = var4;
        func_ov004_0216b498(arg0, var2, var3);
        for (int var11 = 0; var11 < 3; var11++) {
            func_ov004_0216b2c8(arg0, var4, var11 + 0x32, var11);
        }
        var5 = func_ov023_021f6880(func_ov011_021849c8(arg0), 0x32);
        if (var5) {
            var5->inline_ov004_0216c810_7(0);
            var5->inline_ov004_0216c810_21(0);
        }
        func_ov004_0216b20c(arg0, 0x33, 0x96, 0);
        var5 = func_ov023_021f6880(func_ov011_021849c8(arg0), 0x34);
        if (var5) {
            var5->inline_ov004_0216c810_7(0xa);
            var5->inline_ov004_0216c810_21(0xa);
        }
    } else if (data_ov004_02171034.unknown_3_ == 6) {
        func_02012028(var0, 0);
        void* var12 = func_ov011_021849c8(arg0);
        Struct_ov004_0216c810_3* var13 = func_ov023_021f6880(var12, 1);
        if (var13 == 0) return 0;
        if (func_ov023_021f6f10(var13) != 0xb) return 0;
        var13->unknown_c_ |= 8;
        Struct_ov004_0216c810_3* var14 = func_ov023_021f6880(var12, 0x192);
        if (var14 == 0) return 0;
        if (func_ov023_021f6f10(var14) != 4) return 0;
        struct Struct_02072a68_2* var15 = func_ov023_021fa598(var14);
        Struct_ov004_0216c810* var16 = func_020421a0();
        var16->unknown_998_ = 1;
        func_0204500c(var16, func_02072a68(var15, 0x5dc), 0, 0xe3);
        var16->unknown_19ca_ = 0;
        var16->unknown_19af_ = 0;
        func_02012028(var0, 0);
        return 0;
    } else if (data_ov004_02171034.unknown_3_ == 7) {
        func_02012028(var0, 0);
        func_ov011_021848a0(arg0, 0x258);
        return 0;
    }

    func_ov011_02184ad8((struct Struct_ov004_0216b7bc*)arg0);
    int var17;
    void* var18 = func_ov004_0216ae9c(arg0, 0xd2);
    func_ov023_021f8120(var18);
    var17 = 0x60;
    unsigned char var19 = func_0200fb08((struct Struct_02000c9c_8*)GameState::GetInstance());
    Struct_ov004_02170174 var20 = data_ov004_02170174;
    int var21;
    switch (var2) {
    case 0:
        func_ov023_021f7eb8(var18, arg0, var17, 1, 1, 0x12, 5, 0, 1, 0);
        var17 += 0xb40;
        break;
    case 1:
        switch (var3) {
        case 0:
            var21 = var20.unknown_0_[var19];
            func_ov023_021f7eb8(var18, arg0, var17, 1, 1, var21, 6, 0, 1, 0);
            var17 += var21 * 0xc0;
            break;
        default:
            var21 = var20.unknown_0_[var19];
            func_ov023_021f7eb8(var18, arg0, var17, 1, 1, var21, 6, 0, 1, 0);
            var17 += var21 * 0xc0;
            break;
        }
        break;
    case 2:
        var21 = var20.unknown_0_[var19];
        func_ov023_021f7eb8(var18, arg0, var17, 1, 1, var21, 5, 0, 1, 0);
        var17 += var21 * 0xa0;
        break;
    case 3:
        func_ov023_021f7eb8(var18, arg0, var17, 1, 1, 0xc, 3, 0, 1, 0);
        var17 += 0xb40;
        break;
    }
    data_ov004_02171034.unknown_c_ = var17;
    func_ov011_02184ad8((struct Struct_ov004_0216b7bc*)arg0);
    if (var2 == 1 && data_ov004_02171034.unknown_3_ != 5) {
        func_ov004_0216ba70(arg0);
    }
    return 0;
}
