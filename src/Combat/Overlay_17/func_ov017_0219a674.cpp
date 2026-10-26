#include <globaldefs.h>
#include "NitroSDK/Memory.h"

// USA: func_ov017_0219a674
extern "C" ARM void func_ov017_0219a674(unsigned char* self) {
    VectorizedMemset(self, 0, 0x14);
    self[0x0] = 0xf;
    self[0x1] = 0x12;
    *(unsigned short*)(self + 0x2) = 0xff;
    self[0x4] = 0;
    *(unsigned short*)(self + 0x10) = 0x3244;
}
