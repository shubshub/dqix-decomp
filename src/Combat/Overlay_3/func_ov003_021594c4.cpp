#include <globaldefs.h>
#include "Graphics/Background.h"
#include <std_library_functions.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "NitroSDK/ColorEffects.h"
#include "NitroSDK/Graphics.h"

#if defined(jpn)
enum { kRegionValue998_868 = 0x868 };
enum { Enum_ov003_021594c4_2160 = 0x870 };
#else
enum { kRegionValue998_868 = 0x998 };
enum { Enum_ov003_021594c4_2464 = 0x9a0 };
#endif


struct Struct_ov003_021594c4_3 {
    char unk_0[4];
    BackgroundGraphics* graphics;
    char unk_8[0xe0 - 8];
};

struct Struct_ov003_021594c4_4 {
    unsigned char v[2];
};

struct Struct_ov003_0217f380 {
    Struct_ov003_021594c4_4 screen;
    Struct_ov003_021594c4_4 priority;
};

struct Container020e0310;
struct BackgroundGraphics;
struct PacRecord;
struct WindowPane;
struct Struct_0205cf78;
struct WindowPane;
struct Struct_ov003_0215917c;

extern "C" int MessageSystem_GetInstance();
extern "C" void func_ov017_021d243c(int a);
extern "C" void KeyTable_Load(void* container, SafeAllocator* alloc, void* data, unsigned int size);
extern "C" const char* KeyTable_Get(Container020e0310* container, int key);
extern "C" int func_02005a94(const char* string);
extern "C" void func_ov003_02159250(void* self, void* text);
extern "C" void func_ov003_02159464(void* self);
extern "C" void Background_SetMapSize(unsigned char* background, int value);
extern "C" void Background_SetPriority(BackgroundGraphics* background, int screen);
extern "C" void Background_AllocateMap(BackgroundGraphics* background, SafeAllocator* allocator);
extern "C" void Background_SetScroll(BackgroundGraphics* background, int a, int b);
extern "C" int Pac_CountFiles(PacRecord* archive);
extern "C" void* Pac_GetFile(PacRecord* archive, int index, void** name, int* size);
extern "C" void Background_LoadFile(BackgroundGraphics* background, void* file, SafeAllocator* allocator, unsigned int size);
extern "C" void Background_FillRect(BackgroundGraphics* background, int a, int b, int c, int d, int e, int f);
extern "C" void Background_UploadMap(BackgroundGraphics* background, void* a);
extern "C" void WindowPane_AllocateBuffer(WindowPane* obj, SafeAllocator* alloc, int val, unsigned int len);
extern "C" void Window_SetPanes(Struct_0205cf78* s, WindowPane* arr, unsigned char count);
extern "C" void SpriteContext_LoadFile(void* table, void* file, int size, SafeAllocator* alloc);
extern "C" int STD_CompareString(const char* a, const char* b);
extern "C" void func_ov003_0215917c(Struct_ov003_0215917c* obj, int flags);
extern "C" unsigned char GameState_GetOwnPartyOrder(char* obj, void* dst);

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
    SafeAllocator allocators_[4];
    char unk_50[0x64 - 0x50];
    char strings_[0x7c - 0x64];
    void* text_;
    char unknown_80_[0x98 - 0x80];
    char table_[0xd4 - 0x98];
    int unknown_d4_;
    int unk_d8;
    char unk_dc[0xe4 - 0xdc];
    short unknown_e4_;
    char unknown_e6_[2];
    unsigned char unknown_e8_;
    char unknown_e9_[3];
    int unknown_ec_;
    int unknown_f0_;
    char list_[0x18c - 0xf4];
    BackgroundGraphics* graphics_;
    char unknown_190_[0x1a6 - 0x190];
    unsigned char unknown_1a6_;
    char unknown_1a7_[0x1b0 - 0x1a7];
    BackgroundGraphics backgrounds_[2];
    Struct_ov003_021594c4_3 layers_[4];
    char unknown_570_[0x578 - 0x570];
    int task_;
    void* buffer_;
    unsigned char state_;
    char unknown_581_[0x587 - 0x581];
    unsigned char unknown_587_;
    unsigned char unknown_588_;
    char unknown_589_[0x590 - 0x589];
    unsigned char memberCount_;
    char members_[0x59d - 0x591];
    unsigned char unknown_59d_;
    unsigned char unknown_59e_;
    char unknown_59f_;
    unsigned char mode_;
    char unknown_5a1_[0x5b1 - 0x5a1];
    unsigned char unknown_5b1_;
    unsigned char unknown_5b2_;
    char unknown_5b3_;
    unsigned char unknown_5b4_;
};

