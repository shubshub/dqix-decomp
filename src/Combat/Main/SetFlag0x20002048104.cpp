#include <globaldefs.h>

extern "C" void GameObject_InitPartyMember(void* obj);

struct Obj02048104 {
    unsigned short flags;   // 0x0
};

// USA: func_02048104
ARM void SetFlag0x20002048104(struct Obj02048104* obj) {
    GameObject_InitPartyMember(obj);
    obj->flags |= 0x200;
}
