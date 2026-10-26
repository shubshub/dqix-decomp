#include <globaldefs.h>
#include "std_library_functions.h"

// USA: func_ov004_0215ee90
extern "C" ARM void func_ov004_0215ee90(void* obj) {
    char* outer = (char*)obj;
    for (int i = 0; i < 2; i++, outer += 0x240) {
        int j;
        char* entry = outer;
        for (j = 0; j < 0x1a; j++, entry += 0x16) {
            memset(entry, 0xff, 0xe);
            memset(entry + 0xe, 0, 7);
            entry[0x15] = 0;
        }
        outer[0x23c] = 0;
        outer[0x23d] = 0;
        outer[0x23e] = 0;
        outer[0x23f] = 0;
    }
}
