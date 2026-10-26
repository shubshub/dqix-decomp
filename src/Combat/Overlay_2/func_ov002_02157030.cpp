#include <globaldefs.h>

struct Struct_0205d81c;
extern "C" unsigned int func_0205d81c(Struct_0205d81c*, int);

#if defined(jpn)
#define LIST_02157030 0xe20
#else
#define LIST_02157030 0xec8
#endif

// USA: func_ov002_02157030
extern "C" ARM void func_ov002_02157030(unsigned int self, unsigned int id, short* x, short* y, short* w, short* h) {
    char* e = (char*)func_0205d81c((Struct_0205d81c*)(self + LIST_02157030), id);
    if (e == 0) {
        return;
    }
    *x = *(short*)(e + 0xac);
    *y = *(short*)(e + 0xae);
    *w = *(short*)(e + 0xa8);
    *h = *(short*)(e + 0xaa);
}
