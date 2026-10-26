#include <globaldefs.h>
#include "Input/Input.h"

class Struct_ov023_021f6a1c_2 {
public:
    virtual void v00(); virtual void inline_ov023_021f6a1c_6(); virtual void inline_ov023_021f6a1c_7(); virtual void inline_ov023_021f6a1c_8();
    virtual void v04(); virtual void inline_ov023_021f6a1c_10(); virtual void inline_ov023_021f6a1c_11(); virtual void inline_ov023_021f6a1c_12();
    virtual void v08(); virtual void inline_ov023_021f6a1c_14(); virtual void v10(); virtual void inline_ov023_021f6a1c_16();
    virtual void inline_ov023_021f6a1c_17(); virtual void inline_ov023_021f6a1c_18(); virtual void v14(); virtual void inline_ov023_021f6a1c_20();
    virtual void inline_ov023_021f6a1c_21(); virtual void inline_ov023_021f6a1c_22(); virtual void v18(); virtual void inline_ov023_021f6a1c_24();
    virtual void v20(); virtual void inline_ov023_021f6a1c_26(); virtual void inline_ov023_021f6a1c_27(); virtual void inline_ov023_021f6a1c_28();
    virtual void v24(); virtual void inline_ov023_021f6a1c_30(); virtual void inline_ov023_021f6a1c_31(); virtual void inline_ov023_021f6a1c_32();
    virtual void v28(); virtual void inline_ov023_021f6a1c_34(); virtual void v30(); virtual void inline_ov023_021f6a1c_36();
    virtual void inline_ov023_021f6a1c_37(); virtual void inline_ov023_021f6a1c_38(); virtual void v34(); virtual void inline_ov023_021f6a1c_40();
    virtual void inline_ov023_021f6a1c_41(); virtual void inline_ov023_021f6a1c_42(); virtual void v38(); virtual void inline_ov023_021f6a1c_44();
    virtual void v40(); virtual void inline_ov023_021f6a1c_46();
    virtual int inline_ov023_021f6a1c_47();
    virtual void inline_ov023_021f6a1c_2(); virtual void v44(); virtual void inline_ov023_021f6a1c_4();
    virtual int inline_ov023_021f6a1c_5();

    char pad4[0x18 - 4];
    Struct_ov023_021f6a1c_2* next;
};

struct Struct_ov023_021f6a1c {
    Struct_ov023_021f6a1c_2* head;
};

extern "C" void func_ov011_02184a40(void* a, int b);

// USA: func_ov023_021f6a1c
extern "C" ARM void func_ov023_021f6a1c(struct Struct_ov023_021f6a1c* obj, void* arg1) {
    if (g_touchInput.pressed_ == 0) {
        return;
    }

    int a, b;
    g_touchInput.GetTouchPoint(&a, &b);

    Struct_ov023_021f6a1c_2* node = obj->head;
    while (node != NULL) {
        if (node->inline_ov023_021f6a1c_5() != 0) {
            int v = node->inline_ov023_021f6a1c_47();
            if (v > 0) {
                v = node->inline_ov023_021f6a1c_47();
                func_ov011_02184a40(arg1, v);
                return;
            }
        }
        node = node->next;
    }
}
