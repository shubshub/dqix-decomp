#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include <globaldefs.h>

#if defined(jpn)
#define RG(u, j) (j)
#else
#define RG(u, j) (u)
#endif

struct Pair0209a338;
struct Struct_0209a470;
struct Ctx0209a8b4;
struct StreamHeader;
extern "C" void ItemTable_Init(void *p);
extern "C" void func_0209a804(int *p);
extern "C" void func_0209a338(struct Pair0209a338 *p);
extern "C" void func_0209a470(struct Struct_0209a470 *ctx,
                                                                                                    SafeAllocator *alloc,
                                                                                                    struct StreamHeader *hdr,
                                                                                                    int len);
extern "C" void func_0209a8b4(struct Ctx0209a8b4 *ctx,
                                                                                                    SafeAllocator *alloc,
                                                                                                    struct StreamHeader *hdr,
                                                                                                    int len);
extern "C" void func_020dea64(void *list, void *alloc, void *data, unsigned int size, const void *entries, int count);
extern "C" char data_ov002_0216c96e[];

// USA: func_ov002_02156c7c
extern "C" ARM void func_ov002_02156c7c(char *base) {
    void *var0;
    unsigned int var1;
    void *file1;
    unsigned int len1;
    void *file2;
    unsigned int len2;

    if (!(*(unsigned int *) (base + 0x2000 + RG(0x47c, 0x2ac)) & 0x10)) return;

    BackgroundLoader *loader = BackgroundLoader::GetInstance();
    unsigned char n          = 0;
    for (unsigned char i = 0; i < 3; i++) {
        if (loader->GetTaskStatus(*(int *) (base + i * 4 + 0x1000 + RG(0xba4, 0xa6c)))) {
            n++;
        }
    }
    if (n != 3) return;

    int *h = (int *) (base + RG(0x3a4, 0x26c) + 0x1800);
    if (loader->GetTaskStatus(*(int *) (base + 0x1000 + RG(0xba4, 0xa6c)))) {
        loader->GetLoadedFileByID(*h, &var0, &var1);
        ((SafeAllocator *) (base + RG(0, 0x374) + RG(0x810, 0x400)))->Reset();
        ItemTable_Init(base + RG(0x3ec, 0) + RG(0x400, 0x750));
        func_020dea64(base + RG(0x3ec, 0) + RG(0x400, 0x750), base + RG(0, 0x374) + RG(0x810, 0x400), var0, var1, data_ov002_0216c96e, 2);
        loader->RemoveTask(*h);
        *h = -1;
    }
    h = (int *) (base + RG(0x3a8, 0xa70) + RG(0x1800, 0x1000));
    if (loader->GetTaskStatus(*(int *) (base + 0x1000 + RG(0xba8, 0xa70)))) {
        loader->GetLoadedFileByID(*h, &file1, &len1);
        func_0209a804((int *) (base + RG(0x44, 0x27c) + RG(0x2400, 0x2000)));
        if (file1 != NULL && len1 != 0) {
            func_0209a8b4(
                (struct Ctx0209a8b4 *) (base + RG(0x44, 0x27c) + RG(0x2400, 0x2000)), (SafeAllocator *) (base + RG(0x8c, 0x7f0) + RG(0x800, 0)),
                (struct StreamHeader *) file1, len1);
        }
        loader->RemoveTask(*h);
        *h = -1;
    }
    h = (int *) (base + RG(0x3ac, 0x274) + 0x1800);
    if (loader->GetTaskStatus(*(int *) (base + 0x1000 + RG(0xbac, 0xa74)))) {
#if !defined(jpn)
        if (*(unsigned char *) (base + 0x2000 + 0x485) == 0) {
#endif
            loader->GetLoadedFileByID(*h, &file2, &len2);
            ((SafeAllocator *) (base + RG(0, 0x3b4) + RG(0x850, 0x400)))->Reset();
            func_0209a338((struct Pair0209a338 *) (base + RG(0x3c, 0x274) + RG(0x2400, 0x2000)));
            if (file2 != NULL && len2 != 0) {
                func_0209a470(
                    (struct Struct_0209a470 *) (base + RG(0x3c, 0x274) + RG(0x2400, 0x2000)), (SafeAllocator *) (base + RG(0, 0x3b4) + RG(0x850, 0x400)),
                    (struct StreamHeader *) file2, len2);
            }
#if !defined(jpn)
        }
#endif
        loader->RemoveTask(*h);
        *h = -1;
    }
    *(unsigned int *) (base + 0x2000 + RG(0x47c, 0x2ac)) |= 0x20;
}
