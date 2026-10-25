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
int GetField5cb0Value_0201079c(char* battleStruct);
int GetField5cb4Value_020107d0(char* battleStruct);
int IsInRange0201b5b0(int monsterId);
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

    var0 = arg0->unknown_8_;
    func_0209bffc(&var0->unknown_44_);
    if (var2->GetDetailedTaskStatus(arg0->unknown_c_) == BackgroundLoader::TaskStatus_Complete) {
        unsigned int var5;
        void* var6;
        var2->GetLoadedFileByID(arg0->unknown_c_, &var6, &var5);
        if (var6 != 0) {
            int var7 = func_0201079c((char*)var1);
            int var8 = func_020107d0((char*)var1);
            int var9 = var4;
            if (func_0201b5b0(var4)) {
                int var10 = var3->GetFloorMonsterRank(var4 % 20);
                int var11 = var3->GetActiveGrottoEnviron();
                var9 = var10 + (var11 * 100 + 0x9c40);
            }
            func_0209c008(&var0->unknown_44_, (struct Struct_02013fb4*)var6, var5, var9, var7, var8);
        }
    }

    if (arg0->unknown_12_ != 0) {
        func_0209c08c(&var0->unknown_44_, arg0->unknown_12_);
    }
    if (func_0201b5b0(var4)) {
        func_0209c08c(&var0->unknown_44_, 0x26);
        func_0209c08c(&var0->unknown_44_, 0x27);
        func_0209c08c(&var0->unknown_44_, 0x28);
    }

    var2->RemoveTask(arg0->unknown_c_);
    arg0->unknown_c_ = -1;
    arg0->unknown_c_ = var2->QueueLoadFile(&data_ov017_021d7b5d, 0);
    arg0->unknown_10_ = 4;
}
