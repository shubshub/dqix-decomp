#include <globaldefs.h>
extern "C" void func_020bcc7c(struct Struct_020bcbc4*);


struct Struct_020bc9d0 { char pad[0x24]; signed int bit0 : 1; };

// USA: func_020bcbc4
extern "C" ARM void func_020bcbc4(struct Struct_020bc9d0* obj) {
    if (obj->bit0) {
        func_020bcc7c((struct Struct_020bcbc4*)(obj));
    }
}
