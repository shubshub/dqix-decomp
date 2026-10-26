#include <globaldefs.h>

#if defined(jpn)
#define func_ov023_021fc408 func_ov023_021fb700
#endif

struct Struct_ov004_0216b120 {
    char pad0[4];
    unsigned short kind;
    unsigned short field6;
    unsigned short field8;
    char unknown_a_[0x1c - 0xa];
    int field1c;
    char pad20[0x24 - 0x20];
    unsigned short field24;
    unsigned short field26;
    unsigned short field28;
    unsigned short field2a;
    unsigned short field2c;
    unsigned char unknown_2e_;
};

extern "C" void func_ov023_021f6ed8(void*);

// USA: func_ov023_021fc408
extern "C" ARM int func_ov023_021fc408(struct Struct_ov004_0216b120* obj, int unused, int b, int c, int p5, int p6, int p7, int p8, int p9, int p10) {
    func_ov023_021f6ed8(obj);
    obj->kind = 0x13;
    obj->field6 = b;
    obj->field8 = c;
    obj->field1c = 2;
    obj->field24 = p5;
    obj->field26 = p6;
    obj->field28 = p7;
    obj->field2a = p8;
    obj->field2c = p9;
    obj->unknown_2e_ = p10;
    return 1;
}
