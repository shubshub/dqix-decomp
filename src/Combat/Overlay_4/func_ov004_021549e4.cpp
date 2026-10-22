#include <globaldefs.h>


extern "C" int func_ov004_02153c74(void* arg0);
extern "C" int func_ov004_02154984(void* arg0);
extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void*, int);
extern "C" int func_ov023_021f6f10(void*);
extern "C" int func_ov023_021f98e0(void*, void*);
extern "C" unsigned int func_ov023_021f9bb0(struct Struct_ov004_021549e4_2* arg0);
extern "C" unsigned short func_ov023_021f9bc0(struct Struct_ov004_021549e4_4* arg0);
extern "C" unsigned int func_ov023_021f9b6c(struct Struct_ov004_021549e4_3* arg0, unsigned int arg1, unsigned int arg2);
extern "C" void* func_ov023_021f9cb8(void* arg0, void* arg1, void* arg2);
extern "C" void func_ov023_021f88b8(void* arg0, void* arg1, int arg2);
extern "C" void func_ov004_02153e20(void*);
struct SePlayer;
void SePlayer_Play(struct SePlayer* obj, int a, int b);
extern struct SePlayer g_sePlayer;

struct Struct_ov004_021549e4_8 { char unknown_0_[0x7c]; unsigned char unknown_7c_; };
extern struct Struct_ov004_021549e4_8* data_ov004_021707c0;

class Struct_ov004_021549e4_6 {
public:
    virtual void inline_ov004_021549e4(); virtual void inline_ov004_021549e4_2(); virtual void inline_ov004_021549e4_3(); virtual void inline_ov004_021549e4_4();
    virtual void inline_ov004_021549e4_5(); virtual void inline_ov004_021549e4_6(); virtual void inline_ov004_021549e4_7(); virtual void inline_ov004_021549e4_8();
    virtual void inline_ov004_021549e4_9(); virtual void inline_ov004_021549e4_10(); virtual void inline_ov004_021549e4_11(); virtual void inline_ov004_021549e4_12();
    virtual void inline_ov004_021549e4_13(); virtual void inline_ov004_021549e4_14(); virtual void inline_ov004_021549e4_15(); virtual void inline_ov004_021549e4_16();
    virtual void inline_ov004_021549e4_17(); virtual void inline_ov004_021549e4_18(); virtual void inline_ov004_021549e4_19(); virtual void inline_ov004_021549e4_20();
    virtual void inline_ov004_021549e4_21(); virtual void inline_ov004_021549e4_22(); virtual void inline_ov004_021549e4_23(); virtual void inline_ov004_021549e4_24();
    virtual void inline_ov004_021549e4_25(); virtual void inline_ov004_021549e4_26(); virtual void inline_ov004_021549e4_27(); virtual void inline_ov004_021549e4_28();
    virtual void inline_ov004_021549e4_29(); virtual void inline_ov004_021549e4_30(); virtual void inline_ov004_021549e4_31(); virtual void inline_ov004_021549e4_32();
    virtual void inline_ov004_021549e4_33(); virtual void inline_ov004_021549e4_34(); virtual void inline_ov004_021549e4_35(); virtual void inline_ov004_021549e4_36();
    virtual void inline_ov004_021549e4_37(); virtual void inline_ov004_021549e4_38(); virtual void inline_ov004_021549e4_39(); virtual void inline_ov004_021549e4_40();
    virtual void inline_ov004_021549e4_41(); virtual void inline_ov004_021549e4_42(); virtual void inline_ov004_021549e4_43(); virtual void inline_ov004_021549e4_44();
    virtual void inline_ov004_021549e4_45(); virtual void inline_ov004_021549e4_46(); virtual void inline_ov004_021549e4_47(); virtual void inline_ov004_021549e4_48();
    virtual void inline_ov004_021549e4_49(); virtual void inline_ov004_021549e4_50(); virtual void inline_ov004_021549e4_51(); virtual void inline_ov004_021549e4_52();
    virtual void inline_ov004_021549e4_53(); virtual void inline_ov004_021549e4_54(); virtual void inline_ov004_021549e4_55(); virtual void inline_ov004_021549e4_56();
    virtual void inline_ov004_021549e4_57(); virtual void inline_ov004_021549e4_58(); virtual void inline_ov004_021549e4_59();
    virtual void* inline_ov004_021549e4_60();
};

struct Struct_ov004_021549e4 { void* unknown_0_; };
extern "C" short func_ov023_021e1da4(struct Struct_ov004_021549e4* arg0, int arg1);

struct Struct_ov004_021549e4_5;
extern "C" void func_ov023_021f9bdc(struct Struct_ov004_021549e4_5* arg0, int arg1);

struct Struct_ov004_021549e4_7 {
    char unknown_0_[0x5c];
    short unknown_5c_;
    short unknown_5e_;
};

// USA: func_ov004_021549e4
extern "C" ARM int func_ov004_021549e4(void* arg0) {
    void* var0 = (void*)func_ov004_02153c74(arg0);
    if (!var0) return 0;

    data_ov004_021707c0->unknown_7c_++;
    data_ov004_021707c0->unknown_7c_ &= 1;

    func_ov004_02154984(arg0);

    void* var1 = func_ov011_021849c8(arg0);
    void* var2 = func_ov023_021f6880(var1, 0x39);
    if (!var2) return 0;

    void* var3 = ((Struct_ov004_021549e4_6*)var2)->inline_ov004_021549e4_60();
    if (!var3) return 0;

    short var4 = func_ov023_021e1da4((struct Struct_ov004_021549e4*)var3, *(short*)((char*)var0 + 0x18));
    if (var4 < 0) return 0;

    void* var5 = func_ov011_021849c8(arg0);
    void* var6 = func_ov023_021f6880(var5, 0x2c);
    if (!var6) return 0;
    if (func_ov023_021f6f10(var6) != 7) return 0;

    struct Struct_ov004_021549e4_7* var7 = (struct Struct_ov004_021549e4_7*)var6;
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

    func_ov004_02153e20(a1);
    SePlayer_Play(&g_sePlayer, 1, 0);
    return 0;
}
