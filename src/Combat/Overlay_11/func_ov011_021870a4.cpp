#if defined(jpn)
#define R(j,u) (j)
#define data_ov024_021ff384 data_ov023_021fe620
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

struct TaggedNumber02184c30;
extern "C" int func_ov011_02184c30(struct TaggedNumber02184c30* v);

extern "C" void* func_ov017_021b2164(void);
extern "C" void* func_ov011_021845f8(void* ctx, unsigned int id);
extern "C" void* func_ov011_021849c8(void*);
extern "C" int func_ov023_021fc1f4(void* slot, void* ctx, int v0, int v1);

struct Struct_ov011_021870a4 {
    void* unknown_0_;
    char pad[0x2c - 4];
};
extern char data_ov024_021ff384;

struct Struct_ov004_0215c30c;
struct Struct_ov004_0215c30c_2;
extern "C" void func_ov023_021f67ac(struct Struct_ov004_0215c30c*, struct Struct_ov004_0215c30c_2*);

// USA: func_ov011_021870a4
extern "C" ARM int func_ov011_021870a4(struct TaggedNumber02184c30* arg0) {
    int v0 = func_ov011_02184c30(arg0);
    int v1 = func_ov011_02184c30((struct TaggedNumber02184c30*)((char*)arg0 + 8));

    void* ctx = func_ov017_021b2164();
    void* node = func_ov011_021845f8(ctx, v1);
    if (!node) return 0;

    ((SafeAllocator*)((char*)node + 4))->GetSizeWithLargestBlockRemoved();
    void* slot = ((SafeAllocator*)((char*)node + 4))->Allocate(0x2c);
    if (!slot) return 0;

    Struct_ov011_021870a4 tmp;
    tmp.unknown_0_ = &data_ov024_021ff384;
    memcpy(slot, &tmp, 0x2c);

    if (!func_ov023_021fc1f4(slot, ctx, v0, v1)) return 0;

    void* obj = func_ov011_021849c8(ctx);
    func_ov023_021f67ac((struct Struct_ov004_0215c30c*)obj, (struct Struct_ov004_0215c30c_2*)slot);
    return 1;
}
