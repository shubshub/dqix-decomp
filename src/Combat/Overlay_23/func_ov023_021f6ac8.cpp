#include <globaldefs.h>
#include "Input/Input.h"

extern "C" void* func_ov023_021f6880(void** list, int value);
extern "C" void func_ov011_021848a0(void* obj, int val);
extern "C" void func_ov011_02184a40(void* a, int b);

struct Struct_ov023_021f6ac8 {
    unsigned char count;
    char pad1;
    unsigned short unknown_2_[8];
    short f12;
    short f14;
};

struct Struct_ov023_021f6ac8_2 {
    char pad0[0x30];
    Struct_ov023_021f6ac8 array[3];
};

class Struct_ov023_021f6ac8_3 {
public:
    virtual void v00(); virtual void inline_ov023_021f6ac8_40(); virtual void inline_ov023_021f6ac8_41(); virtual void inline_ov023_021f6ac8_42();
    virtual void v04(); virtual void inline_ov023_021f6ac8_44(); virtual void inline_ov023_021f6ac8_45(); virtual void inline_ov023_021f6ac8_46();
    virtual void v08(); virtual void inline_ov023_021f6ac8_48(); virtual void v10(); virtual void inline_ov023_021f6ac8_50();
    virtual void inline_ov023_021f6ac8_51(); virtual void inline_ov023_021f6ac8_52(); virtual void v14(); virtual void inline_ov023_021f6ac8_54();
    virtual void inline_ov023_021f6ac8_55(); virtual void inline_ov023_021f6ac8_56(); virtual void v18(); virtual void inline_ov023_021f6ac8_58();
    virtual void v20(); virtual void inline_ov023_021f6ac8_60(); virtual void inline_ov023_021f6ac8_61(); virtual void inline_ov023_021f6ac8_62();
    virtual void v24(); virtual void inline_ov023_021f6ac8(); virtual void inline_ov023_021f6ac8_2(); virtual void inline_ov023_021f6ac8_3();
    virtual void v28(); virtual void inline_ov023_021f6ac8_5(); virtual void v30(); virtual void inline_ov023_021f6ac8_7();
    virtual void inline_ov023_021f6ac8_8(); virtual void inline_ov023_021f6ac8_9(); virtual void v34(); virtual void inline_ov023_021f6ac8_11();
    virtual void inline_ov023_021f6ac8_12(); virtual void inline_ov023_021f6ac8_13(); virtual void v38(); virtual void inline_ov023_021f6ac8_15();
    virtual void v40(); virtual void inline_ov023_021f6ac8_17(); virtual void inline_ov023_021f6ac8_18(); virtual void inline_ov023_021f6ac8_19();
    virtual void v44(); virtual void inline_ov023_021f6ac8_21(); virtual void inline_ov023_021f6ac8_22(); virtual void inline_ov023_021f6ac8_23();
    virtual void v48(); virtual void inline_ov023_021f6ac8_25(); virtual void v50(); virtual void inline_ov023_021f6ac8_27();
    virtual void inline_ov023_021f6ac8_28(); virtual void inline_ov023_021f6ac8_29(); virtual void v54(); virtual void inline_ov023_021f6ac8_31();
    virtual void inline_ov023_021f6ac8_32(); virtual void inline_ov023_021f6ac8_33(); virtual void v58(); virtual void inline_ov023_021f6ac8_35();
#if defined(jpn)
    virtual void v60();
#else
    virtual void v60(); virtual void inline_ov023_021f6ac8_37();
#endif
    virtual int inline_ov023_021f6ac8_38();
};

// USA: func_ov023_021f6ac8
extern "C" ARM int func_ov023_021f6ac8(void* obj, void* arg1) {
    if (g_touchInput.pressed_ != 0) {
        struct Struct_ov023_021f6ac8_2* o = (struct Struct_ov023_021f6ac8_2*)obj;
        int j;
        for (j = 0; j < 3; j++) {
            struct Struct_ov023_021f6ac8* elem = &o->array[j];
            if (elem->count == 0) continue;

            int found = 0;
            int k;
            for (k = 0; k < elem->count && !found; k++) {
                void* node = func_ov023_021f6880((void**)obj, elem->unknown_2_[k]);
                if (node != 0) {
                    Struct_ov023_021f6ac8_3* v = (Struct_ov023_021f6ac8_3*)node;
                    if (v->inline_ov023_021f6ac8_38() != 0) {
                        found = 1;
                    }
                }
            }

            if (found) continue;

            if (elem->f12 > 0) func_ov011_021848a0(arg1, elem->f12);
            if (elem->f14 > 0) func_ov011_02184a40(arg1, elem->f14);
            return 1;
        }
    }
    return 0;
}
