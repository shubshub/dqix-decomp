#include <globaldefs.h>

struct Struct_0206885c_2 {
    char unk[0x8];
    unsigned int pad : 24;
    unsigned int field : 2;
};

struct Struct_0206885c {
    char unk[0x8];
    struct Struct_0206885c_2* field8;
};

// USA: func_0206885c
extern "C" ARM int func_0206885c(int unused, struct Struct_0206885c* obj) {
    struct Struct_0206885c_2* p = obj->field8;
    if (p != 0) {
        return p->field;
    }
    return 0;
}
