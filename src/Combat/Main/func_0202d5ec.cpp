#include <globaldefs.h>

extern char data_021015a0;
extern "C" void func_0202c848(int);

// USA: func_0202d5ec
extern "C" ARM void func_0202d5ec(unsigned short* obj) {
    if (obj[1] == 0) {
        *(int*)(&data_021015a0 + 0x10) = 1;
        return;
    }
    func_0202c848(obj[1]);
}
