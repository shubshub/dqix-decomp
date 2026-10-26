#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Grotto/Main/ActiveGrottoClass.h"

struct Struct_02013fb4;
struct Struct_0209c08c {
    unsigned short unknown_0_[0xc];
    unsigned short unknown_18_;
};

extern "C" char* Zone3D_GetInstance(void);
int GameState_GetStoryChapter(char* battleStruct);
int GameState_GetStoryPart(char* battleStruct);
int ZoneId_IsMainGrottoFloor(int monsterId);
extern "C" void func_0209c008(void* obj, struct StreamHeader* buffer, int length, int idFlag, int mulVal, int addVal);
void ClearHalfword0x18_0209bffc(void* obj);
void AppendHalfwordCapped_0209c08c(BoundedArray* arr, unsigned short value);

extern const char data_ov017_021d7b5d;

struct Struct_ov017_021b4dc8 {
    unsigned short unknown_0_;
#if defined(jpn)
    char unknown_2_[0x40 - 0x2];
#else
    char unknown1_2_[0x44 - 0x2];
#endif

    Struct_0209c08c unknown_44_;
};

struct Struct_ov017_021b4dc8_2 {
    char unknown_0_[8];
    struct Struct_ov017_021b4dc8* unknown_8_;
    int unknown_c_;
    unsigned char unknown_10_;
    char unknown_11_;
    unsigned short unknown_12_;
};

// USA: func_ov017_021b4dc8
extern "C" ARM void func_ov017_021b4dc8(struct Struct_ov017_021b4dc8_2* arg0) {
#if defined(jpn)
 enum {Enum_ov017_021b4dc8_9196=0x240c};
#else
 enum {Enum_ov017_021b4dc8_9196=0x23ec};
#endif
    ScriptSource_021b4dc8* source;
    GameState* battle = GameState::GetInstance();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    ActiveGrottoClass* grotto = (ActiveGrottoClass*)((char*)Zone3D_GetInstance() + regionalOffset0);
    int monsterId = request->source->monsterId;

    if (var2->GetTaskStatus(arg0->unknown_c_) == 0) {
        return;
    }

    source = request->source;
    ClearHalfword0x18_0209bffc(&source->entries);
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
                int environ = grotto->GetActiveGrottoEnviron();
                scriptId = rank + (environ * 100 + 0x9c40);
            }
            func_0209c008(&var0->unknown_44_, (struct Struct_02013fb4*)var6, var5, var9, var7, var8);
        }
    }

    if (arg0->unknown_12_ != 0) {
        func_0209c08c(&var0->unknown_44_, arg0->unknown_12_);
    }
    if (ZoneId_IsMainGrottoFloor(monsterId)) {
        AppendHalfwordCapped_0209c08c(&source->entries, 0x26);
        AppendHalfwordCapped_0209c08c(&source->entries, 0x27);
        AppendHalfwordCapped_0209c08c(&source->entries, 0x28);
    }

    var2->RemoveTask(arg0->unknown_c_);
    arg0->unknown_c_ = -1;
    arg0->unknown_c_ = var2->QueueLoadFile(&data_ov017_021d7b5d, 0);
    arg0->unknown_10_ = 4;
}
