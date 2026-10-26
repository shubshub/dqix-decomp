#include <globaldefs.h>
extern "C" int func_020a3570(struct Struct_0204a170*);

extern "C" void func_020a212c(void* actor, int arg);

// USA: func_020a20f0
extern "C" ARM void func_020a20f0(void* actor) {
    unsigned char* a = (unsigned char*)actor;
    if (func_020a3570((struct Struct_0204a170*)(actor))) {
        a[0x244] |= 8;
        return;
    }
    if (*(int*)(a + 0x238) == 0) {
        return;
    }
    func_020a212c(actor, 1);
}
