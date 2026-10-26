#include <globaldefs.h>

extern char* data_ov031_02290cfc;
extern "C" void func_ov031_022366d8(void*, char*);

// USA: func_ov031_02235e90
extern "C" ARM void func_ov031_02235e90(void* a) {
    func_ov031_022366d8(a, data_ov031_02290cfc + 0x4f0);
}
