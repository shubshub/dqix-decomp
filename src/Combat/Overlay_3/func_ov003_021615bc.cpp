#include "Combat/MenuNodeChain.h"
#include "Combat/MapDisplay.h"
#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Graphics.h"
#include "Resource/GameResources.h"



#if defined(jpn)
enum { Enum_ov003_021615bc_4 = 3, Enum_ov003_021615bc_205 = 0xc9 };
enum { Enum_ov003_021615bc_552 = 0x110, Enum_ov003_021615bc_200 = 8, Enum_ov003_021615bc_2456 = 0x868, Enum_ov003_021615bc_32 = 0x20, Enum_ov003_021615bc_120 = 0x48, Enum_ov003_021615bc_64 = 0x34, Enum_ov003_021615bc_1844 = 0x524 };
extern "C" void func_02080654(void*, void*, const char*);
extern "C" int func_02081b80(void*, const char*);
extern const char data_ov003_0217e7e0[];
extern const char data_ov003_0217e7fa[];
extern const char data_ov003_0217e814[];
extern const char data_ov003_0217e82a[];
extern const char data_ov003_0217e862[];
extern const char data_ov003_0217e865[];
#else
enum { Enum_ov003_021615bc_4 = 4, Enum_ov003_021615bc_205 = 0xcd };
enum { Enum_ov003_021615bc_552 = 0x228, Enum_ov003_021615bc_200 = 0x464 - 0x39c, Enum_ov003_021615bc_2456 = 0x998, Enum_ov003_021615bc_44 = 0x2c, Enum_ov003_021615bc_120 = 0x78, Enum_ov003_021615bc_64 = 0x40, Enum_ov003_021615bc_1844 = 0x734 };
#endif

extern "C" void func_ov003_021602bc(void* self);
extern "C" void func_ov003_021672e4(void* a, int b, int c);
struct Struct205563c;
void ClearSevenWords_0205563c(Struct205563c*);
extern "C" void GameObject_Initialize(void* a);
extern "C" void WindowPane_Init(void* a);
extern "C" void KeyTable_Load(void* a, void* b, void* c, unsigned int d);
extern "C" void Background_SetPriority(void* a, int b);
extern "C" void Background_LoadFile(void* a, void* b, void* c, int d);
extern "C" void Background_FillRect(void* a, int b, int c, int d, int e, int f, int g);
extern "C" void SpriteContext_LoadFile(void* a, void* b, int c, void* d);
extern "C" int func_0207f9f4(void* a);
extern "C" void func_02081224(void* a, int b);
extern "C" void* Scenario_GetInstance();
struct BackgroundGraphics;
void Background_Init(BackgroundGraphics*);
void Background_SetMapSize(unsigned char*, int);
void Background_AllocateMap(BackgroundGraphics*, SafeAllocator*);
void Background_SetScroll(BackgroundGraphics*, int, int);
void Background_AllocateScreens(BackgroundGraphics*, int, SafeAllocator*);
struct WindowPane;
void WindowPane_AllocateBuffer(WindowPane*, SafeAllocator*, int, unsigned int);
struct PacRecord;
int Pac_CountFiles(PacRecord*);
void* Pac_GetFile(PacRecord*, int, void**, int*);
struct Obj0207f914;
void SetFieldsFromFormattedValue0207f914(Obj0207f914*, int, int, int);
void* MessageSystem_GetInstance();
void DispatchEntryOp0x8_0208108c(void* a, int b);
void SetEntryValueAndFlag02081058(void* a, int b, int c);
void SetSublistEntryField14LowBits_02080798(void* a, int b, int c);
struct Struct0205a198;
void Sprite_Init(Struct0205a198*);
struct ClearTarget0205a234;
void ClearField0And40205a234(ClearTarget0205a234*);
struct EntryManager020e2490;
void InitEntryManager020e2490(EntryManager020e2490*, int, int, void*, SafeAllocator*, int, unsigned char);
void Background_UploadMap(BackgroundGraphics*, void*);
void WrapAddByteField0x22_0205aed0(void*, char*, unsigned int, int);
struct Manager0207f7f0;
struct Node0207f7f0;
void InitNodeChain0207f7f0(Manager0207f7f0*, Node0207f7f0*, int);
unsigned char CheckField0AndBattleState_02160b50(void* a);
int Scenario_TestFlag(int, unsigned char*, int);
extern "C" void Scenario_SetFlag(void*, unsigned char*, int, int);
extern "C" void ColorEffect_ConfigureAlphaBlend(unsigned int* out, unsigned char a, unsigned char b, unsigned char c, int d);

