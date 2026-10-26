#include <globaldefs.h>
#include "std_library_functions.h"

extern int data_ov031_0224f670;

typedef void* (*Type_ov031_0222288c)(int);

// USA: func_ov031_0222288c
extern "C" THUMB void* func_ov031_0222288c(int a, int b) {
    int size = a * b;
    Type_ov031_0222288c fn = *(Type_ov031_0222288c*)((char*)&data_ov031_0224f670 + 4);
    void* p = fn(size);
    if (p) {
        memset(p, 0, size);
    }
    return p;
}
