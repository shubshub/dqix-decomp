#include <globaldefs.h>
#include <Filesystem/BackgroundLoader.h>
#include <GameState/GameState.h>
#include <Memory/SafeAllocator.h>
#include <NitroSDK/Cache.h>
#include <NitroSDK/LoadToVRAM.h>
#include <std_library_functions.h>
#include "Resource/Brightness.h"

#define REG_DISPCNT (*(volatile unsigned int*)0x04000000)

struct Entry_0205d6a0;
struct Struct02074bd0;
struct BackgroundGraphics;

extern "C" void func_ov023_021dc354(void* window);
void Set3DClearColor(int a, int b, int c, int d, int e);
void Window_ClosePane(Entry_0205d6a0* window, int a);
extern "C" void Window_Destroy(void* window);
void ClearFlag0x10IfSet(Struct02074bd0* state);
void Background_ClearMap(BackgroundGraphics* bg, void* p);
extern "C" void Background_FlushMap(void* bg, int a);
extern "C" void Background_TransferMap(void* bg, int a);
void Background_Destroy(BackgroundGraphics* bg);

struct Struct_ov005_02153954 {
    SafeAllocator unknown_0_;
    SafeAllocator unknown_14_;
    SafeAllocator unknown_28_[8];
    SafeAllocator unknown_c8_[16];
    SafeAllocator unknown_208_;
    SafeAllocator unknown_21c_;
    SafeAllocator unknown_230_;
    SafeAllocator unknown_244_;
    SafeAllocator unknown_258_;
    SafeAllocator unknown_26c_;
    SafeAllocator unknown_280_;
    char unknown_294_[0xe10 - 0x294];
    unsigned short* unknown_e10_;
#if defined(jpn)
    char unknown_e14_[0xe68 - 0xe14];
#else
    char unknown1_e14_[0xe6c - 0xe14];
#endif
    char unknown_e6c_[0x10];
    char unknown_e7c_[4];
    int unknown_e80_;
    char unknown_e84_[0xee4 - 0xe84];
    char unknown_ee4_[0x1244 - 0xee4];
#if defined(jpn)
    char unknown_1244_[0x3d00 - 0x1240];
#else
    char unknown_1244_[0x3d88 - 0x1244];
#endif
    char* unknown_3d88_;
    char* unknown_3d8c_;
    char* unknown_3d90_;
    char* unknown_3d94_;
    char unknown_3d98_[0x3dc2 - 0x3d98];
    unsigned short unknown_3dc2_;
    char unknown_3dc4_[4];
    int unknown_3dc8_;
};

// USA: func_ov005_02154198
extern "C" ARM void func_ov005_02154198(Struct_ov005_02153954* arg0) {
    BackgroundLoader* var0 = BackgroundLoader::GetInstance();
    if (arg0->unknown_3dc8_ >= 0) {
        var0->RemoveTask(arg0->unknown_3dc8_);
        arg0->unknown_3dc8_ = -1;
    }
    func_ov023_021dc354(self->infoWindow_);
    Set3DClearColor(self->unk_3dc2, 0x10, 0x7fff, 0, 0);
    GameState* gameState = GameState::GetInstance();
    ClearFlags04(gameState->GetResources(), 0x800);
    REG_DISPCNT = (REG_DISPCNT & ~0x1f00) | (self->layers_ << 8);
    Window_ClosePane((Entry_0205d6a0*)self->window_, 1);
    Window_Destroy(self->window_);
    ClearFlag0x10IfSet((Struct02074bd0*)self->screenState_);
    Background_ClearMap((BackgroundGraphics*)self->backgrounds_, 0);
    Background_FlushMap(self->backgrounds_, 0);
    Background_TransferMap(self->backgrounds_, 0);
    Background_Destroy((BackgroundGraphics*)self->backgrounds_);
    if (self->pageFiles_ != NULL) {
        memset(self->pageFiles_, 0, 0x20);
        CleanInvalidateCacheRange(self->pageFiles_, 0x20);
        LoadToMainBG1CharacterData(self->pageFiles_, 0, 0x20);
    }
    arg0->unknown_14_.Destroy();
    for (int var2 = 0; var2 < 8; var2++)
        arg0->unknown_28_[var2].Destroy();
    for (int var3 = 0; var3 < 16; var3++)
        arg0->unknown_c8_[var3].Destroy();
    arg0->unknown_208_.Destroy();
    arg0->unknown_21c_.Destroy();
    arg0->unknown_0_.Destroy();
    arg0->unknown_230_.Destroy();
    arg0->unknown_244_.Destroy();
    arg0->unknown_258_.Destroy();
    arg0->unknown_26c_.Destroy();
    arg0->unknown_280_.Destroy();
    arg0->unknown_3d88_ = NULL;
    arg0->unknown_3d8c_ = NULL;
    arg0->unknown_3d90_ = NULL;
    arg0->unknown_3d94_ = NULL;
    arg0->unknown_e10_ = NULL;
}
