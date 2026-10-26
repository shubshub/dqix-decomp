#include <globaldefs.h>

struct Struct_02068894_2 {
    char unk[0x8];
    unsigned int pad : 24;
    unsigned int field : 2;
};

struct Struct_02068894 {
    struct Struct_02068894_2* field0;
};

// USA: func_02068894
extern "C" ARM int func_02068894(int unused, struct Struct_02068894* obj) {
    struct Struct_02068894_2* p = obj->field0;
    if (p != 0) {
        return p->field;
    }
    return 0;
}
