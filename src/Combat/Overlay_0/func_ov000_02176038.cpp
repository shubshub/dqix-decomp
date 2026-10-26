#include <globaldefs.h>

struct Struct_ov000_02176038 { char pad[0xb3]; unsigned char flags; };

extern "C" int func_02092b34(void*);

// USA: func_ov000_02176038
extern "C" ARM int func_ov000_02176038(struct Struct_ov000_02176038* obj) {
    obj->flags |= 0x8;
    return func_02092b34((char*)obj + 0x7c);
}
