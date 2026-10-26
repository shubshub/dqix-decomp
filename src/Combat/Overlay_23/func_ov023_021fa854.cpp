#include <globaldefs.h>

// USA: func_ov023_021fa854
extern "C" ARM void* func_ov023_021fa854(char* obj, unsigned int idx) {
    void* ptr = *(void**)(obj + 0x40);
    void* result = NULL;
    if (ptr != NULL) {
        unsigned short count = *(unsigned short*)(obj + 0x4e);
        if (idx < count) {
            result = (char*)ptr + idx * 0x28;
        }
    }
    return result;
}
