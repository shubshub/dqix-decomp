#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "GameState/GameState.h"

extern "C" unsigned short GetSubBGVRAMBanks(void);
extern "C" unsigned short GetSubObjVRAMBanks(void);

struct Struct_02074b64;
extern "C" void func_02074b64(struct Struct_02074b64* arg0);

struct InitTarget0205cfd4;
void Window_Init(struct InitTarget0205cfd4* s);

struct Struct020dfc40;
extern void KeyTable_Reset(Struct020dfc40* p);

struct BackgroundGraphics;
void Background_Init(struct BackgroundGraphics* obj);

extern "C" void WindowPane_Init(void*);

int GameState_GetProtagonistIndex(GameState* battleStruct);

struct Struct_ov023_021e71a0;
extern "C" void func_ov023_021e71a0(struct Struct_ov023_021e71a0* arg0);

// USA: func_ov023_021e7220
extern "C" ARM void func_ov023_021e7220(void* arg0, int arg1) {
#if defined(jpn)
 enum {Enum_ov023_021e7220_1550=0x604};
#else
 enum {Enum_ov023_021e7220_1550=0x60e};
#endif
    ((SafeAllocator*)((char*)obj + 0x0))->ResetAllocatorPointer();
    ((SafeAllocator*)((char*)obj + 0x14))->ResetAllocatorPointer();
    ((SafeAllocator*)((char*)obj + 0x28))->ResetAllocatorPointer();
    GameState* battleStruct = GameState::GetInstance();
    *(int*)((char*)obj + 0x3c) = val;
    *(int*)((char*)obj + 0x40) = GetSubBGVRAMBanks();
    *(int*)((char*)obj + 0x44) = GetSubObjVRAMBanks();
    *(int*)((char*)obj + 0x48) = (*(unsigned int*)0x4001000 & 0x1f00) >> 8;
    *(unsigned char*)((char*)obj + 0x74) = 0;
    *(unsigned char*)((char*)obj + 0x75) = 0;
    BackupSubBgControlRegisters((struct SubBgControlBackup02074b64*)((char*)obj + 0x64));
    Window_Init((struct InitTarget0205cfd4*)((char*)obj + 0x78));
    KeyTable_Reset((Struct020dfc40*)((char*)obj + 0x4c));
    for (int i = 0; i < 2; i++) {
        Background_Init((struct BackgroundGraphics*)((char*)obj + 0x134 + i * 0x20));
    }
    for (int i = 0; i < 5; i++) {
        WindowPane_Init((char*)obj + 0x174 + i * 0xe0);
    }
    *(int*)((char*)obj + 0x5d4) = 0;
    *(int*)((char*)obj + 0x5d8) = 0;
    *(int*)((char*)obj + 0x5dc) = 0;
    *(int*)((char*)obj + 0x5e0) = 0;
    *(int*)((char*)obj + 0x5e4) = -1;
    *(int*)((char*)obj + 0x5ec) = 0;
    *(int*)((char*)obj + 0x5e8) = 0;
    *(int*)((char*)obj + 0x5f0) = GameState_GetProtagonistIndex(battleStruct);
    *(int*)((char*)obj + 0x5f4) = 0;
    *(int*)((char*)obj + 0x5f8) = 0;
    *(int*)((char*)obj + 0x5fc) = 0;
    *(int*)((char*)obj + 0x600) = 0;
#if !defined(jpn)
    *(int*)((char*)arg0 + 0x604) = 0;
    *(int*)((char*)arg0 + 0x608) = 0;
    *(unsigned char*)((char*)arg0 + 0x60c) = 0;
    *(unsigned char*)((char*)arg0 + 0x60d) = 0;
#endif
    func_ov023_021e71a0((struct Struct_ov023_021e71a0*)((char*)arg0 + Enum_ov023_021e7220_1550));
}
