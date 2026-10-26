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
struct Struct_ov004_021549e4_2;
extern "C" unsigned int func_ov023_021f9bb0(struct Struct_ov004_021549e4_2* obj);

// USA: func_ov004_021634dc
extern "C" ARM int func_ov004_021634dc(void* a) {
    void* node = func_ov023_021f6880(func_ov011_021849c8(a), 0xa);
    if (!node) return 0;
    if (func_ov024_021f6f10(node) != 7) return 0;
    short s = *(short*)((char*)node + 0x5c);
    return func_ov023_021f9bb0((struct Struct_ov004_021549e4_2*)node) + (s << 3);
}
