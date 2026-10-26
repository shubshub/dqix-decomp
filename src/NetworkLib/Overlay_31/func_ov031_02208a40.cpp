#include <globaldefs.h>

extern "C" int func_ov031_022089f4(int a, int b, int c, unsigned short d);

extern unsigned short data_ov031_022496fc[2];

// USA: func_ov031_02208a40
extern "C" ARM int func_ov031_02208a40(int a, int b, int c) {
    unsigned int i = 0;
    do {
        if (func_ov031_022089f4(a, b, c, data_ov031_022496fc[i]) != 0) {
            return data_ov031_022496fc[i];
        }
        i++;
    } while (i < 2);
    return 0;
}
