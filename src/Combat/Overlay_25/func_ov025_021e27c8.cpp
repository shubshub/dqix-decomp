#include <globaldefs.h>
#include "std_library_functions.h"
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/FileIO.h"
#include "World/ZoneObjectResourceLoading.h"
#include "GameState/GameState.h"

struct Struct_02000c9c_8;
struct Struct_02057de0_2;
struct Struct_ov025_021e267c_2;
struct Struct_ov025_021e27c8;

struct Struct_ov025_021e267c_3 {
    unsigned char unknown_0_;
    unsigned char unknown_1_;
    unsigned short unknown_2_;
    unsigned short unknown_4_;
    struct Struct_ov025_021e267c_3* unknown_8_;
};

struct Struct_ov025_021ef988_3 {
#if defined(jpn)
    char unknown_0_[4];
    char* unknown_c_;
    char unknown_8_[12];
    int unknown1_8_;
#else
    char unknown1_0_[8];
    int unknown1_8_;
    char* unknown_c_;
#endif

};

extern "C" SafeAllocator* func_ov025_021e8a54(char* arg0);
extern "C" char* func_ov025_021e8a64(char* arg0);
extern "C" Struct_02057de0_2* func_02057924(void);
extern "C" unsigned char func_0200fb08(Struct_02000c9c_8* arg0);
extern "C" int func_ov025_021e24d0(char* arg0, char* arg1, char* arg2);
extern "C" void func_ov025_021e8bac(Struct_ov025_021e267c_2* arg0, Struct_ov025_021e267c_3* arg1);
extern "C" int func_02057de0(Struct_02057de0_2* arg0, int arg1, SafeAllocator* arg2, int arg3, int arg4);
extern "C" void func_ov025_021eb084(Struct_ov025_021e27c8* arg0, int arg1);
extern "C" void __clear(void* arg0, int arg1);

extern Struct_ov025_021ef988_3 data_ov025_021ef988;

// USA: func_ov025_021e27c8
extern "C" ARM void func_ov025_021e27c8(char* arg0, int arg1) {
    char var0[0x50];
    char var1[0x50];
#if defined(jpn)

#else
    char var2[0x50];
#endif

    void* var3;
    unsigned int var4;
    BackgroundLoader* var5 = BackgroundLoader::GetInstance();
    func_ov025_021e8a54(data_ov025_021ef988.unknown_c_);
    func_ov025_021e8a64(data_ov025_021ef988.unknown_c_);
    func_02057924();
#if defined(jpn)

#else
    int var6 = func_0200fb08((Struct_02000c9c_8*)GameState::GetInstance());
#endif

    var3 = 0;
#if defined(jpn)

#else
    __clear(var2, 0x50);
    StringReplaceLanguageTag(arg0, var2, var6);
#endif

    int var7;
    if (func_ov025_021e24d0(arg0, var0, var1)) {
        var7 = var5->GetLoadedFileInArchive(var0, var1, &var3, &var4);
    } else {
#if defined(jpn)
        var7 = var5->GetLoadedFileByName(arg0, &var3, &var4);
#else
        var7 = var5->GetLoadedFileByName(var2, &var3, &var4);
#endif

    }
    void* var8 = var3;
    if (var8 != 0) {
        unsigned int var9 = var4;
        BackgroundLoader::GetInstance();
        char* tables;
        SafeAllocator* alloc;
        void* copy;
        NodeList02057de0* list;
        alloc = GetArrayEntry_021e8a54_021e8a54(data_ov025_021ef988.ui);
        tables = GetArrayEntry_021e8a64_021e8a64(data_ov025_021ef988.ui);
        list = func_02057924();
        copy = alloc->Allocate(len);
        if (copy != 0) {
            memcpy(copy, src, len);
            if (id < 0) id = data_ov025_021ef988.loadedCount + 0x64;
            Node021e8bac* node = (Node021e8bac*)alloc->Allocate(0xc);
            if (node != 0) {
                node->byte0 = 1;
                node->half4 = id;
                PushLogNode021e8bac((Obj021e8bac*)data_ov025_021ef988.ui, node);
                VramState_Restore(tables);
                CreateAndRegisterNode02057de0(list, id, alloc, (int)copy, len);
                VramState_Save(tables);
                data_ov025_021ef988.loadedCount++;
            }
        }
    }
    if (var7 >= 0) {
        var5->RemoveTask(var7);
        func_ov025_021eb084((Struct_ov025_021e27c8*)data_ov025_021ef988.unknown_c_, var7);
    }
}
