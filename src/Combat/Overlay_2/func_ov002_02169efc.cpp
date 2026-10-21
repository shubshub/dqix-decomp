#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "Resource/Brightness.h"
#include <globaldefs.h>
#include "Resource/GameResources.h"

struct Struct_ov002_02155960_2;
struct Struct_ov002_02155960_3;
struct Struct_ov002_0215624c_25;
struct Struct_ov002_02169efc;
struct Struct_ov002_02168d54_9;
struct Struct_ov002_02169efc_2;

char *GetGlobalField0x1c020421a0();
void *GetDataPtr02114e04_020d6c00();
void SetElementFieldC2_0205deb4(struct Struct_0205d81c *s, int key, int value);
extern "C" void *func_0202ae18();
extern "C" int func_0202b7d8(int *arg0);
extern "C" void func_0205def8(struct Struct_ov002_02155960_3 *arg0, int arg1, int arg2);
extern "C" void func_020466e4(unsigned int *arg0, unsigned int arg1);
struct Struct_ov002_0215624c_23;
extern "C" void func_0205a198(Struct_ov002_0215624c_23*);
struct Struct_ov002_0215624c_24;
extern "C" void func_0205a234(Struct_ov002_0215624c_24*);
extern "C" void func_0205a444(char *arg0);
extern "C" void *func_020467f0(Struct_ov002_0215624c_25 *arg0, int arg1, void **arg2, int *arg3);
extern "C" void func_0205a528(void *arg0, void *arg1, unsigned int arg2, SafeAllocator *arg3);
extern "C" void func_020a9ea4(struct Struct_ov002_02169efc *arg0);
extern "C" int func_020aad1c(void *arg0, void *arg1, int arg2, int arg3);
extern "C" void func_020466f4(Struct_ov002_02168d54_9 *arg0, unsigned int arg1);
extern "C" void func_0200fb94(char *arg0, unsigned char arg1);
extern "C" void func_0209c678(Struct_ov002_02169efc_2 *arg0, int arg1);
extern "C" void func_ov017_0218d258(void *arg0);

extern "C" char data_ov002_0216d384[] __attribute__((aligned(4)));
extern "C" char data_0211e33c;
extern "C" char data_02109bf4;

static inline char *inline_ov002_02169efc(char *arg0, int arg1) {
    return *(char **) (arg0 + arg1);
}
#if defined(jpn)
#define RG(u, j) (j)
#define OBJ (arg0 + 0xe20)
#define data_ov002_0216d384 data_ov002_0216db03
extern "C" char data_ov002_0216db03[];
#else
#define RG(u, j) (u)
#define OBJ (arg0 + 0x2c8 + 0xc00)
#endif

