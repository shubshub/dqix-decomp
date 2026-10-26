#if defined(jpn)
#define R(j,u) (j)
#define data_ov023_021ff4b0 data_ov023_021fe73c
#define func_ov023_021fc408 func_ov023_021fb700
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

struct TaggedNumber02184c30;
extern "C" int func_ov011_02184c30(struct TaggedNumber02184c30* v);

extern "C" void* func_ov017_021b2164(void);
extern "C" void* func_ov011_021845f8(void* node, unsigned int id);
extern "C" void* func_ov011_021849c8(void*);
extern "C" int func_ov023_021fc408(void* obj, void* unused, int b, int c, int p5, int p6, int p7, int p8, int p9, int p10);

struct Struct_ov011_021871b8 {
    void* unknown_0_;
    char pad[0x30 - 4];
};
extern char data_ov023_021ff4b0;

struct Struct_ov004_0215c30c;
struct Struct_ov004_0215c30c_2;
extern "C" void func_ov023_021f67ac(struct Struct_ov004_0215c30c*, struct Struct_ov004_0215c30c_2*);

// USA: func_ov011_021871b8
extern "C" ARM int func_ov011_021871b8(struct TaggedNumber02184c30* arg0) {
    int v0 = func_ov011_02184c30(arg0);
    int v1 = func_ov011_02184c30((struct TaggedNumber02184c30*)((char*)arg0 + 8));
    int v2 = func_ov011_02184c30((struct TaggedNumber02184c30*)((char*)arg0 + 0x10));
    int v3 = func_ov011_02184c30((struct TaggedNumber02184c30*)((char*)arg0 + 0x18));
    int v4 = func_ov011_02184c30((struct TaggedNumber02184c30*)((char*)arg0 + 0x20));
    int v5 = func_ov011_02184c30((struct TaggedNumber02184c30*)((char*)arg0 + 0x28));
    int v6 = func_ov011_02184c30((struct TaggedNumber02184c30*)((char*)arg0 + 0x30));
    int v7 = func_ov011_02184c30((struct TaggedNumber02184c30*)((char*)arg0 + 0x38));

    void* base = func_ov017_021b2164();
    void* node = func_ov011_021845f8(base, v1);
    if (!node) return 0;

    ((SafeAllocator*)((char*)node + 4))->GetSizeWithLargestBlockRemoved();
    void* slot = ((SafeAllocator*)((char*)node + 4))->Allocate(0x30);
    if (!slot) return 0;

    Struct_ov011_021871b8 tmp;
    tmp.unknown_0_ = &data_ov023_021ff4b0;
    memcpy(slot, &tmp, 0x30);

    if (!func_ov023_021fc408(slot, base, v0, v1, v2, v3, v4, v5, v6, v7)) return 0;

    void* obj = func_ov011_021849c8(base);
    func_ov023_021f67ac((struct Struct_ov004_0215c30c*)obj, (struct Struct_ov004_0215c30c_2*)slot);
    return 1;
}
