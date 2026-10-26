#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct_ov006_021536e0 {
    int a, b, c, d, e;
    unsigned char f[6];
    unsigned char g[3];
    int h;
    short i;
};

// USA: func_ov006_021536e0
extern "C" ARM void func_ov006_021536e0(struct Struct_ov006_021536e0* p) {
    p->a = 0;
    p->b = 0;
    p->c = 0;
    p->d = 0;
    p->e = 0;
    memset(p->f, -1, 6);
    memset(p->g, -1, 3);
    p->h = 0;
    p->i = 0;
}
