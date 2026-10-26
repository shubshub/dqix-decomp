#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

struct TaggedNumber02184c30;
extern "C" int func_ov011_02184c30(struct TaggedNumber02184c30* v);

extern "C" void* func_ov017_021b2164(void);
extern "C" void* func_ov011_021849c8(void* ctx);
extern "C" void* func_ov023_021f6880(void* list, int value);
extern "C" int func_ov023_021f6f10(void* obj);

struct Struct_ov004_021698f4;
extern "C" void* func_ov023_021f9c0c(struct Struct_ov004_021698f4* obj);

// USA: func_ov011_02186c70
extern "C" ARM int func_ov011_02186c70(struct TaggedNumber02184c30* p) {
    int v = func_ov011_02184c30(p);
    void* ctx = func_ov017_021b2164();
    void* obj = func_ov023_021f6880(func_ov011_021849c8(ctx), v);
    if (obj == 0) return 0;
    if (func_ov023_021f6f10(obj) != 7) return 0;
    func_ov023_021f9c0c((struct Struct_ov004_021698f4*)obj);
    return 1;
}
