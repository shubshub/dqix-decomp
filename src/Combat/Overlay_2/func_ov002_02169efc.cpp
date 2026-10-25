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

char *MessageSystem_GetInstance();
void *GlobalFlags_GetInstance();
void Window_SetPanePalette(struct Struct_0205d81c *s, int key, int value);
extern "C" void *func_0202ae18();
int CheckField0NonZero_0202b7d8(int *p);
void SetElementFlag0x20ByKey0205def8(struct Struct_0205def8 *s, int clear, int key);
void FlagWord_SetBits(unsigned int *p, unsigned int mask);
struct Struct0205a198;
void Sprite_Init(Struct0205a198*);
struct ClearTarget0205a234;
void ClearField0And40205a234(ClearTarget0205a234*);
void SpriteContext_Init(char *renderer);
void *Pac_GetFile(PacRecord *archive, int index, void **name, int *size);
extern "C" void SpriteContext_LoadFile(void *renderer, void *file, unsigned int size, SafeAllocator *allocator);
void ClearStruct020a9ea4(struct Struct020a9ea4 *p);
extern "C" int func_020aad1c(void *loader, void *name, int a, int b);
void FlagWord_ClearBits(FlagWord020466f4 *field, unsigned int bits);
void SetByte0x4_0200fb94(char *gs, unsigned char value);
void BgmPlayer_FadeOut(Actor0209c678 *actor, int state);
void SetFieldFlag17188_0218d258(void *obj);

extern "C" char data_ov002_0216d384[] __attribute__((aligned(4)));
extern "C" char g_fileLoadBuffer;
extern "C" char g_bgmPlayer;

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
    char *g                  = MessageSystem_GetInstance();
    GameResources *res       = GameState::GetInstance()->GetResources();
    void *flags              = GlobalFlags_GetInstance();
    BackgroundLoader *loader = BackgroundLoader::GetInstance();
    int state                = *(int *) (self + 0x1bc0);
    if (state == 0) {
        *(short *) (self + 0x1c28)         = 0x125c;
        *(short *) (self + 0x1c2a)         = -1;
        *(int *) (self + 0x1bb8)           = 0x26;
        *(int *) (self + 0x1bbc)           = 0x24;
        *(unsigned char *) (self + 0x1c2e) = 1;
        Window_SetPanePalette((struct Struct_0205d81c *) OBJ, 0x15, 1);
        Window_SetPanePalette((struct Struct_0205d81c *) OBJ, 0x16, 1);
        if (CheckField0NonZero_0202b7d8((int *) func_0202ae18())) {
            *(short *) (self + 0x1c28)         = 0x125f;
            *(int *) (self + 0x1bbc)           = 0x15;
            *(unsigned char *) (self + 0x1c2e) = 0;
        }
        *(int *) (self + 0x1bc0) = 0;
    } else if (state == 1) {
        SetElementFlag0x20ByKey0205def8((struct Struct_0205def8 *) OBJ, 0, 0x29);
        *(short *) (self + 0x1c28)         = 0x125d;
        *(short *) (self + 0x1c2a)         = -1;
        *(int *) (self + 0x1bb8)           = 0x26;
        *(int *) (self + 0x1bbc)           = 0x24;
        *(unsigned char *) (self + 0x1c2e) = 0;
        *(int *) (self + 0x1bc0)           = 0;
        FlagWord_SetBits((unsigned int *) flags, 0x80);
        *(int *) (self + 0x1bc4) = loader->QueueLoadFile(data_ov002_0216d384, 0);
    } else if (state == 2) {
        if (loader->GetTaskStatus(*(int *) (self + 0x1bc4)) == 0) {
            return;
        }
        for (unsigned char i = 0; i < 0x2c; i++) {
            Sprite_Init((Struct0205a198*)(*(char **) (self + 0x1a64) + i * 0x28));
        }
        ClearField0And40205a234((ClearTarget0205a234*)(*(void **) (self + 0x1a6c)));
        SpriteContext_Init(*(char **) (self + 0x1a68));
        char *r                                      = *(char **) (self + 0x1a68);
        r[0x50]                                      = 0;
        char *v                                      = Ld(self, 0x1a64);
        r                                            = Ld(self, 0x1a68);
        *(char **) (r + 0x40)                        = v;
        *(short *) (r + 0x4c)                        = 8;
        *(int *) (*(char **) (self + 0x1a68) + 0x3c) = *(int *) (self + 0x1a6c);
        ((SafeAllocator *) (self + 0x78 + 0x800))->Reset();
        loader->GetLoadedFileByID(*(int *) (self + 0x1bc4), &file, &size);
        for (int j = 0; j < 4; j++) {
            void *rec = Pac_GetFile((PacRecord *) file, j, &name, &recSize);
            SpriteContext_LoadFile(*(void **) (self + 0x1a68), rec, recSize, (SafeAllocator *) (self + 0x78 + 0x800));
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
        if (func_020aad1c(self + 0x98 + 0x2400, &g_fileLoadBuffer, 0, 1) == 1) {
            *(unsigned char *) (self + 0x1cc2) = 1;
            *(int *) (self + 0x1bc0)           = 0x65;
        }
        BackgroundLoader::RemoveLockGlobal();
    } else if (state == 0x65) {
        *(unsigned char *) (g + 0x19af)    = 0;
        *(short *) (self + 0x1c28)         = 0x125e;
        *(short *) (self + 0x1c2a)         = -1;
        *(int *) (self + 0x1bb8)           = 0x26;
        *(int *) (self + 0x1bbc)           = 0x24;
        *(unsigned char *) (self + 0x1c2e) = 0;
        *(int *) (self + 0x1bc0)           = 0;
        FlagWord_ClearBits((FlagWord020466f4 *) flags, 0x80);
        *(unsigned int *) (self + 0x247c) &= ~8;
        SetByte0x4_0200fb94((char *) GameState::GetInstance(), 0);
    } else if (state == 3) {
        *(unsigned char *) (g + 0x19af) = 0;
        BgmPlayer_FadeOut((Actor0209c678 *) &g_bgmPlayer, 0x3c);
        SetBrightness(res, -16, 0xb4);
        *(int *) (self + 0x1bc0) += 1;
    } else if (state == 4) {
        *(unsigned char *) (g + 0x19af) = 0;
        if (!IsBrightnessTransitionActive(res)) {
            SetFieldFlag17188_0218d258(GetGameResources());
        }
    }
}
