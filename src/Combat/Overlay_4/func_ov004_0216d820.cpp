#include <globaldefs.h>

extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void*, int);
extern "C" void* func_ov004_0216b1c4(void* a, int id);
extern "C" void func_ov004_0216afb0(void* obj, int a, int b, int c, int d, int e, int f, int g, int h);
extern "C" int func_ov004_0216b2c8(void* obj, int id, int a, int b);
extern "C" int func_ov004_0216b7bc(void* obj, int a, int b, int c);

struct Struct_ov004_02171034_5 {
#if defined(jpn)
    unsigned char pad0[0x10];
#else
    unsigned char pad0[0xc];
#endif
    int unknown_c_;
};
extern struct Struct_ov004_02171034_5 data_ov004_02171034;

class Struct_ov004_0216d820 {
public:
    virtual void v00(); virtual void inline_ov004_0216d820_19(); virtual void inline_ov004_0216d820_20(); virtual void inline_ov004_0216d820_21();
    virtual void v04(); virtual void inline_ov004_0216d820_23(); virtual void inline_ov004_0216d820_24(); virtual void inline_ov004_0216d820_25();
    virtual void v08(); virtual void inline_ov004_0216d820_27(); virtual void v10(); virtual void inline_ov004_0216d820_29();
    virtual void inline_ov004_0216d820_30(); virtual void inline_ov004_0216d820_31(); virtual void v14(); virtual void inline_ov004_0216d820();
    virtual void inline_ov004_0216d820_2(); virtual void inline_ov004_0216d820_3(int n); virtual void v18(); virtual void inline_ov004_0216d820_5();
    virtual void v20(); virtual void inline_ov004_0216d820_7(); virtual void inline_ov004_0216d820_8(); virtual void inline_ov004_0216d820_9();
    virtual void v24(); virtual void inline_ov004_0216d820_11(); virtual void inline_ov004_0216d820_12(); virtual void inline_ov004_0216d820_13();
    virtual void v28(); virtual void inline_ov004_0216d820_15(); virtual void v30(); virtual void inline_ov004_0216d820_17(int n);
};

// USA: func_ov004_0216d820
extern "C" ARM int func_ov004_0216d820(void* a) {
    void* node = func_ov023_021f6880(func_ov011_021849c8(a), 1);
    if (node) {
        *((unsigned char*)node + 0xc) |= 0x8;
    }
    func_ov004_0216b1c4(a, 0x12c);

    int v0c = data_ov004_02171034.unknown_c_;

    func_ov004_0216afb0(a, 0x37, 2, 0xd4, 0x3b, 0xa, 0xa, 0xc, 1);
    func_ov004_0216b2c8(a, 0x12c, 0x37, 0);

    Struct_ov004_0216d820* node2 = (Struct_ov004_0216d820*)func_ov023_021f6880(func_ov011_021849c8(a), 0x37);
    if (node2) {
        node2->inline_ov004_0216d820_3(0x10);
        node2->inline_ov004_0216d820_17(0x10);
    }

    func_ov004_0216b7bc(a, 0xd4, v0c, 0);
    return 0;
}
