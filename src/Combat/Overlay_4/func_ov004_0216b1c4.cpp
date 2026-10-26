#if defined(jpn)
#define R(j,u) (j)
#define func_ov024_021f6f10 func_ov023_021f6f10
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void*, int);
#if defined(jpn)
#define func_ov024_021f6f10 func_ov023_021f6f10
extern "C" int func_ov024_021f6f10(void* self);
#else
extern "C" int func_ov024_021f6f10(void* self);
#endif
struct Struct_ov004_02158dcc;
extern "C" void func_ov011_021849e0(struct Struct_ov004_02158dcc* obj, unsigned short val);
struct Struct_ov004_021698f4;
extern "C" void* func_ov023_021f9c0c(struct Struct_ov004_021698f4* obj);

// USA: func_ov004_0216b1c4
extern "C" ARM void* func_ov004_0216b1c4(void* a, int id) {
    void* node = func_ov023_021f6880(func_ov011_021849c8(a), id);
    if (!node) return node;
    int t = func_ov024_021f6f10(node);
    if (t != 7) return (void*)t;
    func_ov011_021849e0((struct Struct_ov004_02158dcc*)a, (unsigned short)id);
    return func_ov023_021f9c0c((struct Struct_ov004_021698f4*)node);
}
