#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/GPC.h"
#include "Memory/SafeAllocator.h"
#include "Resource/GameResources.h"

struct Struct_ov025_021e771c {
    unsigned char unknown_0_[0xc];
};

struct Struct_ov025_021e771c_2 {
    char unknown_0_[0x678];
    Struct_ov025_021e771c unknown_678_;
    Struct_ov025_021e771c unknown_684_;
};

struct Struct_ov025_021e771c_3 {
    char unknown_0_[0x44 - sizeof(SafeAllocator)];
    SafeAllocator unknown_30_[2];
    SafeAllocator* inline_ov025_021e771c(int arg0) { return &unknown_30_[arg0]; }
};

extern "C" Struct_ov025_021e771c_2* func_ov017_021b8478(void* arg0);
extern "C" Struct_ov025_021e771c_3* func_ov000_02160130(void);
extern "C" void func_ov000_02166804(Struct_ov025_021e771c_3* arg0);
void* LoadFileIntoMemory(const char* path, void* dst, unsigned int* outSize);
extern "C" void* ExtractFileFromGP2(const char* arg0, const char* arg1, unsigned int* arg2);
extern "C" void* func_020709d8(void* arg0);
extern "C" void* func_0206efc4(void* arg0);
extern "C" void func_02070b6c(void* arg0, void* arg1, void* arg2, unsigned int arg3, int arg4, int arg5);
#if defined(jpn)
extern "C" void func_0206f230(void* arg0, void* arg1, void* arg2, unsigned int arg3, int arg4, int arg5);
#else
extern "C" void func_0206f230(void* arg0, void* arg1, void* arg2, unsigned int arg3, int arg4, int arg5, int arg6, int arg7);
#endif

extern "C" unsigned int func_ov000_02166008(void* arg0, GPCReadPair* arg1, int arg2);
extern "C" void func_ov000_02166070(Struct_ov025_021e771c_3* arg0, GPCReadPair* arg1, int arg2, int arg3, int arg4, unsigned int arg5);
extern "C" void func_ov000_0216638c(void* arg0, GPCReadPair* arg1, int arg2);

#if defined(jpn)
extern char data_ov025_021efb1e[];
extern char data_ov025_021efb3a[];
#endif
extern char data_ov025_021ef83e[];
extern char g_fileLoadBuffer[];
extern char data_ov025_021ef857[];
extern char data_ov025_021ef86d[];

// USA: func_ov025_021e771c
extern "C" ARM int func_ov025_021e771c(short* arg0, int arg1, int arg2, int arg3) {
    GameResources* var0 = GetGameResources();
    GameState::GetInstance();
    Struct_ov025_021e771c_2* var1 = func_ov017_021b8478(var0->unknown_ptr_3718);
    Struct_ov025_021e771c_3* var2 = func_ov000_02160130();
    func_ov000_02166804(var2);
    Struct_ov025_021e771c* var3 = &var1->unknown_678_;
    Struct_ov025_021e771c* var4 = &var1->unknown_684_;
    SafeAllocator* var5 = var2->inline_ov025_021e771c(1);
    BackgroundLoader::AddLockGlobal();
    unsigned int var6;
#if defined(jpn)
    void* data = LoadFileIntoMemory(data_ov025_021efb1e, g_fileLoadBuffer, &size);
#else
    void* data = LoadFileIntoMemory(data_ov025_021ef83e, g_fileLoadBuffer, &size);
#endif

    if (var7 != 0) {
        func_020709d8(var4);
        func_02070b6c(var4, var5, var7, var6, arg2, arg3);
#if defined(jpn)
        void* data2 = LoadFileIntoMemory(data_ov025_021efb3a, g_fileLoadBuffer, &size);
#else
        void* var8 = ExtractFileFromGP2(data_ov025_021ef857, data_ov025_021ef86d, &var6);
#endif

        if (var8 != 0) {
            func_0206efc4(var3);
#if defined(jpn)
            func_0206f230(var3, var5, var8, var6, arg2, arg3);
#else
            func_0206f230(var3, var5, var8, var6, arg2, arg3, 0, 0);
#endif

            GPCReadPair var9;
            GPCReadPair* var10 = &var9;
            var10++;
            ZeroInitGPCPointer(&(var10 - 1)->pGPCFile);
            (var10 - 1)->ZeroInitializeMachine();
            unsigned int var11 = func_ov000_02166008(var2, &var9, 0);
            for (int var12 = 0; var12 < arg1; var12++) {
                func_ov000_02166070(var2, &var9, var12, arg0[var12], 0, var11);
            }
            func_ov000_0216638c(var2, &var9, 0);
            var9.Reset();
            ZeroDestroyGPCPointer(&var9.pGPCFile);
        }
    }
    BackgroundLoader::RemoveLockGlobal();
    return 1;
}
