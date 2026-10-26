#include <globaldefs.h>

extern "C" int func_ov000_0215e9fc(void* obj, short* buf, int max, int start);
extern "C" int func_ov000_0215eb1c(void* obj, short* buf, int max, int start);

// USA: func_ov000_02153e40
extern "C" ARM int func_ov000_02153e40(void* obj, short* buf, int max, int start) {
    int n = 0;
    n = n + func_ov000_0215e9fc(obj, buf, max, start);
    return n + func_ov000_0215eb1c(obj, buf + n, max - n, start);
}
