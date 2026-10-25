#include "Combat/MenuNodeChain.h"
#include "Combat/MapDisplay.h"
#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Resource/GameResources.h"


#if defined(jpn)
enum { kTaskOffset = 0x1cc, kPartyResourceOffset = 0x50c, kGlobalFieldOffset = 0x868, kManagerListOffset = 0x20, kManagerStateOffset = 0x2c, kManagerFlagOffset = 0x2e };
extern "C" void _Z31MessageSystem_SetStringArgumentP11Obj02046574iPc(void*, int, char*);
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
int _Z11Pac_GetFileP9PacRecordiPPvPi(void*, int, void**, int*);
int _Z14Pac_CountFilesP9PacRecord(void*);
int _Z29GameState_GetProtagonistIndexP9GameState(void*);
void _Z18SpriteContext_InitPc(void*);
int _Z17Scenario_TestFlagiPhi(void*, void*, int);
void _Z14KeyTable_ResetP14Struct020dfc40(void*);
void _Z20ClearFields_021e20c0Pv(void*);
void* _Z12KeyTable_GetP17Container020e0310i(void*, int);
void _Z25WindowPane_AllocateBufferP10WindowPaneP13SafeAllocatorij(void*, void*, int, int);
void _Z23ClearAllBuffers0207fcb8P11Obj0207fcb8(void*);
void _Z20Background_SetScrollP18BackgroundGraphicsii(void*, int, int);
void _Z24SetEntryScaledXY020807fcPviii(void*, int, int, int);
void _Z21Background_SetMapSizePhi(void*, int);
void* _Z21TextQueue_GetInstancev(void);
void* _Z25MessageSystem_GetInstancev(void);
void _Z27GetEntryFieldsAt0x602080828PviPsS0_(void*, short, short*, short*);
void _Z27GetEntryFieldsAt0xE02080878PviPsS0_(void*, int, short*, short*);
void _Z27SetEntryFieldsAt0x602080854Pviii(void*, short, int, int);
void _Z27SetEntryFieldsAt0xE020808a4Pviii(void*, int, int, int);
void _Z28CallFunc0204b04cOverList0x2cP12Cont0207fd44(void*);
void _Z28CallFunc0204b088OverList0x2cP12Cont0207fd88(void*);
void _Z28CallFunc0204c804OverAllElemsP12Cont0207fe44(void*);
int _Z28CountNonZeroEntries_0215570cP11Obj0215570c(void*);
int _Z29LookupValueByEntryKey02081010Pvi(void*, int);
void _Z15TextQueue_ResetP11Obj020d7aa0(void*);
void _Z22Background_AllocateMapP18BackgroundGraphicsP13SafeAllocator(void*, void*);
void _Z28NameText_InitFromPartyMemberPvi(void*, int);
void _Z32GetSublistEntryScaledXY_020807c4PviPsS0_(void*, int, short*, short*);
void _Z35SetFieldsFromFormattedValue0207f914P11Obj0207f914iii(void*, void*, const char*, const char*);
int _Z39IsCombatantFlagit2Set_02155f88_02155f88Pvi(void*, int);
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
    unsigned char unknown_0_[2];
};
extern const Struct_ov003_0217f29c data_ov003_0217f29c[];
extern const short data_ov003_0217f2a0[];
extern const short data_ov003_0217f2ae[];

struct Struct_02000c9c_82 {
    unsigned char unknown_0_0_ : 4;
    unsigned char unknown_0_4_ : 4;
};

struct Ctrl {
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
    char pad70[0x78 - 0x70];
    short f78;
    char pad7a[2];
    char f7c;
    char pad7d[0xe4 - 0x7d];
    char sube4[0xfc - 0xe4];
    char subfc[0x114 - 0xfc];
    char sub114[kTaskOffset - 0x114];
    int task;
    char pad1d4[0x1ec - 0x1d4];
    short f1ec;
    short f1ee;
    char f1f0[2];
    unsigned char f1f2;
    char pad1f3[4];
    char f1f7;
    unsigned char mode;
    unsigned char state;
    char pad1fa;
    unsigned char f1fb;
    unsigned int flags;
};

