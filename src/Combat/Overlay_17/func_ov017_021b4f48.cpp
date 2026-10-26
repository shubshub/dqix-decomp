#if defined(jpn)
enum { Enum_ov017_021b4f48_9196 = 0x240c, Enum_ov017_021b4f48_96 = 0x5c };
#else
enum { Enum_ov017_021b4f48_9196 = 0x23ec, Enum_ov017_021b4f48_96 = 0x60 };
#endif

#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Grotto/Main/ActiveGrottoClass.h"

struct Struct_02013fb4;

extern "C" char* Zone3D_GetInstance(void);
int GameState_GetStoryChapter(char* battleStruct);
int GameState_GetStoryPart(char* battleStruct);
int ZoneId_IsMainGrottoFloor(int monsterId);
void SetupAndRunBufferedScript0209bc98(
    void* dest, struct StreamHeader* data, int size, int param,
    int monsterId, int field5cb0, int field5cb4);

extern const char data_ov017_021d7b71;

struct Struct_ov017_021b4f48 {
    unsigned short unknown_0_;
    char unknown_2_[0x10 - 0x2];
    int unknown_10_;
};

struct Struct_ov017_021b4f48_2 {
    char unknown_0_[8];
    struct Struct_ov017_021b4f48* unknown_8_;
    int unknown_c_;
    unsigned char unknown_10_;
};

// USA: func_ov017_021b4f48
extern "C" ARM void func_ov017_021b4f48(struct ScriptRequest_021b4f48* request) {
    GameState* battle = GameState::GetInstance();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    ActiveGrottoClass* grotto = (ActiveGrottoClass*)((char*)Zone3D_GetInstance() + RegionOffset23ec);

    if (var1->GetTaskStatus(arg0->unknown_c_) == 0) {
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
                int environ = grotto->GetActiveGrottoEnviron();
                monsterId = rank + (environ * 100 + 0x9c40);
            }
            func_0209bc98(
                (char*)arg0->unknown_8_ + Enum_ov017_021b4f48_96, (struct Struct_02013fb4*)var4, var3,
                arg0->unknown_8_->unknown_10_, var5, var6, var7);
        }
    }
    var1->RemoveTask(arg0->unknown_c_);
    arg0->unknown_c_ = -1;
    arg0->unknown_c_ = var1->QueueLoadFile(&data_ov017_021d7b71, 0);
    arg0->unknown_10_ = BackgroundLoader::TaskStatus_Fence;
}
