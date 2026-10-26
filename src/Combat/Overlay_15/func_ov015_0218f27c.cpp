#include <globaldefs.h>

extern "C" int func_ov015_0218cc24(void* obj, void* q);
extern "C" int func_ov015_0218d50c(void* obj, void* q);
extern "C" int func_ov015_0218dbec(void* obj, void* q);
extern "C" int func_ov015_0218df0c(void* obj, void* q);
extern "C" int func_ov015_0218e02c(void* obj, void* q);
extern "C" int func_ov015_0218e2a4(void* obj, void* q);

// USA: func_ov015_0218f27c
extern "C" ARM int func_ov015_0218f27c(void* obj, void* q) {
    int result = 1;
    unsigned char mode = *(unsigned char*)((char*)obj + 0x1c);
    switch (mode) {
    case 0:
        result = func_ov015_0218cc24(obj, q);
        break;
    case 1:
        result = func_ov015_0218d50c(obj, q);
        break;
    case 3:
        result = func_ov015_0218dbec(obj, q);
        break;
    case 2:
        result = func_ov015_0218df0c(obj, q);
        break;
    case 4:
        result = func_ov015_0218e02c(obj, q);
        break;
    case 5:
        result = func_ov015_0218e2a4(obj, q);
        break;
    case 6:
        result = func_ov015_0218e2a4(obj, q);
        break;
    }
    return result;
}
