#include <globaldefs.h>

// USA: func_020d857c
extern "C" ARM int func_020d857c(signed char* a, signed char* b) {
    if (a == NULL) return 0;
    if (b == NULL) return 0;
    if (a == b) return 1;
    while (*a != 0 && *b != 0 && *a == *b) {
        a++;
        b++;
    }
    return (*b == 0) ? 1 : 0;
}
