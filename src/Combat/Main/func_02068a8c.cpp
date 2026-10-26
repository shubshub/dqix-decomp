#include <globaldefs.h>

extern "C" int func_02067fec(void*, int);

// USA: func_02068a8c
extern "C" ARM int func_02068a8c(int a, unsigned char* obj) {
    unsigned int* p = *(unsigned int**)(obj + 0x1c);
    if (p != NULL) {
        return func_02067fec(p, p[0]) == 0;
    }
    return 0;
}
