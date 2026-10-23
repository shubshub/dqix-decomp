#include "Combat/MenuNodeChain.h"
#include "Combat/MapDisplay.h"
#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

#if defined(jpn)
#define func_0205ec34 func_0205ff20
#endif

#if defined(jpn)
enum { Enum_ov003_021560e4_464 = 0x1cc, Enum_ov003_021560e4_1820 = 0x50c, Enum_ov003_021560e4_2456 = 0x868, Enum_ov003_021560e4_32 = 0x20, Enum_ov003_021560e4_44 = 0x2c, Enum_ov003_021560e4_46 = 0x2e };
extern "C" void func_02046574(void*, int, char*);
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
int _Z11Pac_GetFileP11Rec020467f0iPPvPi(void*, int, void**, int*);
int _Z14Pac_CountFilesP19ActiveEntry02046900(void*);
int _Z27GetField0x3acValue_020100a8P9GameState(void*);
void _Z18SpriteContext_InitPc(void*);
int _Z27TestBitInByteArray_0206dfb0iPhi(void*, void*, int);
void _Z14KeyTable_ResetP14Struct020dfc40(void*);
void _Z20ClearFields_021e20c0Pv(void*);
void* _Z12KeyTable_GetP17Container020e0310i(void*, int);
void _Z25WindowPane_AllocateBufferP11Obj0204c7a8P13SafeAllocatorij(void*, void*, int, int);
void _Z23ClearAllBuffers0207fcb8P11Obj0207fcb8(void*);
void _Z20Background_SetScrollP11Obj0204b5e8ii(void*, int, int);
void _Z24SetEntryScaledXY020807fcPviii(void*, int, int, int);
void _Z21Background_SetMapSizePhi(void*, int);
void* _Z25GetGlobalResetObj020d7a50v(void);
void* _Z26GetGlobalField0x1c020421a0v(void);
void _Z27GetEntryFieldsAt0x602080828PviPsS0_(void*, short, short*, short*);
void _Z27GetEntryFieldsAt0xE02080878PviPsS0_(void*, int, short*, short*);
void _Z27SetEntryFieldsAt0x602080854Pviii(void*, short, int, int);
void _Z27SetEntryFieldsAt0xE020808a4Pviii(void*, int, int, int);
void _Z28CallFunc0204b04cOverList0x2cP12Cont0207fd44(void*);
void _Z28CallFunc0204b088OverList0x2cP12Cont0207fd88(void*);
void _Z28CallFunc0204c804OverAllElemsP12Cont0207fe44(void*);
int _Z28CountNonZeroEntries_0215570cP11Obj0215570c(void*);
int _Z29LookupValueByEntryKey02081010Pvi(void*, int);
void _Z29TeardownAndResetState020d7aa0P11Obj020d7aa0(void*);
void _Z22Background_AllocateMapP19AllocTarget0204b12cP13SafeAllocator(void*, void*);
void _Z30InitObjFromCombatantId020e4bf4Pvi(void*, int);
void _Z32GetSublistEntryScaledXY_020807c4PviPsS0_(void*, int, short*, short*);
void _Z35SetFieldsFromFormattedValue0207f914P11Obj0207f914iii(void*, void*, const char*, const char*);
int _Z39IsCombatantFlagit2Set_02155f88_02155f88Pvi(void*, int);
void _ZN13SafeAllocator5ResetEv(void*);
int func_020420e8(int, int);
#if !defined(jpn)
void func_0204500c(void*, void*, int, int);
#endif
void func_02046380(void*);
void Background_LoadFile(void*, void*, int, int);
void Background_SetPriority(void*, int);
void SpriteContext_LoadFile(void*, void*, int, void*);
void* func_0205ec34(void);
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

struct Struct_ov003_021560e4 {
    void* unknown_0_;
    char unknown_4_[0xc - 4];
    int unknown_c_;
    Struct_02020cb8* unknown_10_;
    Struct_0207f7f0_2* unknown_14_;
    Struct_0207f7f0* unknown_18_;
    void* unknown_1c_;
    char unknown_20_[4];
    int unknown_24_;
    char unknown_28_[4];
    char unknown_2c_[0x68 - 0x2c];
    int unknown_68_;
    int unknown_6c_;
    char unknown_70_[0x78 - 0x70];
    short unknown_78_;
    char unknown_7a_[2];
    char unknown_7c_;
    char unknown_7d_[0xe4 - 0x7d];
    char unknown_e4_[0xfc - 0xe4];
    char unknown_fc_[0x114 - 0xfc];
    char unknown_114_[Enum_ov003_021560e4_464 - 0x114];
    int unknown_1d0_;
    char unknown_1d4_[0x1ec - 0x1d4];
    short unknown_1ec_;
    short unknown_1ee_;
    char unknown_1f0_[2];
    unsigned char unknown_1f2_;
    char unknown_1f3_[4];
    char unknown_1f7_;
    unsigned char unknown_1f8_;
    unsigned char unknown_1f9_;
    char unknown_1fa_;
    unsigned char unknown_1fb_;
    unsigned int unknown_1fc_;
};

