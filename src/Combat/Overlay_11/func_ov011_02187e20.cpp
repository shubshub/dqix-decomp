#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

struct Struct_ov011_02184c30 {
    int unknown_0_;
    union { int unknown_0_; float unknown1_0_; } unknown_4_;
};

struct Struct_ov011_02187e20 {
    Struct_ov011_02184c30 unknown_0_;
    Struct_ov011_02184c30 unknown_8_;
};

extern "C" int func_ov011_02184c30(struct Struct_ov011_02184c30* arg0);
extern "C" ARM void* func_ov017_021b2164(void);
extern "C" ARM void* func_ov011_021845f8(void* ctx, int v);
extern "C" ARM void* func_ov011_021849c8(void* ctx);
extern "C" ARM int func_ov004_02167820(void* self, void* param1, int param2, int param3);
void* ResetAndReturnSelf020dfc2c(void* p);
void SpriteContext_Init(char* obj);
void SpriteContext_Destroy(void* obj);

struct Struct_ov004_0215c30c;
struct Struct_ov004_0215c30c_2;
extern "C" void func_ov023_021f67ac(struct Struct_ov004_0215c30c* arg0, struct Struct_ov004_0215c30c_2* arg1);

extern int data_ov004_021705f8;

struct Struct_ov011_02187e20_2 {
    void* unknown_0_;
    char unknown_4_[0x20 - 4];
    SafeAllocator unknown_20_;
    char unknown_34_[0x94 - 0x34];
    char unknown_94_[0x118 - 0x94];
};

// USA: func_ov011_02187e20
extern "C" ARM int func_ov011_02187e20(struct Struct_ov011_02187e20* arg0) {
    int var0 = func_ov011_02184c30(&arg0->unknown_0_);
    int var1 = func_ov011_02184c30(&arg0->unknown_8_);

    void* var2 = func_ov017_021b2164();
    void* var3 = func_ov011_021845f8(var2, var1);
    if (var3 == 0) return 0;

    ((SafeAllocator*)((char*)var3 + 4))->GetSizeWithLargestBlockRemoved();
    void* var4 = ((SafeAllocator*)((char*)var3 + 4))->Allocate(0x118);
    if (var4 == 0) return 0;

    struct Buf02187e20 local;
    local.vtable = &data_ov004_021705f8;
    local.alloc.ResetAllocatorPointer();
    char* base = local.state;
    ResetAndReturnSelf020dfc2c(base + 4);
    SpriteContext_Init(base + 0x60);
    memcpy(block, &local, sizeof(Buf02187e20));

    if (func_ov004_02167820(block, ctx, tag0, tag8) == 0) {
        SpriteContext_Destroy(local.sub);
        return 0;
    }

    void* list = func_ov011_021849c8(ctx);
    AppendNodeToList_021f67ac((struct ListHead_021f67ac*)list, (struct ListNode_021f67ac*)block);
    SpriteContext_Destroy(local.sub);
    return 1;
}