extern char data_ov003_0217fff0[];
extern char data_ov003_0218000a[];
extern char data_ov003_0218001b[];
extern char data_ov003_02180035[];
extern int data_ov003_0217f454[];
extern int data_ov003_0217f460[];
extern char data_ov003_02180046[];
extern char data_ov003_0218005a[];
extern char data_ov003_0218006a[];
extern char data_ov003_02180083[];
extern short data_ov003_0217f46c[];
extern char data_ov003_0218008a[];

struct Struct_ov003_021615bc {
    char unknown_0_[0x28];
};

struct Struct_ov003_021615bc_2 {
    char unknown_0_[Enum_ov003_021615bc_2456];
    int unknown_998_;
    char unknown_99c_[4];
    int unknown_9a0_;
};

struct Scene021615bc {
    char pad0[kScenePrefix];
    SafeAllocator a228;
    char pad1[0x264 - 0x228 - sizeof(SafeAllocator)];
    SafeAllocator a264;
    SafeAllocator a278;
    SafeAllocator a28c;
    SafeAllocator a2a0;
    SafeAllocator a2b4;
    SafeAllocator a2c8;
    char x2dc[0x3c];
    void* p318;
    void* p31c;
    void* p320;
    Manager0207f7f0* p324;
    BackgroundGraphics* p328;
    Node0207f7f0* p32c;
    char pad2[4];
    char x334[0x3c];
    void* p370;
    void* p374;
    char pad3[0x380 - 0x378];
    unsigned short h380;
    char pad3b[2];
    unsigned char b384;
    char pad4[3];
    Entry28* p388;
    void* p38c;
    void* p390;
    void** p394;
    void* p398;
    char pad5[kSceneExtraPadding];
    unsigned int flags464;
    char pad6[4];
    int taskId;
    char pad7[0xc];
    short jpHiraganaEntry;
    short jpKatakanaEntry;
    short h480;
    short h482;
    short h484;
    short h486;
    char pad8[0x49e - 0x488];
    unsigned char b49e;
    char pad9[2];
    unsigned char b4a1;
    char pad10;
    unsigned char b4a3;
    unsigned char step;
    unsigned char b4a5;
    char pad11;
    unsigned char b4a7;
};

