#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Grotto/Main/ActiveGrottoClass.h"

struct StreamHeader;
struct Struct_0209c08c {
    unsigned short items[0xc];
    unsigned short count;
};

extern "C" char* Zone3D_GetInstance(void);
extern "C" int GameState_GetStoryChapter(char* battleStruct);
extern "C" int GameState_GetStoryPart(char* battleStruct);
extern "C" int ZoneId_IsMainGrottoFloor(int monsterId);
extern "C" void func_0209c008(void* obj, struct StreamHeader* buffer, int length, int arg3, int arg4, int arg5);
extern "C" void func_0209bffc(void* obj);
extern "C" void func_0209c08c(Struct_0209c08c* arr, unsigned short value);

extern const char data_ov017_021d7b5d;

struct Struct_ov017_021b4dc8 {
    unsigned short monsterId;
#if defined(jpn)
    char pad2[0x40 - 0x2];
#else
    char pad2[0x44 - 0x2];
#endif

    Struct_0209c08c entries;
};

struct Struct_ov017_021b4dc8_2 {
    char pad0[8];
    struct Struct_ov017_021b4dc8* source;
    int taskId;
    unsigned char state;
    char unknown_11_;
    unsigned short unknown_12_;
};

// USA: func_ov017_021b4dc8
extern "C" ARM void func_ov017_021b4dc8(struct Struct_ov017_021b4dc8_2* request) {
#if defined(jpn)
 enum {regionalOffset0=0x240c};
#else
 enum {regionalOffset0=0x23ec};
#endif
    Struct_ov017_021b4dc8* source;
    GameState* battle = GameState::GetInstance();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    ActiveGrottoClass* grotto = (ActiveGrottoClass*)((char*)Zone3D_GetInstance() + regionalOffset0);
    int monsterId = request->source->monsterId;

    if (loader->GetTaskStatus(request->taskId) == 0) {
        return;
    }

    source = request->source;
    func_0209bffc(&source->entries);
    if (loader->GetDetailedTaskStatus(request->taskId) == BackgroundLoader::TaskStatus_Complete) {
        unsigned int size;
        void* data;
        loader->GetLoadedFileByID(request->taskId, &data, &size);
        if (data != 0) {
            int field5cb0 = GameState_GetStoryChapter((char*)battle);
            int field5cb4 = GameState_GetStoryPart((char*)battle);
            int scriptId = monsterId;
            if (ZoneId_IsMainGrottoFloor(monsterId)) {
                int rank = grotto->GetFloorMonsterRank(monsterId % 20);
                int var11 = grotto->GetActiveGrottoEnviron();
                scriptId = rank + (var11 * 100 + 0x9c40);
            }
            func_0209c008(&source->entries, (struct StreamHeader*)data, size, scriptId, field5cb0, field5cb4);
        }
    }

    if (request->unknown_12_ != 0) {
        func_0209c08c(&source->entries, request->unknown_12_);
    }
    if (ZoneId_IsMainGrottoFloor(monsterId)) {
        func_0209c08c(&source->entries, 0x26);
        func_0209c08c(&source->entries, 0x27);
        func_0209c08c(&source->entries, 0x28);
    }

    loader->RemoveTask(request->taskId);
    request->taskId = -1;
    request->taskId = loader->QueueLoadFile(&data_ov017_021d7b5d, 0);
    request->state = 4;
}
