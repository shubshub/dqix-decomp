#if defined(jpn)
#define R(j,u) (j)
#define _Z27ScaleStatsIfType12_021f6f10Pv _Z27CheckAnyBuffBelow2_021f5c80P16Wrapper_021f5c80iiPiPs
#define _Z19CharacterModel_InitPv func_ov023_021e5080
#define data_ov023_021ff5b4 data_ov023_021fe83c
#define func_ov023_021fc518 func_ov023_021fb810
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"
#include "Resource/GameResources.h"

struct Struct_ov011_02184c30 {
    int unknown_0_;
    union { int unknown_0_; float unknown1_0_; } unknown_4_;
};

extern "C" int func_ov011_02184c30(struct Struct_ov011_02184c30* arg0);
extern "C" ARM void* func_ov017_021b2164(void);
extern "C" ARM void* func_ov011_021845f8(void* ctx, int v);
extern "C" ARM void* func_ov011_021849c8(void* ctx);
extern "C" ARM int func_ov023_021fc518(void* obj, void* script, int id, int heapId, int unk2, int unk);
void CharacterModel_Init(void* model);

struct Struct_ov004_0215c30c;
struct Struct_ov004_0215c30c_2;
extern "C" void func_ov023_021f67ac(struct Struct_ov004_0215c30c* arg0, struct Struct_ov004_0215c30c_2* arg1);

extern char data_ov023_021ff5b4;

struct Struct_ov011_02187720 {
    int unknown_0_;
    SafeAllocator unknown_4_;
};

struct Struct_ov011_02187720_2 {
    char unknown_0_[0x6b8];
    SafeAllocator unknown_6b8_[10];
    SafeAllocator unknown_780_;
    char unknown_794_[0xc20 - 0x794];
};

struct Struct_ov011_02187720_3 {
    void* unknown_0_;
    char unknown_4_[0x1c];
    Struct_ov011_02187720_2 unknown_20_[2];
    char unknown_1860_[0x10];
};

// USA: func_ov011_02187720
extern "C" ARM int func_ov011_02187720(struct Struct_ov011_02184c30* arg0, int arg1) {
    Struct_ov011_02187720_3 var0;
    void* var1;
    SafeAllocator* var2;
    Struct_ov011_02187720_2* var3;
    int var4;
    Struct_ov011_02187720* var5;
    void* var6;
    int var7;
    int var8;
    int var9;

    var9 = func_ov011_02184c30(&arg0[0]);
    var7 = func_ov011_02184c30(&arg0[1]);
    var8 = func_ov011_02184c30(&arg0[2]);
    func_ov011_02184c30(&arg0[3]);
    var6 = func_ov017_021b2164();
    var5 = (Struct_ov011_02187720*)func_ov011_021845f8(var6, var7);
    if (var5 == 0)
        return 0;

    var5->unknown_4_.GetSizeWithLargestBlockRemoved();
    var4 = (*(int**)((char*)GetGameResources() + R(0x392c, 0x3b4c)))[0x13];
    var1 = var5->unknown_4_.Allocate(sizeof(Struct_ov011_02187720_3));
    if (var1 == 0)
        return 0;

    var0.unknown_0_ = &data_ov023_021ff5b4;
    var3 = var0.unknown_20_;
    do {
        var2 = var3->unknown_6b8_;
        do {
            allocator->ResetAllocatorPointer();
            allocator++;
        } while (allocator < model->allocators + 10);
        model->animationAllocator.ResetAllocatorPointer();
        CharacterModel_Init(model);
        model++;
    } while (model < prototype.models + 2);
    memcpy(object, &prototype, sizeof(MenuObject02187720));
    if (!func_ov023_021fc518(object, script, id, heapId, unk2, unk))
        return 0;

    func_ov023_021f67ac((struct Struct_ov004_0215c30c*)func_ov011_021849c8(var6), (struct Struct_ov004_0215c30c_2*)var1);
    return 1;
}
