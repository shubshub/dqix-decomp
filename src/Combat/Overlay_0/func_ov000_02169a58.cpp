#include <globaldefs.h>

// USA: func_ov000_02169a58
extern "C" ARM void* func_ov000_02169a58(char* node, int value) {
    while (node != 0) {
        int i = 0;
        while (i < *(unsigned short*)(node + 4)) {
            if (value == (*(unsigned short**)(node + 0))[i]) {
                return node;
            }
            i++;
        }
        node = *(char**)(node + 0xc);
    }
    return 0;
}
