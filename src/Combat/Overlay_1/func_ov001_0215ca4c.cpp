#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Filesystem/BackgroundLoader.h>
#include <Filesystem/GPC.h>
extern unsigned char g_fileLoadBuffer[0x30000] __attribute__((aligned(4)));
#include <Filesystem/FileIO.h>
#include <std_library_functions.h>

struct Struct_ov001_0215b72c { char unknown_0_[8]; };
extern "C" const char* func_ov017_021d612c(Struct_ov001_0215b72c*);
extern "C" int func_ov017_021d60f4(Struct_ov001_0215b72c*);
extern "C" int func_ov001_0215ad2c(int);
extern "C" void func_0200fd38(GameState*, int, GameObject*);
extern SafeAllocator* data_ov001_021658b8[];
extern const char data_ov001_0216572d[];
extern const char data_ov001_0216576f[];

// USA: func_ov001_0215ca4c
extern "C" ARM int func_ov001_0215ca4c(Struct_ov001_0215b72c* arg0, int arg1) {
    GameState* var0 = GameState::GetInstance();
    BackgroundLoader* var1 = BackgroundLoader::GetInstance();
    const char* var2 = func_ov017_021d612c(arg0++);
    int var3 = func_ov001_0215ad2c(func_ov017_021d60f4(arg0++));
    int var4 = var3;
    int var5 = 0;
    if (arg1 >= 3) var5 = func_ov017_021d60f4(arg0);
    SafeAllocator* var6 = data_ov001_021658b8[var5];
    if (var3 >= 0xa0 && var3 < 0xbf) var4 = var3;
    char var7[32];
    const char* var8 = strrchr(var2, '/');
    strcpy(var7, var8 ? var8 + 1 : var2);
    void* var9;
    unsigned int var10;
    int var11 = 0;
    var1->GetLoadedFileInArchive(data_ov001_0216572d, var7, &var9, &var10);
    if (!var9) {
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
            var15 = 0;
            var13->Reset();
            ZeroDestroyGPCPointer(&var13->pGPCFile);
            return var15;
        }
        void* destination = g_fileLoadBuffer + headerSize;
        unsigned int fileSize;
        if (!DecompressFileFromGPCByName(pair.pGPCFile, pair.machine, destination,
                fileSize, 0x30000 - headerSize, resource)) {
            pair.Reset();
            BackgroundLoader::RemoveLockGlobal();
            var15 = 0;
            var12.Reset();
            ZeroDestroyGPCPointer(&var12.pGPCFile);
            return var15;
        }
        var9 = var16;
        var12.Reset();
        var12.Reset();
        ZeroDestroyGPCPointer(&var12.pGPCFile);
    }
    unsigned int var18;
    const void* var19;
    if (!FindFilesInNarcBySubstring(var9, data_ov001_0216576f, &var19, &var18, 1)) {
        if (var11) BackgroundLoader::RemoveLockGlobal();
        return 0;
    }
    unsigned int decompressedSize;
    void* model = DecompressLZ77FileIntoAllocatedSpace(*allocator, compressedData, decompressedSize);
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
    RegisterCombatantSlot_0200fd38(game, id, (GameObject*)object);
    object->SetScale(266, 266, 266);
    object->SetAnimationByIndex(0, 0);
    return 1;
}
