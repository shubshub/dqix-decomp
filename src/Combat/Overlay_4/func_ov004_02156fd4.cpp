#include <globaldefs.h>

extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void*, int);
#if defined(jpn)
#define func_ov024_021f6f10 func_ov023_021f6f10
extern "C" int func_ov023_021f6f10(void* self);
#else
extern "C" int func_ov024_021f6f10(void* self);
#endif

class Struct_ov004_02156fd4 {
public:
    virtual void v00(); virtual void inline_ov004_02156fd4_28(); virtual void inline_ov004_02156fd4_29(); virtual void inline_ov004_02156fd4_30(); virtual void v04(); virtual void inline_ov004_02156fd4_32(); virtual void inline_ov004_02156fd4_33(); virtual void inline_ov004_02156fd4_34(); virtual void v08(); virtual void inline_ov004_02156fd4_36(); virtual void v10(); virtual void inline_ov004_02156fd4_38(); virtual void inline_ov004_02156fd4_39(); virtual void inline_ov004_02156fd4_40(); virtual void v14(); virtual void inline_ov004_02156fd4_42(); virtual void inline_ov004_02156fd4_43(); virtual void inline_ov004_02156fd4_44(); virtual void v18(); virtual void inline_ov004_02156fd4_46(); virtual void v20(); virtual void inline_ov004_02156fd4_48(); virtual void inline_ov004_02156fd4_49(); virtual void inline_ov004_02156fd4_50(); virtual void v24(); virtual void inline_ov004_02156fd4_52(); virtual void inline_ov004_02156fd4_53(); virtual void inline_ov004_02156fd4_54(); virtual void v28(); virtual void inline_ov004_02156fd4_56(); virtual void v30(); virtual void inline_ov004_02156fd4_58(); virtual void inline_ov004_02156fd4_59(); virtual void inline_ov004_02156fd4(); virtual void v34(); virtual void inline_ov004_02156fd4_3(); virtual void inline_ov004_02156fd4_4(); virtual void inline_ov004_02156fd4_5(); virtual void v38(); virtual void inline_ov004_02156fd4_7(); virtual void v40(); virtual void inline_ov004_02156fd4_9(); virtual void inline_ov004_02156fd4_10(); virtual void inline_ov004_02156fd4_11(); virtual void v44(); virtual void inline_ov004_02156fd4_13(); virtual void inline_ov004_02156fd4_14(); virtual void inline_ov004_02156fd4_15(); virtual void v48(); virtual void inline_ov004_02156fd4_17(); virtual void v50(); virtual void inline_ov004_02156fd4_19(); virtual void inline_ov004_02156fd4_20(); virtual void inline_ov004_02156fd4_21(); virtual void v54(); virtual void inline_ov004_02156fd4_23(); virtual void inline_ov004_02156fd4_24(); virtual void inline_ov004_02156fd4_25();
    virtual int inline_ov004_02156fd4_26();
};

// USA: func_ov004_02156fd4
extern "C" ARM int func_ov004_02156fd4(void* a, int key) {
    Struct_ov004_02156fd4* node = (Struct_ov004_02156fd4*)func_ov023_021f6880(func_ov011_021849c8(a), key);
    if (!node) goto ret0;
    if (func_ov024_021f6f10(node) != 0x11) goto ret0;
    return node->inline_ov004_02156fd4_26();
ret0:
    return 0;
}
