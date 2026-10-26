#include <globaldefs.h>
#include "NitroSDK/Filesystem/CardReadManager.h"
#include "NitroSDK/Filesystem/LowNitroHandle.h"

extern "C" void func_ov031_0223b604(NitroHandle* handle);

// USA: func_ov031_0223b5c4
extern "C" ARM int func_ov031_0223b5c4(NitroHandle* a, void* b, unsigned int c, unsigned int d) {
    LoadDataFromCartridgeToMemory((unsigned int)-1, c + *(unsigned int*)((char*)a + 0x28), b, d,
        func_ov031_0223b604, a, 1);
    return 6;
}
