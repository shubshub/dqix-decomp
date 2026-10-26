#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "GameState/GameState.h"
#include "Filesystem/FileIO.h"
#include "NitroSDK/Memory.h"
#include "std_library_functions.h"
#include "Resource/GameResources.h"


extern "C" void func_020a39d8(SafeAllocator* alloc);
extern "C" void HaltSystem(void);

#if defined(jpn)
extern const char data_020f1bf4[];
#else
extern const char data_020f1a9c[];
extern const char data_020f1ab0[];
#endif

// JPN: func_020a55a0
// USA: func_020a3844
extern "C" ARM int func_020a3844(SafeAllocator* alloc) {
    GameState* battleStruct = GameState::GetInstance();
    GameResources* resources = GetGameResources();
    unsigned char* word = battleStruct->GetTreasureMapLanguageData();
    if (word != 0 || resources->pTMapLanguageOffsets != 0) {
        func_020a39d8(alloc);
    }

    unsigned char* buf = static_cast<unsigned char*>(alloc->Allocate(0x2000));
    resources->pTMapLanguageOffsets = static_cast<TreasureMapLanguageDataOffsets*>(alloc->Allocate(sizeof(TreasureMapLanguageDataOffsets)));

    unsigned int fileSize = 0;
#if defined(jpn)
    if (!LoadFileIntoMemory(data_020f1bf4, buf, &fileSize))
        return 0;
#else
    BackgroundLoader::AddLockGlobal();
    void* extracted = ExtractFileFromGP2(data_020f1a9c, data_020f1ab0, &fileSize);
    memcpy(buf, extracted, fileSize);
    if (fileSize > 0x2000) {
        HaltSystem();
    }
#endif

    unsigned int var6 = 0;
    unsigned int count = 0;
    VectorizedInvertedMemcpy(buf, &count, 4);
    var6 += 4;

    for (unsigned int i = 0; i < count; i++) {
        unsigned char* offsets = (unsigned char*)resources->pTMapLanguageOffsets;
        VectorizedInvertedMemcpy(buf + var6, offsets + i * 4, 4);
        var6 += 4;
    }

#if !defined(jpn)
    BackgroundLoader::RemoveLockGlobal();
#endif
    battleStruct->SetTreasureMapLanguageDataPtr(buf);
    return 1;
}
