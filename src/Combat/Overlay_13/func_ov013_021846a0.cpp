#if defined(jpn)
#define func_ov013_021846a0 func_ov013_021856dc
#endif

#include <globaldefs.h>

#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"
#include "NitroSDK/Graphics.h"

struct MenuManager {
#if defined(jpn)
    char unknown0[0x17ee];
#else
    char unknown0[0x19be];
#endif
    unsigned char menuActive;
};

struct Struct_ov013_021846a0_2 {
    SafeAllocator allocator;
#if defined(jpn)
    char unknown14[0x1e - 0x14];
    char resetState[0x12];
#else
    char unknown14[0x20 - 0x14];
    char resetState[0x12];
    char unknown32[2];
#endif
    int unknown_34_;
    char window[0xbc];
#if defined(jpn)
    char unknown_f0_[0x598 - 0xf0];
#else
    char unknown_f4_[0x60c - 0xf4];
#endif
    SafeAllocator unknown_60c_;
    char texts[0x18];
    unsigned char unknown_638_[4];
    unsigned char state;
    unsigned char unknown_63d_;
    unsigned char step;
    bool stateChanged;
    bool subScreen;
    unsigned int ticks;
    int windowInput;
#if !defined(jpn)
    int unknown_64c_;
#endif
    int task;
    void* unknown_654_;
};

extern "C" MenuManager* MessageSystem_GetInstance(void);

struct Struct_02074bf4;
extern "C" void func_02074bf4(struct Struct_02074bf4*);
struct Struct_02074bd0;
extern "C" void func_02074bd0(struct Struct_02074bd0*);

struct Entry_0205d6a0;
extern "C" void Window_ClosePane(struct Entry_0205d6a0*, int);
struct Cont0205d1e0;
extern "C" void Window_ClearLayers(struct Cont0205d1e0*);
struct Cont0205d274;
extern "C" void Window_FlushLayers(struct Cont0205d274*);
struct Obj0205d2bc;
extern "C" void Window_TransferLayers(struct Obj0205d2bc*);
extern "C" void Window_Destroy(void*);

void CleanInvalidateCacheRange(const void*, unsigned int);
extern "C" int LoadToMainBG1CharacterData(const void*, int, unsigned int);

// USA: func_ov013_021846a0
extern "C" ARM void func_ov013_021846a0(Struct_ov013_021846a0_2* menu) {
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    if (menu->task >= 0) {
        loader->RemoveTask(menu->task);
        menu->task = -1;
    }

    MessageSystem_GetInstance()->menuActive = 0;

    if (menu->subScreen) {
        func_02074bf4((struct Struct_02074bf4*)menu->resetState);
        Window_ClosePane((struct Entry_0205d6a0*)menu->window, 1);
        Window_ClearLayers((struct Cont0205d1e0*)menu->window);
        Window_FlushLayers((struct Cont0205d274*)menu->window);
        Window_TransferLayers((struct Obj0205d2bc*)menu->window);
    } else {
        func_02074bd0((struct Struct_02074bd0*)menu->resetState);
        Window_ClearLayers((struct Cont0205d1e0*)menu->window);
        Window_FlushLayers((struct Cont0205d274*)menu->window);
        Window_TransferLayers((struct Obj0205d2bc*)menu->window);
        Window_Destroy(menu->window);

        if (menu->unknown_654_) {
            memset(menu->unknown_654_, 0, 0x20);
            CleanInvalidateCacheRange(menu->unknown_654_, 0x20);
            LoadToMainBG1CharacterData(menu->unknown_654_, 0, 0x20);
        }

        DISPCNT = (DISPCNT & ~0x1f00) | (menu->unknown_34_ << 8);
    }

    if (menu->unknown_60c_.GetSignedAllocator()) {
        menu->unknown_60c_.Destroy();
    }
    if (menu->allocator.GetSignedAllocator()) {
        menu->allocator.Destroy();
    }

    menu->state = 6;
}
