#include <globaldefs.h>
#if defined(jpn)
#define func_ov023_021f6524 func_ov004_02168f08
extern "C" void* func_ov004_02168fa4(void*, int);
extern "C" void func_ov023_021f809c(void*, void*);
#endif

struct Struct_ov004_02153e20 {
    char unknown_0_[0x20];
    short* unknown_20_;
    unsigned short unknown_24_;
    unsigned short unknown_26_;
    char unknown_28_[0x34];
    short unknown_5c_;
    short unknown_5e_;
};

class Struct_ov004_0216a610_4 {
public:
    virtual void inline_ov004_0216a610_31(); virtual void inline_ov004_0216a610_32(); virtual void inline_ov004_0216a610_33(); virtual void inline_ov004_0216a610_34();
    virtual void inline_ov004_0216a610_35(); virtual void inline_ov004_0216a610_36(); virtual void inline_ov004_0216a610_37(); virtual void inline_ov004_0216a610_38();
    virtual void inline_ov004_0216a610_39(); virtual void inline_ov004_0216a610_40(); virtual void inline_ov004_0216a610_41(); virtual void inline_ov004_0216a610_42();
    virtual void inline_ov004_0216a610_43(); virtual void inline_ov004_0216a610_44(); virtual void inline_ov004_0216a610_45(); virtual void inline_ov004_0216a610_46();
    virtual void inline_ov004_0216a610_47(); virtual void inline_ov004_0216a610_48(); virtual void inline_ov004_0216a610_49(); virtual void inline_ov004_0216a610_50();
    virtual void inline_ov004_0216a610_51(); virtual void inline_ov004_0216a610_52(); virtual void inline_ov004_0216a610_53(); virtual void inline_ov004_0216a610_54();
    virtual void inline_ov004_0216a610_55(); virtual void inline_ov004_0216a610_56(); virtual void inline_ov004_0216a610_57(); virtual void inline_ov004_0216a610();
    virtual void inline_ov004_0216a610_2(); virtual void inline_ov004_0216a610_3(); virtual void inline_ov004_0216a610_4(); virtual void inline_ov004_0216a610_5();
    virtual void inline_ov004_0216a610_6(); virtual void inline_ov004_0216a610_7(); virtual void inline_ov004_0216a610_8(); virtual void inline_ov004_0216a610_9();
    virtual void inline_ov004_0216a610_10(); virtual void inline_ov004_0216a610_11(); virtual void inline_ov004_0216a610_12(); virtual void inline_ov004_0216a610_13();
    virtual void inline_ov004_0216a610_14(); virtual void inline_ov004_0216a610_15(); virtual void inline_ov004_0216a610_16(); virtual void inline_ov004_0216a610_17();
    virtual void inline_ov004_0216a610_18(); virtual void inline_ov004_0216a610_19(); virtual void inline_ov004_0216a610_20(); virtual void inline_ov004_0216a610_21();
    virtual void inline_ov004_0216a610_22(); virtual void inline_ov004_0216a610_23(); virtual void inline_ov004_0216a610_24(); virtual void inline_ov004_0216a610_25();
    virtual void inline_ov004_0216a610_26(); virtual void inline_ov004_0216a610_27(); virtual void inline_ov004_0216a610_28(); virtual void inline_ov004_0216a610_29();
    virtual void inline_ov004_0216a610_30(int arg0);

    char unknown_4_[8];
    unsigned char unknown_c_;
    char unknown_d_[0x13];
    char* unknown_20_;
};

struct Struct_ov004_0216a610 {
    char unknown_0_[6];
    char unknown_6_[0xb];
    unsigned char unknown_11_;
    unsigned short unknown_12_0_ : 14;
    unsigned short unknown_13_6_ : 1;
    unsigned short unknown_13_7_ : 1;
    char unknown_14_[0x18];
};

struct Struct_ov004_0216a610_2 {
    unsigned char unknown_0_;
    char unknown_1_[3];
    struct Struct_ov004_0216a610 unknown_4_[1];
};

struct Struct_ov004_0216a610_3 {
#if !defined(jpn)
    char unknown_0_[8][0x30];
#endif
    char unknown_180_[0x10];
    struct Struct_ov004_0216a610_2* unknown_190_;
};

extern "C" struct Grid021f9b30* func_ov023_021f6524(void* ctx, int value);
Widget0216a610* GetNodeIfType8_02168a6c(void* a, int id);
Widget0216a610* GetNodeIfType15_02168a38(void* a, int id);
extern "C" void Font_DecodeText(void* src, void* dst, int flag);
extern "C" int _Z26SetCellIfInBounds_021f9b30P12Grid021f9b30sjj(struct Grid021f9b30* self, unsigned short val, unsigned int x, unsigned int y);
void DispatchNode_021f6630(int a, int b, short c, short d);

extern struct Struct_ov004_0216a610_3* data_ov004_02171030;

// USA: func_ov004_0216a610
extern "C" ARM int func_ov004_0216a610(void* arg0) {
    struct Struct_ov004_0216a610_2* var0 = data_ov004_02171030->unknown_190_;
    if (var0 == 0) {
        return 0;
    }
    struct Struct_ov004_02153e20* var1 = func_ov023_021f6524(arg0, 0x64);
    short var2 = var1->unknown_5c_;
    short var3 = var1->unknown_5e_;
    int var4;
    for (var4 = 0; var4 < 8; var4++) {
        Struct_ov004_0216a610_4* var5 = func_ov004_02168a6c(arg0, var4 + 0xc8);
        Struct_ov004_0216a610_4* var6 = func_ov004_02168a6c(arg0, var4 + 0xd8);
        Struct_ov004_0216a610_4* var7 = func_ov004_02168a38(arg0, var4 + 0xd0);
        Struct_ov004_0216a610_4* var8 = func_ov004_02168a38(arg0, var4 + 0xe0);
        struct Struct_ov004_0216a610* var9 = &var0->unknown_4_[var4 + var2 * 8];
        if (var9->unknown_13_6_) {
#if defined(jpn)
            var5->unknown_20_ = var9->unknown_6_;
#else
            char* name = data_ov004_02171030->names[i];
            Font_DecodeText(e->name, name, 1);
            label->text = name;
#endif
            var7->inline_ov004_0216a610_30(var9->unknown_12_0_);
            var8->inline_ov004_0216a610_30(var9->unknown_11_);
            var5->unknown_c_ &= ~8;
            var6->unknown_c_ &= ~8;
            var7->unknown_c_ &= ~8;
            var8->unknown_c_ &= ~8;
            func_ov023_021f9b30(var1, var4 + 0xc8, (unsigned short)var4, 0);
        } else {
            var5->unknown_c_ |= 8;
            var6->unknown_c_ |= 8;
            var7->unknown_c_ |= 8;
            var8->unknown_c_ |= 8;
            func_ov023_021f9b30(var1, 0, (unsigned short)var4, 0);
        }
    }
#if defined(jpn)
    void* var11 = func_ov004_02168fa4(arg0, 0x14);
    if(var11) {
        *(short*)((char*)var11+0x104)=var2;
        *(short*)((char*)var11+0x106)=var3;
        func_ov023_021f809c(var11,arg0);
    }
#else
    func_ov023_021f6630((int)arg0, 0x14, var2, var3);
#endif
    return 0;
}
