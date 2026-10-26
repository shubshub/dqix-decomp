#include <globaldefs.h>

extern "C" void GameObject_InitPartyMember(void* obj);

struct Struct_02048104 {
    unsigned short flags;   // 0x0
};

// USA: func_02048104
extern "C" ARM void func_02048104(struct Struct_02048104* obj) {
    GameObject_InitPartyMember(obj);
    obj->flags |= 0x200;
}
