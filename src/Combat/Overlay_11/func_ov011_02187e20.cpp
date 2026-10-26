#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

struct TaggedNumber02184c30 {
    int type;
    union { int i; float f; } value;
};

struct Struct_ov011_02187e20 {
    TaggedNumber02184c30 a;
    TaggedNumber02184c30 b;
};

extern "C" int func_ov011_02184c30(struct TaggedNumber02184c30* v);
extern "C" ARM void* func_ov017_021b2164(void);
extern "C" ARM void* func_ov011_021845f8(void* ctx, int v);
extern "C" ARM void* func_ov011_021849c8(void* ctx);
extern "C" ARM int func_ov004_02167820(void* self, void* param1, int param2, int param3);
extern "C" void* KeyTable_Construct(void* p);
extern "C" void SpriteContext_Init(char* obj);
extern "C" void SpriteContext_Destroy(void* obj);

struct Struct_ov004_0215c30c;
struct Struct_ov004_0215c30c_2;
extern "C" void func_ov023_021f67ac(struct Struct_ov004_0215c30c* head, struct Struct_ov004_0215c30c_2* node);

extern int data_ov004_021705f8;

struct Struct_ov011_02187e20_2 {
    void* unknown_0_;
    char pad0[0x20 - 4];
    SafeAllocator alloc;
    char state[0x94 - 0x34];
    char sub[0x118 - 0x94];
};

// USA: func_ov011_02187e20
extern "C" ARM int func_ov011_02187e20(struct Struct_ov011_02187e20* obj) {
    int tag0 = func_ov011_02184c30(&obj->a);
    int tag8 = func_ov011_02184c30(&obj->b);

    void* ctx = func_ov017_021b2164();
    void* node = func_ov011_021845f8(ctx, tag8);
    if (node == 0) return 0;

    ((SafeAllocator*)((char*)node + 4))->GetSizeWithLargestBlockRemoved();
    void* block = ((SafeAllocator*)((char*)node + 4))->Allocate(0x118);
    if (block == 0) return 0;

    struct Struct_ov011_02187e20_2 local;
    local.unknown_0_ = &data_ov004_021705f8;
    local.alloc.ResetAllocatorPointer();
    char* base = local.state;
    KeyTable_Construct(base + 4);
    SpriteContext_Init(base + 0x60);
    memcpy(block, &local, sizeof(Struct_ov011_02187e20_2));

    if (func_ov004_02167820(block, ctx, tag0, tag8) == 0) {
        SpriteContext_Destroy(local.sub);
        return 0;
    }

    void* list = func_ov011_021849c8(ctx);
    func_ov023_021f67ac((struct Struct_ov004_0215c30c*)list, (struct Struct_ov004_0215c30c_2*)block);
    SpriteContext_Destroy(local.sub);
    return 1;
}