// USA: func_ov003_021615bc
extern "C" ARM void func_ov003_021615bc(Scene021615bc* self) {
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    BackgroundGraphics* l;
    int i;
    int x;
    int k;
    if (self->step == 0) {
        self->a228.Reset();
        self->p318 = self->a228.Allocate(kFirstAllocation);
        self->p31c = self->a228.Allocate(0x1c);
        self->p320 = self->a228.Allocate(0x130);
        self->p324 = (Manager0207f7f0*)self->a228.Allocate(kManagerAllocation);
        self->p328 = (BackgroundGraphics*)self->a228.Allocate(0x60);
        self->p32c = (Node0207f7f0*)self->a228.Allocate(0x380);
        self->p394 = (void**)self->a228.Allocate(0x10);
        func_ov003_021602bc(self);
        func_ov003_021672e4(self->p318, 0, -1);
        ClearSevenWords_0205563c((Struct205563c*)self->p31c);
        GameObject_Initialize(self->p320);
        func_0207f84c(self->p324);
        for (int i = 0; i < 3; i++) {
            Background_Init((BackgroundGraphics*)(self->p328 + i));
        }
        for (int i = 0; i < 4; i++) {
            WindowPane_Init(self->p32c + i);
        }
        if (arg0->unknown_464_ & 0x10000) {
#if defined(jpn)
            arg0->unknown_46c_ = var0->QueueLoadFile(data_ov003_0217e7e0, NULL);
#else
            arg0->unknown_46c_ = var0->QueueLoadFileInGP2(data_ov003_0217fff0, data_ov003_0218000a, NULL);
#endif
        } else {
#if defined(jpn)
            arg0->unknown_46c_ = var0->QueueLoadFile(data_ov003_0217e7fa, NULL);
#else
            arg0->unknown_46c_ = var0->QueueLoadFileInGP2(data_ov003_0218001b, data_ov003_02180035, NULL);
#endif
        }
        arg0->unknown_4a4_ = arg0->unknown_4a4_ + 1;
    }
    if (self->step == 1) {
        if (loader->GetTaskStatus(self->taskId) != 0) {
            void* data;
            unsigned int len;
            loader->GetLoadedFileByID(self->taskId, &data, &len);
            self->a2b4.Reset();
            KeyTable_Load(self->x2dc, &self->a2b4, data, len);
            loader->RemoveTask(self->taskId);
            self->taskId = -1;
            self->step = self->step + 1;
        }
    }
    if (self->step == 2) {
        self->a264.Reset();
        for (i = 0; i < 3; i++) {
            l = self->p328 + i;
            Background_SetMapSize((unsigned char*)l, 0);
            k = data_ov003_0217f454[i];
            l->subScreen_ = 0;
            l->bgNumber_ = k;
            Background_SetPriority(l, data_ov003_0217f460[i]);
            Background_AllocateMap((BackgroundGraphics*)l, (SafeAllocator*)&self->a264);
            Background_SetScroll((BackgroundGraphics*)l, 0, 0);
            if (k == 3) {
                Background_AllocateScreens((BackgroundGraphics*)l, 5, (SafeAllocator*)&self->a264);
            }
        }
        BG1CNT = (BG1CNT & 0x43) | 0x1e00;
        BG2CNT = (BG2CNT & 0x43) | 0x1f00;
        BG3CNT = (BG3CNT & 0x43) | 0x1d08;
        ColorEffect_ConfigureAlphaBlend((unsigned int*)0x4000050, 2, 9, 0xa, 6);
#if defined(jpn)
            arg0->unknown_46c_ = var0->QueueLoadFile(data_ov003_0217e814, NULL);
#else
        arg0->unknown_46c_ = var0->QueueLoadFileInGP2(data_ov003_02180046, data_ov003_0218005a, NULL);
#endif
        arg0->unknown_4a4_ = arg0->unknown_4a4_ + 1;
    }
    if (self->step == 3) {
        if (loader->GetTaskStatus(self->taskId) != 0) {
            void* recs[8];
            int idx[8];
            void* out;
            void* data;
            unsigned int len;
            loader->GetLoadedFileByID(self->taskId, &data, &len);
            int n = Pac_CountFiles((PacRecord*)data);
            for (int i = 0; i < n; i++) {
                recs[i] = Pac_GetFile((PacRecord*)data, i, &out, &idx[i]);
            }
            for (int i = 0; i < n; i++) {
                if (recs[i] != NULL) {
                    if (i == 0) {
                        Background_LoadFile(self->p328 + 1, recs[i], &self->a264, idx[i]);
                    } else {
                        Background_LoadFile(self->p328 + 2, recs[i], &self->a264, idx[i]);
                    }
                }
            }
            loader->RemoveTask(self->taskId);
            self->taskId = -1;
            BackgroundGraphics* l;
            for (int i = 0; i < 3; i++) {
                l = self->p328 + i;
                Background_FillRect(l, 0, 0, 0, 0x20, 0x19, 0);
                Background_UploadMap((BackgroundGraphics*)l, NULL);
            }
            self->a278.Reset();
            self->p398 = self->a278.Allocate(0x6000);
            Node0207f7f0* o;
            for (int i = 0; i < 4; i++) {
                o = self->p32c + i;
                WindowPane_AllocateBuffer((WindowPane*)o, (SafeAllocator*)&self->a278, (int)self->p398, 0x400);
                o->lists = self->p328 + 1;
            }
            arg0->unknown_4a4_ = arg0->unknown_4a4_ + 1;
        }
    }
    if (arg0->unknown_4a4_ == 4) {
        arg0->unknown_28c_.Reset();
#if defined(jpn)
        func_02080654(arg0->unknown_324_, &arg0->unknown_28c_, data_ov003_0217e82a);
#else
        func_0207f914((Struct_0207f914*)arg0->unknown_324_, (int)&arg0->unknown_28c_, (int)data_ov003_0218006a, (int)data_ov003_02180083);
#endif
        arg0->unknown_4a4_ = arg0->unknown_4a4_ + 1;
    }
    if (arg0->unknown_4a4_ == 5) {
        int var21 = func_0207f9f4(arg0->unknown_324_);
        if (var21 == 0) {
            arg0->unknown_4a4_ = arg0->unknown_4a4_ + 1;
        }
        if (var21 < 0) {
            arg0->unknown_4a3_ = 0x10;
        }
    }
    if (arg0->unknown_4a4_ == 6) {
#if defined(jpn)
        Struct_0207f7f0* var22 = arg0->unknown_324_;
        var22->unknown_3b_ = 0x12;
        var22->unknown_3c_ = 0x10;
#endif
        if (self->flags464 & 0x20000) {
            Global998* g = (Global998*)MessageSystem_GetInstance();
            if (g->f998 != 0 && g->f9a0 != 3) {
                return;
            }
            arg0->unknown_464_ &= ~0x20000;
        }
#if !defined(jpn)
        Struct_0207f7f0* var24 = arg0->unknown_324_;
        var24->unknown_3b_ = 0x12;
        var24->unknown_3c_ = 0x10;
        func_0208108c(var24, 0);
        func_0208108c(var24, 1);
        short* var25 = data_ov003_0217f46c;
        for (;;) {
            if (*var25 < 0) {
                break;
            }
            func_02081058(var24, *var25, 0x90);
            var25++;
        }
        func_02081058(var24, 0xc1, 0x9c);
        func_02081058(var24, 0xc2, 0x9c);
        func_02081058(var24, 0xc3, 0x9c);
        short var26 = 0x64;
        for (int var27 = 0; var27 < 8; var27++) {
            func_02080798(var24, var26, 1);
            var26++;
        }
#endif
        self->a2a0.Reset();
        self->p388 = (Entry28*)self->a2a0.Allocate(0x3e8);
        self->p38c = self->a2a0.Allocate(8);
        for (int i = 0; i < 0x19; i++) {
            Sprite_Init((Struct0205a198*)(self->p388 + i));
        }
        func_0205a234((Struct_02043368*)arg0->unknown_38c_);
        arg0->unknown_384_ = 0;
        arg0->unknown_374_ = arg0->unknown_388_;
        arg0->unknown_380_ = 0x19;
        arg0->unknown_370_ = arg0->unknown_38c_;
        arg0->unknown_2c8_.Reset();
        arg0->unknown_390_ = arg0->unknown_2c8_.Allocate(0x24);
        func_020e2490((Struct_020e2490*)arg0->unknown_390_, 0, 1, arg0->unknown_38c_, &arg0->unknown_2c8_, Enum_ov003_021615bc_4, 0x40);
        arg0->unknown_46c_ = var0->QueueLoadFile(data_ov003_0218008a, NULL);
        arg0->unknown_4a4_ = arg0->unknown_4a4_ + 1;
    }
    if (self->step == 7) {
        if (loader->GetTaskStatus(self->taskId) != 0) {
            void* out;
            void* data;
            unsigned int len;
            int idx;
            loader->GetLoadedFileByID(self->taskId, &data, &len);
            int n = Pac_CountFiles((PacRecord*)data);
            for (int i = 0; i < n; i++) {
                void* rec = Pac_GetFile((PacRecord*)data, i, &out, &idx);
                SpriteContext_LoadFile(self->x334, rec, idx, &self->a2a0);
            }
            func_0205aed0(arg0->unknown_334_, (char*)arg0->unknown_388_, 0x19, 0x40);
            var0->RemoveTask(arg0->unknown_46c_);
            arg0->unknown_46c_ = -1;
            arg0->unknown_4a4_ = arg0->unknown_4a4_ + 1;
        }
    }
    if (arg0->unknown_4a4_ == 8) {
        Struct_0207f7f0* var36 = arg0->unknown_324_;
#if defined(jpn)
        arg0->unknown_47c_ = func_02081b80(var36, data_ov003_0217e862);
        arg0->unknown_47e_ = func_02081b80(var36, data_ov003_0217e865);
#endif
        BG0CNT = (BG0CNT & ~3) | 3;
        BG1CNT = (BG1CNT & ~3) | 1;
        BG2CNT = (BG2CNT & ~3);
        BG3CNT = (BG3CNT & ~3) | 2;
        DISPCNT = (DISPCNT & ~0x1f00) | 0x1f00;
        ColorEffect_ConfigureAlphaBlend((unsigned int*)0x4000050, 2, 9, 0xa, 6);
        var36->unknown_2c_ = arg0->unknown_328_;
        var36->unknown_38_ = 2;
        func_0207f7f0(var36, arg0->unknown_32c_, 4);
        var36->unknown_3a_ = 2;
#if !defined(jpn)
        func_02081224(var36, 0x19);
        func_02081224(var36, 0x1a);
        func_02081224(var36, 0x1b);
        arg0->unknown_49e_ = func_ov003_02160b50(arg0);
#endif
        char* save = (char*)Scenario_GetInstance();
        if (self->flags464 & 0x10000) {
            self->b4a3 = 0xa;
            self->step = 0;
        } else if (self->b4a1 == 1) {
            self->b4a3 = 4;
            self->step = 2;
        } else if (self->b4a1 == 2) {
            self->b4a3 = 4;
            self->step = 0;
        } else if (self->b4a1 == 3) {
            self->h484 = 0x50;
            self->h486 = 2;
            self->step = 0;
            self->b4a5 = 0;
            self->b4a3 = 1;
            self->flags464 |= 0x10;
            char* g = (char*)GetGameResources();
            self->h482 = *(unsigned char*)(*(char**)(g + 0x3000 + kResourceSlot) + kResourceByte);
        } else if (self->b4a1 == 4) {
            self->h484 = 0xd;
            self->h486 = 2;
            self->step = 0;
            self->b4a5 = 0;
            self->b4a3 = 1;
            self->flags464 |= 8;
        } else {
#if defined(jpn)
            arg0->unknown_49e_ = func_ov003_02160b50(arg0);
#endif
            if (arg0->unknown_49e_ != 0 && arg0->unknown_49e_ != 1) {
                if (arg0->unknown_49e_ == 2) {
                    var3 = 3;
                }
            } else {
                var3 = 0;
            }
            arg0->unknown_484_ = var3;
            arg0->unknown_486_ = -1;
            int var39 = 1;
            GameObject* var40 = GameState::GetInstance()->GetProtagonist();
            if (var40 != NULL && (**(unsigned int**)((char*)var40 + 0x130) & 1)) {
                arg0->unknown_484_ = 3;
                arg0->unknown_486_ = -1;
                var39 = 0;
            }
            if (flag != 0 && self->b49e != 2) {
                if (Scenario_TestFlag((int)save, (unsigned char*)(save + 0x8c), 0x77e) == 0) {
                    Scenario_SetFlag(save, (unsigned char*)(save + 0x8c), 0x77e, 1);
                    self->h484 = 0x4b;
                    self->h486 = x;
                }
            }
            arg0->unknown_4a3_ = 1;
            arg0->unknown_4a4_ = 0;
            arg0->unknown_4a5_ = 0;
        }
        arg0->unknown_464_ |= 0x1000;
        arg0->unknown_4a7_ = 0;
    }
}
