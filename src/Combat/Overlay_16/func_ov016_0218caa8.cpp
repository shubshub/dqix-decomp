#include <globaldefs.h>
#include "Graphics/Background.h"
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Graphics.h"
#include "NitroSDK/Interrupts.h"
#include "NitroSDK/VRAM.h"


#define IRQ_MASTER_ENABLE (*(volatile unsigned short*)0x04000208)
#define SUB_BG0_SCROLL (*(volatile unsigned int*)0x04001010)

struct Struct_ov016_0218caa8_2 {
    unsigned short id;
    unsigned char padding2[2];
    int value;
    const char* unknown_8_;
    const char* unknown_c_;
    unsigned char flags;
    unsigned char fade;
    short scene;
};

struct Struct_ov016_0219d0c0_9 {
    int mode;
    unsigned char padding4[4];
    void* owner;
    unsigned char unknown_c_[4];
    int unknown_10_;
    unsigned char unknown_14_[0x20];
    Struct_ov016_0218caa8_2* node;
    unsigned char padding38[8];
    int displayState[2];
};


struct BackgroundGraphics;
struct PacRecord;
struct Struct0200fb08;

extern "C" void GXx_SetMasterBrightness_(short*, int);
extern "C" void NNS_SndHandleInit(int*);
extern "C" void SoundPlayer_UnloadAll(void*);
extern "C" int SoundPlayer_LoadSeq(void*, void*, int*);
extern "C" void func_ov016_0218be1c();
extern "C" void Main_HandleVBlank();
extern "C" int SetVBlankIrqEnable(int);
extern "C" int func_0201201c(void*);
extern "C" void GXS_SetGraphicsMode(unsigned int);
extern "C" void* AllocatorUnion_AllocateRounded(AllocatorUnion*, unsigned int);
extern "C" void AllocatorUnion_Free(AllocatorUnion*, void*);
extern "C" void Background_Init(BackgroundGraphics*);
extern "C" void Background_SetMapSize(unsigned char*, int);
extern "C" void Background_AllocateMap(BackgroundGraphics*, SafeAllocator*);
extern "C" void Background_AllocateScreens(BackgroundGraphics*, int, SafeAllocator*);
extern "C" int Pac_CountFiles(PacRecord*);
extern "C" void* Pac_GetFile(PacRecord*, int, void**, int*);
extern "C" int GameState_GetLanguage(Struct0200fb08*);
extern "C" void Background_DrawScreen(BackgroundGraphics*, unsigned int, int, int, short, short, short, short, unsigned short);
extern "C" void Background_UploadMap(BackgroundGraphics*, void*);
extern "C" void OS_WaitVBlankIntr();
extern "C" void MIi_CpuClearFast(unsigned int, void*, unsigned int);
extern "C" void Background_SetPriority(BackgroundGraphics*, int);
extern "C" void Background_LoadFile(BackgroundGraphics*, void*, SafeAllocator*, unsigned int);
extern "C" void func_ov016_0218c04c(char*, void*);

#if !defined(jpn)
extern Struct_ov016_0219d0c0_9 data_ov016_0219d0c0;
#endif
extern int data_ov016_0219d0cc;
extern int g_bgmPlayer;
extern AllocatorUnion g_mainAllocator;
extern const char data_ov016_0219d030[];

#if defined(jpn)
struct Struct_ov016_0218caa8 {
    unsigned short id;
    unsigned char padding2[2];
    int value;
    const char* unknown_8_;
    const char* unknown_c_;
    short scene;
};

struct Struct_ov016_0219d0c0_8 {
    void* owner;
    unsigned char padding4[0xc];
    Struct_ov016_0218caa8* node;
    int mode;
    int unknown_18_;
    unsigned char padding1c[0x4c - 0x1c];
    int displayState[2];
};

extern "C" void Background_FlushFile(void*, char*);
extern "C" void Background_UploadFile(BackgroundGraphics*, char*);
extern "C" void func_ov016_0218ca98(char*);
extern const char data_ov016_0219cf00[];
extern Struct_ov016_0219d0c0_8 data_ov016_0219d0c0;

