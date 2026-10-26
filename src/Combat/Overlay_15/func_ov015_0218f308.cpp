#include <globaldefs.h>

extern "C" void func_ov015_0218c538(void *obj, int arg1);
extern "C" void func_ov015_0218cb2c(void *obj, int arg1);

// USA: func_ov015_0218f308
extern "C" ARM void func_ov015_0218f308(void *obj, int arg1) {
    switch (*((unsigned char *)obj + 0x1c)) {
    case 0:
        func_ov015_0218c538(obj, arg1);
        break;
    case 2:
        func_ov015_0218cb2c(obj, arg1);
        break;
    case 3:
        func_ov015_0218cb2c(obj, arg1);
        break;
    }
}
