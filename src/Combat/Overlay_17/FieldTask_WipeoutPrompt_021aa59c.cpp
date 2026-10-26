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
struct Obj02081ee4;
struct Sub02081ee4;
struct BackgroundGraphics;
struct WindowPane;
struct PacRecord;
struct Obj0207f914;
struct Manager0207f7f0;
struct Node0207f7f0;
struct Obj0207fcb8;
struct Cont0207fd44;
struct Cont0207fd88;
struct Obj0208203c;
struct Obj021ab060;
struct Obj2081;
struct Obj0207fc6c;
struct Ctx021ab0c0;
struct Ctx021ab1a4;
struct SePlayer;
struct Cont0207fe44;
struct FlagWord020466f4;
struct ListHead02046b60;

extern "C" void* LinkSession_GetInstance(void);
extern "C" void* Zone3D_GetInstance(void);
void* GlobalFlags_GetInstance(void);
int MessageSystem_GetInstance(void);
extern "C" int func_ov017_021959b4(void);
extern "C" void func_ov017_021aaf08(void* p);
void* GameState_GetParty(GameState* gs);
int AreListedCombatantsBit0Set(struct Obj02086b98* o);
void SetFlagAndMaybeNotify_021ab010(void* p, int flag);
int CountListNodes_02046c78(struct CountHead* head);
void BgmPlayer_FadeOut(struct Actor0209c678* actor, int arg);
extern "C" void func_020a0cc4(unsigned int size);
void* AllocatorUnion_AllocateRounded(AllocatorUnion* alloc, unsigned int size);
extern "C" void ROMFilesystem_InitFileTables(void);
void InitWithSub02081ee4(struct Obj02081ee4* obj, struct Sub02081ee4* sub);
void Background_Init(struct BackgroundGraphics* obj);
void Background_SetMapSize(unsigned char* obj, int value);
extern "C" void Background_SetPriority(void* obj, int value);
void Background_AllocateMap(struct BackgroundGraphics* obj, SafeAllocator* alloc);
int Background_SetScroll(struct BackgroundGraphics* obj, int a, int b);
extern "C" void WindowPane_Init(void* obj);
void WindowPane_AllocateBuffer(struct WindowPane* obj, SafeAllocator* alloc, int buffer, unsigned int len);
int Pac_CountFiles(struct PacRecord* entry);
void* Pac_GetFile(struct PacRecord* rec, int index, void** out, int* outSize);
extern "C" void Background_LoadFile(void* graphics, void* file, SafeAllocator* allocator, unsigned int size);
#if defined(jpn)
extern "C" void func_02080654(struct Struct_0207f914* arg0, int arg1, int arg2);
#else
extern "C" void func_0207f914(struct Struct_0207f914* arg0, int arg1, int arg2, int arg3);
#endif
extern "C" int func_0207f9f4(void* obj);
void InitNodeChain0207f7f0(struct Manager0207f7f0* mgr, struct Node0207f7f0* node, int count);
void ClearAllBuffers0207fcb8(struct Obj0207fcb8* obj);
void CallFunc0204b04cOverList0x2c(struct Cont0207fd44* obj);
void CallFunc0204b088OverList0x2c(struct Cont0207fd88* obj);
void ResetWithSub0208203c(struct Obj0208203c* obj);
extern "C" void func_020813ec(void* obj, int key);
void SetThreeEntryFlags_021ab060(struct Obj021ab060* obj);
void* FindElementByByte0xc4_02081da8(struct Obj2081* obj, int key);
void CallFunc0204c87cOverEntries0207fc6c(struct Obj0207fc6c* obj, int arg);
extern "C" void func_02081f20(void* repeat, int ticks);
extern "C" int func_020800fc(void* menu, short* cursor, short prevCursor, unsigned short buttons, unsigned char columns, bool wrap);
void ClearSublistEntriesFlag4_020804fc(void* obj, int key);
int UpdateElementCoordFlag_021ab0c0(struct Ctx021ab0c0* ctx);
void SePlayer_Play(struct SePlayer* obj, int a, int b);
void CallFunc0204c804OverAllElems(struct Cont0207fe44* obj);
void FlagWord_SetBits(unsigned int* p, unsigned int mask);
int CheckCoordsInsideElement_021ab1a4(struct Ctx021ab1a4* ctx);
void FlagWord_ClearBits(struct FlagWord020466f4* word, unsigned int mask);
unsigned char GetField0x5729Value_02010750(char* gs);
extern "C" void func_ov017_021d1a18(int a, int b, int c, int d);
int ListContainsId(struct ListHead02046b60* list, int id);
extern "C" void func_02046a8c(struct ListHead02046b60* list, void* node);
void ResetMpForFlaggedCombatants02010604(GameState* gs, int a, int b, int c);
void SetField0x5729Value_0201075c(char* gs, unsigned char value);
void InitActorContext0209c20c(struct Actor0209c20c* actor);

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

