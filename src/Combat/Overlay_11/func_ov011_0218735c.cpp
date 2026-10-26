#if defined(jpn)
#define R(j,u) (j)
#define func_ov024_021f6f10 func_ov023_021f6f10
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

struct TaggedNumber02184c30;
extern "C" int func_ov011_02184c30(struct TaggedNumber02184c30* v);
extern "C" void* func_ov017_021b2164(void);
extern "C" void* func_ov011_021849c8(void*);
struct Struct_ov004_0215f6f4;
extern "C" struct Struct_ov004_0215f6f4* func_ov023_021f6880(void*, int);
#if defined(jpn)
#define func_ov024_021f6f10 func_ov023_021f6f10
extern "C" int func_ov024_021f6f10(void* self);
#else
extern "C" int func_ov024_021f6f10(void* self);
#endif
extern "C" void func_ov023_021f8944(struct Struct_ov004_0215f6f4* obj, int a1, int a2, int a3);

// USA: func_ov011_0218735c
extern "C" ARM int func_ov011_0218735c(struct TaggedNumber02184c30* p) {
    int v = func_ov011_02184c30(p);
    int b = func_ov011_02184c30((struct TaggedNumber02184c30*)((char*)p + 8)) & 0xff;
    void* ctx = func_ov017_021b2164();
    void* obj = func_ov011_021849c8(ctx);
    struct Struct_ov004_0215f6f4* node = func_ov023_021f6880(obj, v);
    if (!node) return 0;
    if (func_ov024_021f6f10(node) != 6) return 0;
    func_ov023_021f8944(node, (int)(long)ctx, b, 1);
    return 1;
}
