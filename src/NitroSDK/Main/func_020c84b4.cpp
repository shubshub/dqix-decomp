#include <globaldefs.h>

extern "C" int func_020c8548(int);
extern "C" int func_020c862c(int);
extern "C" void func_020c86d4(int index, int value);
extern "C" void func_020c86e8(int index, int value);
extern "C" unsigned int func_020c7dcc();
extern "C" void func_020c8a2c(unsigned int value);
extern "C" void func_020c8a34(unsigned int value);

extern int data_0211155c;

// USA: func_020c84b4
extern "C" ARM void func_020c84b4(void) {
    int v1 = func_020c8548(2);
    func_020c86d4(2, v1);
    int v2 = func_020c862c(2);
    func_020c86e8(2, v2);

    int flag = *(int*)((char*)&data_0211155c + 0x4);
    if (flag != 0) {
        unsigned int r = func_020c7dcc();
        if ((r & 0x3) != 0x1) {
            return;
        }
    }
    func_020c8a2c(0x200002b);
    func_020c8a34(0x23e0021);
}
