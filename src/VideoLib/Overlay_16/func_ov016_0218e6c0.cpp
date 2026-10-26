#include <globaldefs.h>

extern "C" int func_ov016_0218ef50(void*);

// USA: func_ov016_0218e6c0
extern "C" ARM int func_ov016_0218e6c0(void* obj) {
    if (obj == NULL) return 0;
    return func_ov016_0218ef50(obj) == 1;
}
