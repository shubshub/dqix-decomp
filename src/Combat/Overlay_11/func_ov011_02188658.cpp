#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

struct TaggedNumber02184c30 {
    int type;
    union { int i; float f; } value;
};

struct Struct_ov011_02188658_2 {
    TaggedNumber02184c30 tag0;
    TaggedNumber02184c30 tag8;
    int unknown_10_;
    int unknown_14_;
    int unknown_18_;
    int unknown_1c_;
    TaggedNumber02184c30 unknown_20_;
    TaggedNumber02184c30 unknown_28_;
    TaggedNumber02184c30 unknown_30_;
};

extern "C" int func_ov011_02184c30(struct TaggedNumber02184c30* v);
extern "C" ARM void* func_ov017_021b2164(void);
extern "C" ARM void* func_ov011_021845f8(void* ctx, int v);
extern "C" ARM void* func_ov011_021849c8(void* ctx);
extern "C" ARM int func_ov023_021f745c(void* buf, void* obj, int arg2, int arg3, int p5, int p6, int p7, int p8, int p9);

struct Struct_ov004_0215c30c;
struct Struct_ov004_0215c30c_2;
extern "C" void func_ov023_021f67ac(struct Struct_ov004_0215c30c* head, struct Struct_ov004_0215c30c_2* node);

extern char data_ov023_021fe4f0;

struct Struct_ov011_02188658 { void* magic; char pad[0x54 - 4]; };

// USA: func_ov011_02188658
extern "C" ARM int func_ov011_02188658(struct Struct_ov011_02188658_2* obj) {
    int tag0 = func_ov011_02184c30(&obj->tag0);
    int tag8 = func_ov011_02184c30(&obj->tag8);
    int p5;
    if (obj->unknown_10_ == 2) p5 = obj->unknown_14_;
    else p5 = 0;
    if (p5 == 0) return 0;

    int p6;
    if (obj->unknown_18_ == 2) p6 = obj->unknown_1c_;
    else p6 = 0;
    if (p6 == 0) return 0;

    int var4 = func_ov011_02184c30(&obj->unknown_20_);
    int var5 = func_ov011_02184c30(&obj->unknown_28_);
    int var6 = func_ov011_02184c30(&obj->unknown_30_);

    void* ctx = func_ov017_021b2164();
    void* node = func_ov011_021845f8(ctx, tag8);
    if (node == 0) return 0;

    ((SafeAllocator*)((char*)node + 4))->GetSizeWithLargestBlockRemoved();
    void* block = ((SafeAllocator*)((char*)node + 4))->Allocate(0x54);
    if (block == 0) return 0;

    struct Struct_ov011_02188658 local;
    local.magic = &data_ov023_021fe4f0;
    memcpy(block, &local, sizeof(Struct_ov011_02188658));

    if (func_ov023_021f745c(block, ctx, tag0, tag8, p5, p6, var4, var5, var6) == 0) return 0;

    func_ov023_021f67ac((struct Struct_ov004_0215c30c*)func_ov011_021849c8(ctx), (struct Struct_ov004_0215c30c_2*)block);
    return 1;
}
