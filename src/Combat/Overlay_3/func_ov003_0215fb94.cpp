#include <globaldefs.h>
#include "Combat/MenuNodeChain.h"
#if defined(jpn)
enum { Enum_ov003_0215fb94_552 = 0x110 };
enum { Enum_ov003_0215fb94_208 = 0x10 };
enum { Enum_ov003_0215fb94_2456 = 0x868 };
enum { Enum_ov003_0215fb94_728 = 0x228 };
enum { Enum_ov003_0215fb94_742 = 0x236 };
#else
enum { Enum_ov003_0215fb94_552 = 0x228 };
enum { Enum_ov003_0215fb94_208 = 0xd0 };
enum { Enum_ov003_0215fb94_2456 = 0x998 };
enum { Enum_ov003_0215fb94_728 = 0x2d8 };
enum { Enum_ov003_0215fb94_742 = 0x2e6 };
#endif
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "Resource/Brightness.h"

struct FlagWord020466f4;
struct Struct_02074bd0;
struct Struct_0207fcb8;
struct Struct_0207fd44_2;
struct Struct_0207fd88;

extern "C" void* GlobalFlags_GetInstance(void);
extern "C" void FlagWord_ClearBits(struct FlagWord020466f4* word, unsigned int mask);
extern "C" void func_02074bd0(struct Struct_02074bd0* obj);
extern "C" void func_0207fcb8(struct Struct_0207fcb8* obj);
extern "C" void func_0207fd44(struct Struct_0207fd44_2* obj);
extern "C" void func_0207fd88(struct Struct_0207fd88* obj);
extern "C" void* memset(void* dst, int val, unsigned int len);
void CleanInvalidateCacheRange(const void* addr, unsigned int size);
extern "C" int LoadToMainBG1CharacterData(int arg0, int arg1, unsigned int arg2);
extern "C" int MessageSystem_GetInstance(void);
extern "C" void MessageSystem_Reset(char* obj);
extern "C" void MessageSystem_Stop(char* obj);

struct Struct_ov003_0215fb94 {
    unsigned char unknown_0_[Enum_ov003_0215fb94_552];
    SafeAllocator unknown_228_;
    SafeAllocator unknown_23c_;
    unsigned char unknown_250_[0x14];
    SafeAllocator unknown_264_;
    SafeAllocator unknown_278_;
    SafeAllocator unknown_28c_;
    SafeAllocator unknown_2a0_;
    SafeAllocator unknown_2b4_;
    SafeAllocator unknown_2c8_;
    unsigned char unknown_2dc_[0x18];
    unsigned char unknown_2f4_[0x30];
    Manager0207f7f0* unknown_324_;
    unsigned char unknown_328_[0x8];
    int unknown_330_;
    unsigned char unknown_334_[0x64];
    void* unknown_398_;
    unsigned char unknown_39c_[Enum_ov003_0215fb94_208];
    int unknown_46c_;
};

// USA: func_ov003_0215fb94
extern "C" ARM void func_ov003_0215fb94(Struct_ov003_0215fb94* view) {
    FlagWord_ClearBits((struct FlagWord020466f4*)GlobalFlags_GetInstance(), 0x80000);
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    if (view->unknown_46c_ >= 0) {
        loader->RemoveTask(view->unknown_46c_);
        view->unknown_46c_ = -1;
    }

    GameResources* resources = GetGameResources();
    volatile unsigned int* dispcnt = (volatile unsigned int*)0x4000000;
    *dispcnt = (*dispcnt & ~0x1f00) | (view->unknown_330_ << 8);
    ClearFlags04(resources, 0xc0);
    *dispcnt = (*dispcnt & ~0x1f00) | 0x100;
    *(volatile unsigned short*)0x4000050 = 0;

    func_02074bd0((struct Struct_02074bd0*)view->unknown_2f4_);

    Manager0207f7f0* sub = view->unknown_324_;
    if (sub != NULL) {
        func_0207fcb8((struct Struct_0207fcb8*)sub);
        func_0207fd44((struct Struct_0207fd44_2*)sub);
        func_0207fd88((struct Struct_0207fd88*)sub);
        func_0207f8bc(sub);
    }

    if (view->unknown_398_ != NULL) {
        memset(view->unknown_398_, 0, 0x20);
        CleanInvalidateCacheRange(view->unknown_398_, 0x20);
        LoadToMainBG1CharacterData((int)view->unknown_398_, 0, 0x20);
    }
    view->unknown_398_ = NULL;

    char* controller = (char*)MessageSystem_GetInstance();
    if (*(int*)(controller + Enum_ov003_0215fb94_2456) != 0) {
        MessageSystem_Reset(controller);
        MessageSystem_Stop(controller);
    }
    *(int*)(controller + Enum_ov003_0215fb94_728) = 0;
    controller[Enum_ov003_0215fb94_742] = 1;

    view->unknown_2c8_.Destroy();
    view->unknown_2b4_.Destroy();
    view->unknown_2a0_.Destroy();
    view->unknown_28c_.Destroy();
    view->unknown_278_.Destroy();
    view->unknown_264_.Destroy();
    view->unknown_23c_.Destroy();
    view->unknown_228_.Destroy();
}
