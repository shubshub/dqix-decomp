#include <globaldefs.h>

struct Struct_0205ce28 {
    char unk[0x8];
    int field8;
};

struct Struct_0205ce28_2 {
    char unk[0x440];
    struct Struct_0205ce28* unknown_440_;
};

// USA: func_0205ce28
extern "C" ARM int func_0205ce28(struct Struct_0205ce28_2* obj) {
    struct Struct_0205ce28* p = obj->unknown_440_;
    if (p != 0) {
        return p->field8 == 0;
    }
    return 1;
}
