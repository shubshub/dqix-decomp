#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#if defined(jpn)
extern char data_ov013_02188de0[];
extern char data_ov013_02188dfa[];
#define data_ov013_02187db8 data_ov013_02188ce0
#endif
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Graphics.h"
#include "GameState/GameState.h"

void SpriteContext_Init(char* renderer);
struct Struct0205a198;
void Sprite_Init(Struct0205a198* sprite);
struct PacRecord;
int Pac_CountFiles(PacRecord* pac);
void* Pac_GetFile(PacRecord* pac, int index, void** outName, int* outSize);
extern "C" void SpriteContext_LoadFile(void* renderer, void* file, unsigned int size, SafeAllocator* allocator);
extern "C" void func_020728ac(void* texts, SafeAllocator* allocator, void* file, unsigned int size, int, int, int);
struct List0208df10;
void ClearList0208df10(List0208df10* table);
void* GetFieldAt0x150_02053c6c(unsigned char* member);
signed char GetTableByte020dd11c(unsigned int vocation, unsigned int index);
struct Struct0208df20;
void InitAndRunScript0208df20(Struct0208df20* table, void* allocator, int file, int size, int skills, void* count);
struct BackgroundGraphics;
void Background_Init(BackgroundGraphics* graphics);
extern "C" void Background_SetPriority(void* graphics, int priority);
void Background_SetMapSize(unsigned char* graphics, int value);
void Background_SetScroll(BackgroundGraphics* graphics, int a, int b);
void Background_AllocateMap(BackgroundGraphics* graphics, SafeAllocator* allocator);
void Background_AllocateScreens(BackgroundGraphics* graphics, int count, SafeAllocator* allocator);
extern "C" void WindowPane_Init(void* canvas);
extern "C" void func_ov013_02187a58(void* self, void* canvas);
extern "C" void Background_LoadFile(void* graphics, void* file, SafeAllocator* allocator, unsigned int size);
void* Background_GetScreen(BackgroundGraphics* graphics, unsigned int index);
struct Tilemap0204ae44;
void FillTilemapPalette0204ae44(Tilemap0204ae44* layer, int member);
struct Obj0204b988;
void DispatchIndexedEntry0204b988(Obj0204b988* graphics, unsigned int a, int b, int c, unsigned short d);
void Background_UploadMap(BackgroundGraphics* graphics, void* characters);
extern "C" void func_020dc7e8(int a, int b);

extern char data_ov013_02187e48[];
extern char data_ov013_02187e61[];
extern char data_ov013_02187e77[];
extern char data_ov013_02187e89[];
extern char data_ov013_02187e9e[];
extern char data_ov013_02187eaf[];
extern const unsigned char data_ov013_02187db8[2];

#define BLDCNT (*(volatile unsigned short*)0x04000050)
#define BLDCNTSUB (*(volatile unsigned short*)0x04001050)

struct Struct_ov013_021870f0 {
    char unknown_0_[0x28];
};

struct Struct_ov013_021870f0_2 {
    char unknown_0_[0x40];
    Struct_ov013_021870f0* unknown_40_;
    char unknown_44_[4];
    unsigned int unknown_48_;
    short unknown_4c_;
    unsigned short unknown_4e_;
    unsigned char unknown_50_;
    char unknown_51_[3];
};

struct BackgroundGraphics021870f0 {
    char unk_0[0x1c];
    unsigned char subScreen_ : 4;
    unsigned char bgNumber_ : 4;
    unsigned char screenCount_;
    char unk_1e[2];
};

struct Struct_ov013_021870f0_4 {
    void* unknown_0_;
    void* unknown_4_;
    void* unknown_8_;
    char unknown_c_[0xa8 - 0xc];
    short unknown_a8_;
    short unknown_aa_;
    char unknown_ac_[0xb4 - 0xac];
    short unknown_b4_;
    short unknown_b6_;
    char unknown_b8_[0xe0 - 0xb8];
};

struct Struct_ov013_021870f0_5 {
#if defined(jpn)
    char unknown_0_[0x8b8];
#else
    char unknown1_0_[0x950];
#endif
    int unknown_950_;
};

struct Struct_ov013_021870f0_6 {
    SafeAllocator* unknown_0_;
    char unknown_4_[8];
    char unknown_c_[8];
    char unknown_14_[0x10];
    unsigned char unknown_24_;
    unsigned char unknown_25_;
    char unknown_26_[2];
    Struct_ov013_021870f0_3 unknown_28_;
#if !defined(jpn)
    Struct_ov013_021870f0_2* unknown_48_;
    Struct_ov013_021870f0* unknown_4c_;
    short* unknown_50_;
    short* unknown_54_;
    unsigned char* unknown_58_;
#endif
    int unknown_5c_;
    unsigned int unknown_60_;
    unsigned char unknown_64_;
    bool unknown_65_;
    unsigned char unknown_66_;
    signed char unknown_67_;
};

