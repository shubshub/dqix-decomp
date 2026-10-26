#include <globaldefs.h>

extern "C" void func_020939ac(void*);

// USA: func_020939fc
extern "C" ARM void func_020939fc(unsigned char* obj) {
#if defined(jpn)
    obj[0x139] &= ~1;
#else
    obj[0x3c9] &= ~1;
#endif
    func_020939ac(obj);
}
