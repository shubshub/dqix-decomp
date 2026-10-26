#include <globaldefs.h>
#include "NitroSDK/ProcessorContext.h"

extern "C" void OSi_ReferSymbol(unsigned int);

// USA: func_ov031_0220aa68
extern "C" ARM void func_ov031_0220aa68(unsigned char v) {
    OSi_ReferSymbol(0x2000c44);
    void* mgr = *(void**)((char*)data_02111304.activeContext + 0xa4);
    if (mgr) {
        *(unsigned char*)((char*)mgr + 9) = v;
    }
}
