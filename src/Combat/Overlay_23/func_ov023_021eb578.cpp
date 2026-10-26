#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "GameState/GameState.h"

struct GameResources;
struct Container020e0310;
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
extern "C" void* GlobalFlags_GetInstance(void);
extern "C" void FlagWord_SetBits(unsigned int* p, unsigned int mask);
extern "C" void func_020dc2bc(void);
extern "C" void KeyTable_Load(void* dest, void* allocator, void* fileData, unsigned int size);
extern "C" int MessageSystem_GetInstance(void);
extern "C" void func_ov023_021ec368(int screenSize, int colorMode, int screenBase, int charBase, int bit13);
extern "C" void func_ov023_021ec39c(int screenSize, int colorMode, int screenBase, int charBase);
extern "C" void func_ov023_021ec3c8(int screenSize, int colorMode, int screenBase, int charBase);
extern "C" void func_ov023_021ec3f4(int screenSize, int colorMode, int screenBase, int charBase);
extern "C" void func_ov023_021ec420(int screenSize, int colorMode, int screenBase, int charBase, int bit13);
extern "C" void func_ov023_021ec454(int screenSize, int colorMode, int screenBase, int charBase);
extern "C" void Background_SetMapSize(unsigned char* obj, int value);
extern "C" void Background_SetPriority(void*, int);
extern "C" int Background_SetScroll(struct BackgroundGraphics* obj, int a, int b);
extern "C" void Background_AllocateMap(struct BackgroundGraphics* obj, SafeAllocator* alloc);
extern "C" int Pac_CountFiles(struct PacRecord* entry);
extern "C" void* Pac_GetFile(struct PacRecord* rec, int index, void** out, int* out44);
extern "C" void Background_LoadFile(void* list, void* payload, SafeAllocator* alloc, int field44);
extern "C" void Background_FillRect(void* target, int type, int a, int b, int c, int d, int flags);
extern "C" void Background_UploadMap(struct BackgroundGraphics* obj, void* buf);
extern "C" void WindowPane_AllocateBuffer(struct WindowPane* obj, SafeAllocator* alloc, int val, unsigned int len);
extern "C" void Window_SetPanes(struct Struct_0205cf78* s, struct WindowPane* arr, unsigned char count);
extern "C" int KeyTable_Get(struct Container020e0310* c, int key);
extern "C" void Background_Init(struct BackgroundGraphics* obj);
extern "C" void Background_AllocateScreens(struct BackgroundGraphics* obj, int count, SafeAllocator* alloc);
extern "C" void Background_DrawScreen(struct BackgroundGraphics*, unsigned int, int, int, short, short, short, short, unsigned short);
extern "C" void SpriteContext_Init(char* obj);
extern "C" void Sprite_Init(struct Struct0205a198* p);
extern "C" void func_0205a234(struct ClearTarget0205a234* target);
extern "C" void SpriteContext_LoadFile(void* a, void* ptr, int val, void* d);

extern char data_ov023_021fe108[];
#if defined(jpn)
extern char data_ov023_021fd39c[];
#endif
extern char data_ov023_021fe121[];
extern char data_ov023_021fe131[];
extern unsigned char data_ov023_021fd844[];

struct Struct_ov008_021895a8 {
    unsigned char v[2];
};

struct Struct_ov023_021eb578 {
    char pad0[0x1c];
    unsigned char screen : 4;
    unsigned char priority : 4;
    char unknown_1d_[3];
};

struct Struct_ov023_021eb578_2 {
    char pad0[4];
    Struct_ov023_021eb578* layer;
    char pad8[0xd8];
};

struct Struct_ov023_021eb578_3 {
    char pad0[0x3c];
    char* f3c;
    char* f40;
    char unknown_44_[8];
    short unknown_4c_;
    char unknown_4e_[2];
    unsigned char unknown_50_;
};

struct Struct_ov023_021eb578_4 {
    SafeAllocator* allocs;
    char container[0x18];
    int f1c;
    int f20;
    int f24;
    char pad28[0x1c];
    Struct_ov023_021eb578 layers[2];
    Struct_ov023_021eb578 subLayers[2];
    char linker[0x98];
    Struct_ov023_021eb578* unknown_15c_;
    char unknown_160_[0x16];
    unsigned char unknown_176_;
    char unknown_177_[9];
    Struct_ov023_021eb578_2 panels[3];
    char* buffer;
    Struct_ov023_021eb578_3* obj424;
    char* obj428;
    char* unknown_42c_;
    unsigned char mode;
    unsigned char result;
    unsigned char state;
    char unknown_433_;
    int taskId;
    unsigned short flags;
};

#define IS_SUB_SCREEN_MODE(self)     ((self)->mode == 0 || (self)->mode == 1 || (self)->mode == 6 || ((self)->mode == 7 && !((self)->flags & 8)))
#define IS_MAIN_SCREEN_MODE(self) ((self)->mode == 2 || ((self)->mode == 7 && ((self)->flags & 8)))

#define REG16(a) (*(volatile unsigned short*)(a))
#define REG32(a) (*(volatile unsigned int*)(a))

