#if defined(jpn)
#define R(j,u) (j)
#define data_ov024_021fe80c data_ov023_021fdad4
#define data_ov024_021fec60 data_ov023_021fdf18
#define data_ov024_021fed64 data_ov023_021fe018
#define func_ov023_021f8cf4 func_ov023_021f8180
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

struct TaggedNumber02184c30;
extern "C" int func_ov011_02184c30(struct TaggedNumber02184c30* v);

extern "C" void* func_ov017_021b2164(void);
extern "C" void* func_ov011_021845f8(void* ctx, int v);
extern "C" void* func_ov011_021849c8(void*);
extern "C" int func_ov023_021fb2b0(void* obj, void* ctx, int arg2, int arg3, int arg4, int arg5);

struct Struct_ov011_02185dd4 {
    void* unknown_0_;
    char pad[0x2c - 4];
};
extern char data_ov024_021fed64;

struct Struct_ov004_0215c30c;
struct Struct_ov004_0215c30c_2;
extern "C" void func_ov023_021f67ac(struct Struct_ov004_0215c30c*, struct Struct_ov004_0215c30c_2*);

// USA: func_ov011_02185dd4
extern "C" ARM int func_ov011_02185dd4(struct TaggedNumber02184c30* arg0) {
    int v0 = func_ov011_02184c30(arg0);
    int v1 = func_ov011_02184c30((struct TaggedNumber02184c30*)((char*)arg0 + 8));
    int v2 = func_ov011_02184c30((struct TaggedNumber02184c30*)((char*)arg0 + 0x10));
    int v3 = func_ov011_02184c30((struct TaggedNumber02184c30*)((char*)arg0 + 0x18));

    void* ctx = func_ov017_021b2164();
    void* node = func_ov011_021845f8(ctx, v1);
    if (!node) return 0;

    ((SafeAllocator*)((char*)node + 4))->GetSizeWithLargestBlockRemoved();
    void* block = ((SafeAllocator*)((char*)node + 4))->Allocate(0x2c);
    if (!block) return 0;

    Struct_ov011_02185dd4 tmp;
    tmp.unknown_0_ = &data_ov024_021fed64;
    memcpy(block, &tmp, 0x2c);

    if (!func_ov023_021fb2b0(block, ctx, v0, v1, v2, v3)) return 0;

    void* obj = func_ov011_021849c8(ctx);
    func_ov023_021f67ac((struct Struct_ov004_0215c30c*)obj, (struct Struct_ov004_0215c30c_2*)block);
    return 1;
}
