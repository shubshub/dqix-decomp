#include <globaldefs.h>

// USA: func_ov003_02171df0
extern "C" ARM int func_ov003_02171df0(unsigned char* arr) {
    for (int i = 0; i < 6; i++) {
        if (arr[i] != 0) return 0;
    }
    return 1;
}
