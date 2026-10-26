#include <globaldefs.h>

struct Struct_020a0840 {
    char pad[0x44];
    unsigned int value;
};

// USA: func_020a0840
extern "C" ARM void func_020a0840(struct Struct_020a0840* p, unsigned int amount) {
    unsigned int old = p->value;
    unsigned int sum = amount + old;
    if (sum < old) {
        sum = 0xffffffff;
    }
    p->value = sum;
}
