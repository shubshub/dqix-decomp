#if defined(jpn)
#define R(j,u) (j)
#define data_ov024_021ff8c8 data_ov023_021feb44
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

struct Struct_ov011_02188184_2 {
    TaggedNumber02184c30 a;
    TaggedNumber02184c30 b;
    TaggedNumber02184c30 c;
    TaggedNumber02184c30 d;
    TaggedNumber02184c30 e;
    TaggedNumber02184c30 f;
    TaggedNumber02184c30 g;
};

extern "C" int func_ov011_02184c30(struct TaggedNumber02184c30* v);
extern "C" ARM void* func_ov017_021b2164(void);
extern "C" ARM void* func_ov011_021845f8(void* ctx, int v);
extern "C" ARM void* func_ov011_021849c8(void* ctx);

struct Struct_ov011_02188184_3;
extern "C" ARM int func_ov023_021fd320(struct Struct_ov011_02188184_3* obj, int unused, int val, int byteVal, int p5, int p6, int p7, int p8, int p9);

struct Struct_ov004_0215c30c;
struct Struct_ov004_0215c30c_2;
extern "C" void func_ov023_021f67ac(struct Struct_ov004_0215c30c* head, struct Struct_ov004_0215c30c_2* node);

extern int data_ov024_021ff8c8;

struct Struct_ov011_02188184 { void* unknown_0_; char pad[0x30 - 4]; };

// USA: func_ov011_02188184
extern "C" ARM int func_ov011_02188184(struct Struct_ov011_02188184_2* obj) {
    int tag0 = func_ov011_02184c30(&obj->a);
    int tag8 = func_ov011_02184c30(&obj->b);
    int tag10 = func_ov011_02184c30(&obj->c);
    int tag18 = func_ov011_02184c30(&obj->d);
    int var4 = func_ov011_02184c30(&obj->e);
    int var5 = func_ov011_02184c30(&obj->f);
    int var6 = func_ov011_02184c30(&obj->g);

    void* ctx = func_ov017_021b2164();
    void* node = func_ov011_021845f8(ctx, tag8);
    if (node == 0) return 0;

    ((SafeAllocator*)((char*)node + 4))->GetSizeWithLargestBlockRemoved();
    void* block = ((SafeAllocator*)((char*)node + 4))->Allocate(0x30);
    if (block == 0) return 0;

    struct Struct_ov011_02188184 local;
    local.unknown_0_ = &data_ov024_021ff8c8;
    memcpy(block, &local, sizeof(Struct_ov011_02188184));

    if (func_ov023_021fd320((struct Struct_ov011_02188184_3*)block, (int)ctx, tag0, tag8, tag10, tag18, var4, var5, var6) == 0) return 0;

    func_ov023_021f67ac((struct Struct_ov004_0215c30c*)func_ov011_021849c8(ctx), (struct Struct_ov004_0215c30c_2*)block);
    return 1;
}
