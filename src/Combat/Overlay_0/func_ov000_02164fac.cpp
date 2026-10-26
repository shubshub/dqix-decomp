#include <globaldefs.h>
extern unsigned char g_fileLoadBuffer[0x30000] __attribute__((aligned(4)));
#include "std_library_functions.h"
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/FileIO.h"
#include "Filesystem/GPC.h"
#include "GameState/GameState.h"
#include "Resource/ActionDataTables.h"
#include "Resource/GameResources.h"

struct StreamHeader;
struct Foo0207df50;
struct Struct_0205faf4_11;
struct Struct_203dafc;
struct State0207dfc8;

extern "C" void* LinkSession_GetInstance(void);
extern "C" void Main_HandleLid(void);

extern "C" void func_ov000_0216d1c4(int, StreamHeader*, int, int*);
extern "C" int LinkSession_IsActive(int* obj);
extern "C" void func_020d84f4(void);
extern "C" void* func_02079a3c(void* obj);
extern "C" int func_020a35e0(unsigned char* obj, unsigned char index);
extern "C" int func_02061bd8(Struct_0205faf4_11* obj);
extern "C" void VramState_Rewind(Foo0207df50* p);
extern "C" void VramState_Restore(char* obj);
extern "C" void VramState_Save(char* obj);
extern "C" void func_02072c9c(int combatantId, char* buf);
extern "C" void func_0203dafc(Struct_203dafc* obj);
extern "C" void func_02049c88(void* obj, void* state);
extern "C" void func_ov000_02165480(void*, int);
struct Struct_ov000_02164fac;
extern "C" Struct_ov000_02164fac* func_02053c6c(unsigned char* obj);
extern "C" void func_ov000_02166a94(void* work);
#if defined(jpn)
extern "C" void func_0207ab68(ActionDataTables* tables, SafeAllocator* allocator);
#endif
extern "C" int func_ov017_0219e008(void* ov);
extern "C" void VramState_CopyCurrentTo(State0207dfc8* src, State0207dfc8* dst);

extern const char data_ov000_02183960[];
extern const char data_ov000_02183976[];
extern const char data_ov000_02183983[];
extern const char data_ov000_0218399e[];
extern const char data_ov000_021839b8[];
extern const char data_ov000_021839c0[];
extern const char data_ov000_021839da[];
extern const char data_ov000_021839e2[];
extern const char data_ov000_021839e8[];

struct Struct_01ff91ac_11 { char data[0x70]; };
struct Slot70 { char data[0x70]; };
static inline SafeAllocator* inline_ov000_02164fac(GameResources* res, int i) { return &res->allocator_array_38[i]; }

struct Struct_ov000_02164fac_3 {
    char unknown_0_[4];
    int unknown_4_;
    char unknown_8_[0x44 - 0x8];
    SafeAllocator unknown_44_;
    SafeAllocator unknown_58_;
#if defined(jpn)
    char unknown_6c_[0x1a8 - 0x6c];
    char state[0x21c - 0x1a8];
    unsigned char* roster;
    char unknown_220_[0x5914 - 0x220];
    int scriptState;
    char unknown_5918_[0x5e2c - 0x5918];
#else
    char unknown1_6c_[0x1bc - 0x6c];
    char state[0x2a0 - 0x1bc];
    unsigned char* roster;
    char unknown_2a4_[0x5724 - 0x2a4];
    int scriptState;
    char unknown_5728_[0x5c3c - 0x5728];
#endif
    Struct_01ff91ac_11 models[4];
};

struct Struct_ov000_02164fac_4 {
    unsigned char unknown_0_0_ : 1;
    unsigned char rest : 7;
};

struct Struct_ov000_02164fac {
    char unknown_0_[0x49c];
    Struct_ov000_02164fac_4 flags;
#if defined(jpn)
    char unknown_49d_[0x8b4 - 0x49d];
#else
    char unknown1_49d_[0x94c - 0x49d];
#endif
    int phase;
};

#if defined(jpn)
#define INFO_NAME_ID 0xc
#else
#define INFO_NAME_ID 0x11
#endif

struct Struct_ov000_02164fac_5 {
    Object3D object;
    char unknown_ac_[0xc2 - 0xac];
    unsigned char flags;
#if defined(jpn)
    char unknown_c3_[0x144 - 0xc3];
    Struct_ov000_02164fac* data;
    unsigned char* model;
    char unknown_14c_[0x1b8 - 0x14c];
#else
    char unknown1_c3_[0x150 - 0xc3];
    Struct_ov000_02164fac* data;
    unsigned char* model;
    char unknown_158_[0x1c4 - 0x158];
#endif
    unsigned char* info;
};

