#include <globaldefs.h>

struct Struct_02070a30 {
    unsigned int count : 12;
};

// USA: func_02070af4
extern "C" ARM int func_02070af4(struct Struct_02070a30* p) {
    return p->count * 0x84;
}
