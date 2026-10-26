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
extern "C" int func_ov023_021fbddc(void*, int, int, int);

// USA: func_ov004_0216863c
extern "C" ARM int func_ov004_0216863c(void* a) {
    void* node = func_ov023_021f6880(func_ov011_021849c8(a), 0x7);
    if (node) {
        if (func_ov024_021f6f10(node) == 0x10) {
            typedef void (*Type_ov004_0216863c)(void*);
            ((Type_ov004_0216863c)&func_ov023_021fbddc)(node);
        }
    }
    return 0;
}
