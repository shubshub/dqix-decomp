#include <globaldefs.h>
#include "std_library_functions.h"

extern int data_ov031_0224f7dc;

// USA: func_ov031_02222adc
extern "C" THUMB int func_ov031_02222adc(void* dst) {
    memcpy(dst, &data_ov031_0224f7dc, 0xe8);
    return 1;
}
