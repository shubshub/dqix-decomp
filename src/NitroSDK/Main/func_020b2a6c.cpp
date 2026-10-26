#include <globaldefs.h>

#if defined(jpn)
#define func_020b2a6c func_020b4538
#endif

struct Struct_020b2a6c {
    unsigned char pad[0x17];
    unsigned char unknown_17_;
    unsigned char field18;
};

// USA: func_020b2a6c
extern "C" ARM unsigned int func_020b2a6c(unsigned char* code, struct Struct_020b2a6c* info) {
    unsigned char c;
    if (code == NULL || info == NULL) {
        return 0;
    }
    c = code[0];
    switch (c) {
    case 0x4d:
        return ((info->field18 << 1) + 0x1c) & ~3;
    case 0x4a:
    case 0x56:
        return ((info->unknown_17_ << 1) + 0x1c) & ~3;
    }
    return 0;
}
