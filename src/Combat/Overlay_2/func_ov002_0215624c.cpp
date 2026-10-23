#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include <globaldefs.h>
#include "Input/Input.h"

#if defined(jpn)
#define REGIONAL_OFFSET(jp, us) jp
#define data_ov002_0216c96c data_ov002_0216cfc0
enum { Enum_ov002_0215624c_43 = 0x2e };
#else
#define REGIONAL_OFFSET(jp, us) us
enum { Enum_ov002_0215624c_43 = 0x2b };
#endif

struct Struct_ov002_02155960_2;
struct Struct_ov002_0215624c_15;
struct Struct_ov002_0215624c_17;
struct Struct_ov002_0215624c_18;
struct Struct_ov002_0215624c_19;
struct Struct_ov002_0215624c_20;
struct Struct_ov002_0215624c_21;
struct Struct_ov002_0215624c_22;
struct Struct_ov002_0215624c_23;
struct Struct_ov002_0215624c_24;
struct Struct_ov002_0215624c_25;
struct Struct_ov002_0215624c_11;
struct Struct_ov002_0215624c_26;
struct Struct_0201099c_3;

unsigned char *FindElementForFieldB0_0205d8c4(struct Struct_0205d81c *s);
int IsField0x9cEqual3_0204c7cc(unsigned char *obj);
void SetFieldAt0x30_0205bc24(void *obj, int value);
extern "C" int Window_Update(void *obj, int val);
int Window_GetSelectedIndex(struct Struct_0205c570 *s);
void PushInputLogB_020a1ef0(int id);
int GetGlobalField0x1c020421a0(void);
void Background_SetMapSize(unsigned char *obj, int value);
extern "C" void Background_SetPriority(void *obj, int val);
void Background_AllocateMap(struct AllocTarget0204b12c *obj,
                                                                                         SafeAllocator *alloc);
int Background_SetScroll(struct Obj0204b5e8 *obj, int a, int b);
extern "C" void ColorEffect_ConfigureAlphaBlend(int reg, int a, int b, int c, int d);
extern "C" void Background_FillRect(void *obj, unsigned short tile, int x, int y, int w, int h, unsigned short palette);
void Background_UploadMap(struct List0204b0e8 *obj, void *buf);
extern "C" void Background_LoadFile(void *obj, void *data, SafeAllocator *alloc, int size);
void WindowPane_AllocateBuffer(struct Obj0204c7a8 *obj, SafeAllocator *alloc,
                                                                           int buf, unsigned int size);
void Window_SetPanes(struct Struct_0205cf78 *s,
                                                                                     struct Elem_0205cf78 *arr,
                                                                                     unsigned char count);
extern "C" void *memset(void *dst, int value, unsigned int length);
extern "C" void *memcpy(void *dst, const void *src, unsigned int length);
void *GetTableEntry020421b0(int idx);
void CleanInvalidateCacheRange(const void *where, unsigned int len);
extern "C" void LoadToMainBG1CharacterData(const void *data, unsigned int offset, unsigned int length);
extern "C" void LoadToMainBG3CharacterData(const void *data, unsigned int offset, unsigned int length);
void Sprite_Init(struct Struct0205a198 *s);
void ClearField0And40205a234(struct ClearTarget0205a234 *t);
void SpriteContext_Init(char *p);
void *Pac_GetFile(struct Rec020467f0 *rec, int index, void **out, int *out44);
extern "C" void SpriteContext_LoadFile(void *a, void *ptr, int val, void *d);
void FindAndLinkMatchingEntry0205de24(struct Struct0205de24 *obj, unsigned char keyLow,
                                                                        unsigned char keyHigh);
int Pac_CountFiles(struct ActiveEntry02046900 *entry);
extern "C" void KeyTable_Load(void *dest, void *allocator, void *fileData, unsigned int size);
int KeyTable_Get(struct Container020e0310 *c, int key);
extern "C" void func_020dc7e8(int a, int b);
void InitBattleTag0215bf34(char *self);
void InitBattleTag0215c028(char *self);
extern "C" void func_ov002_0215bba8(char *self);
extern "C" void func_ov002_02161cf0(char *self);
extern "C" void func_ov002_0215c0f8(char *self);
extern "C" void func_ov002_0215a938(char *self);

