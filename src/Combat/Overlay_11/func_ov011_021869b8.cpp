#if defined(jpn)
#define CharacterCreationUI_Draw3D func_ov011_02184c30
#define R(j,u) (j)
#define data_ov005_0215cbd4 data_ov005_0215dfb4
#define data_ov005_0215cd60 data_ov005_0215e140
#define data_ov014_02189480 data_ov014_0218a2c0
#define data_ov014_02189498 data_ov014_0218a2d8
#define data_ov015_02193fe0 data_ov015_02194b20
#define data_ov015_02194564 data_ov015_02195184
#define data_ov015_02194570 data_ov015_02195190
#define data_ov015_021945a0 data_ov015_021951c0
#define data_ov015_021945d0 data_ov015_021951f0
#define data_ov024_021ff17c data_ov023_021ff17c
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

struct Struct_ov011_021869b8_5 {
    TaggedNumber02184c30 a;
    TaggedNumber02184c30 b;
    TaggedNumber02184c30 c;
    TaggedNumber02184c30 d;
    TaggedNumber02184c30 e;
};

extern "C" int CharacterCreationUI_Draw3D(struct TaggedNumber02184c30* v);
extern "C" ARM void* func_ov017_021b2164(void);
extern "C" ARM void* func_ov011_021845f8(void* ctx, int v);
extern "C" ARM void* func_ov011_021849c8(void* ctx);

struct Struct_ov011_021869b8 {
    char pad[0xe8];
    int (*fn)(void*);
};
struct Struct_ov011_021869b8_2 {
    struct Struct_ov011_021869b8* unknown_0_;
};
extern "C" ARM struct Struct_ov011_021869b8_2* func_ov023_021f6880(void* list, int v);

extern "C" ARM int func_ov023_021fbd00(void* obj, void* ctx, int a0, int a1, int a2, int a5,
                                       unsigned char a6);

extern "C" void* KeyTable_Construct(void* p);
extern "C" void* func_020df80c(void* p);
extern "C" void SpriteContext_Init(char* obj);
extern "C" void SpriteContext_Destroy(void* obj);

struct Struct_ov004_0215c30c;
struct Struct_ov004_0215c30c_2;
extern "C" void func_ov023_021f67ac(struct Struct_ov004_0215c30c* head, struct Struct_ov004_0215c30c_2* node);

extern int data_ov024_021ff17c;

struct Struct_ov011_021869b8_3 {
    SafeAllocator a0;
    SafeAllocator a1;
    SafeAllocator a2;
    char unknown_3c_[0x54 - 0x3c];
    char m54[0x6c - 0x54];
    char unknown_6c_[0x7c - 0x6c];
    char unknown_7c_[0x8c - 0x7c];
    char m8c[0xa4 - 0x8c];
    char ma4[R(0x128 - 0xa4, 0x12c - 0xa4)];
    char m12c[R(0x718 - 0x128, 0x79c - 0x12c)];
};

struct Struct_ov011_021869b8_4 {
    void* unknown_0_;
    char pad4[0x20 - 4];
    Struct_ov011_021869b8_3 sub;
};

// USA: func_ov011_021869b8
extern "C" ARM int func_ov011_021869b8(struct Struct_ov011_021869b8_5* obj, int argc) {
    struct Struct_ov011_021869b8_4 local;
    unsigned char flag;
    void* ctx;
    void* node;
    void* block;
    int extra;
    int tag18;
    struct Struct_ov011_021869b8_3* sub;
    int tag8;
    int tag10;
    int tag0;
    struct Struct_ov011_021869b8_2* e2;
    void* list;

    tag0 = CharacterCreationUI_Draw3D(&obj->a);
    tag8 = CharacterCreationUI_Draw3D(&obj->b);
    tag10 = CharacterCreationUI_Draw3D(&obj->c);
    tag18 = CharacterCreationUI_Draw3D(&obj->d);

    flag = 0;
    if (argc - 4) flag = (unsigned char)CharacterCreationUI_Draw3D(&obj->e);

    ctx = func_ov017_021b2164();
    node = func_ov011_021845f8(ctx, tag8);
    if (node == 0) return 0;

    ((SafeAllocator*)((char*)node + 4))->GetSizeWithLargestBlockRemoved();
    block = ((SafeAllocator*)((char*)node + 4))->Allocate(R(0x738, 0x7bc));
    if (block == 0) return 0;

    extra = 0;
    list = func_ov011_021849c8(ctx);
    e2 = func_ov023_021f6880(list, tag18);
    if (e2 != 0) extra = e2->unknown_0_->fn(e2);

    sub = &local.sub;
    local.unknown_0_ = &data_ov024_021ff17c;
    sub->a0.ResetAllocatorPointer();
    sub->a1.ResetAllocatorPointer();
    sub->a2.ResetAllocatorPointer();
    KeyTable_Construct(sub->m54);
    func_020df80c(sub->unknown_6c_);
    func_020df80c(sub->unknown_7c_);
    KeyTable_Construct(sub->m8c);
    KeyTable_Construct(sub->ma4);
    SpriteContext_Init(sub->m12c);
    memcpy(block, &local, sizeof(Struct_ov011_021869b8_4));

    if (func_ov023_021fbd00(block, ctx, tag0, tag8, tag10, extra, flag) == 0) {
        SpriteContext_Destroy(local.sub.m12c);
        return 0;
    }
    func_ov023_021f67ac((struct Struct_ov004_0215c30c*)list, (struct Struct_ov004_0215c30c_2*)block);
    SpriteContext_Destroy(local.sub.m12c);
    return 1;
}
