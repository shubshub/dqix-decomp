#include <globaldefs.h>

extern "C" int func_020d424c(int, int);
extern "C" int func_020d40bc(int, int, int, int, int, int);
extern "C" void func_020d404c(int index, int value);
extern "C" void* func_020d41d8(void);

struct Struct_020d4e58 {
    int field0;
    int field4;
    char pad[0x10 - 0x8];
    int field10;
};

// USA: func_020d4e58
extern "C" ARM int func_020d4e58(int a, int b) {
    int result = func_020d424c(1, 0);
    if (result != 0) {
        return result;
    }
    func_020d404c(3, a);
    struct Struct_020d4e58* ctx = (struct Struct_020d4e58*)func_020d41d8();
    result = func_020d40bc(3, 4, ctx->field0, ctx->field4, ctx->field10, b);
    if (result == 0) {
        result = 2;
    }
    return result;
}
