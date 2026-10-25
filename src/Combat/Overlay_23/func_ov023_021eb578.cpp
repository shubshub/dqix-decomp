#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "GameState/GameState.h"

struct GameResources;
struct Struct_0201099c_3;
struct Struct_0205cf78;
struct WindowPane;
struct PacRecord;
struct BackgroundGraphics;
struct WindowPane;
struct Struct0205a198;
struct ClearTarget0205a234;

void SetSubBrightness(GameResources* resources, int brightness, int duration);
void SetMainBrightness(GameResources* resources, int brightness, int duration);
int IsBrightnessTransitionActive(GameResources* resources);
void* GlobalFlags_GetInstance(void);
void FlagWord_SetBits(unsigned int* p, unsigned int mask);
void OrGlobalFlag0x40_020dc2bc(void);
extern "C" void KeyTable_Load(void* dest, void* allocator, void* fileData, unsigned int size);
int MessageSystem_GetInstance(void);
void ConfigureSubBg1Control_021ec368(int screenSize, int colorMode, int screenBase, int charBase, int bit13);
extern "C" void func_ov023_021ec39c(int screenSize, int colorMode, int screenBase, int charBase);
extern "C" void func_ov023_021ec3c8(int screenSize, int colorMode, int screenBase, int charBase);
extern "C" void func_ov023_021ec3f4(int screenSize, int colorMode, int screenBase, int charBase);
void ConfigureBg1Control_021ec420(int screenSize, int colorMode, int screenBase, int charBase, int bit13);
extern "C" void func_ov023_021ec454(int screenSize, int colorMode, int screenBase, int charBase);
void Background_SetMapSize(unsigned char* obj, int value);
extern "C" void Background_SetPriority(void*, int);
int Background_SetScroll(struct BackgroundGraphics* obj, int a, int b);
void Background_AllocateMap(struct BackgroundGraphics* obj, SafeAllocator* alloc);
int Pac_CountFiles(struct PacRecord* entry);
void* Pac_GetFile(struct PacRecord* rec, int index, void** out, int* out44);
extern "C" void Background_LoadFile(void* list, void* payload, SafeAllocator* alloc, int field44);
extern "C" void Background_FillRect(void* target, int type, int a, int b, int c, int d, int flags);
void Background_UploadMap(struct BackgroundGraphics* obj, void* buf);
void WindowPane_AllocateBuffer(struct WindowPane* obj, SafeAllocator* alloc, int val, unsigned int len);
void Window_SetPanes(struct Struct_0205cf78* s, struct WindowPane* arr, unsigned char count);
int KeyTable_Get(struct Container020e0310* c, int key);
void Background_Init(struct BackgroundGraphics* obj);
void Background_AllocateScreens(struct BackgroundGraphics* obj, int count, SafeAllocator* alloc);
void Background_DrawScreen(struct BackgroundGraphics*, unsigned int, int, int, short, short, short, short, unsigned short);
void SpriteContext_Init(char* obj);
void Sprite_Init(struct Struct0205a198* p);
void ClearField0And40205a234(struct ClearTarget0205a234* target);
extern "C" void SpriteContext_LoadFile(void* a, void* ptr, int val, void* d);

extern char data_ov023_021fe108[];
#if defined(jpn)
extern char data_ov023_021fd39c[];
#endif
extern char data_ov023_021fe121[];
extern char data_ov023_021fe131[];
extern unsigned char data_ov023_021fd844[];

struct Struct_ov008_021895a8 {
    unsigned char unknown_0_[2];
};

struct Struct_ov023_021eb578 {
    char unknown_0_[0x1c];
    unsigned char unknown_1c_0_ : 4;
    unsigned char unknown_1c_4_ : 4;
    char unknown_1d_[3];
};

struct Struct_ov023_021eb578_2 {
    char unknown_0_[4];
    Struct_ov023_021eb578* unknown_4_;
    char unknown_8_[0xd8];
};

struct Struct_ov023_021eb578_3 {
    char unknown_0_[0x3c];
    char* unknown_3c_;
    char* unknown_40_;
    char unknown_44_[8];
    short unknown_4c_;
    char unknown_4e_[2];
    unsigned char unknown_50_;
};

struct Struct_ov023_021eb578_4 {
    SafeAllocator* unknown_0_;
    char unknown_4_[0x18];
    int unknown_1c_;
    int unknown_20_;
    int unknown_24_;
    char unknown_28_[0x1c];
    Struct_ov023_021eb578 unknown_44_[2];
    Struct_ov023_021eb578 unknown_84_[2];
    char unknown_c4_[0x98];
    Struct_ov023_021eb578* unknown_15c_;
    char unknown_160_[0x16];
    unsigned char unknown_176_;
    char unknown_177_[9];
    Struct_ov023_021eb578_2 unknown_180_[3];
    char* unknown_420_;
    Struct_ov023_021eb578_3* unknown_424_;
    char* unknown_428_;
    char* unknown_42c_;
    unsigned char unknown_430_;
    unsigned char unknown_431_;
    unsigned char unknown_432_;
    char unknown_433_;
    int unknown_434_;
    unsigned short unknown_438_;
};

