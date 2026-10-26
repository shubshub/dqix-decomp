#include <globaldefs.h>

struct Struct_02048120;
extern "C" void func_02048120(struct Struct_02048120*);

// USA: func_020489bc
extern "C" ARM void func_020489bc(void* obj) {
    func_02048120((struct Struct_02048120*)obj);
    *(unsigned short*)obj |= 0x80;
    *(int*)((char*)obj + 0x13c) = 0;
    *(int*)((char*)obj + 0x138) = 0;
    *(char*)((char*)obj + 0x140) = 0;
}
