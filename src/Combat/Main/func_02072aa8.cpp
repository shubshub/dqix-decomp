#include <globaldefs.h>

struct Struct_02072aa8 {
    int field0;
    short field4;
    short field6;
};

// USA: func_02072aa8
extern "C" ARM int func_02072aa8(struct Struct_02072aa8* obj, int ptr, int value) {
    short v = value;
    obj->field0 = ptr;
    obj->field6 = v;
    obj->field4 = v;
    return 1;
}
