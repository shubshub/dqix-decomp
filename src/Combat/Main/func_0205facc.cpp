#include <globaldefs.h>

extern "C" void func_0206ddb8(void*);

// USA: func_0205facc
extern "C" ARM void func_0205facc(void* obj) {
    func_0206ddb8(obj);
    *(int*)((char*)obj + 0x480) = 0;
    *(int*)((char*)obj + 0x47c) = 0;
    *(int*)((char*)obj + 0x494) = 0;
    *(int*)((char*)obj + 0x498) = 0;
    *(char*)((char*)obj + 0x492) = 0;
}
