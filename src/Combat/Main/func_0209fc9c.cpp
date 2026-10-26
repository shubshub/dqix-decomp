#include <globaldefs.h>

struct Struct_0209da08 {
    char pad0[4];
    char* data;
};

// USA: func_0209fc9c
extern "C" ARM int func_0209fc9c(struct Struct_0209da08* ctx, int index) {
    unsigned char* arr = (unsigned char*)(ctx->data + 0x8d5c);
    if (arr == NULL) {
        return 0;
    }
    if (index < 0 && index >= 10) {
        return 0;
    }
    return arr[index];
}
