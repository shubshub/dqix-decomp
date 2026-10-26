#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void __clear(void* buf, int len);

extern char data_020f08f8[];
extern char data_020e80cc[];
extern char data_020f08fa[];

// USA: func_02068ea0
extern "C" ARM void func_02068ea0(signed char* ids, char* dest) {
    if (ids[0] < 0) {
        return;
    }
    char buf[0x30];
    __clear(buf, 0x30);
    int i;
    for (i = 0; i < 4; i++) {
        if (ids[0] < 0) {
            break;
        }
        if (i != 0) {
            strcat(buf, data_020f08f8);
        }
        signed char id = *ids++;
        strcat(buf, &data_020e80cc[id * 0xc]);
    }
    sprintf(dest, data_020f08fa, buf);
}
