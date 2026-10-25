#if defined(jpn)
#define CharacterCreationUI_Draw3D _Z28GetTaggedValueAsInt_02184c30P20TaggedNumber02184c30
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

struct Struct_ov011_02184c30 {
    int unknown_0_;
    union { int unknown_0_; float unknown1_0_; } unknown_4_;
};

struct Struct_ov011_021869b8_5 {
    Struct_ov011_02184c30 unknown_0_;
    Struct_ov011_02184c30 unknown_8_;
    Struct_ov011_02184c30 unknown_10_;
    Struct_ov011_02184c30 unknown_18_;
    Struct_ov011_02184c30 unknown_20_;
};

extern "C" int CharacterCreationUI_Draw3D(struct TaggedNumber02184c30* v);
extern "C" ARM void* func_ov017_021b2164(void);
extern "C" ARM void* func_ov011_021845f8(void* arg0, int arg1);
extern "C" ARM void* func_ov011_021849c8(void* arg0);

struct Struct_ov011_021869b8 {
    char unknown_0_[0xe8];
    int (*unknown_e8_)(void*);
};
struct Struct_ov011_021869b8_2 {
    struct Struct_ov011_021869b8* unknown_0_;
};
extern "C" ARM struct Struct_ov011_021869b8_2* func_ov023_021f6880(void* arg0, int arg1);

extern "C" ARM int func_ov023_021fbd00(void* arg0, void* arg1, int arg2, int arg3, int arg4, int arg5,
                                       unsigned char arg6);

void* ResetAndReturnSelf020dfc2c(void* p);
void* ZeroInitReturn020df80c(void* p);
void SpriteContext_Init(char* obj);
void SpriteContext_Destroy(void* obj);

struct Struct_ov004_0215c30c;
struct Struct_ov004_0215c30c_2;
extern "C" void func_ov023_021f67ac(struct Struct_ov004_0215c30c* arg0, struct Struct_ov004_0215c30c_2* arg1);

extern int data_ov024_021ff17c;

struct Struct_ov011_021869b8_3 {
    SafeAllocator unknown_0_;
    SafeAllocator unknown_14_;
    SafeAllocator unknown_28_;
    char unknown_3c_[0x54 - 0x3c];
    char unknown_54_[0x6c - 0x54];
    char unknown_6c_[0x7c - 0x6c];
    char unknown_7c_[0x8c - 0x7c];
    char unknown_8c_[0xa4 - 0x8c];
    char unknown_a4_[R(0x128 - 0xa4, 0x12c - 0xa4)];
    char unknown_12c_[R(0x718 - 0x128, 0x79c - 0x12c)];
};

struct Struct_ov011_021869b8_4 {
    void* unknown_0_;
    char unknown_4_[0x20 - 4];
    Struct_ov011_021869b8_3 unknown_20_;
};

// USA: func_ov011_021869b8
extern "C" ARM int func_ov011_021869b8(struct Struct_ov011_021869b8_5* arg0, int arg1) {
    struct Struct_ov011_021869b8_4 var0;
    unsigned char var1;
    void* var2;
    void* var3;
    void* var4;
    int var5;
    int var6;
    struct Struct_ov011_021869b8_3* var7;
    int var8;
    int var9;
    int var10;
    struct Struct_ov011_021869b8_2* var11;
    void* var12;

    tag0 = CharacterCreationUI_Draw3D(&obj->a);
    tag8 = CharacterCreationUI_Draw3D(&obj->b);
    tag10 = CharacterCreationUI_Draw3D(&obj->c);
    tag18 = CharacterCreationUI_Draw3D(&obj->d);

    flag = 0;
    if (argc - 4) flag = (unsigned char)CharacterCreationUI_Draw3D(&obj->e);

    var2 = func_ov017_021b2164();
    var3 = func_ov011_021845f8(var2, var8);
    if (var3 == 0) return 0;

    ((SafeAllocator*)((char*)var3 + 4))->GetSizeWithLargestBlockRemoved();
    var4 = ((SafeAllocator*)((char*)var3 + 4))->Allocate(R(0x738, 0x7bc));
    if (var4 == 0) return 0;

    var5 = 0;
    var12 = func_ov011_021849c8(var2);
    var11 = func_ov023_021f6880(var12, var6);
    if (var11 != 0) var5 = var11->unknown_0_->unknown_e8_(var11);

    sub = &local.sub;
    local.vtable = &data_ov024_021ff17c;
    sub->a0.ResetAllocatorPointer();
    sub->a1.ResetAllocatorPointer();
    sub->a2.ResetAllocatorPointer();
    ResetAndReturnSelf020dfc2c(sub->m54);
    ZeroInitReturn020df80c(sub->m6c);
    ZeroInitReturn020df80c(sub->m7c);
    ResetAndReturnSelf020dfc2c(sub->m8c);
    ResetAndReturnSelf020dfc2c(sub->ma4);
    SpriteContext_Init(sub->m12c);
    memcpy(block, &local, sizeof(Buf021869b8));

    if (func_ov023_021fbd00(block, ctx, tag0, tag8, tag10, extra, flag) == 0) {
        SpriteContext_Destroy(local.sub.m12c);
        return 0;
    }
    AppendNodeToList_021f67ac((struct ListHead_021f67ac*)list, (struct ListNode_021f67ac*)block);
    SpriteContext_Destroy(local.sub.m12c);
    return 1;
}
