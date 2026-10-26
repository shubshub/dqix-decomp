#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include <globaldefs.h>

struct BackgroundGraphics;
struct WindowPane;
struct Struct_0205cf78;
struct WindowPane;
struct Struct0205a198;
struct ClearTarget0205a234;
struct PacRecord;
struct Container020e0310;
struct Struct_0206f7f4;

extern "C" Struct_0206f7f4 *func_0206f504();
extern "C" short func_0206f7f4(Struct_0206f7f4 *, int);
extern "C" char *strcpy(char *dst, const char *src);
extern "C" int sprintf(char *dst, const char *fmt, ...);
extern "C" void *__clear(void *dst, int count);
extern "C" int func_02005a94();
extern "C" void func_ov003_0215e1ec(char *self);
extern "C" void func_ov003_0215ca90(void *self, int v);
extern "C" void Background_Init(struct BackgroundGraphics *obj);
extern "C" void Background_SetMapSize(unsigned char *obj, int value);
extern "C" void Background_SetPriority(void *obj, int val);
extern "C" void Background_AllocateMap(struct BackgroundGraphics *obj,
                                                                                         SafeAllocator *alloc);
extern "C" int Background_SetScroll(struct BackgroundGraphics *obj, int a, int b);
extern "C" void ColorEffect_ConfigureAlphaBlend(int reg, int a, int b, int c, int d);
extern "C" int Pac_CountFiles(struct PacRecord *entry);
extern "C" void *Pac_GetFile(struct PacRecord *rec, int index, void **out, int *out44);
extern "C" void Background_LoadFile(void *obj, void *data, SafeAllocator *alloc, int size);
extern "C" void Background_FillRect(void *obj, unsigned short tile, int x, int y, int w, int h, unsigned short palette);
extern "C" void Background_UploadMap(struct BackgroundGraphics *obj, void *buf);
extern "C" void WindowPane_AllocateBuffer(struct WindowPane *obj, SafeAllocator *alloc,
                                                                           int buf, unsigned int size);
extern "C" void Window_SetPanes(struct Struct_0205cf78 *s,
                                                                                     struct WindowPane *arr,
                                                                                     unsigned char count);
extern "C" void Sprite_Init(struct Struct0205a198 *s);
extern "C" void func_0205a234(struct ClearTarget0205a234 *t);
extern "C" void SpriteContext_LoadFile(void *a, void *ptr, int val, void *d);
extern "C" void KeyTable_Load(void *dest, void *allocator, void *fileData, unsigned int size);
extern "C" int KeyTable_Get(struct Container020e0310 *c, int key);

struct Struct_ov003_0215caf0 {
    unsigned char v[2];
};

struct Struct_ov003_0217e0a8 {
    struct Struct_ov003_0215caf0 layer;
    struct Struct_ov003_0215caf0 unknown_2_;
};

struct Struct_ov003_0215caf0_2 {
    unsigned char pad[0x1c];
    unsigned char lo : 4;
    unsigned char hi : 4;
};

extern char data_ov003_0217febc[];
extern char data_ov003_0217fed6[];
extern char data_ov003_0217fee7[];
extern char data_ov003_0217ff02[];
extern char data_ov003_0217ff14[];
extern char data_ov003_0217ff27[];
extern struct Struct_ov003_0217e0a8 data_ov003_0217f3a8;

#if defined(jpn)
extern char data_ov003_0217e6d4[];
extern char data_ov003_0217e6ee[];
extern char data_ov003_0217e70b[];
extern char data_ov003_0217e729[];
extern char data_ov003_0217e73c[];
#define data_ov003_0217f3a8 data_ov003_0217e0a8
extern struct Struct_ov003_0217e0a8 data_ov003_0217e0a8;
enum { regionalShift = 0x18, Enum_ov003_0215caf0_0_2 = 1, Enum_ov003_0215caf0_6144 = 0x1000, Enum_ov003_0215caf0_512 = 0x100 };
#else
enum { regionalShift = 0, Enum_ov003_0215caf0_0_2 = 0, Enum_ov003_0215caf0_6144 = 0x1800, Enum_ov003_0215caf0_512 = 0x200 };
#endif

#define S16(off) (*(short *) (self + (off) + regionalShift))
#define S32(off) (*(int *) (self + (off) + regionalShift))
#define U8(off) (*(unsigned char *) (self + (off) + regionalShift))
#define REG16(a) (*(volatile unsigned short *) (a))
#define REG32(a) (*(volatile unsigned int *) (a))

