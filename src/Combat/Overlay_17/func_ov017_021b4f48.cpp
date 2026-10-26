#if defined(jpn)
enum { RegionOffset23ec = 0x240c, Enum_ov017_021b4f48_96 = 0x5c };
#else
enum { RegionOffset23ec = 0x23ec, Enum_ov017_021b4f48_96 = 0x60 };
#endif

#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Grotto/Main/ActiveGrottoClass.h"

struct StreamHeader;

extern "C" char* Zone3D_GetInstance(void);
extern "C" int GameState_GetStoryChapter(char* battleStruct);
extern "C" int GameState_GetStoryPart(char* battleStruct);
extern "C" int ZoneId_IsMainGrottoFloor(int monsterId);
extern "C" void func_0209bc98(
    void* dest, struct StreamHeader* data, int size, int param,
    int monsterId, int field5cb0, int field5cb4);

extern const char data_ov017_021d7b71;

struct Struct_ov017_021b4f48 {
    unsigned short monsterId;
    char pad2[0x10 - 0x2];
    int param;
};

struct Struct_ov017_021b4f48_2 {
    char pad0[8];
    struct Struct_ov017_021b4f48* source;
    int taskId;
    unsigned char state;
};

// USA: func_ov017_021b4f48
extern "C" ARM void func_ov017_021b4f48(struct Struct_ov017_021b4f48_2* request) {
    GameState* battle = GameState::GetInstance();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    ActiveGrottoClass* grotto = (ActiveGrottoClass*)((char*)Zone3D_GetInstance() + RegionOffset23ec);

    if (loader->GetTaskStatus(request->taskId) == 0) {
        return;
    }
    if (loader->GetDetailedTaskStatus(request->taskId) == BackgroundLoader::TaskStatus_Complete) {
        unsigned int size;
        void* data;
        loader->GetLoadedFileByID(request->taskId, &data, &size);
        if (data != 0) {
            int monsterId = request->source->monsterId;
            int field5cb0 = GameState_GetStoryChapter((char*)battle);
            int field5cb4 = GameState_GetStoryPart((char*)battle);
            if (ZoneId_IsMainGrottoFloor(monsterId)) {
                int rank = grotto->GetFloorMonsterRank(monsterId % 20);
                int var9 = grotto->GetActiveGrottoEnviron();
                monsterId = rank + (var9 * 100 + 0x9c40);
            }
            func_0209bc98(
                (char*)request->source + Enum_ov017_021b4f48_96, (struct StreamHeader*)data, size,
                request->source->param, monsterId, field5cb0, field5cb4);
        }
    }
    loader->RemoveTask(request->taskId);
    request->taskId = -1;
    request->taskId = loader->QueueLoadFile(&data_ov017_021d7b71, 0);
    request->state = BackgroundLoader::TaskStatus_Fence;
}
