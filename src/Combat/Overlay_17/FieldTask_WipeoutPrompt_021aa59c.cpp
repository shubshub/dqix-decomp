#include "Combat/MenuNodeChain.h"
#include "Combat/MapDisplay.h"
#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "Resource/Brightness.h"
#include "NitroSDK/Graphics.h"
#include "NitroSDK/ColorEffects.h"
#include "Input/Input.h"
#include "Resource/GameResources.h"

#if defined(jpn)
#define func_02046c78 func_02047a98
#endif

struct AllocatorUnion;
struct Obj02086b98;
struct CountHead;
struct Actor0209c678;
struct Actor0209c20c;
struct Struct_02081ee4;
struct Struct_02081ee4_2;
struct BackgroundGraphics;
struct WindowPane;
struct PacRecord;
struct Struct_0207f914;
struct Manager0207f7f0;
struct Node0207f7f0;
struct Struct_0207fcb8;
struct Struct_0207fd44_2;
struct Struct_0207fd88;
struct Struct_02081f20_2;
struct Struct_ov017_021aa59c_4;
struct Struct_0207fdcc_2;
struct Struct_0207fc6c;
struct Struct_ov017_021aa59c_5;
struct Struct_ov017_021aa59c_6;
struct SePlayer;
struct Struct_0207fe44;
struct FlagWord020466f4;
struct ListHead02046b60;

extern "C" void* LinkSession_GetInstance(void);
extern "C" void* Zone3D_GetInstance(void);
extern "C" void* GlobalFlags_GetInstance(void);
extern "C" int MessageSystem_GetInstance(void);
extern "C" int func_ov017_021959b4(void);
extern "C" void func_ov017_021aaf08(void* p);
extern "C" void* GameState_GetParty(GameState* gs);
extern "C" int func_02086b98(struct Obj02086b98* o);
extern "C" void func_ov017_021ab010(void* p, int flag);
extern "C" int func_02046c78(struct CountHead* head);
extern "C" void BgmPlayer_FadeOut(struct Actor0209c678* actor, int arg);
extern "C" void func_020a0cc4(unsigned int size);
extern "C" void* AllocatorUnion_AllocateRounded(AllocatorUnion* alloc, unsigned int size);
extern "C" void ROMFilesystem_InitFileTables(void);
extern "C" void func_02081ee4(struct Struct_02081ee4* obj, struct Struct_02081ee4_2* sub);
extern "C" void Background_Init(struct BackgroundGraphics* obj);
extern "C" void Background_SetMapSize(unsigned char* obj, int value);
extern "C" void Background_SetPriority(void* obj, int value);
extern "C" void Background_AllocateMap(struct BackgroundGraphics* obj, SafeAllocator* alloc);
extern "C" int Background_SetScroll(struct BackgroundGraphics* obj, int a, int b);
extern "C" void WindowPane_Init(void* obj);
extern "C" void WindowPane_AllocateBuffer(struct WindowPane* obj, SafeAllocator* alloc, int buffer, unsigned int len);
extern "C" int Pac_CountFiles(struct PacRecord* entry);
extern "C" void* Pac_GetFile(struct PacRecord* rec, int index, void** out, int* outSize);
extern "C" void Background_LoadFile(void* graphics, void* file, SafeAllocator* allocator, unsigned int size);
#if defined(jpn)
extern "C" void func_02080654(struct Struct_0207f914* obj, int alloc, int filename);
#else
extern "C" void func_0207f914(struct Struct_0207f914* obj, int alloc, int a, int b);
#endif
extern "C" int func_0207f9f4(void* obj);
extern "C" void func_0207f7f0(struct Manager0207f7f0* mgr, struct Node0207f7f0* node, int count);
extern "C" void func_0207fcb8(struct Struct_0207fcb8* obj);
extern "C" void func_0207fd44(struct Struct_0207fd44_2* obj);
extern "C" void func_0207fd88(struct Struct_0207fd88* obj);
extern "C" void func_0208203c(struct Struct_02081f20_2* obj);
extern "C" void func_020813ec(void* obj, int key);
extern "C" void func_ov017_021ab060(struct Struct_ov017_021aa59c_4* obj);
extern "C" void* func_02081da8(struct Struct_0207fdcc_2* obj, int key);
extern "C" void func_0207fc6c(struct Struct_0207fc6c* obj, int arg);
extern "C" void func_02081f20(void* repeat, int ticks);
extern "C" int func_020800fc(void* menu, short* cursor, short arg2, unsigned short arg3, unsigned char columns, bool wrap);
extern "C" void func_020804fc(void* obj, int key);
extern "C" int func_ov017_021ab0c0(struct Struct_ov017_021aa59c_5* ctx);
extern "C" void SePlayer_Play(struct SePlayer* obj, int a, int b);
extern "C" void func_0207fe44(struct Struct_0207fe44* obj);
extern "C" void FlagWord_SetBits(unsigned int* p, unsigned int mask);
extern "C" int func_ov017_021ab1a4(struct Struct_ov017_021aa59c_6* ctx);
extern "C" void FlagWord_ClearBits(struct FlagWord020466f4* word, unsigned int mask);
extern "C" unsigned char func_02010750(char* gs);
extern "C" void func_ov017_021d1a18(int a, int b, int c, int d);
extern "C" int func_02046b60(struct ListHead02046b60* list, int id);
extern "C" void func_02046a8c(struct ListHead02046b60* list, void* node);
extern "C" void func_02010604(GameState* gs, int a, int b, int c);
extern "C" void func_0201075c(char* gs, unsigned char value);
extern "C" void func_0209c20c(struct Actor0209c20c* actor);

