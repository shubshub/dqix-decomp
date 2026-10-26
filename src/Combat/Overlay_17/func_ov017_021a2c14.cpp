#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "NitroSDK/Filesystem/NarcHandle.h"
#include "Filesystem/FileIO.h"
#include "NitroSDK/Filesystem/FileAccessor.h"
#include "NitroSDK/Filesystem/LowNitroHandle.h"
#include "World/Zone3D.h"
extern "C" char* strcpy(char*, const char*);
extern "C" int sprintf(char*, const char*, ...);
extern "C" char* strstr(const char*, const char*);

struct Struct_0203d028_6;
struct Struct_0203cfb4;
struct Struct_02013fb4;
struct Struct_0203dce4_2;
struct Struct_ov017_021a2c14 { int unknown_0_; Vector3i unknown_4_; };
struct Struct_ov017_021a2c14_2 { unsigned int unknown_0_; unsigned char unknown_4_[0x10]; Struct_ov017_021a2c14* unknown_14_; Object3D* unknown_18_; };
#if defined(jpn)
enum { Enum_ov017_021a2c14_1500 = 0x58c };
#define data_ov017_021d76a6 data_ov017_021d7ae6
#define data_ov017_021d76bb data_ov017_021d7afb
#define data_ov017_021d76bf data_ov017_021d7aff
#define data_ov017_021d76c9 data_ov017_021d7b09
#define data_ov017_021d76d1 data_ov017_021d7b11
#define data_ov017_021d76d4 data_ov017_021d7b14
#else
enum { Enum_ov017_021a2c14_1500 = 0x5dc };
#endif
void* GetGlobalPtr021075f4_0203cf4c();
int GameState_GetStoryChapter(char*);
int GameState_GetStoryPart(char*);
int GameState_GetStoryStep(char*);
void Init0203cfb4(Struct_0203cfb4*);
Pool020401fc* EmptyStub0203d004(void*);
void InitPool020401fc(Pool020401fc*, unsigned int, SafeAllocator*);
void* GetPtrField0x94_0203cffc(void*);
void* GetPtrField0x90_0203cff4(void*);
void ClearFirstWord0206da74(int*);
void ClearFirstWord02064e20(int*);
extern "C" void func_0206da80(void*, int, int, int, int, SafeAllocator*, const void*, int);
extern "C" void func_02064e2c(int, int, int, Struct_02013fb4*, int);
extern "C" void func_02064e88(void*, void*, SafeAllocator*);
extern "C" void func_0203d028(void*, int, SafeAllocator*, unsigned char*);
extern "C" void func_0203e2c4(void*, unsigned short);
extern "C" void* Zone3D_GetInstance();
Entry021a2c14* GetEntryUnlessFlag0x8000_0203dce4(EntryList_203dce4*, int);
extern "C" int Zone3D_GetGroundHeight(void*, Vector3i*);
extern char data_ov017_021d76a6[];
extern unsigned char g_fileLoadBuffer[];
extern char data_ov017_021d76bb[];
extern char data_ov017_021d76bf[];
extern char data_ov017_021d76c9[];
extern char data_ov017_021d76d1[];
extern char data_ov017_021d76d4[];

// USA: func_ov017_021a2c14
extern "C" ARM int func_ov017_021a2c14(GameResources* object, Zone3D_StructPtr_8* request) {
    GameState* game = GameState::GetInstance();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    void* context = GetGlobalPtr021075f4_0203cf4c();
    SafeAllocator* allocator = &object->allocator_array_38[7];
    unsigned char* zoneState = reinterpret_cast<unsigned char*>(object) + ZoneStateOffset;
    int id = request->unknown_0_;
    int field0 = GameState_GetStoryChapter((char*)game);
    int field1 = GameState_GetStoryPart((char*)game);
    int field2 = GameState_GetStoryStep((char*)game);
    Init0203cfb4((Struct_0203cfb4*)context);
    if (loader->GetNumQueuedTasks() > 0) return 0;
    char path[0x50];
    NarcHandle archive;
    NitroVM vm;
    char resourcePath[0x50];
    char scriptPath[0x50];
    char prefix[8];
    unsigned int archiveSize;
    strcpy(prefix, request->mapShortName_);
    prefix[3] = 0;
    if (prefix[0] == 'F') prefix[1] = 0;
    BackgroundLoader::AddLockGlobal();
    sprintf(path, data_ov017_021d76a6, prefix);
    if (!LoadFileIntoMemory(path, g_fileLoadBuffer, &archiveSize)) {
        InitPool020401fc(EmptyStub0203d004(context), 12, allocator);
        BackgroundLoader::RemoveLockGlobal();
        return 0;
    }
    if (!archive.Initialize(data_ov017_021d76bb, g_fileLoadBuffer)) {
        BackgroundLoader::RemoveLockGlobal();
        return 0;
    }
    NitroVM_Initialize(&var11);
    unsigned int var16;
    unsigned int var17;
    int var18;
    void* var19 = func_0203cffc(var2);
    func_0206da74((int*)var19);
    var16 = 0;
    while (PrepareReadFileInNARCByID(&var11, &var10, var16)) {
        NitroVM_WriteOutFilePath(&var11, var12, 0x50);
        const void* var20 = var10.GetFileByIndex(var16);
        var18 = var11.fileInfo.unknown_8_ - var11.fileInfo.unknown_4_;
        if (strstr(var12, data_ov017_021d76bf)) {
            func_0206da80(var19, var6, var7, var8, var5, var3, var20, var18);
        }
        NitroVM_FinishRead(&var11);
        ++var16;
    }
    void* var21 = func_0203cff4(var2);
    func_02064e20((int*)var21);
    var17 = 0;
    while (PrepareReadFileInNARCByID(&var11, &var10, var17)) {
        NitroVM_WriteOutFilePath(&var11, var13, 0x50);
        const void* var22 = var10.GetFileByIndex(var17);
        var18 = var11.fileInfo.unknown_8_ - var11.fileInfo.unknown_4_;
        if (strstr(var13, data_ov017_021d76c9)) {
            func_02064e2c((int)var21, (int)var19, (int)var3, (Struct_02013fb4*)var22, var18);
            if (strstr(var13, data_ov017_021d76d1) && !strstr(var13, data_ov017_021d76d4)) {
                func_02064e88(var21, var19, var3);
            }
        }
        NitroVM_FinishRead(&var11);
        ++var17;
    }
    var10.Destroy();
    BackgroundLoader::RemoveLockGlobal();
    func_0203d028(context, 0, allocator, zoneState);
    func_0203e2c4(context, id);
    void* zone = Zone3D_GetInstance();
    for (int entryIndex = 0; entryIndex < 32; ++entryIndex) {
        Entry021a2c14* entry = GetEntryUnlessFlag0x8000_0203dce4((EntryList_203dce4*)context, entryIndex);
        if (!entry || (entry->flags & 0x800) || (entry->flags & 0x1000)) continue;
        if (entry->holder) {
            Vector3i holderPosition = entry->holder->position;
            holderPosition.y = Zone3D_GetGroundHeight(zone, &holderPosition);
            entry->holder->position = holderPosition;
        } else if (entry->actor) {
            Vector3i actorPosition = entry->actor->position_;
            actorPosition.y = Zone3D_GetGroundHeight(zone, &actorPosition);
            entry->actor->position_ = actorPosition;
        }
    }
    return 1;
}
