#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Resource/GameResources.h"
#include "NitroSDK/Memory.h"
#include "Resource/Brightness.h"


#if defined(jpn)
enum { kBackupAllocator = 0x6c0, Enum_020e081c_1904 = 0x6c4, Enum_020e081c_1908 = 0x6c8,
       Enum_020e081c_2498 = 0x916, Enum_020e081c_2499 = 0x917, Enum_020e081c_2556 = 0x950, kObjectTask = 0x95c,
       Enum_020e081c_13312 = 0x2500, kDisplay = 0x200, kDisplayWidth = 0x608 };
#define data_020f2b78 data_020f2cd0
extern const char data_020f2ce8[];
#else
enum { kBackupAllocator = 0x76c, Enum_020e081c_1904 = 0x770, Enum_020e081c_1908 = 0x774,
       Enum_020e081c_2498 = 0x9c2, Enum_020e081c_2499 = 0x9c3, Enum_020e081c_2556 = 0x9fc, kObjectTask = 0xa08,
       Enum_020e081c_13312 = 0x3400, kDisplay = 0x258, kDisplayWidth = 0x508 };
extern const char data_020f2b90[];
extern const char data_020f2ba2[];
#endif

struct Struct0205a198 { char bytes[0x28]; };
struct PacRecord;
struct SetFlagStruct;
struct Struct_02021410;
struct Struct_020e081c {
    char unknown0[0x40];
    Struct0205a198* records;
    char unknown44[8];
    unsigned short count;
    char unknown_4e_[2];
    unsigned char active;
    char unknown_51_[3];
};

extern "C" void* Zone3D_GetInstance();
extern "C" char* OamManager_GetInstance();
extern "C" char* BgVram_GetInstance();
extern "C" void MapDisplay_SetHoldSubScreenDark(SetFlagStruct*, int);
extern "C" void MapDisplay_FadeOutSubScreen(void*, int);
extern "C" void func_020209d0(void* context);
extern "C" void BgVram_Reset(char*);
extern "C" void OamManager_Init(char*);
extern "C" void Sprite_Init(Struct0205a198*);
extern "C" void SpriteContext_Init(char*);
extern "C" int SpriteContext_LoadArchive(void*, PacRecord*, int, void*);
extern "C" void* CachedTextTable_GetInstance();
extern "C" void* OamManager_GetSubOamBuffer(char*);
extern "C" void HaltSystem();
extern "C" void OS_WaitVBlankIntr();
#if defined(jpn)
extern "C" void func_02020cb8(void*, int);
#else
extern "C" void func_02020cb8(void*, int*);
#endif
extern "C" void MapDisplay_RemoveTask(void*, int*);
extern "C" void func_02021410(Struct_02021410*, int, int);
extern const char data_020f2b78[];

static inline SafeAllocator* GetResourceAllocator(GameResources* resources, int index) {
    return &resources->allocator_array_38[index];
}

// KEEP-NAME: func_020e081c is the shared regional export.
// USA: func_020e081c
extern "C" ARM void func_020e081c(char* self) {
    GameState::GetInstance();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    Zone3D_GetInstance();
    GameResources* resources = GetGameResources();
    char* battle = OamManager_GetInstance();
    char* table = BgVram_GetInstance();
    SafeAllocator* allocator = GetResourceAllocator(resources, 12);
    if (*(signed char*)(self + Enum_020e081c_2498) == 0) {
        MapDisplay_SetHoldSubScreenDark((SetFlagStruct*)self, 0);
        MapDisplay_FadeOutSubScreen(self, 0x19);
        func_020209d0(self);
        allocator->Reset();
        BgVram_Reset(table);
        OamManager_Init(battle);
        for (int i = 0; i < 28; ++i)
            Sprite_Init(&((Struct0205a198*)(self + 0xe8))[i]);
        SpriteContext_Init(self + 0x94);
        Struct_020e081c* script = (Struct_020e081c*)(self + 0x94);
        script->active = 1;
        script->records = (Struct0205a198*)(self + 0xe8);
        script->count = 5;
        loader->AddFence();
        *(int*)(self + Enum_020e081c_2556) = loader->QueueLoadFile(data_020f2b78, 0);
#if defined(jpn)
        *(int*)(self + kObjectTask) = loader->QueueLoadFile(data_020f2ce8, 0);
#else
        *(int*)(self + kObjectTask) = loader->QueueLoadFileInGP2(data_020f2b90, data_020f2ba2, 0);
#endif
        ++*(signed char*)(self + Enum_020e081c_2498);
    } else if (*(signed char*)(self + Enum_020e081c_2498) == 1) {
        if (!loader->GetTaskStatus(*(int*)(self + Enum_020e081c_2556))) return;
        if (!loader->GetTaskStatus(*(int*)(self + kObjectTask))) return;
        MapDisplay_FadeOutSubScreen(self, 0x19);
        if (IsScreenNotFullyFaded((GameResources*)resources, true)) return;
        void* file = 0;
        unsigned int length = 0;
        loader->GetLoadedFileByID(*(int*)(self + kObjectTask), &file, &length);
        SpriteContext_LoadArchive(self + 0x94, (PacRecord*)file, length, allocator);
        *(int*)((char*)CachedTextTable_GetInstance() + kDisplayWidth) = 0x2800;
        void* display = (char*)OamManager_GetSubOamBuffer(OamManager_GetInstance()) + kDisplay;
        *(void**)CachedTextTable_GetInstance() = display;
        if (!*(SafeAllocator**)(self + kBackupAllocator)) HaltSystem();
        if (*(SafeAllocator**)(self + kBackupAllocator) && *(void**)(self + Enum_020e081c_1904))
            (*(SafeAllocator**)(self + kBackupAllocator))->Free(*(void**)(self + Enum_020e081c_1904));
        *(unsigned int*)(self + Enum_020e081c_1908) = Enum_020e081c_13312;
        *(void**)(self + Enum_020e081c_1904) = (*(SafeAllocator**)(self + kBackupAllocator))->Allocate(*(unsigned int*)(self + Enum_020e081c_1908));
        VectorizedInvertedMemcpy((const void*)0x06600000, *(void**)(self + Enum_020e081c_1904), *(unsigned int*)(self + Enum_020e081c_1908));
        OS_WaitVBlankIntr();
#if defined(jpn)
        func_02020cb8(self, *(int*)(self + Enum_020e081c_2556));
#else
        func_02020cb8(self, (int*)(self + Enum_020e081c_2556));
#endif
        MapDisplay_RemoveTask(self, (int*)(self + kObjectTask));
        func_02021410((Struct_02021410*)self, 1, 3);
        *(unsigned char*)(self + Enum_020e081c_2499) = 0;
        ++*(signed char*)(self + Enum_020e081c_2498);
    }
}
