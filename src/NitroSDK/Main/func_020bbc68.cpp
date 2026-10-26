#include <globaldefs.h>

struct Struct_020bbc68 {
    unsigned char data[0x10];
};

struct Struct_020bbc68_2 {
    struct Struct_020bbc68* base;  // 0x0
    char unknown_4_[0x04];              // 0x4..0x7
    unsigned short index;        // 0x8
};

// USA: func_020bbc68
extern "C" ARM struct Struct_020bbc68* func_020bbc68(struct Struct_020bbc68_2* list) {
    return list->base + list->index;
}
