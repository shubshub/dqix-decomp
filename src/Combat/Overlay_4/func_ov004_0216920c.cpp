#include <globaldefs.h>

struct Struct_ov004_0216920c_7;

class Struct_ov004_0216920c_8 {
public:
    char unknown_4_[0x8];
    unsigned char unknown_c_;
    char unknown_d_[0x13];
    void* unknown_20_;
    char unknown_24_[0x19];
    unsigned char unknown_3d_;
    char unknown_3e_[0x1e];
    short unknown_5c_;
    short unknown_5e_;

    virtual void inline_ov004_0216920c_30();
    virtual void inline_ov004_0216920c_31();
    virtual void inline_ov004_0216920c_32();
    virtual void inline_ov004_0216920c_33();
    virtual void inline_ov004_0216920c_34();
    virtual void inline_ov004_0216920c_35();
    virtual void inline_ov004_0216920c_36();
    virtual void inline_ov004_0216920c_37();
    virtual void inline_ov004_0216920c_38();
    virtual void inline_ov004_0216920c_39();
    virtual void inline_ov004_0216920c_40();
    virtual void inline_ov004_0216920c_41();
    virtual void inline_ov004_0216920c_42();
    virtual void inline_ov004_0216920c_43();
    virtual void inline_ov004_0216920c_44();
    virtual void inline_ov004_0216920c_45();
    virtual void inline_ov004_0216920c_46();
    virtual void inline_ov004_0216920c_47(int arg0);
    virtual void inline_ov004_0216920c_48();
    virtual void inline_ov004_0216920c_49(int arg0);
    virtual void inline_ov004_0216920c_50();
    virtual void inline_ov004_0216920c_51(int arg0);
    virtual void inline_ov004_0216920c_52();
    virtual void inline_ov004_0216920c_53();
    virtual void inline_ov004_0216920c_54();
    virtual void inline_ov004_0216920c_55();
    virtual void inline_ov004_0216920c_56();
    virtual void inline_ov004_0216920c_57();
    virtual void inline_ov004_0216920c();
    virtual void inline_ov004_0216920c_2();
    virtual void inline_ov004_0216920c_3();
    virtual void inline_ov004_0216920c_4(int arg0);
    virtual void inline_ov004_0216920c_5();
    virtual void inline_ov004_0216920c_6();
    virtual void inline_ov004_0216920c_7();
    virtual void inline_ov004_0216920c_8();
    virtual void inline_ov004_0216920c_9();
    virtual void inline_ov004_0216920c_10();
    virtual void inline_ov004_0216920c_11();
    virtual void inline_ov004_0216920c_12();
    virtual void inline_ov004_0216920c_13();
    virtual void inline_ov004_0216920c_14();
    virtual void inline_ov004_0216920c_15();
    virtual void inline_ov004_0216920c_16();
    virtual void inline_ov004_0216920c_17();
    virtual void inline_ov004_0216920c_18();
    virtual void inline_ov004_0216920c_19();
    virtual void inline_ov004_0216920c_20();
    virtual void inline_ov004_0216920c_21();
    virtual void inline_ov004_0216920c_22();
    virtual void inline_ov004_0216920c_23();
    virtual void inline_ov004_0216920c_24();
    virtual void inline_ov004_0216920c_25();
    virtual void inline_ov004_0216920c_26();
    virtual void inline_ov004_0216920c_27();
    virtual void inline_ov004_0216920c_28();
    virtual void inline_ov004_0216920c_29(int arg0);
};

struct Struct_ov004_0216920c {
    char unknown_0_[6];
    char unknown_6_[11];
    unsigned char unknown_11_;
    unsigned short unknown_12_0_ : 14;
    unsigned short unknown_13_6_ : 1;
    char unknown_14_[0x2c - 0x14];
};

struct Struct_ov004_0216920c_2 {
    unsigned char unknown_0_;
    char unknown_1_[3];
    struct Struct_ov004_0216920c unknown_4_[16];
};

struct Struct_ov004_0216920c_3 { char unknown_0_[0x30]; };

struct Struct_ov004_0216920c_4 {
#if defined(jpn)
    char unknown_0_[0x10];
#else
    struct Struct_ov004_0216920c_3 unknown1_0_[8];
    char unknown_180_[0x10];
#endif
    struct Struct_ov004_0216920c_2* unknown_190_;
    char unknown_194_[4];
    unsigned char unknown_198_;
};

struct Struct_ov004_0216920c_5 {
    char unknown_0_[0x1b4];
    int unknown_1b4_;
    unsigned int unknown_1b8_;
    char unknown_1bc_[2];
    short unknown_1be_;
};

