#if defined(jpn)
#define R(j,u) (j)
#define data_ov023_021fef74 data_ov023_021fe220
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

extern "C" int func_ov011_02184c30(struct TaggedNumber02184c30* v);
extern "C" ARM void* func_ov017_021b2164(void);
extern "C" ARM void* func_ov011_021845f8(void* ctx, int v);
extern "C" ARM void* func_ov011_021849c8(void* ctx);
extern "C" int func_ov023_021fba80(void*, int, int, int);

struct Struct_ov004_0215c30c;
struct Struct_ov004_0215c30c_2;
extern "C" void func_ov023_021f67ac(struct Struct_ov004_0215c30c* head, struct Struct_ov004_0215c30c_2* node);

extern char data_ov023_021fef74;

struct Struct_ov011_021866e0 {
    int id;
    SafeAllocator allocator;
};

struct Struct_ov011_021866e0_2 {
    void* unknown_0_;
    char pad[0x24 - 4];
};

// USA: func_ov011_021866e0
extern "C" ARM int func_ov011_021866e0(struct TaggedNumber02184c30* params, int count) {
    int id = func_ov011_02184c30(&params[0]);
    int var1 = func_ov011_02184c30(&params[1]);
    void* script = func_ov017_021b2164();
    Struct_ov011_021866e0* heap = (Struct_ov011_021866e0*)func_ov011_021845f8(script, var1);
    if (heap == 0)
        return 0;

    heap->allocator.GetSizeWithLargestBlockRemoved();
    void* object = heap->allocator.Allocate(sizeof(Struct_ov011_021866e0_2));
    if (object == 0)
        return 0;

    Struct_ov011_021866e0_2 prototype;
    prototype.unknown_0_ = &data_ov023_021fef74;
    memcpy(object, &prototype, sizeof(Struct_ov011_021866e0_2));
    if (!func_ov023_021fba80(object, (int)script, id, var1))
        return 0;

    func_ov023_021f67ac((struct Struct_ov004_0215c30c*)func_ov011_021849c8(script), (struct Struct_ov004_0215c30c_2*)object);
    return 1;
}
