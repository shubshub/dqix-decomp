#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

struct TaggedNumber02184c30 {
    int type;
    union { int i; float f; } value;
};

struct Struct_ov011_02187a14_2 {
    TaggedNumber02184c30 a;
    TaggedNumber02184c30 b;
    TaggedNumber02184c30 c;
};

extern "C" int func_ov011_02184c30(struct TaggedNumber02184c30* v);
extern "C" ARM void* func_ov017_021b2164(void);
extern "C" ARM void* func_ov011_021849c8(void* ctx);
extern "C" ARM void* func_ov023_021f6880(void* obj, int v);
extern "C" ARM int func_ov023_021f6f10(void* obj);
extern "C" ARM void* func_ov011_021845f8(void* ctx, int v);

struct Struct_ov011_02185020_3;
#if defined(jpn)
extern "C" ARM Struct_ov011_02185020_3* func_ov011_02185110(Struct_ov011_02185020_3* obj);
#else
extern "C" ARM Struct_ov011_02185020_3* func_ov011_02185110(Struct_ov011_02185020_3* obj);
#endif
#if defined(jpn)
extern "C" ARM void* func_ov011_0218513c(void* obj);
#else
extern "C" ARM void* func_ov011_0218513c(void* obj);
#endif
extern "C" ARM int func_ov023_021f6f20(void* obj, int p1, int p3, int p4, int arg4, unsigned int arg5);
extern "C" ARM void* func_ov023_021f7318(void* p);

struct Foo02048004;
extern "C" ARM void func_02048004(struct Foo02048004* src, struct Foo02048004* dst);
extern "C" ARM void func_ov023_021f7320(void* p);

struct Struct_ov004_0215c30c;
struct Struct_ov004_0215c30c_2;
extern "C" void func_ov023_021f67ac(struct Struct_ov004_0215c30c* head, struct Struct_ov004_0215c30c_2* node);

struct Struct_ov011_02187a14 {
    int words[0xac / 4];
};

// USA: func_ov011_02187a14
extern "C" ARM int func_ov011_02187a14(struct Struct_ov011_02187a14_2* obj) {
    int tag0 = func_ov011_02184c30(&obj->a);
    int tag8 = func_ov011_02184c30(&obj->b);
    int tag10 = func_ov011_02184c30(&obj->c);

    void* ctx = func_ov017_021b2164();
    void* list = func_ov011_021849c8(ctx);
    void* e2 = func_ov023_021f6880(list, tag10);
    func_ov023_021f6f10(e2);

    void* node = func_ov011_021845f8(ctx, tag8);
    if (node == 0) return 0;

    ((SafeAllocator*)((char*)node + 4))->GetSizeWithLargestBlockRemoved();
    void* block = ((SafeAllocator*)((char*)node + 4))->Allocate(0xac);
    if (block == 0) return 0;

    Struct_ov011_02187a14 local;
    func_ov011_02185110((Struct_ov011_02185020_3*)&local);
    memcpy(block, &local, sizeof(local));

    if (func_ov023_021f6f20(block, (int)ctx, tag0, tag8, 0, 0) == 0) {
        func_ov011_0218513c(&local);
        return 0;
    }

    void* p1 = func_ov023_021f7318(e2);
    void* p2 = func_ov023_021f7318(block);
    func_02048004((struct Foo02048004*)p1, (struct Foo02048004*)p2);
    func_ov023_021f7320(block);
    func_ov023_021f67ac((struct Struct_ov004_0215c30c*)list, (struct Struct_ov004_0215c30c_2*)block);
    func_ov011_0218513c(&local);
    return 1;
}
