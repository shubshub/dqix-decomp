#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/GPC.h"
#include "Filesystem/FileIO.h"
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"
#include "Resource/MonsterDefinition.h"

#if defined(jpn)
#define data_ov000_02183a47 data_ov000_02184b7a
#define data_ov000_02183a4e data_ov000_02184b81
#define data_ov000_02183a54 data_ov000_02184b87
#endif

extern char data_ov000_02183a47[];
extern char data_ov000_02183a4e[];
extern char data_ov000_02183a54[];
extern char data_ov000_021839e2[];
extern char g_stringFormat[];

struct Struct_02013fb4;
struct Struct_02070b6c_3 { unsigned char unknown_0_[0xc]; };
struct Struct_0203d028_11 {
    int unknown_0_;
    int unknown_4_;
    int unknown_8_;
    SafeAllocator* unknown_c_;
    int unknown_10_;
    int unknown_14_;
    int unknown_18_;
    int unknown_1c_;
};
struct Struct_0203d028;

struct Struct_ov000_02166070_3 { int unknown_0_; const char* unknown_4_; };
struct Struct_ov000_02166070_4 {
    unsigned char unknown_0_[0x14]; unsigned int unknown_14_; unsigned char unknown_18_[0x14]; char unknown_2c_[1]; };
struct Struct_020484f8_2 { Struct_ov000_02166070_3* unknown_0_; Struct_ov000_02166070_4* unknown_4_; int unknown_8_; };

struct Struct_ov000_02166070 {
    unsigned char unknown_0_[0x678];
    Struct_0206ef48 unknown_678_;
    Struct_02070b6c_3 unknown_684_;
};
struct Struct_ov000_02166070_2 {
    unsigned char unknown_0_[0x44];
    SafeAllocator unknown_44_;
#if defined(jpn)
    unsigned char unknown_58_[0x138 - 0x44 - sizeof(SafeAllocator)];
    char unknown_14c_[0x70];
    char unknown_1bc_[0x21c - 0x1a8];
    Struct_ov000_02166070* unknown_2a0_;
    unsigned char unknown_220_[0xe34 - 0x220];
#else
    unsigned char unknown1_58_[0x14c - 0x44 - sizeof(SafeAllocator)];
    char unknown_14c_[0x70];
    char unknown_1bc_[0x2a0 - 0x1bc];
    Struct_ov000_02166070* unknown_2a0_;
    unsigned char unknown_2a4_[0xeb8 - 0x2a4];
#endif
    Object3D* unknown_eb8_[4];
};

extern "C" Struct_ov000_02166070_3* func_0206f4f0(Struct_0206f01c_2*, int);
extern "C" void func_020484d0(void*);
extern "C" void func_0207df90(char*);
extern "C" void func_0207dfac(char*);
extern "C" void func_0203dafc(struct Struct_0203d028_11*);
extern "C" Struct_ov000_02166070_4* func_02070fd0(struct Struct_02070b6c_3*, int);
extern "C" void func_ov000_0216d1c4(int, struct Struct_02013fb4*, int, int*);
extern "C" void func_020484f8(Object3D*, Struct_020484f8_2*);
extern "C" void func_0207df50(struct Struct_0203d028*);
extern "C" void _ZN8Object3D10SetField78Et(Object3D*, unsigned int);
extern "C" void _ZN8Object3D10SetField7aEt(Object3D*, unsigned int);
extern "C" void func_0207de48(char*, int, int);

