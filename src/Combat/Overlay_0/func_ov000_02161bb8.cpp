#include <globaldefs.h>

// USA: func_ov000_02161bb8
extern "C" ARM int func_ov000_02161bb8(unsigned char* obj) {
    for (;;) {
        unsigned char id = *obj;
        unsigned int flags = *(unsigned int*)(obj + 4);
        if (!(flags & (1 << id))) {
            return id;
        }
        *obj = id + 1;
        if (*obj >= 0x12) {
            *obj = 1;
        }
    }
}
