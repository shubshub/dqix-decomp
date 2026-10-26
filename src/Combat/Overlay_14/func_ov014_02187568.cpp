#include "Combat/MenuNodeChain.h"
#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#include <std_library_functions.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "NitroSDK/ColorEffects.h"
#include "NitroSDK/Graphics.h"
#include "Resource/Brightness.h"

struct Struct_ov014_02184f78 {
    Struct_ov014_02184f78* unknown_0_;
    const char* unknown_4_;
    const char* name_;
    short unknown_c_;
    char unknown_e_[4];
    signed char unknown_12_;
    unsigned char unknown_13_0_ : 1;
    unsigned char unknown_13_1_ : 1;
    unsigned char unknown_13_2_ : 6;
    char unk_14[6];
    short unknown_1a_;
    char unk_1c[4];
};

struct BackgroundGraphics;
struct Node0207f7f0;

struct Struct_020974b0 {
    char unk_0[0x10];
};

struct TextTable {
    char unk_0[0x18];
};

struct SpriteRenderer {
    char unk_0[0x3c];
    void* animations_;
    void* sprites_;
    char unknown_44_[4];
    unsigned int unknown_48_;
    short unknown_4c_;
    unsigned short unknown_4e_;
    unsigned char unk_50;
    char unknown_51_[3];

    void SetSprites(void* sprites, short arg1)
    {
        sprites_ = sprites;
        unknown_4c_ = arg1;
    }
};

struct Struct_ov014_02186bc8 {
    char unk_0[0xa4];
    Struct_020974b0 list_;
    SafeAllocator* unknown_b4_;
    Struct_ov014_02184f78* entries_;
    Struct_ov014_02184f78* unknown_bc_;
    Manager0207f7f0* menu_;
    BackgroundGraphics* backgrounds_;
    Node0207f7f0* canvases_;
    void* canvasBuffer_;
    short* cursor_;
    void* unknown_d4_;
    void* animations_;
    void* unknown_dc_;
    TextTable textTable_;
    SpriteRenderer spriteRenderer_;
    char unknown_14c_[0xc];
    unsigned short unknown_158_;
    unsigned char unknown_15a_;
    char unknown_15b_;
    int unknown_15c_;
    int unknown_160_;
    int ticks_;
    int unknown_168_;
    int unknown_16c_;
    short unknown_170_;
    short unknown_172_;
    short unknown_174_;
    short unknown_176_;
    short unknown_178_;
    unsigned char unknown_17a_;
    unsigned char unknown_17b_;
    unsigned char unknown_17c_;
    signed char unknown_17d_;
    unsigned char unknown_17e_;
    bool unknown_17f_;
    short unknown_180_;
    short unknown_182_[8];
};

struct Struct_02097420;
struct Struct_02097418;
struct Struct_0207f914;
struct PacRecord;
struct Struct020dfc40;
struct Manager0207f7f0;
struct Node0207f7f0;

extern "C" void func_020c54a4(int, unsigned int, unsigned int, unsigned short);
extern "C" void Set3DClearColor(int, int, int, int, int);
extern "C" int func_02097420(Struct_02097420*);
extern "C" Struct_ov014_02184f78* func_02097418(Struct_02097418*);
extern "C" void func_0206819c(const char*, char*, int);
extern "C" void func_0207f914(Struct_0207f914*, int, int, int);
extern "C" void func_02080798(void*, int, int);
extern "C" int Pac_CountFiles(PacRecord*);
extern "C" void* Pac_GetFile(PacRecord*, int, void**, int*);
extern "C" void KeyTable_Reset(Struct020dfc40*);
extern "C" void func_020abf38(void*);
extern "C" void func_0207f7f0(Manager0207f7f0*, Node0207f7f0*, int);

extern "C" {
void func_020972e0(Struct_020974b0* list, SafeAllocator* allocator, void* file, unsigned int size);
int func_0207f9f4(Manager0207f7f0* menu);
void SpriteContext_LoadFile(SpriteRenderer* renderer, void* file, unsigned int size, SafeAllocator* allocator);
void KeyTable_Load(TextTable* texts, SafeAllocator* allocator, void* file, unsigned int size);
void func_020abf60(Struct_020974b0* list);
void func_ov014_02187488(Struct_ov014_02186bc8* self);
Struct_ov014_02184f78* func_020974b0(Struct_020974b0* list, int arg1, int, bool arg3, int, short* outCount);
}

extern const char data_ov014_0218970c[];
extern const char data_ov014_02189722[];
extern const char data_ov014_02189734[];
extern const char data_ov014_0218974d[];
extern const char data_ov014_02189754[];
extern const char data_ov014_0218976a[];
extern const char data_ov014_02189784[];

