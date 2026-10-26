#if defined(jpn)
#define R(j,u) (j)
#define func_ov024_021f6f10 func_ov023_021f6f10
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

extern "C" void* func_ov011_021849c8(void*);
#if defined(jpn)
#define func_ov024_021f6f10 func_ov023_021f6f10
extern "C" int func_ov024_021f6f10(void* self);
#else
extern "C" int func_ov024_021f6f10(void* self);
#endif
extern "C" int func_ov004_021537a8(void* self, int key, int arg);
extern "C" int func_ov023_021e1de8(void* obj, int value, int id, int idx);

class Struct_ov004_02154e64 {
public:
    virtual void v00(); virtual void inline_ov004_02154e64_41(); virtual void inline_ov004_02154e64_42(); virtual void inline_ov004_02154e64_43();
    virtual void v04(); virtual void inline_ov004_02154e64_45(); virtual void inline_ov004_02154e64_46(); virtual void inline_ov004_02154e64_47();
    virtual void v08(); virtual void inline_ov004_02154e64_49(); virtual void v10(); virtual void inline_ov004_02154e64_51();
    virtual void inline_ov004_02154e64_52(); virtual void inline_ov004_02154e64_53(); virtual void v14(); virtual void inline_ov004_02154e64_55();
    virtual void inline_ov004_02154e64_56(); virtual void inline_ov004_02154e64_57(); virtual void v18(); virtual void inline_ov004_02154e64_59();
    virtual void v20(); virtual void inline_ov004_02154e64(); virtual void inline_ov004_02154e64_2(); virtual void inline_ov004_02154e64_3();
    virtual void v24(); virtual void inline_ov004_02154e64_5(); virtual void inline_ov004_02154e64_6(); virtual void inline_ov004_02154e64_7();
    virtual void v28(); virtual void inline_ov004_02154e64_9(); virtual void v30(); virtual void inline_ov004_02154e64_11();
    virtual void inline_ov004_02154e64_12(); virtual void inline_ov004_02154e64_13(); virtual void v34(); virtual void inline_ov004_02154e64_15();
    virtual void inline_ov004_02154e64_16(); virtual void inline_ov004_02154e64_17(); virtual void v38(); virtual void inline_ov004_02154e64_19();
    virtual void v40(); virtual void inline_ov004_02154e64_21(); virtual void inline_ov004_02154e64_22(); virtual void inline_ov004_02154e64_23();
    virtual void v44(); virtual void inline_ov004_02154e64_25(); virtual void inline_ov004_02154e64_26(); virtual void inline_ov004_02154e64_27();
    virtual void v48(); virtual void inline_ov004_02154e64_29(); virtual void v50(); virtual void inline_ov004_02154e64_31();
    virtual void inline_ov004_02154e64_32(); virtual void inline_ov004_02154e64_33(); virtual void v54(); virtual void inline_ov004_02154e64_35();
    virtual void inline_ov004_02154e64_36(); virtual void inline_ov004_02154e64_37(); virtual void v58();
    virtual void* inline_ov004_02154e64_39();
};
extern "C" Struct_ov004_02154e64* func_ov023_021f6880(void*, int);

// USA: func_ov004_02154e64
extern "C" ARM int func_ov004_02154e64(void* a1) {
    Struct_ov004_02154e64* obj = func_ov023_021f6880(func_ov011_021849c8(a1), 0x39);
    if (!obj) return 0;
    if (func_ov024_021f6f10(obj) != 0x12) return 0;
    void* r = obj->inline_ov004_02154e64_39();
    if (!obj) return 0;
    unsigned short key = 0x1a;
    short j = 1;
    for (; j <= 7; key++, j++) {
        if (func_ov023_021e1de8(r, -1, j, -1) == 0) {
            func_ov004_021537a8(a1, key, 0);
        }
    }
    return 0;
}
