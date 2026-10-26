#include <globaldefs.h>

extern "C" ARM unsigned int func_ov031_022135ac(unsigned int x);
extern "C" ARM unsigned int func_ov031_022155e8(unsigned char* p);
extern "C" ARM int func_ov031_02207538(unsigned int* a, unsigned int* b);

// USA: func_ov031_02215690
extern "C" ARM void func_ov031_02215690(unsigned char* obj) {
    if (obj[0xd0d] < 6) {
        obj += func_ov031_022135ac(obj[0xd0d]) << 8;
    } else {
        return;
    }
    unsigned char flag = obj[0xc0];
    int sum = obj[0xc8] + obj[0xc9] + obj[0xca] + obj[0xcb];
    if (flag != 0) {
        return;
    }
    if (sum == 0) {
        return;
    }
    unsigned int a = func_ov031_022155e8(obj + 0xc8);
    unsigned int b = func_ov031_022155e8(obj + 0xcc);
    func_ov031_02207538(&a, &b);
}
