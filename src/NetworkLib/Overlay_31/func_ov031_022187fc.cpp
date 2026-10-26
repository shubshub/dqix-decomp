#include <globaldefs.h>
#include "NitroSDK/Memory.h"

typedef void (*Type_ov031_022187fc)(void*, int, int);

extern int data_ov031_02249f00;

// USA: func_ov031_022187fc
extern "C" ARM void func_ov031_022187fc(int obj, void* buf) {
    int val = *(int*)buf;
    Type_ov031_022187fc fn = *(Type_ov031_022187fc*)(obj + 0x1000 + 0x14);
    if (val != 0) {
        fn(&data_ov031_02249f00, val, 0);
    }
    VectorizedMemset(buf, 0, 0x10);
}
