#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void func_020489bc(void* obj);

// USA: func_02048614
extern "C" ARM void func_02048614(unsigned char* obj) {
    func_020489bc(obj);
    *(unsigned short*)obj |= 0x400;
    *(int*)(obj + 0x148) = 0;
    *(int*)(obj + 0x144) = 0;
    obj[0x17c] = 0;
    obj[0x17d] = 0;
    obj[0x17e] = 0;
    obj[0x17f] = 0;
    obj[0x180] = 0;
    obj[0x181] = 0;
    obj[0x182] = 0;
    obj[0x183] = 0;
    obj[0x184] = 0;
    memset(obj + 0x14c, 0, 0x30);
    *(unsigned short*)(obj + 0x186) = 0;
    *(unsigned short*)(obj + 0x188) = 0;
    *(unsigned short*)(obj + 0x18a) = 0;
    obj[0x18c] = 0;
    obj[0x18d] = 0;
    *(unsigned short*)(obj + 0x18e) = 0x1000;
}
