#include <globaldefs.h>

struct Struct_020688b0_2 {
    char unk[0x8];
    unsigned int pad : 24;
    unsigned int field : 2;
};

struct Struct_020688b0 {
    char unk[0x10];
    struct Struct_020688b0_2* field10;
};

// USA: func_020688b0
extern "C" ARM int func_020688b0(int unused, struct Struct_020688b0* obj) {
    struct Struct_020688b0_2* p = obj->field10;
    if (p != 0) {
        return p->field;
    }
    return 0;
}
