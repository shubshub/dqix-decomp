#include <globaldefs.h>
extern "C" void func_0205e324(void*);
extern "C" void func_0205e180(struct Struct0205e16c*);


// USA: func_0202c814
extern "C" ARM void* func_0202c814(void* obj) {
    func_0205e324((void*)(obj));
    func_0205e180((struct Struct0205e16c*)((char*)obj + 0x1518));
    func_0205e180((struct Struct0205e16c*)((char*)obj + 0x150c));
    func_0205e180((struct Struct0205e16c*)((char*)obj + 0x1500));
    return obj;
}
