#include <globaldefs.h>
extern "C" int func_020cf08c(int, int, int);

extern char data_02111818;
extern "C" void func_020cf864(void);
extern "C" void func_020cf854(int val);

// USA: func_020cf0fc
extern "C" ARM int func_020cf0fc(int a) {
    int result = func_020cf08c((int)(a), (int)(func_020cf854), (int)(0));
    *(int*)(&data_02111818 + 0x2c) = result;
    if (result == 0) {
        func_020cf864();
    }
    return *(int*)(&data_02111818 + 0x2c);
}