// USA: func_ov002_02169efc
extern "C" ARM void func_ov002_02169efc(char *self) {
    void *file;
    unsigned int size;
    int recSize;
    void *name;
    char *g                  = GetGlobalField0x1c020421a0();
    GameResources *res       = GameState::GetInstance()->GetResources();
    void *flags              = GetDataPtr02114e04_020d6c00();
    BackgroundLoader *loader = BackgroundLoader::GetInstance();
    int state                = *(int *) (self + 0x1bc0);
    if (state == 0) {
        *(short *) (self + 0x1c28)         = 0x125c;
        *(short *) (self + 0x1c2a)         = -1;
        *(int *) (self + 0x1bb8)           = 0x26;
        *(int *) (self + 0x1bbc)           = 0x24;
        *(unsigned char *) (self + 0x1c2e) = 1;
        SetElementFieldC2_0205deb4((struct Struct_0205d81c *) OBJ, 0x15, 1);
        SetElementFieldC2_0205deb4((struct Struct_0205d81c *) OBJ, 0x16, 1);
        if (CheckField0NonZero_0202b7d8((int *) func_0202ae18())) {
            *(short *) (self + 0x1c28)         = 0x125f;
            *(int *) (self + 0x1bbc)           = 0x15;
            *(unsigned char *) (self + 0x1c2e) = 0;
        }
        *(int *) (arg0 + RG(0x1bc0, 0x1a88)) = 0;
    } else if (var8 == 1) {
        func_0205def8((struct Struct_ov002_02155960_3 *) OBJ, 0, RG(0x29, 0x2c));
        *(short *) (arg0 + RG(0x1c28, 0x1af0))         = 0x125d;
        *(short *) (arg0 + RG(0x1c2a, 0x1af2))         = -1;
        *(int *) (arg0 + RG(0x1bb8, 0x1a80))           = RG(0x26, 0x29);
        *(int *) (arg0 + RG(0x1bbc, 0x1a84))           = RG(0x24, 0x27);
        *(unsigned char *) (arg0 + RG(0x1c2e, 0x1af6)) = 0;
        *(int *) (arg0 + RG(0x1bc0, 0x1a88))           = 0;
        func_020466e4((unsigned int *) var6, 0x80);
        *(int *) (arg0 + RG(0x1bc4, 0x1a8c)) = var7->QueueLoadFile(data_ov002_0216d384, 0);
    } else if (var8 == 2) {
        if (var7->GetTaskStatus(*(int *) (arg0 + RG(0x1bc4, 0x1a8c))) == 0) {
            return;
        }
        for (unsigned char var9 = 0; var9 < 0x2c; var9++) {
            func_0205a198((Struct_ov002_0215624c_23*)(*(char **) (arg0 + RG(0x1a64, 0x19bc)) + var9 * 0x28));
        }
        func_0205a234((Struct_ov002_0215624c_24*)(*(void **) (arg0 + RG(0x1a6c, 0x19c4))));
        func_0205a444(*(char **) (arg0 + RG(0x1a68, 0x19c0)));
        var4 = *(char **) (arg0 + RG(0x1a68, 0x19c0));
        var4[0x50]                                      = 0;
        char *var10                                      = inline_ov002_02169efc(arg0, RG(0x1a64, 0x19bc));
        var4                                            = inline_ov002_02169efc(arg0, RG(0x1a68, 0x19c0));
        *(char **) (var4 + 0x40)                        = var10;
        *(short *) (var4 + 0x4c)                        = 8;
        *(int *) (*(char **) (arg0 + RG(0x1a68, 0x19c0)) + 0x3c) = *(int *) (arg0 + RG(0x1a6c, 0x19c4));
        ((SafeAllocator *) (arg0 + RG(0x78 + 0x800, 0x3dc + 0x400)))->Reset();
        var7->GetLoadedFileByID(*(int *) (arg0 + RG(0x1bc4, 0x1a8c)), &var0, &var1);
        for (int var11 = 0; var11 < 4; var11++) {
            void *var12 = func_020467f0((Struct_ov002_0215624c_25 *) var0, var11, &var3, &var2);
            func_0205a528(*(void **) (arg0 + RG(0x1a68, 0x19c0)), var12, var2, (SafeAllocator *) (arg0 + RG(0x78 + 0x800, 0x3dc + 0x400)));
        }
        var7->RemoveTask(*(int *) (arg0 + RG(0x1bc4, 0x1a8c)));
        *(int *) (arg0 + RG(0x1bc4, 0x1a8c)) = -1;
        *(int *) (arg0 + RG(0x1bc0, 0x1a88)) = 0x63;
    } else if (var8 == 0x63) {
        if (BackgroundLoader::GetInstance()->GetNumQueuedTasks() > 0) {
            return;
        }
        *(unsigned int *) (arg0 + RG(0x247c, 0x22ac)) |= 8;
        func_020a9ea4((struct Struct_ov002_02169efc *) (arg0 + RG(0x98 + 0x2400, 0x2c8 + 0x2000)));
        *(int *) (arg0 + RG(0x1bc0, 0x1a88)) = 0x64;
    } else if (var8 == 0x64) {
        *(unsigned char *) (var4 + RG(0x19af, 0x17df)) = 0;
        BackgroundLoader::AddLockGlobal();
        BackgroundLoader::FreeAllocationsGlobal();
        if (func_020aad1c(arg0 + RG(0x98 + 0x2400, 0x2c8 + 0x2000), &data_0211e33c, 0, 1) == 1) {
            *(unsigned char *) (arg0 + RG(0x1cc2, 0x1b86)) = 1;
            *(int *) (arg0 + RG(0x1bc0, 0x1a88))           = 0x65;
        }
        BackgroundLoader::RemoveLockGlobal();
    } else if (var8 == 0x65) {
        *(unsigned char *) (var4 + RG(0x19af, 0x17df))    = 0;
        *(short *) (arg0 + RG(0x1c28, 0x1af0))         = 0x125e;
        *(short *) (arg0 + RG(0x1c2a, 0x1af2))         = -1;
        *(int *) (arg0 + RG(0x1bb8, 0x1a80))           = RG(0x26, 0x29);
        *(int *) (arg0 + RG(0x1bbc, 0x1a84))           = RG(0x24, 0x27);
        *(unsigned char *) (arg0 + RG(0x1c2e, 0x1af6)) = 0;
        *(int *) (arg0 + RG(0x1bc0, 0x1a88))           = 0;
        func_020466f4((Struct_ov002_02168d54_9 *) var6, 0x80);
        *(unsigned int *) (arg0 + RG(0x247c, 0x22ac)) &= ~8;
        func_0200fb94((char *) GameState::GetInstance(), 0);
    } else if (var8 == 3) {
        *(unsigned char *) (var4 + RG(0x19af, 0x17df)) = 0;
        func_0209c678((Struct_ov002_02169efc_2 *) &data_02109bf4, 0x3c);
        SetBrightness(var5, -16, 0xb4);
        *(int *) (arg0 + RG(0x1bc0, 0x1a88)) += 1;
    } else if (var8 == 4) {
        *(unsigned char *) (var4 + RG(0x19af, 0x17df)) = 0;
        if (!IsBrightnessTransitionActive(var5)) {
            func_ov017_0218d258(GetGameResources());
        }
    }
}
