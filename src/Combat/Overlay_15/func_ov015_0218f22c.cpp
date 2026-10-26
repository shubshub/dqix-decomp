#include <globaldefs.h>

extern "C" void func_ov015_0218e810(void* obj);
extern "C" void func_ov015_0218eb04(void* obj);
extern "C" void func_ov015_0218ecd8(void* obj);
extern "C" void func_ov015_0218edcc(void* obj);
extern "C" void func_ov015_0218ee38(void* obj);

// USA: func_ov015_0218f22c
extern "C" ARM void func_ov015_0218f22c(void* obj) {
    unsigned char mode = *(unsigned char*)((char*)obj + 0x1c);
    switch (mode) {
    case 0:
        func_ov015_0218e810(obj);
        break;
    case 1:
        func_ov015_0218eb04(obj);
        break;
    case 3:
        func_ov015_0218ecd8(obj);
        break;
    case 2:
        func_ov015_0218edcc(obj);
        break;
    case 4:
        func_ov015_0218ee38(obj);
        break;
    }
}
