#include <globaldefs.h>
#include "Resource/ActionDataTables.h"

#if defined(jpn)
#define REGION_OFFSET_0 0xdc
#define REGION_OFFSET_1 0x1e4
#else
#define REGION_OFFSET_0 0x9c
#define REGION_OFFSET_1 0x1a4
#endif

extern "C" void* func_02079e2c(char* p, int key);

struct Struct_ov000_02170cf8 {
    char pad[4];
    unsigned int field4 : 12;
    unsigned int unknown_5_4_ : 20;
};

// USA: func_ov000_02170cf8
extern "C" ARM void* func_ov000_02170cf8(char* obj, int val) {
    if (val == 0) {
        return 0;
    }
    ActionDataTables* data = func_020797dc();
    if (data == 0) {
        return 0;
    }
    void* result = func_02079e2c((char*)data, (short)val);
    if (result != 0) {
        return result;
    }
    struct Struct_ov000_02170cf8** arr1 = (struct Struct_ov000_02170cf8**)(obj + REGION_OFFSET_0);
    for (unsigned short i = 0; i < 0x42; i++) {
        struct Struct_ov000_02170cf8* e = arr1[i];
        if (e != 0 && e->field4 == val) {
            return e;
        }
    }
    struct Struct_ov000_02170cf8** arr2 = (struct Struct_ov000_02170cf8**)(obj + REGION_OFFSET_1);
    for (unsigned short i = 0; i < 0x93; i++) {
        struct Struct_ov000_02170cf8* e = arr2[i];
        if (e != 0 && e->field4 == val) {
            return e;
        }
    }
    return 0;
}
