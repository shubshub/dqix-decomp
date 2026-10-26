#include <globaldefs.h>

struct Struct_0208dc84_2 {
    short field0;
    unsigned short field2;
    int field4;
    int field8;
#if defined(jpn)
    int fieldC;
#endif
};

// USA: func_0208e000
extern "C" ARM void func_0208e000(struct Struct_0208dc84_2* dst, struct Struct_0208dc84_2* src) {
    dst->field0 = src->field0;
    dst->field2 = src->field2;
    dst->field4 = src->field4;
    dst->field8 = src->field8;
#if defined(jpn)
    dst->fieldC = src->fieldC;
#endif
}
