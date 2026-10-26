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

struct Struct_ov011_02187310 { char a[8]; char b[8]; };
struct Struct_ov011_02187310_2 { char pad[0xc]; unsigned char fieldC; };

// USA: func_ov011_02187310
extern "C" ARM int func_ov011_02187310(struct Struct_ov011_02187310* p) {
    int v1 = func_ov011_02184c30((struct TaggedNumber02184c30*)&p->a);
    unsigned char mask = (unsigned char)func_ov011_02184c30((struct TaggedNumber02184c30*)&p->b);
    void* ctx = func_ov017_021b2164();
    struct Struct_ov011_02187310_2* result = (struct Struct_ov011_02187310_2*)func_ov023_021f6880(func_ov011_021849c8(ctx), v1);
    if (result == 0) return 0;
    result->fieldC = result->fieldC & ~mask;
    return 1;
}
