#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/GPC.h"
#include "GameState/GameState.h"
extern unsigned char g_fileLoadBuffer[0x30000] __attribute__((aligned(4)));
#include "Filesystem/FileIO.h"

struct Struct0200fb08;
struct FlagWord02046708;
int GameState_GetLanguage(Struct0200fb08*);
FlagWord02046708* GlobalFlags_GetInstance();
int FlagWord_TestBits(FlagWord02046708*, unsigned int);
extern "C" void __clear(void*, unsigned int);

struct Struct_0207568c : GPCReadPair {
    Struct_0207568c() {
        GPCReadPair* var0 = this;
        ZeroInitGPCPointer(&var0->pGPCFile);
        var0->ZeroInitializeMachine();
    }
};

// KEEP-NAME: the ROM symbol here is the mangled C++ name, not a func_ tag.
// USA: func_0207568c
extern "C" ARM void* ExtractFileFromGP2(const char* arg0, const char* arg1, unsigned int* arg2) {
    if (arg2 != NULL) *arg2 = 0;
    BackgroundLoader::FreeAllocationsGlobal();
    GameState* state = GameState::GetInstance();
    char localized[0x80];
    __clear(localized, sizeof(localized));
    StringReplaceLanguageTag(filename, localized, GameState_GetLanguage((Struct0200fb08*)state));
    void* result;
    unsigned int offset;
    unsigned int headerLength = 0;
    unsigned char* buffer = g_fileLoadBuffer;
    unsigned int capacity = 0x30000;
    if (FlagWord_TestBits(GlobalFlags_GetInstance(), 0x02000000)) capacity -= 0x8000;
    ScopedGPCReader pair;
    if (LoadAndDecompressGPCHeaderAndInnerFileInfo(&pair.pGPCFile, pair.machine, archive, buffer, headerLength, capacity, false, NULL)) {
        offset = headerLength;
        unsigned int decompressed = 0;
        DecompressFileFromGPCByName(pair.pGPCFile, pair.machine, buffer + offset, decompressed, capacity - offset, localized);
        *length = decompressed;
        pair.Reset();
        ZeroDestroyGPCPointer(&pair.pGPCFile);
        return buffer + offset;
    } else {
        var2 = NULL;
        var7.Reset();
        ZeroDestroyGPCPointer(&var7.pGPCFile);
    }
    return var2;
}
