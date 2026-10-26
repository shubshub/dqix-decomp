#include <globaldefs.h>

extern "C" void* func_ov001_02158e0c(void*);

// USA: func_ov001_0215913c
extern "C" ARM void* func_ov001_0215913c(void* obj, int p1, int p2, int p3) {
    unsigned int* e = (unsigned int*)func_ov001_02158e0c(obj);
    if (e != NULL) {
        e[0] = 0xd;
        e[1] = p1;
        e[2] = p2;
        e[3] = p3;
    }
    return e;
}
