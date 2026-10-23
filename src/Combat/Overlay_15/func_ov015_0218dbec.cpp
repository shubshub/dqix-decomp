#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"
#include "World/Object3D.h"
#include "Filesystem/GPC.h"
extern unsigned char data_0211e33c[0x30000] __attribute__((aligned(4)));
#include "Filesystem/FileIO.h"
#include "Filesystem/BackgroundLoader.h"

struct Struct_0206f01c_2;
struct Struct_02070b6c_3;
struct Struct_0203d028;
struct Struct_0203d028_11;

extern "C" void* func_0206f4f0(Struct_0206f01c_2*, int);
extern "C" void* func_02070fd0(Struct_02070b6c_3*, int);
extern "C" void func_0203dafc(struct Struct_0203d028_11*);

extern "C" void* __clear(void* dst, int count);
void CopyInternalFields0207df50(Foo0207df50*);
void VramState_Restore(char*);
void VramState_Save(char*);
void ResetObjectState02079a3c(void*);
extern "C" void _ZN8Object3D10SetField7aEt(Object3D*, unsigned int);
extern "C" void func_0205ebc0(void*, int, int);

struct Struct_ov015_0218dbec_4 {
    int unknown_0_;
    int unknown_4_;
    char unknown_8_[0x14 - 8];
    unsigned int unknown_14_;
};

struct Struct_ov015_0218dbec {
    char unknown_0_[8];
    short unknown_8_;
};

struct Struct_ov015_0218dbec_2 {
    char unknown_0_[0x64];
    char unknown_64_[0xc];
    char unknown_70_[0x1a1 - 0x70];
    unsigned char unknown_1a1_;
};

struct Struct_ov015_02193cf0 { unsigned int unknown_0_[3]; };

struct Struct_ov015_0218dbec_3 {
    Struct_ov015_0218dbec_2* unknown_0_;
    char** unknown_4_;
    SafeAllocator* unknown_8_;
    int unknown_c_;
    Struct_ov015_0218dbec_4* unknown_10_;
    char unknown_14_[0x24 - 0x14];
    Object3D* unknown_24_;
    char unknown_28_[0x44 - 0x28];
    int unknown_44_;
};

extern char data_ov015_021940f5;
extern char data_ov015_021940fe;
extern char data_ov015_02194105;
extern char data_ov015_0219411d;
extern char data_ov015_02194123;
extern struct Vec3Words02193cf0 data_ov015_02193cf0;
extern int g_sePlayer;

// USA: func_ov015_0218dbec
extern "C" ARM int func_ov015_0218dbec(Struct_ov015_0218dbec_3* arg0, Struct_ov015_0218dbec* arg1) {
    arg0->unknown_10_ = (Struct_ov015_0218dbec_4*)func_0206f4f0((Struct_0206f01c_2*)(arg0->unknown_0_->unknown_64_), arg1->unknown_8_);
    if (arg0->unknown_10_ == 0) {
        return 0;
    }

    char var0[0x10];
    __clear(var0, 0x10);
    arg0->unknown_8_->Reset();

    int ok = 1;
    char* mgr = *self->pairsRoot;
    CopyInternalFields0207df50((Foo0207df50*)mgr);
    VramState_Restore(mgr);

    if (arg0->unknown_0_->unknown_1a1_ != 0) {
        sprintf(var0, &data_ov015_021940f5, arg0->unknown_10_->unknown_4_);
    } else {
        sprintf(var0, &data_ov015_021940fe, arg0->unknown_10_->unknown_4_);
    }

    BackgroundLoader::AddLockGlobal();
    BackgroundLoader::FreeAllocationsGlobal();

    GPCReadPair var3;
    func_02079a3c(&var3);
    unsigned int var4;
    if (LoadAndDecompressGPCHeaderAndInnerFileInfo(&var3.pGPCFile, var3.machine, &data_ov015_02194105,
                                                   data_0211e33c, var4, 0x30000, false, 0)) {
        unsigned int var5;
        char* var6 = (char*)data_0211e33c + var4;
        if (DecompressFileFromGPCByName(var3.pGPCFile, var3.machine, var6, var5, 0x30000 - var4, var0)) {
            const void* var7 = 0;
            unsigned int var8 = 0;
            unsigned int var9 = 0;
            unsigned int var10 = 0;
            void* var11 = 0;
            void* var12 = 0;
            if (FindFilesInNarcBySubstring(var6, &data_ov015_0219411d, &var7, &var8, 1)) {
                var11 = DecompressLZ77FileIntoAllocatedSpace(*arg0->unknown_8_, var7, var9);
            }
            if (FindFilesInNarcBySubstring(var6, &data_ov015_02194123, &var7, &var8, 1)) {
                var12 = DecompressLZ77FileIntoAllocatedSpace(*arg0->unknown_8_, var7, var10);
            }
            ObjectArchiveLoadInfo var13;
            if (var11 != 0) {
                func_0203dafc((Struct_0203d028_11*)&var13);
                var13.allocator = arg0->unknown_8_;
                var13.unk_8 = var9;
                var13.fileData = var11;
                var13.unk_10 = 1;
                arg0->unknown_24_->LoadFromCCHROrCMOTArchive(&var13, 0);
            }
            if (var12 != 0) {
                func_0203dafc((Struct_0203d028_11*)&var13);
                var13.allocator = arg0->unknown_8_;
                var13.unk_8 = var10;
                var13.fileData = var12;
                var13.unk_10 = 1;
                arg0->unknown_24_->LoadFromCCHROrCMOTArchive(&var13, 0);
            }
            Struct_ov015_02193cf0 var14 = data_ov015_02193cf0;
            arg0->unknown_24_->SetScale((const Vector3fix*)&var14);
            arg0->unknown_24_->MaybeSetBCFGAnimation(0, arg0->unknown_44_);
        } else {
            var1 = 0;
        }
        var3.Reset();
    } else {
        var1 = 0;
    }

    BackgroundLoader::RemoveLockGlobal();
    VramState_Save(mgr);

    int var15;
    if (var1 == 0) {
        var15 = 0;
        var3.Reset();
        ZeroDestroyGPCPointer(&var3.pGPCFile);
        return var15;
    } else {
        Record0218dbec* rec = (Record0218dbec*)SearchWithLow15Comparator02070fd0((Container02070e60*)(self->tables->search70), (unsigned short)entry->key);
        if (rec != 0) {
            self->object->SetField78(rec->packed & 0xffff);
            _ZN8Object3D10SetField7aEt(self->object, rec->packed >> 16);
            SetForwardAndStore0205ebc0(&g_sePlayer, rec->packed & 0xffff, rec->packed >> 16);
        }
        arg0->unknown_c_ = arg0->unknown_10_->unknown_0_;
        var15 = 1;
        var3.Reset();
        ZeroDestroyGPCPointer(&var3.pGPCFile);
        return var15;
    }
}
