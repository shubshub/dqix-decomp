#include <globaldefs.h>

struct Struct_02053dfc_2 {
    char unk[0x8];
    int field8;
};

struct Struct_02053dfc {
#if defined(jpn)
    char unk[0x190];
#else
    char unk[0x19c];
#endif
    struct Struct_02053dfc_2* unknown_19c_;
};

// USA: func_02053dfc
extern "C" ARM int func_02053dfc(struct Struct_02053dfc* obj) {
    struct Struct_02053dfc_2* p = obj->unknown_19c_;
    if (p != 0) {
        return p->field8;
    }
    return 0;
}
