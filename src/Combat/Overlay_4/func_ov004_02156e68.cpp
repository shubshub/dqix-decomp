#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

struct Struct_ov004_021549e4_4;
struct Struct_ov004_021549e4_2;
struct Struct_ov004_021549e4_3;

extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void**, int);
extern "C" unsigned short func_ov023_021f6f10(void*);
extern "C" unsigned short func_ov023_021f9bc0(Struct_ov004_021549e4_4*);
extern "C" unsigned int func_ov023_021f9bb0(Struct_ov004_021549e4_2*);
extern "C" unsigned int func_ov023_021f9b6c(Struct_ov004_021549e4_3*, unsigned int, unsigned int);

// USA: func_ov004_02156e68
extern "C" ARM void* func_ov004_02156e68(void* a, int key) {
    void* base = func_ov011_021849c8(a);
    void* node = func_ov023_021f6880((void**)base, key);
    if (!node) return 0;
    if (func_ov023_021f6f10(node) != 7) return 0;
    unsigned short field2a = func_ov023_021f9bc0((Struct_ov004_021549e4_4*)node);
    unsigned int idx = func_ov023_021f9bb0((Struct_ov004_021549e4_2*)node);
    unsigned int entry = func_ov023_021f9b6c((Struct_ov004_021549e4_3*)node, idx, field2a);
    return func_ov023_021f6880((void**)base, entry);
}