#define IS_SUB_SCREEN_MODE(self)     ((self)->unknown_430_ == 0 || (self)->unknown_430_ == 1 || (self)->unknown_430_ == 6 || ((self)->unknown_430_ == 7 && !((self)->unknown_438_ & 8)))
#define IS_MAIN_SCREEN_MODE(self) ((self)->unknown_430_ == 2 || ((self)->unknown_430_ == 7 && ((self)->unknown_438_ & 8)))

#define REG16(a) (*(volatile unsigned short*)(a))
#define REG32(a) (*(volatile unsigned int*)(a))

#define SET_LAYER_PRIORITIES(m0, m1, m2, m3, mPlanes, s0, s1, s2, s3, sPlanes)     do {         REG16(0x4000008) = (REG16(0x4000008) & ~3) | (m0);         REG16(0x400000a) = (REG16(0x400000a) & ~3) | (m1);         REG16(0x400000c) = (REG16(0x400000c) & ~3) | (m2);         REG16(0x400000e) = (REG16(0x400000e) & ~3) | (m3);         REG32(0x4000000) = (REG32(0x4000000) & ~0x1f00) | ((mPlanes) << 8);         REG16(0x4001008) = (REG16(0x4001008) & ~3) | (s0);         REG16(0x400100a) = (REG16(0x400100a) & ~3) | (s1);         REG16(0x400100c) = (REG16(0x400100c) & ~3) | (s2);         REG16(0x400100e) = (REG16(0x400100e) & ~3) | (s3);         REG32(0x4001000) = (REG32(0x4001000) & ~0x1f00) | ((sPlanes) << 8);     } while (0)

