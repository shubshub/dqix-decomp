#include <globaldefs.h>

extern "C" void func_0209c2e0(void* obj, int a, int b);

// USA: func_0209ca70
extern "C" ARM void func_0209ca70(void* obj, int val) {
    if (val < 1) return;
    if (val > 5) return;
    *(unsigned char*)((char*)obj + 0xcc) = val;
    func_0209c2e0(obj, *(unsigned char*)((char*)obj + 0xcd), 0);
}
