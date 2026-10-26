#include <globaldefs.h>

extern "C" void func_02059cc8(unsigned char* obj);

// USA: func_020d7334
extern "C" ARM void func_020d7334(unsigned char* base, int index) {
    int off;
    unsigned int mask;
    if (index >= 0xc0) index -= 0xbc;
    off = index * 0xd8;
    func_02059cc8(base + off);
    *(int*)(base + 0xd4 + off) = 0;
    mask = ~(1 << index);
    *(unsigned short*)(base + 0xa00 + 0x24) &= mask;
    *(unsigned short*)(base + 0xa00 + 0x26) &= mask;
}
