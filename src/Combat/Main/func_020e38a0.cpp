#include <globaldefs.h>

struct Struct_020e3814 {
    int f0;
    unsigned char f4, unknown_5_, unknown_6_;
};
extern "C" void func_020e3840(struct Struct_020e3814* s);

// USA: func_020e38a0
extern "C" ARM struct Struct_020e3814* func_020e38a0(struct Struct_020e3814 *p) {
    int i;
    for (i = 0; i < 4; ) {
        if (p->f4 == 0) {
            func_020e3840(p);
            return p;
        }
        i++;
        p++;
    }
    return NULL;
}
