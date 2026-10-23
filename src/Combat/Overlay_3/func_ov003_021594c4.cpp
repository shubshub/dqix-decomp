#include <globaldefs.h>
#include <std_library_functions.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "NitroSDK/ColorEffects.h"
#include "NitroSDK/Graphics.h"

#if defined(jpn)
enum { Enum_ov003_021594c4_2152 = 0x868 };
enum { Enum_ov003_021594c4_2160 = 0x870 };
#else
enum { Enum_ov003_021594c4_2456 = 0x998 };
enum { Enum_ov003_021594c4_2464 = 0x9a0 };
#endif

struct Struct_ov003_021594c4 {
    char unknown_0_[0x1c];
    unsigned char unknown_1c_0_ : 4;
    unsigned char unknown_1c_4_ : 4;
    unsigned char unknown_1d_;
    char unknown_1e_[2];
};

struct Struct_ov003_021594c4_3 {
    char unknown_0_[4];
    Struct_ov003_021594c4* unknown_4_;
    char unknown_8_[0xe0 - 8];
};

struct Struct_ov003_021594c4_4 {
    unsigned char unknown_0_[2];
};

struct Struct_ov003_0217f380 {
    Struct_ov003_021594c4_4 unknown_0_;
    Struct_ov003_021594c4_4 unknown_2_;
};

struct Struct_0201099c_3;
struct Struct_02020cb8_5;
struct Struct_0204b12c;
struct Struct_02020aec;
struct Struct_02020cb8_4;
struct Struct_02020cb8_2;
struct Struct_0204c7a8;
struct Struct_0205cf78;
struct Struct_0205cf78_2;
struct Struct_ov003_0215917c;

int GetGlobalField0x1c020421a0();
extern "C" void func_ov017_021d243c(int a);
extern "C" void KeyTable_Load(void* container, SafeAllocator* alloc, void* data, unsigned int size);
const char* KeyTable_Get(Container020e0310* container, int key);
extern "C" int func_02005a94(const char* string);
extern "C" void func_ov003_02159250(void* self, void* text);
extern "C" void func_ov003_02159464(void* self);
void Background_SetMapSize(unsigned char* background, int value);
extern "C" void Background_SetPriority(BackgroundGraphics* background, int screen);
void Background_AllocateMap(AllocTarget0204b12c* background, SafeAllocator* allocator);
void Background_SetScroll(Obj0204b5e8* background, int a, int b);
int Pac_CountFiles(ActiveEntry02046900* archive);
void* Pac_GetFile(Rec020467f0* archive, int index, void** name, int* size);
extern "C" void Background_LoadFile(BackgroundGraphics* background, void* file, SafeAllocator* allocator, unsigned int size);
extern "C" void Background_FillRect(BackgroundGraphics* background, int a, int b, int c, int d, int e, int f);
void Background_UploadMap(List0204b0e8* background, void* a);
void WindowPane_AllocateBuffer(Obj0204c7a8* obj, SafeAllocator* alloc, int val, unsigned int len);
void Window_SetPanes(Struct_0205cf78* s, Elem_0205cf78* arr, unsigned char count);
extern "C" void SpriteContext_LoadFile(void* table, void* file, int size, SafeAllocator* alloc);
int CompareStrings_020d3018(const char* a, const char* b);
void AppendFlagEvents_0215917c(QueueStruct0215917c* obj, int flags);
unsigned char CopyOutRegion0x5718_02011494(char* obj, void* dst);

#if defined(jpn)
#include "Filesystem/FileIO.h"
extern char data_ov003_0217e649[];
#else
extern char data_ov003_0217fe2d[];
extern char data_ov003_0217fe48[];
#endif
extern char data_ov003_0217fe5a[];
extern const Struct_ov003_0217f380 data_ov003_0217f380;
extern char data_ov003_0217fe6b[];
extern char data_ov003_0217fe7e[];

