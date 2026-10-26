#include <globaldefs.h>

extern "C" void* func_0207d9f4(unsigned char* arr, int offset);

// USA: func_0207da30
extern "C" ARM int func_0207da30(unsigned char* arr, int id, int offset) {
    unsigned char* p = (unsigned char*)func_0207d9f4(arr, offset);
    if (p == NULL) return 0;
    if (*(unsigned short*)p != id) return 0;
    return *(signed char*)(p + offset + 8) != -1;
}
