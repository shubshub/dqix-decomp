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
extern "C" void* func_ov011_021849c8(void* p);
extern "C" void* func_ov023_021f6880(void* obj, int key);
#if defined(jpn)
#define func_ov024_021f6f10 func_ov023_021f6f10
extern "C" int func_ov024_021f6f10(void* self);
#else
extern "C" int func_ov024_021f6f10(void* self);
#endif

struct Struct_ov004_0215de9c;
extern "C" void func_ov023_021fb25c(Struct_ov004_0215de9c*, unsigned int, unsigned int, unsigned int, int);

// USA: func_ov011_02187570
extern "C" ARM int func_ov011_02187570(struct TaggedNumber02184c30* a) {
    int v0 = func_ov011_02184c30(a);
    int v1 = func_ov011_02184c30((struct TaggedNumber02184c30*)((char*)a + 8));
    int v2 = func_ov011_02184c30((struct TaggedNumber02184c30*)((char*)a + 0x10));
    int v3 = func_ov011_02184c30((struct TaggedNumber02184c30*)((char*)a + 0x18));
    int v4 = func_ov011_02184c30((struct TaggedNumber02184c30*)((char*)a + 0x20));
    void* ctx = func_ov017_021b2164();
    void* obj = func_ov011_021849c8(ctx);
    struct Struct_ov004_0215de9c* node = (struct Struct_ov004_0215de9c*)func_ov023_021f6880(obj, v0);
    if (!node) return 1;
    if (func_ov024_021f6f10(node) != 1) return 1;
    func_ov023_021fb25c(node, v1, v2, v3, v4);
    return 1;
}
