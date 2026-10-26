#include <globaldefs.h>

struct Struct_020b0fac_2 {
    void* field0;
    int (*unknown_4_)(const char** cursor);
};

struct Struct_020b0fac {
    int unknown_0_;
    int unknown_4_;
    const char* cursor;
};

// USA: func_020b0fac
extern "C" ARM int func_020b0fac(struct Struct_020b0fac_2* obj, int width, const char* text) {
    struct Struct_020b0fac ctx;
    int* var1 = (int*)&ctx;
    ctx.cursor = text;
    var1[0] = 0;
    var1[1] = 0;

    int var2 = 1;
    int (*var3)(const char**) = obj->unknown_4_;
    int ch = var3(&ctx.cursor);
    if (ch != 0) {
        do {
            if (ch == 0xa) var2++;
            ch = var3(&ctx.cursor);
        } while (ch != 0);
    }

    signed char extra = ((signed char*)obj->field0)[1];
    return var2 * (width + extra) - width;
}
