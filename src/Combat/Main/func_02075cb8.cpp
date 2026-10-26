#include <globaldefs.h>
extern "C" void func_020d0050(int);


struct Struct_02108dfc {
    unsigned char flag;
    unsigned char pad1;
    unsigned short value;
};

extern struct Struct_02108dfc data_02108dfc;

// USA: func_02075cb8
extern "C" ARM void func_02075cb8(void) {
    func_020d0050((int)(data_02108dfc.value));
    data_02108dfc.flag = 1;
}
