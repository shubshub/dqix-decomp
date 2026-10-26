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

struct StreamHeader;
struct Struct_02070b6c_3 { unsigned char data[0xc]; };
struct Struct_203dafc {
    int field0;
    int unknown_4_;
    int unknown_8_;
    SafeAllocator* allocator;
    int field10;
    int field14;
    int field18;
    int field1c;
};
struct Foo0207df50;

struct Struct_ov000_02166070_3 { int id; const char* name; };
struct Struct_ov000_02166070_4 {
    unsigned char unknown_0_[0x14]; unsigned int words; unsigned char unknown_18_[0x14]; char name[1]; };
struct Struct_020484f8_2 { Struct_ov000_02166070_3* entry; Struct_ov000_02166070_4* names; int script; };

struct Struct_ov000_02166070 {
    unsigned char unknown_0_[0x678];
    Struct_0206ef48 search;
    Struct_02070b6c_3 names;
};
struct Struct_ov000_02166070_2 {
    unsigned char unknown_0_[0x44];
    SafeAllocator allocator;
#if defined(jpn)
    unsigned char unknown_58_[0x138 - 0x44 - sizeof(SafeAllocator)];
    char tables14c[0x70];
    char tables1bc[0x21c - 0x1a8];
    Struct_ov000_02166070* roster;
    unsigned char unknown_220_[0xe34 - 0x220];
#else
    unsigned char unknown1_58_[0x14c - 0x44 - sizeof(SafeAllocator)];
    char tables14c[0x70];
    char tables1bc[0x2a0 - 0x1bc];
    Struct_ov000_02166070* roster;
    unsigned char unknown_2a4_[0xeb8 - 0x2a4];
#endif
    Object3D* models[4];
};

extern "C" Struct_ov000_02166070_3* func_0206f4f0(Struct_0206f01c_2*, int);
extern "C" void func_020484d0(void*);
extern "C" void VramState_Restore(char*);
extern "C" void VramState_Save(char*);
extern "C" void func_0203dafc(struct Struct_203dafc*);
extern "C" Struct_ov000_02166070_4* func_02070fd0(struct Struct_02070b6c_3*, int);
extern "C" void func_ov000_0216d1c4(int, struct StreamHeader*, int, int*);
extern "C" void func_020484f8(Object3D*, Struct_020484f8_2*);
extern "C" void VramState_Rewind(struct Foo0207df50*);
extern "C" void _ZN8Object3D13SetSoundGroupEt(Object3D*, unsigned int);
extern "C" void _ZN8Object3D15SetSoundArchiveEt(Object3D*, unsigned int);
extern "C" void VramState_Reserve(char*, int, int);

// USA: func_ov000_02166070
extern "C" ARM void func_ov000_02166070(Struct_ov000_02166070_2* self, GPCReadPair* pair, int slot, int id, int flag, unsigned int offset) {
    Struct_ov000_02166070* roster = self->roster;
    Struct_0206f01c_2* search = &roster->search.table;
    SafeAllocator* alloc = &self->allocator;
    Struct_02070b6c_3* names = &roster->names;
    char path[0x10];
    struct Struct_203dafc params;
    Struct_020484f8_2 input;
    unsigned int length;
    const void* filePtr;
    unsigned int fileSize;
    unsigned int var10;
    unsigned int var11;
    const void* scriptPtr;
    unsigned int scriptSize;
    Struct_ov000_02166070_3* entry = func_0206f4f0(search, (short)id);
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
    void* model = DecompressLZ77FileIntoAllocatedSpace(*alloc, filePtr, var10);
    if (!FindFilesInNarcBySubstring(g_fileLoadBuffer + offset, data_ov000_02183a54, &filePtr, &fileSize, 1)) {
        pair->Reset();
        if (flag) BackgroundLoader::RemoveLockGlobal();
        return;
    }
    void* anim = DecompressLZ77FileIntoAllocatedSpace(*alloc, filePtr, var11);
    if (!FindFilesInNarcBySubstring(g_fileLoadBuffer + offset, data_ov000_021839e2, &scriptPtr, &scriptSize, 1)) {
        scriptPtr = 0;
        scriptSize = 0;
    }
    Object3D* obj = (Object3D*)alloc->Allocate(0xb8);
    if (obj == 0) {
        pair->Reset();
        if (flag) BackgroundLoader::RemoveLockGlobal();
        return;
    }
    func_020484d0(obj);
    obj->unknown_2_ = id;
    VramState_Restore(self->tables1bc);
    func_0203dafc(&params);
    params.unknown_4_ = (int)model;
    params.unknown_8_ = var10;
    params.allocator = alloc;
    obj->LoadFromCCHROrCMOTArchive((ObjectArchiveLoadInfo*)&params, 0);
    VramState_Save(self->tables1bc);
    func_0203dafc(&params);
    params.unknown_4_ = (int)anim;
    params.unknown_8_ = var11;
    params.allocator = alloc;
    obj->LoadFromCCHROrCMOTArchive((ObjectArchiveLoadInfo*)&params, 0);
    input.names = func_02070fd0(names, id);
    input.entry = func_0206f4f0(search, id << 16 >> 16);
    sprintf(input.names->name, g_stringFormat, input.entry->id);
    if (scriptPtr == 0) {
        input.script = 0;
    } else {
        func_ov000_0216d1c4((int)alloc, (StreamHeader*)scriptPtr, scriptSize, &input.script);
    }
    func_020484f8(obj, &input);
    unsigned int low = (unsigned short)input.names->words;
    unsigned int high;
    _ZN8Object3D13SetSoundGroupEt(obj, (high = input.names->words >> 16, low));
    _ZN8Object3D15SetSoundArchiveEt(obj, high);
    self->models[slot] = obj;
    if (id == 0x13f || id == 0x13d || id == 0x321) {
        VramState_Rewind((struct Foo0207df50*)self->tables14c);
        VramState_Restore(self->tables14c);
        VramState_Reserve(self->tables14c, 0x800, 0);
        VramState_Reserve(self->tables14c, 0xb800, 0x400);
    }
}
