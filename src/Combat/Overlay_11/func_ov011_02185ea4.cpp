#if defined(jpn)
#define R(j,u) (j)
#define data_ov023_021fee68 data_ov023_021fe118
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"
#include "World/ZoneLootableRecord.h"

struct TaggedNumber02184c30 {
    int type;
    union { int i; float f; } value;
};

struct Struct_ov011_02185ea4_3 {
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
extern "C" ARM int func_ov023_021fb534(void* obj, void* ctx, int arg2, int arg3, unsigned int arg4, int arg5);

struct Struct_ov004_0215c30c;
struct Struct_ov004_0215c30c_2;
extern "C" void func_ov023_021f67ac(struct Struct_ov004_0215c30c* head, struct Struct_ov004_0215c30c_2* node);

extern char data_ov023_021fee68;

struct Struct_ov011_02185ea4 {
    char pad[0x54];
    Struct_0204719c table;
};

struct Struct_ov011_02185ea4_2 {
    void* magic;
    char pad0[0x20 - 4];
    Struct_ov011_02185ea4 header;
    char pad1[0xb4 - 0x20 - 0x5c];
};

// USA: func_ov011_02185ea4
extern "C" ARM int func_ov011_02185ea4(struct Struct_ov011_02185ea4_3* obj) {
    int tag0 = func_ov011_02184c30(&obj->a);
    int tag8 = func_ov011_02184c30(&obj->b);
    int sb;
    if (obj->mode == 2) sb = obj->extra;
    else sb = 0;
    if (sb == 0) return 0;

    int tag18 = func_ov011_02184c30(&obj->c);

    void* ctx = func_ov017_021b2164();
    void* node = func_ov011_021845f8(ctx, tag8);
    if (node == 0) return 0;

    ((SafeAllocator*)((char*)node + 4))->GetSizeWithLargestBlockRemoved();
    void* block = ((SafeAllocator*)((char*)node + 4))->Allocate(0xb4);
    if (block == 0) return 0;

    struct Struct_ov011_02185ea4_2 local;
    struct Struct_ov011_02185ea4* header = &local.header;
    local.magic = &data_ov023_021fee68;
    func_02048080((struct Struct_0204719c*)((char*)header + 0x54));
    memcpy(block, &local, sizeof(Struct_ov011_02185ea4_2));

    if (func_ov023_021fb534(block, ctx, tag0, tag8, sb, tag18) == 0) {
        func_02048080(&local.header.table);
        return 0;
    }

    void* list = func_ov011_021849c8(ctx);
    func_ov023_021f67ac((struct Struct_ov004_0215c30c*)list, (struct Struct_ov004_0215c30c_2*)block);
    func_02048080(&local.header.table);
    return 1;
}
