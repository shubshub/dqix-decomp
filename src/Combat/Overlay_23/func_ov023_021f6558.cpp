#include <globaldefs.h>

extern "C" void* func_ov023_021f6524(void* ctx, int value);
struct Struct_ov004_021549e4_4;
extern "C" unsigned short func_ov023_021f9bc0(struct Struct_ov004_021549e4_4* o);
struct Struct_ov004_021549e4_2;
extern "C" unsigned int func_ov023_021f9bb0(struct Struct_ov004_021549e4_2* obj);
struct Struct_ov004_021549e4_3;
extern "C" unsigned int func_ov023_021f9b6c(struct Struct_ov004_021549e4_3* obj, unsigned int a, unsigned int b);

// USA: func_ov023_021f6558
extern "C" ARM void* func_ov023_021f6558(void* ctx, int value) {
    void* obj = func_ov023_021f6524(ctx, value);
    if (obj == 0) return (void*)-1;
    unsigned int b = func_ov023_021f9bc0((struct Struct_ov004_021549e4_4*)obj);
    unsigned int a = func_ov023_021f9bb0((struct Struct_ov004_021549e4_2*)obj);
    return (void*)func_ov023_021f9b6c((struct Struct_ov004_021549e4_3*)obj, a, b);
}
