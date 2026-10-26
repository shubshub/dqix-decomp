#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "Resource/Brightness.h"
#include <globaldefs.h>
#include "Resource/GameResources.h"

struct Struct_0205d81c;
struct Struct_0205def8;
struct PacRecord;
struct Struct020a9ea4;
struct FlagWord020466f4;
struct Actor0209c678;

extern "C" char *MessageSystem_GetInstance();
extern "C" void *GlobalFlags_GetInstance();
extern "C" void Window_SetPanePalette(struct Struct_0205d81c *s, int key, int value);
extern "C" void *LinkSession_GetInstance();
extern "C" int LinkSession_IsActive(int *p);
extern "C" void func_0205def8(struct Struct_0205def8 *s, int clear, int key);
extern "C" void FlagWord_SetBits(unsigned int *p, unsigned int mask);
struct Struct0205a198;
extern "C" void Sprite_Init(Struct0205a198*);
struct ClearTarget0205a234;
extern "C" void func_0205a234(ClearTarget0205a234*);
extern "C" void SpriteContext_Init(char *renderer);
extern "C" void *Pac_GetFile(PacRecord *archive, int index, void **name, int *size);
extern "C" void SpriteContext_LoadFile(void *renderer, void *file, unsigned int size, SafeAllocator *allocator);
extern "C" void func_020a9ea4(struct Struct020a9ea4 *p);
extern "C" int func_020aad1c(void *loader, void *name, int a, int b);
extern "C" void FlagWord_ClearBits(FlagWord020466f4 *field, unsigned int bits);
extern "C" void func_0200fb94(char *gs, unsigned char value);
extern "C" void BgmPlayer_FadeOut(Actor0209c678 *actor, int state);
extern "C" void func_ov017_0218d258(void *obj);

extern "C" char data_ov002_0216d384[] __attribute__((aligned(4)));
extern "C" char g_fileLoadBuffer;
extern "C" char g_bgmPlayer;

static inline char *Ld(char *p, int o) {
    return *(char **) (p + o);
}
#if defined(jpn)
#define RG(u, j) (j)
#define OBJ (self + 0xe20)
#define data_ov002_0216d384 data_ov002_0216db03
extern "C" char data_ov002_0216db03[];
#else
#define RG(u, j) (u)
#define OBJ (self + 0x2c8 + 0xc00)
#endif