struct Struct_02109bf4_10 {
    char unknown_0_[0xd0];
};
extern ActorData02109bf4 g_bgmPlayer;

struct Struct_ov017_021aa59c {
    unsigned short unknown_0_;
    unsigned char unknown_2_;
};

struct Struct_ov017_021aa59c_2 {
    unsigned short unknown_0_;
#if defined(jpn)
    char unknown_2_[0x27c2];
#else
    char unknown1_2_[0x2782];
#endif
    short unknown_2784_;
    short unknown_2786_;
    unsigned char unknown_2788_;
};

struct Self021aa59c {
    unsigned char type;
    unsigned char done;
    char unknown_2[6];
    void* tileBuffer;
    int savedBgMode;
    char unknown_10[4];
    int state;
    Manager0207f7f0* menu;
    BackgroundGraphics* layers;
    Node0207f7f0* panels;
    SafeAllocator alloc;
    int result;
    void* repeat;
    Input021aa59c* input;
    short* cursorPtr;
    short key;
    short unknown_4a;
    short cursor;
    short prevCursor;
    int loadTask;
    char unknown_54[0x10];
    int finished;
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

    if (arg0->unknown_14_ < 6 && (func_ov017_021959b4() != 0 || var0->unknown_42e2_ != 0)) {
        func_ov017_021aaf08(arg0);
        arg0->unknown_1_ = 1;
        return;
    }
    if (!AreListedCombatantsBit0Set((Obj02086b98*)GameState_GetParty(gs))) {
        SetFlagAndMaybeNotify_021ab010(self, 1);
        return;
    }
    if (func_02046c78(var3) > 1) {
        func_ov017_021aaf08(arg0);
        arg0->unknown_1_ = 1;
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
        arg0->unknown_18_ = (Struct_0207f7f0*)arg0->unknown_24_.Allocate(0x34);
#else
        arg0->unknown_18_ = (Struct_0207f7f0*)arg0->unknown_24_.Allocate(0x40);
#endif
        arg0->unknown_3c_ = arg0->unknown_24_.Allocate(0xc);
        arg0->unknown_40_ = (Struct_ov017_021aa59c*)arg0->unknown_24_.Allocate(4);
        func_02081ee4((Struct_02081ee4*)arg0->unknown_3c_, (Struct_02081ee4_2*)arg0->unknown_40_);

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
        arg0->unknown_50_ = var5->QueueLoadFile(data_ov017_021d7ddc, NULL);
#else
        arg0->unknown_50_ = var5->QueueLoadFile(data_ov017_021d7870, NULL);
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
            var5->RemoveTask(arg0->unknown_50_);
            arg0->unknown_50_ = -1;
            func_0207f84c(arg0->unknown_18_);
#if defined(jpn)
            func_02080654((Struct_0207f914*)arg0->unknown_18_, (int)&arg0->unknown_24_, (int)data_ov017_021d7def);
#else
            func_0207f914((Struct_0207f914*)arg0->unknown_18_, (int)&arg0->unknown_24_, (int)data_ov017_021d7883, (int)data_ov017_021d789c);
#endif
            arg0->unknown_14_ = 2;
        }
    } else if (var6 == 2) {
        int var20 = func_0207f9f4(arg0->unknown_18_);
        if (var20 == 0) {
            arg0->unknown_14_ = 3;
        }
        if (var20 < 0) {
            arg0->unknown_14_ = 8;
        }
    } else if (var6 == 3) {
        Struct_0207f7f0* var21 = arg0->unknown_18_;
        var21->unknown_2c_ = arg0->unknown_1c_;
        var21->unknown_38_ = 2;
        func_0207f7f0(var21, arg0->unknown_20_, 2);
        var21->unknown_3a_ = 1;
        func_0207fcb8((Struct_0207fcb8*)var21);
        func_0207fd44((Struct_0207fd44_2*)var21);
        func_0207fd88((Struct_0207fd88*)var21);
        BG0CNT = (BG0CNT & ~3) | 2;
        BG1CNT = BG1CNT & ~3;
        BG2CNT = (BG2CNT & ~3) | 1;
        BG3CNT = (BG3CNT & ~3) | 3;
        DISPCNT = (DISPCNT & ~0x1f00) | 0x1700;
        arg0->unknown_14_ = 4;
    } else if (var6 == 4) {
        arg0->unknown_48_ = 0;
        arg0->unknown_4c_ = 0;
        arg0->unknown_4e_ = 0;
        func_0208203c((Struct_02081f20_2*)arg0->unknown_3c_);
        arg0->unknown_44_ = NULL;
        func_020813ec(arg0->unknown_18_, arg0->unknown_48_);
        func_ov017_021ab060((Struct_ov017_021aa59c_4*)arg0);
        arg0->unknown_14_ = 5;
    } else if (var6 == 5) {
        bool var22 = false;
        bool var23 = false;
        void* var24;
        Struct_0207f7f0* var25 = arg0->unknown_18_;
        var24 = func_02081da8((Struct_0207fdcc_2*)var25, arg0->unknown_48_);
        if (var25 != NULL) {
            if (var24 != NULL) {
                int var26 = var2->GetTickCount();
                func_0207fc6c((Struct_0207fc6c*)var25, var26);
                arg0->unknown_44_ = &arg0->unknown_4c_;
                if (arg0->unknown_44_ != NULL) {
                    func_02081f20(arg0->unknown_3c_, var26);
                    arg0->unknown_4e_ = *arg0->unknown_44_;
                    arg0->unknown_38_ = func_020800fc(var25, arg0->unknown_44_, arg0->unknown_4e_, arg0->unknown_40_->unknown_0_, arg0->unknown_40_->unknown_2_, false);
                    var25->unknown_36_ = *arg0->unknown_44_;
                    if (arg0->unknown_38_ != 0) {
                        func_020804fc(var25, arg0->unknown_48_);
                    }
                    if (arg0->unknown_4e_ != *arg0->unknown_44_ || g_touchInput.pressed_ != 0) {
                        func_020813ec(var25, arg0->unknown_48_);
                        func_ov017_021ab060((Struct_ov017_021aa59c_4*)arg0);
                    }
                }
                if (func_ov017_021ab0c0((Struct_ov017_021aa59c_5*)arg0) != 0) {
                    if (arg0->unknown_4e_ != *arg0->unknown_44_) {
                        return;
                    }
                    SePlayer_Play(&g_sePlayer, 1, 0);
                    ResetWithSub0208203c((Obj0208203c*)self->repeat);
                    self->cursorPtr = NULL;
                    if (self->cursor == 0) {
                        CallFunc0204c804OverAllElems((Cont0207fe44*)self->menu);
                        FlagWord_SetBits(flags, 0x200);
                    } else if (self->cursor == 1) {
                        cancelled = true;
                    }
                } else if (func_ov017_021ab1a4((Struct_ov017_021aa59c_6*)arg0) != 0) {
                    var23 = true;
                }
            } else if (g_keyManager.TestKeysPressed(0x401) != 0 || g_touchInput.pressed_ != 0) {
                func_020813ec(menu, self->key);
                SetThreeEntryFlags_021ab060((Obj021ab060*)self);
                FlagWord_ClearBits((FlagWord020466f4*)flags, 0x200);
            }
        }
        if (func_02010750((char*)var2) != 0 || var22) {
            arg0->unknown_14_ = 6;
            var23 = true;
            arg0->unknown_64_ = true;
        }
        if (redraw && menu != NULL && element != NULL) {
            CallFunc0204c804OverAllElems((Cont0207fe44*)self->menu);
            FlagWord_SetBits(flags, 0x200);
        }
    } else if (var6 == 6) {
        if (var1->unknown_0_ == 10000) {
            func_ov017_021d1a18(var1->unknown_2786_, var1->unknown_2784_, var1->unknown_2788_, 1);
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
            if (ListContainsId(list, 0x40) != 0) {
                func_02046a8c(list, res->fieldTasks_[39]);
            }
            ResetMpForFlaggedCombatants02010604(gs, 0, GetField0x5729Value_02010750((char*)gs), 0);
            SetField0x5729Value_0201075c((char*)gs, 0);
            DISPCNT = (DISPCNT & ~0x1f00) | (self->savedBgMode << 8);
            ROMFilesystem_InitFileTables();
            InitActorContext0209c20c((Actor0209c20c*)&g_bgmPlayer);
            func_ov017_021aaf08(self);
            self->done = 1;
        }
    }
}
