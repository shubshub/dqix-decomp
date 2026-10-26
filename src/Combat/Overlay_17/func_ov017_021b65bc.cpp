#include <globaldefs.h>

extern "C" void func_0204715c(char* obj);

// USA: func_ov017_021b65bc
extern "C" ARM void func_ov017_021b65bc(char* obj) {
    if (*(unsigned char*)(obj + 0xfc) != 3) {
        return;
    }
    func_0204715c(obj + 0xc);
}
