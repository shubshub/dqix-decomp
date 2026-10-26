#include <globaldefs.h>

struct TaggedNumber02184c30;
extern "C" int func_ov011_02184c30(struct TaggedNumber02184c30* v);

extern "C" void* func_ov017_021b2164(void);
extern "C" void* func_ov011_021849c8(void*);

class Struct_ov011_02187c6c {
public:
    virtual void v00(); virtual void inline_ov011_02187c6c_7(); virtual void inline_ov011_02187c6c_8(); virtual void inline_ov011_02187c6c_9();
    virtual void v04(); virtual void inline_ov011_02187c6c_11(); virtual void inline_ov011_02187c6c_12(); virtual void inline_ov011_02187c6c_13();
    virtual void v08(); virtual void inline_ov011_02187c6c_15(); virtual void v10(); virtual void inline_ov011_02187c6c_17();
    virtual void inline_ov011_02187c6c_18(); virtual void inline_ov011_02187c6c_19(); virtual void v14(); virtual void inline_ov011_02187c6c_21();
    virtual void inline_ov011_02187c6c_22(); virtual void inline_ov011_02187c6c_23(); virtual void v18(); virtual void inline_ov011_02187c6c_25();
    virtual void v20(); virtual void inline_ov011_02187c6c_27(); virtual void inline_ov011_02187c6c_28(); virtual void inline_ov011_02187c6c_29();
    virtual void v24(); virtual void inline_ov011_02187c6c_31(); virtual void inline_ov011_02187c6c_32(); virtual void inline_ov011_02187c6c_33();
    virtual void v28(); virtual void inline_ov011_02187c6c_35(); virtual void v30(); virtual void inline_ov011_02187c6c_37();
    virtual void inline_ov011_02187c6c_38(); virtual void inline_ov011_02187c6c_39(); virtual void v34(); virtual void inline_ov011_02187c6c();
    virtual void inline_ov011_02187c6c_2();
    virtual void inline_ov011_02187c6c_3(int a);
    virtual void v38();
    virtual void inline_ov011_02187c6c_5(int a);
};
extern "C" struct Struct_ov011_02187c6c* func_ov023_021f6880(void*, int);

// USA: func_ov011_02187c6c
extern "C" ARM int func_ov011_02187c6c(struct TaggedNumber02184c30* arg0) {
    int v0 = func_ov011_02184c30(arg0);
    int v1 = func_ov011_02184c30((struct TaggedNumber02184c30*)((char*)arg0 + 8));
    int v2 = func_ov011_02184c30((struct TaggedNumber02184c30*)((char*)arg0 + 0x10));
    struct Struct_ov011_02187c6c* node = func_ov023_021f6880(func_ov011_021849c8(func_ov017_021b2164()), v0);
    if (node) {
        node->inline_ov011_02187c6c_3(v1);
        node->inline_ov011_02187c6c_5(v2);
    }
    return 1;
}
