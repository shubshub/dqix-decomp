#if defined(jpn)
enum { Enum_ov017_021b3780_336 = 0x144 };
#else
enum { Enum_ov017_021b3780_336 = 0x150 };
#endif

#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "std_library_functions.h"

extern "C" int func_02053c6c(unsigned char* arg0);

struct Struct_020534ac;
extern "C" void* func_02099ff0(void* arg0);

struct Struct_0209a088_2;
struct Struct_0209a088 {
    char unknown_0_[0xc];
};
extern "C" void func_0209a088(struct Struct_0209a088* arg0, struct Struct_0209a088_2* arg1);

extern "C" void* func_0209a004(void* arg0, int arg1);

extern "C" void PartyMember_RecalculateStats(void* a, int arg2);

extern unsigned char data_ov017_021d6b20;

struct Struct_ov017_021b3780 {
    unsigned int unknown_0_[10];
    short unknown_28_;
    char unknown_2a_[2];
};

struct Struct_ov017_021b3780_2 {
    char unknown_0_[0x8];
    short unknown_8_;
    char unknown_a_[6];
    int unknown_10_;
};

// USA: func_ov017_021b3780
extern "C" ARM int func_ov017_021b3780(struct Struct_ov017_021b3780_2* arg0) {
    GameState* var0 = GameState::GetInstance();
    int var1 = (int)BackgroundLoader::GetInstance();
    if (!((BackgroundLoader*)(var1))->GetTaskStatus((int)(arg0->unknown_10_))) {
        return 0;
    }
    GameObject* var2 = func_0200ff1c(var0, arg0->unknown_8_);
    if (!var2) {
        return 0;
    }
    int var3 = func_02053c6c((unsigned char*)var2);
    if (!var3) {
        return 0;
    }

    int var4 = arg0->unknown_10_;
    int var5;
    volatile int var6;
    ((BackgroundLoader*)((struct Struct_020534ac*)var1))->GetLoadedFileByID((int)(var4), (void**)(&var5), (unsigned int*)((int*)&var6));

    struct Struct_0209a088 var7;
    func_02099ff0(&var7);
    int var8 = var6;
    func_0209a088(&var7, (struct Struct_0209a088_2*)var5);

    struct Struct_ov017_021b3780* var9 = (struct Struct_ov017_021b3780*)(*(char**)((char*)var2 + Enum_ov017_021b3780_336) + 0x2f4);
    unsigned char* var10 = &data_ov017_021d6b20;
    int var11;
    for (var11 = 0; var11 < 8; var11++, var10++, var9++) {
        var9->unknown_0_[0] = 0;
        var9->unknown_0_[1] = 0;
        var9->unknown_0_[2] = 0;
        var9->unknown_0_[3] = 0;
        var9->unknown_0_[4] = 0;
        var9->unknown_0_[5] = 0;
        var9->unknown_0_[6] = 0;
        var9->unknown_0_[7] = 0;
        var9->unknown_0_[8] = 0;
        var9->unknown_0_[9] = 0;
        var9->unknown_28_ = -1;

        unsigned char var12 = *var10;
        short var13 = *(short*)((char*)var3 + var12 * 0x20 + 0x100 + 0xac);
        if (var13 > 0) {
            void* var14 = func_0209a004(&var7, var13);
            if (var14) {
                memcpy(var9, var14, 0x2c);
            }
        }
    }

    ((BackgroundLoader*)(loadedList))->RemoveTask((int)(key));
    ctx->listKey = -1;
    PartyMember_RecalculateStats((void*)base150, 0);
    return 1;
}
