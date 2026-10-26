#include <globaldefs.h>

struct Struct_ov011_02186548 {
    char pad0[4];
    unsigned short kind;
    unsigned short field6;
    unsigned short field8;
    unsigned short fielda;
    char unknown_c_[4];
    int field10;
    char unknown_14_[0xc];
    int field20;
    int field24;
    unsigned char field28;
    unsigned char unknown_29_;
};

struct Struct_ov011_02186548_2 { int a, b; };
struct Struct_ov011_02186548_3 { unsigned char a, b; };

extern "C" void func_ov023_021f6ed8(void*);

// USA: func_ov023_021fd1e0
extern "C" ARM int func_ov023_021fd1e0(struct Struct_ov011_02186548* obj, int unused, int p2, int p3, struct Struct_ov011_02186548_2* p4, struct Struct_ov011_02186548_3* p5) {
    func_ov023_021f6ed8(obj);
    obj->kind = 0xd;
    obj->field6 = p2;
    obj->field8 = p3;
    obj->field20 = p4->a;
    obj->field24 = p4->b;
    obj->field28 = p5->a;
    obj->unknown_29_ = p5->b;
    return 1;
}
