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
extern "C" void func_0205563c(Struct205563c*);
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
extern "C" void Background_Init(BackgroundGraphics*);
extern "C" void Background_SetMapSize(unsigned char*, int);
extern "C" void Background_AllocateMap(BackgroundGraphics*, SafeAllocator*);
extern "C" void Background_SetScroll(BackgroundGraphics*, int, int);
extern "C" void Background_AllocateScreens(BackgroundGraphics*, int, SafeAllocator*);
struct WindowPane;
extern "C" void WindowPane_AllocateBuffer(WindowPane*, SafeAllocator*, int, unsigned int);
struct PacRecord;
extern "C" int Pac_CountFiles(PacRecord*);
extern "C" void* Pac_GetFile(PacRecord*, int, void**, int*);
struct Struct_0207f914;
extern "C" void func_0207f914(Struct_0207f914*, int, int, int);
extern "C" void* MessageSystem_GetInstance();
extern "C" void func_0208108c(void* a, int b);
extern "C" void func_02081058(void* a, int b, int c);
extern "C" void func_02080798(void* a, int b, int c);
struct Struct0205a198;
extern "C" void Sprite_Init(Struct0205a198*);
struct ClearTarget0205a234;
extern "C" void func_0205a234(ClearTarget0205a234*);
struct Struct_020e2490;
extern "C" void func_020e2490(Struct_020e2490*, int, int, void*, SafeAllocator*, int, unsigned char);
extern "C" void Background_UploadMap(BackgroundGraphics*, void*);
extern "C" void func_0205aed0(void*, char*, unsigned int, int);
struct Manager0207f7f0;
struct Node0207f7f0;
extern "C" void func_0207f7f0(Manager0207f7f0*, Node0207f7f0*, int);
extern "C" unsigned char func_ov003_02160b50(void* a);
extern "C" int Scenario_TestFlag(int, unsigned char*, int);
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
    char pad[0x28];
};

struct Global998 {
    char pad[Enum_ov003_021615bc_2456];
    int unknown_998_;
    char pad2[4];
    int unknown_9a0_;
};

struct Struct_ov003_021615bc_3 {
    char pad0[Enum_ov003_021615bc_552];
    SafeAllocator a228;
    char pad1[0x264 - 0x228 - sizeof(SafeAllocator)];
    SafeAllocator a264;
    SafeAllocator a278;
    SafeAllocator unknown_28c_;
    SafeAllocator a2a0;
    SafeAllocator a2b4;
    SafeAllocator unknown_2c8_;
    char x2dc[0x3c];
    void* unknown_318_;
    void* unknown_31c_;
    void* p320;
    Manager0207f7f0* unknown_324_;
    BackgroundGraphics* p328;
    Node0207f7f0* p32c;
    char pad2[4];
    char x334[0x3c];
    void* unknown_370_;
    void* unknown_374_;
    char pad3[0x380 - 0x378];
    unsigned short unknown_380_;
    char unknown_382_[2];
    unsigned char unknown_384_;
    char pad4[3];
    Struct_ov003_021615bc* p388;
    void* p38c;
    void* unknown_390_;
    void** unknown_394_;
    void* p398;
    char pad5[Enum_ov003_021615bc_200];
    unsigned int unknown_464_;
    char pad6[4];
    int taskId;
    char unknown_470_[0xc];
    short unknown_47c_;
    short unknown_47e_;
    short unknown_480_;
    short unknown_482_;
    short unknown_484_;
    short unknown_486_;
    char pad8[0x49e - 0x488];
    unsigned char unknown_49e_;
    char unknown_49f_[2];
    unsigned char unknown_4a1_;
    char pad10;
    unsigned char unknown_4a3_;
    unsigned char step;
    unsigned char unknown_4a5_;
    char unknown_4a6_;
    unsigned char unknown_4a7_;
};

