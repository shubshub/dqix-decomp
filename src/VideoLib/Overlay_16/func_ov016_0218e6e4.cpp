#include <globaldefs.h>

extern "C" int func_ov016_0218f088(void*);

// USA: func_ov016_0218e6e4
extern "C" ARM int func_ov016_0218e6e4(void* obj) {
    if (obj == NULL) return 0;
    return func_ov016_0218f088(obj) == 1;
}
