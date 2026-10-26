#include <globaldefs.h>
#include "Resource/Script.h"

struct Variant02030b0c;

struct Struct_02073ec4_3;
struct Struct_02073ec4_2;
extern "C" struct Struct_02073ec4_3* func_0209bd94(struct Struct_02073ec4_2* table, int key);

struct Struct_0201c1c8_3 {
    unsigned char raw[0x4c];
};

struct Struct_0209ae9c {
    struct Struct_0201c1c8_3 entries[6];
    int count;
    int unknown_1cc_;
    int unknown_1d0_;
};

struct Struct_0209ae9c_2 {
    struct Struct_0209ae9c* field0;
    struct Struct_02073ec4_2* field4;
    int field8;
};
extern struct Struct_0209ae9c_2* data_02109bac;

// USA: func_0209ae9c
extern "C" ARM int func_0209ae9c(struct Variant02030b0c* param0) {
    data_02109bac->field8 = 0;

    int handle = ((Script::Parameter*)param0)->ToInt();
    if (func_0209bd94(data_02109bac->field4, handle) == NULL) {
        return 1;
    }

    struct Struct_0209ae9c* inner = data_02109bac->field0;
    int var2 = ++inner->count;
    data_02109bac->field0->unknown_1cc_ = 0;
    data_02109bac->field0->unknown_1d0_ = 0;
    *(short*)((char*)data_02109bac->field0 + var2 * 0x4c) = (short)handle;
    data_02109bac->field8 = 1;
    return 1;
}
