#include <globaldefs.h>
#include "Combat/MenuNodeChain.h"
#if defined(jpn)
enum { Enum_ov003_021549a8_728 = 0x228 };
enum { Enum_ov003_021549a8_732 = 0x22c };
enum { Enum_ov003_021549a8_742 = 0x236 };
enum { Enum_ov003_021549a8_743 = 0x237 };
enum { Enum_ov003_021549a8_2456 = 0x868 };
enum { Enum_ov003_021549a8_352 = 0x15c };
enum { Enum_ov003_021549a8_464 = 0x1cc };
enum { Enum_ov003_021549a8_468 = 0x1d0 };
enum { Enum_ov003_021549a8_516 = 0x200 };
enum { Enum_ov003_021549a8_520 = 0x204 };
enum { Enum_ov003_021549a8_524 = 0x208 };
#else
enum { Enum_ov003_021549a8_728 = 0x2d8 };
enum { Enum_ov003_021549a8_732 = 0x2dc };
enum { Enum_ov003_021549a8_742 = 0x2e6 };
enum { Enum_ov003_021549a8_743 = 0x2e7 };
enum { Enum_ov003_021549a8_2456 = 0x998 };
enum { Enum_ov003_021549a8_352 = 0x160 };
enum { Enum_ov003_021549a8_464 = 0x1d0 };
enum { Enum_ov003_021549a8_468 = 0x1d4 };
enum { Enum_ov003_021549a8_516 = 0x204 };
enum { Enum_ov003_021549a8_520 = 0x208 };
enum { Enum_ov003_021549a8_524 = 0x20c };
#endif
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Cache.h"
#include "std_library_functions.h"

extern "C" void func_ov023_021eb26c(void* arg0);
struct Struct_02074bd0;
extern "C" void func_02074bd0(struct Struct_02074bd0* arg0);
struct Struct_0207fcb8;
extern "C" void func_0207fcb8(struct Struct_0207fcb8* arg0);
struct Struct_0207fd44_2;
extern "C" void func_0207fd44(struct Struct_0207fd44_2* arg0);
struct Struct_0207fd88;
extern "C" void func_0207fd88(struct Struct_0207fd88* arg0);
extern "C" int LoadToMainBG1CharacterData(int src, int offset, unsigned int size);
void MessageSystem_Reset(char* obj);
extern "C" void MessageSystem_Stop(void* self);

struct Struct_ov003_021549a8 {
    char unknown_0_[Enum_ov003_021549a8_728];
    int unknown_2d8_;
    char unknown_2dc_[Enum_ov003_021549a8_742 - Enum_ov003_021549a8_732];
    unsigned char unknown_2e6_;
    char unknown_2e7_[Enum_ov003_021549a8_2456 - Enum_ov003_021549a8_743];
    int unknown_998_;
};
Controller020421a0* MessageSystem_GetInstance(void);

struct Struct_ov003_021549a8_2 {
    SafeAllocator* unknown_0_;
    char unknown_4_[0xc - 0x4];
    void* unknown_c_;
    char unknown_10_[0x18 - 0x10];
    Struct_0207f7f0* unknown_18_;
    char unknown_1c_[Enum_ov003_021549a8_352 - 0x1c];
    char unknown_160_[Enum_ov003_021549a8_464 - Enum_ov003_021549a8_352];
    int unknown_1d0_;
    char unknown_1d4_[Enum_ov003_021549a8_516 - Enum_ov003_021549a8_468];
    void* unknown_204_;
    char unknown_208_[Enum_ov003_021549a8_524 - Enum_ov003_021549a8_520];
    int unknown_20c_;
};

// USA: func_ov003_021549a8
extern "C" ARM void func_ov003_021549a8(Struct_ov003_021549a8_2* arg0) {
    BackgroundLoader* var0 = BackgroundLoader::GetInstance();
    if (arg0->unknown_1d0_ >= 0) {
        var0->RemoveTask(arg0->unknown_1d0_);
        arg0->unknown_1d0_ = -1;
    }
    if (arg0->unknown_20c_ >= 0) {
        var0->RemoveTask(arg0->unknown_20c_);
        arg0->unknown_20c_ = -1;
    }
    if (arg0->unknown_204_ != NULL) {
        func_ov023_021eb26c(arg0->unknown_204_);
        arg0->unknown_204_ = NULL;
    }

    unsigned int* var1 = (unsigned int*)0x4000000;
    *var1 = (*var1 & ~0x1f00) | 0x100;
    *(unsigned short*)0x4000050 = 0;
    func_02074bd0((struct Struct_02074bd0*)arg0->unknown_160_);

    Struct_0207f7f0* var2 = arg0->unknown_18_;
    if (var2 != NULL) {
        func_0207fcb8((struct Struct_0207fcb8*)var2);
        func_0207fd44((struct Struct_0207fd44_2*)var2);
        func_0207fd88((struct Struct_0207fd88*)var2);
        func_0207f8bc(var2);
    }

    if (arg0->unknown_c_ != NULL) {
        memset(arg0->unknown_c_, 0, 0x20);
        CleanInvalidateCacheRange(arg0->unknown_c_, 0x20);
        LoadToMainBG1CharacterData((int)arg0->unknown_c_, 0, 0x20);
    }
    arg0->unknown_c_ = NULL;

    Controller020421a0* g = MessageSystem_GetInstance();
    if (g->active != 0) {
        MessageSystem_Reset((char*)g);
        MessageSystem_Stop(g);
    }
    var3->unknown_2d8_ = 0;
    var3->unknown_2e6_ = 1;

    if (arg0->unknown_0_ != NULL) {
        for (unsigned char var4 = 0; var4 < 8; var4++) {
            arg0->unknown_0_[var4].Destroy();
        }
    }
}
