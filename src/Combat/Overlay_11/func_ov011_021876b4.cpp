#include <globaldefs.h>

struct TaggedNumber02184c30;
extern "C" int func_ov011_02184c30(struct TaggedNumber02184c30* v);

extern "C" void* func_ov017_021b2164(void);
extern "C" void* func_ov011_021849c8(void*);

// Two virtual calls on the same object; target methods at vtable indices
// 0x84/4 = 33 and 0x8c/4 = 35. See func_ov011_02187cd8.cpp.
class Struct_ov011_021876b4 {
public:
    virtual void v00(); virtual void inline_ov011_021876b4_10(); virtual void inline_ov011_021876b4_11(); virtual void inline_ov011_021876b4_12();
    virtual void v04(); virtual void inline_ov011_021876b4_14(); virtual void inline_ov011_021876b4_15(); virtual void inline_ov011_021876b4_16();
    virtual void v08(); virtual void inline_ov011_021876b4_18(); virtual void v10(); virtual void inline_ov011_021876b4_20();
    virtual void inline_ov011_021876b4_21(); virtual void inline_ov011_021876b4_22(); virtual void v14(); virtual void inline_ov011_021876b4_24();
    virtual void inline_ov011_021876b4_25(); virtual void inline_ov011_021876b4_26(); virtual void v18(); virtual void inline_ov011_021876b4_28();
    virtual void v20(); virtual void inline_ov011_021876b4_30(); virtual void inline_ov011_021876b4_31(); virtual void inline_ov011_021876b4_32();
    virtual void v24(); virtual void inline_ov011_021876b4_34(); virtual void inline_ov011_021876b4_35(); virtual void inline_ov011_021876b4_36();
    virtual void v28(); virtual void inline_ov011_021876b4_2(); virtual void v30(); virtual void inline_ov011_021876b4_4();
    virtual void inline_ov011_021876b4_5();
    virtual void inline_ov011_021876b4_6(int a);
    virtual void v34();
    virtual void inline_ov011_021876b4_8(int a);
};
extern "C" struct Struct_ov011_021876b4* func_ov023_021f6880(void*, int);

// USA: func_ov011_021876b4
extern "C" ARM int func_ov011_021876b4(struct TaggedNumber02184c30* arg0) {
    int v0 = func_ov011_02184c30(arg0);
    int v1 = func_ov011_02184c30((struct TaggedNumber02184c30*)((char*)arg0 + 8));
    int v2 = func_ov011_02184c30((struct TaggedNumber02184c30*)((char*)arg0 + 0x10));
    struct Struct_ov011_021876b4* node = func_ov023_021f6880(func_ov011_021849c8(func_ov017_021b2164()), v0);
    if (node) {
        node->inline_ov011_021876b4_6(v1);
        node->inline_ov011_021876b4_8(v2);
    }
    return 1;
}
