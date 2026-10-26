#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Resource/GameResources.h"
#include "NitroSDK/Memory.h"
#include "Resource/Brightness.h"


#if defined(jpn)
enum { Enum_020e081c_1900 = 0x6c0, Enum_020e081c_1904 = 0x6c4, Enum_020e081c_1908 = 0x6c8,
       Enum_020e081c_2498 = 0x916, Enum_020e081c_2499 = 0x917, Enum_020e081c_2556 = 0x950, Enum_020e081c_2568 = 0x95c,
       Enum_020e081c_13312 = 0x2500, Enum_020e081c_600 = 0x200, Enum_020e081c_1288 = 0x608 };
#define data_020f2b78 data_020f2cd0
extern const char data_020f2ce8[];
#else
enum { Enum_020e081c_1900 = 0x76c, Enum_020e081c_1904 = 0x770, Enum_020e081c_1908 = 0x774,
       Enum_020e081c_2498 = 0x9c2, Enum_020e081c_2499 = 0x9c3, Enum_020e081c_2556 = 0x9fc, Enum_020e081c_2568 = 0xa08,
       Enum_020e081c_13312 = 0x3400, Enum_020e081c_600 = 0x258, Enum_020e081c_1288 = 0x508 };
extern const char data_020f2b90[];
extern const char data_020f2ba2[];
#endif

struct Struct0205a198 { char bytes[0x28]; };
struct PacRecord;
struct SetFlagStruct;
struct ToggleState;
struct Script020e081c {
    char unknown0[0x40];
    Struct0205a198* records;
    char unknown44[8];
    unsigned short count;
    char unknown4e[2];
    unsigned char active;
    char unknown51[3];
};

extern "C" void* Zone3D_GetInstance();
extern "C" char* OamManager_GetInstance();
char* BgVram_GetInstance();
void MapDisplay_SetHoldSubScreenDark(SetFlagStruct*, int);
extern "C" void MapDisplay_FadeOutSubScreen(void*, int);
void InitSubScreenDisplay_020209d0(void* context);
void BgVram_Reset(char*);
void OamManager_Init(char*);
void Sprite_Init(Struct0205a198*);
void SpriteContext_Init(char*);
int SpriteContext_LoadArchive(void*, PacRecord*, int, void*);
void* CachedTextTable_GetInstance();
extern "C" void* OamManager_GetSubOamBuffer(char*);
extern "C" void HaltSystem();
void OS_WaitVBlankIntr();
#if defined(jpn)
extern "C" void func_02020cb8(void*, int);
#else
extern "C" void func_02020cb8(void*, int*);
#endif
void MapDisplay_RemoveTask(void*, int*);
void SetToggleState_02021410(ToggleState*, int, int);
extern const char data_020f2b78[];

static inline SafeAllocator* inline_02021578(GameResources* arg0, int arg1) {
    return &arg0->allocator_array_38[arg1];
}

// KEEP-NAME: func_020e081c is the shared regional export.
// USA: func_020e081c
extern "C" ARM void func_020e081c(char* arg0) {
    GameState::GetInstance();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    Zone3D_GetInstance();
    GameResources* resources = GetGameResources();
    char* battle = OamManager_GetInstance();
    char* table = BgVram_GetInstance();
    SafeAllocator* allocator = GetResourceAllocator(resources, 12);
    if (*(signed char*)(self + kStage) == 0) {
        MapDisplay_SetHoldSubScreenDark((SetFlagStruct*)self, 0);
        MapDisplay_FadeOutSubScreen(self, 0x19);
        InitSubScreenDisplay_020209d0(self);
        allocator->Reset();
        BgVram_Reset(table);
        OamManager_Init(battle);
        for (int i = 0; i < 28; ++i)
            Sprite_Init(&((Struct0205a198*)(self + 0xe8))[i]);
        SpriteContext_Init(self + 0x94);
        Script020e081c* script = (Script020e081c*)(self + 0x94);
        script->active = 1;
        script->records = (Struct0205a198*)(self + 0xe8);
        script->count = 5;
        loader->AddFence();
        *(int*)(self + kBaseTask) = loader->QueueLoadFile(data_020f2b78, 0);
#if defined(jpn)
        *(int*)(arg0 + Enum_020e081c_2568) = var0->QueueLoadFile(data_020f2ce8, 0);
#else
        *(int*)(arg0 + Enum_020e081c_2568) = var0->QueueLoadFileInGP2(data_020f2b90, data_020f2ba2, 0);
#endif
        ++*(signed char*)(self + kStage);
    } else if (*(signed char*)(self + kStage) == 1) {
        if (!loader->GetTaskStatus(*(int*)(self + kBaseTask))) return;
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
        if (*(SafeAllocator**)(self + kBackupAllocator) && *(void**)(self + kBackupBuffer))
            (*(SafeAllocator**)(self + kBackupAllocator))->Free(*(void**)(self + kBackupBuffer));
        *(unsigned int*)(self + kBackupSize) = kBackupBytes;
        *(void**)(self + kBackupBuffer) = (*(SafeAllocator**)(self + kBackupAllocator))->Allocate(*(unsigned int*)(self + kBackupSize));
        VectorizedInvertedMemcpy((const void*)0x06600000, *(void**)(self + kBackupBuffer), *(unsigned int*)(self + kBackupSize));
        OS_WaitVBlankIntr();
#if defined(jpn)
        func_02020cb8(arg0, *(int*)(arg0 + Enum_020e081c_2556));
#else
        func_02020cb8(arg0, (int*)(arg0 + Enum_020e081c_2556));
#endif
        MapDisplay_RemoveTask(self, (int*)(self + kObjectTask));
        SetToggleState_02021410((ToggleState*)self, 1, 3);
        *(unsigned char*)(self + kActive) = 0;
        ++*(signed char*)(self + kStage);
    }
}
