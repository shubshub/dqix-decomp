#include <globaldefs.h>

// USA: func_ov004_0215e438
extern "C" ARM void* func_ov004_0215e438(void* obj, int idx) {
    void* arr = *(void**)((char*)obj + 0x40);
    void* result = NULL;
    if (arr != NULL) {
        unsigned short count = *(unsigned short*)((char*)obj + 0x4e);
        if ((unsigned int)idx < count) {
            result = (char*)arr + idx * 0x28;
        }
    }
    return result;
}
