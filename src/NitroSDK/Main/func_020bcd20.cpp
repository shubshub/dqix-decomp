#include <globaldefs.h>

extern "C" void func_020bcd30(void* obj, int flag);

// USA: func_020bcd20
extern "C" ARM void func_020bcd20(void* obj) {
    func_020bcd30(obj, 1);
}
