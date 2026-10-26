#include <globaldefs.h>

struct Struct_020d404c { unsigned char pad[0x18]; int arr[1]; };

extern char data_021142e0;

// USA: func_020d404c
extern "C" ARM void func_020d404c(int index, int value) {
    struct Struct_020d404c* ctx = *(struct Struct_020d404c**)(&data_021142e0 + 4);
    ctx->arr[index] = value;
}
