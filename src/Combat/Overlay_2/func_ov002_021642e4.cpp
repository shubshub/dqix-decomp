#include "Memory/SafeAllocator.h"
#include <globaldefs.h>

struct Struct_0205de24_2;
struct Struct_0205c570;

void FindAndLinkMatchingEntry0205de24(struct Struct0205de24 *obj, unsigned char keyLow,
                                                                        unsigned char keyHigh);
int Window_GetSelectedIndex(struct Struct_0205c570 *s);
int CheckFlagOrThreshold_02161b48(char *self, int flag);
void *GetDataPtr02114e04_020d6c00(void);
void OrBitsIntoField0_020466e4(unsigned int *p, unsigned int mask);
extern "C" int GetInventoryItemByID(char *self, int idx, int member);
extern "C" void func_ov002_02161cf0(char *self);
extern "C" void func_ov002_0215d864(char *self);
extern "C" void func_ov002_02161b98(char *self);
extern "C" void func_ov002_02156e90(char *self);
extern "C" void func_ov023_021dc9e8(char *obj, SafeAllocator *alloc, int item, char *list, int n);
extern "C" void func_ov023_021dc134(char *obj, int item, int flag);
extern "C" void func_ov023_021dbfd0(char *obj, SafeAllocator *alloc);
extern "C" void func_ov023_021dcae0(char *obj, int item);
extern "C" void func_ov023_021dca88(char *obj);

// USA: func_ov002_021642e4
#if defined(jpn)
extern "C" ARM void func_ov002_021642e4(char *arg0) {
    int var0 = *(int *) (arg0 + 0x1a88);
    char *var1 = arg0 + 0x38;
    if (var0 == 0) {
        *(short *) (arg0 + 0x1ab0) = 0;
        func_0205de24((struct Struct_0205de24_2 *) (arg0 + 0xe20), 0, 2);
        func_ov002_02161cf0(arg0);
        func_ov002_0215d864(arg0);
        func_020466e4((unsigned int *) func_020d6c00(), 1);
        if (*(int *) (arg0 + 0x22ac) & 1) {
            ((SafeAllocator *) (arg0 + 0x7c8))->Reset();
            func_ov023_021dc9e8(var1, (SafeAllocator *) (arg0 + 0x7c8),
                                GetInventoryItemByID(arg0, *(short *) (arg0 + 0x1ab0), *(signed char *) (arg0 + 0x1ae8)),
                                arg0 + 0x750, 0x50);
        } else {
            ((SafeAllocator *) (arg0 + 0x7c8))->Reset();
            func_ov023_021dc134(var1,
                                GetInventoryItemByID(arg0, *(short *) (arg0 + 0x1ab0), *(signed char *) (arg0 + 0x1ae8)), 0);
            struct Struct_ov002_02162e50 {
                char unknown_0_[0x6f0];
                unsigned short unknown_6f0_;
            };
            ((Struct_ov002_02162e50 *) (var1))->unknown_6f0_ |= 0x50;
            func_ov023_021dbfd0(var1, (SafeAllocator *) (arg0 + 0x7c8));
            *(char **) (var1 + 0x48) = arg0 + 0x750;
            *(int *) (arg0 + 0x22ac) |= 1;
        }
        (*(int *) (self + 0x1a88))++;
    } else if (phase == 1) {
        *(int *) (self + 0x22ac) |= 4;
        func_ov002_02161b98(self);
        *(short *) (self + 0x1ab0) =
            Window_GetSelectedIndex((struct Struct_0205c570 *) (self + 0xe20));
        *(short *) (self + 0x1aea) = GetInventoryItemByID(self, *(short *) (self + 0x1ab0), *(signed char *) (self + 0x1ae8));
        func_ov023_021dcae0(sub, *(short *) (self + 0x1aea));
        if (CheckFlagOrThreshold_02161b48(self, 1)) {
            *(short *) (self + 0x1aea) = -1;
            *(short *) (self + 0x1ab0) = -1;
            func_ov002_02156e90(self);
            func_ov023_021dca88(sub);
        }
    }
}
#else
extern "C" ARM void func_ov002_021642e4(char *arg0) {
    int var2 = *(int *) (arg0 + 0x1bc0);
    if (var2 == 0) {
        *(short *) (arg0 + 0x1be8) = 0;
        func_0205de24((struct Struct_0205de24_2 *) (arg0 + 0xec8), 0, 2);
        func_ov002_02161cf0(arg0);
        func_ov002_0215d864(arg0);
        func_020466e4((unsigned int *) func_020d6c00(), 1);
        if (*(int *) (arg0 + 0x247c) & 1) {
            ((SafeAllocator *) (arg0 + 0x864))->Reset();
            func_ov023_021dc9e8(arg0 + 0x50, (SafeAllocator *) (arg0 + 0x864),
                                GetInventoryItemByID(arg0, *(short *) (arg0 + 0x1be8), *(signed char *) (arg0 + 0x1c20)),
                                arg0 + 0x7ec, 0x50);
        } else {
            ((SafeAllocator *) (arg0 + 0x864))->Reset();
            func_ov023_021dc134(arg0 + 0x50,
                                GetInventoryItemByID(arg0, *(short *) (arg0 + 0x1be8), *(signed char *) (arg0 + 0x1c20)), 0);
            struct Struct_ov002_02162e50 {
                char unknown_0_[0x774];
                unsigned short unknown_774_;
            };
            ((Struct_ov002_02162e50 *) (arg0 + 0x50))->unknown_774_ |= 0x50;
            func_ov023_021dbfd0(arg0 + 0x50, (SafeAllocator *) (arg0 + 0x864));
            *(char **) (arg0 + 0x98) = arg0 + 0x7ec;
            *(int *) (arg0 + 0x247c) |= 1;
        }
        (*(int *) (self + 0x1bc0))++;
    } else if (phase == 1) {
        *(int *) (self + 0x247c) |= 4;
        func_ov002_02161b98(self);
        *(short *) (self + 0x1be8) =
            Window_GetSelectedIndex((struct Struct_0205c570 *) (self + 0xec8));
        *(short *) (self + 0x1c22) = GetInventoryItemByID(self, *(short *) (self + 0x1be8), *(signed char *) (self + 0x1c20));
        func_ov023_021dcae0(self + 0x50, *(short *) (self + 0x1c22));
        if (CheckFlagOrThreshold_02161b48(self, 1)) {
            *(short *) (self + 0x1c22) = -1;
            *(short *) (self + 0x1be8) = -1;
            func_ov002_02156e90(self);
            func_ov023_021dca88(self + 0x50);
        }
    }
}
#endif