// USA: func_ov000_02164fac
extern "C" ARM void func_ov000_02164fac(Struct_ov000_02164fac_3* work) {
    GPCReadPair pair;
    char name[0x50];
    ObjectArchiveLoadInfo info;
    ObjectArchiveLoadInfo info2;
    unsigned int size;
    const void* script;
    unsigned int scriptSize;
    char var7[8];
    const void* var8;
    unsigned int var9;
    int scriptState;
    Slot70* blocks;

    GameState* game = GameState::GetInstance();
    GameResources* res = GetGameResources();
    int* search = (int*)LinkSession_GetInstance();
    SafeAllocator* allocator = inline_ov000_02164fac(res, 7);
    blocks = (Slot70*)res->vramStates_;
    allocator->Reset();
    VramState_Rewind((Foo0207df50*)&blocks[7]);
    BackgroundLoader::AddLockGlobal();
    Main_HandleLid();
    ActionDataTables* table = func_020797dc();
#if defined(jpn)
    func_0207ab68(table, allocator);
#else
    work->unknown_58_.Reset();
    func_02079cf8(table, allocator, &work->unknown_58_);
#endif
    Main_HandleLid();

    if (LoadFileIntoMemory(data_ov000_02183960, g_fileLoadBuffer, &size)) {
        GetFileInNarc(g_fileLoadBuffer, data_ov000_02183976, &script, &scriptSize, 0);
        if (script != NULL) {
            Main_HandleLid();
            func_ov000_0216d1c4(work->unknown_4_, (StreamHeader*)script, scriptSize, &work->scriptState);
        }
    }
    if (LinkSession_IsActive(search)) {
        func_020d84f4();
    }

    unsigned char* buf = g_fileLoadBuffer;
    int capacity = 0x30000;
    func_02079a3c(&pair);
    const char* path = data_ov000_02183983;
    if (LoadAndDecompressGPCHeaderAndInnerFileInfo(&pair.pGPCFile, pair.machine,
            path, buf, size, capacity, false, 0)) {
        buf += size;
        capacity -= size;

        for (int i = 0; i < 4; i++) {
            if (!func_020a35e0(work->roster, i)) {
                continue;
            }
            Struct_ov000_02164fac_5* c = (Struct_ov000_02164fac_5*)func_0200ff1c(game, i);
            unsigned char* model;
            if (c == NULL || (model = c->model) == NULL) {
                continue;
            }

            SafeAllocator* alloc;
            Main_HandleLid();
            if (func_02061bd8((Struct_0205faf4_11*)c)) {
                c->object.Destroy();
                if (c->info != NULL) {
                    sprintf(name, data_ov000_0218399e, c->info[INFO_NAME_ID]);
                }
                alloc = (SafeAllocator*)(model + 4);
                alloc->Reset();
                VramState_Rewind((Foo0207df50*)(model + 0xcc));
                VramState_Restore((char*)(model + 0xcc));
                LoadFileIntoMemory(name, g_fileLoadBuffer, &size);
                buf = g_fileLoadBuffer;
            } else {
                func_02072c9c(i, var7);
                if (c->data->flags.unknown_0_0_ == 1) {
                    var7[0] = 'w';
                }
                sprintf(name, data_ov000_021839b8, var7);
                alloc = (SafeAllocator*)(model + 0x52c);
                DecompressFileFromGPCByName(pair.pGPCFile, pair.machine, buf, size, capacity, name);
            }

            if (size != 0) {
                c->object.RemoveAllAnimationPackages();
                ((SafeAllocator*)(model + 0x52c))->Reset();
                func_0203dafc((Struct_203dafc*)&info);
                info.allocator = alloc;
                info.unk_10 = 1;
                info.packageID = 0;
                info.fileSize = size;
                info.fileData = buf;
                c->object.LoadFromCCHROrCMOTArchive(&info, NULL);
            }

            func_02049c88(c, &work->models[i]);
            Main_HandleLid();
            if (func_02061bd8((Struct_0205faf4_11*)c)) {
                VramState_Save((char*)(model + 0xcc));
                if (c->info != NULL) {
                    sprintf(name, data_ov000_021839c0, c->info[INFO_NAME_ID]);
                }
                LoadFileIntoMemory(name, g_fileLoadBuffer, &size);
                buf = g_fileLoadBuffer;
            } else {
                var7[0] = 'm';
                sprintf(name, data_ov000_021839da, var7);
                DecompressFileFromGPCByName(pair.pGPCFile, pair.machine, buf, size, capacity, name);
            }

            if (size != 0) {
                c->object.RemoveAnimationPackageByID(1);
                ((SafeAllocator*)(model + 0x540))->Reset();
                func_0203dafc((Struct_203dafc*)&info2);
                info2.unk_10 = 1;
                info2.packageID = 1;
                info2.allocator = (SafeAllocator*)(model + 0x540);
                info2.fileSize = size;
                info2.fileData = buf;
                c->object.LoadFromCCHROrCMOTArchive(&info2, NULL);
                if (FindFilesInNarcBySubstring(buf, data_ov000_021839e2, &var8, &var9, 1)) {
                    func_ov000_0216d1c4((int)(model + 0x540), (StreamHeader*)var8, var9, &scriptState);
                    func_ov000_02165480(c, scriptState);
                }
            }

            c->flags |= 0x20;
            c->object.SetAnimationByName(data_ov000_021839e8, 0);
            if (func_02061bd8((Struct_0205faf4_11*)c)) {
                Struct_ov000_02164fac* data = func_02053c6c((unsigned char*)c);
                if (data != NULL) {
                    data->phase = 0;
                }
            }
            if (LinkSession_IsActive(search)) {
                func_020d84f4();
            }
        }
    }

    BackgroundLoader::RemoveLockGlobal();
    Main_HandleLid();
    func_ov000_02166a94(work);
#if defined(jpn)
    unsigned int var25 = allocator->GetMaxPossibleAllocation();
#else
    unsigned int var25 = 0x26a80;
#endif
    void* mem = allocator->Allocate(var25);
    if (mem != NULL) {
        work->unknown_44_.CreateTypeA(mem, var25);
    }
    if (func_ov017_0219e008(res) == 0) {
        VramState_CopyCurrentTo((State0207dfc8*)res->vramStates_, (State0207dfc8*)work->state);
    } else {
        VramState_CopyCurrentTo((State0207dfc8*)&blocks[7], (State0207dfc8*)work->state);
    }
    pair.Reset();
    ZeroDestroyGPCPointer(&pair.pGPCFile);
}
