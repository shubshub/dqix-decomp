#include <globaldefs.h>

extern "C" void* func_ov001_02158e0c(void*);

// USA: func_ov001_02159168
extern "C" ARM void* func_ov001_02159168(void* obj, int p1, int p2, int p3, int p4, int p5, unsigned char p6) {
    unsigned int* e = (unsigned int*)func_ov001_02158e0c(obj);
    if (e != NULL) {
        e[0] = 0xe;
        e[1] = p1;
        e[2] = p2;
        e[3] = p3;
        *(int*)((char*)e + 0x1c) = p4;
        *(int*)((char*)e + 0x20) = p5;
        *(int*)((char*)e + 0x24) = p6;
    }
    return e;
}
