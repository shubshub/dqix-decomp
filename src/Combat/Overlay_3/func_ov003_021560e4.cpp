#include "Combat/MenuNodeChain.h"
#include "Combat/MapDisplay.h"
#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Resource/GameResources.h"


#if defined(jpn)
enum { Enum_ov003_021560e4_464 = 0x1cc, Enum_ov003_021560e4_1820 = 0x50c, Enum_ov003_021560e4_2456 = 0x868, Enum_ov003_021560e4_32 = 0x20, Enum_ov003_021560e4_44 = 0x2c, Enum_ov003_021560e4_46 = 0x2e };
extern "C" void MessageSystem_SetStringArgument(void*, int, char*);
extern "C" void func_0204500c(void*, void*, int);
extern "C" void func_02080654(void*, void*, const char*);
extern const char data_ov003_0217e554[];
extern const char data_ov003_0217e56e[];
extern const char data_ov003_0217e595[];
extern const char data_ov003_0217e5b3[];
extern const char data_ov003_0217e5c9[];
#else
enum { Enum_ov003_021560e4_464 = 0x1d0, Enum_ov003_021560e4_1820 = 0x71c, Enum_ov003_021560e4_2456 = 0x998, Enum_ov003_021560e4_44_2 = 0x2c, Enum_ov003_021560e4_56 = 0x38, Enum_ov003_021560e4_58 = 0x3a };
#endif

extern "C" {
void ColorEffect_ConfigureAlphaBlend(int, int, int, int, int);
extern "C" int Pac_GetFile(void*, int, void**, int*);
extern "C" int Pac_CountFiles(void*);
extern "C" int GameState_GetProtagonistIndex(void*);
extern "C" void SpriteContext_Init(void*);
extern "C" int Scenario_TestFlag(void*, void*, int);
extern "C" void KeyTable_Reset(void*);
extern "C" void func_ov023_021e20c0(void*);
extern "C" void* KeyTable_Get(void*, int);
extern "C" void WindowPane_AllocateBuffer(void*, void*, int, int);
extern "C" void func_0207fcb8(void*);
extern "C" void Background_SetScroll(void*, int, int);
extern "C" void func_020807fc(void*, int, int, int);
extern "C" void Background_SetMapSize(void*, int);
extern "C" void* TextQueue_GetInstance(void);
extern "C" void* MessageSystem_GetInstance(void);
extern "C" void func_02080828(void*, short, short*, short*);
extern "C" void func_02080878(void*, int, short*, short*);
extern "C" void func_02080854(void*, short, int, int);
extern "C" void func_020808a4(void*, int, int, int);
extern "C" void func_0207fd44(void*);
extern "C" void func_0207fd88(void*);
extern "C" void func_0207fe44(void*);
extern "C" int func_ov003_0215570c(void*);
extern "C" int func_02081010(void*, int);
extern "C" void TextQueue_Reset(void*);
extern "C" void Background_AllocateMap(void*, void*);
extern "C" void NameText_InitFromPartyMember(void*, int);
extern "C" void func_020807c4(void*, int, short*, short*);
extern "C" void func_0207f914(void*, void*, const char*, const char*);
extern "C" int func_ov003_02155f88(void*, int);
void _ZN13SafeAllocator5ResetEv(void*);
int Font_GetTextWidth(int, int);
#if !defined(jpn)
void func_0204500c(void*, void*, int, int);
#endif
void func_02046380(void*);
void Background_LoadFile(void*, void*, int, int);
void Background_SetPriority(void*, int);
void SpriteContext_LoadFile(void*, void*, int, void*);
void* Scenario_GetInstance(void);
int func_0207f9f4(void*);
void KeyTable_Load(void*, void*, void*, unsigned int);
void func_ov003_02156054(void*);
void func_ov023_021e20f0(void*, void*, void*, unsigned int);
}

extern const char data_ov003_0217fce4[];
extern const char data_ov003_0217fcfe[];
extern const char data_ov003_0217fd0f[];
extern const char data_ov003_0217fd23[];
extern const char data_ov003_0217fd33[];
extern const char data_ov003_0217fd46[];
extern const char data_ov003_0217fd60[];
extern const char data_ov003_0217fd68[];
extern const char data_ov003_0217fd7e[];
extern const char data_ov003_0217fd90[];
extern const char data_ov003_0217fdaa[];
struct Struct_ov003_0217f29c {
    unsigned char v[2];
};
extern const Struct_ov003_0217f29c data_ov003_0217f29c[];
extern const short data_ov003_0217f2a0[];
extern const short data_ov003_0217f2ae[];