struct Struct_ov002_0215624c_12 {
    int unknown_0_;
    int unknown_4_;
};

struct Struct_ov002_0215624c_13 {
    int unknown_0_;
    short unknown_4_;
    char unknown_6_[0x1a];
};

struct Struct_ov002_0215624c_14 {
    unsigned char unknown_0_[3];
};

struct Struct_ov002_0216c96c {
    unsigned char unknown_0_[4];
#if defined(jpn)
    struct Struct_ov002_0215624c_14 unknown_7_;
    struct Struct_ov002_0215624c_14 unknown_4_;
#else
    struct Struct_ov002_0215624c_14 unknown_4_;
    struct Struct_ov002_0215624c_14 unknown_7_;
#endif
};

struct Struct_ov002_0215624c_16 {
    unsigned char unknown_0_[0x1c];
    unsigned char unknown_1c_0_ : 4;
    unsigned char unknown_1c_4_ : 4;
};

extern struct Struct_ov002_0216c96c data_ov002_0216c96c;
#if defined(jpn)
extern char data_ov002_0216d50c[];
extern char data_ov002_0216d520[];
#endif
extern char data_ov002_0216ced4[];
extern char data_ov002_0216cee8[];
extern char data_ov002_0216cef8[];
extern char data_ov002_0216cf11[];

#define S16(off) (*(short *) (arg0 + (off)))
#define S32(off) (*(int *) (arg0 + (off)))
#define U8(off) (*(unsigned char *) (arg0 + (off)))
#define REG16(a) (*(volatile unsigned short *) (a))
#define REG32(a) (*(volatile unsigned int *) (a))

