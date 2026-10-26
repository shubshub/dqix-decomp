#if defined(jpn)
#define R(j,u) (j)
#define data_ov024_021ff6b8 data_ov023_021fe93c
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
extern "C" int func_ov011_02184c30(struct TaggedNumber02184c30* v);

struct Struct_ov011_02187b30_2 {
    TaggedNumber02184c30 a;
    TaggedNumber02184c30 b;
    TaggedNumber02184c30 c;
    int sel;
    int val;
};

extern "C" ARM void* func_ov017_021b2164(void);
extern "C" ARM void* func_ov011_021845f8(void* ctx, int v);
extern "C" ARM void* func_ov011_021849c8(void* ctx);

struct Struct_ov011_02186548;
extern "C" int func_ov023_021fcdd4(struct Struct_ov011_02186548* obj, int p1, int p2, int p3, int p4, int p5);

struct Struct_ov004_0215c30c;
struct Struct_ov004_0215c30c_2;
extern "C" void func_ov023_021f67ac(struct Struct_ov004_0215c30c* head, struct Struct_ov004_0215c30c_2* node);

extern char data_ov024_021ff6b8;

struct Struct_ov011_02187b30 { void* unknown_0_; char pad[0xcc - 4]; };

// USA: func_ov011_02187b30
extern "C" ARM int func_ov011_02187b30(struct Struct_ov011_02187b30_2* obj) {
    int tag0 = func_ov011_02184c30(&obj->a);
    int tag8 = func_ov011_02184c30(&obj->b);
    int tag10 = func_ov011_02184c30(&obj->c);
    int sb;
    if (obj->sel == 2) sb = obj->val;
    else sb = 0;
    if (sb == 0) return 0;

    void* ctx = func_ov017_021b2164();
    void* node = func_ov011_021845f8(ctx, tag8);
    if (node == 0) return 0;

    ((SafeAllocator*)((char*)node + 4))->GetSizeWithLargestBlockRemoved();
    void* block = ((SafeAllocator*)((char*)node + 4))->Allocate(0xcc);
    if (block == 0) return 0;

    struct Struct_ov011_02187b30 local;
    local.unknown_0_ = &data_ov024_021ff6b8;
    memcpy(block, &local, sizeof(local));

    if (func_ov023_021fcdd4((struct Struct_ov011_02186548*)block, (int)ctx, tag0, tag8, tag10, sb) == 0) return 0;

    void* list = func_ov011_021849c8(ctx);
    func_ov023_021f67ac((struct Struct_ov004_0215c30c*)list, (struct Struct_ov004_0215c30c_2*)block);
    return 1;
}
