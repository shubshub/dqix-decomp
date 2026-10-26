#include <globaldefs.h>

struct Struct_020e3004_2;
extern "C" void func_020e303c(struct Struct_020e3004_2* s);

struct Struct_020e3544 {
    unsigned char id;
    unsigned char pad[3];
};

// USA: func_020e3544
extern "C" ARM void func_020e3544(struct Struct_020e3544 *p, int id) {
    int i;
    for (i = 0; i < 8; ) {
        if (p->id == id) {
            func_020e303c((struct Struct_020e3004_2*)p);
        }
        i++;
        p++;
    }
}
