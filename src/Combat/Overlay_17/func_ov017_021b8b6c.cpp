#include <globaldefs.h>

extern "C" void func_ov017_021b6f9c(void* p);

struct Struct_ov017_021b6f9c {
    char pad[0x600 + 0xb4];
};

// USA: func_ov017_021b8b6c
extern "C" ARM void func_ov017_021b8b6c(char* p) {
    unsigned short* f = (unsigned short*)(p + 0x600 + 0xb4);
    if (*f != 1) return;
    func_ov017_021b6f9c(p);
    p[1] = 1;
}
