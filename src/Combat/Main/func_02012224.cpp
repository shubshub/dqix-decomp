#include <globaldefs.h>

extern "C" void func_0200f3a4(void*);
extern "C" int func_020998ac(int*);

// USA: func_02012224
extern "C" ARM char* func_02012224(char* obj) {
    func_0200f3a4(obj);
    func_020998ac((int*)(obj + 0x468));
    return obj;
}
