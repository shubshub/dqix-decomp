#include <globaldefs.h>

extern "C" void func_020464a4(char* src, char* dst, int size);

// USA: func_0204653c
extern "C" ARM void func_0204653c(void* obj, char* src) {
#if defined(jpn)
    func_020464a4(src, (char*)obj + 0x2fc, 0x40);
#else
    func_020464a4(src, (char*)obj + 0x42c, 0x40);
#endif
}
