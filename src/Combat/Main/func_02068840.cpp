#include <globaldefs.h>

struct Struct_02068840_2 {
    char unk[0x8];
    unsigned int pad : 24;
    unsigned int field : 2;
};

struct Struct_02068840 {
    char unk[0x20];
    struct Struct_02068840_2* field20;
};

// USA: func_02068840
extern "C" ARM int func_02068840(int unused, struct Struct_02068840* obj) {
    struct Struct_02068840_2* p = obj->field20;
    if (p != 0) {
        return p->field;
    }
    return 0;
}