// USA: func_ov013_021870f0
extern "C" ARM bool func_ov013_021870f0(Struct_ov013_021870f0_6* arg0) {
    SafeAllocator* var0;
    if (arg0->unknown_65_)
        return true;
    bool var1 = true;
    BackgroundLoader* var2 = BackgroundLoader::GetInstance();
    if (arg0->unknown_66_ == 0)
    {
#if defined(jpn)
        FontBankLoader* manager = FontBankLoader_GetInstance();
        BlankFunction02094b3c(manager, 10);
        BlankFunction02094b30(manager, 0x68, 0);
#else
        SafeAllocator* allocators = self->allocators_;
        allocators[4].Reset();
        self->spriteRenderer_ = (SpriteRenderer021870f0*)allocators[4].Allocate(sizeof(SpriteRenderer021870f0));
        self->sprites_ = (Sprite021870f0*)allocators[4].Allocate(13 * sizeof(Sprite021870f0));
        self->markerX_ = (short*)allocators[4].Allocate(13 * sizeof(short));
        self->markerY_ = (short*)allocators[4].Allocate(13 * sizeof(short));
        self->markerPalettes_ = (unsigned char*)allocators[4].Allocate(13);
        SpriteContext_Init((char*)self->spriteRenderer_);
        self->spriteRenderer_->unk_50 = self->screen_;
        SpriteRenderer021870f0* renderer = self->spriteRenderer_;
        renderer->sprites_ = self->sprites_;
        renderer->numSprites_ = 13;
        for (int i = 0; i < 13; i++)
        {
            Sprite_Init((Struct0205a198*)&self->sprites_[i]);
        }
        for (int var7 = 0; var7 < 10; var7++)
        {
            arg0->unknown_50_[var7] = -1;
            arg0->unknown_54_[var7] = -1;
            arg0->unknown_58_[var7] = 2;
        }
        arg0->unknown_5c_ = var2->QueueLoadFile(data_ov013_02187e48, NULL);
#endif
        var1 = false;
        arg0->unknown_66_++;
    }
    else if (arg0->unknown_66_ == 1)
    {
#if defined(jpn)
        if (AlwaysTrue02094b4c(FontBankLoader_GetInstance())) {
            self->step_++;
        }
#else
        if (var2->GetTaskStatus(arg0->unknown_5c_))
        {
            SafeAllocator* allocators = self->allocators_;
            void* name;
            void* file;
            unsigned int size;
            loader->GetLoadedFileByID(self->task_, &file, &size);
            int numFiles = Pac_CountFiles((PacRecord*)file);
            for (int i = 0; i < numFiles; i++)
            {
                unsigned int dataSize;
                void* data = Pac_GetFile((PacRecord*)file, i, &name, (int*)&dataSize);
                SpriteContext_LoadFile(self->spriteRenderer_, data, dataSize, &allocators[4]);
            }
            var2->RemoveTask(arg0->unknown_5c_);
            arg0->unknown_5c_ = -1;
            arg0->unknown_66_++;
        }
#endif
        var1 = false;
    }
    else if (arg0->unknown_66_ == 2)
    {
        loader->FreeAllocations();
#if defined(jpn)
        arg0->unknown_5c_ = var2->QueueLoadFile(data_ov013_02188de0, NULL);
#else
        arg0->unknown_5c_ = var2->QueueLoadFileInGP2(data_ov013_02187e61, data_ov013_02187e77, NULL);
#endif
        var1 = false;
        arg0->unknown_66_++;
    }
    else if (arg0->unknown_66_ == 3)
    {
        if (var2->GetTaskStatus(arg0->unknown_5c_))
        {
            void* var16;
            unsigned int var17;
            var2->GetLoadedFileByID(arg0->unknown_5c_, &var16, &var17);
            SafeAllocator* var18 = arg0->unknown_0_;
            var18[3].Reset();
            func_020728ac(arg0->unknown_4_, &var18[3], var16, var17, 0, 0, 0);
            var2->RemoveTask(arg0->unknown_5c_);
            arg0->unknown_5c_ = -1;
            arg0->unknown_66_++;
        }
        var1 = false;
    }
    else if (arg0->unknown_66_ == 4)
    {
        ClearList0208df10((List0208df10*)self->abilities_);
        loader->FreeAllocations();
#if defined(jpn)
        arg0->unknown_5c_ = var2->QueueLoadFile(data_ov013_02188dfa, NULL);
#else
        arg0->unknown_5c_ = var2->QueueLoadFileInGP2(data_ov013_02187e89, data_ov013_02187e9e, NULL);
#endif
        var1 = false;
        arg0->unknown_66_++;
    }
    else if (arg0->unknown_66_ == 5)
    {
        if (var2->GetTaskStatus(arg0->unknown_5c_))
        {
            void* var19;
            unsigned int var20;
            var2->GetLoadedFileByID(arg0->unknown_5c_, &var19, &var20);
            SafeAllocator* var21 = arg0->unknown_0_;
            var21[2].Reset();
            short* var22 = NULL;
            short var23[5] = {};
            GameObject* var24 = func_0200ff1c(GameState::GetInstance(), arg0->unknown_67_);
            if (var24 != NULL)
            {
                Struct_ov013_021870f0_5* var25 = (Struct_ov013_021870f0_5*)func_02053c6c((unsigned char*)var24);
                if (var25 != NULL)
                {
                    for (unsigned char var26 = 0; var26 < 5; var26++)
                    {
                        var23[var26] = func_020dd11c((unsigned char)var25->unknown_950_, var26);
                    }
                    var22 = var23;
                }
            }
            func_0208df20((Struct_0208df20*)arg0->unknown_c_, &var21[2], (int)var19, var20, (int)var22, (void*)5);
            var2->RemoveTask(arg0->unknown_5c_);
            arg0->unknown_5c_ = -1;
            arg0->unknown_66_++;
        }
        var1 = false;
    }
    else if (arg0->unknown_66_ == 6)
    {
        SafeAllocator* allocator = self->allocators_;
        allocator->Reset();
        unsigned char palettes[2];
        palettes[0] = data_ov013_02187db8[0];
        palettes[1] = data_ov013_02187db8[1];
        Background_Init((BackgroundGraphics*)&self->background_);
        self->background_.subScreen_ = self->screen_;
        self->background_.bgNumber_ = palettes[self->screen_];
        Background_SetPriority(&self->background_, 0);
        Background_SetMapSize((unsigned char*)&self->background_, 0);
        Background_SetScroll((BackgroundGraphics*)&self->background_, 0, 0);
        Background_AllocateMap((BackgroundGraphics*)&self->background_, allocator);
        Background_AllocateScreens((BackgroundGraphics*)&self->background_, 1, allocator);
        if (self->screen_ == 0)
        {
            DISPCNT = (DISPCNT & ~0x1f00) | 0x1200;
            BLDCNT = 0;
        }
        else
        {
            BG0CNTSUB = (BG0CNTSUB & (3 | 0x40)) | (0xf << 8);
            BLDCNTSUB = 0;
        }
        var1 = false;
        arg0->unknown_66_++;
    }
    else if (arg0->unknown_66_ == 7)
    {
        loader->FreeAllocations();
        self->task_ = loader->QueueLoadFile(data_ov013_02187eaf, NULL);
        result = false;
        self->step_++;
    }
    else if (arg0->unknown_66_ == 8)
    {
        if (var2->GetTaskStatus(arg0->unknown_5c_))
        {
            void* data;
            void* name;
            void* file;
            unsigned int size;
            loader->GetLoadedFileByID(self->task_, &file, &size);
            int numFiles = Pac_CountFiles((PacRecord*)file);
            allocators = self->allocators_;
            allocators[1].Reset();
            for (int i = 0; i < numFiles; i++)
            {
                unsigned int dataSize;
                data = Pac_GetFile((PacRecord*)file, i, &name, (int*)&dataSize);
                if (data != NULL)
                {
                    if (var34 == 0)
                    {
                        Canvas021870f0 canvas;
                        WindowPane_Init(&canvas);
                        canvas.unk_b4 = 0xa;
                        canvas.unk_b6 = 0xb;
                        canvas.width_ = 0x20;
                        canvas.height_ = 0x18;
                        canvas.pixels_ = (char*)data + 0x10;
                        func_ov013_02187a58(self, &canvas);
                    }
                    Background_LoadFile(&self->background_, data, &allocators[1], dataSize);
                }
            }
            loader->RemoveTask(self->task_);
            self->task_ = -1;
            void* layer = Background_GetScreen((BackgroundGraphics*)&self->background_, 0);
            if (layer != NULL)
                FillTilemapPalette0204ae44((Tilemap0204ae44*)layer, self->member_);
            DispatchIndexedEntry0204b988((Obj0204b988*)&self->background_, 0, 0, 0, 0xffff);
            Background_UploadMap((BackgroundGraphics*)&self->background_, NULL);
            self->loaded_ = true;
            self->step_ = 0;
            if (self->screen_ == 0)
                func_020dc7e8(4, -1);
            else
                func_020dc7e8(3, -1);
        }
        var1 = false;
    }
    return var1;
}
