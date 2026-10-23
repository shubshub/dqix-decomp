#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/GPC.h"
#include "Filesystem/BackgroundLoader.h"

struct Struct_0206f01c_2;
#if defined(jpn)
#define data_ov017_021d7668 data_ov017_021d7aa8
#define data_ov017_021d7680 data_ov017_021d7ac0
#define data_ov017_021d7689 data_ov017_021d7ac9
#endif
struct Struct_ov017_021a28a8 {
#if defined(jpn)
    char unknown_0_[0x40];
#else
    char unknown1_0_[0x44];
#endif
    char unknown_44_[0x2b4];
    char unknown_2f8_[0xc];
    char unknown_304_[0xc];
};
struct Struct_ov017_021a28a8_2 { int unknown_0_; int unknown_4_; };
struct Struct_ov017_021a28a8_3 { Object3D unknown_0_; int unknown_ac_; };
struct Struct_ov017_021a28a8_4 {
#if defined(jpn)
    char unknown_0_[0xf2c];
#else
    char unknown1_0_[0x113c];
#endif
    SafeAllocator unknown_113c_;
    char unknown_1150_[0x20];
};

void ClearSlotsAndProcess_021a27e8(void*);
ResourceEntry021a28a8* FindEntryByCurrentId02027cb0();
int GetCount0209c0ec(char*);
void VramState_Restore(char*);
void VramState_Save(char*);
int GetCheckedHalfword_0209c0a8(void*, int);
ResourceInfo021a28a8* SearchWithComparator0206f4f0(BinarySearchByComparatorStruct*, int);
void* FindNodeBySignedId_0206ef18(void*, int);
bool FindFilesInNarcBySubstring(const void*, const char*, const void**, unsigned int*, unsigned int);
void* DecompressLZ77FileIntoAllocatedSpace(SafeAllocator&, const void*, unsigned int&);
extern "C" void func_0209953c(unsigned short);
extern "C" void func_02072ac4(void*);
extern "C" void func_0200fd38(GameState*, int, GameObject*);
extern "C" void func_ov017_021a2b1c(void*);
extern char data_ov017_021d7668[];
extern char data_0211e33c[] __attribute__((aligned(4)));
extern char data_ov017_021d7680[];
extern char data_ov017_021d7689[];

// USA: func_ov017_021a28a8
// JPN: func_ov017_021a3338
extern "C" ARM void func_ov017_021a28a8(ResourceArena021a28a8* arena) {
    GameState* state = GameState::GetInstance();
    SafeAllocator* allocator = &arena->allocator;
    char* tables = arena->pairTables;
    ClearSlotsAndProcess_021a27e8(arena);
    ResourceEntry021a28a8* area = FindEntryByCurrentId02027cb0();
    if (!area) return;
    ResourceObject021a28a8* objects = (ResourceObject021a28a8*)allocator->Allocate(GetCount0209c0ec(area->ids) * 0xb0);
    if (!objects) return;
    VramState_Restore(tables);
    BackgroundLoader::AddLockGlobal();
    BackgroundLoader::FreeAllocationsGlobal();
    GPCReadPair var5;
    GPCReadPair* var6 = &var5;
    ZeroInitGPCPointer(&var5.pGPCFile);
    var6->ZeroInitializeMachine();
    unsigned int var7;
    if (LoadAndDecompressGPCHeaderAndInnerFileInfo(&var5.pGPCFile, var5.machine, data_ov017_021d7668, data_0211e33c, var7, 0x30000, false, 0)) {
        unsigned int var8 = var7;
        unsigned int var9 = 0x30000 - var8;
        for (int var10 = 0; var10 < func_0209c0ec(var3->unknown_44_); ++var10) {
            int var11 = func_0209c0a8(var3->unknown_44_, var10);
            Struct_ov017_021a28a8_2* var12 = func_0206f4f0((Struct_0206f01c_2*)var3->unknown_2f8_, (short)var11);
            void* var13 = func_0206ef18(var3->unknown_304_, (short)var11);
            if (var12 && var13) {
                char var14[16];
                sprintf(var14, data_ov017_021d7680, var12->unknown_4_);
                unsigned int var15 = 0;
                if (DecompressFileFromGPCByName(var5.pGPCFile, var5.machine, data_0211e33c + var8, var15, var9, var14)) {
                    const void* var16;
                    unsigned int var17;
                    if (FindFilesInNarcBySubstring(data_0211e33c + var8, data_ov017_021d7689, &var16, &var17, 1)) {
                        unsigned int var18;
                        void* var19 = DecompressLZ77FileIntoAllocatedSpace(*var1, var16, var18);
                        if (!var19) {
                            func_0209953c(3);
                        } else {
                            func_02072ac4(&var4[var10]);
                            var4[var10].unknown_0_.unknown_2_ = var11;
                            ObjectArchiveLoadInfo var20;
                            var20.fileData = var19;
                            var20.unk_8 = var18;
                            var20.unk_0 = 0;
                            var20.unk_10 = 0;
                            var20.unk_14 = 0;
                            var20.unk_18 = 0;
                            var20.packageID = 0;
                            var20.allocator = var1;
                            if (var4[var10].unknown_0_.LoadFromCCHROrCMOTArchive(&var20, 0)) {
                                func_0200fd38(var0, var10 + 7, (GameObject*)&var4[var10]);
                            } else func_0209953c(3);
                        }
                    }
                }
            }
        }
        var5.Reset();
    }
    BackgroundLoader::RemoveLockGlobal();
    VramState_Save(tables);
    func_ov017_021a2b1c(arena);
    archive.Reset();
    ZeroDestroyGPCPointer(&archive.pGPCFile);
}

#if defined(jpn)
#undef data_ov017_021d7668
#undef data_ov017_021d7680
#undef data_ov017_021d7689
#endif
