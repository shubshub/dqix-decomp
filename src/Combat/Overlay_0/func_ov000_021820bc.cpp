#include <globaldefs.h>

typedef int (*Type_ov000_021820bc)(void*, int, int);
extern Type_ov000_021820bc data_ov000_0218409c[];

// USA: func_ov000_021820bc
extern "C" ARM int func_ov000_021820bc(void* obj, int unused, int index, int arg) {
    if (index < 0 || (unsigned int)index >= 0x3a) {
        return 0;
    }
    Type_ov000_021820bc h = data_ov000_0218409c[index];
    if (h == 0) {
        return 0;
    }
    return h(obj, unused, arg);
}
