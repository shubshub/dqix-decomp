#if defined(jpn)
#define R(j,u) (j)
#define func_ov013_021846a0 func_ov013_021856dc
#define func_ov013_02184d80 func_ov013_02185db4
#define func_ov013_02186160 func_ov013_02187178
#define func_ov013_021864f0 func_ov013_02187820
#define func_ov013_0218678c func_ov013_02187ab8
#define func_ov013_0218683c func_ov013_02187b68
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Resource/Brightness.h"

struct Entry_0205d6a0;
extern "C" void Window_ClosePane(Entry_0205d6a0*, int);
extern "C" void* GlobalFlags_GetInstance();
struct FlagWord020466f4;
extern "C" void FlagWord_ClearBits(FlagWord020466f4*, unsigned int);

struct Struct_ov008_0218b240 {
    char pad0[R(0xe95,0xe99)];
    unsigned char unknown_e99_;
    unsigned char unknown_e9a_;
    unsigned char unknown_e9b_;
    unsigned char unknown_e9c_;
    char pad1[0xea0 - 0xe9d];
    int unknown_ea0_;
    int unknown_ea4_;
    int unknown_ea8_;
    char pad2[R(4,0xeb4 - 0xeac)];
    int unknown_eb4_;
    char pad3[0xec0 - 0xeb8];
    unsigned char bit0 : 1;
    unsigned char unknown_ec0_1_ : 1;
    unsigned char bit2 : 1;
    unsigned char unknown_ec0_3_ : 1;
    unsigned char rest : 4;
};

// USA: func_ov008_0218b240
extern "C" ARM void func_ov008_0218b240(Struct_ov008_0218b240* obj) {
    if (obj->unknown_ec0_3_) return;

    GameState::GetInstance();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();

    obj->bit0 = 0;
    Window_ClosePane((Entry_0205d6a0*)((char*)obj + 0x18), 1);

    obj->unknown_e99_ = 2;
    obj->unknown_e9a_ = 0;
    obj->unknown_e9b_ = 2;
    obj->unknown_e9c_ = 0;

    void* ptr = GlobalFlags_GetInstance();
    FlagWord_ClearBits((FlagWord020466f4*)ptr, 0x2f);
    ClearFlags00(GetGameResources(), 0x10);

    loader->RemoveTask(obj->unknown_ea0_);
    loader->RemoveTask(obj->unknown_eb4_);
    loader->RemoveTask(obj->unknown_ea4_);
    loader->RemoveTask(obj->unknown_ea8_);

    obj->unknown_ea0_ = -1;
    obj->unknown_eb4_ = -1;
    obj->unknown_ea4_ = -1;
    obj->unknown_ea8_ = -1;

    obj->unknown_ec0_3_ = 1;
}
