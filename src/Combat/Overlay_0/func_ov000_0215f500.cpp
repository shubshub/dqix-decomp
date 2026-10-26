#include <globaldefs.h>

struct Struct_ov000_0215f500 { unsigned short v[7]; };

struct Struct_ov000_0215f500_2 {
    unsigned short field0;
    unsigned short field2;
    short field4;
    short field6;
    unsigned char field8;
    unsigned char field9;
    unsigned char fieldA;
    unsigned char fieldB;
    unsigned char fieldC;
    int field10;
    int field14;
    struct Struct_ov000_0215f500 unknown_18_;
};

// USA: func_ov000_0215f500
extern "C" ARM struct Struct_ov000_0215f500_2* func_ov000_0215f500(struct Struct_ov000_0215f500_2* dst, struct Struct_ov000_0215f500_2* src) {
    dst->field0 = src->field0;
    dst->field2 = src->field2;
    dst->field4 = src->field4;
    dst->field6 = src->field6;
    dst->field8 = src->field8;
    dst->field9 = src->field9;
    dst->fieldA = src->fieldA;
    dst->fieldB = src->fieldB;
    dst->fieldC = src->fieldC;
    dst->field10 = src->field10;
    dst->field14 = src->field14;
    dst->unknown_18_ = src->unknown_18_;
    return dst;
}
