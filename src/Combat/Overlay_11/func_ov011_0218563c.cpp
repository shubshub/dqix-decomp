#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

struct TaggedNumber02184c30 {
    int type;
    union { int i; float f; } value;
};

struct Struct_ov011_0218563c_2 {
    TaggedNumber02184c30 a;
    TaggedNumber02184c30 b;
    int mode;
    int extra;
    TaggedNumber02184c30 c;
};

extern "C" int func_ov011_02184c30(struct TaggedNumber02184c30* v);
extern "C" ARM void* func_ov017_021b2164(void);
extern "C" ARM void* func_ov011_021845f8(void* ctx, int v);
extern "C" ARM void* func_ov011_021849c8(void* ctx);

struct Struct_ov011_0218563c_3;
extern "C" ARM int func_ov023_021fa298(struct Struct_ov011_0218563c_3* obj, int p1, int p2, int p3, int p4, int p5, int p6);

struct Struct_ov004_0215c30c;
struct Struct_ov004_0215c30c_2;
extern "C" void func_ov023_021f67ac(struct Struct_ov004_0215c30c* head, struct Struct_ov004_0215c30c_2* node);

#if defined(jpn)
extern "C" int func_ov023_021f9724(void* obj, int p1, int p2, int p3, int p4, int p5);
extern int data_ov023_021fea34;
#else
extern int data_ov024_021fea34;
#endif

struct Struct_ov011_0218563c {
    void* unknown_0_;
#if defined(jpn)
    char pad[0x2c - 4];
#else
    char pad[0x30 - 4];
#endif
};

// USA: func_ov011_0218563c
extern "C" ARM int func_ov011_0218563c(struct Struct_ov011_0218563c_2* obj) {
    int tag0 = func_ov011_02184c30(&obj->a);
    int tag8 = func_ov011_02184c30(&obj->b);
    int sb;
    if (obj->mode == 2) sb = obj->extra;
    else sb = 0;
    if (sb == 0) return 0;

    void* ctx = func_ov017_021b2164();
    void* node = func_ov011_021845f8(ctx, tag8);
    if (node == 0) return 0;

    int tag18 = func_ov011_02184c30(&obj->c);

    ((SafeAllocator*)((char*)node + 4))->GetSizeWithLargestBlockRemoved();
    void* block = ((SafeAllocator*)((char*)node + 4))->Allocate(sizeof(Struct_ov011_0218563c));
    if (block == 0) return 0;

    struct Struct_ov011_0218563c local;
#if defined(jpn)
    local.unknown_0_ = &data_ov023_021fea34;
#else
    local.unknown_0_ = &data_ov024_021fea34;
#endif
    memcpy(block, &local, sizeof(Struct_ov011_0218563c));

#if defined(jpn)
    if (func_ov023_021f9724(block, (int)ctx, tag0, tag8, sb, tag18) == 0) return 0;
#else
    if (func_ov023_021fa298((struct Struct_ov011_0218563c_3*)block, (int)ctx, tag0, tag8, 0, sb, tag18) == 0) return 0;
#endif

    func_ov023_021f67ac((struct Struct_ov004_0215c30c*)func_ov011_021849c8(ctx), (struct Struct_ov004_0215c30c_2*)block);
    return 1;
}