// USA: func_ov003_021594c4
extern "C" ARM void func_ov003_021594c4(Struct_ov003_021594c4_2* self) {
#if defined(jpn)
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    int g = MessageSystem_GetInstance();
    unsigned char state = self->state_;

    if (state == 0) {
        self->text_ = *(void**)(MessageSystem_GetInstance() + 0x28);
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
            self->unknown_5b1_ = func_02005a94(str);
        }
        if (self->unknown_5b1_ == 3) {
            self->unknown_5b1_ = 0;
            self->unknown_5b2_ = 0;
        }
        *(int*)(g + kRegionValue998_868) = 1;
        *(unsigned char*)(g + 0x17ef) = 1;
        *(unsigned char*)(g + 0x17ff) |= 2;
        func_ov003_02159250(self, self->text_);
        if (self->mode_ == 2 || self->unknown_587_ == 1 || self->unknown_587_ == 2) {
            if (self->mode_ == 2) {
                self->unknown_5b4_ = 1;
                self->state_ = 2;
                self->task_ = loader->QueueLoadFile(data_ov003_0217fe5a, NULL);
                *(int*)(MessageSystem_GetInstance() + kRegionValue998_868) = 1;
            } else {
                self->unknown_588_ = 10;
                self->state_ = 0;
            }
            self->unknown_59d_ = 1;
            self->unknown_59e_ = 0;
            func_ov003_02159464(self);
            return;
        }
        Struct_ov003_021594c4_4 priority = data_ov003_0217f380.priority;
        Struct_ov003_021594c4_4 screen = data_ov003_0217f380.screen;
        BackgroundGraphics* background;
        for (int i = 0; i < 2; i++) {
            background = &self->backgrounds_[i];
            Background_SetMapSize((unsigned char*)background, 0);
            background->subScreen_ = 0;
            background->bgNumber_ = priority.v[i];
            Background_SetPriority(background, screen.v[i]);
            Background_AllocateMap((BackgroundGraphics*)background, &self->allocators_[1]);
            Background_SetScroll((BackgroundGraphics*)background, 0, 0);
        }
        BG1CNT = (BG1CNT & 0x43) | 0x1d00;
        BG2CNT = (BG2CNT & 0x43) | 0x1e00;
        ColorEffect_ConfigureAlphaBlend(0x4000050, 2, 1, 10, 6);
        self->task_ = loader->QueueLoadFile(data_ov003_0217fe6b, NULL);
        self->state_++;
    }

    if (state == 1) {
        BackgroundLoader* var11 = BackgroundLoader::GetInstance();
        if (var11->GetTaskStatus(self->task_) != 0) {
            char name[4];
            void* archive;
            unsigned int archiveSize;
            void* files[2];
            int sizes[2];
            var11->GetLoadedFileByID(self->task_, &archive, &archiveSize);
            int count = Pac_CountFiles((PacRecord*)archive);
            for (int i = 0; i < count; i++) {
                files[i] = Pac_GetFile((PacRecord*)archive, i, (void**)name, &sizes[i]);
            }
            for (int i = 0; i < count; i++) {
                if (files[i] != NULL) {
                    Background_LoadFile(&self->backgrounds_[1], files[i], &self->allocators_[1], sizes[i]);
                }
            }
            var11->RemoveTask(self->task_);
            self->task_ = -1;
            BackgroundGraphics* background;
            for (int i = 0; i < 2; i++) {
                background = &self->backgrounds_[i];
                Background_FillRect(background, 0, 0, 0, 0x20, 0x19, 0);
                Background_UploadMap((BackgroundGraphics*)background, 0);
            }
            self->allocators_[2].Reset();
            self->buffer_ = self->allocators_[2].Allocate(0x4000);
            for (int i = 0; i < 4; i++) {
                Struct_ov003_021594c4_3* layer = &self->layers_[i];
                WindowPane_AllocateBuffer((WindowPane*)layer, &self->allocators_[1], (int)self->buffer_, 0x400);
                layer->graphics = &self->backgrounds_[1];
            }
            self->graphics_ = &self->backgrounds_[0];
            self->unknown_1a6_ = 2;
            Window_SetPanes((Struct_0205cf78*)self->list_, (WindowPane*)self->layers_, 4);
            self->task_ = var11->QueueLoadFile(data_ov003_0217fe5a, NULL);
            self->state_++;
        }
    }

    if (state == 2) {
        if (loader->GetTaskStatus(self->task_) != 0) {
            char name[4];
            void* archive;
            unsigned int archiveSize;
            int size;
            self->unknown_e8_ = 0;
            self->unk_d8 = self->unknown_ec_;
            self->unknown_e4_ = 0xe;
            self->unknown_d4_ = self->unknown_f0_;
            loader->GetLoadedFileByID(self->task_, &archive, &archiveSize);
            int count = Pac_CountFiles((PacRecord*)archive);
            self->allocators_[3].Reset();
            for (int i = 0; i < count; i++) {
                void* file = Pac_GetFile((PacRecord*)archive, i, (void**)name, &size);
                SpriteContext_LoadFile(self->table_, file, size, &self->allocators_[3]);
            }
            loader->RemoveTask(self->task_);
            self->task_ = -1;
            if (self->unknown_5b4_ != 0) {
                self->unknown_588_ = 3;
                self->state_ = 0;
                return;
            }
            self->unknown_59d_ = 1;
            self->unknown_59e_ = 0;
            func_ov003_02159464(self);
            self->state_++;
        }
    }

    if (state == 3 && *(int*)(g + Enum_ov003_021594c4_2160) == 3) {
        self->unknown_59d_ = 1;
        BG0CNT = (BG0CNT & ~3) | 2;
        BG1CNT = (BG1CNT & ~3) | 1;
        BG2CNT = (BG2CNT & ~3);
        BG3CNT = (BG3CNT & ~3) | 3;
        DISPCNT = (DISPCNT & ~0x1f00) | 0x1700;
        unsigned char flags = 0x3f;
        for (int i = 0; i < 6; i++) {
            const char* str = KeyTable_Get((Container020e0310*)self->strings_, (short)i);
            if (STD_CompareString(data_ov003_0217fe7e, str) == 0) {
                flags &= ~(1 << i);
            }
        }
        func_ov003_0215917c((Struct_ov003_0215917c*)self, flags);
        self->memberCount_ = GameState_GetOwnPartyOrder((char*)GameState::GetInstance(), self->members_);
        self->unknown_588_ = 1;
        self->state_ = 1;
    }
