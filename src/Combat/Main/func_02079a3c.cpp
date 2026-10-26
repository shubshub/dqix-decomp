#include <globaldefs.h>
#include "Filesystem/GPC.h"

void ZeroInitGPCPointer(GPCFile** ppGPC);

// USA: func_02079a3c
extern "C" ARM void* func_02079a3c(void* obj) {
    ZeroInitGPCPointer((GPCFile**)(obj));
    ((GPCReadPair*)obj)->ZeroInitializeMachine();
    return obj;
}
