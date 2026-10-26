#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" unsigned char func_ov031_02227548(void);

extern char data_ov031_02250bb0[0x40];
extern unsigned char data_ov031_02248990[];

// USA: func_ov031_02223478
extern "C" ARM char* func_ov031_02223478(unsigned char* src) {
    strncpy(data_ov031_02250bb0, (char*)src, 0x3f);
    if (src[5] == 'x') {
        return data_ov031_02250bb0;
    }
    unsigned char field0 = func_ov031_02227548();
    if (src[5] == 'y') {
        if (field0 != 0) {
            return data_ov031_02250bb0;
        }
    }
    data_ov031_02250bb0[5] = data_ov031_02248990[field0];
    return data_ov031_02250bb0;
}