// USA: func_ov003_021560e4
extern "C" ARM void func_ov003_021560e4(Struct_ov003_021560e4* arg0) {
    char* var0;
    int var1;
    BackgroundLoader* var2;
    var2 = BackgroundLoader::GetInstance();
    var1 = arg0->unknown_1f9_;

    if (state == 0) {
        if (self->flags & 1) {
            _Z15TextQueue_ResetP11Obj020d7aa0(_Z21TextQueue_GetInstancev());
        }
        func_ov003_02156054(self);
        FontBankLoader* g = FontBankLoader_GetInstance();
        FontBankLoader_CancelLoads(g);
        BlankFunction02094b34(g, 0x66, 0x1f5, 0, 0);
        self->state = self->state + 1;
    } else if (state == 1) {
        if (AlwaysTrue02094b4c(FontBankLoader_GetInstance())) {
#if defined(jpn)
            arg0->unknown_1d0_ = var2->QueueLoadFile(data_ov003_0217e554, 0);
#else
            arg0->unknown_1d0_ = var2->QueueLoadFileInGP2(data_ov003_0217fce4, data_ov003_0217fcfe, 0);
#endif
            arg0->unknown_1f9_ = arg0->unknown_1f9_ + 1;
        }
    } else if (state == 2) {
        if (loader->GetTaskStatus(self->task)) {
            int tmp[3];
            void* file;
            unsigned int size;
            loader->GetLoadedFileByID(self->task, &file, &size);
            void* a = self->alloc;
            _ZN13SafeAllocator5ResetEv(a);
            _Z14KeyTable_ResetP14Struct020dfc40(self->sube4);
            KeyTable_Load(self->sube4, a, file, size);
            loader->RemoveTask(self->task);
            self->task = -1;
            char* g = (char*)_Z25MessageSystem_GetInstancev();
            int key = -1;
            if (self->flags & 1) {
                key = 0x1a;
                char* x = (char*)GetGameResources();
                int id = *(short*)(*(char**)(x + 0x3000 + kPartyResourceOffset) + 0x22);
                GameState* gs = GameState::GetInstance();
                GameObject* pm = gs->GetPartyMemberByIndex(id);
                if (pm == 0) {
                    pm = gs->GetPartyMemberByIndex(_Z29GameState_GetProtagonistIndexP9GameState(gs));
                }
                func_02046380(var8);
#if defined(jpn)
                if (pm != 0) {
                    _Z31MessageSystem_SetStringArgumentP11Obj02046574iPc(g, 0, *(char**)((char*)pm + 0x134));
                }
#else
                _Z28NameText_InitFromPartyMemberPvi(tmp, pm->obj3D_.actorIndex_);
                *(void**)g = tmp;
#endif
            } else {
                char* x = (char*)Scenario_GetInstance();
                if (_Z17Scenario_TestFlagiPhi(x, x + 0x8c, 0x799)) {
                    key = 0;
                } else {
                    arg0->unknown_1ec_ = 0;
                    arg0->unknown_1ee_ = 1;
                    arg0->unknown_1f8_ = 7;
                }
            }
            void* r = _Z12KeyTable_GetP17Container020e0310i(self->sube4, key);
            if (r) {
#if defined(jpn)
                func_0204500c(var8, var15, 0);
#else
                func_0204500c(var8, var15, 0, 0xe3);
#endif
                *(int*)(var8 + Enum_ov003_021560e4_2456) = 1;
                *(int*)(var8 + Enum_ov003_021560e4_2456 + 4) = 1;
            }
            _Z18SpriteContext_InitPc(self->sub2c);
            self->f7c = 0;
            self->f6c = self->f24;
            self->f78 = 10;
            if (self->f1c) {
                self->f68 = *(int*)((char*)self->f1c + 0x20);
            }
#if defined(jpn)
            arg0->unknown_1d0_ = var2->QueueLoadFile(data_ov003_0217e56e, 0);
#else
            arg0->unknown_1d0_ = var2->QueueLoadFileInGP2(data_ov003_0217fd0f, data_ov003_0217fd23, 0);
#endif
            arg0->unknown_1f9_ = arg0->unknown_1f9_ + 1;
        }
    } else if (state == 3) {
        if (loader->GetTaskStatus(self->task)) {
            void* p;
            void* file;
            unsigned int size;
            int len;
            loader->GetLoadedFileByID(self->task, &file, &size);
            int n = _Z14Pac_CountFilesP9PacRecord(file);
            a = (char*)self->alloc;
            _ZN13SafeAllocator5ResetEv(a + 0x3c);
            for (int i = 0; i < n; i++) {
                void* rec = (void*)_Z11Pac_GetFileP9PacRecordiPPvPi(file, i, &p, &len);
                SpriteContext_LoadFile(self->sub2c, rec, len, a + 0x3c);
            }
            loader->RemoveTask(self->task);
            self->task = -1;
            a = (char*)self->alloc;
            _ZN13SafeAllocator5ResetEv(a + 0x14);
            BytePair A = data_ov003_0217f29c[0];
            BytePair B = data_ov003_0217f29c[1];
            for (unsigned char i = 0; i < 2; i++) {
                BackgroundGraphics* e = self->f10 + i;
                _Z21Background_SetMapSizePhi(e, 0);
                e->subScreen_ = 0;
                e->bgNumber_ = A.v[i];
                Background_SetPriority(e, B.v[i]);
                _Z22Background_AllocateMapP18BackgroundGraphicsP13SafeAllocator(e, a + 0x14);
                _Z20Background_SetScrollP18BackgroundGraphicsii(e, 0, 0);
            }
            *(volatile unsigned short*)0x400000a = (*(volatile unsigned short*)0x400000a & 0x43) | 0x1e00;
            *(volatile unsigned short*)0x400000c = (*(volatile unsigned short*)0x400000c & 0x43) | 0x1f00;
            ColorEffect_ConfigureAlphaBlend(0x4000050, 4, 1, 10, 6);
            arg0->unknown_1d0_ = var2->QueueLoadFile(data_ov003_0217fd33, 0);
            arg0->unknown_1f9_ = arg0->unknown_1f9_ + 1;
        }
    } else if (state == 4) {
        if (loader->GetTaskStatus(self->task)) {
            void* p;
            void* file;
            unsigned int size;
            int len;
            loader->GetLoadedFileByID(self->task, &file, &size);
            int n = _Z14Pac_CountFilesP9PacRecord(file);
            BackgroundGraphics* e = self->f10;
            for (int i = 0; i < n; i++) {
                void* rec = (void*)_Z11Pac_GetFileP9PacRecordiPPvPi(file, i, &p, &len);
                Background_LoadFile(e, rec, 0, len);
            }
            loader->RemoveTask(self->task);
            self->task = -1;
            char* a = (char*)self->alloc;
            for (unsigned char j = 0; j < 3; j++) {
                Node0207f7f0* ent = self->f14 + j;
                _Z25WindowPane_AllocateBufferP10WindowPaneP13SafeAllocatorij(ent, a + 0x14, self->f0c, 0x4cc);
                ent->lists = self->f10;
            }
            var35 = (char*)arg0->unknown_0_;
            _ZN13SafeAllocator5ResetEv(var35 + 0x28);
#if defined(jpn)
            func_02080654(arg0->unknown_18_, var35 + 0x28, data_ov003_0217e595);
#else
            func_0207f914(arg0->unknown_18_, var35 + 0x28, data_ov003_0217fd46, data_ov003_0217fd60);
#endif
            arg0->unknown_1f9_ = arg0->unknown_1f9_ + 1;
        }
    } else if (var1 == 5) {
        int var38 = func_0207f9f4(arg0->unknown_18_);
        if (var38 == 0) {
            arg0->unknown_1f9_ = arg0->unknown_1f9_ + 1;
        }
        if (var38 < 0) {
            arg0->unknown_1f8_ = 7;
        }
    } else if (var1 == 6) {
        void* var39 = arg0->unknown_18_;
#if !defined(jpn)
        short x, y, w, h;
        _Z32GetSublistEntryScaledXY_020807c4PviPsS0_(p, 2, &x, &y);
        _Z27GetEntryFieldsAt0xE02080878PviPsS0_(p, 2, &w, &h);
        int mx = 0;
        for (int k = 0; k < 2; k++) {
            int v = Font_GetTextWidth(_Z29LookupValueByEntryKey02081010Pvi(p, data_ov003_0217f2a0[k]), 0);
            if (mx < v) mx = v;
        }
        var42 = (var44 + 0x1b) & ~7;
        var42 = var42 >> 3;
        if (var42 & 1) var42 = var42 + 1;
        var40 = (0x20 - var42) >> 1;
        var40 = var40 << 3;
        func_020807fc(var39, 2, var40, var41);
        func_020808a4(var39, 2, var42, var43);
#endif
        if (func_ov003_0215570c(arg0) >= 9) {
            for (unsigned char var47 = 0; var47 < 12; var47++) {
                for (int var48 = 0; var48 < 3; var48++) {
                    int var49 = var47 + data_ov003_0217f2ae[var48];
                    short var50, var51;
                    func_02080828(var39, var49, &var50, &var51);
                    func_02080854(var39, var49, var50, (short)(var51 - 1));
                }
            }
        }
#if defined(jpn)
            arg0->unknown_1d0_ = var2->QueueLoadFile(data_ov003_0217e5b3, 0);
#else
        arg0->unknown_1d0_ = var2->QueueLoadFileInGP2(data_ov003_0217fd68, data_ov003_0217fd7e, 0);
#endif
        arg0->unknown_1f9_ = arg0->unknown_1f9_ + 1;
    } else if (var1 == 7) {
        if (var2->GetTaskStatus(arg0->unknown_1d0_)) {
            void* var52;
            unsigned int var53;
            var2->GetLoadedFileByID(arg0->unknown_1d0_, &var52, &var53);
            if (var52) {
                char* var54 = (char*)arg0->unknown_0_;
                _ZN13SafeAllocator5ResetEv(var54 + 0x50);
                func_ov023_021e20c0(arg0->unknown_114_);
                func_ov023_021e20f0(arg0->unknown_114_, var54 + 0x50, var52, var53);
            }
            var2->RemoveTask(arg0->unknown_1d0_);
            arg0->unknown_1d0_ = -1;
#if defined(jpn)
            arg0->unknown_1d0_ = var2->QueueLoadFile(data_ov003_0217e5c9, 0);
#else
            arg0->unknown_1d0_ = var2->QueueLoadFileInGP2(data_ov003_0217fd90, data_ov003_0217fdaa, 0);
#endif
            arg0->unknown_1f9_ = arg0->unknown_1f9_ + 1;
        }
    } else if (state == 8) {
        if (loader->GetTaskStatus(self->task)) {
            void* file;
            unsigned int size;
            loader->GetLoadedFileByID(self->task, &file, &size);
            if (file) {
                void* a = self->alloc;
                _Z14KeyTable_ResetP14Struct020dfc40(self->subfc);
                KeyTable_Load(self->subfc, a, file, size);
            }
            var2->RemoveTask(arg0->unknown_1d0_);
            arg0->unknown_1d0_ = -1;
            arg0->unknown_1f9_ = arg0->unknown_1f9_ + 1;
        }
    } else if (state == 9) {
        char* g = (char*)_Z25MessageSystem_GetInstancev();
        if (*(int*)(g + kGlobalFieldOffset + 8) == 3) {
            Manager0207f7f0* p = self->f18;
            p->lists = self->f10;
            p->mode = 2;
            InitNodeChain0207f7f0(p, self->f14, 3);
            p->active = 1;
            _Z23ClearAllBuffers0207fcb8P11Obj0207fcb8(p);
            _Z28CallFunc0204b04cOverList0x2cP12Cont0207fd44(p);
            _Z28CallFunc0204b088OverList0x2cP12Cont0207fd88(p);
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
                if (self->f1fb == 0) {
                    self->f1f7 = _Z29GameState_GetProtagonistIndexP9GameState(gs);
                    self->state = 0;
                    if (_Z39IsCombatantFlagit2Set_02155f88_02155f88Pvi(self, self->f1f7)) {
                        self->f1ec = 8;
                        self->mode = 7;
                        _Z28CallFunc0204c804OverAllElemsP12Cont0207fe44(p);
                    } else {
                        arg0->unknown_1fc_ = arg0->unknown_1fc_ | 2;
                        arg0->unknown_1ec_ = 9;
                        arg0->unknown_1f8_ = 3;
                        arg0->unknown_1f9_ = 0;
                    }
                } else {
                    arg0->unknown_1f7_ = arg0->unknown_1f2_;
                    arg0->unknown_1ec_ = 6;
                    arg0->unknown_1f8_ = 2;
                    arg0->unknown_1f9_ = 2;
                }
            } else {
                char* x = (char*)Scenario_GetInstance();
                if (_Z17Scenario_TestFlagiPhi(x, x + 0x8c, 0x796)) {
                    self->f1ec = 4;
                    self->mode = 1;
                } else {
                    arg0->unknown_1ec_ = 2;
                    arg0->unknown_1f8_ = 2;
                }
            }
        }
    }
}
