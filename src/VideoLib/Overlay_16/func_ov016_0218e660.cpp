#include <globaldefs.h>

extern "C" int func_ov016_0218ef14(int* obj);

// USA: func_ov016_0218e660
extern "C" ARM int func_ov016_0218e660(int* obj) {
    if (obj == 0) {
        return 0;
    }
    return func_ov016_0218ef14(obj);
}
