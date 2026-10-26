#include <globaldefs.h>

extern "C" void func_020464a4(char* src, char* dst, int size);

// USA: func_02046558
extern "C" ARM void func_02046558(void* obj, char* src) {
    func_020464a4(src, (char*)obj + 0x46c, 0x40);
}
