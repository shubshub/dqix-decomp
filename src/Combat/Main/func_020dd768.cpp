#include <globaldefs.h>

struct Struct_020dd768 {
    char pad0[8];
    unsigned int lo : 14;
    unsigned int kind : 2;
};

// USA: func_020dd768
extern "C" ARM int func_020dd768(struct Struct_020dd768* p) {
    int flag;
    if (p == NULL) {
        return 0;
    }
    flag = 0;
    switch (p->kind) {
    case 0:
        flag |= 4;
        break;
    case 1:
        flag |= 1;
        break;
    case 2:
        flag |= 2;
        break;
    }
    return flag;
}
