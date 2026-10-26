#include <globaldefs.h>

extern "C" void* func_ov031_02211b64(void *a, void *b, int c);

// USA: func_ov031_02211b54
extern "C" ARM void* func_ov031_02211b54(void *a, void *b) {
    return func_ov031_02211b64(a, b, 0x20);
}
