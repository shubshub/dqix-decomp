#include <globaldefs.h>

struct Struct_ov011_0218563c_3 {
    char pad0[4];
    unsigned short kind;
    unsigned short field6;
    unsigned short field8;
    unsigned short fielda;
    char unknown_c_[4];
    int field10;
    char unknown_14_[0x14];
    int field28;
    unsigned char field2c;
};

extern "C" void func_ov023_021f6ed8(void*);
extern "C" int func_ov023_021fa5a0(void*, int);

// USA: func_ov023_021fa298
#if defined(jpn)
struct Struct_ov023_021f9724 {
    char pad0[4];
    unsigned short kind;
    unsigned short field6;
    unsigned short field8;
    unsigned short fielda;
    char unknown_c_[4];
    int field10;
    char unknown_14_[0x14];
    unsigned char field28;
};

extern "C" ARM int func_ov023_021f9724(struct Struct_ov023_021f9724* obj, int p1, int p2, int p3, int p4, int p5) {
    func_ov023_021f6ed8(obj);
    obj->kind = 4;
    obj->field6 = p2;
    obj->field8 = p3;
    obj->fielda = 0;
    obj->field10 = p4;
    obj->field28 = p5;
    func_ov023_021fa5a0(obj, p1);
    return 1;
}
#else
extern "C" ARM int func_ov023_021fa298(struct Struct_ov011_0218563c_3* obj, int p1, int p2, int p3, int p4, int p5, int p6) {
    func_ov023_021f6ed8(obj);
    obj->kind = 4;
    obj->field6 = p2;
    obj->field8 = p3;
    obj->fielda = 0;
    obj->field28 = p4;
    obj->field10 = p5;
    obj->field2c = p6;
    func_ov023_021fa5a0(obj, p1);
    return 1;
}
#endif