extern "C" Node0216920c* func_ov023_021f6524(void* ctx, int value);
void ClearNodeMaskById_021f6600(void*, int, int);
Node0216920c* GetNodeIfType8_02168a6c(void* a, int id);
Node0216920c* GetNodeIfType15_02168a38(void* a, int id);
extern "C" void Font_DecodeText(void*, void*, int);
extern "C" int _Z26SetCellIfInBounds_021f9b30P12Grid021f9b30sjj(struct Grid0216920c* self, unsigned short val, unsigned int x, unsigned int y);
extern "C" void func_ov023_021f65d4(void*, int, int);
extern "C" void func_ov023_021f9da0(void*, unsigned char);
extern "C" void func_ov004_02169b4c(void*);
extern "C" void func_ov023_021f6630(int, int, short, short);

extern struct Struct_ov004_0216920c_4* data_ov004_02171030;

#if defined(jpn)
extern "C" Struct_ov004_0216920c_8* func_ov004_02168f08(void*, int);
extern "C" void func_ov004_02168ed8(void*, int, int);
extern "C" void func_ov004_02168eac(void*, int, int);
struct Struct_ov004_0216920c_6 {
    char unknown_0_[0x104];
    short unknown_104_;
    short unknown_106_;
};
extern "C" Struct_ov004_0216920c_6* func_ov004_02168fa4(void*, int);
extern "C" void func_ov023_021f809c(void*, void*);
#define func_ov023_021f6524 func_ov004_02168f08
#define func_ov023_021f6600 func_ov004_02168ed8
#define func_ov023_021f65d4 func_ov004_02168eac
#endif

// USA: func_ov004_0216920c
extern "C" ARM int func_ov004_0216920c(struct Struct_ov004_0216920c_5* arg0) {
    struct Struct_ov004_0216920c_2* var0 = data_ov004_02171030->unknown_190_;
    if (!var0) return 0;
    Struct_ov004_0216920c_8* var1 = func_ov023_021f6524(arg0, 0x64);
    short var2 = var1->unknown_5c_;
    int var3 = 0;
    short var4 = var1->unknown_5e_;
    func_ov023_021f6600(arg0, 2, 8);
    int var5;
    for (var5 = 0; var5 < 8; var5++) {
        Struct_ov004_0216920c_8* var6 = func_ov004_02168a6c(arg0, var5 + 0xc8);
        Struct_ov004_0216920c_8* var7 = func_ov004_02168a6c(arg0, var5 + 0xd8);
        Struct_ov004_0216920c_8* var8 = func_ov004_02168a38(arg0, var5 + 0xd0);
        Struct_ov004_0216920c_8* var9 = func_ov004_02168a38(arg0, var5 + 0xe0);
        struct Struct_ov004_0216920c* var10 = &var0->unknown_4_[var2 * 8 + var5];
        if (var10->unknown_13_6_) {
#if defined(jpn)
            var6->unknown_20_ = var10->unknown_6_;
#else
            struct Slot0216920c* slot = &data_ov004_02171030->slots[i];
            Font_DecodeText(e->name, slot, 1);
            a->f20 = slot;
#endif
            var8->inline_ov004_0216920c_29(var10->unknown_12_0_);
            var9->inline_ov004_0216920c_29(var10->unknown_11_);
            var9->unknown_3d_ = 1;
            var6->unknown_c_ &= ~8;
            var7->unknown_c_ &= ~8;
            var8->unknown_c_ &= ~8;
            var9->unknown_c_ &= ~8;
            func_ov023_021f9b30((struct Struct_ov004_0216920c_7*)var1, (unsigned short)(var5 + 0xc8), (unsigned short)var5, 0);
            var6->inline_ov004_0216920c_49(3);
        } else {
            var6->unknown_c_ |= 8;
            var7->unknown_c_ |= 8;
            var8->unknown_c_ |= 8;
            var9->unknown_c_ |= 8;
            func_ov023_021f9b30((struct Struct_ov004_0216920c_7*)var1, 0, (unsigned short)var5, 0);
            var6->inline_ov004_0216920c_49(3);
            var3++;
        }
    }
    if (var3 == 8) {
        func_ov023_021f65d4(arg0, 2, 8);
        func_ov023_021f9da0(var1, 0);
    }
    func_ov023_021f65d4(arg0, 0x14, 4);
    data_ov004_02171030->unknown_198_ = 0;
    func_ov004_02169b4c(arg0);
    var1->inline_ov004_0216920c_51(3);
    Struct_ov004_0216920c_8* var12 = func_ov004_02168a6c(arg0, 0xc8);
    var12->inline_ov004_0216920c_47(0xd);
    var12->inline_ov004_0216920c_4(0xd);
#if defined(jpn)
    Struct_ov004_0216920c_6* var13 = func_ov004_02168fa4(arg0, 0x14);
    if (var13) {
        var13->unknown_104_ = var2;
        var13->unknown_106_ = var4;
        func_ov023_021f809c(var13, arg0);
    }
#else
    func_ov023_021f6630((int)arg0, 0x14, var2, var4);
#endif
    if (arg0->unknown_1b4_ != 0 && arg0->unknown_1b8_ > 0xf) {
        arg0->unknown_1be_ = 0xf;
    }
    return 0;
}
