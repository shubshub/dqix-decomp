#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

struct TaggedNumber02184c30 {
    int type;
    union { int i; float f; } value;
};

struct Struct_ov011_02188774 {
    TaggedNumber02184c30 a;
    TaggedNumber02184c30 b;
    int unknown_10_;
    int unknown_14_;
    int unknown_18_;
    int unknown_1c_;
    TaggedNumber02184c30 c;
};

extern "C" int func_ov011_02184c30(struct TaggedNumber02184c30* v);
extern "C" ARM void* func_ov017_021b2164(void);
extern "C" ARM void* func_ov011_021845f8(void* ctx, int v);
extern "C" ARM void* func_ov011_021849c8(void* ctx);
extern "C" ARM void* func_ov011_02185ce0(void* obj);
extern "C" ARM void SpriteContext_Destroy(void* obj);
extern "C" ARM int func_ov023_021fa760(void* obj, void* ctx, int p2, int p3, int p4, int p5, int p6);

struct Struct_ov004_0215c30c;
struct Struct_ov004_0215c30c_2;
extern "C" void func_ov023_021f67ac(struct Struct_ov004_0215c30c* head, struct Struct_ov004_0215c30c_2* node);

struct Struct_ov011_02188774_2 {
    void* unknown_0_;
    char pad[0x24 - 4];
    char sub[0x88 - 0x24];
};

// USA: func_ov011_02188774
extern "C" ARM int func_ov011_02188774(struct Struct_ov011_02188774* obj) {
    int tag0 = func_ov011_02184c30(&obj->a);
    int tag8 = func_ov011_02184c30(&obj->b);
    int flag1;
    if (obj->unknown_10_ == 2) flag1 = obj->unknown_14_;
    else flag1 = 0;
    if (flag1 == 0) return 0;

    int flag2;
    if (obj->unknown_18_ == 2) flag2 = obj->unknown_1c_;
    else flag2 = 0;
    if (flag2 == 0) return 0;

    int var4 = func_ov011_02184c30(&obj->c);

    void* ctx = func_ov017_021b2164();
    void* node = func_ov011_021845f8(ctx, tag8);
    if (node == 0) return 0;

    ((SafeAllocator*)((char*)node + 4))->GetSizeWithLargestBlockRemoved();
    void* block = ((SafeAllocator*)((char*)node + 4))->Allocate(0x88);
    if (block == 0) return 0;

    struct Struct_ov011_02188774_2 local;
    func_ov011_02185ce0(&local);
    memcpy(block, &local, sizeof(Struct_ov011_02188774_2));

    if (func_ov023_021fa760(block, ctx, tag0, tag8, flag1, flag2, var4) == 0) {
        SpriteContext_Destroy(local.sub);
        return 0;
    }

    void* list = func_ov011_021849c8(ctx);
    func_ov023_021f67ac((struct Struct_ov004_0215c30c*)list, (struct Struct_ov004_0215c30c_2*)block);
    SpriteContext_Destroy(local.sub);
    return 1;
}
