#include <globaldefs.h>

extern "C" void func_0200edf4(void);
extern "C" void func_020015e8(int param0);
extern int data_020f2e60;

// USA: func_0200159c
extern "C" ARM void func_0200159c(int param0) {
    if (*(int*)((char*)&data_020f2e60 + 0xc) == 0) {
        func_0200edf4();
        void (*fn)(void) = *(void (**)(void))((char*)&data_020f2e60 + 0x4);
        if (fn != 0) {
            fn();
            *(void (**)(void))((char*)&data_020f2e60 + 0x4) = 0;
        }
    }
    func_020015e8(param0);
}
