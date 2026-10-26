#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

struct TaggedNumber02184c30 {
    int type;
    union { int i; float f; } value;
};

struct Struct_ov011_02185be8_2 {
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
extern "C" ARM void* func_ov011_02185ce0(void* obj);
extern "C" ARM void SpriteContext_Destroy(void* obj);
#if defined(jpn)
// JPN: func_ov011_02185ce0 is inlined, the object is 0x84 bytes and func_ov023_021fa760 takes 6 arguments.
extern "C" void SpriteContext_Init(char* obj);
extern int data_ov023_021fddfc;
extern "C" ARM int func_ov023_021fa760(void* obj, void* ctx, int p2, int p3, int p5, int p6);
#else
extern "C" ARM int func_ov023_021fa760(void* obj, void* ctx, int p2, int p3, int p4, int p5, int p6);
#endif

struct Struct_ov004_0215c30c;
struct Struct_ov004_0215c30c_2;
extern "C" void func_ov023_021f67ac(struct Struct_ov004_0215c30c* head, struct Struct_ov004_0215c30c_2* node);

#if defined(jpn)
struct Struct_ov011_02185be8 {
    void* unknown_0_;
    char pad[0x20 - 4];
    char sub[0x84 - 0x20];
};
#else
struct Struct_ov011_02185be8 {
    void* unknown_0_;
    char pad[0x24 - 4];
    char sub[0x88 - 0x24];
};
#endif

// USA: func_ov011_02185be8
extern "C" ARM int func_ov011_02185be8(struct Struct_ov011_02185be8_2* obj) {
    int tag0 = func_ov011_02184c30(&obj->a);
    int tag8 = func_ov011_02184c30(&obj->b);

    int flag;
    if (obj->mode == 2) flag = obj->extra;
    else flag = 0;
    if (flag == 0) return 0;

    int tag18 = func_ov011_02184c30(&obj->c);

    void* ctx = func_ov017_021b2164();
    void* node = func_ov011_021845f8(ctx, tag8);
    if (node == 0) return 0;

    ((SafeAllocator*)((char*)node + 4))->GetSizeWithLargestBlockRemoved();
    void* block = ((SafeAllocator*)((char*)node + 4))->Allocate(sizeof(Struct_ov011_02185be8));
    if (block == 0) return 0;

    struct Struct_ov011_02185be8 local;
#if defined(jpn)
    local.unknown_0_ = &data_ov023_021fddfc;
    SpriteContext_Init(local.sub);
#else
    func_ov011_02185ce0(&local);
#endif
    memcpy(block, &local, sizeof(Struct_ov011_02185be8));

#if defined(jpn)
    if (func_ov023_021fa760(block, ctx, tag0, tag8, flag, tag18) == 0) {
#else
    if (func_ov023_021fa760(block, ctx, tag0, tag8, 0, flag, tag18) == 0) {
#endif
        SpriteContext_Destroy(local.sub);
        return 0;
    }

    void* list = func_ov011_021849c8(ctx);
    func_ov023_021f67ac((struct Struct_ov004_0215c30c*)list, (struct Struct_ov004_0215c30c_2*)block);
    SpriteContext_Destroy(local.sub);
    return 1;
}
