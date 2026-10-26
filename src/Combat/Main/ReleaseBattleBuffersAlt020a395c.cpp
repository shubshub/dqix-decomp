#include <globaldefs.h>
#if defined(jpn)
#define BUFFER_OFFSET 0x1dc
#define OWNED_OFFSET 0x1e0
#else
#define BUFFER_OFFSET 0x48c
#define OWNED_OFFSET 0x490
#endif
#include "NitroSDK/Memory/AllocatorUnion.h"
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

extern "C" void ROMFilesystem_InitFileTables(void);
void AllocatorUnion_Free(AllocatorUnion* alloc, void* data);
extern AllocatorUnion g_mainAllocator;

// USA: func_020a395c  (semantic: ReleaseBattleBuffersAlt020a395c)
extern "C" ARM void func_020a395c(void) {
    GameState* battleStruct = GameState::GetInstance();
    int base = ((int)GetGameResources());
    unsigned char* word = battleStruct->GetTreasureMapLanguageData();
    AllocatorUnion_Free(&g_mainAllocator, *(void**)(base + 0x4000 + BUFFER_OFFSET));
    AllocatorUnion_Free(&g_mainAllocator, word);
    if (*(unsigned char*)(base + 0x4000 + OWNED_OFFSET) != 0) {
        ROMFilesystem_InitFileTables();
        *(unsigned char*)(base + 0x4000 + OWNED_OFFSET) = 0;
    }
    battleStruct->SetTreasureMapLanguageDataPtr(0);
    *(void**)(base + 0x4000 + BUFFER_OFFSET) = 0;
}

