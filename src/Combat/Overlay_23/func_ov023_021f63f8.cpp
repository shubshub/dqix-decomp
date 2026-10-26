#include <globaldefs.h>

extern "C" void* func_ov011_021849c8(void*);
extern "C" int func_ov023_021f6f10(void*);

// virtual call at vtable idx 0xd8/4 = 54; class w/ virtuals mirrors the
// ROM's single-scratch vtable pointer-chase (ldr r2,[r0]; ldr r2,[r2,#0xd8]).
class Struct_ov023_021f63f8 {
public:
    virtual void v00(); virtual void inline_ov023_021f63f8_24(); virtual void inline_ov023_021f63f8_25(); virtual void inline_ov023_021f63f8_26();
    virtual void v04(); virtual void inline_ov023_021f63f8_28(); virtual void inline_ov023_021f63f8_29(); virtual void inline_ov023_021f63f8_30();
    virtual void v08(); virtual void inline_ov023_021f63f8_32(); virtual void v10(); virtual void inline_ov023_021f63f8_34();
    virtual void inline_ov023_021f63f8_35(); virtual void inline_ov023_021f63f8_36(); virtual void v14(); virtual void inline_ov023_021f63f8_38();
    virtual void inline_ov023_021f63f8_39(); virtual void inline_ov023_021f63f8_40(); virtual void v18(); virtual void inline_ov023_021f63f8_42();
    virtual void v20(); virtual void inline_ov023_021f63f8_44(); virtual void inline_ov023_021f63f8_45(); virtual void inline_ov023_021f63f8_46();
    virtual void v24(); virtual void inline_ov023_021f63f8_48(); virtual void inline_ov023_021f63f8_49(); virtual void inline_ov023_021f63f8_50();
    virtual void v28(); virtual void inline_ov023_021f63f8_52(); virtual void v30(); virtual void inline_ov023_021f63f8_54();
    virtual void inline_ov023_021f63f8_55(); virtual void inline_ov023_021f63f8(); virtual void v34(); virtual void inline_ov023_021f63f8_3();
    virtual void inline_ov023_021f63f8_4(); virtual void inline_ov023_021f63f8_5(); virtual void v38(); virtual void inline_ov023_021f63f8_7();
    virtual void v40(); virtual void inline_ov023_021f63f8_9(); virtual void inline_ov023_021f63f8_10(); virtual void inline_ov023_021f63f8_11();
    virtual void v44(); virtual void inline_ov023_021f63f8_13(); virtual void inline_ov023_021f63f8_14(); virtual void inline_ov023_021f63f8_15();
    virtual void v48(); virtual void inline_ov023_021f63f8_17(); virtual void v50(); virtual void inline_ov023_021f63f8_19();
    virtual void inline_ov023_021f63f8_20(); virtual void inline_ov023_021f63f8_21();
    virtual void inline_ov023_021f63f8_22(int arg);
    char pad4[0x1c];
    void* field20;
};
extern "C" Struct_ov023_021f63f8* func_ov023_021f6880(void*, int);

// USA: func_ov023_021f63f8
extern "C" ARM void func_ov023_021f63f8(void* ctx, int key, void* arg2, int arg) {
    Struct_ov023_021f63f8* node = func_ov023_021f6880(func_ov011_021849c8(ctx), key);
    if (node == 0) return;
    if (func_ov023_021f6f10(node) != 8) return;
    node->field20 = arg2;
    node->inline_ov023_021f63f8_22(arg);
}
