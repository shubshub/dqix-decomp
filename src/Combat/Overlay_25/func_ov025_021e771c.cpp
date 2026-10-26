#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/GPC.h"
#include "Memory/SafeAllocator.h"
#include "Resource/GameResources.h"

struct Struct_ov025_021e771c {
    unsigned char data[0xc];
};

struct Struct_ov025_021e771c_2 {
    char pad[0x678];
    Struct_ov025_021e771c tableA;
    Struct_ov025_021e771c tableB;
};

struct Struct_ov025_021e771c_3 {
    char pad[0x44 - sizeof(SafeAllocator)];
    SafeAllocator allocs[2];
    SafeAllocator* inline_ov025_021e771c(int i) { return &allocs[i]; }
};

extern "C" Struct_ov025_021e771c_2* func_ov017_021b8478(void* node);
extern "C" Struct_ov025_021e771c_3* func_ov000_02160130(void);
extern "C" void func_ov000_02166804(Struct_ov025_021e771c_3* work);
void* LoadFileIntoMemory(const char* path, void* dst, unsigned int* outSize);
extern "C" void* ExtractFileFromGP2(const char* arg0, const char* innerFilePath, unsigned int* outSize);
extern "C" void* func_020709d8(void* obj);
extern "C" void* func_0206efc4(void* obj);
extern "C" void func_02070b6c(void* table, void* owner, void* data, unsigned int size, int a, int b);
#if defined(jpn)
extern "C" void func_0206f230(void* table, void* owner, void* data, unsigned int size, int a, int b);
#else
extern "C" void func_0206f230(void* table, void* owner, void* data, unsigned int size, int a, int b, int c, int d);
#endif

extern "C" unsigned int func_ov000_02166008(void* unused, GPCReadPair* arg1, int flag);
extern "C" void func_ov000_02166070(Struct_ov025_021e771c_3* work, GPCReadPair* arg1, int index, int id, int flag, unsigned int length);
extern "C" void func_ov000_0216638c(void* unused, GPCReadPair* pair, int flag);

#if defined(jpn)
extern char data_ov025_021efb1e[];
extern char data_ov025_021efb3a[];
#endif
extern char data_ov025_021ef83e[];
extern char g_fileLoadBuffer[];
extern char data_ov025_021ef857[];
extern char data_ov025_021ef86d[];

// USA: func_ov025_021e771c
extern "C" ARM int func_ov025_021e771c(short* ids, int count, int a, int b) {
    GameResources* resources = GetGameResources();
    GameState::GetInstance();
    Struct_ov025_021e771c_2* res = func_ov017_021b8478(resources->unknown_ptr_3718);
    Struct_ov025_021e771c_3* work = func_ov000_02160130();
    func_ov000_02166804(work);
    Struct_ov025_021e771c* tableA = &res->tableA;
    Struct_ov025_021e771c* tableB = &res->tableB;
    SafeAllocator* owner = work->inline_ov025_021e771c(1);
    BackgroundLoader::AddLockGlobal();
    unsigned int size;
#if defined(jpn)
    void* data = LoadFileIntoMemory(data_ov025_021efb1e, g_fileLoadBuffer, &size);
#else
    void* data = LoadFileIntoMemory(data_ov025_021ef83e, g_fileLoadBuffer, &size);
#endif

    if (data != 0) {
        func_020709d8(tableB);
        func_02070b6c(tableB, owner, data, size, a, b);
#if defined(jpn)
        void* data2 = LoadFileIntoMemory(data_ov025_021efb3a, g_fileLoadBuffer, &size);
#else
        void* data2 = ExtractFileFromGP2(data_ov025_021ef857, data_ov025_021ef86d, &size);
#endif

        if (data2 != 0) {
            func_0206efc4(tableA);
#if defined(jpn)
            func_0206f230(tableA, owner, data2, size, a, b);
#else
            func_0206f230(tableA, owner, data2, size, a, b, 0, 0);
#endif

            GPCReadPair pair;
            GPCReadPair* var10 = &pair;
            var10++;
            ZeroInitGPCPointer(&(var10 - 1)->pGPCFile);
            (var10 - 1)->ZeroInitializeMachine();
            unsigned int length = func_ov000_02166008(work, &pair, 0);
            for (int i = 0; i < count; i++) {
                func_ov000_02166070(work, &pair, i, ids[i], 0, length);
            }
            func_ov000_0216638c(work, &pair, 0);
            pair.Reset();
            ZeroDestroyGPCPointer(&pair.pGPCFile);
        }
    }
    BackgroundLoader::RemoveLockGlobal();
    return 1;
}
