#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

struct TaggedNumber02184c30 {
    int type;
    union { int i; float f; } value;
};

extern "C" int func_ov011_02184c30(struct TaggedNumber02184c30* v);

struct Struct_ov011_02188560 {
    TaggedNumber02184c30 a;
    TaggedNumber02184c30 b;
    int unknown_10_;
    int unknown_14_;
    int unknown_18_;
    int unknown_1c_;
    TaggedNumber02184c30 c;
};

extern "C" ARM void* func_ov017_021b2164(void);
extern "C" ARM void* func_ov011_021845f8(void* ctx, int v);
extern "C" ARM void* func_ov011_021849c8(void* ctx);

struct Struct_ov011_0218563c_3;
extern "C" int func_ov023_021fa298(struct Struct_ov011_0218563c_3* obj, int p1, int p2, int p3, int p4, int p5, int p6);

struct Struct_ov004_0215c30c;
struct Struct_ov004_0215c30c_2;
extern "C" void func_ov023_021f67ac(struct Struct_ov004_0215c30c* head, struct Struct_ov004_0215c30c_2* node);

extern int data_ov024_021fea34;

struct Struct_ov011_02188560_2 { void* unknown_0_; char pad[0x30 - 4]; };

// USA: func_ov011_02188560
extern "C" ARM int func_ov011_02188560(struct Struct_ov011_02188560* obj) {
    int tag0 = func_ov011_02184c30(&obj->a);
    int tag8 = func_ov011_02184c30(&obj->b);

    int var2;
    if (obj->unknown_10_ == 2) var2 = obj->unknown_14_;
    else var2 = 0;
    if (var2 == 0) return 0;

    int var3;
    if (obj->unknown_18_ == 2) var3 = obj->unknown_1c_;
    else var3 = 0;
    if (var3 == 0) return 0;

    void* ctx = func_ov017_021b2164();
    void* node = func_ov011_021845f8(ctx, tag8);
    if (node == 0) return 0;

    int var6 = func_ov011_02184c30(&obj->c);

    ((SafeAllocator*)((char*)node + 4))->GetSizeWithLargestBlockRemoved();
    void* block = ((SafeAllocator*)((char*)node + 4))->Allocate(0x30);
    if (block == 0) return 0;

    struct Struct_ov011_02188560_2 local;
    local.unknown_0_ = &data_ov024_021fea34;
    memcpy(block, &local, sizeof(Struct_ov011_02188560_2));

    if (func_ov023_021fa298((struct Struct_ov011_0218563c_3*)block, (int)ctx, tag0, tag8, var2, var3, var6) == 0) return 0;

    func_ov023_021f67ac((struct Struct_ov004_0215c30c*)func_ov011_021849c8(ctx), (struct Struct_ov004_0215c30c_2*)block);
    return 1;
}
