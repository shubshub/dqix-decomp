#include <globaldefs.h>

// USA: func_ov003_0215ee68
extern "C" ARM int func_ov003_0215ee68(void* obj) {
    unsigned char* p = (unsigned char*)obj;
    p[0x1e] = 1;
    p[0x20] = (p[0x20] != 0) ? 0 : 1;
    return 5;
}
