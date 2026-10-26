#include <globaldefs.h>

struct Struct_0202bad4 {
    char data[0xc0];
};

struct Struct_0202bad4_2 {
    char pad[0x10];
    struct Struct_0202bad4 elements[1];
};

// USA: func_0202bad4
extern "C" ARM struct Struct_0202bad4* func_0202bad4(struct Struct_0202bad4_2* base, int index) {
    return &base->elements[index];
}
