#include <globaldefs.h>

extern "C" void* func_ov000_02160130(void);
extern "C" void func_ov000_02163710(void* obj, int flag);
extern "C" void func_ov000_021636ac(void* objRaw);

// USA: func_ov025_021e82e4
extern "C" ARM int func_ov025_021e82e4(unsigned char* param) {
    void* obj = func_ov000_02160130();
    if (param[8]) {
        func_ov000_02163710(obj, 1);
    } else {
        func_ov000_021636ac(obj);
    }
    return 1;
}
