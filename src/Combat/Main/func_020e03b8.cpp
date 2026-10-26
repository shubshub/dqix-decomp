#include <globaldefs.h>

struct Struct_020e03b8 {
    unsigned int a : 12;
    unsigned int b : 19;
    unsigned int c : 1;
};

// USA: func_020e03b8
extern "C" ARM int func_020e03b8(int unused, struct Struct_020e03b8* obj, int val) {
    unsigned int t;
    if (obj == NULL || val == 0) {
        return 0;
    }
    t = obj->b + ((obj->a << 3) + 4);
    return t == (unsigned int)val;
}
