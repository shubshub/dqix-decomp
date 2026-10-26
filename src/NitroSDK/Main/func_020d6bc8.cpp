#include <globaldefs.h>

// USA: func_020d6bc8
extern "C" ARM int func_020d6bc8(void (*callback)(void)) {
    if (callback != NULL) {
        callback();
    }
    return 0xffe412c4;
}
