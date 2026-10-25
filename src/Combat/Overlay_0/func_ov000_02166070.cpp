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

ModelEntry* SearchWithComparator0206f4f0(BinarySearchByComparatorStruct*, int);
void SetFlag0x400Reset020484d0(void*);
void VramState_Restore(char*);
void VramState_Save(char*);
void ClearEightWords_0203dafc(struct Struct_203dafc*);
ModelNames* SearchWithLow15Comparator02070fd0(struct Container02070e60*, int);
void RunOverlayScript0216d1c4(int, struct StreamHeader*, int, int*);
void InitObjectFields020484f8(Object3D*, Input020484f8*);
void VramState_Rewind(struct Foo0207df50*);
extern "C" void _ZN8Object3D10SetField78Et(Object3D*, unsigned int);
extern "C" void _ZN8Object3D10SetField7aEt(Object3D*, unsigned int);
extern "C" void VramState_Reserve(char*, int, int);

// USA: func_ov000_02166070
extern "C" ARM void func_ov000_02166070(Scene02166070* self, GPCReadPair* pair, int slot, int id, int flag, unsigned int offset) {
    CombatantRoster02166070* roster = self->roster;
    BinarySearchByComparatorStruct* search = &roster->search.table;
    SafeAllocator* alloc = &self->allocator;
    Container02070e60* names = &roster->names;
    char path[0x10];
    struct Struct_203dafc params;
    Input020484f8 input;
    unsigned int length;
    const void* filePtr;
    unsigned int fileSize;
    unsigned int modelLength;
    unsigned int animLength;
    const void* scriptPtr;
    unsigned int scriptSize;
    ModelEntry* entry = SearchWithComparator0206f4f0(search, (short)id);
    if (entry == 0) return;
    sprintf(path, data_ov000_02183a47, entry->name);
    if (!DecompressFileFromGPCByName(pair->pGPCFile, pair->machine, g_fileLoadBuffer + offset, length, 0x30000 - offset, path)) {
        pair->Reset();
        if (flag) BackgroundLoader::RemoveLockGlobal();
        return;
    }
    if (!FindFilesInNarcBySubstring(g_fileLoadBuffer + offset, data_ov000_02183a4e, &filePtr, &fileSize, 1)) {
        pair->Reset();
        if (flag) BackgroundLoader::RemoveLockGlobal();
        return;
    }
    void* model = DecompressLZ77FileIntoAllocatedSpace(*alloc, filePtr, modelLength);
    if (!FindFilesInNarcBySubstring(g_fileLoadBuffer + offset, data_ov000_02183a54, &filePtr, &fileSize, 1)) {
        pair->Reset();
        if (flag) BackgroundLoader::RemoveLockGlobal();
        return;
    }
    void* anim = DecompressLZ77FileIntoAllocatedSpace(*alloc, filePtr, animLength);
    if (!FindFilesInNarcBySubstring(g_fileLoadBuffer + offset, data_ov000_021839e2, &scriptPtr, &scriptSize, 1)) {
        scriptPtr = 0;
        scriptSize = 0;
    }
    Object3D* var17 = (Object3D*)var2->Allocate(0xb8);
    if (var17 == 0) {
        arg1->Reset();
        if (arg4) BackgroundLoader::RemoveLockGlobal();
        return;
    }
    SetFlag0x400Reset020484d0(obj);
    obj->unknown_2_ = id;
    VramState_Restore(self->tables1bc);
    ClearEightWords_0203dafc(&params);
    params.fieldTable = (int)model;
    params.fieldLength = modelLength;
    params.allocator = alloc;
    obj->LoadFromCCHROrCMOTArchive((ObjectArchiveLoadInfo*)&params, 0);
    VramState_Save(self->tables1bc);
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
    InitObjectFields020484f8(obj, &input);
    unsigned int low = (unsigned short)input.names->words;
    unsigned int high;
    _ZN8Object3D10SetField78Et(obj, (high = input.names->words >> 16, low));
    _ZN8Object3D10SetField7aEt(obj, high);
    self->models[slot] = obj;
    if (id == 0x13f || id == 0x13d || id == 0x321) {
        VramState_Rewind((struct Foo0207df50*)self->tables14c);
        VramState_Restore(self->tables14c);
        VramState_Reserve(self->tables14c, 0x800, 0);
        VramState_Reserve(self->tables14c, 0xb800, 0x400);
    }
}
