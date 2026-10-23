#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include <globaldefs.h>

#if defined(jpn)
#define RG(u, j) (j)
#else
#define RG(u, j) (u)
#endif

struct Pair0209a338;
struct Ctx0209a470;
struct Ctx0209a8b4;
struct StreamHeader;
void ItemTable_Init(void *p);
void ClearField00209a804(int *p);
void ClearFirstTwoWords0209a338(struct Pair0209a338 *p);
void SetupAndRunBufferedScript0209a470(struct Ctx0209a470 *ctx,
                                                                                                    SafeAllocator *alloc,
                                                                                                    struct StreamHeader *hdr,
                                                                                                    int len);
void SetupAndRunBufferedScript0209a8b4(struct Ctx0209a8b4 *ctx,
                                                                                                    SafeAllocator *alloc,
                                                                                                    struct StreamHeader *hdr,
                                                                                                    int len);
extern "C" void func_020dea64(void *list, void *alloc, void *data, unsigned int size, const void *entries, int count);
extern "C" char data_ov002_0216c96e[];

// USA: func_ov002_02156c7c
extern "C" ARM void func_ov002_02156c7c(char *arg0) {
    void *var0;
    unsigned int var1;
    void *var2;
    unsigned int var3;
    void *var4;
    unsigned int var5;

    if (!(*(unsigned int *) (arg0 + 0x2000 + RG(0x47c, 0x2ac)) & 0x10)) return;

    BackgroundLoader *var6 = BackgroundLoader::GetInstance();
    unsigned char var7          = 0;
    for (unsigned char var8 = 0; var8 < 3; var8++) {
        if (var6->GetTaskStatus(*(int *) (arg0 + var8 * 4 + 0x1000 + RG(0xba4, 0xa6c)))) {
            var7++;
        }
    }
    if (var7 != 3) return;

    int *h = (int *) (base + RG(0x3a4, 0x26c) + 0x1800);
    if (loader->GetTaskStatus(*(int *) (base + 0x1000 + RG(0xba4, 0xa6c)))) {
        loader->GetLoadedFileByID(*h, &file0, &len0);
        ((SafeAllocator *) (base + RG(0, 0x374) + RG(0x810, 0x400)))->Reset();
        ItemTable_Init(base + RG(0x3ec, 0) + RG(0x400, 0x750));
        func_020dea64(base + RG(0x3ec, 0) + RG(0x400, 0x750), base + RG(0, 0x374) + RG(0x810, 0x400), file0, len0, data_ov002_0216c96e, 2);
        loader->RemoveTask(*h);
        *h = -1;
    }
    var9 = (int *) (arg0 + RG(0x3a8, 0xa70) + RG(0x1800, 0x1000));
    if (var6->GetTaskStatus(*(int *) (arg0 + 0x1000 + RG(0xba8, 0xa70)))) {
        var6->GetLoadedFileByID(*var9, &var2, &var3);
        func_0209a804((int *) (arg0 + RG(0x44, 0x27c) + RG(0x2400, 0x2000)));
        if (var2 != NULL && var3 != 0) {
            func_0209a8b4(
                (struct Struct_02086f24_6 *) (arg0 + RG(0x44, 0x27c) + RG(0x2400, 0x2000)), (SafeAllocator *) (arg0 + RG(0x8c, 0x7f0) + RG(0x800, 0)),
                (struct Struct_02013fb4 *) var2, var3);
        }
        var6->RemoveTask(*var9);
        *var9 = -1;
    }
    var9 = (int *) (arg0 + RG(0x3ac, 0x274) + 0x1800);
    if (var6->GetTaskStatus(*(int *) (arg0 + 0x1000 + RG(0xbac, 0xa74)))) {
#if !defined(jpn)
        if (*(unsigned char *) (arg0 + 0x2000 + 0x485) == 0) {
#endif
            var6->GetLoadedFileByID(*var9, &var4, &var5);
            ((SafeAllocator *) (arg0 + RG(0, 0x3b4) + RG(0x850, 0x400)))->Reset();
            func_0209a338((struct Struct_0200f3a4_8 *) (arg0 + RG(0x3c, 0x274) + RG(0x2400, 0x2000)));
            if (var4 != NULL && var5 != 0) {
                func_0209a470(
                    (struct Struct_0209a470 *) (arg0 + RG(0x3c, 0x274) + RG(0x2400, 0x2000)), (SafeAllocator *) (arg0 + RG(0, 0x3b4) + RG(0x850, 0x400)),
                    (struct Struct_02013fb4 *) var4, var5);
            }
#if !defined(jpn)
        }
#endif
        var6->RemoveTask(*var9);
        *var9 = -1;
    }
    *(unsigned int *) (arg0 + 0x2000 + RG(0x47c, 0x2ac)) |= 0x20;
}
