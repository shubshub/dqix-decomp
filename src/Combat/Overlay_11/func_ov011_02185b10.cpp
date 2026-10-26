#if defined(jpn)
#define R(j,u) (j)
#define data_ov024_021fe910 data_ov023_021fdbd4
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

struct Struct_ov011_02185b10_2 {
    TaggedNumber02184c30 a;
    TaggedNumber02184c30 b;
};

extern "C" int func_ov011_02184c30(struct TaggedNumber02184c30* v);
extern "C" ARM void* func_ov017_021b2164(void);
extern "C" ARM void* func_ov011_021849c8(void* ctx);
extern "C" ARM void* func_ov023_021f6880(void* obj, int v);
extern "C" ARM void* func_ov011_021845f8(void* ctx, int v);

struct Struct_ov011_02185b10_3;
extern "C" ARM int func_ov023_021f9ec8(struct Struct_ov011_02185b10_3* obj, void* ctx, int arg2, int arg3, int arg4);

struct Struct_ov004_0215c30c;
struct Struct_ov004_0215c30c_2;
extern "C" void func_ov023_021f67ac(struct Struct_ov004_0215c30c* head, struct Struct_ov004_0215c30c_2* node);

extern int data_ov024_021fe910;

struct Struct_ov011_02185b10 { void* unknown_0_; char pad[0x28 - 4]; };

// USA: func_ov011_02185b10
extern "C" ARM int func_ov011_02185b10(struct Struct_ov011_02185b10_2* obj) {
    void* ctx = func_ov017_021b2164();
    void* list = func_ov011_021849c8(ctx);
    if (func_ov023_021f6880(list, 0xffff) != 0) return 0;

    int tag0 = func_ov011_02184c30(&obj->a);
    int tag8 = func_ov011_02184c30(&obj->b);

    void* node = func_ov011_021845f8(ctx, tag0);
    if (node == 0) return 0;

    ((SafeAllocator*)((char*)node + 4))->GetSizeWithLargestBlockRemoved();
    void* block = ((SafeAllocator*)((char*)node + 4))->Allocate(0x28);
    if (block == 0) return 0;

    struct Struct_ov011_02185b10 local;
    local.unknown_0_ = &data_ov024_021fe910;
    memcpy(block, &local, sizeof(local));

    if (func_ov023_021f9ec8((struct Struct_ov011_02185b10_3*)block, ctx, 0xffff, tag0, tag8) == 0) return 0;

    func_ov023_021f67ac((struct Struct_ov004_0215c30c*)list, (struct Struct_ov004_0215c30c_2*)block);
    return 1;
}
