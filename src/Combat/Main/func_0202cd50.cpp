#include <globaldefs.h>

extern char data_021015a0;
extern char data_02101680;
extern char data_0210168a;
extern "C" int func_0202cddc(void);
extern "C" void VectorizedMemset(void*, int, int);

struct Struct_0202cd50 { unsigned short a, b, c; };

// USA: func_0202cd50
extern "C" ARM int func_0202cd50(int (*cb)(void), Struct_0202cd50* data, int c) {
    *(int*)(&data_021015a0 + 0x10) = 2;
    *(void**)(&data_021015a0 + 0x44) = (void*)cb;
    *(unsigned short*)(&data_021015a0 + 0x8) = (unsigned short)c;
    *(unsigned short*)(&data_02101680 + 0x6) = 1;
    *(unsigned short*)(&data_021015a0 + 0x4) = 0;
    if (data != 0) {
        *(unsigned short*)(&data_02101680 + 0xe) = data->c;
        *(unsigned short*)(&data_02101680 + 0xc) = data->b;
        *(unsigned short*)(&data_02101680 + 0xa) = data->a;
    } else {
        VectorizedMemset(&data_0210168a, 0xff, 6);
    }
    if (func_0202cddc() == 0) {
        *(int*)(&data_021015a0 + 0x10) = 9;
        return 0;
    }
    return 1;
}
