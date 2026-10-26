#include <globaldefs.h>

struct NitroVM;
int NitroVM_CancelCommand(struct NitroVM*);

// USA: func_020c0100
extern "C" ARM int func_020c0100(void* obj) {
    return NitroVM_CancelCommand((struct NitroVM*)((char*)obj + 0x5c));
}