// USA: func_ov000_02166070
extern "C" ARM void func_ov000_02166070(Struct_ov000_02166070_2* arg0, GPCReadPair* arg1, int arg2, int arg3, int arg4, unsigned int arg5) {
    Struct_ov000_02166070* var0 = arg0->unknown_2a0_;
    Struct_0206f01c_2* var1 = &var0->unknown_678_.unknown_0_;
    SafeAllocator* var2 = &arg0->unknown_44_;
    Struct_02070b6c_3* var3 = &var0->unknown_684_;
    char var4[0x10];
    struct Struct_0203d028_11 var5;
    Struct_020484f8_2 var6;
    unsigned int var7;
    const void* var8;
    unsigned int var9;
    unsigned int var10;
    unsigned int var11;
    const void* var12;
    unsigned int var13;
    Struct_ov000_02166070_3* var14 = func_0206f4f0(var1, (short)arg3);
    if (var14 == 0) return;
    sprintf(var4, data_ov000_02183a47, var14->unknown_4_);
    if (!DecompressFileFromGPCByName(arg1->pGPCFile, arg1->machine, data_0211e33c + arg5, var7, 0x30000 - arg5, var4)) {
        arg1->Reset();
        if (arg4) BackgroundLoader::RemoveLockGlobal();
        return;
    }
    if (!FindFilesInNarcBySubstring(data_0211e33c + arg5, data_ov000_02183a4e, &var8, &var9, 1)) {
        arg1->Reset();
        if (arg4) BackgroundLoader::RemoveLockGlobal();
        return;
    }
    void* var15 = DecompressLZ77FileIntoAllocatedSpace(*var2, var8, var10);
    if (!FindFilesInNarcBySubstring(data_0211e33c + arg5, data_ov000_02183a54, &var8, &var9, 1)) {
        arg1->Reset();
        if (arg4) BackgroundLoader::RemoveLockGlobal();
        return;
    }
    void* var16 = DecompressLZ77FileIntoAllocatedSpace(*var2, var8, var11);
    if (!FindFilesInNarcBySubstring(data_0211e33c + arg5, data_ov000_021839e2, &var12, &var13, 1)) {
        var12 = 0;
        var13 = 0;
    }
    Object3D* var17 = (Object3D*)var2->Allocate(0xb8);
    if (var17 == 0) {
        arg1->Reset();
        if (arg4) BackgroundLoader::RemoveLockGlobal();
        return;
    }
    SetFlag0x400Reset020484d0(obj);
    obj->unknown_2_ = id;
    RestorePairTables0207df90(self->tables1bc);
    ClearEightWords_0203dafc(&params);
    params.fieldTable = (int)model;
    params.fieldLength = modelLength;
    params.allocator = alloc;
    obj->LoadFromCCHROrCMOTArchive((ObjectArchiveLoadInfo*)&params, 0);
    BackupPairTables0207dfac(self->tables1bc);
    ClearEightWords_0203dafc(&params);
    params.fieldTable = (int)anim;
    params.fieldLength = animLength;
    params.allocator = alloc;
    obj->LoadFromCCHROrCMOTArchive((ObjectArchiveLoadInfo*)&params, 0);
    input.names = SearchWithLow15Comparator02070fd0(names, id);
    input.entry = SearchWithComparator0206f4f0(search, id << 16 >> 16);
    sprintf(input.names->name, g_stringFormat, input.entry->id);
    if (scriptPtr == 0) {
        input.script = 0;
    } else {
        func_ov000_0216d1c4((int)var2, (Struct_02013fb4*)var12, var13, &var6.unknown_8_);
    }
    func_020484f8(var17, &var6);
    unsigned int var18 = (unsigned short)var6.unknown_4_->unknown_14_;
    unsigned int var19;
    _ZN8Object3D10SetField78Et(var17, (var19 = var6.unknown_4_->unknown_14_ >> 16, var18));
    _ZN8Object3D10SetField7aEt(var17, var19);
    arg0->unknown_eb8_[arg2] = var17;
    if (arg3 == 0x13f || arg3 == 0x13d || arg3 == 0x321) {
        func_0207df50((struct Struct_0203d028*)arg0->unknown_14c_);
        func_0207df90(arg0->unknown_14c_);
        func_0207de48(arg0->unknown_14c_, 0x800, 0);
        func_0207de48(arg0->unknown_14c_, 0xb800, 0x400);
    }
}
