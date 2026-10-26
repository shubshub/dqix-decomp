#include <globaldefs.h>

// USA: func_02088474
extern "C" ARM void func_02088474(void* obj, int bits, int id) {
    unsigned char* p = (unsigned char*)obj;

    p[0x21] = 0;

    unsigned int f = *(unsigned int*)(p + 0x18);
    f &= ~0x20;
    *(unsigned int*)(p + 0x18) = f;

    f = *(unsigned int*)(p + 0x14);
    unsigned int var2 = (unsigned int)bits << 28;
    f &= ~0x80000;
    *(unsigned int*)(p + 0x14) = f;

    unsigned int h = *(unsigned short*)(p + 0x22);
    h &= ~0x3c;
    *(unsigned short*)(p + 0x22) = (unsigned short)h;

    f = *(unsigned int*)(p + 0x14);
    f &= ~0x800000;
    *(unsigned int*)(p + 0x14) = f;

    p[0x24] = 0;

    if (id == 0x1fc || id == 0x20f) {
        unsigned int f2 = *(unsigned int*)(p + 0x14);
        f2 &= ~0x1000000;
        *(unsigned int*)(p + 0x14) = f2;
        id = 0;
        p[0x24] = (unsigned char)id;
    }

    f = *(unsigned int*)(p + 0x14);
    f |= 0x80000;
    *(unsigned int*)(p + 0x14) = f;

    h = *(unsigned short*)(p + 0x22);
    h &= ~0x3c;
    h |= var2 >> 26;
    *(unsigned short*)(p + 0x22) = (unsigned short)h;
}