// USA: func_ov003_021560e4
extern "C" ARM void func_ov003_021560e4(Struct_ov003_021560e4* arg0) {
    char* var0;
    int var1;
    BackgroundLoader* var2;
    var2 = BackgroundLoader::GetInstance();
    var1 = arg0->unknown_1f9_;

    if (var1 == 0) {
        if (arg0->unknown_1fc_ & 1) {
            func_020d7aa0(func_020d7a50());
        }
        func_ov003_02156054(arg0);
        Struct_0208cb08* var3 = func_02094a00();
        func_02094ab0(var3);
        func_02094b34(var3, 0x66, 0x1f5, 0, 0);
        arg0->unknown_1f9_ = arg0->unknown_1f9_ + 1;
    } else if (var1 == 1) {
        if (func_02094b4c(func_02094a00())) {
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
            char* g = (char*)_Z26GetGlobalField0x1c020421a0v();
            int key = -1;
            if (self->flags & 1) {
                key = 0x1a;
                char* x = (char*)GetGameResources();
                int id = *(short*)(*(char**)(x + 0x3000 + kPartyResourceOffset) + 0x22);
                GameState* gs = GameState::GetInstance();
                GameObject* pm = gs->GetPartyMemberByIndex(id);
                if (pm == 0) {
                    pm = gs->GetPartyMemberByIndex(_Z27GetField0x3acValue_020100a8P9GameState(gs));
                }
                func_02046380(var8);
#if defined(jpn)
                if (var13 != 0) {
                    func_02046574(var8, 0, *(char**)((char*)var13 + 0x134));
                }
#else
                func_020e4bf4(var4, var13->obj3D_.unknown_4_);
                *(void**)var8 = var4;
#endif
            } else {
                char* var14 = (char*)func_0205ec34();
                if (func_0206dfb0(var14, var14 + 0x8c, 0x799)) {
                    var9 = 0;
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
            int n = _Z14Pac_CountFilesP19ActiveEntry02046900(file);
            a = (char*)self->alloc;
            _ZN13SafeAllocator5ResetEv(a + 0x3c);
            for (int i = 0; i < n; i++) {
                void* rec = (void*)_Z11Pac_GetFileP11Rec020467f0iPPvPi(file, i, &p, &len);
                SpriteContext_LoadFile(self->sub2c, rec, len, a + 0x3c);
            }
            loader->RemoveTask(self->task);
            self->task = -1;
            a = (char*)self->alloc;
            _ZN13SafeAllocator5ResetEv(a + 0x14);
            BytePair A = data_ov003_0217f29c[0];
            BytePair B = data_ov003_0217f29c[1];
            for (unsigned char i = 0; i < 2; i++) {
                List0204af64* e = self->f10 + i;
                _Z21Background_SetMapSizePhi(e, 0);
                e->b1c_lo = 0;
                e->b1c_hi = A.v[i];
                Background_SetPriority(e, B.v[i]);
                _Z22Background_AllocateMapP19AllocTarget0204b12cP13SafeAllocator(e, a + 0x14);
                _Z20Background_SetScrollP11Obj0204b5e8ii(e, 0, 0);
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
            int n = _Z14Pac_CountFilesP19ActiveEntry02046900(file);
            List0204af64* e = self->f10;
            for (int i = 0; i < n; i++) {
                void* rec = (void*)_Z11Pac_GetFileP11Rec020467f0iPPvPi(file, i, &p, &len);
                Background_LoadFile(e, rec, 0, len);
            }
            loader->RemoveTask(self->task);
            self->task = -1;
            char* a = (char*)self->alloc;
            for (unsigned char j = 0; j < 3; j++) {
                Node0207f7f0* ent = self->f14 + j;
                _Z25WindowPane_AllocateBufferP11Obj0204c7a8P13SafeAllocatorij(ent, a + 0x14, self->f0c, 0x4cc);
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
        short var40, var41, var42, var43;
        func_020807c4(var39, 2, &var40, &var41);
        func_02080878(var39, 2, &var42, &var43);
        int var44 = 0;
        for (int var45 = 0; var45 < 2; var45++) {
            int var46 = func_020420e8(func_02081010(var39, data_ov003_0217f2a0[var45]), 0);
            if (var44 < var46) var44 = var46;
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
    } else if (var1 == 9) {
        char* var58 = (char*)func_020421a0();
        if (*(int*)(var58 + Enum_ov003_021560e4_2456 + 8) == 3) {
            Struct_0207f7f0* var59 = arg0->unknown_18_;
            var59->unknown_2c_ = arg0->unknown_10_;
            var59->unknown_38_ = 2;
            func_0207f7f0(var59, arg0->unknown_14_, 3);
            var59->unknown_3a_ = 1;
            func_0207fcb8(var59);
            func_0207fd44(var59);
            func_0207fd88(var59);
            volatile unsigned short* var60 = (volatile unsigned short*)0x4000008;
            var60[0] = (var60[0] & ~3) | 2;
            var60[1] = var60[1] & ~3;
            var60[2] = (var60[2] & ~3) | 1;
            var60[3] = (var60[3] & ~3) | 3;
            *(volatile unsigned int*)0x4000000 = (*(volatile unsigned int*)0x4000000 & ~0x1f00) | 0x1700;
            arg0->unknown_1f8_ = 7;
            arg0->unknown_1f9_ = 0;
            if (arg0->unknown_1fc_ & 1) {
                GameState* var61 = GameState::GetInstance();
                if (arg0->unknown_1fb_ == 0) {
                    arg0->unknown_1f7_ = func_020100a8(var61);
                    arg0->unknown_1f9_ = 0;
                    if (func_ov003_02155f88(arg0, arg0->unknown_1f7_)) {
                        arg0->unknown_1ec_ = 8;
                        arg0->unknown_1f8_ = 7;
                        func_0207fe44(var59);
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
                char* var62 = (char*)func_0205ec34();
                if (func_0206dfb0(var62, var62 + 0x8c, 0x796)) {
                    arg0->unknown_1ec_ = 4;
                    arg0->unknown_1f8_ = 1;
                } else {
                    arg0->unknown_1ec_ = 2;
                    arg0->unknown_1f8_ = 2;
                }
            }
        }
    }
}