// USA: func_ov002_0215624c
extern "C" ARM void func_ov002_0215624c(char *arg0) {
    BackgroundLoader *var0 = BackgroundLoader::GetInstance();

    if (g_keyManager.TestKeysPressed(0x601)) {
        U8(REGIONAL_OFFSET(0x1af7, 0x1c2f)) = 1;
    }
    if (g_keyManager.TestKeysPressed(0x802)) {
        U8(REGIONAL_OFFSET(0x1af7, 0x1c2f))  = 0;
        S32(REGIONAL_OFFSET(0x1a80, 0x1bb8)) = Enum_ov002_0215624c_43;
        if (S32(REGIONAL_OFFSET(0x1a8c, 0x1bc4)) >= 0) {
            var0->RemoveTask(S32(REGIONAL_OFFSET(0x1a8c, 0x1bc4)));
            S32(REGIONAL_OFFSET(0x1a8c, 0x1bc4)) = -1;
        }
        for (int var1 = 0; var1 < 5; var1++) {
            var0->RemoveTask(((int *) (arg0 + REGIONAL_OFFSET(0x1a6c, 0x1ba4)))[var1]);
            *(int *) (arg0 + var1 * 4 + REGIONAL_OFFSET(0x1a6c, 0x1ba4)) = -1;
        }
        return;
    }

    unsigned char *var2 = func_0205d8c4((struct Struct_ov002_02155960_2 *) (arg0 + REGIONAL_OFFSET(0xe20, 0xec8)));
    if (var2 != 0 && func_0204c7cc(var2) && !(var2[0xc5] & 2)) {
        func_0205bc24(&((struct Struct_ov002_0215624c_12 *) (arg0 + REGIONAL_OFFSET(0xe20, 0xec8)))->unknown_4_, -1);
    }
    S32(REGIONAL_OFFSET(0x1a90, 0x1bc8)) = Window_Update(self + REGIONAL_OFFSET(0xe20, 0xec8), S32(REGIONAL_OFFSET(0x1a68, 0x1ba0)));
    short old   = S16(REGIONAL_OFFSET(0x1aa8, 0x1be0));
    S16(REGIONAL_OFFSET(0x1aa8, 0x1be0)) = Window_GetSelectedIndex((struct Struct_0205c570 *) (self + REGIONAL_OFFSET(0xe20, 0xec8)));
    if (S32(REGIONAL_OFFSET(0x1a88, 0x1bc0)) >= 1 && old != S16(REGIONAL_OFFSET(0x1aa8, 0x1be0))) {
        S32(REGIONAL_OFFSET(0x1a90, 0x1bc8)) = 1;
        int var4   = S32(REGIONAL_OFFSET(0x1a80, 0x1bb8));
        S32(REGIONAL_OFFSET(0x1a80, 0x1bb8)) = 1;
        func_ov002_0215bba8(arg0);
        S32(REGIONAL_OFFSET(0x1a80, 0x1bb8)) = var4;
    }

    if (S32(REGIONAL_OFFSET(0x1a88, 0x1bc0)) == 0) {
        PushInputLogB_020a1ef0(1);
        char *w     = (char *) GameState::GetInstance()->GetResources();
        S32(REGIONAL_OFFSET(0x1a98, 0x1bd0)) = *(int *) ((char *) GetGlobalField0x1c020421a0() + REGIONAL_OFFSET(0x28, 0x5c));
        ((SafeAllocator *) (self + REGIONAL_OFFSET(0x78c, 0x828)))->Reset();

        struct Bytes3_0215624c prio  = data_ov002_0216c96c.prio;
        struct Bytes3_0215624c layer = data_ov002_0216c96c.layer;
        struct Layer0215624c *o;
        for (int i = 0; i < 3; i++) {
            o = (struct Layer0215624c *) (self + REGIONAL_OFFSET(0xedc, 0xf84) + i * 0x20);
            Background_SetMapSize((unsigned char *) o, 0);
            o->lo = 0;
            o->hi = prio.v[i];
            Background_SetPriority(o, layer.v[i]);
            Background_AllocateMap((struct AllocTarget0204b12c *) o,
                                                                                     (SafeAllocator *) (self + REGIONAL_OFFSET(0x78c, 0x828)));
            Background_SetScroll((struct Obj0204b5e8 *) o, 0, 0);
        }

        REG16(0x0400000a) = (REG16(0x0400000a) & 0x43) | 0x1d00;
        REG16(0x0400000c) = (REG16(0x0400000c) & 0x43) | 0x1e00;
        REG16(0x0400000e) = (REG16(0x0400000e) & 0x43) | 0x1f08;
        ColorEffect_ConfigureAlphaBlend(0x04000050, 2, 1, 10, 6);

        char *o2;
        for (int i = 0; i < 3; i++) {
            o2 = self + REGIONAL_OFFSET(0xedc, 0xf84) + i * 0x20;
            Background_FillRect(o2, 0, 0, 0, 0x20, 0x19, 0);
            Background_UploadMap((struct List0204b0e8 *) o2, 0);
        }

        void *gfx = *(void **) (w + 0x2c);
        Background_LoadFile(self + REGIONAL_OFFSET(0xefc, 0xfa4), gfx, (SafeAllocator *) (self + REGIONAL_OFFSET(0x78c, 0x828)), 0);
        Background_LoadFile(self + REGIONAL_OFFSET(0xf1c, 0xfc4), gfx, (SafeAllocator *) (self + REGIONAL_OFFSET(0x78c, 0x828)), 0);

        for (int var13 = 0; var13 < 3; var13++) {
            struct Struct_ov002_0215624c_13 *var14 = (struct Struct_ov002_0215624c_13 *) (arg0 + REGIONAL_OFFSET(0xedc, 0xf84)) + var13;
            var14->unknown_0_               = 0x60;
            var14->unknown_4_              = 3;
        }

        S32(REGIONAL_OFFSET(0x1aa0, 0x1bd8)) = (int) ((SafeAllocator *) (self + REGIONAL_OFFSET(0x78c, 0x828)))->Allocate(0x4400);
        for (int i = 0; i < 12; i++) {
            char *o = self + REGIONAL_OFFSET(0xf3c, 0xfe4) + i * 0xe0;
            WindowPane_AllocateBuffer((struct Obj0204c7a8 *) o,
                                                                       (SafeAllocator *) (self + REGIONAL_OFFSET(0x78c, 0x828)), S32(REGIONAL_OFFSET(0x1aa0, 0x1bd8)), 0x400);
            *(char **) (o + 4) = self + REGIONAL_OFFSET(0xefc, 0xfa4);
        }
        *(char **) (arg0 + REGIONAL_OFFSET(0xeb8, 0xf60)) = arg0 + REGIONAL_OFFSET(0xedc, 0xf84);
        U8(REGIONAL_OFFSET(0xed2, 0xf7a))                 = 3;
        Window_SetPanes((struct Struct_0205cf78 *) (self + REGIONAL_OFFSET(0xe20, 0xec8)),
                                                                             (struct Elem_0205cf78 *) (self + REGIONAL_OFFSET(0xf3c, 0xfe4)), 12);

        memset((void *) S32(REGIONAL_OFFSET(0x1aa0, 0x1bd8)), 0, 0x60);
        memset((char *) S32(REGIONAL_OFFSET(0x1aa0, 0x1bd8)) + 0x20, 0x11111111, 0x20);
        memcpy((char *) S32(REGIONAL_OFFSET(0x1aa0, 0x1bd8)) + 0x40, func_020421b0(REGIONAL_OFFSET(0x1f, 0x15)), 0x20);
        CleanInvalidateCacheRange((void *) S32(REGIONAL_OFFSET(0x1aa0, 0x1bd8)), 0x60);
        LoadToMainBG1CharacterData((void *) S32(REGIONAL_OFFSET(0x1aa0, 0x1bd8)), 0, 0x60);
        LoadToMainBG3CharacterData((void *) S32(REGIONAL_OFFSET(0x1aa0, 0x1bd8)), 0, 0x60);

        for (unsigned char i = 0; i < REGIONAL_OFFSET(0x2c, 0x2b); i++) {
            Sprite_Init((struct Struct0205a198 *) (S32(REGIONAL_OFFSET(0x19bc, 0x1a64)) + i * 0x28));
        }
        ClearField0And40205a234((struct ClearTarget0205a234 *) S32(REGIONAL_OFFSET(0x19c4, 0x1a6c)));
        SpriteContext_Init((char *) S32(REGIONAL_OFFSET(0x19c0, 0x1a68)));
        *(unsigned char *) (S32(REGIONAL_OFFSET(0x19c0, 0x1a68)) + 0x50) = 0;
        {
            char *var18               = (char *) S32(REGIONAL_OFFSET(0x19c0, 0x1a68));
            *(int *) (var18 + 0x40)   = S32(REGIONAL_OFFSET(0x19bc, 0x1a64));
            *(short *) (var18 + 0x4c) = REGIONAL_OFFSET(0x2c, 0x2b);
        }
        *(int *) (S32(REGIONAL_OFFSET(0x19c0, 0x1a68)) + 0x3c) = S32(REGIONAL_OFFSET(0x19c4, 0x1a6c));
        memcpy((void *) S32(REGIONAL_OFFSET(0x1aa0, 0x1bd8)), *(void **) (var5 + 0x30), *(unsigned int *) (var5 + 0x34));

        ((SafeAllocator *) (self + REGIONAL_OFFSET(0x7dc, 0x878)))->Reset();
        for (int i = 0; i < 4; i++) {
            int val;
            void *out;
            void *rec = Pac_GetFile((struct Rec020467f0 *) S32(REGIONAL_OFFSET(0x1aa0, 0x1bd8)), i, &out, &val);
            SpriteContext_LoadFile((void *) S32(REGIONAL_OFFSET(0x19c0, 0x1a68)), rec, val, self + REGIONAL_OFFSET(0x7dc, 0x878));
        }

        S16(REGIONAL_OFFSET(0x1aa8, 0x1be0)) = 0;
        func_0205de24((struct Struct_ov002_0215624c_11 *) (arg0 + REGIONAL_OFFSET(0xe20, 0xec8)), 0, 2);

        if (U8(REGIONAL_OFFSET(0x22b5, 0x2485)) == 0 && U8(REGIONAL_OFFSET(0x2364, 0x253c)) == 0) {
            func_ov002_0215bf34(arg0);
            func_ov002_0215c028(arg0);
            int var23   = S32(REGIONAL_OFFSET(0x1a80, 0x1bb8));
            S32(REGIONAL_OFFSET(0x1a80, 0x1bb8)) = 1;
            func_ov002_02161cf0(arg0);
            func_ov002_0215c0f8(arg0);
            S32(REGIONAL_OFFSET(0x1a80, 0x1bb8)) = var23;
        }

        S32(REGIONAL_OFFSET(0x22ac, 0x247c)) |= 4;
        REG16(0x04000008) = (REG16(0x04000008) & ~3) | 3;
        REG16(0x0400000a) = (REG16(0x0400000a) & ~3) | 2;
        REG16(0x0400000c) = (REG16(0x0400000c) & ~3) | 1;
        REG16(0x0400000e) = (REG16(0x0400000e) & ~3);
        REG32(0x04000000) = (REG32(0x04000000) & ~0x1f00) | 0x1f00;
        Window_Update(self + REGIONAL_OFFSET(0xe20, 0xec8), S32(REGIONAL_OFFSET(0x1a68, 0x1ba0)));
        Window_Update(self + REGIONAL_OFFSET(0xe20, 0xec8), S32(REGIONAL_OFFSET(0x1a68, 0x1ba0)));

        if (U8(REGIONAL_OFFSET(0x22b5, 0x2485)) != 0) {
            char *var24                 = (char *) GameState::GetInstance();
#if defined(jpn)
            *(short *) (var24 + 0x6f9c) = 0;
            *(short *) (var24 + 0x6f9e) = -1;
            *(short *) (var24 + 0x6fa0) = -1;
#else
            *(short *) (var24 + 0x71dc) = 0;
            *(short *) (var24 + 0x7f58) = 0;
            *(short *) (var24 + 0x71de) = -1;
            *(short *) (var24 + 0x71e0) = -1;
#endif
        }

#if defined(jpn)
        S32(REGIONAL_OFFSET(0x1a6c, 0x1ba4)) = var0->QueueLoadFile(data_ov002_0216d50c, 0);
        S32(REGIONAL_OFFSET(0x1a70, 0x1ba8)) = var0->QueueLoadFile(data_ov002_0216d520, 0);
#else
        S32(REGIONAL_OFFSET(0x1a6c, 0x1ba4)) = var0->QueueLoadFileInGP2(data_ov002_0216ced4, data_ov002_0216cee8, 0);
        S32(REGIONAL_OFFSET(0x1a70, 0x1ba8)) = var0->QueueLoadFileInGP2(data_ov002_0216cef8, data_ov002_0216cf11, 0);
#endif
        S32(REGIONAL_OFFSET(0x1a88, 0x1bc0))++;
    } else if (S32(REGIONAL_OFFSET(0x1a88, 0x1bc0)) == 1) {
        unsigned char var25 = 0;
        for (int var26 = 0; var26 < 2; var26++) {
            if (var0->GetTaskStatus(*(int *) (arg0 + var26 * 4 + REGIONAL_OFFSET(0x1a6c, 0x1ba4)))) {
                var25++;
            }
        }
        if (var25 != 2) {
            return;
        }

        if (loader->GetTaskStatus(S32(REGIONAL_OFFSET(0x1a6c, 0x1ba4)))) {
            void *out;
            void *data;
            unsigned int len;
            int val;
            loader->GetLoadedFileByID(S32(REGIONAL_OFFSET(0x1a6c, 0x1ba4)), &data, &len);
            int n = Pac_CountFiles((struct ActiveEntry02046900 *) data);
            for (unsigned char i = 0; i < REGIONAL_OFFSET(0x2c, 0x2b); i++) {
                Sprite_Init((struct Struct0205a198 *) (S32(REGIONAL_OFFSET(0x19bc, 0x1a64)) + i * 0x28));
            }
            ClearField0And40205a234((struct ClearTarget0205a234 *) S32(REGIONAL_OFFSET(0x19c4, 0x1a6c)));
            SpriteContext_Init((char *) S32(REGIONAL_OFFSET(0x19c0, 0x1a68)));
            *(unsigned char *) (S32(REGIONAL_OFFSET(0x19c0, 0x1a68)) + 0x50) = 0;
            {
                char *var33               = (char *) S32(REGIONAL_OFFSET(0x19c0, 0x1a68));
                *(int *) (var33 + 0x40)   = S32(REGIONAL_OFFSET(0x19bc, 0x1a64));
                *(short *) (var33 + 0x4c) = REGIONAL_OFFSET(0x2c, 0x2b);
            }
            *(int *) (S32(REGIONAL_OFFSET(0x19c0, 0x1a68)) + 0x3c) = S32(REGIONAL_OFFSET(0x19c4, 0x1a6c));
            ((SafeAllocator *) (self + REGIONAL_OFFSET(0x7dc, 0x878)))->Reset();
            for (int i = 0; i < n; i++) {
                void *rec = Pac_GetFile((struct Rec020467f0 *) data, i, &out, &val);
                SpriteContext_LoadFile((void *) S32(REGIONAL_OFFSET(0x19c0, 0x1a68)), rec, val, self + REGIONAL_OFFSET(0x7dc, 0x878));
            }
            var0->RemoveTask(S32(REGIONAL_OFFSET(0x1a6c, 0x1ba4)));
            S32(REGIONAL_OFFSET(0x1a6c, 0x1ba4)) = -1;
        }

        if (loader->GetTaskStatus(S32(REGIONAL_OFFSET(0x1a70, 0x1ba8)))) {
            void *data;
            unsigned int len;
            loader->GetLoadedFileByID(S32(REGIONAL_OFFSET(0x1a70, 0x1ba8)), &data, &len);
            ((SafeAllocator *) (self + REGIONAL_OFFSET(0x7a0, 0x83c)))->Reset();
            KeyTable_Load(self + REGIONAL_OFFSET(0x8, 0x20), self + REGIONAL_OFFSET(0x7a0, 0x83c), data, len);
            S32(REGIONAL_OFFSET(0x1aa4, 0x1bdc)) = KeyTable_Get((struct Container020e0310 *) (self + REGIONAL_OFFSET(0x8, 0x20)), 0);
            loader->RemoveTask(S32(REGIONAL_OFFSET(0x1a70, 0x1ba8)));
            S32(REGIONAL_OFFSET(0x1a70, 0x1ba8)) = -1;
        }

        if (U8(REGIONAL_OFFSET(0x22b5, 0x2485)) != 0) {
            S32(REGIONAL_OFFSET(0x1a80, 0x1bb8)) = 4;
            S32(REGIONAL_OFFSET(0x1a84, 0x1bbc)) = Enum_ov002_0215624c_43;
            S32(REGIONAL_OFFSET(0x1a88, 0x1bc0)) = 0;
        } else {
            S32(REGIONAL_OFFSET(0x1a80, 0x1bb8)) = 1;
            S32(REGIONAL_OFFSET(0x1a84, 0x1bbc)) = Enum_ov002_0215624c_43;
            S32(REGIONAL_OFFSET(0x1a88, 0x1bc0)) = 1;
        }
        S32(REGIONAL_OFFSET(0x22ac, 0x247c)) |= 2;
        U8(REGIONAL_OFFSET(0x22aa, 0x247a)) = 0;
        if (U8(REGIONAL_OFFSET(0x22b5, 0x2485)) == 0) {
            func_ov002_0215a938(arg0);
        }
        func_020dc7e8(1, -1);
        func_020dc7e8(8, -1);
    }
}
