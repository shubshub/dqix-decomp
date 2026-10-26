#include <globaldefs.h>

extern "C" void func_0205facc(void*);
extern "C" void func_0206ddb8(void*);

// USA: func_02064d1c
extern "C" ARM void* func_02064d1c(void* obj) {
    func_0206ddb8(obj);
    func_0205facc(obj);
    return obj;
}
