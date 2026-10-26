#include <globaldefs.h>

struct Struct_02068824_2 {
    char unk[0x8];
    unsigned int pad : 24;
    unsigned int field : 2;
};

struct Struct_02068824 {
    char unk[0x18];
    struct Struct_02068824_2* field18;
};

// USA: func_02068824
extern "C" ARM int func_02068824(int unused, struct Struct_02068824* obj) {
    struct Struct_02068824_2* p = obj->field18;
    if (p != 0) {
        return p->field;
    }
    return 0;
}
