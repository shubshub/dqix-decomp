#include <globaldefs.h>

// USA: func_020424ac
extern "C" ARM char* func_020424ac(char* str) {
    if (str != 0) {
        while (*str != 0) {
            if (*str == '>' && str[1] != '>') {
                return str;
            }
            str++;
        }
    }
    return 0;
}
