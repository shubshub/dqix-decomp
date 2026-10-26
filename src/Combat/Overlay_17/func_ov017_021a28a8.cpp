#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/GPC.h"
#include "Filesystem/BackgroundLoader.h"

struct BinarySearchByComparatorStruct;
#if defined(jpn)
#define data_ov017_021d7668 data_ov017_021d7aa8
#define data_ov017_021d7680 data_ov017_021d7ac0
#define data_ov017_021d7689 data_ov017_021d7ac9
#endif
struct ResourceEntry021a28a8 {
#if defined(jpn)
    char field_0[0x40];
#else
    char field_0[0x44];
#endif
    char ids[0x2b4];
    char monsters[0xc];
    char nodes[0xc];
};
struct ResourceInfo021a28a8 { int field_0; int filename; };
struct ResourceObject021a28a8 { Object3D object; int field_ac; };
struct ResourceArena021a28a8 {
#if defined(jpn)
    char field_0[0xf2c];
#else
    char field_0[0x113c];
#endif
    SafeAllocator allocator;
    char pairTables[0x20];
};

void ClearSlotsAndProcess_021a27e8(void*);
ResourceEntry021a28a8* ZoneRecords_FindCurrent();
int GetCount0209c0ec(char*);
void VramState_Restore(char*);
void VramState_Save(char*);
int GetCheckedHalfword_0209c0a8(void*, int);
ResourceInfo021a28a8* SearchWithComparator0206f4f0(BinarySearchByComparatorStruct*, int);
void* FindNodeBySignedId_0206ef18(void*, int);
bool FindFilesInNarcBySubstring(const void*, const char*, const void**, unsigned int*, unsigned int);
void* DecompressLZ77FileIntoAllocatedSpace(SafeAllocator&, const void*, unsigned int&);
void InsertShortIntoTable021098f4_0209953c(unsigned short);
void ResetFieldAc_02072ac4(void*);
void RegisterCombatantSlot_0200fd38(GameState*, int, GameObject*);
extern "C" void func_ov017_021a2b1c(void*);
extern char data_ov017_021d7668[];
extern char g_fileLoadBuffer[] __attribute__((aligned(4)));
extern char data_ov017_021d7680[];
extern char data_ov017_021d7689[];

// USA: func_ov017_021a28a8
// JPN: func_ov017_021a3338
extern "C" ARM void func_ov017_021a28a8(ResourceArena021a28a8* arena) {
    GameState* state = GameState::GetInstance();
    SafeAllocator* allocator = &arena->allocator;
    char* tables = arena->pairTables;
    ClearSlotsAndProcess_021a27e8(arena);
    ResourceEntry021a28a8* area = ZoneRecords_FindCurrent();
    if (!area) return;
    ResourceObject021a28a8* objects = (ResourceObject021a28a8*)allocator->Allocate(GetCount0209c0ec(area->ids) * 0xb0);
    if (!objects) return;
    VramState_Restore(tables);
    BackgroundLoader::AddLockGlobal();
    BackgroundLoader::FreeAllocationsGlobal();
    GPCReadPair archive;
    GPCReadPair* pair = &archive;
    ZeroInitGPCPointer(&archive.pGPCFile);
    pair->ZeroInitializeMachine();
    unsigned int headerLength;
    if (LoadAndDecompressGPCHeaderAndInnerFileInfo(&archive.pGPCFile, archive.machine, data_ov017_021d7668, g_fileLoadBuffer, headerLength, 0x30000, false, 0)) {
        unsigned int start = headerLength;
        unsigned int available = 0x30000 - start;
        for (int i = 0; i < GetCount0209c0ec(area->ids); ++i) {
            int id = GetCheckedHalfword_0209c0a8(area->ids, i);
            ResourceInfo021a28a8* info = SearchWithComparator0206f4f0((BinarySearchByComparatorStruct*)area->monsters, (short)id);
            void* node = FindNodeBySignedId_0206ef18(area->nodes, (short)id);
            if (info && node) {
                char filename[16];
                sprintf(filename, data_ov017_021d7680, info->filename);
                unsigned int archiveLength = 0;
                if (DecompressFileFromGPCByName(archive.pGPCFile, archive.machine, g_fileLoadBuffer + start, archiveLength, available, filename)) {
                    const void* file;
                    unsigned int fileLength;
                    if (FindFilesInNarcBySubstring(g_fileLoadBuffer + start, data_ov017_021d7689, &file, &fileLength, 1)) {
                        unsigned int length;
                        void* decompressed = DecompressLZ77FileIntoAllocatedSpace(*allocator, file, length);
                        if (!decompressed) {
                            InsertShortIntoTable021098f4_0209953c(3);
                        } else {
                            ResetFieldAc_02072ac4(&objects[i]);
                            objects[i].object.unknown_2_ = id;
                            ObjectArchiveLoadInfo load;
                            load.fileData = decompressed;
                            load.fileSize = length;
                            load.unk_0 = 0;
                            load.unk_10 = 0;
                            load.unk_14 = 0;
                            load.unk_18 = 0;
                            load.packageID = 0;
                            load.allocator = allocator;
                            if (objects[i].object.LoadFromCCHROrCMOTArchive(&load, 0)) {
                                RegisterCombatantSlot_0200fd38(state, i + 7, (GameObject*)&objects[i]);
                            } else InsertShortIntoTable021098f4_0209953c(3);
                        }
                    }
                }
            }
        }
        archive.Reset();
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
