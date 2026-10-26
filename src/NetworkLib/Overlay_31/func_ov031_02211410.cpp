#include <globaldefs.h>

extern "C" int func_ov031_02210044(void);
extern "C" int func_ov031_0220f3f4(void);

// USA: func_ov031_02211410
extern "C" ARM int func_ov031_02211410(void) {
    int size = 0;
    size += 0x60;
    size += ((unsigned int)(func_ov031_02210044() + 0x1f) >> 5) << 5;
    return size + (((unsigned int)(func_ov031_0220f3f4() + 0x1f) >> 5) << 5);
}
