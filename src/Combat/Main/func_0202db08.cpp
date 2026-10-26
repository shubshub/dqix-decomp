#include <globaldefs.h>
extern "C" int func_020d472c(void*);

extern char data_021015a0;
extern "C" void func_0202c848(int);

// USA: func_0202db08
extern "C" ARM void func_0202db08(unsigned short* obj) {
    int r;
    if (obj[1] != 0) {
        func_0202c848(obj[1]);
        *(int*)(&data_021015a0 + 0x10) = 0xa;
        return;
    }
    r = func_020d472c((void*)(*(int*)(&data_021015a0 + 0x40)));
    if (r == 0) {
        *(int*)(&data_021015a0 + 0x10) = 1;
        return;
    }
    func_0202c848(r);
    *(int*)(&data_021015a0 + 0x10) = 0xa;
}
