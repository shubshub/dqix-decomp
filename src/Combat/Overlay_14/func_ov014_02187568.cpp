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
    const char* unknown_8_;
    short unknown_c_;
    char unknown_e_[4];
    signed char unknown_12_;
    unsigned char unknown_13_0_ : 1;
    unsigned char unknown_13_1_ : 1;
    unsigned char unknown_13_2_ : 6;
    char unknown_14_[6];
    short unknown_1a_;
    char unknown_1c_[4];
};

struct BackgroundGraphics;
struct Node0207f7f0;

struct Struct_020974b0 {
    char unknown_0_[0x10];
};

struct Struct_01ff8b48_13 {
    char unknown_0_[0x18];
};

struct Struct_ov008_02188d74 {
    char unknown_0_[0x3c];
    void* unknown_3c_;
    void* unknown_40_;
    char unknown_44_[4];
    unsigned int unknown_48_;
    short unknown_4c_;
    unsigned short unknown_4e_;
    unsigned char unknown_50_;
    char unknown_51_[3];

    void inline_ov008_02188d74(void* arg0, short arg1)
    {
        unknown_40_ = arg0;
        unknown_4c_ = arg1;
    }
};

struct MonsterListScreen {
    char unk_0[0xa4];
    MonsterList list_;
    SafeAllocator* listAllocators_;
    MonsterListEntry* entries_;
    MonsterListEntry* pageEntry_;
    Manager0207f7f0* menu_;
    BackgroundGraphics* backgrounds_;
    Node0207f7f0* canvases_;
    void* canvasBuffer_;
    short* cursor_;
    void* listSprites_;
    void* animations_;
    void* records_;
    TextTable textTable_;
    SpriteRenderer spriteRenderer_;
    char repeat_[0xc];
    unsigned short repeatButtons_;
    unsigned char unk_15a;
    char unk_15b;
    int unk_15c;
    int menuEvents_;
    int ticks_;
    int listTaskID_;
    int listBackgroundTaskID_;
    short group_;
    short modeCursor_;
    short familyCursor_;
    short monsterCursor_;
    short prevCursor_;
    unsigned char listState_;
    unsigned char listStep_;
    unsigned char listBackgroundStep_;
    signed char family_;
    unsigned char listFlags_;
    bool closing_;
    short numMonsters_;
    short variantIDs_[8];
};

struct Field4Low12_02097420;
struct BufferField8_02097418;
struct Obj0207f914;
struct PacRecord;
struct Struct020dfc40;
struct Manager0207f7f0;
struct Node0207f7f0;

void SetFogState_020c54a4(int, unsigned int, unsigned int, unsigned short);
void Set3DClearColor_020c5588(int, int, int, int, int);
int GetField4Low12(Field4Low12_02097420*);
MonsterListEntry* GetBufferField8(BufferField8_02097418*);
void CopyTextAndUppercaseIfFlagged0206819c(const char*, char*, int);
void SetFieldsFromFormattedValue0207f914(Obj0207f914*, int, int, int);
void SetSublistEntryField14LowBits_02080798(void*, int, int);
int Pac_CountFiles(PacRecord*);
void* Pac_GetFile(PacRecord*, int, void**, int*);
void KeyTable_Reset(Struct020dfc40*);
void CopyOutBattleRegion0x75f0_020abf38(void*);
void InitNodeChain0207f7f0(Manager0207f7f0*, Node0207f7f0*, int);

extern "C" {
void func_020972e0(MonsterList* list, SafeAllocator* allocator, void* file, unsigned int size);
int func_0207f9f4(Manager0207f7f0* menu);
void SpriteContext_LoadFile(SpriteRenderer* renderer, void* file, unsigned int size, SafeAllocator* allocator);
void KeyTable_Load(TextTable* texts, SafeAllocator* allocator, void* file, unsigned int size);
void func_020abf60(MonsterList* list);
void func_ov014_02187488(MonsterListScreen* self);
MonsterListEntry* func_020974b0(MonsterList* list, int family, int, bool sort, int, short* outCount);
}