// USA: func_ov023_021eb578
extern "C" ARM void func_ov023_021eb578(Scene021eb578* self) {
    SafeAllocator* allocs;
    FontBankLoader* g;
    GameResources* res;
    BackgroundLoader* loader;
    unsigned char state;
    res = GameState::GetInstance()->GetResources();
    g = FontBankLoader_GetInstance();
    loader = BackgroundLoader::GetInstance();
    state = self->state;

    if (var4 == 0) {
        if (IS_SUB_SCREEN_MODE(arg0)) {
            SetSubBrightness(var2, -16, 15);
        } else if (IS_MAIN_SCREEN_MODE(arg0)) {
            SetMainBrightness(var2, -16, 15);
        }
        func_02094b40(var1);
        func_02094b34(var1, 0x71, 0x201, 0, 0);
        arg0->unknown_432_++;
    }

    if (var4 == 1) {
        if (IsBrightnessTransitionActive(var2)) {
            return;
        }
        if (func_02094b4c(var1) == 0) {
            return;
        }
        if (self->flags & 0x10) {
            FlagWord_SetBits((unsigned int*)GlobalFlags_GetInstance(), 1);
            OrGlobalFlag0x40_020dc2bc();
        }
#if defined(jpn)
        arg0->unknown_434_ = var3->QueueLoadFile(data_ov023_021fd39c, NULL);
#else
        arg0->unknown_434_ = var3->QueueLoadFileInGP2(data_ov023_021fe108, data_ov023_021fe121, NULL);
#endif
        arg0->unknown_432_++;
    }

    if (var4 == 2) {
        void* var5;
        unsigned int var6;
        unsigned char var7[2];
        int var8;
        if (var3->GetTaskStatus(arg0->unknown_434_) == 0) {
            return;
        }
        loader->GetLoadedFileByID(self->taskId, &data, &length);
        allocs = self->allocs;
        allocs[2].Reset();
        KeyTable_Load(self->container, &allocs[2], data, length);
        loader->RemoveTask(self->taskId);
        self->taskId = -1;
#if defined(jpn)
        self->f1c = *(int*)(MessageSystem_GetInstance() + 0x28);
#else
        self->f1c = *(int*)(MessageSystem_GetInstance() + 0x5c);
#endif
        if (arg0->unknown_430_ == 0 || arg0->unknown_430_ == 1) {
            func_ov023_021ec368(0, 0, 0x1a, 4, 0);
            func_ov023_021ec39c(0, 0, 0x1b, 4);
            func_ov023_021ec3c8(0, 0, 0x1c, 6);
            func_ov023_021ec3f4(0, 0, 0x1d, 2);
            var7[0] = 1;
            var7[1] = 0;
        } else if (arg0->unknown_430_ == 7) {
            if (!(arg0->unknown_438_ & 8)) {
                func_ov023_021ec368(0, 0, 0xe, 0, 0);
                func_ov023_021ec39c(0, 0, 0xf, 0);
                func_ov023_021ec3c8(0, 0, 7, 1);
                func_ov023_021ec3f4(0, 0, 0x1e, 2);
                var7[0] = 1;
                var7[1] = 0;
            } else {
                func_ov023_021ec420(0, 0, 0, 1, 0);
                func_ov023_021ec454(0, 0, 0x1f, 1);
                func_ov023_021ec3f4(0, 0, 0x17, 3);
                func_ov023_021ec3c8(0, 0, 0x17, 2);
                var7[0] = 0;
                var7[1] = 1;
            }
        } else if (arg0->unknown_430_ == 2) {
            func_ov023_021ec420(0, 0, 0, 1, 0);
            func_ov023_021ec454(0, 0, 0x1f, 1);
            func_ov023_021ec3f4(0, 0, 0x17, 3);
            func_ov023_021ec3c8(0, 0, 0x17, 2);
            var7[0] = 0;
            var7[1] = 1;
        } else if (arg0->unknown_430_ == 6) {
            func_ov023_021ec368(0, 0, 0xe, 0, 0);
            func_ov023_021ec39c(0, 0, 0xf, 0);
            func_ov023_021ec3c8(0, 0, 7, 1);
            func_ov023_021ec3f4(0, 0, 0x1d, 2);
            var7[0] = 1;
            var7[1] = 0;
        }
        for (i = 0; i < 2; i++) {
            Layer021eb578* layer = &self->subLayers[i];
            Background_SetMapSize((unsigned char*)layer, 0);
            layer->screen = screens[i];
            layer->priority = 3;
            Background_SetPriority(layer, 0);
            Background_SetScroll((struct BackgroundGraphics*)layer, 0, 0);
            Background_AllocateMap((struct BackgroundGraphics*)layer, &self->allocs[1]);
        }
        arg0->unknown_434_ = var3->QueueLoadFile(data_ov023_021fe131, NULL);
        arg0->unknown_432_++;
    }

    if (var4 == 3) {
        void* var10;
        void* var11;
        unsigned int var12;
        int var13;
        void* var14;
        unsigned char var15[3];
        int var16;
        int var17;
        int var18;
        int var19;
        if (var3->GetTaskStatus(arg0->unknown_434_) == 0) {
            return;
        }
        allocs = self->allocs;
        loader->GetLoadedFileByID(self->taskId, &data, &length);
        count = Pac_CountFiles((struct PacRecord*)data);
        for (i = 0; i < count; i++) {
            rec = Pac_GetFile((struct PacRecord*)data, i, &out, &field);
            if (rec != NULL && i != 1) {
                Background_LoadFile(&self->subLayers[0], rec, &allocs[1], field);
                Background_LoadFile(&self->subLayers[1], rec, &allocs[1], field);
            }
        }
        loader->RemoveTask(self->taskId);
        self->taskId = -1;
        for (j = 0; j < 2; j++) {
            Layer021eb578* layer = &self->subLayers[j];
            Background_FillRect(layer, 0, 0, 0, 0x20, 0x19, 0);
            Background_UploadMap((struct BackgroundGraphics*)layer, 0);
        }
        self->buffer = (char*)allocs[1].Allocate(0x2a00);
        panelLayers[0] = 0;
        panelLayers[1] = 0;
        panelLayers[2] = 1;
        for (k = 0; k < 3; k++) {
            Panel021eb578* panel = &self->panels[k];
            WindowPane_AllocateBuffer((struct WindowPane*)panel, &allocs[1], (int)self->buffer, 0x400);
            panel->layer = &self->subLayers[panelLayers[k]];
        }
        self->firstLayer = &self->subLayers[0];
        self->f176 = 2;
        Window_SetPanes((struct Struct_0205cf78*)self->linker, (struct WindowPane*)self->panels, 3);
        self->taskId = loader->QueueLoadFile((const char*)KeyTable_Get((struct Container020e0310*)self->container, 3), NULL);
        self->state++;
    }

    if (var4 == 4) {
        void* var22;
        void* var23;
        unsigned int var24;
        int var25;
        void* var26;
        unsigned char var27[2];
        signed char var28[2];
        unsigned char var29[2];
        int var30;
        int var31;
        int var32;
        int var33;
        if (var3->GetTaskStatus(arg0->unknown_434_) == 0) {
            return;
        }
        var0 = arg0->unknown_0_;
        var0->Reset();
        var30 = 0;
        if (IS_SUB_SCREEN_MODE(arg0)) {
            var30 = 1;
        } else if (IS_MAIN_SCREEN_MODE(arg0)) {
            var30 = 0;
        }
        *(Bytes2*)priorities = *(Bytes2*)&data_ov023_021fd844[8];
        *(Bytes2*)kinds = *(Bytes2*)&data_ov023_021fd844[6];
        *(Bytes2*)counts = *(Bytes2*)&data_ov023_021fd844[0];
        for (j = 0; j < 2; j++) {
            Layer021eb578* layer = &self->layers[j];
            Background_Init((struct BackgroundGraphics*)layer);
            layer->screen = screen;
            layer->priority = priorities[j];
            Background_SetPriority(layer, kinds[j]);
            Background_SetScroll((struct BackgroundGraphics*)layer, 0, 0);
            Background_AllocateMap((struct BackgroundGraphics*)layer, allocs);
            Background_AllocateScreens((struct BackgroundGraphics*)layer, counts[j], allocs);
        }
        loader->GetLoadedFileByID(self->taskId, &data, &length);
        count = Pac_CountFiles((struct PacRecord*)data);
        for (i = 0; i < count; i++) {
            rec = Pac_GetFile((struct PacRecord*)data, i, &out, &field);
            if (rec != NULL) {
                if (i < 3) {
                    Background_LoadFile(&self->layers[0], rec, allocs, field);
                } else {
                    Background_LoadFile(&self->layers[1], rec, allocs, field);
                }
            }
        }
        loader->RemoveTask(self->taskId);
        self->taskId = -1;
        Background_DrawScreen((struct BackgroundGraphics*)&self->layers[0], 0, 0, 0, 0, 0, 0x20, 0x18, 0xffff);
        Background_UploadMap((struct BackgroundGraphics*)&self->layers[0], 0);
        Background_FillRect(&self->layers[1], 0, 0, 0, 0x20, 0x19, 0);
        Background_UploadMap((struct BackgroundGraphics*)&self->layers[1], 0);
        if (self->mode == 0 || self->mode == 1) {
            SET_LAYER_PRIORITIES(1, 2, 3, 0, 0x1b, 3, 2, 1, 0, 0x1e);
        } else if (arg0->unknown_430_ == 7) {
            if (!(arg0->unknown_438_ & 8)) {
                SET_LAYER_PRIORITIES(1, 2, 3, 0, 0x1b, 3, 2, 1, 0, 0x1e);
            } else {
                SET_LAYER_PRIORITIES(3, 2, 1, 0, 0x1e, 2, 3, 1, 0, 0x1f);
            }
        } else if (arg0->unknown_430_ == 2) {
            SET_LAYER_PRIORITIES(3, 2, 1, 0, 0x1e, 2, 3, 1, 0, 0x1f);
        } else if (arg0->unknown_430_ == 6) {
            SET_LAYER_PRIORITIES(3, 1, 2, 0, 0x19, 3, 2, 1, 0, 0x1e);
        }
        self->taskId = loader->QueueLoadFile((const char*)KeyTable_Get((struct Container020e0310*)self->container, 4), NULL);
        self->state++;
    }

    if (var4 == 5) {
        void* var35;
        void* var36;
        unsigned int var37;
        int var38;
        void* var39;
        int var40;
        Struct_ov023_021eb578_3* var41;
        int var42;
        int var43;
        int var44;
        if (var3->GetTaskStatus(arg0->unknown_434_) == 0) {
            return;
        }
        screen = self->layers[0].screen;
        allocs = self->allocs;
        SpriteContext_Init((char*)self->obj424);
        self->obj424->f50 = screen;
        obj = self->obj424;
        obj->f40 = self->obj428;
        obj->f4c = 4;
        self->obj424->f3c = self->obj42c;
        for (j = 0; j < 4; j++) {
            Sprite_Init((struct Struct0205a198*)(self->obj428 + j * 0x28));
        }
        ClearField0And40205a234((struct ClearTarget0205a234*)self->obj42c);
        loader->GetLoadedFileByID(self->taskId, &data, &length);
        count = Pac_CountFiles((struct PacRecord*)data);
        allocs[3].Reset();
        for (i = 0; i < count; i++) {
            rec = Pac_GetFile((struct PacRecord*)data, i, &out, &field);
            if (rec != NULL) {
                SpriteContext_LoadFile(self->obj424, rec, field, &allocs[3]);
            }
        }
        var3->RemoveTask(arg0->unknown_434_);
        arg0->unknown_434_ = -1;
        arg0->unknown_432_++;
    }

    if (var4 == 6) {
        if (arg0->unknown_44_[0].unknown_1c_0_ == 0) {
            SetMainBrightness(var2, 0, 15);
        } else {
            SetSubBrightness(var2, 0, 15);
        }
        if (arg0->unknown_20_ == 0 || arg0->unknown_24_ == 0) {
            arg0->unknown_431_ = 2;
            arg0->unknown_432_ = 0;
        } else {
            arg0->unknown_431_ = 1;
            arg0->unknown_432_ = 0;
        }
    }
}
