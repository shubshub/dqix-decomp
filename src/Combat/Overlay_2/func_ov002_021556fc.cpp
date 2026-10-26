#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include <globaldefs.h>
#if defined(jpn)
#define FIELD_1ba4 0x1a6c
#define FIELD_2458 0x228c
#define FIELD_1bc4 0x1a8c
#define FIELD_38 0x20
#define FIELD_1bd0 0x1a98
#define FIELD_ec8 0xe20
#define FIELD_1bd8 0x1aa0
#define FIELD_2468 0x2298
#define FIELD_1bd4 0x1a9c
#define FIELD_810 0x774
#define FIELD_828 0x78c
#define FIELD_83c 0x7a0
#define FIELD_850 0x7b4
#define FIELD_864 0x7c8
#define FIELD_878 0x7dc
#define FIELD_88c 0x7f0
#define FIELD_8a0 0x804
#else
#define FIELD_1ba4 0x1ba4
#define FIELD_2458 0x2458
#define FIELD_1bc4 0x1bc4
#define FIELD_38 0x38
#define FIELD_1bd0 0x1bd0
#define FIELD_ec8 0xec8
#define FIELD_1bd8 0x1bd8
#define FIELD_2468 0x2468
#define FIELD_1bd4 0x1bd4
#define FIELD_810 0x810
#define FIELD_828 0x828
#define FIELD_83c 0x83c
#define FIELD_850 0x850
#define FIELD_864 0x864
#define FIELD_878 0x878
#define FIELD_88c 0x88c
#define FIELD_8a0 0x8a0
#endif

struct S020466c8;
struct Struct_02074bd0;
struct Cont0205d1e0;
struct Cont0205d274;
struct Obj0205d2bc;
struct Obj0205d048;

extern "C" char *MessageSystem_GetInstance();
extern "C" void func_020466c8(S020466c8 *s, int v);
extern "C" void *GameState_GetParty(GameState *gameState);
extern "C" void func_ov017_021cff8c(int id, int a);
extern "C" void func_ov016_0218b5c0(int a, int b);
extern "C" void *FontBankLoader_GetInstance();
extern "C" void FontBankLoader_CancelLoads(void *p);
extern "C" void func_02074bd0(Struct_02074bd0 *s);
extern "C" void MessageSystem_Reset(char *p);
extern "C" void Window_ClearLayers(Cont0205d1e0 *c);
extern "C" void Window_FlushLayers(Cont0205d274 *c);
extern "C" void Window_TransferLayers(Obj0205d2bc *o);
extern "C" void Window_Destroy(struct Obj0205d048 *obj);
extern "C" void *memset(void *dst, int value, unsigned int length);
void CleanInvalidateCacheRange(const void *p, unsigned int len);
extern "C" void LoadToMainBG1CharacterData(const void *data, unsigned int offset, unsigned int length);
extern "C" void func_ov002_0215b428(unsigned char *self);
extern "C" void func_020a1f4c(int v);
extern "C" void func_ov023_021eb26c(void *arg0);

// USA: func_ov002_021556fc
extern "C" ARM void func_ov002_021556fc(char *self) {
    func_020466c8((S020466c8 *) MessageSystem_GetInstance(), 0);
    unsigned char *p = (unsigned char *) GameState_GetParty(GameState::GetInstance());
    for (int i = 0; i < p[0xf7c]; i++) {
        func_ov017_021cff8c((p + i)[0xf78], 0);
    }
    func_ov016_0218b5c0(1, -1);
    BackgroundLoader *loader = BackgroundLoader::GetInstance();
    for (int j = 0; j < 5; j++) {
        if (((int *) (self + FIELD_1ba4))[j] >= 0) {
            loader->RemoveTask(((int *) (self + FIELD_1ba4))[j]);
        }
        ((int *) (self + FIELD_1ba4))[j] = -1;
    }
    if (*(int *) (self + FIELD_2458) >= 0) {
        loader->RemoveTask(*(int *) (self + FIELD_2458));
        *(int *) (self + FIELD_2458) = -1;
    }
    if (*(int *) (self + FIELD_1bc4) >= 0) {
        loader->RemoveTask(*(int *) (self + FIELD_1bc4));
        *(int *) (self + FIELD_1bc4) = -1;
    }
    FontBankLoader_CancelLoads(FontBankLoader_GetInstance());
    *(volatile unsigned int *) 0x4000000   = (*(volatile unsigned int *) 0x4000000 & ~0x1f00) | 0x100;
    *(volatile unsigned short *) 0x4000050 = 0;
    func_02074bd0((Struct_02074bd0 *) (self + FIELD_38));
    MessageSystem_Reset(MessageSystem_GetInstance());
    *(void **) (self + FIELD_1bd0) = 0;
    Window_ClearLayers((Cont0205d1e0 *) (self + FIELD_ec8));
    Window_FlushLayers((Cont0205d274 *) (self + FIELD_ec8));
    Window_TransferLayers((Obj0205d2bc *) (self + FIELD_ec8));
    Window_Destroy((struct Obj0205d048 *) (self + FIELD_ec8));
    if (*(void **) (self + FIELD_1bd8) != 0) {
        memset(*(void **) (self + FIELD_1bd8), 0, 0x20);
        CleanInvalidateCacheRange(*(void **) (self + FIELD_1bd8), 0x20);
        LoadToMainBG1CharacterData(*(void **) (self + FIELD_1bd8), 0, 0x20);
    }
    *(void **) (self + FIELD_1bd8) = 0;
#if !defined(jpn)
    func_ov002_0215b428((unsigned char *) self);
#endif
    func_020a1f4c(1);
    if (*(void **) (self + FIELD_2468) != 0) {
        func_ov023_021eb26c(*(void **) (self + FIELD_2468));
    }
    SafeAllocator *allocs[8] = {
        (SafeAllocator *) (self + FIELD_810), (SafeAllocator *) (self + FIELD_828), (SafeAllocator *) (self + FIELD_83c),
        (SafeAllocator *) (self + FIELD_850), (SafeAllocator *) (self + FIELD_864), (SafeAllocator *) (self + FIELD_878),
        (SafeAllocator *) (self + FIELD_88c), (SafeAllocator *) (self + FIELD_8a0),
    };
    *(void **) (self + FIELD_1bd4) = 0;
    for (int k = 0; k < 8; k++) {
        SafeAllocator *a = allocs[k];
        if (a->GetSignedAllocator() != 0) {
            a->Destroy();
        }
    }
}