// USA: func_ov003_0215caf0
extern "C" ARM void func_ov003_0215caf0(char *self) {
    BackgroundLoader *loader = BackgroundLoader::GetInstance();
    unsigned char state      = U8(0x3b8);

    if (state == 0) {
#if defined(jpn)
        S32(0x3b4) = (int) ((SafeAllocator *) (self + 0x3c))->Allocate(0x10);
        int idx    = (short) (func_0206f7f4(func_0206f504(), 0) - 1);
        if (idx < 0) {
            idx = 0;
        }
        if (idx == 0xe) {
            U8(0x3f3) = 1;
        }
        char buf1[0x40];
        if (U8(0x3f0) != 0) {
            strcpy(buf1, data_ov003_0217e6d4);
        } else {
            sprintf(buf1, data_ov003_0217e6ee, idx);
        }
        ((int *) S32(0x3b4))[0] = loader->QueueLoadFile(buf1, 0);
        ((int *) S32(0x3b4))[1] = loader->QueueLoadFile(data_ov003_0217e70b, 0);
        ((int *) S32(0x3b4))[2] = loader->QueueLoadFile(data_ov003_0217e729, 0);
        ((int *) S32(0x3b4))[3] = loader->QueueLoadFile(data_ov003_0217e73c, 0);
#else
        S32(0x3b4) = (int) ((SafeAllocator *) (self + 0x3c))->Allocate(0xc);
        int idx    = (short) (func_0206f7f4(func_0206f504(), 0) - 1);
        if (idx < 0) {
            idx = 0;
        }
        if (idx == 0xe) {
            U8(0x3f3) = 1;
        }
        char buf1[0x40];
        char buf2[0x18];
        __clear(buf1, 0x40);
        __clear(buf2, 0x18);
        if (U8(0x3f0) != 0) {
            strcpy(buf1, data_ov003_0217febc);
            strcpy(buf2, data_ov003_0217fed6);
        } else {
            sprintf(buf1, data_ov003_0217fee7, idx);
            sprintf(buf2, data_ov003_0217ff02, idx);
        }
        ((int *) S32(0x3b4))[0] = loader->QueueLoadFileInGP2(buf1, buf2, 0);
        ((int *) S32(0x3b4))[1] = loader->QueueLoadFile(data_ov003_0217ff14, 0);
        ((int *) S32(0x3b4))[2] = loader->QueueLoadFile(data_ov003_0217ff27, 0);
#endif
        U8(0x3b8)               = U8(0x3b8) + 1;
    }

    if (state == 1) {
        if (loader->GetTaskStatus(((int *) S32(0x3b4))[0]) > 0) {
            void *data;
            unsigned int len;
            loader->GetLoadedFileByID(((int *) S32(0x3b4))[0], &data, &len);
            ((SafeAllocator *) self)->Reset();
            KeyTable_Load(self + 0x64, self, data, len);
            if (KeyTable_Get((struct Container020e0310 *) (self + 0x64), 0x32) != 0) {
                U8(0x3ee) = func_02005a94();
            }
            if (U8(0x3ee) == 3) {
                U8(0x3ee) = 0;
                U8(0x3ef) = 0;
            }
            if (U8(0x3f0) != 0) {
                U8(0x3ee) = 2;
                U8(0x3ef) = 1;
            }
            loader->RemoveTask(((int *) S32(0x3b4))[0]);
            ((int *) S32(0x3b4))[0] = -1;
        }

#if defined(jpn)
        if (loader->GetTaskStatus(((int *) S32(0x3b4))[1]) > 0) {
            void *data1;
            unsigned int len1;
            loader->GetLoadedFileByID(((int *) S32(0x3b4))[1], &data1, &len1);
            ((SafeAllocator *) (self + 0x14))->Reset();
            KeyTable_Load(self + 0x7c, self + 0x14, data1, len1);
            loader->RemoveTask(((int *) S32(0x3b4))[1]);
            ((int *) S32(0x3b4))[1] = -1;
        }

#endif
        if (loader->GetTaskStatus(((int *) S32(0x3b4))[1 + Enum_ov003_0215caf0_0_2]) > 0) {
            ((SafeAllocator *) (self + 0x28))->Reset();
            struct Struct_ov003_0215caf0 var11  = data_ov003_0217f3a8.unknown_2_;
            struct Struct_ov003_0215caf0 layer = data_ov003_0217f3a8.layer;
            struct Struct_ov003_0215caf0_2 *o;
            for (int i = 0; i < 2; i++) {
                o = (struct Struct_ov003_0215caf0_2 *) (self + 0x154 + regionalShift + i * 0x20);
                Background_Init((struct BackgroundGraphics *) o);
                Background_SetMapSize((unsigned char *) o, 0);
                o->lo = 0;
                o->hi = var11.v[i];
                Background_SetPriority(o, layer.v[i]);
                Background_AllocateMap((struct BackgroundGraphics *) o,
                                                                                         (SafeAllocator *) (self + 0x28));
                Background_SetScroll((struct BackgroundGraphics *) o, 0, 0);
            }
            REG16(0x0400000a) = (REG16(0x0400000a) & 0x43) | 0xd08;
            REG16(0x0400000c) = (REG16(0x0400000c) & 0x43) | 0xe08;
            ColorEffect_ConfigureAlphaBlend(0x04000050, 2, 1, 10, 6);

            void *out;
            void *data2;
            unsigned int len2;
            int val;
            loader->GetLoadedFileByID(((int *) S32(0x3b4))[1 + Enum_ov003_0215caf0_0_2], &data2, &len2);
            int n = Pac_CountFiles((struct PacRecord *) data2);
            for (int i = 0; i < n; i++) {
                void *rec = Pac_GetFile((struct PacRecord *) data2, i, &out, &val);
                if (rec != 0) {
                    Background_LoadFile(self + 0x174 + regionalShift, rec, (SafeAllocator *) (self + 0x28), val);
                }
            }
            char *o2;
            for (int i = 0; i < 2; i++) {
                o2 = self + 0x154 + regionalShift + i * 0x20;
                Background_FillRect(o2, 0, 0, 0, 0x20, 0x19, 0);
                Background_UploadMap((struct BackgroundGraphics *) o2, 0);
            }
            S32(0x354) = (int) ((SafeAllocator *) (self + 0x28))->Allocate(Enum_ov003_0215caf0_6144);
            char *o3;
            for (int i = 0; i < 2; i++) {
                o3 = self + 0x194 + regionalShift + i * 0xe0;
                WindowPane_AllocateBuffer((struct WindowPane *) o3,
                                                                           (SafeAllocator *) (self + 0x28), S32(0x354), Enum_ov003_0215caf0_512);
                *(char **) (o3 + 4) = self + 0x174 + regionalShift;
            }
            *(char **) (self + 0x130 + regionalShift) = self + 0x154 + regionalShift;
            U8(0x14a)                 = 2;
            Window_SetPanes((struct Struct_0205cf78 *) (self + 0x98 + regionalShift),
                                                                                 (struct WindowPane *) (self + 0x194 + regionalShift), 2);
            REG16(0x04000008) = (REG16(0x04000008) & ~3) | 2;
            REG16(0x0400000a) = (REG16(0x0400000a) & ~3) | 1;
            REG16(0x0400000c) = (REG16(0x0400000c) & ~3);
            REG16(0x0400000e) = (REG16(0x0400000e) & ~3) | 3;
            REG32(0x04000000) = (REG32(0x04000000) & ~0x1f00) | 0x1700;
            loader->RemoveTask(((int *) S32(0x3b4))[1 + Enum_ov003_0215caf0_0_2]);
            ((int *) S32(0x3b4))[1 + Enum_ov003_0215caf0_0_2] = -1;
        }

        if (loader->GetTaskStatus(((int *) S32(0x3b4))[2 + Enum_ov003_0215caf0_0_2]) > 0) {
            ((SafeAllocator *) (self + 0x50))->Reset();
            S32(0x3ac) = (int) ((SafeAllocator *) (self + 0x50))->Allocate(0xf0);
            for (unsigned char i = 0; i < 6; i++) {
                Sprite_Init((struct Struct0205a198 *) (S32(0x3ac) + i * 0x28));
            }
            S32(0x3b0) = (int) ((SafeAllocator *) (self + 0x50))->Allocate(8);
            func_0205a234((struct ClearTarget0205a234 *) S32(0x3b0));
            U8(0x3a8)  = 0;
            S32(0x398) = S32(0x3ac);
            S16(0x3a4) = 6;
            S32(0x394) = S32(0x3b0);
            void *out3;
            void *data3;
            unsigned int len3;
            int val3;
            loader->GetLoadedFileByID(((int *) S32(0x3b4))[2 + Enum_ov003_0215caf0_0_2], &data3, &len3);
            int n3 = Pac_CountFiles((struct PacRecord *) data3);
            for (int i = 0; i < n3; i++) {
                void *rec3 = Pac_GetFile((struct PacRecord *) data3, i, &out3, &val3);
                SpriteContext_LoadFile(self + 0x358 + regionalShift, rec3, val3, self + 0x50);
            }
            loader->RemoveTask(((int *) S32(0x3b4))[2 + Enum_ov003_0215caf0_0_2]);
            ((int *) S32(0x3b4))[2 + Enum_ov003_0215caf0_0_2] = -1;
        }

        int var34 = 1;
        for (int i = 0; i < 3 + Enum_ov003_0215caf0_0_2; i++) {
            if (((int *) S32(0x3b4))[i] >= 0) {
                var34 = 0;
            }
        }
        if (var34 != 0) {
            state++;
        }
    }

    if (state == 2) {
        func_ov003_0215e1ec(self);
        if (U8(0x3f0) != 0) {
            func_ov003_0215ca90(self, 3);
        } else {
            int g = KeyTable_Get((struct Container020e0310 *) (self + 0x64), 0x2710);
            int r = 1;
            if (g != 0) {
                r = func_02005a94();
            }
            func_ov003_0215ca90(self, r);
            if (r == 0) {
                U8(0x3f2) = 1;
            }
        }
        U8(0x3bc) = 1;
        U8(0x3b8) = 0;
    }
}
