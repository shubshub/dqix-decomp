#include <globaldefs.h>

extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void*, int);
#if defined(jpn)
extern "C" int func_ov023_021f6f10(void* self);
#else
extern "C" int func_ov024_021f6f10(void* self);
#endif
extern "C" int func_ov004_02153978(void*, short*, short*, short*);
extern "C" int func_ov023_021f9bc8(char* obj);

struct Struct_ov004_02153c74 { struct Struct_ov004_02153c74* next; int field4; };

class Struct_ov004_02153c74_2 {
public:
    virtual void v00(); virtual void inline_ov004_02153c74_38(); virtual void inline_ov004_02153c74_39(); virtual void inline_ov004_02153c74_40();
    virtual void v04(); virtual void inline_ov004_02153c74_42(); virtual void inline_ov004_02153c74_43(); virtual void inline_ov004_02153c74_44();
    virtual void v08(); virtual void inline_ov004_02153c74_46(); virtual void v10(); virtual void inline_ov004_02153c74_48();
    virtual void inline_ov004_02153c74_49(); virtual void inline_ov004_02153c74_50(); virtual void v14(); virtual void inline_ov004_02153c74_52();
    virtual void inline_ov004_02153c74_53(); virtual void inline_ov004_02153c74_54(); virtual void v18(); virtual void inline_ov004_02153c74_56();
    virtual void v20(); virtual void inline_ov004_02153c74_58(); virtual void inline_ov004_02153c74_59(); virtual void inline_ov004_02153c74_60();
    virtual void v24(); virtual void inline_ov004_02153c74_2(); virtual void inline_ov004_02153c74_3(); virtual void inline_ov004_02153c74_4();
    virtual void v28(); virtual void inline_ov004_02153c74_6(); virtual void v30(); virtual void inline_ov004_02153c74_8();
    virtual void inline_ov004_02153c74_9(); virtual void inline_ov004_02153c74_10(); virtual void v34(); virtual void inline_ov004_02153c74_12();
    virtual void inline_ov004_02153c74_13(); virtual void inline_ov004_02153c74_14(); virtual void v38(); virtual void inline_ov004_02153c74_16();
    virtual void v40(); virtual void inline_ov004_02153c74_18(); virtual void inline_ov004_02153c74_19(); virtual void inline_ov004_02153c74_20();
    virtual void v44(); virtual void inline_ov004_02153c74_22(); virtual void inline_ov004_02153c74_23(); virtual void inline_ov004_02153c74_24();
    virtual void v48(); virtual void inline_ov004_02153c74_26(); virtual void v50(); virtual void inline_ov004_02153c74_28();
    virtual void inline_ov004_02153c74_29(); virtual void inline_ov004_02153c74_30(); virtual void v54(); virtual void inline_ov004_02153c74_32();
    virtual void inline_ov004_02153c74_33(); virtual void inline_ov004_02153c74_34(); virtual void v58();
    virtual void* inline_ov004_02153c74_36();
};

// USA: func_ov004_02153c74
extern "C" ARM int func_ov004_02153c74(void* a) {
    void* var0 = func_ov011_021849c8(a);
    void* n1 = func_ov023_021f6880(var0, 0x2c);
    if (!n1) return 0;
#if defined(jpn)
    if (func_ov023_021f6f10(n1) != 7) return 0;
#else
    if (func_ov024_021f6f10(n1) != 7) return 0;
#endif

    short base = *(short*)((char*)n1 + 0x5c);
    short b, c, d;
    func_ov004_02153978(a, &b, &c, &d);
    int target = func_ov023_021f9bc8((char*)n1) + (base << 4);

    void* n2 = func_ov023_021f6880(var0, 0x2d);
    if (!n2) return 0;
#if defined(jpn)
    if (func_ov023_021f6f10(n2) != 0x11) return 0;
#else
    if (func_ov024_021f6f10(n2) != 0x11) return 0;
#endif

    void* n3 = func_ov023_021f6880(var0, 0x39);
    if (!n3) return 0;
#if defined(jpn)
    if (func_ov023_021f6f10(n3) != 0x12) return 0;
#else
    if (func_ov024_021f6f10(n3) != 0x12) return 0;
#endif

    void* result = ((Struct_ov004_02153c74_2*)n3)->inline_ov004_02153c74_36();
    if (!result) return 0;

    struct Struct_ov004_02153c74* node = *(struct Struct_ov004_02153c74**)result;
    if (!node) return 0;
    short idx = 0;
    while (node != 0) {
        if (idx == target) break;
        idx++;
        node = node->next;
    }
    return node ? node->field4 : 0;
}
