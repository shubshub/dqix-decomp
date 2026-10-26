#include <globaldefs.h>

extern "C" int func_ov016_0218f330(void* obj);

// USA: func_ov016_0218e750
extern "C" ARM int func_ov016_0218e750(void* obj) {
    if (obj == 0) {
        return 0;
    }
    return func_ov016_0218f330(obj);
}