// USA: func_ov016_0218caa8
extern "C" ARM void func_ov016_0218caa8(char* name, void* owner, Struct_ov016_0218caa8* node, int mode)
{
    data_ov016_0219d0c0.node = node;
    data_ov016_0219d0c0.displayState[0] = 0;
    data_ov016_0219d0c0.displayState[1] = 0;
    data_ov016_0219d0c0.unknown_18_ = node->scene < 0;
    data_ov016_0219d0c0.mode = mode;
    GXx_SetMasterBrightness_((short*)0x0400006c, -16);
    GXx_SetMasterBrightness_((short*)0x0400106c, -16);
    SetInterruptHandler(1, (const void*)func_ov016_0218be1c);
    EnableSpecificInterrupts(0x60078);
    unsigned short var0 = IRQ_MASTER_ENABLE;
    IRQ_MASTER_ENABLE = 1;
    SetVBlankIrqEnable(1);
    GameState* gameState = GameState::GetInstance();
    if (func_0201201c(gameState) == 5)
    {
        MapVRAMBanksToLCDC(0x1ff);
        MIi_CpuClearFast(0, (void*)0x06800000, 0xa4000);
        MIi_CpuClearFast(0xc0, (void*)0x07000000, 0x400);
        MIi_CpuClearFast(0, (void*)0x05000000, 0x400);
        MIi_CpuClearFast(0xc0, (void*)0x07000400, 0x400);
        MIi_CpuClearFast(0, (void*)0x05000400, 0x400);
        MapVRAMBanksToLCDC(3);
        MapVRAMBanksToSubBG(0x80);
        GXS_SetGraphicsMode(0);
        DISPCNTSUB = (DISPCNTSUB & ~0x1f00) | 0x100;
        BG0CNTSUB &= ~3;
        unsigned short var2 = BG0CNTSUB;
        var2 &= 0x43;
        var2 |= 0xf00;
        BG0CNTSUB = var2;
        SUB_BG0_SCROLL = 0;

        int task;
        BackgroundLoader* loader = BackgroundLoader::GetInstance();
        loader->ClearQueue();
        task = loader->QueueLoadFile(data_ov016_0219cf00, NULL);
        void* recordName;
        void* archive;
        unsigned int archiveLength;
        for (;;)
        {
            if (loader->GetTaskStatus(task) != 0)
            {
                loader->GetLoadedFileByID(task, &archive, &archiveLength);
                int count = Pac_CountFiles((PacRecord*)archive);
                BackgroundGraphics background;
                Background_Init((BackgroundGraphics*)&background);
                background.subScreen_ = 1;
                background.bgNumber_ = 0;
                Background_SetPriority(&background, 0);
                Background_SetMapSize((unsigned char*)&background, 0);
                for (int index = 0; index < count; index++)
                {
                    int recordLength;
                    char* record = (char*)Pac_GetFile((PacRecord*)archive, index, &recordName, &recordLength);
                    if (record != NULL)
                    {
                        Background_FlushFile(&background, record);
                        Background_UploadFile((BackgroundGraphics*)&background, record);
                    }
                }
                loader->RemoveTask(task);
                break;
            }
            loader->RemoveAllLocks();
        }
    }
    else
    {
        MapVRAMBanksToLCDC(0x1ff);
        MIi_CpuClearFast(0, (void*)0x06800000, 0xa4000);
        DisableLCDCMappedVRAMBanks();
        MIi_CpuClearFast(0xc0, (void*)0x07000000, 0x400);
        MIi_CpuClearFast(0, (void*)0x05000000, 0x400);
        MIi_CpuClearFast(0xc0, (void*)0x07000400, 0x400);
        MIi_CpuClearFast(0, (void*)0x05000400, 0x400);
        MapVRAMBanksToLCDC(0x1ff);
    }
    OS_WaitVBlankIntr();
    data_ov016_0219d0c0.owner = owner;
    GXx_SetMasterBrightness_((short*)0x0400006c, 0);
    GXx_SetMasterBrightness_((short*)0x0400106c, 0);
    func_ov016_0218ca98(name);
    SetInterruptHandler(1, (const void*)Main_HandleVBlank);
}
#else
// USA: func_ov016_0218caa8
extern "C" ARM void func_ov016_0218caa8(char* name, void* owner, Struct_ov016_0218caa8_2* node, int mode, void* script)
{
    GXx_SetMasterBrightness_((short*)0x0400006c, -16);
    GXx_SetMasterBrightness_((short*)0x0400106c, -16);
    data_ov016_0219d0c0.node = node;
    data_ov016_0219d0c0.displayState[0] = 0;
    data_ov016_0219d0c0.displayState[1] = 0;
    data_ov016_0219d0c0.unknown_10_ = node->scene < 0;
    data_ov016_0219d0c0.mode = mode;
    NNS_SndHandleInit(&data_ov016_0219d0cc);
    if (data_ov016_0219d0c0.node->flags == 0)
    {
        SoundPlayer_UnloadAll(&g_bgmPlayer);
        SoundPlayer_LoadSeq(&g_bgmPlayer, (void*)(int)data_ov016_0219d0c0.node->scene, NULL);
    }
    SetInterruptHandler(1, (const void*)func_ov016_0218be1c);
    EnableSpecificInterrupts(0x60078);
    unsigned short var13 = IRQ_MASTER_ENABLE;
    IRQ_MASTER_ENABLE = 1;
    SetVBlankIrqEnable(1);
    GameState* gameState = GameState::GetInstance();
    if (func_0201201c(gameState) == 5)
    {
        MapVRAMBanksToLCDC(0x1ff);
        MIi_CpuClearFast(0, (void*)0x06800000, 0xa4000);
        MIi_CpuClearFast(0xc0, (void*)0x07000000, 0x400);
        MIi_CpuClearFast(0, (void*)0x05000000, 0x400);
        MIi_CpuClearFast(0xc0, (void*)0x07000400, 0x400);
        MIi_CpuClearFast(0, (void*)0x05000400, 0x400);
        MapVRAMBanksToLCDC(3);
        MapVRAMBanksToSubBG(0x80);
        GXS_SetGraphicsMode(0);
        DISPCNTSUB = (DISPCNTSUB & ~0x1f00) | 0x100;
        BG0CNTSUB &= ~3;
        unsigned short var15 = BG0CNTSUB;
        var15 &= 0x43;
        var15 |= 0xf00;
        BG0CNTSUB = var15;
        SUB_BG0_SCROLL = 0;

        void* buffer = AllocatorUnion_AllocateRounded(&g_mainAllocator, 0x2000);
        SafeAllocator allocator;
        allocator.ResetAllocatorPointer();
        allocator.ResetAllocatorPointer();
        allocator.CreateTypeA(buffer, 0x2000);
        BackgroundGraphics background;
        Background_Init((BackgroundGraphics*)&background);
        background.subScreen_ = 1;
        background.bgNumber_ = 0;
        Background_SetPriority(&background, 0);
        Background_SetMapSize((unsigned char*)&background, 0);
        Background_AllocateMap((BackgroundGraphics*)&background, &allocator);
        Background_AllocateScreens((BackgroundGraphics*)&background, 5, &allocator);
        int task;
        BackgroundLoader* loader = BackgroundLoader::GetInstance();
        loader->ClearQueue();
        task = loader->QueueLoadFile(data_ov016_0219d030, NULL);
        void* recordName;
        void* archive;
        unsigned int archiveLength;
        for (;;)
        {
            if (loader->GetTaskStatus(task) != 0)
            {
                loader->GetLoadedFileByID(task, &archive, &archiveLength);
                int count = Pac_CountFiles((PacRecord*)archive);
                for (int index = 0; index < count; index++)
                {
                    int recordLength;
                    void* record = Pac_GetFile((PacRecord*)archive, index, &recordName, &recordLength);
                    if (record != NULL)
                    {
                        Background_LoadFile(&background, record, &allocator, recordLength);
                    }
                }
                loader->RemoveTask(task);
                int selection = 0;
                switch (GameState_GetLanguage((Struct0200fb08*)gameState))
                {
                case 2:
                    selection = 1;
                    break;
                case 3:
                    selection = 3;
                    break;
                case 4:
                    selection = 2;
                    break;
                case 5:
                    selection = 4;
                    break;
                }
                Background_DrawScreen((BackgroundGraphics*)&background, 0, 0, 0, 0, 0, 32, 25, 0xffff);
                if (selection > 0)
                {
                    Background_DrawScreen((BackgroundGraphics*)&background, (unsigned char)selection, 0, 0, 0, 17, 32, 25, 0xffff);
                }
                Background_UploadMap((BackgroundGraphics*)&background, NULL);
                break;
            }
            loader->RemoveAllLocks();
        }
        if (allocator.GetSignedAllocator() != NULL)
        {
            allocator.Destroy();
        }
        if (buffer != NULL)
        {
            AllocatorUnion_Free(&g_mainAllocator, buffer);
        }
    }
    else
    {
        MapVRAMBanksToLCDC(0x1ff);
        MIi_CpuClearFast(0, (void*)0x06800000, 0xa4000);
        DisableLCDCMappedVRAMBanks();
        MIi_CpuClearFast(0xc0, (void*)0x07000000, 0x400);
        MIi_CpuClearFast(0, (void*)0x05000000, 0x400);
        MIi_CpuClearFast(0xc0, (void*)0x07000400, 0x400);
        MIi_CpuClearFast(0, (void*)0x05000400, 0x400);
        MapVRAMBanksToLCDC(0x1ff);
    }
    OS_WaitVBlankIntr();
    data_ov016_0219d0c0.owner = owner;
    GXx_SetMasterBrightness_((short*)0x0400006c, 0);
    GXx_SetMasterBrightness_((short*)0x0400106c, 0);
    func_ov016_0218c04c(name, script);
    SetInterruptHandler(1, (const void*)Main_HandleVBlank);
}
#endif
