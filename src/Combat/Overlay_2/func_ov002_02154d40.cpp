#include "Memory/SafeAllocator.h"
#include <globaldefs.h>

#if defined(jpn)
#define RG(u, j) (j)
#else
#define RG(u, j) (u)
#endif

struct Struct_020e2490;
struct Struct_020e1368;
struct Struct_020e1374;

extern "C" void func_020e2490(Struct_020e2490 *mgr, int a,
                                                                                          int b, void *p, SafeAllocator *alloc,
                                                                                          int c, unsigned char d);
extern "C" void func_020e1368(Struct_020e1368 *p, unsigned int a, unsigned int b,
                                                                    unsigned char c);
extern "C" void func_020e1374(Struct_020e1374 *p, unsigned int a, unsigned int b, int c);

// USA: func_ov002_02154d40
extern "C" ARM void func_ov002_02154d40(char *self, SafeAllocator *alloc) {
    if (alloc == NULL) return;
    ((SafeAllocator *) (self + RG(0x810, 0x774)))->CreateTypeA(alloc->Allocate(0x3c00), 0x3c00);
    ((SafeAllocator *) (self + RG(0x83c, 0x7a0)))->CreateTypeA(alloc->Allocate(RG(0x5400, 0x4000)), RG(0x5400, 0x4000));
    ((SafeAllocator *) (self + RG(0x828, 0x78c)))->CreateTypeA(alloc->Allocate(0xd400), 0xd400);
    ((SafeAllocator *) (self + RG(0x850, 0x7b4)))->CreateTypeA(alloc->Allocate(0x4c00), 0x4c00);
    ((SafeAllocator *) (self + RG(0x864, 0x7c8)))->CreateTypeA(alloc->Allocate(0x9400), 0x9400);
    ((SafeAllocator *) (self + RG(0x878, 0x7dc)))->CreateTypeA(alloc->Allocate(0x800), 0x800);
    ((SafeAllocator *) (self + RG(0x88c, 0x7f0)))->CreateTypeA(alloc->Allocate(0x580), 0x580);
    ((SafeAllocator *) (self + RG(0x8a0, 0x804)))->CreateTypeA(alloc->Allocate(0x533), 0x533);
    *(void **) (self + RG(0x1a64, 0x19bc)) = alloc->Allocate(RG(0x6b8, 0x6e0));
    *(void **) (self + RG(0x1a68, 0x19c0)) = alloc->Allocate(0x54);
    *(void **) (self + RG(0x1a6c, 0x19c4)) = alloc->Allocate(8);
    *(void **) (self + RG(0x1bd4, 0x1a9c)) = alloc->Allocate(RG(0x960, 0x800));
    *(void **) (self + 0)      = alloc->Allocate(0x24);
    *(void **) (self + 4)      = alloc->Allocate(0x24);
    func_020e2490(*(Struct_020e2490 **) (self + 0), 0, 0, 0,
                                                                              alloc, 0xc, 0x40);
    func_020e2490(*(Struct_020e2490 **) (self + 4), 0, 1,
                                                                              *(void **) (self + RG(0x1a6c, 0x19c4)), alloc, RG(4, 3), 0x60);
    char *e = *(char **) (*(char **) (self + 0) + 0xc);
    func_020e1368((Struct_020e1368 *) (e + 0xc), 0, 0x3000, 5);
    func_020e1374((Struct_020e1374 *) (e + 0xc), 0x3800, 0x3000, 4);
}
