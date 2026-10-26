#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

struct TaggedNumber02184c30 {
    int type;
    union { int i; float f; } value;
};

struct Struct_ov011_0218792c_2 {
    TaggedNumber02184c30 a;
    TaggedNumber02184c30 b;
    TaggedNumber02184c30 c;
    TaggedNumber02184c30 d;
    TaggedNumber02184c30 e;
};

extern "C" int func_ov011_02184c30(struct TaggedNumber02184c30* v);
extern "C" ARM void* func_ov017_021b2164(void);
extern "C" ARM void* func_ov011_021845f8(void* ctx, int v);
extern "C" ARM void* func_ov011_021849c8(void* ctx);
#if defined(jpn)
extern "C" ARM int func_ov023_021f745c(void* buf, void* obj, int arg2, int arg3, int p5, int p7, int p8, int p9);
#else
extern "C" ARM int func_ov023_021f745c(void* buf, void* obj, int arg2, int arg3, int p5, int p6, int p7, int p8, int p9);
#endif

struct Struct_ov004_0215c30c;
struct Struct_ov004_0215c30c_2;
extern "C" void func_ov023_021f67ac(struct Struct_ov004_0215c30c* head, struct Struct_ov004_0215c30c_2* node);

extern char data_ov023_021fe4f0;

struct Struct_ov011_0218792c { void* magic; char pad[R(0x50, 0x54) - 4]; };

// USA: func_ov011_0218792c
extern "C" ARM int func_ov011_0218792c(struct Struct_ov011_0218792c_2* obj) {
    int tag0 = func_ov011_02184c30(&obj->a);
    int tag8 = func_ov011_02184c30(&obj->b);
    int var2 = func_ov011_02184c30(&obj->c);
    int var3 = func_ov011_02184c30(&obj->d);
    int var4 = func_ov011_02184c30(&obj->e);

    void* ctx = func_ov017_021b2164();
    void* node = func_ov011_021845f8(ctx, tag8);
    if (node == 0) return 0;

    ((SafeAllocator*)((char*)node + 4))->GetSizeWithLargestBlockRemoved();
    void* block = ((SafeAllocator*)((char*)node + 4))->Allocate(R(0x50, 0x54));
    if (block == 0) return 0;

    struct Struct_ov011_0218792c local;
    local.magic = &data_ov023_021fe4f0;
    memcpy(block, &local, sizeof(Struct_ov011_0218792c));

#if defined(jpn)
    if (func_ov023_021f745c(block, ctx, tag0, tag8, 0, var2, var3, var4) == 0) return 0;
#else
    if (func_ov023_021f745c(block, ctx, tag0, tag8, 0, 0, var2, var3, var4) == 0) return 0;
#endif

    func_ov023_021f67ac((struct Struct_ov004_0215c30c*)func_ov011_021849c8(ctx), (struct Struct_ov004_0215c30c_2*)block);
    return 1;
}
