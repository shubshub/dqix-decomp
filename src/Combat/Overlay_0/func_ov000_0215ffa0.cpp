#include <globaldefs.h>

// USA: func_ov000_0215ffa0
extern "C" ARM short func_ov000_0215ffa0(void *obj_) {
    unsigned char *obj = (unsigned char*)obj_;
    int idx;
    unsigned char b = obj[0x17];
    idx = b - 1;
    if (b > 3) idx = 2;
    if (b == 0) idx = 0;
    return *(short*)((char*)obj + idx * 2 + 0xe);
}
