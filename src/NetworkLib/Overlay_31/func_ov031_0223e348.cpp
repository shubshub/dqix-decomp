#include <globaldefs.h>

extern int data_ov031_02290dc8[3];
extern void (*data_ov031_02290dc0)(void*);

// USA: func_ov031_0223e348
extern "C" ARM void func_ov031_0223e348(void) {
    int i = 0;
    do {
        int v = data_ov031_02290dc8[i];
        if (v != 0) {
            data_ov031_02290dc0((void*)v);
            data_ov031_02290dc8[i] = 0;
        }
        i++;
    } while (i < 3);
}
