#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

struct TaggedNumber02184c30;
extern "C" int func_ov011_02184c30(struct TaggedNumber02184c30* v);

struct Struct_ov011_02184c4c;
extern "C" float func_ov011_02184c4c(struct Struct_ov011_02184c4c* v);

extern "C" ARM void* func_ov017_021b2164(void);
extern "C" ARM void* func_ov011_021845f8(void* ctx, int v);
extern "C" ARM void* func_ov011_021849c8(void* ctx);
extern "C" int func_ov023_021fbb64(void* obj, void* ctx, int p2, int p3, int p4, int p5, int p6, int p7, int p8, int p9, int p10);

struct Struct_ov004_0215c30c;
struct Struct_ov004_0215c30c_2;
extern "C" void func_ov023_021f67ac(struct Struct_ov004_0215c30c* head, struct Struct_ov004_0215c30c_2* node);

extern char data_ov023_021ff078;

struct Struct_ov011_02186884 { void* unknown_0_; char pad[0x40 - 4]; };

// USA: func_ov011_02186884
extern "C" ARM int func_ov011_02186884(char* obj) {
    int v0 = func_ov011_02184c30((struct TaggedNumber02184c30*)obj);
    int v1 = func_ov011_02184c30((struct TaggedNumber02184c30*)(obj + 8));
    int v2 = func_ov011_02184c30((struct TaggedNumber02184c30*)(obj + 0x10));
    int v3 = (int)func_ov011_02184c4c((struct Struct_ov011_02184c4c*)(obj + 0x18));
    int v4 = (int)func_ov011_02184c4c((struct Struct_ov011_02184c4c*)(obj + 0x20));
    int v5 = (int)func_ov011_02184c4c((struct Struct_ov011_02184c4c*)(obj + 0x28));
    int v6 = (int)func_ov011_02184c4c((struct Struct_ov011_02184c4c*)(obj + 0x30));
    int v7 = func_ov011_02184c30((struct TaggedNumber02184c30*)(obj + 0x38));
    int v8 = func_ov011_02184c30((struct TaggedNumber02184c30*)(obj + 0x40));

    void* ctx = func_ov017_021b2164();
    void* node = func_ov011_021845f8(ctx, v1);
    if (node == 0) return 0;

    ((SafeAllocator*)((char*)node + 4))->GetSizeWithLargestBlockRemoved();
    void* slot = ((SafeAllocator*)((char*)node + 4))->Allocate(0x40);
    if (slot == 0) return 0;

    struct Struct_ov011_02186884 local;
    local.unknown_0_ = &data_ov023_021ff078;
    memcpy(slot, &local, sizeof(Struct_ov011_02186884));

    if (func_ov023_021fbb64(slot, ctx, v0, v1, v2, v3, v4, v5, v6, v7, v8) == 0) return 0;

    void* list = func_ov011_021849c8(ctx);
    func_ov023_021f67ac((struct Struct_ov004_0215c30c*)list, (struct Struct_ov004_0215c30c_2*)slot);
    return 1;
}
