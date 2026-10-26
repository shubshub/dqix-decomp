#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"
#include "World/Object3D.h"
#include "Filesystem/GPC.h"
extern unsigned char g_fileLoadBuffer[0x30000] __attribute__((aligned(4)));
#include "Filesystem/FileIO.h"
#include "Filesystem/BackgroundLoader.h"

struct Struct_0206f01c_2;
struct Struct_02070b6c_3;
struct Foo0207df50;
struct Struct_203dafc;

extern "C" void* func_0206f4f0(Struct_0206f01c_2*, int);
extern "C" void* func_02070fd0(Struct_02070b6c_3*, int);
extern "C" void func_0203dafc(struct Struct_203dafc*);

extern "C" void* __clear(void* dst, int count);
extern "C" void VramState_Rewind(Foo0207df50*);
extern "C" void VramState_Restore(char*);
extern "C" void VramState_Save(char*);
extern "C" void func_02079a3c(void*);
extern "C" void _ZN8Object3D15SetSoundArchiveEt(Object3D*, unsigned int);
extern "C" void SePlayer_LoadExtraArchiveB(void*, int, int);

struct Struct_ov015_0218dbec_4 {
    int value;
    int number;
    char pad8[0x14 - 8];
    unsigned int packed;
};

struct Struct_ov015_0218dbec {
    char pad0[8];
    short key;
};

struct Struct_ov015_0218dbec_2 {
    char pad0[0x64];
    char unknown_64_[0xc];
    char unknown_70_[0x1a1 - 0x70];
    unsigned char variant;
};

struct Struct_ov015_02193cf0 { unsigned int v[3]; };

struct Struct_ov015_0218dbec_3 {
    Struct_ov015_0218dbec_2* tables;
    char** unknown_4_;
    SafeAllocator* allocator;
    int selected;
    Struct_ov015_0218dbec_4* record;
    char unknown_14_[0x24 - 0x14];
    Object3D* object;
    char pad28[0x44 - 0x28];
    int animation;
};

extern char data_ov015_021940f5;
extern char data_ov015_021940fe;
extern char data_ov015_02194105;
extern char data_ov015_0219411d;
extern char data_ov015_02194123;
extern struct Struct_ov015_02193cf0 data_ov015_02193cf0;
extern int g_sePlayer;

// USA: func_ov015_0218dbec
extern "C" ARM int func_ov015_0218dbec(Struct_ov015_0218dbec_3* self, Struct_ov015_0218dbec* entry) {
    self->record = (Struct_ov015_0218dbec_4*)func_0206f4f0((Struct_0206f01c_2*)(self->tables->unknown_64_), entry->key);
    if (self->record == 0) {
        return 0;
    }

    char name[0x10];
    __clear(name, 0x10);
    self->allocator->Reset();

    int ok = 1;
    char* mgr = *self->unknown_4_;
    VramState_Rewind((Foo0207df50*)mgr);
    VramState_Restore(mgr);

    if (self->tables->variant != 0) {
        sprintf(name, &data_ov015_021940f5, self->record->number);
    } else {
        sprintf(name, &data_ov015_021940fe, self->record->number);
    }

    BackgroundLoader::AddLockGlobal();
    BackgroundLoader::FreeAllocationsGlobal();

    GPCReadPair pair;
    func_02079a3c(&pair);
    unsigned int headerSize;
    if (LoadAndDecompressGPCHeaderAndInnerFileInfo(&pair.pGPCFile, pair.machine, &data_ov015_02194105,
                                                   g_fileLoadBuffer, headerSize, 0x30000, false, 0)) {
        unsigned int fileSize;
        char* narc = (char*)g_fileLoadBuffer + headerSize;
        if (DecompressFileFromGPCByName(pair.pGPCFile, pair.machine, narc, fileSize, 0x30000 - headerSize, name)) {
            const void* found = 0;
            unsigned int var8 = 0;
            unsigned int sizeA = 0;
            unsigned int sizeB = 0;
            void* var11 = 0;
            void* var12 = 0;
            if (FindFilesInNarcBySubstring(narc, &data_ov015_0219411d, &found, &var8, 1)) {
                var11 = DecompressLZ77FileIntoAllocatedSpace(*self->allocator, found, sizeA);
            }
            if (FindFilesInNarcBySubstring(narc, &data_ov015_02194123, &found, &var8, 1)) {
                var12 = DecompressLZ77FileIntoAllocatedSpace(*self->allocator, found, sizeB);
            }
            ObjectArchiveLoadInfo loadInfo;
            if (var11 != 0) {
                func_0203dafc((Struct_203dafc*)&loadInfo);
                loadInfo.allocator = self->allocator;
                loadInfo.fileSize = sizeA;
                loadInfo.fileData = var11;
                loadInfo.unk_10 = 1;
                self->object->LoadFromCCHROrCMOTArchive(&loadInfo, 0);
            }
            if (var12 != 0) {
                func_0203dafc((Struct_203dafc*)&loadInfo);
                loadInfo.allocator = self->allocator;
                loadInfo.fileSize = sizeB;
                loadInfo.fileData = var12;
                loadInfo.unk_10 = 1;
                self->object->LoadFromCCHROrCMOTArchive(&loadInfo, 0);
            }
            Struct_ov015_02193cf0 scale = data_ov015_02193cf0;
            self->object->SetScale((const Vector3fix*)&scale);
            self->object->SetAnimationByIndex(0, self->animation);
        } else {
            ok = 0;
        }
        pair.Reset();
    } else {
        ok = 0;
    }

    BackgroundLoader::RemoveLockGlobal();
    VramState_Save(mgr);

    int result;
    if (ok == 0) {
        result = 0;
        pair.Reset();
        ZeroDestroyGPCPointer(&pair.pGPCFile);
        return result;
    } else {
        Struct_ov015_0218dbec_4* rec = (Struct_ov015_0218dbec_4*)func_02070fd0((Struct_02070b6c_3*)(self->tables->unknown_70_), (unsigned short)entry->key);
        if (rec != 0) {
            self->object->SetSoundGroup(rec->packed & 0xffff);
            _ZN8Object3D15SetSoundArchiveEt(self->object, rec->packed >> 16);
            SePlayer_LoadExtraArchiveB(&g_sePlayer, rec->packed & 0xffff, rec->packed >> 16);
        }
        self->selected = self->record->value;
        result = 1;
        pair.Reset();
        ZeroDestroyGPCPointer(&pair.pGPCFile);
        return result;
    }
}
