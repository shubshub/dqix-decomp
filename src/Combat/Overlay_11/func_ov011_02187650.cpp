#if defined(jpn)
#define R(j,u) (j)
#define func_ov024_021f6f10 func_ov023_021f6f10
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

struct TaggedNumber02184c30 {
    int type;
    union { int i; float f; } value;
};
extern "C" int func_ov011_02184c30(struct TaggedNumber02184c30* v);

extern "C" void* func_ov017_021b2164(void);
extern "C" void* func_ov011_021849c8(void* p);
extern "C" void* func_ov023_021f6880(void* list, int value);
#if defined(jpn)
#define func_ov024_021f6f10 func_ov023_021f6f10
extern "C" int func_ov024_021f6f10(void* self);
#else
extern "C" int func_ov024_021f6f10(void* self);
#endif

class Struct_ov011_02187650 {
public:
    virtual void v00(); virtual void inline_ov011_02187650_17(); virtual void inline_ov011_02187650_18(); virtual void inline_ov011_02187650_19();
    virtual void v04(); virtual void inline_ov011_02187650_21(); virtual void inline_ov011_02187650_22(); virtual void inline_ov011_02187650_23();
    virtual void v08(); virtual void inline_ov011_02187650_25(); virtual void v10(); virtual void inline_ov011_02187650_27();
    virtual void inline_ov011_02187650_28(); virtual void inline_ov011_02187650_29(); virtual void v14(); virtual void inline_ov011_02187650();
    virtual void inline_ov011_02187650_2(); virtual void inline_ov011_02187650_3(); virtual void v18(); virtual void inline_ov011_02187650_5();
    virtual void v20(); virtual void inline_ov011_02187650_7(); virtual void inline_ov011_02187650_8(); virtual void inline_ov011_02187650_9();
    virtual void v24(); virtual void inline_ov011_02187650_11(); virtual void inline_ov011_02187650_12(); virtual void inline_ov011_02187650_13();
    virtual void v28();
    virtual void inline_ov011_02187650_15(int a);
};

// USA: func_ov011_02187650
extern "C" ARM int func_ov011_02187650(struct TaggedNumber02184c30* a) {
    int val = func_ov011_02184c30(a);
    int val2 = func_ov011_02184c30((struct TaggedNumber02184c30*)((char*)a + 8));
    Struct_ov011_02187650* node = (Struct_ov011_02187650*)func_ov023_021f6880(func_ov011_021849c8(func_ov017_021b2164()), val);
    if (!node) return 0;
    if (func_ov024_021f6f10(node) != 7) return 0;
    node->inline_ov011_02187650_15(val2);
    return 1;
}
