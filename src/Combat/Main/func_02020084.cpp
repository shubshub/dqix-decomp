#include <globaldefs.h>

// USA: func_02020084
extern "C" ARM int func_02020084(unsigned char* base, int bit) {
    int var0;
    if (bit >= 0 && bit <= 3) var0 = 1;
    else var0 = 0;
    if (var0) {
        return (base[0x55d] & (1 << bit)) != 0;
    }
    return 0;
}
