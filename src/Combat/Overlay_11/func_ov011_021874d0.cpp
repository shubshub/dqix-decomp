#include <globaldefs.h>

struct TaggedNumber02184c30;
extern "C" int func_ov011_02184c30(struct TaggedNumber02184c30* v);

extern "C" void* func_ov017_021b2164(void);
extern "C" void* func_ov011_021849c8(void*);

class Struct_ov011_021874d0 {
public:
    virtual void v00(); virtual void inline_ov011_021874d0_2(); virtual void inline_ov011_021874d0_3(); virtual void inline_ov011_021874d0_4();
    virtual void v04(); virtual void inline_ov011_021874d0_6(); virtual void inline_ov011_021874d0_7(); virtual void inline_ov011_021874d0_8();
    virtual void v08(); virtual void inline_ov011_021874d0_10(); virtual void v10(); virtual void inline_ov011_021874d0_12();
    virtual void inline_ov011_021874d0_13(); virtual void inline_ov011_021874d0_14(); virtual void v14(); virtual void inline_ov011_021874d0_16();
    virtual void inline_ov011_021874d0_17(); virtual void inline_ov011_021874d0_18(); virtual void v18(); virtual void inline_ov011_021874d0_20();
    virtual void v20(); virtual void inline_ov011_021874d0_22(); virtual void inline_ov011_021874d0_23(); virtual void inline_ov011_021874d0_24();
    virtual void v24();
    virtual void inline_ov011_021874d0_26(int a);
    virtual void inline_ov011_021874d0_27();
    virtual void inline_ov011_021874d0_28(int a);
};
extern "C" struct Struct_ov011_021874d0* func_ov023_021f6880(void*, int);

// USA: func_ov011_021874d0
extern "C" ARM int func_ov011_021874d0(struct TaggedNumber02184c30* arg0) {
    int v0 = func_ov011_02184c30(arg0);
    int v1 = func_ov011_02184c30((struct TaggedNumber02184c30*)((char*)arg0 + 8));
    int v2 = func_ov011_02184c30((struct TaggedNumber02184c30*)((char*)arg0 + 0x10));
    struct Struct_ov011_021874d0* node = func_ov023_021f6880(func_ov011_021849c8(func_ov017_021b2164()), v0);
    if (node) {
        node->inline_ov011_021874d0_26(v1);
        node->inline_ov011_021874d0_28(v2);
    }
    return 1;
}
