#include <globaldefs.h>


extern "C" int func_ov004_021551a8(void* arg0);
extern "C" int func_ov004_02155b6c(void* arg0);
extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void*, int);
extern "C" int func_ov023_021f6f10(void*);
extern "C" int func_ov023_021f98e0(void*, void*);
extern "C" unsigned int func_ov023_021f9bb0(struct Struct_ov004_021549e4_2* arg0);
extern "C" unsigned short func_ov023_021f9bc0(struct Struct_ov004_021549e4_4* arg0);
extern "C" unsigned int func_ov023_021f9b6c(struct Struct_ov004_021549e4_3* arg0, unsigned int arg1, unsigned int arg2);
extern "C" void* func_ov023_021f9cb8(void* arg0, void* arg1, void* arg2);
extern "C" void func_ov023_021f88b8(void* arg0, void* arg1, int arg2);
extern "C" void func_ov004_0215534c(void*);
struct SePlayer;
void SePlayer_Play(struct SePlayer* obj, int a, int b);
extern struct SePlayer g_sePlayer;

struct Struct_ov004_02155bbc_3 { char unknown_0_[0x10]; unsigned char unknown_10_; };
extern struct Struct_ov004_02155bbc_3* data_ov004_021707c4;

class Struct_ov004_02155bbc {
public:
    virtual void inline_ov004_02155bbc(); virtual void inline_ov004_02155bbc_2(); virtual void inline_ov004_02155bbc_3(); virtual void inline_ov004_02155bbc_4();
    virtual void inline_ov004_02155bbc_5(); virtual void inline_ov004_02155bbc_6(); virtual void inline_ov004_02155bbc_7(); virtual void inline_ov004_02155bbc_8();
    virtual void inline_ov004_02155bbc_9(); virtual void inline_ov004_02155bbc_10(); virtual void inline_ov004_02155bbc_11(); virtual void inline_ov004_02155bbc_12();
    virtual void inline_ov004_02155bbc_13(); virtual void inline_ov004_02155bbc_14(); virtual void inline_ov004_02155bbc_15(); virtual void inline_ov004_02155bbc_16();
    virtual void inline_ov004_02155bbc_17(); virtual void inline_ov004_02155bbc_18(); virtual void inline_ov004_02155bbc_19(); virtual void inline_ov004_02155bbc_20();
    virtual void inline_ov004_02155bbc_21(); virtual void inline_ov004_02155bbc_22(); virtual void inline_ov004_02155bbc_23(); virtual void inline_ov004_02155bbc_24();
    virtual void inline_ov004_02155bbc_25(); virtual void inline_ov004_02155bbc_26(); virtual void inline_ov004_02155bbc_27(); virtual void inline_ov004_02155bbc_28();
    virtual void inline_ov004_02155bbc_29(); virtual void inline_ov004_02155bbc_30(); virtual void inline_ov004_02155bbc_31(); virtual void inline_ov004_02155bbc_32();
    virtual void inline_ov004_02155bbc_33(); virtual void inline_ov004_02155bbc_34(); virtual void inline_ov004_02155bbc_35(); virtual void inline_ov004_02155bbc_36();
    virtual void inline_ov004_02155bbc_37(); virtual void inline_ov004_02155bbc_38(); virtual void inline_ov004_02155bbc_39(); virtual void inline_ov004_02155bbc_40();
    virtual void inline_ov004_02155bbc_41(); virtual void inline_ov004_02155bbc_42(); virtual void inline_ov004_02155bbc_43(); virtual void inline_ov004_02155bbc_44();
    virtual void inline_ov004_02155bbc_45(); virtual void inline_ov004_02155bbc_46(); virtual void inline_ov004_02155bbc_47(); virtual void inline_ov004_02155bbc_48();
    virtual void inline_ov004_02155bbc_49(); virtual void inline_ov004_02155bbc_50(); virtual void inline_ov004_02155bbc_51(); virtual void inline_ov004_02155bbc_52();
    virtual void inline_ov004_02155bbc_53(); virtual void inline_ov004_02155bbc_54(); virtual void inline_ov004_02155bbc_55(); virtual void inline_ov004_02155bbc_56();
    virtual void inline_ov004_02155bbc_57(); virtual void inline_ov004_02155bbc_58(); virtual void inline_ov004_02155bbc_59();
    virtual void* inline_ov004_02155bbc_60();
};

struct Struct_ov004_021549e4 { void* unknown_0_; };
extern "C" short func_ov023_021e1da4(struct Struct_ov004_021549e4* arg0, int arg1);

struct Struct_ov004_021549e4_5;
extern "C" void func_ov023_021f9bdc(struct Struct_ov004_021549e4_5* arg0, int arg1);

struct Struct_ov004_02155bbc_2 {
    char unknown_0_[0x5c];
    short unknown_5c_;
    short unknown_5e_;
};

// USA: func_ov004_02155bbc
extern "C" ARM int func_ov004_02155bbc(void* arg0) {
    void* var0 = (void*)func_ov004_021551a8(arg0);
    if (!var0) return 0;

    data_ov004_021707c4->unknown_10_++;
    data_ov004_021707c4->unknown_10_ &= 1;

    func_ov004_02155b6c(arg0);

    void* var1 = func_ov011_021849c8(arg0);
    void* var2 = func_ov023_021f6880(var1, 0x39);
    if (!var2) return 0;

    void* var3 = ((Struct_ov004_02155bbc*)var2)->inline_ov004_02155bbc_60();
    if (!var3) return 0;

    short var4 = func_ov023_021e1da4((struct Struct_ov004_021549e4*)var3, *(short*)((char*)var0 + 0x18));
    if (var4 < 0) return 0;

    void* var5 = func_ov011_021849c8(arg0);
    void* var6 = func_ov023_021f6880(var5, 0x2c);
    if (!var6) return 0;
    if (func_ov023_021f6f10(var6) != 7) return 0;

    struct Struct_ov004_02155bbc_2* var7 = (struct Struct_ov004_02155bbc_2*)var6;
    short var8 = var7->unknown_5e_;
    var7->unknown_5c_ = (short)(var4 / 16);
    var7->unknown_5e_ = var8;
    short var9 = (short)(var4 % 16);
    unsigned short var10 = (unsigned short)var9;
    func_ov023_021f9bdc((struct Struct_ov004_021549e4_5*)var6, var10);

    func_ov023_021f98e0(var6, arg0);

    unsigned int var11 = func_ov023_021f9bb0((struct Struct_ov004_021549e4_2*)var6);
    unsigned short var12 = func_ov023_021f9bc0((struct Struct_ov004_021549e4_4*)var6);
    unsigned int var13 = func_ov023_021f9b6c((struct Struct_ov004_021549e4_3*)var6, var11, var12);

    void* var14 = func_ov011_021849c8(arg0);
    void* var15 = func_ov023_021f6880(var14, var13);
    if (var15) {
        if (func_ov023_021f6f10(var15) == 8) {
            void* var16 = func_ov023_021f9cb8(var6, arg0, var15);
            if (var16) {
                func_ov023_021f88b8(var16, arg0, 0x8000);
            }
        }
    }

    func_ov004_0215534c(a1);
    SePlayer_Play(&g_sePlayer, 1, 0);
    return 0;
}
