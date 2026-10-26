#include <globaldefs.h>

struct Struct_0200dbdc {
    char pad[8];
    unsigned char* p;
};

// USA: func_0200dbdc
extern "C" ARM int func_0200dbdc(struct Struct_0200dbdc* obj) {
    unsigned char* p = obj->p;
    int v;
    if (p != 0) {
        v = *p & 0x1f;
    } else {
        v = 0;
    }
    return v & 0xff;
}
