#include <globaldefs.h>

// USA: func_ov025_021ed2f4
extern "C" ARM int func_ov025_021ed2f4(void* obj) {
    return (*(unsigned char*)((char*)obj + 0x150) == 0) &&
           (*(unsigned short*)((char*)obj + 0x100 + 0x5e) == 0);
}