// USA: func_ov014_02187568
extern "C" ARM void func_ov014_02187568(Struct_ov014_02186bc8* self)
{
    int* resources = (int*)GameState::GetInstance()->GetResources();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    if (self->unknown_17b_ == 0)
    {
        SetFlags04(GetGameResources(), 0x609fe);
        func_020c54a4(0, 0, 0, 0);
        Set3DClearColor(0, 0, 0x7fff, 0, 0);
        FontBankLoader* music = FontBankLoader_GetInstance();
        FontBankLoader_CancelLoads(music);
        func_02094b40(music);
        func_02094b30(music, 0x6a, 0);
        self->unknown_17b_++;
    }
    else if (self->unknown_17b_ == 1)
    {
        if (func_02094b4c(FontBankLoader_GetInstance()))
            self->unknown_17b_++;
    }
    else if (self->unknown_17b_ == 2)
    {
        self->unknown_168_ = loader->QueueLoadFileInGP2(data_ov014_0218970c, data_ov014_02189722, NULL);
        self->unknown_17b_++;
    }
    else if (self->unknown_17b_ == 3)
    {
        if (loader->GetTaskStatus(self->unknown_168_))
        {
            void* file;
            unsigned int size;
            loader->GetLoadedFileByID(self->unknown_168_, &file, &size);
            if (file != NULL)
            {
                self->unknown_b4_[0].Reset();
                func_020972e0(&self->list_, &self->unknown_b4_[0], file, size);
            }
            loader->RemoveTask(self->unknown_168_);
            self->unknown_168_ = -1;
            self->unknown_17b_++;
        }
    }
    else if (self->unknown_17b_ == 4)
    {
        int count = func_02097420((Struct_02097420*)&self->list_);
        Struct_ov014_02184f78* entry = func_02097418((Struct_02097418*)&self->list_);
        for (int i = 0; i < count; i++, entry++)
        {
            char name[0x80] = {};
            func_0206819c(entry->name_, name, 0);
            sprintf((char*)entry->name_, name);
        }
        BG0CNTSUB = (BG0CNTSUB & (3 | 0x40)) | (0x1d << 8);
        BG1CNTSUB = (BG1CNTSUB & (3 | 0x40)) | (0x1e << 8);
        BG2CNTSUB = (BG2CNTSUB & (3 | 0x40)) | (0x1f << 8) | (2 << 2);
        self->unknown_17e_ |= 0x10;
        self->unknown_17b_++;
    }
    else if (self->unknown_17b_ == 5)
    {
        if (!(self->unknown_17e_ & 0x10))
        {
            SafeAllocator* allocators = self->unknown_b4_;
            allocators[2].Reset();
            func_0207f914((Struct_0207f914*)self->menu_, (int)&allocators[2], (int)data_ov014_02189734, (int)data_ov014_0218974d);
            self->unknown_17b_++;
        }
    }
    else if (self->unknown_17b_ == 6)
    {
        int status = func_0207f9f4(self->menu_);
        if (status == 0)
            self->unknown_17b_++;
        if (status < 0)
            self->unknown_17a_ = 6;
    }
    else if (self->unknown_17b_ == 7)
    {
        func_02080798(self->menu_, 6, 1);
        self->spriteRenderer_.unk_50 = 1;
        self->spriteRenderer_.SetSprites(self->unknown_d4_, 8);
        self->spriteRenderer_.animations_ = self->animations_;
        self->unknown_168_ = loader->QueueLoadFile(data_ov014_02189754, NULL);
        self->unknown_17b_++;
    }
    else if (self->unknown_17b_ == 8)
    {
        if (loader->GetTaskStatus(self->unknown_168_))
        {
            void* name;
            void* file;
            unsigned int size;
            unsigned int cellsSize;
            SafeAllocator* allocators;
            int numFiles;
            loader->GetLoadedFileByID(self->unknown_168_, &file, &size);
            numFiles = Pac_CountFiles((PacRecord*)file);
            allocators = self->unknown_b4_;
            allocators[3].Reset();
            for (int i = 0; i < numFiles; i++)
            {
                void* cells = Pac_GetFile((PacRecord*)file, i, &name, (int*)&cellsSize);
                if (cells != NULL)
                    SpriteContext_LoadFile(&self->spriteRenderer_, cells, cellsSize, &allocators[3]);
            }
            loader->RemoveTask(self->unknown_168_);
            self->unknown_168_ = -1;
            self->unknown_17b_++;
        }
    }
    else if (self->unknown_17b_ == 9)
    {
        KeyTable_Reset((Struct020dfc40*)&self->textTable_);
        self->unknown_168_ = loader->QueueLoadFileInGP2(data_ov014_0218976a, data_ov014_02189784, NULL);
        self->unknown_17b_++;
    }
    else if (self->unknown_17b_ == 10)
    {
        if (loader->GetTaskStatus(self->unknown_168_))
        {
            void* file;
            unsigned int size;
            loader->GetLoadedFileByID(self->unknown_168_, &file, &size);
            if (file != NULL)
            {
                SafeAllocator* allocators = self->unknown_b4_;
                allocators[4].Reset();
                KeyTable_Load(&self->textTable_, &allocators[4], file, size);
            }
            loader->RemoveTask(self->unknown_168_);
            self->unknown_168_ = -1;
            self->unknown_17b_ += 3;
        }
    }
    else if (self->unknown_17b_ == 11)
        self->unknown_17b_++;
    else if (self->unknown_17b_ == 12)
        self->unknown_17b_++;
    else if (self->unknown_17b_ == 13)
    {
        func_020abf60(&self->list_);
        func_020abf38(self->unknown_dc_);
        func_ov014_02187488(self);
        BG0CNTSUB = (BG0CNTSUB & ~3);
        BG1CNTSUB = (BG1CNTSUB & ~3) | 1;
        BG2CNTSUB = (BG2CNTSUB & ~3) | 2;
        BG3CNTSUB = (BG3CNTSUB & ~3) | 3;
        DISPCNTSUB = (DISPCNTSUB & ~0x1f00) | (0x17 << 8);
        ColorEffect_ConfigureAlphaBlend(0x04001050, BLEND_TARGET_BG1, 4, 10, 6);
        Manager0207f7f0* menu = self->menu_;
        menu->lists = self->backgrounds_;
        menu->mode = 2;
        func_0207f7f0(self->menu_, self->canvases_, 4);
        self->menu_->active = 0;
        func_020974b0(&self->list_, -1, -1, false, 0, &self->unknown_180_);
        short count = 0;
        self->entries_ = func_020974b0(&self->list_, self->unknown_17d_, -1, (self->unknown_17e_ & 8) != 0, 0x10, &count);
        self->unknown_bc_ = self->entries_;
        self->unknown_17a_ = 1;
        self->unknown_17b_ = 0;
    }
}
