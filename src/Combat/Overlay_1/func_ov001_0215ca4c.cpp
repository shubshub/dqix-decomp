#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Filesystem/BackgroundLoader.h>
#include <Filesystem/GPC.h>
extern unsigned char g_fileLoadBuffer[0x30000] __attribute__((aligned(4)));
#include <Filesystem/FileIO.h>
#include <std_library_functions.h>

struct Struct_ov001_0215b72c { char data[8]; };
extern "C" const char* func_ov017_021d612c(Struct_ov001_0215b72c*);
extern "C" int func_ov017_021d60f4(Struct_ov001_0215b72c*);
extern "C" int func_ov001_0215ad2c(int);
extern "C" void func_0200fd38(GameState*, int, GameObject*);
extern SafeAllocator* data_ov001_021658b8[];
extern const char data_ov001_0216572d[];
extern const char data_ov001_0216576f[];

// USA: func_ov001_0215ca4c
extern "C" ARM int func_ov001_0215ca4c(Struct_ov001_0215b72c* arguments, int count) {
    GameState* game = GameState::GetInstance();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    const char* resource = func_ov017_021d612c(arguments++);
    int slot = func_ov001_0215ad2c(func_ov017_021d60f4(arguments++));
    int id = slot;
    int var5 = 0;
    if (count >= 3) var5 = func_ov017_021d60f4(arguments);
    SafeAllocator* allocator = data_ov001_021658b8[var5];
    if (slot >= 0xa0 && slot < 0xbf) id = slot;
    char filename[32];
    const char* var8 = strrchr(resource, '/');
    strcpy(filename, var8 ? var8 + 1 : resource);
    void* archiveData;
    unsigned int var10;
    int locked = 0;
    loader->GetLoadedFileInArchive(data_ov001_0216572d, filename, &archiveData, &var10);
    if (!archiveData) {
        BackgroundLoader::AddLockGlobal();
        BackgroundLoader::FreeAllocationsGlobal();
        locked = 1;
        GPCReadPair pair;
        GPCReadPair* reader = &pair;
        ZeroInitGPCPointer(&reader->pGPCFile);
        reader->ZeroInitializeMachine();
        unsigned int headerSize;
        int result;
        if (!LoadAndDecompressGPCHeaderAndInnerFileInfo(&reader->pGPCFile, pair.machine,
                data_ov001_0216572d, g_fileLoadBuffer, headerSize, 0x30000, false, 0)) {
            BackgroundLoader::RemoveLockGlobal();
            result = 0;
            reader->Reset();
            ZeroDestroyGPCPointer(&reader->pGPCFile);
            return result;
        }
        void* destination = g_fileLoadBuffer + headerSize;
        unsigned int fileSize;
        if (!DecompressFileFromGPCByName(pair.pGPCFile, pair.machine, destination,
                fileSize, 0x30000 - headerSize, resource)) {
            pair.Reset();
            BackgroundLoader::RemoveLockGlobal();
            result = 0;
            pair.Reset();
            ZeroDestroyGPCPointer(&pair.pGPCFile);
            return result;
        }
        archiveData = destination;
        pair.Reset();
        pair.Reset();
        ZeroDestroyGPCPointer(&pair.pGPCFile);
    }
    unsigned int var18;
    const void* var19;
    if (!FindFilesInNarcBySubstring(archiveData, data_ov001_0216576f, &var19, &var18, 1)) {
        if (locked) BackgroundLoader::RemoveLockGlobal();
        return 0;
    }
    unsigned int decompressedSize;
    void* model = DecompressLZ77FileIntoAllocatedSpace(*allocator, var19, decompressedSize);
    Object3D* object = (Object3D*)allocator->Allocate(sizeof(Object3D));
    object->Initialize();
    ObjectArchiveLoadInfo info;
    info.fileSize = decompressedSize;
    info.allocator = allocator;
    info.fileData = model;
    info.unk_0 = 0;
    info.unk_14 = 0;
    info.unk_18 = 0;
    info.packageID = 0;
    info.unk_10 = 0;
    object->LoadFromCCHROrCMOTArchive(&info, 0);
    if (locked) BackgroundLoader::RemoveLockGlobal();
    func_0200fd38(game, id, (GameObject*)object);
    object->SetScale(266, 266, 266);
    object->SetAnimationByIndex(0, 0);
    return 1;
}
