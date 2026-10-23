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

struct Struct_020466c8;
struct Struct_02074bd0;
struct Struct_0205d1e0;
struct Struct_0205d274;
struct Struct_0205d2bc;
struct Struct_0205d048;

char *GetGlobalField0x1c020421a0();
void SetField0x38(S020466c8 *s, int v);
void *GetPtrField0x2a04_02010828(GameState *gameState);
extern "C" void func_ov017_021cff8c(int id, int a);
extern "C" void func_ov016_0218b5c0(int a, int b);
void *GetGlobal02109400_02094a00();
extern "C" void func_02094ab0(void *p);
void ClearFlag0x10IfSet(Struct02074bd0 *s);
void ReinitController02043204(char *p);
void Window_ClearLayers(Cont0205d1e0 *c);
void Window_FlushLayers(Cont0205d274 *c);
void Window_TransferLayers(Obj0205d2bc *o);
extern "C" void func_0205d048(struct Obj0205d048 *obj);
extern "C" void *memset(void *dst, int value, unsigned int length);
void CleanInvalidateCacheRange(const void *p, unsigned int len);
extern "C" void LoadToMainBG1CharacterData(const void *data, unsigned int offset, unsigned int length);
extern "C" void func_ov002_0215b428(unsigned char *arg0);
extern "C" void func_020a1f4c(int arg0);
extern "C" void func_ov023_021eb26c(void *arg0);

// USA: func_ov002_021556fc
extern "C" ARM void func_ov002_021556fc(char *arg0) {
    func_020466c8((Struct_020466c8 *) func_020421a0(), 0);
    unsigned char *var0 = (unsigned char *) func_02010828(GameState::GetInstance());
    for (int var1 = 0; var1 < var0[0xf7c]; var1++) {
        func_ov017_021cff8c((var0 + var1)[0xf78], 0);
    }
    func_ov016_0218b5c0(1, -1);
    BackgroundLoader *var2 = BackgroundLoader::GetInstance();
    for (int var3 = 0; var3 < 5; var3++) {
        if (((int *) (arg0 + FIELD_1ba4))[var3] >= 0) {
            var2->RemoveTask(((int *) (arg0 + FIELD_1ba4))[var3]);
        }
        ((int *) (arg0 + FIELD_1ba4))[var3] = -1;
    }
    if (*(int *) (arg0 + FIELD_2458) >= 0) {
        var2->RemoveTask(*(int *) (arg0 + FIELD_2458));
        *(int *) (arg0 + FIELD_2458) = -1;
    }
    if (*(int *) (arg0 + FIELD_1bc4) >= 0) {
        var2->RemoveTask(*(int *) (arg0 + FIELD_1bc4));
        *(int *) (arg0 + FIELD_1bc4) = -1;
    }
    func_02094ab0(func_02094a00());
    *(volatile unsigned int *) 0x4000000   = (*(volatile unsigned int *) 0x4000000 & ~0x1f00) | 0x100;
    *(volatile unsigned short *) 0x4000050 = 0;
    ClearFlag0x10IfSet((Struct02074bd0 *) (self + FIELD_38));
    ReinitController02043204(GetGlobalField0x1c020421a0());
    *(void **) (self + FIELD_1bd0) = 0;
    Window_ClearLayers((Cont0205d1e0 *) (self + FIELD_ec8));
    Window_FlushLayers((Cont0205d274 *) (self + FIELD_ec8));
    Window_TransferLayers((Obj0205d2bc *) (self + FIELD_ec8));
    func_0205d048((struct Obj0205d048 *) (self + FIELD_ec8));
    if (*(void **) (self + FIELD_1bd8) != 0) {
        memset(*(void **) (self + FIELD_1bd8), 0, 0x20);
        CleanInvalidateCacheRange(*(void **) (self + FIELD_1bd8), 0x20);
        LoadToMainBG1CharacterData(*(void **) (self + FIELD_1bd8), 0, 0x20);
    }
    *(void **) (arg0 + FIELD_1bd8) = 0;
#if !defined(jpn)
    func_ov002_0215b428((unsigned char *) arg0);
#endif
    func_020a1f4c(1);
    if (*(void **) (arg0 + FIELD_2468) != 0) {
        func_ov023_021eb26c(*(void **) (arg0 + FIELD_2468));
    }
    SafeAllocator *var4[8] = {
        (SafeAllocator *) (arg0 + FIELD_810), (SafeAllocator *) (arg0 + FIELD_828), (SafeAllocator *) (arg0 + FIELD_83c),
        (SafeAllocator *) (arg0 + FIELD_850), (SafeAllocator *) (arg0 + FIELD_864), (SafeAllocator *) (arg0 + FIELD_878),
        (SafeAllocator *) (arg0 + FIELD_88c), (SafeAllocator *) (arg0 + FIELD_8a0),
    };
    *(void **) (arg0 + FIELD_1bd4) = 0;
    for (int var5 = 0; var5 < 8; var5++) {
        SafeAllocator *var6 = var4[var5];
        if (var6->GetSignedAllocator() != 0) {
            var6->Destroy();
        }
    }
}