extern AllocatorUnion g_mainAllocator;
extern struct SePlayer g_sePlayer;
#if defined(jpn)
extern char data_ov017_021d7ddc[];
extern char data_ov017_021d7def[];
#else
extern char data_ov017_021d7870[];
extern char data_ov017_021d7883[];
extern char data_ov017_021d789c[];
#endif

struct ActorData02109bf4 {
    char unknown[0xd0];
};
extern ActorData02109bf4 g_bgmPlayer;

struct Struct_ov017_021aa59c {
    unsigned short unknown_0_;
    unsigned char columns;
};

struct Scene021aa59c {
    unsigned short id;
#if defined(jpn)
    char unknown_2_[0x27c2];
#else
    char unknown1_2_[0x2782];
#endif
    short y;
    short x;
    unsigned char layer;
};

struct Self021aa59c {
    unsigned char type;
    unsigned char done;
    char unknown_2_[6];
    void* tileBuffer;
    int unknown_c_;
    char unknown_10[4];
    int state;
    Manager0207f7f0* menu;
    BackgroundGraphics* layers;
    Node0207f7f0* panels;
    SafeAllocator alloc;
    int result;
    void* repeat;
    Struct_ov017_021aa59c* input;
    short* unknown_44_;
    short key;
    short unknown_4a_;
    short cursor;
    short unknown_4e_;
    int loadTask;
    char unknown_54_[0x10];
    int unknown_64_;
};

