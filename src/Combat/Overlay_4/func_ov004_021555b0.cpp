#include <globaldefs.h>

extern "C" int func_ov004_0215513c(void*, short*, short*, short*);
extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void*, int);
#if defined(jpn)
extern "C" int func_ov023_021f6f10(void* self);
#else
extern "C" int func_ov024_021f6f10(void* self);
#endif
extern "C" int func_ov023_021e1f0c(int a, short b, short c, short d);
extern "C" void func_ov023_021f65d4(void* obj, int id, int mask);
extern "C" void func_ov023_021f6600(void* obj, int id, int mask);
extern "C" void func_ov023_021f65b4(void*, void*, short, short);

class Struct_ov004_021555b0 {
public:
    virtual void v00(); virtual void inline_ov004_021555b0_45(); virtual void inline_ov004_021555b0_46(); virtual void inline_ov004_021555b0_47();
    virtual void v04(); virtual void inline_ov004_021555b0_49(); virtual void inline_ov004_021555b0_50(); virtual void inline_ov004_021555b0_51();
    virtual void v08(); virtual void inline_ov004_021555b0_53(); virtual void v10(); virtual void inline_ov004_021555b0_55();
    virtual void inline_ov004_021555b0_56(); virtual void inline_ov004_021555b0_57(); virtual void v14(); virtual void inline_ov004_021555b0_59();
    virtual void inline_ov004_021555b0_60(); virtual void inline_ov004_021555b0(); virtual void v18(); virtual void inline_ov004_021555b0_3();
    virtual void v20(); virtual void inline_ov004_021555b0_5(); virtual void inline_ov004_021555b0_6(); virtual void inline_ov004_021555b0_7();
    virtual void v24(); virtual void inline_ov004_021555b0_9(); virtual void inline_ov004_021555b0_10(); virtual void inline_ov004_021555b0_11();
    virtual void v28(); virtual void inline_ov004_021555b0_13(); virtual void v30(); virtual void inline_ov004_021555b0_15();
    virtual void inline_ov004_021555b0_16(); virtual void inline_ov004_021555b0_17(); virtual void v34(); virtual void inline_ov004_021555b0_19();
    virtual void inline_ov004_021555b0_20(); virtual void inline_ov004_021555b0_21(); virtual void v38(); virtual void inline_ov004_021555b0_23();
    virtual void v40(); virtual void inline_ov004_021555b0_25(); virtual void inline_ov004_021555b0_26(); virtual void inline_ov004_021555b0_27();
    virtual void v44(); virtual void inline_ov004_021555b0_29(); virtual void inline_ov004_021555b0_30(); virtual void inline_ov004_021555b0_31();
    virtual void v48(); virtual void inline_ov004_021555b0_33(); virtual void v50(); virtual void inline_ov004_021555b0_35();
    virtual void inline_ov004_021555b0_36(); virtual void inline_ov004_021555b0_37(); virtual void v54(); virtual void inline_ov004_021555b0_39();
    virtual void inline_ov004_021555b0_40(); virtual void inline_ov004_021555b0_41(); virtual void v58();
    virtual int inline_ov004_021555b0_43();
};

// USA: func_ov004_021555b0
extern "C" ARM int func_ov004_021555b0(void* a) {
    short b, c, d;
    func_ov004_0215513c(a, &b, &c, &d);

    void* base = func_ov011_021849c8(a);
    void* node = func_ov023_021f6880(base, 0x39);
    if (!node) return 0;
#if defined(jpn)
    if (func_ov023_021f6f10(node) != 0x12) return 0;
#else
    if (func_ov024_021f6f10(node) != 0x12) return 0;
#endif

    int var5 = ((Struct_ov004_021555b0*)node)->inline_ov004_021555b0_43();
    if (!node) return 0;

    int result = func_ov023_021e1f0c(var5, b, c, d);
    short v = (result + 15) / 16;

    if (result == 0) {
        func_ov023_021f65d4(a, 0xa, 8);
        func_ov023_021f6600(a, 3, 4);
        unsigned short i = 0x1a, j = 0;
        for (; j < 0x10; i++, j++) {
            func_ov023_021f65d4(a, i, 8);
        }
        func_ov023_021f6600(a, 0x3a, 8);
    } else {
        func_ov023_021f65d4(a, 0x3a, 8);
    }

    func_ov023_021f65b4(a, (void*)0x2c, 0, v);
    return 0;
}
