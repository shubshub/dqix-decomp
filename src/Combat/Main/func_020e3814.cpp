#include <globaldefs.h>

struct Struct_020e3814 {
    int f0;
    unsigned char f4, unknown_5_, unknown_6_;
};
extern "C" void func_020e3840(struct Struct_020e3814* s);

// USA: func_020e3814
extern "C" ARM void func_020e3814(struct Struct_020e3814 *p) {
    int i;
    for (i = 0; i < 4; ) {
        func_020e3840(p);
        i++;
        p++;
    }
}
