#include <globaldefs.h>

struct Struct_ov023_021f64a8 {
    virtual void inline_ov023_021f64a8_41();
    virtual void inline_ov023_021f64a8_52();
    virtual void inline_ov023_021f64a8_5();
    virtual void inline_ov023_021f64a8_16();
    virtual void inline_ov023_021f64a8_22();
    virtual void inline_ov023_021f64a8_23();
    virtual void inline_ov023_021f64a8_24();
    virtual void inline_ov023_021f64a8_25();
    virtual void inline_ov023_021f64a8_26();
    virtual void inline_ov023_021f64a8_27();
    virtual void inline_ov023_021f64a8_28();
    virtual void inline_ov023_021f64a8_29();
    virtual void inline_ov023_021f64a8_30();
    virtual void inline_ov023_021f64a8_31();
    virtual void inline_ov023_021f64a8_32();
    virtual void inline_ov023_021f64a8_33();
    virtual void inline_ov023_021f64a8_34();
    virtual void inline_ov023_021f64a8_35();
    virtual void inline_ov023_021f64a8_36();
    virtual void inline_ov023_021f64a8_37();
    virtual void inline_ov023_021f64a8_38();
    virtual void inline_ov023_021f64a8_39();
    virtual void inline_ov023_021f64a8_40();
    virtual void inline_ov023_021f64a8_42();
    virtual void inline_ov023_021f64a8_43();
    virtual void inline_ov023_021f64a8_44();
    virtual void inline_ov023_021f64a8_45();
    virtual void inline_ov023_021f64a8_46();
    virtual void inline_ov023_021f64a8_47();
    virtual void inline_ov023_021f64a8_48();
    virtual void inline_ov023_021f64a8_49();
    virtual void inline_ov023_021f64a8_50();
    virtual void inline_ov023_021f64a8_51();
    virtual void inline_ov023_021f64a8_53();
    virtual void inline_ov023_021f64a8_54();
    virtual void inline_ov023_021f64a8_55();
    virtual void inline_ov023_021f64a8_56();
    virtual void inline_ov023_021f64a8_57();
    virtual void inline_ov023_021f64a8();
    virtual void inline_ov023_021f64a8_2();
    virtual void inline_ov023_021f64a8_3();
    virtual void inline_ov023_021f64a8_4();
    virtual void inline_ov023_021f64a8_6();
    virtual void inline_ov023_021f64a8_7();
    virtual void inline_ov023_021f64a8_8();
    virtual void inline_ov023_021f64a8_9();
    virtual void inline_ov023_021f64a8_10();
    virtual void inline_ov023_021f64a8_11();
    virtual void inline_ov023_021f64a8_12();
    virtual void inline_ov023_021f64a8_13();
    virtual void inline_ov023_021f64a8_14();
    virtual void inline_ov023_021f64a8_15();
    virtual void inline_ov023_021f64a8_17();
    virtual void inline_ov023_021f64a8_18();
    virtual void inline_ov023_021f64a8_19(void* arg);
    virtual void inline_ov023_021f64a8_20();
    virtual void inline_ov023_021f64a8_21(void* arg);
};

extern "C" void* func_ov011_021849c8(void*);
extern "C" struct Struct_ov023_021f64a8* func_ov023_021f6880(void*, int);
extern "C" int func_ov023_021f6f10(void);

// USA: func_ov023_021f64a8
extern "C" ARM void func_ov023_021f64a8(void* obj, int id, void* arg2, void* arg3) {
    void* sub = func_ov011_021849c8(obj);
    struct Struct_ov023_021f64a8* node = func_ov023_021f6880(sub, id);
    if (!node) return;
    int state = func_ov023_021f6f10();
    if (state != 0xf) return;
    node->inline_ov023_021f64a8_21(arg2);
    node->inline_ov023_021f64a8_19(arg3);
}