extern const char data_ov014_0218970c[];
extern const char data_ov014_02189722[];
extern const char data_ov014_02189734[];
extern const char data_ov014_0218974d[];
extern const char data_ov014_02189754[];
extern const char data_ov014_0218976a[];
extern const char data_ov014_02189784[];

// USA: func_ov014_02187568
extern "C" ARM void func_ov014_02187568(Struct_ov014_02186bc8* arg0)
{
    int* resources = (int*)GameState::GetInstance()->GetResources();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    if (self->listStep_ == 0)
    {
        SetFlags04(GetGameResources(), 0x609fe);
        SetFogState_020c54a4(0, 0, 0, 0);
        Set3DClearColor_020c5588(0, 0, 0x7fff, 0, 0);
        FontBankLoader* music = FontBankLoader_GetInstance();
        FontBankLoader_CancelLoads(music);
        BlankFunction02094b40(music);
        BlankFunction02094b30(music, 0x6a, 0);
        self->listStep_++;
    }
    else if (arg0->unknown_17b_ == 1)
    {
        if (AlwaysTrue02094b4c(FontBankLoader_GetInstance()))
            self->listStep_++;
    }
    else if (arg0->unknown_17b_ == 2)
    {
        arg0->unknown_168_ = var1->QueueLoadFileInGP2(data_ov014_0218970c, data_ov014_02189722, NULL);
        arg0->unknown_17b_++;
    }
    else if (arg0->unknown_17b_ == 3)
    {
        if (var1->GetTaskStatus(arg0->unknown_168_))
        {
            void* var3;
            unsigned int var4;
            var1->GetLoadedFileByID(arg0->unknown_168_, &var3, &var4);
            if (var3 != NULL)
            {
                arg0->unknown_b4_[0].Reset();
                func_020972e0(&arg0->unknown_a4_, &arg0->unknown_b4_[0], var3, var4);
            }
            var1->RemoveTask(arg0->unknown_168_);
            arg0->unknown_168_ = -1;
            arg0->unknown_17b_++;
        }
    }
    else if (arg0->unknown_17b_ == 4)
    {
        int var5 = func_02097420((Struct_02097420*)&arg0->unknown_a4_);
        Struct_ov014_02184f78* var6 = func_02097418((Struct_02097418*)&arg0->unknown_a4_);
        for (int var7 = 0; var7 < var5; var7++, var6++)
        {
            char var8[0x80] = {};
            func_0206819c(var6->unknown_8_, var8, 0);
            sprintf((char*)var6->unknown_8_, var8);
        }
        BG0CNTSUB = (BG0CNTSUB & (3 | 0x40)) | (0x1d << 8);
        BG1CNTSUB = (BG1CNTSUB & (3 | 0x40)) | (0x1e << 8);
        BG2CNTSUB = (BG2CNTSUB & (3 | 0x40)) | (0x1f << 8) | (2 << 2);
        arg0->unknown_17e_ |= 0x10;
        arg0->unknown_17b_++;
    }
    else if (arg0->unknown_17b_ == 5)
    {
        if (!(arg0->unknown_17e_ & 0x10))
        {
            SafeAllocator* var9 = arg0->unknown_b4_;
            var9[2].Reset();
            func_0207f914((Struct_0207f914*)arg0->unknown_c0_, (int)&var9[2], (int)data_ov014_02189734, (int)data_ov014_0218974d);
            arg0->unknown_17b_++;
        }
    }
    else if (arg0->unknown_17b_ == 6)
    {
        int var10 = func_0207f9f4(arg0->unknown_c0_);
        if (var10 == 0)
            arg0->unknown_17b_++;
        if (var10 < 0)
            arg0->unknown_17a_ = 6;
    }
    else if (arg0->unknown_17b_ == 7)
    {
        func_02080798(arg0->unknown_c0_, 6, 1);
        arg0->unknown_f8_.unknown_50_ = 1;
        arg0->unknown_f8_.inline_ov008_02188d74(arg0->unknown_d4_, 8);
        arg0->unknown_f8_.unknown_3c_ = arg0->unknown_d8_;
        arg0->unknown_168_ = var1->QueueLoadFile(data_ov014_02189754, NULL);
        arg0->unknown_17b_++;
    }
    else if (arg0->unknown_17b_ == 8)
    {
        if (var1->GetTaskStatus(arg0->unknown_168_))
        {
            void* name;
            void* file;
            unsigned int size;
            unsigned int cellsSize;
            SafeAllocator* allocators;
            int numFiles;
            loader->GetLoadedFileByID(self->listTaskID_, &file, &size);
            numFiles = Pac_CountFiles((PacRecord*)file);
            allocators = self->listAllocators_;
            allocators[3].Reset();
            for (int i = 0; i < numFiles; i++)
            {
                void* cells = Pac_GetFile((PacRecord*)file, i, &name, (int*)&cellsSize);
                if (cells != NULL)
                    SpriteContext_LoadFile(&self->spriteRenderer_, cells, cellsSize, &allocators[3]);
            }
            var1->RemoveTask(arg0->unknown_168_);
            arg0->unknown_168_ = -1;
            arg0->unknown_17b_++;
        }
    }
    else if (arg0->unknown_17b_ == 9)
    {
        KeyTable_Reset((Struct020dfc40*)&self->textTable_);
        self->listTaskID_ = loader->QueueLoadFileInGP2(data_ov014_0218976a, data_ov014_02189784, NULL);
        self->listStep_++;
    }
    else if (arg0->unknown_17b_ == 10)
    {
        if (var1->GetTaskStatus(arg0->unknown_168_))
        {
            void* var19;
            unsigned int var20;
            var1->GetLoadedFileByID(arg0->unknown_168_, &var19, &var20);
            if (var19 != NULL)
            {
                SafeAllocator* allocators = self->listAllocators_;
                allocators[4].Reset();
                KeyTable_Load(&self->textTable_, &allocators[4], file, size);
            }
            var1->RemoveTask(arg0->unknown_168_);
            arg0->unknown_168_ = -1;
            arg0->unknown_17b_ += 3;
        }
    }
    else if (arg0->unknown_17b_ == 11)
        arg0->unknown_17b_++;
    else if (arg0->unknown_17b_ == 12)
        arg0->unknown_17b_++;
    else if (arg0->unknown_17b_ == 13)
    {
        func_020abf60(&arg0->unknown_a4_);
        func_020abf38(arg0->unknown_dc_);
        func_ov014_02187488(arg0);
        BG0CNTSUB = (BG0CNTSUB & ~3);
        BG1CNTSUB = (BG1CNTSUB & ~3) | 1;
        BG2CNTSUB = (BG2CNTSUB & ~3) | 2;
        BG3CNTSUB = (BG3CNTSUB & ~3) | 3;
        DISPCNTSUB = (DISPCNTSUB & ~0x1f00) | (0x17 << 8);
        ColorEffect_ConfigureAlphaBlend(0x04001050, BLEND_TARGET_BG1, 4, 10, 6);
        Struct_0207f7f0* var22 = arg0->unknown_c0_;
        var22->unknown_2c_ = arg0->unknown_c4_;
        var22->unknown_38_ = 2;
        func_0207f7f0(arg0->unknown_c0_, arg0->unknown_c8_, 4);
        arg0->unknown_c0_->unknown_3a_ = 0;
        func_020974b0(&arg0->unknown_a4_, -1, -1, false, 0, &arg0->unknown_180_);
        short var23 = 0;
        arg0->unknown_b8_ = func_020974b0(&arg0->unknown_a4_, arg0->unknown_17d_, -1, (arg0->unknown_17e_ & 8) != 0, 0x10, &var23);
        arg0->unknown_bc_ = arg0->unknown_b8_;
        arg0->unknown_17a_ = 1;
        arg0->unknown_17b_ = 0;
    }
}
