#include <globaldefs.h>
#include "std_library_functions.h"

extern int data_ov000_021833e8;

// USA: func_ov000_02174da4
extern "C" ARM void* func_ov000_02174da4(int unused, void* dest) {
    return memcpy(dest, &data_ov000_021833e8, 0x10);
}