#define SET_LAYER_PRIORITIES(m0, m1, m2, m3, mPlanes, s0, s1, s2, s3, sPlanes)     do {         REG16(0x4000008) = (REG16(0x4000008) & ~3) | (m0);         REG16(0x400000a) = (REG16(0x400000a) & ~3) | (m1);         REG16(0x400000c) = (REG16(0x400000c) & ~3) | (m2);         REG16(0x400000e) = (REG16(0x400000e) & ~3) | (m3);         REG32(0x4000000) = (REG32(0x4000000) & ~0x1f00) | ((mPlanes) << 8);         REG16(0x4001008) = (REG16(0x4001008) & ~3) | (s0);         REG16(0x400100a) = (REG16(0x400100a) & ~3) | (s1);         REG16(0x400100c) = (REG16(0x400100c) & ~3) | (s2);         REG16(0x400100e) = (REG16(0x400100e) & ~3) | (s3);         REG32(0x4001000) = (REG32(0x4001000) & ~0x1f00) | ((sPlanes) << 8);     } while (0)

// USA: func_ov023_021eb578
extern "C" ARM void func_ov023_021eb578(Struct_ov023_021eb578_4* self) {
    SafeAllocator* allocs;
    FontBankLoader* g;
    GameResources* res;
    BackgroundLoader* loader;
    unsigned char state;
    res = GameState::GetInstance()->GetResources();
    g = FontBankLoader_GetInstance();
    loader = BackgroundLoader::GetInstance();
    state = self->state;

    if (state == 0) {
        if (IS_SUB_SCREEN_MODE(self)) {
            SetSubBrightness(res, -16, 15);
        } else if (IS_MAIN_SCREEN_MODE(self)) {
            SetMainBrightness(res, -16, 15);
        }
        func_02094b40(g);
        func_02094b34(g, 0x71, 0x201, 0, 0);
        self->state++;
    }

    if (state == 1) {
        if (IsBrightnessTransitionActive(res)) {
            return;
        }
        if (func_02094b4c(g) == 0) {
            return;
        }
        if (self->flags & 0x10) {
            FlagWord_SetBits((unsigned int*)GlobalFlags_GetInstance(), 1);
            func_020dc2bc();
        }
#if defined(jpn)
        self->taskId = loader->QueueLoadFile(data_ov023_021fd39c, NULL);
#else
        self->taskId = loader->QueueLoadFileInGP2(data_ov023_021fe108, data_ov023_021fe121, NULL);
#endif
        self->state++;
    }

    if (state == 2) {
        void* data;
        unsigned int length;
        unsigned char screens[2];
        int i;
        if (loader->GetTaskStatus(self->taskId) == 0) {
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
        if (self->mode == 0 || self->mode == 1) {
            func_ov023_021ec368(0, 0, 0x1a, 4, 0);
            func_ov023_021ec39c(0, 0, 0x1b, 4);
            func_ov023_021ec3c8(0, 0, 0x1c, 6);
            func_ov023_021ec3f4(0, 0, 0x1d, 2);
            screens[0] = 1;
            screens[1] = 0;
        } else if (self->mode == 7) {
            if (!(self->flags & 8)) {
                func_ov023_021ec368(0, 0, 0xe, 0, 0);
                func_ov023_021ec39c(0, 0, 0xf, 0);
                func_ov023_021ec3c8(0, 0, 7, 1);
                func_ov023_021ec3f4(0, 0, 0x1e, 2);
                screens[0] = 1;
                screens[1] = 0;
            } else {
                func_ov023_021ec420(0, 0, 0, 1, 0);
                func_ov023_021ec454(0, 0, 0x1f, 1);
                func_ov023_021ec3f4(0, 0, 0x17, 3);
                func_ov023_021ec3c8(0, 0, 0x17, 2);
                screens[0] = 0;
                screens[1] = 1;
            }
        } else if (self->mode == 2) {
            func_ov023_021ec420(0, 0, 0, 1, 0);
            func_ov023_021ec454(0, 0, 0x1f, 1);
            func_ov023_021ec3f4(0, 0, 0x17, 3);
            func_ov023_021ec3c8(0, 0, 0x17, 2);
            screens[0] = 0;
            screens[1] = 1;
        } else if (self->mode == 6) {
            func_ov023_021ec368(0, 0, 0xe, 0, 0);
            func_ov023_021ec39c(0, 0, 0xf, 0);
            func_ov023_021ec3c8(0, 0, 7, 1);
            func_ov023_021ec3f4(0, 0, 0x1d, 2);
            screens[0] = 1;
            screens[1] = 0;
        }
        for (i = 0; i < 2; i++) {
            Struct_ov023_021eb578* layer = &self->subLayers[i];
            Background_SetMapSize((unsigned char*)layer, 0);
            layer->screen = screens[i];
            layer->priority = 3;
            Background_SetPriority(layer, 0);
            Background_SetScroll((struct BackgroundGraphics*)layer, 0, 0);
            Background_AllocateMap((struct BackgroundGraphics*)layer, &self->allocs[1]);
        }
        self->taskId = loader->QueueLoadFile(data_ov023_021fe131, NULL);
        self->state++;
    }

    if (state == 3) {
        void* out;
        void* data;
        unsigned int length;
        int field;
        void* rec;
        unsigned char var15[3];
        int count;
        int i;
        int j;
        int k;
        if (loader->GetTaskStatus(self->taskId) == 0) {
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
            Struct_ov023_021eb578* layer = &self->subLayers[j];
            Background_FillRect(layer, 0, 0, 0, 0x20, 0x19, 0);
            Background_UploadMap((struct BackgroundGraphics*)layer, 0);
        }
        self->buffer = (char*)allocs[1].Allocate(0x2a00);
        var15[0] = 0;
        var15[1] = 0;
        var15[2] = 1;
        for (k = 0; k < 3; k++) {
            Struct_ov023_021eb578_2* panel = &self->panels[k];
            WindowPane_AllocateBuffer((struct WindowPane*)panel, &allocs[1], (int)self->buffer, 0x400);
            panel->layer = &self->subLayers[var15[k]];
        }
        self->unknown_15c_ = &self->subLayers[0];
        self->unknown_176_ = 2;
        Window_SetPanes((struct Struct_0205cf78*)self->linker, (struct WindowPane*)self->panels, 3);
        self->taskId = loader->QueueLoadFile((const char*)KeyTable_Get((struct Container020e0310*)self->container, 3), NULL);
        self->state++;
    }

    if (state == 4) {
        void* out;
        void* data;
        unsigned int length;
        int field;
        void* rec;
        unsigned char priorities[2];
        signed char kinds[2];
        unsigned char counts[2];
        int screen;
        int count;
        int i;
        int j;
        if (loader->GetTaskStatus(self->taskId) == 0) {
            return;
        }
        allocs = self->allocs;
        allocs->Reset();
        screen = 0;
        if (IS_SUB_SCREEN_MODE(self)) {
            screen = 1;
        } else if (IS_MAIN_SCREEN_MODE(self)) {
            screen = 0;
        }
        *(Struct_ov008_021895a8*)priorities = *(Struct_ov008_021895a8*)&data_ov023_021fd844[8];
        *(Struct_ov008_021895a8*)kinds = *(Struct_ov008_021895a8*)&data_ov023_021fd844[6];
        *(Struct_ov008_021895a8*)counts = *(Struct_ov008_021895a8*)&data_ov023_021fd844[0];
        for (j = 0; j < 2; j++) {
            Struct_ov023_021eb578* layer = &self->layers[j];
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
        } else if (self->mode == 7) {
            if (!(self->flags & 8)) {
                SET_LAYER_PRIORITIES(1, 2, 3, 0, 0x1b, 3, 2, 1, 0, 0x1e);
            } else {
                SET_LAYER_PRIORITIES(3, 2, 1, 0, 0x1e, 2, 3, 1, 0, 0x1f);
            }
        } else if (self->mode == 2) {
            SET_LAYER_PRIORITIES(3, 2, 1, 0, 0x1e, 2, 3, 1, 0, 0x1f);
        } else if (self->mode == 6) {
            SET_LAYER_PRIORITIES(3, 1, 2, 0, 0x19, 3, 2, 1, 0, 0x1e);
        }
        self->taskId = loader->QueueLoadFile((const char*)KeyTable_Get((struct Container020e0310*)self->container, 4), NULL);
        self->state++;
    }

    if (state == 5) {
        void* out;
        void* data;
        unsigned int length;
        int field;
        void* rec;
        int screen;
        Struct_ov023_021eb578_3* obj;
        int count;
        int i;
        int j;
        if (loader->GetTaskStatus(self->taskId) == 0) {
            return;
        }
        screen = self->layers[0].screen;
        allocs = self->allocs;
        SpriteContext_Init((char*)self->obj424);
        self->obj424->unknown_50_ = screen;
        obj = self->obj424;
        obj->f40 = self->obj428;
        obj->unknown_4c_ = 4;
        self->obj424->f3c = self->unknown_42c_;
        for (j = 0; j < 4; j++) {
            Sprite_Init((struct Struct0205a198*)(self->obj428 + j * 0x28));
        }
        func_0205a234((struct ClearTarget0205a234*)self->unknown_42c_);
        loader->GetLoadedFileByID(self->taskId, &data, &length);
        count = Pac_CountFiles((struct PacRecord*)data);
        allocs[3].Reset();
        for (i = 0; i < count; i++) {
            rec = Pac_GetFile((struct PacRecord*)data, i, &out, &field);
            if (rec != NULL) {
                SpriteContext_LoadFile(self->obj424, rec, field, &allocs[3]);
            }
        }
        loader->RemoveTask(self->taskId);
        self->taskId = -1;
        self->state++;
    }

    if (state == 6) {
        if (self->layers[0].screen == 0) {
            SetMainBrightness(res, 0, 15);
        } else {
            SetSubBrightness(res, 0, 15);
        }
        if (self->f20 == 0 || self->f24 == 0) {
            self->result = 2;
            self->state = 0;
        } else {
            self->result = 1;
            self->state = 0;
        }
    }
}
