#if defined(jpn)
#define R(j,u) (j)
#define data_ov023_021ff7c4 data_ov023_021fea44
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

struct TaggedNumber02184c30;
extern "C" int func_ov011_02184c30(struct TaggedNumber02184c30* v);

struct Struct_ov011_02186548;
struct Struct_ov011_02186548_2 { int a, b; };
struct Struct_ov011_02186548_3 { unsigned char a, b; };
extern "C" int func_ov023_021fd1e0(struct Struct_ov011_02186548* obj, int unused, int p2, int p3, struct Struct_ov011_02186548_2* p4, struct Struct_ov011_02186548_3* p5);

struct Struct_ov004_0215c30c;
struct Struct_ov004_0215c30c_2;
extern "C" void func_ov023_021f67ac(struct Struct_ov004_0215c30c* head, struct Struct_ov004_0215c30c_2* node);

extern "C" void* func_ov017_021b2164(void);
extern "C" void* func_ov011_021845f8(void* ctx, int v);
extern "C" void* func_ov011_021849c8(void* ctx);

extern int data_ov023_021ff7c4;

struct Struct_ov011_02186548_4 {
    void* unknown_0_;
    char pad[0x2c - 4];
};

// USA: func_ov011_02186548
extern "C" ARM int func_ov011_02186548(char* obj) {
    int a = func_ov011_02184c30((struct TaggedNumber02184c30*)obj);
    int b = func_ov011_02184c30((struct TaggedNumber02184c30*)(obj + 8));

    struct Struct_ov011_02186548_2 pair;
    pair.a = func_ov011_02184c30((struct TaggedNumber02184c30*)(obj + 0x10));
    pair.b = func_ov011_02184c30((struct TaggedNumber02184c30*)(obj + 0x18));

    struct Struct_ov011_02186548_3 flags;
    flags.a = func_ov011_02184c30((struct TaggedNumber02184c30*)(obj + 0x20)) != 0;
    flags.b = func_ov011_02184c30((struct TaggedNumber02184c30*)(obj + 0x28)) != 0;

    void* ctx = func_ov017_021b2164();
    void* base = func_ov011_021845f8(ctx, b);
    if (base == 0) return 0;

    ((SafeAllocator*)((char*)base + 4))->GetSizeWithLargestBlockRemoved();
    void* newObj = ((SafeAllocator*)((char*)base + 4))->Allocate(0x2c);
    if (newObj == 0) return 0;

    struct Struct_ov011_02186548_4 local;
    local.unknown_0_ = &data_ov023_021ff7c4;
    memcpy(newObj, &local, 0x2c);

    if (func_ov023_021fd1e0((struct Struct_ov011_02186548*)newObj, (int)ctx, a, b, &pair, &flags) == 0) return 0;

    void* list = func_ov011_021849c8(ctx);
    func_ov023_021f67ac((struct Struct_ov004_0215c30c*)list, (struct Struct_ov004_0215c30c_2*)newObj);
    return 1;
}
