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

struct Struct_02038598_4;
struct Struct_02074bd0;
struct Struct_0207fcb8;
struct Struct_0207fd44_2;
struct Struct_0207fd88;

void* GlobalFlags_GetInstance(void);
void FlagWord_ClearBits(struct FlagWord020466f4* word, unsigned int mask);
void ClearFlag0x10IfSet(struct Struct02074bd0* obj);
void ClearAllBuffers0207fcb8(struct Obj0207fcb8* obj);
void CallFunc0204b04cOverList0x2c(struct Cont0207fd44* obj);
void CallFunc0204b088OverList0x2c(struct Cont0207fd88* obj);
extern "C" void* memset(void* dst, int val, unsigned int len);
void CleanInvalidateCacheRange(const void* addr, unsigned int size);
extern "C" int LoadToMainBG1CharacterData(int arg0, int arg1, unsigned int arg2);
int MessageSystem_GetInstance(void);
void MessageSystem_Reset(char* obj);
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
    Struct_0207f7f0* unknown_324_;
    unsigned char unknown_328_[0x8];
    int unknown_330_;
    unsigned char unknown_334_[0x64];
    void* unknown_398_;
    unsigned char unknown_39c_[Enum_ov003_0215fb94_208];
    int unknown_46c_;
};

// USA: func_ov003_0215fb94
extern "C" ARM void func_ov003_0215fb94(BattleView0215fb94* view) {
    FlagWord_ClearBits((struct FlagWord020466f4*)GlobalFlags_GetInstance(), 0x80000);
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    if (view->loadTaskId >= 0) {
        loader->RemoveTask(view->loadTaskId);
        view->loadTaskId = -1;
    }

    GameResources* var1 = GetGameResources();
    volatile unsigned int* var2 = (volatile unsigned int*)0x4000000;
    *var2 = (*var2 & ~0x1f00) | (arg0->unknown_330_ << 8);
    ClearFlags04(var1, 0xc0);
    *var2 = (*var2 & ~0x1f00) | 0x100;
    *(volatile unsigned short*)0x4000050 = 0;

    func_02074bd0((struct Struct_02074bd0*)arg0->unknown_2f4_);

    Struct_0207f7f0* var3 = arg0->unknown_324_;
    if (var3 != NULL) {
        func_0207fcb8((struct Struct_0207fcb8*)var3);
        func_0207fd44((struct Struct_0207fd44_2*)var3);
        func_0207fd88((struct Struct_0207fd88*)var3);
        func_0207f8bc(var3);
    }

    if (arg0->unknown_398_ != NULL) {
        memset(arg0->unknown_398_, 0, 0x20);
        CleanInvalidateCacheRange(arg0->unknown_398_, 0x20);
        LoadToMainBG1CharacterData((int)arg0->unknown_398_, 0, 0x20);
    }
    arg0->unknown_398_ = NULL;

    char* controller = (char*)MessageSystem_GetInstance();
    if (*(int*)(controller + kRegion998) != 0) {
        MessageSystem_Reset(controller);
        MessageSystem_Stop(controller);
    }
    *(int*)(var4 + Enum_ov003_0215fb94_728) = 0;
    var4[Enum_ov003_0215fb94_742] = 1;

    arg0->unknown_2c8_.Destroy();
    arg0->unknown_2b4_.Destroy();
    arg0->unknown_2a0_.Destroy();
    arg0->unknown_28c_.Destroy();
    arg0->unknown_278_.Destroy();
    arg0->unknown_264_.Destroy();
    arg0->unknown_23c_.Destroy();
    arg0->unknown_228_.Destroy();
}
