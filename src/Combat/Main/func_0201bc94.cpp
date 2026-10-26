#include <globaldefs.h>

struct Struct_0201bc94_2 {
    unsigned char unknown_0_0_ : 4;
    unsigned char flag4 : 1;
    unsigned char unknown_0_5_ : 3;
};

struct Struct0201bc94 {
    unsigned short field0;
    unsigned short field2;
    unsigned short field4;
    unsigned short field6;
    Struct_0201bc94_2* field8;
};

// USA: func_0201bc94
extern "C" ARM int func_0201bc94(Struct0201bc94* obj) {
    int result = 1;
    if (obj->field0 == 0x2710) {
        result = 0;
    }
    else if (obj->field0 == 0x2774) {
        result = 0;
    }
    else if (obj->field4 == 0x170c) {
        result = 0;
    }
    else if (obj->field4 == 0x1901) {
        result = 0;
    }
    else {
        Struct_0201bc94_2* inner = (Struct_0201bc94_2*)((char*)obj->field8 + 0xc);
        if (!inner->flag4)
            result = 0;
    }
    return result;
}