struct Struct_ov003_021594c4_2 {
    SafeAllocator unknown_0_[4];
    char unknown_50_[0x64 - 0x50];
    char unknown_64_[0x7c - 0x64];
    void* unknown_7c_;
    char unknown_80_[0x98 - 0x80];
    char unknown_98_[0xd4 - 0x98];
    int unknown_d4_;
    int unknown_d8_;
    char unknown_dc_[0xe4 - 0xdc];
    short unknown_e4_;
    char unknown_e6_[2];
    unsigned char unknown_e8_;
    char unknown_e9_[3];
    int unknown_ec_;
    int unknown_f0_;
    char unknown_f4_[0x18c - 0xf4];
    Struct_ov003_021594c4* unknown_18c_;
    char unknown_190_[0x1a6 - 0x190];
    unsigned char unknown_1a6_;
    char unknown_1a7_[0x1b0 - 0x1a7];
    Struct_ov003_021594c4 unknown_1b0_[2];
    Struct_ov003_021594c4_3 unknown_1f0_[4];
    char unknown_570_[0x578 - 0x570];
    int unknown_578_;
    void* unknown_57c_;
    unsigned char unknown_580_;
    char unknown_581_[0x587 - 0x581];
    unsigned char unknown_587_;
    unsigned char unknown_588_;
    char unknown_589_[0x590 - 0x589];
    unsigned char unknown_590_;
    char unknown_591_[0x59d - 0x591];
    unsigned char unknown_59d_;
    unsigned char unknown_59e_;
    char unknown_59f_;
    unsigned char unknown_5a0_;
    char unknown_5a1_[0x5b1 - 0x5a1];
    unsigned char unknown_5b1_;
    unsigned char unknown_5b2_;
    char unknown_5b3_;
    unsigned char unknown_5b4_;
};