// Overlay 17, originally func_ov017_021aa59c (USA/EUR 0x021aa59c, JPN 0x021aae04)
extern "C" ARM void FieldTask_WipeoutPrompt(Self021aa59c* self, ListHead02046b60* list) {
    GameResources* res;
    Scene021aa59c* scene;
    GameState* gs = GameState::GetInstance();
    LinkSession_GetInstance();
    res = GetGameResources();
    MessageSystem_GetInstance();
    CountHead* nodes = (CountHead*)res->fieldTaskQueue_;
    scene = (Scene021aa59c*)Zone3D_GetInstance();
    unsigned int* flags = (unsigned int*)GlobalFlags_GetInstance();

    if (self->state < 6 && (func_ov017_021959b4() != 0 || res->unknown_42e2_ != 0)) {
        func_ov017_021aaf08(self);
        self->done = 1;
        return;
    }
    if (!func_02086b98((Obj02086b98*)GameState_GetParty(gs))) {
        func_ov017_021ab010(self, 1);
        return;
    }
    if (func_02046c78(nodes) > 1) {
        func_ov017_021aaf08(self);
        self->done = 1;
        return;
    }

    BgmPlayer_FadeOut((Actor0209c678*)&g_bgmPlayer, 0);
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    int state = self->state;
    if (state == 0) {
        func_020a0cc4(0x7800);
        void* buffer = AllocatorUnion_AllocateRounded(&g_mainAllocator, 0x7800);
        if (buffer == NULL) {
            ROMFilesystem_InitFileTables();
            func_ov017_021aaf08(self);
            self->done = 1;
            return;
        }
        self->alloc.CreateTypeA(buffer, 0x7800);
        self->alloc.Reset();
        self->tileBuffer = self->alloc.Allocate(0x1400);
        self->panels = (Node0207f7f0*)self->alloc.Allocate(0x1c0);
        self->layers = (BackgroundGraphics*)self->alloc.Allocate(0x40);
#if defined(jpn)
        self->menu = (Manager0207f7f0*)self->alloc.Allocate(0x34);
#else
        self->menu = (Manager0207f7f0*)self->alloc.Allocate(0x40);
#endif
        self->repeat = self->alloc.Allocate(0xc);
        self->input = (Struct_ov017_021aa59c*)self->alloc.Allocate(4);
        func_02081ee4((Struct_02081ee4*)self->repeat, (Struct_02081ee4_2*)self->input);

        BackgroundGraphics* layer = self->layers;
        for (int i = 0; i < 2; i++) {
            Background_Init((BackgroundGraphics*)layer);
            Background_SetMapSize((unsigned char*)layer, 0);
            layer->subScreen_ = 0;
            layer->bgNumber_ = i + 1;
            Background_SetPriority(layer, i);
            Background_AllocateMap((BackgroundGraphics*)layer, &self->alloc);
            Background_SetScroll((BackgroundGraphics*)layer, 0, 0);
            layer++;
        }

        Node0207f7f0* panel = self->panels;
        for (unsigned char j = 0; j < 2; j++) {
            WindowPane_Init(panel);
            WindowPane_AllocateBuffer((WindowPane*)panel, &self->alloc, (int)self->tileBuffer, 0x800);
            panel->lists = self->layers;
            panel++;
        }

        BG1CNT = (BG1CNT & 0x43) | 0x1e00;
        BG2CNT = (BG2CNT & 0x43) | 0x1f00;
        ColorEffect_ConfigureAlphaBlend(0x04000050, 4, 1, 10, 6);
#if defined(jpn)
        self->loadTask = loader->QueueLoadFile(data_ov017_021d7ddc, NULL);
#else
        self->loadTask = loader->QueueLoadFile(data_ov017_021d7870, NULL);
#endif
        self->state = 1;
    } else if (state == 1) {
        if (loader->GetTaskStatus(self->loadTask) != 0) {
            void* record;
            void* file;
            unsigned int fileSize;
            loader->GetLoadedFileByID(self->loadTask, &file, &fileSize);
            int count = Pac_CountFiles((PacRecord*)file);
            BackgroundGraphics* layers = self->layers;
            for (int i = 0; i < count; i++) {
                int recordSize;
                void* data = Pac_GetFile((PacRecord*)file, i, &record, &recordSize);
                Background_LoadFile(layers, data, NULL, recordSize);
            }
            loader->RemoveTask(self->loadTask);
            self->loadTask = -1;
            func_0207f84c(self->menu);
#if defined(jpn)
            func_02080654((Struct_0207f914*)self->menu, (int)&self->alloc, (int)data_ov017_021d7def);
#else
            func_0207f914((Struct_0207f914*)self->menu, (int)&self->alloc, (int)data_ov017_021d7883, (int)data_ov017_021d789c);
#endif
            self->state = 2;
        }
    } else if (state == 2) {
        int status = func_0207f9f4(self->menu);
        if (status == 0) {
            self->state = 3;
        }
        if (status < 0) {
            self->state = 8;
        }
    } else if (state == 3) {
        Manager0207f7f0* menu = self->menu;
        menu->lists = self->layers;
        menu->mode = 2;
        func_0207f7f0(menu, self->panels, 2);
        menu->active = 1;
        func_0207fcb8((Struct_0207fcb8*)menu);
        func_0207fd44((Struct_0207fd44_2*)menu);
        func_0207fd88((Struct_0207fd88*)menu);
        BG0CNT = (BG0CNT & ~3) | 2;
        BG1CNT = BG1CNT & ~3;
        BG2CNT = (BG2CNT & ~3) | 1;
        BG3CNT = (BG3CNT & ~3) | 3;
        DISPCNT = (DISPCNT & ~0x1f00) | 0x1700;
        self->state = 4;
    } else if (state == 4) {
        self->key = 0;
        self->cursor = 0;
        self->unknown_4e_ = 0;
        func_0208203c((Struct_02081f20_2*)self->repeat);
        self->unknown_44_ = NULL;
        func_020813ec(self->menu, self->key);
        func_ov017_021ab060((Struct_ov017_021aa59c_4*)self);
        self->state = 5;
    } else if (state == 5) {
        bool cancelled = false;
        bool var23 = false;
        void* element;
        Manager0207f7f0* menu = self->menu;
        element = func_02081da8((Struct_0207fdcc_2*)menu, self->key);
        if (menu != NULL) {
            if (element != NULL) {
                int ticks = gs->GetTickCount();
                func_0207fc6c((Struct_0207fc6c*)menu, ticks);
                self->unknown_44_ = &self->cursor;
                if (self->unknown_44_ != NULL) {
                    func_02081f20(self->repeat, ticks);
                    self->unknown_4e_ = *self->unknown_44_;
                    self->result = func_020800fc(menu, self->unknown_44_, self->unknown_4e_, self->input->unknown_0_, self->input->columns, false);
                    menu->unknown_36_ = *self->unknown_44_;
                    if (self->result != 0) {
                        func_020804fc(menu, self->key);
                    }
                    if (self->unknown_4e_ != *self->unknown_44_ || g_touchInput.pressed_ != 0) {
                        func_020813ec(menu, self->key);
                        func_ov017_021ab060((Struct_ov017_021aa59c_4*)self);
                    }
                }
                if (func_ov017_021ab0c0((Struct_ov017_021aa59c_5*)self) != 0) {
                    if (self->unknown_4e_ != *self->unknown_44_) {
                        return;
                    }
                    SePlayer_Play(&g_sePlayer, 1, 0);
                    func_0208203c((Struct_02081f20_2*)self->repeat);
                    self->unknown_44_ = NULL;
                    if (self->cursor == 0) {
                        func_0207fe44((Struct_0207fe44*)self->menu);
                        FlagWord_SetBits(flags, 0x200);
                    } else if (self->cursor == 1) {
                        cancelled = true;
                    }
                } else if (func_ov017_021ab1a4((Struct_ov017_021aa59c_6*)self) != 0) {
                    var23 = true;
                }
            } else if (g_keyManager.TestKeysPressed(0x401) != 0 || g_touchInput.pressed_ != 0) {
                func_020813ec(menu, self->key);
                func_ov017_021ab060((Struct_ov017_021aa59c_4*)self);
                FlagWord_ClearBits((FlagWord020466f4*)flags, 0x200);
            }
        }
        if (func_02010750((char*)gs) != 0 || cancelled) {
            self->state = 6;
            var23 = true;
            self->unknown_64_ = true;
        }
        if (var23 && menu != NULL && element != NULL) {
            func_0207fe44((Struct_0207fe44*)self->menu);
            FlagWord_SetBits(flags, 0x200);
        }
    } else if (state == 6) {
        if (scene->id == 10000) {
            func_ov017_021d1a18(scene->x, scene->y, scene->layer, 1);
        }
        FlagWord_SetBits((unsigned int*)GlobalFlags_GetInstance(), 0x200000);
        SetBrightness(res, -16, 120);
        self->state = 7;
    } else if (state == 7) {
        if (IsBrightnessTransitionActive(res) != 0) {
            self->state = 8;
        }
    } else if (state == 8) {
        if (IsBrightnessTransitionActive(res) == 0) {
            if (func_02046b60(list, 0x40) != 0) {
                func_02046a8c(list, res->fieldTasks_[39]);
            }
            func_02010604(gs, 0, func_02010750((char*)gs), 0);
            func_0201075c((char*)gs, 0);
            DISPCNT = (DISPCNT & ~0x1f00) | (self->unknown_c_ << 8);
            ROMFilesystem_InitFileTables();
            func_0209c20c((Actor0209c20c*)&g_bgmPlayer);
            func_ov017_021aaf08(self);
            self->done = 1;
        }
    }
}
