#include <globaldefs.h>

extern "C" int func_ov000_0217f7d4(void* obj);
extern "C" void* func_ov000_02161318(void* obj, int idx);
extern "C" void func_ov000_0217fa60(void* obj);
extern "C" void func_ov000_02174c14(void* obj);
struct Struct_ov000_02170fd0;
extern "C" void func_ov000_02170fd0(struct Struct_ov000_02170fd0* obj, int b);

// USA: func_ov000_0217f78c
extern "C" ARM void func_ov000_0217f78c(void* objRaw) {
    char* obj = (char*)objRaw;
    int id = func_ov000_0217f7d4(obj);
    void* p = func_ov000_02161318(obj, id);
    if (p != NULL) {
        *(int*)(obj + 0x17c) = id;
        func_ov000_02170fd0((struct Struct_ov000_02170fd0*)p, 0);
        return;
    }
    func_ov000_0217fa60(obj);
    func_ov000_02174c14(obj);
}
