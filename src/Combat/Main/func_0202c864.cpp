#include <globaldefs.h>

extern char data_021015a0;
extern char data_02101600;
extern char data_02101640;

extern "C" int func_0202c958(void);
extern "C" void func_0202c848(int arg);
extern "C" void func_0202c918(unsigned short* a);
extern "C" int func_020d68dc(int value, unsigned int count, void* data);

typedef unsigned int (*Type_0202c864)(void*, void*);

// USA: func_0202c864
extern "C" ARM void func_0202c864(unsigned short* a)
{
    unsigned short v = a[1];
    if (v != 0) {
        func_0202c848(v);
        *(int*)(&data_021015a0 + 0x10) = 9;
        return;
    }

    Type_0202c864 fn = *(Type_0202c864*)(&data_021015a0 + 0x3c);
    if (fn != 0) {
        int result;
        *(int*)(&data_021015a0 + 0x10) = 3;
        unsigned int ret = fn(&data_02101600, &data_02101640);
        result = func_020d68dc((int)func_0202c918, ret, &data_02101600);
        if (result == 2) {
            result = 1;
        } else {
            func_0202c848(result);
            *(int*)(&data_021015a0 + 0x10) = 9;
            result = 0;
        }
        if (result == 0) {
            *(int*)(&data_021015a0 + 0x10) = 9;
        }
    } else {
        if (func_0202c958() == 0) {
            *(int*)(&data_021015a0 + 0x10) = 9;
        }
    }
}
