#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"

struct Struct_02013fb4;

struct Struct_0209c0c0 {
    unsigned short unknown_0_[12];
    unsigned short unknown_18_;
};

struct Struct_ov017_021b5070 {
    char unknown_0_[0x10];
    int unknown_10_;
    SafeAllocator* unknown_14_;
#if defined(jpn)
    char unknown_18_[0x40 - 0x18];
#else
    char unknown1_18_[0x44 - 0x18];
#endif

    Struct_0209c0c0 unknown_44_;
    char unknown_5e_[0x60 - 0x5e];
    char unknown_60_[0x124 - 0x60];
    char unknown_124_[1];
};

struct Struct_ov017_021b5070_2 {
    char unknown_0_[8];
    Struct_ov017_021b5070* unknown_8_;
    int unknown_c_;
    unsigned char unknown_10_;
    char unknown_11_[3];
    unsigned char* unknown_14_;
};

extern "C" void __clear(void* arg0, int arg1);
extern "C" void* memset(void* arg0, int arg1, unsigned int arg2);
extern "C" unsigned short func_0209c0c0(Struct_0209c0c0* arg0, Struct_0209c0c0* arg1);
extern "C" void func_0209af58(void* arg0, Struct_02013fb4* arg1, int arg2, int arg3, int arg4);

void* LoadFileIntoMemory(const char* path, void* buffer, unsigned int* outLength);

extern unsigned char g_fileLoadBuffer[0x30000] __attribute__((aligned(4)));
extern char data_ov017_021d7b85[];
extern char data_ov017_021d7b9b[];
extern char data_ov017_021d7bb1[];
#if defined(jpn)
extern char data_ov017_021d82c5[];
#endif

// USA: func_ov017_021b5070
extern "C" ARM void func_ov017_021b5070(Struct_ov017_021b5070_2* arg0) {
    GameState::GetInstance();
    BackgroundLoader* var0 = BackgroundLoader::GetInstance();
    if (!var0->GetTaskStatus(arg0->unknown_c_)) return;
    if (var0->GetDetailedTaskStatus(arg0->unknown_c_) == 2) {
        unsigned int var1;
        void* var2;
        var0->GetLoadedFileByID(arg0->unknown_c_, &var2, &var1);
        if (var2 != NULL) {
            Struct_ov017_021b5070* var3 = arg0->unknown_8_;
#if defined(jpn)
            func_0209af58(var3->unknown_124_, (Struct_02013fb4*)var2, var1, var3->unknown_10_, (int)var3->unknown_60_);
#else
            func_0209af58(var3->unknown_124_, (Struct_02013fb4*)var2, var1, arg0->unknown_8_->unknown_10_, (int)var3->unknown_60_);
#endif

        }
    }
    var0->RemoveTask(arg0->unknown_c_);
    arg0->unknown_c_ = -1;
#if defined(jpn)
    arg0->unknown_c_ = var0->QueueLoadFile(data_ov017_021d82c5, NULL);

#else
    Struct_ov017_021b5070* var4 = arg0->unknown_8_;
    unsigned short var5[12];
    __clear(var5, sizeof(var5));
    short var6 = func_0209c0c0(&var4->unknown_44_, (Struct_0209c0c0*)var5);
    SafeAllocator* var7 = arg0->unknown_8_->unknown_14_;
    unsigned char* var8;
    if (var7 == NULL) {
        var8 = NULL;
    } else if ((unsigned short)var6 == 0) {
        var8 = NULL;
    } else {
        unsigned int var9;
        BackgroundLoader::AddLockGlobal();
        BackgroundLoader::FreeAllocationsGlobal();
        short* data = (short*)LoadFileIntoMemory(data_ov017_021d7b85, g_fileLoadBuffer, &size);
        BackgroundLoader::RemoveLockGlobal();
        if (var10 == NULL) {
            var8 = NULL;
        } else if (var9 == 0) {
            var8 = NULL;
        } else {
            unsigned char* var11;
            int var12;
            int var13;
            int var14;
            var12 = var10[0];
            var11 = (unsigned char*)var10 + (var12 * 2 + 2);
            var8 = (unsigned char*)var7->Allocate(0xc);
            memset(var8, 0, 0xc);
            for (var14 = 0; var14 < (unsigned short)var6; var14++) {
                short var15 = var5[var14];
                short* var16 = var10 + 1;
                for (var13 = 0; var13 < var12; var13++) {
                    if (*var16++ == var15) break;
                }
                if (var13 >= 0 && var13 < var12) {
                    var8[var14] = var11[var13];
                }
            }
        }
    }
    arg0->unknown_14_ = var8;
    arg0->unknown_c_ = var0->QueueLoadFileInGP2(data_ov017_021d7b9b, data_ov017_021d7bb1, NULL);

#endif
    arg0->unknown_10_ = 6;
}
