#include <globaldefs.h>

struct Struct_020421c4_2 {
    char* base;         // 0x0
    short index;        // 0x4
    char pad[4];        // 0x6..0x9
    unsigned char flag; // 0xa
};

// USA: func_0204aa48
extern "C" ARM int func_0204aa48(struct Struct_020421c4_2* list) {
    int shift = 5;
    if (list->flag) {
        shift = 6;
    }
    return list->index << shift;
}
