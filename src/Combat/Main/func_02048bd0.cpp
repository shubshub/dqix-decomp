#include <globaldefs.h>

// USA: func_02048bd0
extern "C" ARM int func_02048bd0(unsigned char* obj) {
    int* p = *(int**)(obj + 0x13c);
    if (p != 0) {
        return (p[8] & 0x80) != 0;
    }
    return 0;
}
