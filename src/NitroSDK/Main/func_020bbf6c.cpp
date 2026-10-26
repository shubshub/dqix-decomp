#include <globaldefs.h>

struct Struct_0210f840 { void* ptr; unsigned char pad[0x20]; };
extern struct Struct_0210f840 data_0210f840[];

// USA: func_020bbf6c
extern "C" ARM void func_020bbf6c(int index, void* value) {
    data_0210f840[index].ptr = value;
}
