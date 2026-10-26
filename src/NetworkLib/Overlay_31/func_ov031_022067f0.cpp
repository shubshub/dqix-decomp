#include <globaldefs.h>

struct Struct_ov031_0220528c;
struct Struct_ov031_022067f0_2 {
    char padding[0x10c];
    Struct_ov031_0220528c* callback;
};
struct Struct_ov031_022067f0 {
    char padding[0x68];
    Struct_ov031_022067f0_2* inner;
    char unknown_6c_[4];
    volatile short flags;
    signed char tag;
};
extern "C" int func_ov031_02207180(void*);
extern "C" void* func_ov031_02205134(void*, void*, int);
extern "C" int func_ov031_0220528c(Struct_ov031_0220528c*, void*);
extern "C" int func_ov031_0220689c(void*);

// USA: func_ov031_022067f0
extern "C" ARM int func_ov031_022067f0(void* argument) {
    Struct_ov031_022067f0* context = (Struct_ov031_022067f0*)argument;
    if (func_ov031_02207180(argument)) return -28;
    int var1 = 0;
    if (context != NULL) var1 = (context->flags & 1) != 0;
    if (!var1) return -39;
    if (!(context->flags & 4) || (context->flags & 8)) return -56;
    context->flags |= 8;
    Struct_ov031_022067f0_2* inner = context->inner;
    if (inner != NULL && inner->callback != NULL) {
        void* record = func_ov031_02205134((void*)func_ov031_0220689c,
            inner->callback, context->tag);
        if (record == NULL) return -33;
        return func_ov031_0220528c(inner->callback, record);
    }
    return 0;
}