// USA: func_ov002_02169efc
extern "C" ARM void func_ov002_02169efc(char *self) {
    void *file;
    unsigned int size;
    int recSize;
    void *name;
    char *g                  = MessageSystem_GetInstance();
    GameResources *res       = GameState::GetInstance()->GetResources();
    void *flags              = GlobalFlags_GetInstance();
    BackgroundLoader *loader = BackgroundLoader::GetInstance();
    int state                = *(int *) (self + RG(0x1bc0, 0x1a88));
    if (state == 0) {
        *(short *) (self + RG(0x1c28, 0x1af0))         = 0x125c;
        *(short *) (self + RG(0x1c2a, 0x1af2))         = -1;
        *(int *) (self + RG(0x1bb8, 0x1a80))           = RG(0x26, 0x29);
        *(int *) (self + RG(0x1bbc, 0x1a84))           = RG(0x24, 0x27);
        *(unsigned char *) (self + RG(0x1c2e, 0x1af6)) = 1;
        Window_SetPanePalette((struct Struct_0205d81c *) OBJ, RG(0x15, 0x16), 1);
        Window_SetPanePalette((struct Struct_0205d81c *) OBJ, RG(0x16, 0x17), 1);
        if (LinkSession_IsActive((int *) LinkSession_GetInstance())) {
            *(short *) (self + RG(0x1c28, 0x1af0))         = 0x125f;
            *(int *) (self + RG(0x1bbc, 0x1a84))           = RG(0x15, 0x16);
            *(unsigned char *) (self + RG(0x1c2e, 0x1af6)) = 0;
        }
        *(int *) (self + RG(0x1bc0, 0x1a88)) = 0;
    } else if (state == 1) {
        func_0205def8((struct Struct_0205def8 *) OBJ, 0, RG(0x29, 0x2c));
        *(short *) (self + RG(0x1c28, 0x1af0))         = 0x125d;
        *(short *) (self + RG(0x1c2a, 0x1af2))         = -1;
        *(int *) (self + RG(0x1bb8, 0x1a80))           = RG(0x26, 0x29);
        *(int *) (self + RG(0x1bbc, 0x1a84))           = RG(0x24, 0x27);
        *(unsigned char *) (self + RG(0x1c2e, 0x1af6)) = 0;
        *(int *) (self + RG(0x1bc0, 0x1a88))           = 0;
        FlagWord_SetBits((unsigned int *) flags, 0x80);
        *(int *) (self + RG(0x1bc4, 0x1a8c)) = loader->QueueLoadFile(data_ov002_0216d384, 0);
    } else if (state == 2) {
        if (loader->GetTaskStatus(*(int *) (self + RG(0x1bc4, 0x1a8c))) == 0) {
            return;
        }
        for (unsigned char i = 0; i < 0x2c; i++) {
            Sprite_Init((Struct0205a198*)(*(char **) (self + RG(0x1a64, 0x19bc)) + i * 0x28));
        }
        func_0205a234((ClearTarget0205a234*)(*(void **) (self + RG(0x1a6c, 0x19c4))));
        SpriteContext_Init(*(char **) (self + RG(0x1a68, 0x19c0)));
        g = *(char **) (self + RG(0x1a68, 0x19c0));
        g[0x50]                                      = 0;
        char *v                                      = Ld(self, RG(0x1a64, 0x19bc));
        g                                            = Ld(self, RG(0x1a68, 0x19c0));
        *(char **) (g + 0x40)                        = v;
        *(short *) (g + 0x4c)                        = 8;
        *(int *) (*(char **) (self + RG(0x1a68, 0x19c0)) + 0x3c) = *(int *) (self + RG(0x1a6c, 0x19c4));
        ((SafeAllocator *) (self + RG(0x78 + 0x800, 0x3dc + 0x400)))->Reset();
        loader->GetLoadedFileByID(*(int *) (self + RG(0x1bc4, 0x1a8c)), &file, &size);
        for (int j = 0; j < 4; j++) {
            void *rec = Pac_GetFile((PacRecord *) file, j, &name, &recSize);
            SpriteContext_LoadFile(*(void **) (self + RG(0x1a68, 0x19c0)), rec, recSize, (SafeAllocator *) (self + RG(0x78 + 0x800, 0x3dc + 0x400)));
        }
        loader->RemoveTask(*(int *) (self + RG(0x1bc4, 0x1a8c)));
        *(int *) (self + RG(0x1bc4, 0x1a8c)) = -1;
        *(int *) (self + RG(0x1bc0, 0x1a88)) = 0x63;
    } else if (state == 0x63) {
        if (BackgroundLoader::GetInstance()->GetNumQueuedTasks() > 0) {
            return;
        }
        *(unsigned int *) (self + RG(0x247c, 0x22ac)) |= 8;
        func_020a9ea4((struct Struct020a9ea4 *) (self + RG(0x98 + 0x2400, 0x2c8 + 0x2000)));
        *(int *) (self + RG(0x1bc0, 0x1a88)) = 0x64;
    } else if (state == 0x64) {
        *(unsigned char *) (g + RG(0x19af, 0x17df)) = 0;
        BackgroundLoader::AddLockGlobal();
        BackgroundLoader::FreeAllocationsGlobal();
        if (func_020aad1c(self + RG(0x98 + 0x2400, 0x2c8 + 0x2000), &g_fileLoadBuffer, 0, 1) == 1) {
            *(unsigned char *) (self + RG(0x1cc2, 0x1b86)) = 1;
            *(int *) (self + RG(0x1bc0, 0x1a88))           = 0x65;
        }
        BackgroundLoader::RemoveLockGlobal();
    } else if (state == 0x65) {
        *(unsigned char *) (g + RG(0x19af, 0x17df))    = 0;
        *(short *) (self + RG(0x1c28, 0x1af0))         = 0x125e;
        *(short *) (self + RG(0x1c2a, 0x1af2))         = -1;
        *(int *) (self + RG(0x1bb8, 0x1a80))           = RG(0x26, 0x29);
        *(int *) (self + RG(0x1bbc, 0x1a84))           = RG(0x24, 0x27);
        *(unsigned char *) (self + RG(0x1c2e, 0x1af6)) = 0;
        *(int *) (self + RG(0x1bc0, 0x1a88))           = 0;
        FlagWord_ClearBits((FlagWord020466f4 *) flags, 0x80);
        *(unsigned int *) (self + RG(0x247c, 0x22ac)) &= ~8;
        func_0200fb94((char *) GameState::GetInstance(), 0);
    } else if (state == 3) {
        *(unsigned char *) (g + RG(0x19af, 0x17df)) = 0;
        BgmPlayer_FadeOut((Actor0209c678 *) &g_bgmPlayer, 0x3c);
        SetBrightness(res, -16, 0xb4);
        *(int *) (self + RG(0x1bc0, 0x1a88)) += 1;
    } else if (state == 4) {
        *(unsigned char *) (g + RG(0x19af, 0x17df)) = 0;
        if (!IsBrightnessTransitionActive(res)) {
            func_ov017_0218d258(GetGameResources());
        }
    }
}
