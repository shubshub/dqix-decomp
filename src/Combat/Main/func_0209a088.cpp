#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct_0209a088_2 {
    unsigned int count : 12;
    unsigned int : 19;
    unsigned int flag : 1;
};

struct Struct_0209a088 {
    struct Struct_0209a088_2 field0;
    void* field4;
    void* field8;
};

// USA: func_0209a088
extern "C" ARM void func_0209a088(struct Struct_0209a088* obj, struct Struct_0209a088_2* src) {
    if (src == NULL) return;
    memcpy(&obj->field0, src, 4);
    obj->field4 = (void*)(src + 1);
    obj->field8 = (char*)src + (obj->field0.count * 0x2c + 4);
    if (obj->field0.flag) return;
    obj->field0.flag = 1;
    src->flag = 1;
}
