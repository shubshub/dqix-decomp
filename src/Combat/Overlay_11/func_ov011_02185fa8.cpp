#include <globaldefs.h>

struct TaggedNumber02184c30;
extern "C" int func_ov011_02184c30(struct TaggedNumber02184c30* v);

extern "C" void* func_ov017_021b2164(void);
extern "C" void* func_ov011_021849c8(void*);

// Real virtual call; target method at vtable index 0xc4/4 = 49.
// See func_ov011_02187cd8.cpp for why a class w/
// dummy virtuals (rather than a manual fn-ptr struct) matches mwcc's
// single-scratch pointer chase (ldr ip,[r0]; ldr ip,[ip,#0xc4]).
class Struct_ov011_02185fa8 {
public:
    virtual void v00(); virtual void inline_ov011_02185fa8_29(); virtual void inline_ov011_02185fa8_30(); virtual void inline_ov011_02185fa8_31();
    virtual void v04(); virtual void inline_ov011_02185fa8_33(); virtual void inline_ov011_02185fa8_34(); virtual void inline_ov011_02185fa8_35();
    virtual void v08(); virtual void inline_ov011_02185fa8_37(); virtual void v10(); virtual void inline_ov011_02185fa8_39();
    virtual void inline_ov011_02185fa8_40(); virtual void inline_ov011_02185fa8_41(); virtual void v14(); virtual void inline_ov011_02185fa8_43();
    virtual void inline_ov011_02185fa8_44(); virtual void inline_ov011_02185fa8_45(); virtual void v18(); virtual void inline_ov011_02185fa8_47();
    virtual void v20(); virtual void inline_ov011_02185fa8_49(); virtual void inline_ov011_02185fa8_50(); virtual void inline_ov011_02185fa8();
    virtual void v24(); virtual void inline_ov011_02185fa8_3(); virtual void inline_ov011_02185fa8_4(); virtual void inline_ov011_02185fa8_5();
    virtual void v28(); virtual void inline_ov011_02185fa8_7(); virtual void v30(); virtual void inline_ov011_02185fa8_9();
    virtual void inline_ov011_02185fa8_10(); virtual void inline_ov011_02185fa8_11(); virtual void v34(); virtual void inline_ov011_02185fa8_13();
    virtual void inline_ov011_02185fa8_14(); virtual void inline_ov011_02185fa8_15(); virtual void v38(); virtual void inline_ov011_02185fa8_17();
    virtual void v40(); virtual void inline_ov011_02185fa8_19(); virtual void inline_ov011_02185fa8_20(); virtual void inline_ov011_02185fa8_21();
    virtual void v44(); virtual void inline_ov011_02185fa8_23(); virtual void inline_ov011_02185fa8_24(); virtual void inline_ov011_02185fa8_25();
    virtual void v48();
    virtual void inline_ov011_02185fa8_27(int a, int b, int c);
};
extern "C" struct Struct_ov011_02185fa8* func_ov023_021f6880(void*, int);

// USA: func_ov011_02185fa8
extern "C" ARM int func_ov011_02185fa8(struct TaggedNumber02184c30* arg0) {
    int v0 = func_ov011_02184c30(arg0);
    int v1 = func_ov011_02184c30((struct TaggedNumber02184c30*)((char*)arg0 + 8));
    int v2 = func_ov011_02184c30((struct TaggedNumber02184c30*)((char*)arg0 + 0x10));
    int v3 = func_ov011_02184c30((struct TaggedNumber02184c30*)((char*)arg0 + 0x18));
    struct Struct_ov011_02185fa8* node = func_ov023_021f6880(func_ov011_021849c8(func_ov017_021b2164()), v0);
    if (!node) return 0;
    node->inline_ov011_02185fa8_27(v1, v2, v3);
    return 1;
}