// USA: func_ov003_021615bc
extern "C" ARM void func_ov003_021615bc(Struct_ov003_021615bc_3* self) {
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    BackgroundGraphics* l;
    int i;
    int x;
    int k;
    if (self->step == 0) {
        self->a228.Reset();
        self->unknown_318_ = self->a228.Allocate(Enum_ov003_021615bc_120);
        self->unknown_31c_ = self->a228.Allocate(0x1c);
        self->p320 = self->a228.Allocate(0x130);
        self->unknown_324_ = (Manager0207f7f0*)self->a228.Allocate(Enum_ov003_021615bc_64);
        self->p328 = (BackgroundGraphics*)self->a228.Allocate(0x60);
        self->p32c = (Node0207f7f0*)self->a228.Allocate(0x380);
        self->unknown_394_ = (void**)self->a228.Allocate(0x10);
        func_ov003_021602bc(self);
        func_ov003_021672e4(self->unknown_318_, 0, -1);
        func_0205563c((Struct205563c*)self->unknown_31c_);
        GameObject_Initialize(self->p320);
        func_0207f84c(self->unknown_324_);
        for (int i = 0; i < 3; i++) {
            Background_Init((BackgroundGraphics*)(self->p328 + i));
        }
        for (int i = 0; i < 4; i++) {
            WindowPane_Init(self->p32c + i);
        }
        if (self->unknown_464_ & 0x10000) {
#if defined(jpn)
            self->taskId = loader->QueueLoadFile(data_ov003_0217e7e0, NULL);
#else
            self->taskId = loader->QueueLoadFileInGP2(data_ov003_0217fff0, data_ov003_0218000a, NULL);
#endif
        } else {
#if defined(jpn)
            self->taskId = loader->QueueLoadFile(data_ov003_0217e7fa, NULL);
#else
            self->taskId = loader->QueueLoadFileInGP2(data_ov003_0218001b, data_ov003_02180035, NULL);
#endif
        }
        self->step = self->step + 1;
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
            self->taskId = loader->QueueLoadFile(data_ov003_0217e814, NULL);
#else
        self->taskId = loader->QueueLoadFileInGP2(data_ov003_02180046, data_ov003_0218005a, NULL);
#endif
        self->step = self->step + 1;
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
            self->step = self->step + 1;
        }
    }
    if (self->step == 4) {
        self->unknown_28c_.Reset();
#if defined(jpn)
        func_02080654(self->unknown_324_, &self->unknown_28c_, data_ov003_0217e82a);
#else
        func_0207f914((Struct_0207f914*)self->unknown_324_, (int)&self->unknown_28c_, (int)data_ov003_0218006a, (int)data_ov003_02180083);
#endif
        self->step = self->step + 1;
    }
    if (self->step == 5) {
        int r = func_0207f9f4(self->unknown_324_);
        if (r == 0) {
            self->step = self->step + 1;
        }
        if (r < 0) {
            self->unknown_4a3_ = 0x10;
        }
    }
    if (self->step == 6) {
#if defined(jpn)
        Manager0207f7f0* m = self->unknown_324_;
        m->unknown_3b_ = 0x12;
        m->field3c = 0x10;
#endif
        if (self->unknown_464_ & 0x20000) {
            Global998* g = (Global998*)MessageSystem_GetInstance();
            if (g->unknown_998_ != 0 && g->unknown_9a0_ != 3) {
                return;
            }
            self->unknown_464_ &= ~0x20000;
        }
#if !defined(jpn)
        Manager0207f7f0* m = self->unknown_324_;
        m->unknown_3b_ = 0x12;
        m->field3c = 0x10;
        func_0208108c(m, 0);
        func_0208108c(m, 1);
        short* p = data_ov003_0217f46c;
        for (;;) {
            if (*p < 0) {
                break;
            }
            func_02081058(m, *p, 0x90);
            p++;
        }
        func_02081058(m, 0xc1, 0x9c);
        func_02081058(m, 0xc2, 0x9c);
        func_02081058(m, 0xc3, 0x9c);
        short id = 0x64;
        for (int i = 0; i < 8; i++) {
            func_02080798(m, id, 1);
            id++;
        }
#endif
        self->a2a0.Reset();
        self->p388 = (Struct_ov003_021615bc*)self->a2a0.Allocate(0x3e8);
        self->p38c = self->a2a0.Allocate(8);
        for (int i = 0; i < 0x19; i++) {
            Sprite_Init((Struct0205a198*)(self->p388 + i));
        }
        func_0205a234((ClearTarget0205a234*)self->p38c);
        self->unknown_384_ = 0;
        self->unknown_374_ = self->p388;
        self->unknown_380_ = 0x19;
        self->unknown_370_ = self->p38c;
        self->unknown_2c8_.Reset();
        self->unknown_390_ = self->unknown_2c8_.Allocate(0x24);
        func_020e2490((Struct_020e2490*)self->unknown_390_, 0, 1, self->p38c, &self->unknown_2c8_, Enum_ov003_021615bc_4, 0x40);
        self->taskId = loader->QueueLoadFile(data_ov003_0218008a, NULL);
        self->step = self->step + 1;
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
            func_0205aed0(self->x334, (char*)self->p388, 0x19, 0x40);
            loader->RemoveTask(self->taskId);
            self->taskId = -1;
            self->step = self->step + 1;
        }
    }
    if (self->step == 8) {
        Manager0207f7f0* m = self->unknown_324_;
#if defined(jpn)
        self->unknown_47c_ = func_02081b80(m, data_ov003_0217e862);
        self->unknown_47e_ = func_02081b80(m, data_ov003_0217e865);
#endif
        BG0CNT = (BG0CNT & ~3) | 3;
        BG1CNT = (BG1CNT & ~3) | 1;
        BG2CNT = (BG2CNT & ~3);
        BG3CNT = (BG3CNT & ~3) | 2;
        DISPCNT = (DISPCNT & ~0x1f00) | 0x1f00;
        ColorEffect_ConfigureAlphaBlend((unsigned int*)0x4000050, 2, 9, 0xa, 6);
        m->lists = self->p328;
        m->mode = 2;
        func_0207f7f0(m, self->p32c, 4);
        m->active = 2;
#if !defined(jpn)
        func_02081224(m, 0x19);
        func_02081224(m, 0x1a);
        func_02081224(m, 0x1b);
        self->unknown_49e_ = func_ov003_02160b50(self);
#endif
        char* save = (char*)Scenario_GetInstance();
        if (self->unknown_464_ & 0x10000) {
            self->unknown_4a3_ = 0xa;
            self->step = 0;
        } else if (self->unknown_4a1_ == 1) {
            self->unknown_4a3_ = 4;
            self->step = 2;
        } else if (self->unknown_4a1_ == 2) {
            self->unknown_4a3_ = 4;
            self->step = 0;
        } else if (self->unknown_4a1_ == 3) {
            self->unknown_484_ = 0x50;
            self->unknown_486_ = 2;
            self->step = 0;
            self->unknown_4a5_ = 0;
            self->unknown_4a3_ = 1;
            self->unknown_464_ |= 0x10;
            char* g = (char*)GetGameResources();
            self->unknown_482_ = *(unsigned char*)(*(char**)(g + 0x3000 + Enum_ov003_021615bc_1844) + Enum_ov003_021615bc_205);
        } else if (self->unknown_4a1_ == 4) {
            self->unknown_484_ = 0xd;
            self->unknown_486_ = 2;
            self->step = 0;
            self->unknown_4a5_ = 0;
            self->unknown_4a3_ = 1;
            self->unknown_464_ |= 8;
        } else {
#if defined(jpn)
            self->unknown_49e_ = func_ov003_02160b50(self);
#endif
            if (self->unknown_49e_ != 0 && self->unknown_49e_ != 1) {
                if (self->unknown_49e_ == 2) {
                    x = 3;
                }
            } else {
                x = 0;
            }
            self->unknown_484_ = x;
            self->unknown_486_ = -1;
            int flag = 1;
            GameObject* prot = GameState::GetInstance()->GetProtagonist();
            if (prot != NULL && (**(unsigned int**)((char*)prot + 0x130) & 1)) {
                self->unknown_484_ = 3;
                self->unknown_486_ = -1;
                flag = 0;
            }
            if (flag != 0 && self->unknown_49e_ != 2) {
                if (Scenario_TestFlag((int)save, (unsigned char*)(save + 0x8c), 0x77e) == 0) {
                    Scenario_SetFlag(save, (unsigned char*)(save + 0x8c), 0x77e, 1);
                    self->unknown_484_ = 0x4b;
                    self->unknown_486_ = x;
                }
            }
            self->unknown_4a3_ = 1;
            self->step = 0;
            self->unknown_4a5_ = 0;
        }
        self->unknown_464_ |= 0x1000;
        self->unknown_4a7_ = 0;
    }
}
