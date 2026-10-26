#include <globaldefs.h>

extern int data_0211166c;
extern short data_02111670[9];

// USA: func_020c9a54
extern "C" ARM void func_020c9a54(void) {
    int i;
    data_0211166c = 0;
    i = 0;
    do {
        data_02111670[i] = 0;
        i++;
    } while (i < 9);
}
