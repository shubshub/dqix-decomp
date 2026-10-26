#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include <globaldefs.h>

#if defined(jpn)
#define REGION_VALUE(j, u) (j)
#else
#define REGION_VALUE(j, u) (u)
#endif

struct Struct_020a13c4;
struct Struct_020a15bc;
struct Struct020dfc40;
struct Struct_ov002_021688f8 {
    unsigned int a;
    void* ptr;
    unsigned int c;
    char pad[0x38];
    char buf[REGION_VALUE(0x118, 0x200)];
};
struct Struct_ov002_021688f8_2 {
    unsigned char pad[0x49c];
    unsigned char bit0 : 1;
};
struct Container020e0310;
extern "C" int func_ov002_02168c00(unsigned char *p);
extern "C" void func_020a13c4(struct Struct_020a13c4 *s);
extern "C" void func_020a13e4(void *p, void *alloc, int a, unsigned short b, unsigned char c);
extern "C" void *func_020a15bc(struct Struct_020a15bc *arr, int key);
extern "C" void *KeyTable_Construct(void *p);
extern "C" void KeyTable_Reset(struct Struct020dfc40 *s);
extern "C" void func_ov002_02168c38(struct Struct_ov002_021688f8 *f);
extern "C" void func_ov002_02168d10(unsigned char *rec, int v);
extern "C" int KeyTable_Get(struct Container020e0310 *c, int key);
extern "C" void *ExtractFileFromGP2(const char *arg0, const char *innerFilePath, unsigned int *outSize);
extern "C" int func_ov023_021ed724(void *p, short *keys, int n);
extern "C" void func_020e0028(void *c, void *alloc, void *data, unsigned int size, short *keys, unsigned short n);
extern "C" void func_ov002_02168ca8(unsigned char *rec, void *elem);
extern "C" int sprintf(char *dst, const char *fmt, ...);
extern "C" void *__clear(void *dst, int count);
extern "C" char data_ov002_0216d326[];
extern "C" char data_ov002_0216d33d[];

#if defined(jpn)
extern "C" const char data_ov002_0216dab4[];
extern "C" int func_020e1fc4(void* texts, SafeAllocator* allocator, const char* arg2,
    short* ids, unsigned short count, short variant, bool lock);
#endif

