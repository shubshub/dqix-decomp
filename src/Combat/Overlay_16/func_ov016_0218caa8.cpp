#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Graphics.h"
#include "NitroSDK/Interrupts.h"
#include "NitroSDK/VRAM.h"

#if defined(jpn)
#define func_020c39a0 func_020c546c
#endif

#define IRQ_MASTER_ENABLE (*(volatile unsigned short*)0x04000208)
#define SUB_BG0_SCROLL (*(volatile unsigned int*)0x04001010)

struct Struct_ov016_0218caa8_2 {
    unsigned short unknown_0_;
    unsigned char unknown_2_[2];
    int unknown_4_;
    const char* unknown_8_;
    const char* unknown_c_;
    unsigned char unknown_10_;
    unsigned char unknown_11_;
    short unknown_12_;
};

struct Struct_ov016_0219d0c0_9 {
    int unknown_0_;
    unsigned char unknown_4_[4];
    void* unknown_8_;
    unsigned char unknown_c_[4];
    int unknown_10_;
    unsigned char unknown_14_[0x20];
    Struct_ov016_0218caa8_2* unknown_34_;
    unsigned char unknown_38_[8];
    int unknown_40_[2];
};

struct Struct_ov003_021594c4 {
    unsigned char unknown_0_[0x1c];
    unsigned char unknown_1c_0_ : 4;
    unsigned char unknown_1c_4_ : 4;
    unsigned char unknown_1d_;
    unsigned char unknown_1e_[2];
};

struct Struct_02020cb8;
struct Struct_0204b12c;
struct Struct_0204af38;
struct Struct_02020aec;
struct Struct_02020cb8_4;
struct Struct_0204b8d0;
struct Struct_02020cb8_2;
struct Struct_02000c9c_8;

extern "C" void func_020c39a0(short*, int);
void ClearField0x0_020bc078(int*);
void CallField0xa00203aa44(void*);
int TryAllocateOrAppend0203aaf8(void*, void*, int*);
void EnsureInitAndSetFlag_0218be1c();
void InitOverlay17ObjAndBumpBattleCounter02012bd8();
int SetVBlankIrqEnable_020c3864(int);
int GetWord0x7f6c_0201201c(void*);
void SetSubBgMode_020c3984(unsigned int);
void* AllocateAligned4_02012d88(AllocatorUnion*, unsigned int);
void TailForward02012da4(AllocatorUnion*, void*);
void Background_Init(List0204af64*);
void Background_SetMapSize(unsigned char*, int);
void Background_AllocateMap(AllocTarget0204b12c*, SafeAllocator*);
void Background_AllocateScreens(Foo0204af38*, int, SafeAllocator*);
int Pac_CountFiles(ActiveEntry02046900*);
void* Pac_GetFile(Rec020467f0*, int, void**, int*);
int NormalizeField5_0200fb08(Struct0200fb08*);
void Background_DrawScreen(Obj0204b8d0*, unsigned int, int, int, short, short, short, short, unsigned short);
void Background_UploadMap(List0204b0e8*, void*);
void DelayThenSyncBit0_020c9820();
extern "C" void func_020ca458(unsigned int, void*, unsigned int);
extern "C" void Background_SetPriority(BackgroundGraphics*, int);
extern "C" void Background_LoadFile(BackgroundGraphics*, void*, SafeAllocator*, unsigned int);
extern "C" void func_ov016_0218c04c(char*, void*);

#if !defined(jpn)
extern Struct_ov016_0219d0c0_9 data_ov016_0219d0c0;
#endif
extern int data_ov016_0219d0cc;
extern int data_02109bf4;
extern AllocatorUnion data_02114e20;
extern const char data_ov016_0219d030[];

#if defined(jpn)
struct Struct_ov016_0218caa8 {
    unsigned short unknown_0_;
    unsigned char unknown_2_[2];
    int unknown_4_;
    const char* unknown_8_;
    const char* unknown_c_;
    short unknown_10_;
};

struct Struct_ov016_0219d0c0_8 {
    void* unknown_0_;
    unsigned char unknown_4_[0xc];
    Struct_ov016_0218caa8* unknown_10_;
    int unknown_14_;
    int unknown_18_;
    unsigned char unknown_1c_[0x4c - 0x1c];
    int unknown_4c_[2];
};

struct SelfTag0204b3a0;
void Background_FlushFile(void*, char*);
void Background_UploadFile(SelfTag0204b3a0*, char*);
extern "C" void func_ov016_0218ca98(char*);
extern const char data_ov016_0219cf00[];
extern Struct_ov016_0219d0c0_8 data_ov016_0219d0c0;

