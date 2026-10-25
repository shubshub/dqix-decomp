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
int GetField5cb0Value_0201079c(char* battleStruct);
int GetField5cb4Value_020107d0(char* battleStruct);
int IsInRange0201b5b0(int monsterId);
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
    if (var1->GetDetailedTaskStatus(arg0->unknown_c_) == BackgroundLoader::TaskStatus_Complete) {
        unsigned int var3;
        void* var4;
        var1->GetLoadedFileByID(arg0->unknown_c_, &var4, &var3);
        if (var4 != 0) {
            int var5 = arg0->unknown_8_->unknown_0_;
            int var6 = func_0201079c((char*)var0);
            int var7 = func_020107d0((char*)var0);
            if (func_0201b5b0(var5)) {
                int var8 = var2->GetFloorMonsterRank(var5 % 20);
                int var9 = var2->GetActiveGrottoEnviron();
                var5 = var8 + (var9 * 100 + 0x9c40);
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
