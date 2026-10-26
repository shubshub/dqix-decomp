#include <globaldefs.h>

// USA: func_0205e7dc
extern "C" ARM void func_0205e7dc(unsigned char* obj, int index) {
    unsigned char* p = obj + 0x1524;
    p[(unsigned)index >> 3] |= 1 << (index % 8);
}