// USA: func_ov016_0218caa8
extern "C" ARM void func_ov016_0218caa8(char* arg0, void* arg1, Struct_ov016_0218caa8* arg2, int arg3)
{
    data_ov016_0219d0c0.unknown_10_ = arg2;
    data_ov016_0219d0c0.unknown_4c_[0] = 0;
    data_ov016_0219d0c0.unknown_4c_[1] = 0;
    data_ov016_0219d0c0.unknown_18_ = arg2->unknown_10_ < 0;
    data_ov016_0219d0c0.unknown_14_ = arg3;
    func_020c39a0((short*)0x0400006c, -16);
    func_020c39a0((short*)0x0400106c, -16);
    SetInterruptHandler(1, (const void*)func_ov016_0218be1c);
    EnableSpecificInterrupts(0x60078);
    unsigned short var0 = IRQ_MASTER_ENABLE;
    IRQ_MASTER_ENABLE = 1;
    func_020c3864(1);
    GameState* var1 = GameState::GetInstance();
    if (func_0201201c(var1) == 5)
    {
        MapVRAMBanksToLCDC(0x1ff);
        func_020ca458(0, (void*)0x06800000, 0xa4000);
        func_020ca458(0xc0, (void*)0x07000000, 0x400);
        func_020ca458(0, (void*)0x05000000, 0x400);
        func_020ca458(0xc0, (void*)0x07000400, 0x400);
        func_020ca458(0, (void*)0x05000400, 0x400);
        MapVRAMBanksToLCDC(3);
        MapVRAMBanksToSubBG(0x80);
        func_020c3984(0);
        DISPCNTSUB = (DISPCNTSUB & ~0x1f00) | 0x100;
        BG0CNTSUB &= ~3;
        unsigned short var2 = BG0CNTSUB;
        var2 &= 0x43;
        var2 |= 0xf00;
        BG0CNTSUB = var2;
        SUB_BG0_SCROLL = 0;

        int var3;
        BackgroundLoader* var4 = BackgroundLoader::GetInstance();
        var4->MaybeReset();
        var3 = var4->QueueLoadFile(data_ov016_0219cf00, NULL);
        void* var5;
        void* var6;
        unsigned int var7;
        for (;;)
        {
            if (var4->GetTaskStatus(var3) != 0)
            {
                loader->GetLoadedFileByID(task, &archive, &archiveLength);
                int count = Pac_CountFiles((ActiveEntry02046900*)archive);
                BackgroundGraphics background;
                Background_Init((List0204af64*)&background);
                background.screen = 1;
                background.layer = 0;
                Background_SetPriority(&background, 0);
                Background_SetMapSize((unsigned char*)&background, 0);
                for (int index = 0; index < count; index++)
                {
                    int recordLength;
                    char* record = (char*)Pac_GetFile((Rec020467f0*)archive, index, &recordName, &recordLength);
                    if (record != NULL)
                    {
                        Background_FlushFile(&background, record);
                        Background_UploadFile((SelfTag0204b3a0*)&background, record);
                    }
                }
                var4->RemoveTask(var3);
                break;
            }
            var4->RemoveAllLocks();
        }
    }
    else
    {
        MapVRAMBanksToLCDC(0x1ff);
        func_020ca458(0, (void*)0x06800000, 0xa4000);
        DisableLCDCMappedVRAMBanks();
        func_020ca458(0xc0, (void*)0x07000000, 0x400);
        func_020ca458(0, (void*)0x05000000, 0x400);
        func_020ca458(0xc0, (void*)0x07000400, 0x400);
        func_020ca458(0, (void*)0x05000400, 0x400);
        MapVRAMBanksToLCDC(0x1ff);
    }
    func_020c9820();
    data_ov016_0219d0c0.unknown_0_ = arg1;
    func_020c39a0((short*)0x0400006c, 0);
    func_020c39a0((short*)0x0400106c, 0);
    func_ov016_0218ca98(arg0);
    SetInterruptHandler(1, (const void*)func_02012bd8);
}
#else
// USA: func_ov016_0218caa8
extern "C" ARM void func_ov016_0218caa8(char* arg0, void* arg1, Struct_ov016_0218caa8_2* arg2, int arg3, void* arg4)
{
    func_020c39a0((short*)0x0400006c, -16);
    func_020c39a0((short*)0x0400106c, -16);
    data_ov016_0219d0c0.unknown_34_ = arg2;
    data_ov016_0219d0c0.unknown_40_[0] = 0;
    data_ov016_0219d0c0.unknown_40_[1] = 0;
    data_ov016_0219d0c0.unknown_10_ = arg2->unknown_12_ < 0;
    data_ov016_0219d0c0.unknown_0_ = arg3;
    func_020bc078(&data_ov016_0219d0cc);
    if (data_ov016_0219d0c0.unknown_34_->unknown_10_ == 0)
    {
        func_0203aa44(&data_02109bf4);
        func_0203aaf8(&data_02109bf4, (void*)(int)data_ov016_0219d0c0.unknown_34_->unknown_12_, NULL);
    }
    SetInterruptHandler(1, (const void*)func_ov016_0218be1c);
    EnableSpecificInterrupts(0x60078);
    unsigned short var13 = IRQ_MASTER_ENABLE;
    IRQ_MASTER_ENABLE = 1;
    func_020c3864(1);
    GameState* var14 = GameState::GetInstance();
    if (func_0201201c(var14) == 5)
    {
        MapVRAMBanksToLCDC(0x1ff);
        func_020ca458(0, (void*)0x06800000, 0xa4000);
        func_020ca458(0xc0, (void*)0x07000000, 0x400);
        func_020ca458(0, (void*)0x05000000, 0x400);
        func_020ca458(0xc0, (void*)0x07000400, 0x400);
        func_020ca458(0, (void*)0x05000400, 0x400);
        MapVRAMBanksToLCDC(3);
        MapVRAMBanksToSubBG(0x80);
        func_020c3984(0);
        DISPCNTSUB = (DISPCNTSUB & ~0x1f00) | 0x100;
        BG0CNTSUB &= ~3;
        unsigned short var15 = BG0CNTSUB;
        var15 &= 0x43;
        var15 |= 0xf00;
        BG0CNTSUB = var15;
        SUB_BG0_SCROLL = 0;

        void* buffer = AllocateAligned4_02012d88(&data_02114e20, 0x2000);
        SafeAllocator allocator;
        allocator.ResetAllocatorPointer();
        allocator.ResetAllocatorPointer();
        allocator.CreateTypeA(buffer, 0x2000);
        BackgroundGraphics background;
        Background_Init((List0204af64*)&background);
        background.screen = 1;
        background.layer = 0;
        Background_SetPriority(&background, 0);
        Background_SetMapSize((unsigned char*)&background, 0);
        Background_AllocateMap((AllocTarget0204b12c*)&background, &allocator);
        Background_AllocateScreens((Foo0204af38*)&background, 5, &allocator);
        int task;
        BackgroundLoader* loader = BackgroundLoader::GetInstance();
        loader->MaybeReset();
        task = loader->QueueLoadFile(data_ov016_0219d030, NULL);
        void* recordName;
        void* archive;
        unsigned int archiveLength;
        for (;;)
        {
            if (var20->GetTaskStatus(var19) != 0)
            {
                loader->GetLoadedFileByID(task, &archive, &archiveLength);
                int count = Pac_CountFiles((ActiveEntry02046900*)archive);
                for (int index = 0; index < count; index++)
                {
                    int recordLength;
                    void* record = Pac_GetFile((Rec020467f0*)archive, index, &recordName, &recordLength);
                    if (record != NULL)
                    {
                        Background_LoadFile(&background, record, &allocator, recordLength);
                    }
                }
                var20->RemoveTask(var19);
                int var28 = 0;
                switch (func_0200fb08((Struct_02000c9c_8*)var14))
                {
                case 2:
                    var28 = 1;
                    break;
                case 3:
                    var28 = 3;
                    break;
                case 4:
                    var28 = 2;
                    break;
                case 5:
                    var28 = 4;
                    break;
                }
                Background_DrawScreen((Obj0204b8d0*)&background, 0, 0, 0, 0, 0, 32, 25, 0xffff);
                if (selection > 0)
                {
                    Background_DrawScreen((Obj0204b8d0*)&background, (unsigned char)selection, 0, 0, 0, 17, 32, 25, 0xffff);
                }
                Background_UploadMap((List0204b0e8*)&background, NULL);
                break;
            }
            var20->RemoveAllLocks();
        }
        if (var17.GetSignedAllocator() != NULL)
        {
            var17.Destroy();
        }
        if (var16 != NULL)
        {
            func_02012da4(&data_02114e20, var16);
        }
    }
    else
    {
        MapVRAMBanksToLCDC(0x1ff);
        func_020ca458(0, (void*)0x06800000, 0xa4000);
        DisableLCDCMappedVRAMBanks();
        func_020ca458(0xc0, (void*)0x07000000, 0x400);
        func_020ca458(0, (void*)0x05000000, 0x400);
        func_020ca458(0xc0, (void*)0x07000400, 0x400);
        func_020ca458(0, (void*)0x05000400, 0x400);
        MapVRAMBanksToLCDC(0x1ff);
    }
    func_020c9820();
    data_ov016_0219d0c0.unknown_8_ = arg1;
    func_020c39a0((short*)0x0400006c, 0);
    func_020c39a0((short*)0x0400106c, 0);
    func_ov016_0218c04c(arg0, arg4);
    SetInterruptHandler(1, (const void*)func_02012bd8);
}
#endif
