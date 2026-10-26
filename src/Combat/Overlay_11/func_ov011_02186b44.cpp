#if defined(jpn)
#define R(j,u) (j)
#define data_ov024_021ff280 data_ov023_021fe520
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
extern "C" ARM int func_ov023_021fbe08(void* obj, void* script, int id, int arg3, int unk);
extern "C" void* ItemTable_Construct(void* obj);

struct Struct_ov004_0215c30c;
struct Struct_ov004_0215c30c_2;
extern "C" void func_ov023_021f67ac(struct Struct_ov004_0215c30c* head, struct Struct_ov004_0215c30c_2* node);

extern char data_ov024_021ff280;

struct Struct_ov011_02186b44 {
    int id;
    SafeAllocator allocator;
};

struct Struct_ov011_02186b44_2 {
    void* unknown_0_;
    char pad[0x20 - 4];
    SafeAllocator allocator;
    char part[0x50 - 0x34];
};

// USA: func_ov011_02186b44
extern "C" ARM int func_ov011_02186b44(struct TaggedNumber02184c30* params, int count) {
    int unk;
    int id = func_ov011_02184c30(&params[0]);
    int var2 = func_ov011_02184c30(&params[1]);
    unk = 0;
    if (count - 2 != 0)
        unk = func_ov011_02184c30(&params[2]);

    void* script = func_ov017_021b2164();
    Struct_ov011_02186b44* heap = (Struct_ov011_02186b44*)func_ov011_021845f8(script, var2);
    if (heap == 0)
        return 0;

    heap->allocator.GetSizeWithLargestBlockRemoved();
    void* object = heap->allocator.Allocate(sizeof(Struct_ov011_02186b44_2));
    if (object == 0)
        return 0;

    Struct_ov011_02186b44_2 prototype;
    prototype.unknown_0_ = &data_ov024_021ff280;
    prototype.allocator.ResetAllocatorPointer();
    ItemTable_Construct(prototype.part);
    memcpy(object, &prototype, sizeof(Struct_ov011_02186b44_2));
    if (!func_ov023_021fbe08(object, script, id, var2, unk))
        return 0;

    func_ov023_021f67ac((struct Struct_ov004_0215c30c*)func_ov011_021849c8(script), (struct Struct_ov004_0215c30c_2*)object);
    return 1;
}