// USA: func_ov002_021688f8; JPN: func_ov002_021691dc
extern "C" ARM void func_ov002_021688f8(char *base) {
    char ctr[0x18];
#if !defined(jpn)
    char path[0x40];
    char name[0x20];
    unsigned int size;
#endif
    short *keys;
    unsigned char *tmp;
    int j;
    int n;
    GameState *gs = GameState::GetInstance();
    BackgroundLoader::GetInstance();
    if (!func_ov002_02168c00(*(unsigned char **) (base + 0x2000 + REGION_VALUE(0x290, 0x460)))) return;
    n = *(short *) (*(char **) (base + 0x2000 + REGION_VALUE(0x290, 0x460)) + 0x68);
    if (n > 0) {
        keys = (short *) ((SafeAllocator *) (base + REGION_VALUE(0x3c8, 0x64) + REGION_VALUE(0x400, 0x800)))->Allocate(n * 2);
        for (int i = 0; i < n; i++) {
            keys[i] = *(short *) (*(char **) (base + 0x2000 + REGION_VALUE(0x290, 0x460)) + i * 2 + 0x6a);
        }
        *(void **) (base + 0x2000 + REGION_VALUE(0x290, 0x460)) = NULL;
        ((SafeAllocator *) (base + REGION_VALUE(0x38c, 0x28) + REGION_VALUE(0x400, 0x800)))->Reset();
        *(void **) (base + 0x2000 + REGION_VALUE(0x294, 0x464)) = ((SafeAllocator *) (base + REGION_VALUE(0x38c, 0x28) + REGION_VALUE(0x400, 0x800)))->Allocate(0x14);
        func_020a13c4((struct Struct_020a13c4 *) *(void **) (base + 0x2000 + REGION_VALUE(0x294, 0x464)));
        func_020a13e4(*(void **) (base + 0x2000 + REGION_VALUE(0x294, 0x464)), base + REGION_VALUE(0x38c, 0x28) + REGION_VALUE(0x400, 0x800), 0, 0, 4);
        *(unsigned char *) (base + 0x2000 + REGION_VALUE(0x2a1, 0x471)) =
            (func_ov023_021ed724(*(void **) (base + 0x2000 + REGION_VALUE(0x294, 0x464)), keys, n) & 1) ? 1 : 0;
        char *hero = (char *) gs->GetProtagonist();
        KeyTable_Construct(ctr);
        KeyTable_Reset((struct Struct020dfc40 *) ctr);
#if defined(jpn)
        func_020e1fc4(ctr, (SafeAllocator*)(base + 0x78c), data_ov002_0216dab4, keys,
            (unsigned short)n, (*(struct Struct_ov002_021688f8_2**)(hero + 0x144))->bit0, true);
#else
        BackgroundLoader::AddLockGlobal();
        size = 0;
        __clear(path, 0x40);
        __clear(name, 0x20);
        sprintf(path, data_ov002_0216d326, (*(struct Struct_ov002_021688f8_2 **) (hero + 0x150))->bit0);
        sprintf(name, data_ov002_0216d33d, (*(struct Struct_ov002_021688f8_2 **) (hero + 0x150))->bit0);
        void *data = ExtractFileFromGP2(path, name, &size);
        if (data != NULL) {
            func_020e0028(ctr, base + REGION_VALUE(0x38c, 0x28) + REGION_VALUE(0x400, 0x800), data, size, keys, n);
        }
        BackgroundLoader::RemoveLockGlobal();
#endif
        tmp = (unsigned char *) ((SafeAllocator *) (base + REGION_VALUE(0x3c8, 0x64) + REGION_VALUE(0x400, 0x800)))->Allocate(50 * sizeof(Struct_ov002_021688f8));
        for (j = 0; j < n; j++) {
            func_ov002_02168c38((struct Struct_ov002_021688f8 *) (tmp + j * sizeof(Struct_ov002_021688f8)));
            void *elem =
                func_020a15bc(*(struct Struct_020a15bc **) (base + 0x2000 + REGION_VALUE(0x294, 0x464)), keys[j]);
            if (elem == NULL) continue;
            int text = KeyTable_Get((struct Container020e0310 *) ctr, keys[j]);
            if (text == 0) continue;
            func_ov002_02168ca8(tmp + j * sizeof(Struct_ov002_021688f8), elem);
            func_ov002_02168d10(tmp + j * sizeof(Struct_ov002_021688f8), text);
        }
        *(void **) (base + 0x2000 + REGION_VALUE(0x294, 0x464)) = NULL;
        ((SafeAllocator *) (base + REGION_VALUE(0x38c, 0x28) + REGION_VALUE(0x400, 0x800)))->Reset();
        *(void **) (base + 0x2000 + REGION_VALUE(0x29c, 0x46c)) = ((SafeAllocator *) (base + REGION_VALUE(0x38c, 0x28) + REGION_VALUE(0x400, 0x800)))->Allocate(n * sizeof(Struct_ov002_021688f8));
        for (int i = 0; i < n; i++) {
            func_ov002_02168c38((struct Struct_ov002_021688f8 *) (*(unsigned char **) (base + 0x2000 + REGION_VALUE(0x29c, 0x46c)) + i * sizeof(Struct_ov002_021688f8)));
            func_ov002_02168ca8(*(unsigned char **) (base + 0x2000 + REGION_VALUE(0x29c, 0x46c)) + i * sizeof(Struct_ov002_021688f8), tmp + i * sizeof(Struct_ov002_021688f8));
            func_ov002_02168d10(*(unsigned char **) (base + 0x2000 + REGION_VALUE(0x29c, 0x46c)) + i * sizeof(Struct_ov002_021688f8),
                                                 (int) (tmp + i * sizeof(Struct_ov002_021688f8) + 0xc));
        }
        *(unsigned char *) (base + 0x2000 + REGION_VALUE(0x2a0, 0x470)) = n;
        *(int *) (base + 0x1000 + REGION_VALUE(0xa88, 0xbc0)) += 1;
    } else {
        *(void **) (base + 0x2000 + REGION_VALUE(0x290, 0x460)) = NULL;
        *(int *) (base + 0x1000 + REGION_VALUE(0xa88, 0xbc0))   = 100;
    }
}