// USA: func_ov003_021594c4
extern "C" ARM void func_ov003_021594c4(Struct_ov003_021594c4_2* arg0) {
#if defined(jpn)
    BackgroundLoader* var0 = BackgroundLoader::GetInstance();
    int var1 = func_020421a0();
    unsigned char var2 = arg0->unknown_580_;

    if (var2 == 0) {
        arg0->unknown_7c_ = *(void**)(func_020421a0() + 0x28);
        func_ov017_021d243c(1);
        self->allocators_[2].Reset();
        void* data = self->allocators_[2].Allocate(0x4000);
        char name[0x40];
        unsigned int size;
        sprintf(name, data_ov003_0217e649, self->mode_);
        LoadFileIntoMemory(name, data, &size);
        self->allocators_[0].Reset();
        KeyTable_Load(self->strings_, &self->allocators_[0], data, size);
        const char* str = KeyTable_Get((Container020e0310*)self->strings_, 0x32);
        if (str != NULL) {
            self->unk_5b1 = func_02005a94(str);
        }
        if (arg0->unknown_5b1_ == 3) {
            arg0->unknown_5b1_ = 0;
            arg0->unknown_5b2_ = 0;
        }
        *(int*)(var1 + Enum_ov003_021594c4_2152) = 1;
        *(unsigned char*)(var1 + 0x17ef) = 1;
        *(unsigned char*)(var1 + 0x17ff) |= 2;
        func_ov003_02159250(arg0, arg0->unknown_7c_);
        if (arg0->unknown_5a0_ == 2 || arg0->unknown_587_ == 1 || arg0->unknown_587_ == 2) {
            if (arg0->unknown_5a0_ == 2) {
                arg0->unknown_5b4_ = 1;
                arg0->unknown_580_ = 2;
                arg0->unknown_578_ = var0->QueueLoadFile(data_ov003_0217fe5a, NULL);
                *(int*)(func_020421a0() + Enum_ov003_021594c4_2152) = 1;
            } else {
                arg0->unknown_588_ = 10;
                arg0->unknown_580_ = 0;
            }
            arg0->unknown_59d_ = 1;
            arg0->unknown_59e_ = 0;
            func_ov003_02159464(arg0);
            return;
        }
        BackgroundPair priority = data_ov003_0217f380.priority;
        BackgroundPair screen = data_ov003_0217f380.screen;
        BackgroundGraphics* background;
        for (int i = 0; i < 2; i++) {
            background = &self->backgrounds_[i];
            Background_SetMapSize((unsigned char*)background, 0);
            background->unk_1c_0_ = 0;
            background->unk_1c_4_ = priority.v[i];
            Background_SetPriority(background, screen.v[i]);
            Background_AllocateMap((AllocTarget0204b12c*)background, &self->allocators_[1]);
            Background_SetScroll((Obj0204b5e8*)background, 0, 0);
        }
        BG1CNT = (BG1CNT & 0x43) | 0x1d00;
        BG2CNT = (BG2CNT & 0x43) | 0x1e00;
        ColorEffect_ConfigureAlphaBlend(0x4000050, 2, 1, 10, 6);
        arg0->unknown_578_ = var0->QueueLoadFile(data_ov003_0217fe6b, NULL);
        arg0->unknown_580_++;
    }

    if (state == 1) {
        BackgroundLoader* loader2 = BackgroundLoader::GetInstance();
        if (loader2->GetTaskStatus(self->task_) != 0) {
            char name[4];
            void* archive;
            unsigned int archiveSize;
            void* files[2];
            int sizes[2];
            loader2->GetLoadedFileByID(self->task_, &archive, &archiveSize);
            int count = Pac_CountFiles((ActiveEntry02046900*)archive);
            for (int i = 0; i < count; i++) {
                files[i] = Pac_GetFile((Rec020467f0*)archive, i, (void**)name, &sizes[i]);
            }
            for (int i = 0; i < count; i++) {
                if (files[i] != NULL) {
                    Background_LoadFile(&self->backgrounds_[1], files[i], &self->allocators_[1], sizes[i]);
                }
            }
            loader2->RemoveTask(self->task_);
            self->task_ = -1;
            BackgroundGraphics* background;
            for (int i = 0; i < 2; i++) {
                background = &self->backgrounds_[i];
                Background_FillRect(background, 0, 0, 0, 0x20, 0x19, 0);
                Background_UploadMap((List0204b0e8*)background, 0);
            }
            self->allocators_[2].Reset();
            self->buffer_ = self->allocators_[2].Allocate(0x4000);
            for (int i = 0; i < 4; i++) {
                BackgroundLayer* layer = &self->layers_[i];
                WindowPane_AllocateBuffer((Obj0204c7a8*)layer, &self->allocators_[1], (int)self->buffer_, 0x400);
                layer->graphics = &self->backgrounds_[1];
            }
            self->graphics_ = &self->backgrounds_[0];
            self->unk_1a6 = 2;
            Window_SetPanes((Struct_0205cf78*)self->list_, (Elem_0205cf78*)self->layers_, 4);
            self->task_ = loader2->QueueLoadFile(data_ov003_0217fe5a, NULL);
            self->state_++;
        }
    }

    if (state == 2) {
        if (loader->GetTaskStatus(self->task_) != 0) {
            char name[4];
            void* archive;
            unsigned int archiveSize;
            int size;
            self->unk_e8 = 0;
            self->unk_d8 = self->unk_ec;
            self->unk_e4 = 0xe;
            self->unk_d4 = self->unk_f0;
            loader->GetLoadedFileByID(self->task_, &archive, &archiveSize);
            int count = Pac_CountFiles((ActiveEntry02046900*)archive);
            self->allocators_[3].Reset();
            for (int i = 0; i < count; i++) {
                void* file = Pac_GetFile((Rec020467f0*)archive, i, (void**)name, &size);
                SpriteContext_LoadFile(self->table_, file, size, &self->allocators_[3]);
            }
            var0->RemoveTask(arg0->unknown_578_);
            arg0->unknown_578_ = -1;
            if (arg0->unknown_5b4_ != 0) {
                arg0->unknown_588_ = 3;
                arg0->unknown_580_ = 0;
                return;
            }
            arg0->unknown_59d_ = 1;
            arg0->unknown_59e_ = 0;
            func_ov003_02159464(arg0);
            arg0->unknown_580_++;
        }
    }

    if (var2 == 3 && *(int*)(var1 + Enum_ov003_021594c4_2160) == 3) {
        arg0->unknown_59d_ = 1;
        BG0CNT = (BG0CNT & ~3) | 2;
        BG1CNT = (BG1CNT & ~3) | 1;
        BG2CNT = (BG2CNT & ~3);
        BG3CNT = (BG3CNT & ~3) | 3;
        DISPCNT = (DISPCNT & ~0x1f00) | 0x1700;
        unsigned char flags = 0x3f;
        for (int i = 0; i < 6; i++) {
            const char* str = KeyTable_Get((Container020e0310*)self->strings_, (short)i);
            if (CompareStrings_020d3018(data_ov003_0217fe7e, str) == 0) {
                flags &= ~(1 << i);
            }
        }
        func_ov003_0215917c((Struct_ov003_0215917c*)arg0, var31);
        arg0->unknown_590_ = func_02011494((char*)GameState::GetInstance(), arg0->unknown_591_);
        arg0->unknown_588_ = 1;
        arg0->unknown_580_ = 1;
    }
#else
    BackgroundLoader* var34 = BackgroundLoader::GetInstance();
    int var35 = func_020421a0();
    unsigned char var36 = arg0->unknown_580_;

    if (var36 == 0) {
        arg0->unknown_7c_ = *(void**)(func_020421a0() + 0x5c);
        func_ov017_021d243c(1);
        char var37[0x40];
        char var38[0x18];
        sprintf(var37, data_ov003_0217fe2d, arg0->unknown_5a0_);
        sprintf(var38, data_ov003_0217fe48, arg0->unknown_5a0_);
        arg0->unknown_578_ = var34->QueueLoadFileInGP2(var37, var38, NULL);
        arg0->unknown_580_++;
    }

    if (state == 1) {
        if (loader->GetTaskStatus(self->task_) == 0) return;
        void* data;
        unsigned int size;
        loader->GetLoadedFileByID(self->task_, &data, &size);
        self->allocators_[0].Reset();
        KeyTable_Load(self->strings_, &self->allocators_[0], data, size);
        loader->RemoveTask(self->task_);
        self->task_ = -1;
        const char* str = KeyTable_Get((Container020e0310*)self->strings_, 0x32);
        if (str != NULL) {
            self->unk_5b1 = func_02005a94(str);
        }
        if (arg0->unknown_5b1_ == 3) {
            arg0->unknown_5b1_ = 0;
            arg0->unknown_5b2_ = 0;
        }
        *(int*)(var35 + Enum_ov003_021594c4_2456) = 1;
        *(unsigned char*)(var35 + 0x19bf) = 1;
        *(unsigned char*)(var35 + 0x19cf) = 1;
        func_ov003_02159250(arg0, arg0->unknown_7c_);
        if (arg0->unknown_5a0_ == 2 || arg0->unknown_587_ == 1 || arg0->unknown_587_ == 2) {
            if (arg0->unknown_5a0_ == 2) {
                arg0->unknown_5b4_ = 1;
                arg0->unknown_580_ = 3;
                arg0->unknown_578_ = var34->QueueLoadFile(data_ov003_0217fe5a, NULL);
                *(int*)(func_020421a0() + Enum_ov003_021594c4_2456) = 1;
            } else {
                arg0->unknown_588_ = 10;
                arg0->unknown_580_ = 0;
            }
            arg0->unknown_59d_ = 1;
            arg0->unknown_59e_ = 0;
            func_ov003_02159464(arg0);
            return;
        }
        BackgroundPair priority = data_ov003_0217f380.priority;
        BackgroundPair screen = data_ov003_0217f380.screen;
        BackgroundGraphics* background;
        for (int i = 0; i < 2; i++) {
            background = &self->backgrounds_[i];
            Background_SetMapSize((unsigned char*)background, 0);
            background->unk_1c_0_ = 0;
            background->unk_1c_4_ = priority.v[i];
            Background_SetPriority(background, screen.v[i]);
            Background_AllocateMap((AllocTarget0204b12c*)background, &self->allocators_[1]);
            Background_SetScroll((Obj0204b5e8*)background, 0, 0);
        }
        BG1CNT = (BG1CNT & 0x43) | 0x1d00;
        BG2CNT = (BG2CNT & 0x43) | 0x1e00;
        ColorEffect_ConfigureAlphaBlend(0x4000050, 2, 1, 10, 6);
        arg0->unknown_578_ = var34->QueueLoadFile(data_ov003_0217fe6b, NULL);
        arg0->unknown_580_++;
    }

    if (state == 2) {
        BackgroundLoader* loader2 = BackgroundLoader::GetInstance();
        if (loader2->GetTaskStatus(self->task_) != 0) {
            char name[4];
            void* archive;
            unsigned int archiveSize;
            void* files[2];
            int sizes[2];
            loader2->GetLoadedFileByID(self->task_, &archive, &archiveSize);
            int count = Pac_CountFiles((ActiveEntry02046900*)archive);
            for (int i = 0; i < count; i++) {
                files[i] = Pac_GetFile((Rec020467f0*)archive, i, (void**)name, &sizes[i]);
            }
            for (int i = 0; i < count; i++) {
                if (files[i] != NULL) {
                    Background_LoadFile(&self->backgrounds_[1], files[i], &self->allocators_[1], sizes[i]);
                }
            }
            loader2->RemoveTask(self->task_);
            self->task_ = -1;
            BackgroundGraphics* background;
            for (int i = 0; i < 2; i++) {
                background = &self->backgrounds_[i];
                Background_FillRect(background, 0, 0, 0, 0x20, 0x19, 0);
                Background_UploadMap((List0204b0e8*)background, 0);
            }
            self->allocators_[2].Reset();
            self->buffer_ = self->allocators_[2].Allocate(0x4000);
            for (int i = 0; i < 4; i++) {
                BackgroundLayer* layer = &self->layers_[i];
                WindowPane_AllocateBuffer((Obj0204c7a8*)layer, &self->allocators_[1], (int)self->buffer_, 0x400);
                layer->graphics = &self->backgrounds_[1];
            }
            self->graphics_ = &self->backgrounds_[0];
            self->unk_1a6 = 2;
            Window_SetPanes((Struct_0205cf78*)self->list_, (Elem_0205cf78*)self->layers_, 4);
            self->task_ = loader2->QueueLoadFile(data_ov003_0217fe5a, NULL);
            self->state_++;
        }
    }

    if (state == 3) {
        if (loader->GetTaskStatus(self->task_) != 0) {
            char name[4];
            void* archive;
            unsigned int archiveSize;
            int size;
            self->unk_e8 = 0;
            self->unk_d8 = self->unk_ec;
            self->unk_e4 = 0xe;
            self->unk_d4 = self->unk_f0;
            loader->GetLoadedFileByID(self->task_, &archive, &archiveSize);
            int count = Pac_CountFiles((ActiveEntry02046900*)archive);
            self->allocators_[3].Reset();
            for (int i = 0; i < count; i++) {
                void* file = Pac_GetFile((Rec020467f0*)archive, i, (void**)name, &size);
                SpriteContext_LoadFile(self->table_, file, size, &self->allocators_[3]);
            }
            var34->RemoveTask(arg0->unknown_578_);
            arg0->unknown_578_ = -1;
            if (arg0->unknown_5b4_ != 0) {
                arg0->unknown_588_ = 3;
                arg0->unknown_580_ = 0;
                return;
            }
            arg0->unknown_59d_ = 1;
            arg0->unknown_59e_ = 0;
            func_ov003_02159464(arg0);
            arg0->unknown_580_++;
        }
    }

    if (var36 == 4 && *(int*)(var35 + Enum_ov003_021594c4_2464) == 3) {
        arg0->unknown_59d_ = 1;
        BG0CNT = (BG0CNT & ~3) | 2;
        BG1CNT = (BG1CNT & ~3) | 1;
        BG2CNT = (BG2CNT & ~3);
        BG3CNT = (BG3CNT & ~3) | 3;
        DISPCNT = (DISPCNT & ~0x1f00) | 0x1700;
        unsigned char flags = 0x3f;
        for (int i = 0; i < 6; i++) {
            const char* str = KeyTable_Get((Container020e0310*)self->strings_, (short)i);
            if (CompareStrings_020d3018(data_ov003_0217fe7e, str) == 0) {
                flags &= ~(1 << i);
            }
        }
        func_ov003_0215917c((Struct_ov003_0215917c*)arg0, var66);
        arg0->unknown_590_ = func_02011494((char*)GameState::GetInstance(), arg0->unknown_591_);
        arg0->unknown_588_ = 1;
        arg0->unknown_580_ = 1;
    }
#endif
}
