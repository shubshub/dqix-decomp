#include <globaldefs.h>

struct Struct_020535f4 {
#if defined(jpn)
    char pad[0x178];
#else
    char pad[0x184];
#endif
    unsigned char counter;
};

// USA: func_020535f4
extern "C" ARM void func_020535f4(struct Struct_020535f4* p) {
    p->counter++;
}
