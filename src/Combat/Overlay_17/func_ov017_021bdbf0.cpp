#include <globaldefs.h>

struct ByteHeader0204693c;
extern "C" void func_0204693c(struct ByteHeader0204693c* p);

// USA: func_ov017_021bdbf0
extern "C" ARM void func_ov017_021bdbf0(unsigned char* obj) {
    func_0204693c((struct ByteHeader0204693c*)obj);
    obj[0x0] = 0x32;
    obj[0x10] = 0;
    obj[0x11] = 1;
    for (int i = 0; i < 4; i++) {
        *(short*)(obj + i * 2 + 8) = -1;
    }
}
