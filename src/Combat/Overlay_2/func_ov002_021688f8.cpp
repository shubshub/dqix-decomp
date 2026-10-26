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
struct Struct_0201099c_14;
struct Struct_ov002_021688f8 {
    unsigned int unknown_0_;
    void* unknown_4_;
    unsigned int unknown_8_;
    char unknown_c_[0x38];
    char unknown_44_[REGION_VALUE(0x118, 0x200)];
};
struct Struct_ov002_021688f8_2 {
    unsigned char unknown_0_[0x49c];
    unsigned char unknown_49c_0_ : 1;
};
struct Container020e0310;
int AreFields60And64BothNegOne_02168c00(unsigned char *p);
void ClearStruct020a13c4(struct S020a13c4 *s);
void SetupGlobalAndRunScript020a13e4(void *p, void *alloc, int a, unsigned short b, unsigned char c);
void *FindElementByField020a15bc(struct Array020a15bc *arr, int key);
void *KeyTable_Construct(void *p);
void KeyTable_Reset(struct Struct020dfc40 *s);
void Reset02168c38(struct Foo02168c38 *f);
void AppendFormattedValue_02168d10(unsigned char *rec, int v);
int KeyTable_Get(struct Container020e0310 *c, int key);
extern "C" void *ExtractFileFromGP2(const char *gp2Path, const char *innerFilePath, unsigned int *outSize);
extern "C" int func_ov023_021ed724(void *p, short *keys, int n);
extern "C" void func_020e0028(void *c, void *alloc, void *data, unsigned int size, short *keys, unsigned short n);
extern "C" void func_ov002_02168ca8(unsigned char *rec, void *elem);
extern "C" int sprintf(char *dst, const char *fmt, ...);
extern "C" void *__clear(void *dst, int count);
extern "C" char data_ov002_0216d326[];
extern "C" char data_ov002_0216d33d[];

#if defined(jpn)
extern "C" const char data_ov002_0216dab4[];
extern "C" int func_020e1fc4(void* arg0, SafeAllocator* arg1, const char* arg2,
    short* arg3, unsigned short arg4, short arg5, bool arg6);
#endif

