#include <globaldefs.h>


extern "C" void func_ov004_02153978(void* self, short* a, short* b, short* c);
extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void*, int);
#if defined(jpn)
extern "C" int func_ov023_021f6f10(void* self);
#else
extern "C" int func_ov024_021f6f10(void* self);
#endif
extern "C" int func_ov023_021e1de8(void* obj, int value, int id, int idx);
extern "C" void func_ov023_021f65d4(void* obj, int id, int mask);
extern "C" void func_ov023_021f6600(void* obj, int id, int mask);

class Struct_ov004_021540a4 {
public:
    virtual void v00(); virtual void inline_ov004_021540a4_42(); virtual void inline_ov004_021540a4_43(); virtual void inline_ov004_021540a4_44();
    virtual void v04(); virtual void inline_ov004_021540a4_46(); virtual void inline_ov004_021540a4_47(); virtual void inline_ov004_021540a4_48();
    virtual void v08(); virtual void inline_ov004_021540a4_50(); virtual void v10(); virtual void inline_ov004_021540a4_52();
    virtual void inline_ov004_021540a4_53(); virtual void inline_ov004_021540a4_54(); virtual void v14(); virtual void inline_ov004_021540a4_56();
    virtual void inline_ov004_021540a4_57(); virtual void inline_ov004_021540a4_58(); virtual void v18(); virtual void inline_ov004_021540a4_60();
    virtual void v20(); virtual void inline_ov004_021540a4_2(); virtual void inline_ov004_021540a4_3(); virtual void inline_ov004_021540a4_4();
    virtual void v24(); virtual void inline_ov004_021540a4_6(); virtual void inline_ov004_021540a4_7(); virtual void inline_ov004_021540a4_8();
    virtual void v28(); virtual void inline_ov004_021540a4_10(); virtual void v30(); virtual void inline_ov004_021540a4_12();
    virtual void inline_ov004_021540a4_13(); virtual void inline_ov004_021540a4_14(); virtual void v34(); virtual void inline_ov004_021540a4_16();
    virtual void inline_ov004_021540a4_17(); virtual void inline_ov004_021540a4_18(); virtual void v38(); virtual void inline_ov004_021540a4_20();
    virtual void v40(); virtual void inline_ov004_021540a4_22(); virtual void inline_ov004_021540a4_23(); virtual void inline_ov004_021540a4_24();
    virtual void v44(); virtual void inline_ov004_021540a4_26(); virtual void inline_ov004_021540a4_27(); virtual void inline_ov004_021540a4_28();
    virtual void v48(); virtual void inline_ov004_021540a4_30(); virtual void v50(); virtual void inline_ov004_021540a4_32();
    virtual void inline_ov004_021540a4_33(); virtual void inline_ov004_021540a4_34(); virtual void v54(); virtual void inline_ov004_021540a4_36();
    virtual void inline_ov004_021540a4_37(); virtual void inline_ov004_021540a4_38(); virtual void v58();
    virtual void* inline_ov004_021540a4_40();
};

// USA: func_ov004_021540a4
extern "C" ARM int func_ov004_021540a4(void* a) {
    short e0, e1, e2;
    func_ov004_02153978(a, &e0, &e1, &e2);

    void* var3 = func_ov011_021849c8(a);
    void* n = func_ov023_021f6880(var3, 0x39);
    if (!n) return 0;
#if defined(jpn)
    if (func_ov023_021f6f10(n) != 0x12) return 0;
#else
    if (func_ov024_021f6f10(n) != 0x12) return 0;
#endif

    void* result = ((Struct_ov004_021540a4*)n)->inline_ov004_021540a4_40();
    if (!n) return 0;

    int ret = func_ov023_021e1de8(result, e0, e1, e2);
    short var7 = (short)((ret + 15) / 16);

    if (ret == 0) {
        func_ov023_021f65d4(a, 0xa, 8);
        func_ov023_021f6600(a, 3, 4);
        for (unsigned short id = 0x1a, i = 0; i < 0x10; id++, i++) {
            void* b2 = func_ov011_021849c8(a);
            void* node = func_ov023_021f6880(b2, id);
            if (node) *((unsigned char*)node + 0xc) |= 8;
        }
        void* b3 = func_ov011_021849c8(a);
        void* node2 = func_ov023_021f6880(b3, 0x3a);
        if (node2) *((unsigned char*)node2 + 0xc) &= ~8;
    } else {
        func_ov023_021f6600(a, 0xa, 8);
        func_ov023_021f65d4(a, 0x3a, 8);
    }

    void* var14 = func_ov011_021849c8(a);
    void* n2 = func_ov023_021f6880(var14, 0x2c);
    if (!n2) return 0;
#if defined(jpn)
    if (func_ov023_021f6f10(n2) != 7) return 0;
#else
    if (func_ov024_021f6f10(n2) != 7) return 0;
#endif
    *(short*)((char*)n2 + 0x5c) = 0;
    *(short*)((char*)n2 + 0x5e) = var7;
    return 0;
}
