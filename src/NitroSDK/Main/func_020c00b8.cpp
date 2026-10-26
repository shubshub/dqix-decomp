#include <globaldefs.h>
#include "NitroSDK/Filesystem/NitroVM.h"

int NitroVM_FinishRead(NitroVM*);

// USA: func_020c00b8
extern "C" ARM void *func_020c00b8(void *obj) {
    return (void*)NitroVM_FinishRead((NitroVM *)((char *)obj + 0x5c));
}
