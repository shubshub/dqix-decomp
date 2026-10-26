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
struct Struct_02074bd0;
struct BackgroundGraphics;

extern "C" void func_ov023_021dc354(void* window);
extern "C" void Set3DClearColor(int a, int b, int c, int d, int e);
extern "C" void Window_ClosePane(Entry_0205d6a0* window, int a);
extern "C" void Window_Destroy(void* window);
extern "C" void func_02074bd0(Struct_02074bd0* state);
extern "C" void Background_ClearMap(BackgroundGraphics* bg, void* p);
extern "C" void Background_FlushMap(void* bg, int a);
extern "C" void Background_TransferMap(void* bg, int a);
extern "C" void Background_Destroy(BackgroundGraphics* bg);

struct EquipmentMenu {
    SafeAllocator allocator_;
    SafeAllocator modelAllocator_;
    SafeAllocator equippedAllocators_[8];
    SafeAllocator itemAllocators_[16];
    SafeAllocator dragAllocator_;
    SafeAllocator textAllocator_;
    SafeAllocator unknown_230_;
    SafeAllocator unknown_244_;
    SafeAllocator unknown_258_;
    SafeAllocator unknown_26c_;
    SafeAllocator unknown_280_;
    char unknown_294_[0xe10 - 0x294];
    unsigned short* text_;
#if defined(jpn)
    char unknown_e14_[0xe68 - 0xe14];
#else
    char unknown1_e14_[0xe6c - 0xe14];
#endif
    char unknown_e6c_[0x10];
    char unknown_e7c_[4];
    int layers_;
    char backgrounds_[0xee4 - 0xe84];
    char window_[0x1244 - 0xee4];
#if defined(jpn)
    char unknown_1244_[0x3d00 - 0x1240];
#else
    char unknown_1244_[0x3d88 - 0x1244];
#endif
    char* pageFiles_;
    char* dragFile_;
    char* equippedFiles_;
    char* itemFile_;
    char unknown_3d98_[0x3dc2 - 0x3d98];
    unsigned short unk_3dc2;
    char unknown_3dc4_[4];
    int task_;
};

// USA: func_ov005_02154198
extern "C" ARM void func_ov005_02154198(EquipmentMenu* self) {
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    if (self->task_ >= 0) {
        loader->RemoveTask(self->task_);
        self->task_ = -1;
    }
    func_ov023_021dc354(self->unknown_1244_);
    Set3DClearColor(self->unk_3dc2, 0x10, 0x7fff, 0, 0);
    GameState* gameState = GameState::GetInstance();
    ClearFlags04(gameState->GetResources(), 0x800);
    REG_DISPCNT = (REG_DISPCNT & ~0x1f00) | (self->layers_ << 8);
    Window_ClosePane((Entry_0205d6a0*)self->window_, 1);
    Window_Destroy(self->window_);
    func_02074bd0((Struct_02074bd0*)self->unknown_e6c_);
    Background_ClearMap((BackgroundGraphics*)self->backgrounds_, 0);
    Background_FlushMap(self->backgrounds_, 0);
    Background_TransferMap(self->backgrounds_, 0);
    Background_Destroy((BackgroundGraphics*)self->backgrounds_);
    if (self->pageFiles_ != NULL) {
        memset(self->pageFiles_, 0, 0x20);
        CleanInvalidateCacheRange(self->pageFiles_, 0x20);
        LoadToMainBG1CharacterData(self->pageFiles_, 0, 0x20);
    }
    self->modelAllocator_.Destroy();
    for (int i = 0; i < 8; i++)
        self->equippedAllocators_[i].Destroy();
    for (int i = 0; i < 16; i++)
        self->itemAllocators_[i].Destroy();
    self->dragAllocator_.Destroy();
    self->textAllocator_.Destroy();
    self->allocator_.Destroy();
    self->unknown_230_.Destroy();
    self->unknown_244_.Destroy();
    self->unknown_258_.Destroy();
    self->unknown_26c_.Destroy();
    self->unknown_280_.Destroy();
    self->pageFiles_ = NULL;
    self->dragFile_ = NULL;
    self->equippedFiles_ = NULL;
    self->itemFile_ = NULL;
    self->text_ = NULL;
}
