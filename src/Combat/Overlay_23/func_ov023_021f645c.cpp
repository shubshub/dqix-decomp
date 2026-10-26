#include <globaldefs.h>

struct Struct_ov023_021f645c {
    virtual void inline_ov023_021f645c_41();
    virtual void inline_ov023_021f645c_51();
    virtual void inline_ov023_021f645c_7();
    virtual void inline_ov023_021f645c_17();
    virtual void inline_ov023_021f645c_20();
    virtual void inline_ov023_021f645c_21();
    virtual void inline_ov023_021f645c_22();
    virtual void inline_ov023_021f645c_23();
    virtual void inline_ov023_021f645c_24();
    virtual void inline_ov023_021f645c_25();
    virtual void inline_ov023_021f645c_26();
    virtual void inline_ov023_021f645c_27();
    virtual void inline_ov023_021f645c_28();
    virtual void inline_ov023_021f645c_29();
    virtual void inline_ov023_021f645c_30();
    virtual void inline_ov023_021f645c_31();
    virtual void inline_ov023_021f645c_32();
    virtual void inline_ov023_021f645c_33();
    virtual void inline_ov023_021f645c_34();
    virtual void inline_ov023_021f645c_35();
    virtual void inline_ov023_021f645c_36();
    virtual void inline_ov023_021f645c_37();
    virtual void inline_ov023_021f645c_38();
    virtual void inline_ov023_021f645c_39();
    virtual void inline_ov023_021f645c_40();
    virtual void inline_ov023_021f645c_42();
    virtual void inline_ov023_021f645c_43();
    virtual void inline_ov023_021f645c_44();
    virtual void inline_ov023_021f645c_45();
    virtual void inline_ov023_021f645c_46();
    virtual void inline_ov023_021f645c_47();
    virtual void inline_ov023_021f645c_48();
    virtual void inline_ov023_021f645c_49();
    virtual void inline_ov023_021f645c_50();
    virtual void inline_ov023_021f645c_52();
    virtual void inline_ov023_021f645c_53();
    virtual void inline_ov023_021f645c_54();
    virtual void inline_ov023_021f645c_55();
    virtual void inline_ov023_021f645c();
    virtual void inline_ov023_021f645c_2();
    virtual void inline_ov023_021f645c_3();
    virtual void inline_ov023_021f645c_4();
    virtual void inline_ov023_021f645c_5();
    virtual void inline_ov023_021f645c_6();
    virtual void inline_ov023_021f645c_8();
    virtual void inline_ov023_021f645c_9();
    virtual void inline_ov023_021f645c_10();
    virtual void inline_ov023_021f645c_11();
    virtual void inline_ov023_021f645c_12();
    virtual void inline_ov023_021f645c_13();
    virtual void inline_ov023_021f645c_14();
    virtual void inline_ov023_021f645c_15();
    virtual void inline_ov023_021f645c_16();
    virtual void inline_ov023_021f645c_18();
    virtual void inline_ov023_021f645c_19(void* arg);
    char pad[0x34];
    unsigned short field38;
};

extern "C" void* func_ov011_021849c8(void*);
extern "C" struct Struct_ov023_021f645c* func_ov023_021f6880(void*, int);
extern "C" int func_ov023_021f6f10(void);

// USA: func_ov023_021f645c
extern "C" ARM void func_ov023_021f645c(void* obj, int id, unsigned short field38, void* arg3) {
    void* sub = func_ov011_021849c8(obj);
    struct Struct_ov023_021f645c* node = func_ov023_021f6880(sub, id);
    if (!node) return;
    int state = func_ov023_021f6f10();
    if (state != 8) return;
    node->field38 = field38;
    node->inline_ov023_021f645c_19(arg3);
}