// USA: func_ov002_021688f8; JPN: func_ov002_021691dc
extern "C" ARM void func_ov002_021688f8(char *arg0) {
    char var0[0x18];
#if !defined(jpn)
    char var1[0x40];
    char var2[0x20];
    unsigned int var3;
#endif
    short *var4;
    unsigned char *var5;
    int var6;
    int var7;
    GameState *var8 = GameState::GetInstance();
    BackgroundLoader::GetInstance();
    if (!func_ov002_02168c00(*(unsigned char **) (arg0 + 0x2000 + REGION_VALUE(0x290, 0x460)))) return;
    var7 = *(short *) (*(char **) (arg0 + 0x2000 + REGION_VALUE(0x290, 0x460)) + 0x68);
    if (var7 > 0) {
        var4 = (short *) ((SafeAllocator *) (arg0 + REGION_VALUE(0x3c8, 0x64) + REGION_VALUE(0x400, 0x800)))->Allocate(var7 * 2);
        for (int var9 = 0; var9 < var7; var9++) {
            var4[var9] = *(short *) (*(char **) (arg0 + 0x2000 + REGION_VALUE(0x290, 0x460)) + var9 * 2 + 0x6a);
        }
        *(void **) (base + 0x2000 + REGION_VALUE(0x290, 0x460)) = NULL;
        ((SafeAllocator *) (base + REGION_VALUE(0x38c, 0x28) + REGION_VALUE(0x400, 0x800)))->Reset();
        *(void **) (base + 0x2000 + REGION_VALUE(0x294, 0x464)) = ((SafeAllocator *) (base + REGION_VALUE(0x38c, 0x28) + REGION_VALUE(0x400, 0x800)))->Allocate(0x14);
        ClearStruct020a13c4((struct S020a13c4 *) *(void **) (base + 0x2000 + REGION_VALUE(0x294, 0x464)));
        SetupGlobalAndRunScript020a13e4(*(void **) (base + 0x2000 + REGION_VALUE(0x294, 0x464)), base + REGION_VALUE(0x38c, 0x28) + REGION_VALUE(0x400, 0x800), 0, 0, 4);
        *(unsigned char *) (base + 0x2000 + REGION_VALUE(0x2a1, 0x471)) =
            (func_ov023_021ed724(*(void **) (base + 0x2000 + REGION_VALUE(0x294, 0x464)), keys, n) & 1) ? 1 : 0;
        char *hero = (char *) gs->GetProtagonist();
        KeyTable_Construct(ctr);
        KeyTable_Reset((struct Struct020dfc40 *) ctr);
#if defined(jpn)
        func_020e1fc4(var0, (SafeAllocator*)(arg0 + 0x78c), data_ov002_0216dab4, var4,
            (unsigned short)var7, (*(struct Struct_ov002_021688f8_2**)(var10 + 0x144))->unknown_49c_0_, true);
#else
        BackgroundLoader::AddLockGlobal();
        var3 = 0;
        __clear(var1, 0x40);
        __clear(var2, 0x20);
        sprintf(var1, data_ov002_0216d326, (*(struct Struct_ov002_021688f8_2 **) (var10 + 0x150))->unknown_49c_0_);
        sprintf(var2, data_ov002_0216d33d, (*(struct Struct_ov002_021688f8_2 **) (var10 + 0x150))->unknown_49c_0_);
        void *var11 = ExtractFileFromGP2(var1, var2, &var3);
        if (var11 != NULL) {
            func_020e0028(var0, arg0 + REGION_VALUE(0x38c, 0x28) + REGION_VALUE(0x400, 0x800), var11, var3, var4, var7);
        }
        BackgroundLoader::RemoveLockGlobal();
#endif
        tmp = (unsigned char *) ((SafeAllocator *) (base + REGION_VALUE(0x3c8, 0x64) + REGION_VALUE(0x400, 0x800)))->Allocate(50 * sizeof(Foo02168c38));
        for (j = 0; j < n; j++) {
            Reset02168c38((struct Foo02168c38 *) (tmp + j * sizeof(Foo02168c38)));
            void *elem =
                FindElementByField020a15bc(*(struct Array020a15bc **) (base + 0x2000 + REGION_VALUE(0x294, 0x464)), keys[j]);
            if (elem == NULL) continue;
            int text = KeyTable_Get((struct Container020e0310 *) ctr, keys[j]);
            if (text == 0) continue;
            func_ov002_02168ca8(tmp + j * sizeof(Foo02168c38), elem);
            AppendFormattedValue_02168d10(tmp + j * sizeof(Foo02168c38), text);
        }
        *(void **) (arg0 + 0x2000 + REGION_VALUE(0x294, 0x464)) = NULL;
        ((SafeAllocator *) (arg0 + REGION_VALUE(0x38c, 0x28) + REGION_VALUE(0x400, 0x800)))->Reset();
        *(void **) (arg0 + 0x2000 + REGION_VALUE(0x29c, 0x46c)) = ((SafeAllocator *) (arg0 + REGION_VALUE(0x38c, 0x28) + REGION_VALUE(0x400, 0x800)))->Allocate(var7 * sizeof(Struct_ov002_021688f8));
        for (int var14 = 0; var14 < var7; var14++) {
            func_ov002_02168c38((struct Struct_ov002_021688f8 *) (*(unsigned char **) (arg0 + 0x2000 + REGION_VALUE(0x29c, 0x46c)) + var14 * sizeof(Struct_ov002_021688f8)));
            func_ov002_02168ca8(*(unsigned char **) (arg0 + 0x2000 + REGION_VALUE(0x29c, 0x46c)) + var14 * sizeof(Struct_ov002_021688f8), var5 + var14 * sizeof(Struct_ov002_021688f8));
            func_ov002_02168d10(*(unsigned char **) (arg0 + 0x2000 + REGION_VALUE(0x29c, 0x46c)) + var14 * sizeof(Struct_ov002_021688f8),
                                                 (int) (var5 + var14 * sizeof(Struct_ov002_021688f8) + 0xc));
        }
        *(unsigned char *) (arg0 + 0x2000 + REGION_VALUE(0x2a0, 0x470)) = var7;
        *(int *) (arg0 + 0x1000 + REGION_VALUE(0xa88, 0xbc0)) += 1;
    } else {
        *(void **) (arg0 + 0x2000 + REGION_VALUE(0x290, 0x460)) = NULL;
        *(int *) (arg0 + 0x1000 + REGION_VALUE(0xa88, 0xbc0))   = 100;
    }
}