struct Struct_02000c9c_82 {
    unsigned char lo : 4;
    unsigned char hi : 4;
};

struct Struct_ov003_021560e4 {
    void* alloc;
    char pad04[0xc - 4];
    int f0c;
    BackgroundGraphics* f10;
    Node0207f7f0* f14;
    Manager0207f7f0* f18;
    void* f1c;
    char pad20[4];
    int f24;
    char pad28[4];
    char sub2c[0x68 - 0x2c];
    int f68;
    int f6c;
    char unknown_70_[0x78 - 0x70];
    short unknown_78_;
    char unknown_7a_[2];
    char f7c;
    char unknown_7d_[0xe4 - 0x7d];
    char sube4[0xfc - 0xe4];
    char subfc[0x114 - 0xfc];
    char unknown_114_[Enum_ov003_021560e4_464 - 0x114];
    int task;
    char unknown_1d4_[0x1ec - 0x1d4];
    short unknown_1ec_;
    short unknown_1ee_;
    char unknown_1f0_[2];
    unsigned char unknown_1f2_;
    char unknown_1f3_[4];
    char f1f7;
    unsigned char mode;
    unsigned char state;
    char unknown_1fa_;
    unsigned char unknown_1fb_;
    unsigned int flags;
};

// USA: func_ov003_021560e4
extern "C" ARM void func_ov003_021560e4(Struct_ov003_021560e4* self) {
    char* a;
    int state;
    BackgroundLoader* loader;
    loader = BackgroundLoader::GetInstance();
    state = self->state;

    if (state == 0) {
        if (self->flags & 1) {
            TextQueue_Reset(TextQueue_GetInstance());
        }
        func_ov003_02156054(self);
        FontBankLoader* g = FontBankLoader_GetInstance();
        FontBankLoader_CancelLoads(g);
        func_02094b34(g, 0x66, 0x1f5, 0, 0);
        self->state = self->state + 1;
    } else if (state == 1) {
        if (func_02094b4c(FontBankLoader_GetInstance())) {
#if defined(jpn)
            self->task = loader->QueueLoadFile(data_ov003_0217e554, 0);
#else
            self->task = loader->QueueLoadFileInGP2(data_ov003_0217fce4, data_ov003_0217fcfe, 0);
#endif
            self->state = self->state + 1;
        }
    } else if (state == 2) {
        if (loader->GetTaskStatus(self->task)) {
            int tmp[3];
            void* file;
            unsigned int size;
            loader->GetLoadedFileByID(self->task, &file, &size);
            void* a = self->alloc;
            _ZN13SafeAllocator5ResetEv(a);
            KeyTable_Reset(self->sube4);
            KeyTable_Load(self->sube4, a, file, size);
            loader->RemoveTask(self->task);
            self->task = -1;
            char* g = (char*)MessageSystem_GetInstance();
            int key = -1;
            if (self->flags & 1) {
                key = 0x1a;
                char* x = (char*)GetGameResources();
                int id = *(short*)(*(char**)(x + 0x3000 + Enum_ov003_021560e4_1820) + 0x22);
                GameState* gs = GameState::GetInstance();
                GameObject* pm = gs->GetPartyMemberByIndex(id);
                if (pm == 0) {
                    pm = gs->GetPartyMemberByIndex(GameState_GetProtagonistIndex(gs));
                }
                func_02046380(g);
#if defined(jpn)
                if (pm != 0) {
                    MessageSystem_SetStringArgument(g, 0, *(char**)((char*)pm + 0x134));
                }
#else
                NameText_InitFromPartyMember(tmp, pm->obj3D_.actorIndex_);
                *(void**)g = tmp;
#endif
            } else {
                char* x = (char*)Scenario_GetInstance();
                if (Scenario_TestFlag(x, x + 0x8c, 0x799)) {
                    key = 0;
                } else {
                    self->unknown_1ec_ = 0;
                    self->unknown_1ee_ = 1;
                    self->mode = 7;
                }
            }
            void* r = KeyTable_Get(self->sube4, key);
            if (r) {
#if defined(jpn)
                func_0204500c(g, r, 0);
#else
                func_0204500c(g, r, 0, 0xe3);
#endif
                *(int*)(g + Enum_ov003_021560e4_2456) = 1;
                *(int*)(g + Enum_ov003_021560e4_2456 + 4) = 1;
            }
            SpriteContext_Init(self->sub2c);
            self->f7c = 0;
            self->f6c = self->f24;
            self->unknown_78_ = 10;
            if (self->f1c) {
                self->f68 = *(int*)((char*)self->f1c + 0x20);
            }
#if defined(jpn)
            self->task = loader->QueueLoadFile(data_ov003_0217e56e, 0);
#else
            self->task = loader->QueueLoadFileInGP2(data_ov003_0217fd0f, data_ov003_0217fd23, 0);
#endif
            self->state = self->state + 1;
        }
    } else if (state == 3) {
        if (loader->GetTaskStatus(self->task)) {
            void* p;
            void* file;
            unsigned int size;
            int len;
            loader->GetLoadedFileByID(self->task, &file, &size);
            int n = Pac_CountFiles(file);
            a = (char*)self->alloc;
            _ZN13SafeAllocator5ResetEv(a + 0x3c);
            for (int i = 0; i < n; i++) {
                void* rec = (void*)Pac_GetFile(file, i, &p, &len);
                SpriteContext_LoadFile(self->sub2c, rec, len, a + 0x3c);
            }
            loader->RemoveTask(self->task);
            self->task = -1;
            a = (char*)self->alloc;
            _ZN13SafeAllocator5ResetEv(a + 0x14);
            Struct_ov003_0217f29c A = data_ov003_0217f29c[0];
            Struct_ov003_0217f29c B = data_ov003_0217f29c[1];
            for (unsigned char i = 0; i < 2; i++) {
                BackgroundGraphics* e = self->f10 + i;
                Background_SetMapSize(e, 0);
                e->subScreen_ = 0;
                e->bgNumber_ = A.v[i];
                Background_SetPriority(e, B.v[i]);
                Background_AllocateMap(e, a + 0x14);
                Background_SetScroll(e, 0, 0);
            }
            *(volatile unsigned short*)0x400000a = (*(volatile unsigned short*)0x400000a & 0x43) | 0x1e00;
            *(volatile unsigned short*)0x400000c = (*(volatile unsigned short*)0x400000c & 0x43) | 0x1f00;
            ColorEffect_ConfigureAlphaBlend(0x4000050, 4, 1, 10, 6);
            self->task = loader->QueueLoadFile(data_ov003_0217fd33, 0);
            self->state = self->state + 1;
        }
    } else if (state == 4) {
        if (loader->GetTaskStatus(self->task)) {
            void* p;
            void* file;
            unsigned int size;
            int len;
            loader->GetLoadedFileByID(self->task, &file, &size);
            int n = Pac_CountFiles(file);
            BackgroundGraphics* e = self->f10;
            for (int i = 0; i < n; i++) {
                void* rec = (void*)Pac_GetFile(file, i, &p, &len);
                Background_LoadFile(e, rec, 0, len);
            }
            loader->RemoveTask(self->task);
            self->task = -1;
            char* a = (char*)self->alloc;
            for (unsigned char j = 0; j < 3; j++) {
                Node0207f7f0* ent = self->f14 + j;
                WindowPane_AllocateBuffer(ent, a + 0x14, self->f0c, 0x4cc);
                ent->lists = self->f10;
            }
            a = (char*)self->alloc;
            _ZN13SafeAllocator5ResetEv(a + 0x28);
#if defined(jpn)
            func_02080654(self->f18, a + 0x28, data_ov003_0217e595);
#else
            func_0207f914(self->f18, a + 0x28, data_ov003_0217fd46, data_ov003_0217fd60);
#endif
            self->state = self->state + 1;
        }
    } else if (state == 5) {
        int r = func_0207f9f4(self->f18);
        if (r == 0) {
            self->state = self->state + 1;
        }
        if (r < 0) {
            self->mode = 7;
        }
    } else if (state == 6) {
        void* p = self->f18;
#if !defined(jpn)
        short x, y, w, h;
        func_020807c4(p, 2, &x, &y);
        func_02080878(p, 2, &w, &h);
        int var44 = 0;
        for (int k = 0; k < 2; k++) {
            int v = Font_GetTextWidth(func_02081010(p, data_ov003_0217f2a0[k]), 0);
            if (var44 < v) var44 = v;
        }
        w = (var44 + 0x1b) & ~7;
        w = w >> 3;
        if (w & 1) w = w + 1;
        x = (0x20 - w) >> 1;
        x = x << 3;
        func_020807fc(p, 2, x, y);
        func_020808a4(p, 2, w, h);
#endif
        if (func_ov003_0215570c(self) >= 9) {
            for (unsigned char i = 0; i < 12; i++) {
                for (int j = 0; j < 3; j++) {
                    int idx = i + data_ov003_0217f2ae[j];
                    short a, b;
                    func_02080828(p, idx, &a, &b);
                    func_02080854(p, idx, a, (short)(b - 1));
                }
            }
        }
#if defined(jpn)
            self->task = loader->QueueLoadFile(data_ov003_0217e5b3, 0);
#else
        self->task = loader->QueueLoadFileInGP2(data_ov003_0217fd68, data_ov003_0217fd7e, 0);
#endif
        self->state = self->state + 1;
    } else if (state == 7) {
        if (loader->GetTaskStatus(self->task)) {
            void* file;
            unsigned int size;
            loader->GetLoadedFileByID(self->task, &file, &size);
            if (file) {
                char* a = (char*)self->alloc;
                _ZN13SafeAllocator5ResetEv(a + 0x50);
                func_ov023_021e20c0(self->unknown_114_);
                func_ov023_021e20f0(self->unknown_114_, a + 0x50, file, size);
            }
            loader->RemoveTask(self->task);
            self->task = -1;
#if defined(jpn)
            self->task = loader->QueueLoadFile(data_ov003_0217e5c9, 0);
#else
            self->task = loader->QueueLoadFileInGP2(data_ov003_0217fd90, data_ov003_0217fdaa, 0);
#endif
            self->state = self->state + 1;
        }
    } else if (state == 8) {
        if (loader->GetTaskStatus(self->task)) {
            void* file;
            unsigned int size;
            loader->GetLoadedFileByID(self->task, &file, &size);
            if (file) {
                void* a = self->alloc;
                KeyTable_Reset(self->subfc);
                KeyTable_Load(self->subfc, a, file, size);
            }
            loader->RemoveTask(self->task);
            self->task = -1;
            self->state = self->state + 1;
        }
    } else if (state == 9) {
        char* g = (char*)MessageSystem_GetInstance();
        if (*(int*)(g + Enum_ov003_021560e4_2456 + 8) == 3) {
            Manager0207f7f0* p = self->f18;
            p->lists = self->f10;
            p->mode = 2;
            func_0207f7f0(p, self->f14, 3);
            p->active = 1;
            func_0207fcb8(p);
            func_0207fd44(p);
            func_0207fd88(p);
            volatile unsigned short* bg = (volatile unsigned short*)0x4000008;
            bg[0] = (bg[0] & ~3) | 2;
            bg[1] = bg[1] & ~3;
            bg[2] = (bg[2] & ~3) | 1;
            bg[3] = (bg[3] & ~3) | 3;
            *(volatile unsigned int*)0x4000000 = (*(volatile unsigned int*)0x4000000 & ~0x1f00) | 0x1700;
            self->mode = 7;
            self->state = 0;
            if (self->flags & 1) {
                GameState* gs = GameState::GetInstance();
                if (self->unknown_1fb_ == 0) {
                    self->f1f7 = GameState_GetProtagonistIndex(gs);
                    self->state = 0;
                    if (func_ov003_02155f88(self, self->f1f7)) {
                        self->unknown_1ec_ = 8;
                        self->mode = 7;
                        func_0207fe44(p);
                    } else {
                        self->flags = self->flags | 2;
                        self->unknown_1ec_ = 9;
                        self->mode = 3;
                        self->state = 0;
                    }
                } else {
                    self->f1f7 = self->unknown_1f2_;
                    self->unknown_1ec_ = 6;
                    self->mode = 2;
                    self->state = 2;
                }
            } else {
                char* x = (char*)Scenario_GetInstance();
                if (Scenario_TestFlag(x, x + 0x8c, 0x796)) {
                    self->unknown_1ec_ = 4;
                    self->mode = 1;
                } else {
                    self->unknown_1ec_ = 2;
                    self->mode = 2;
                }
            }
        }
    }
}
