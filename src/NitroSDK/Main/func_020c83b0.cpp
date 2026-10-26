#include <globaldefs.h>

extern "C" int func_020c8548(int);
extern "C" int func_020c862c(int);
extern "C" void func_020c86d4(int index, int value);
extern "C" void func_020c86e8(int index, int value);

extern int data_0211155c;

// USA: func_020c83b0
extern "C" ARM void func_020c83b0(void) {
    if (data_0211155c != 0) {
        return;
    }
    data_0211155c = 1;

    int var0 = func_020c8548(0);
    func_020c86d4(0, var0);
    int var1 = func_020c862c(0);
    func_020c86e8(0, var1);

    func_020c86e8(2, 0);
    func_020c86d4(2, 0);

    int var2 = func_020c8548(3);
    func_020c86d4(3, var2);
    int var3 = func_020c862c(3);
    func_020c86e8(3, var3);

    int var4 = func_020c8548(4);
    func_020c86d4(4, var4);
    int var5 = func_020c862c(4);
    func_020c86e8(4, var5);

    int var6 = func_020c8548(5);
    func_020c86d4(5, var6);
    int var7 = func_020c862c(5);
    func_020c86e8(5, var7);

    int var8 = func_020c8548(6);
    func_020c86d4(6, var8);
    int var9 = func_020c862c(6);
    func_020c86e8(6, var9);
}
