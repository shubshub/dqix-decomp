#include <globaldefs.h>

struct Struct0209c830 {
    char pad[0xc9];
    unsigned char active;
    char pad2[4];
    unsigned short value;
};

// USA: func_0209c830
extern "C" ARM void func_0209c830(Struct0209c830* p, int value) {
    p->value = value;
    p->active = 1;
}