#else
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    int g = MessageSystem_GetInstance();
    unsigned char state = self->state_;

    if (state == 0) {
        self->text_ = *(void**)(MessageSystem_GetInstance() + 0x5c);
        func_ov017_021d243c(1);
        char archive[0x40];
        char file[0x18];
        sprintf(archive, data_ov003_0217fe2d, self->mode_);
        sprintf(file, data_ov003_0217fe48, self->mode_);
        self->task_ = loader->QueueLoadFileInGP2(archive, file, NULL);
        self->state_++;
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
            self->unknown_5b1_ = func_02005a94(str);
        }
        if (self->unknown_5b1_ == 3) {
            self->unknown_5b1_ = 0;
            self->unknown_5b2_ = 0;
        }
        *(int*)(g + kRegionValue998_868) = 1;
        *(unsigned char*)(g + 0x19bf) = 1;
        *(unsigned char*)(g + 0x19cf) = 1;
        func_ov003_02159250(self, self->text_);
        if (self->mode_ == 2 || self->unknown_587_ == 1 || self->unknown_587_ == 2) {
            if (self->mode_ == 2) {
                self->unknown_5b4_ = 1;
                self->state_ = 3;
                self->task_ = loader->QueueLoadFile(data_ov003_0217fe5a, NULL);
                *(int*)(MessageSystem_GetInstance() + kRegionValue998_868) = 1;
            } else {
                self->unknown_588_ = 10;
                self->state_ = 0;
            }
            self->unknown_59d_ = 1;
            self->unknown_59e_ = 0;
            func_ov003_02159464(self);
            return;
        }
        Struct_ov003_021594c4_4 priority = data_ov003_0217f380.priority;
        Struct_ov003_021594c4_4 screen = data_ov003_0217f380.screen;
        BackgroundGraphics* background;
        for (int i = 0; i < 2; i++) {
            background = &self->backgrounds_[i];
            Background_SetMapSize((unsigned char*)background, 0);
            background->subScreen_ = 0;
            background->bgNumber_ = priority.v[i];
            Background_SetPriority(background, screen.v[i]);
            Background_AllocateMap((BackgroundGraphics*)background, &self->allocators_[1]);
            Background_SetScroll((BackgroundGraphics*)background, 0, 0);
        }
        BG1CNT = (BG1CNT & 0x43) | 0x1d00;
        BG2CNT = (BG2CNT & 0x43) | 0x1e00;
        ColorEffect_ConfigureAlphaBlend(0x4000050, 2, 1, 10, 6);
        self->task_ = loader->QueueLoadFile(data_ov003_0217fe6b, NULL);
        self->state_++;
    }

    if (state == 2) {
        BackgroundLoader* var46 = BackgroundLoader::GetInstance();
        if (var46->GetTaskStatus(self->task_) != 0) {
            char name[4];
            void* archive;
            unsigned int archiveSize;
            void* files[2];
            int sizes[2];
            var46->GetLoadedFileByID(self->task_, &archive, &archiveSize);
            int count = Pac_CountFiles((PacRecord*)archive);
            for (int i = 0; i < count; i++) {
                files[i] = Pac_GetFile((PacRecord*)archive, i, (void**)name, &sizes[i]);
            }
            for (int i = 0; i < count; i++) {
                if (files[i] != NULL) {
                    Background_LoadFile(&self->backgrounds_[1], files[i], &self->allocators_[1], sizes[i]);
                }
            }
            var46->RemoveTask(self->task_);
            self->task_ = -1;
            BackgroundGraphics* background;
            for (int i = 0; i < 2; i++) {
                background = &self->backgrounds_[i];
                Background_FillRect(background, 0, 0, 0, 0x20, 0x19, 0);
                Background_UploadMap((BackgroundGraphics*)background, 0);
            }
            self->allocators_[2].Reset();
            self->buffer_ = self->allocators_[2].Allocate(0x4000);
            for (int i = 0; i < 4; i++) {
                Struct_ov003_021594c4_3* layer = &self->layers_[i];
                WindowPane_AllocateBuffer((WindowPane*)layer, &self->allocators_[1], (int)self->buffer_, 0x400);
                layer->graphics = &self->backgrounds_[1];
            }
            self->graphics_ = &self->backgrounds_[0];
            self->unknown_1a6_ = 2;
            Window_SetPanes((Struct_0205cf78*)self->list_, (WindowPane*)self->layers_, 4);
            self->task_ = var46->QueueLoadFile(data_ov003_0217fe5a, NULL);
            self->state_++;
        }
    }

    if (state == 3) {
        if (loader->GetTaskStatus(self->task_) != 0) {
            char name[4];
            void* archive;
            unsigned int archiveSize;
            int size;
            self->unknown_e8_ = 0;
            self->unk_d8 = self->unknown_ec_;
            self->unknown_e4_ = 0xe;
            self->unknown_d4_ = self->unknown_f0_;
            loader->GetLoadedFileByID(self->task_, &archive, &archiveSize);
            int count = Pac_CountFiles((PacRecord*)archive);
            self->allocators_[3].Reset();
            for (int i = 0; i < count; i++) {
                void* file = Pac_GetFile((PacRecord*)archive, i, (void**)name, &size);
                SpriteContext_LoadFile(self->table_, file, size, &self->allocators_[3]);
            }
            loader->RemoveTask(self->task_);
            self->task_ = -1;
            if (self->unknown_5b4_ != 0) {
                self->unknown_588_ = 3;
                self->state_ = 0;
                return;
            }
            self->unknown_59d_ = 1;
            self->unknown_59e_ = 0;
            func_ov003_02159464(self);
            self->state_++;
        }
    }

    if (state == 4 && *(int*)(g + Enum_ov003_021594c4_2464) == 3) {
        self->unknown_59d_ = 1;
        BG0CNT = (BG0CNT & ~3) | 2;
        BG1CNT = (BG1CNT & ~3) | 1;
        BG2CNT = (BG2CNT & ~3);
        BG3CNT = (BG3CNT & ~3) | 3;
        DISPCNT = (DISPCNT & ~0x1f00) | 0x1700;
        unsigned char flags = 0x3f;
        for (int i = 0; i < 6; i++) {
            const char* str = KeyTable_Get((Container020e0310*)self->strings_, (short)i);
            if (STD_CompareString(data_ov003_0217fe7e, str) == 0) {
                flags &= ~(1 << i);
            }
        }
        func_ov003_0215917c((Struct_ov003_0215917c*)self, flags);
        self->memberCount_ = GameState_GetOwnPartyOrder((char*)GameState::GetInstance(), self->members_);
        self->unknown_588_ = 1;
        self->state_ = 1;
    }
#endif
}
