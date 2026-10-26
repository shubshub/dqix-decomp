#include <globaldefs.h>
#include "std_library_functions.h"
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/FileIO.h"
#include "World/ZoneObjectResourceLoading.h"
#include "GameState/GameState.h"

struct Struct0200fb08;
struct Struct_02057de0_2;
struct Struct_ov025_021e267c_2;
struct Struct_ov025_021e27c8;

struct Struct_ov025_021e267c_3 {
    unsigned char byte0;
    unsigned char unknown_1_;
    unsigned short unknown_2_;
    unsigned short unknown_4_;
    struct Struct_ov025_021e267c_3* next;
};

struct Struct_ov025_021ef988_3 {
#if defined(jpn)
    char pad0[4];
    char* unknown_c_;
    char pad8[12];
    int unknown1_8_;
#else
    char pad0[8];
    int unknown1_8_;
    char* unknown_c_;
#endif

};

extern "C" SafeAllocator* func_ov025_021e8a54(char* obj);
extern "C" char* func_ov025_021e8a64(char* obj);
extern "C" Struct_02057de0_2* func_02057924(void);
extern "C" unsigned char GameState_GetLanguage(Struct0200fb08* obj);
extern "C" int func_ov025_021e24d0(char* s, char* out2, char* out1);
extern "C" void func_ov025_021e8bac(Struct_ov025_021e267c_2* obj, Struct_ov025_021e267c_3* node);
extern "C" int func_02057de0(Struct_02057de0_2* list, int id, SafeAllocator* alloc, int data, int size);
extern "C" void func_ov025_021eb084(Struct_ov025_021e27c8* obj, int val);
extern "C" void __clear(void* p, int n);

extern Struct_ov025_021ef988_3 data_ov025_021ef988;

// USA: func_ov025_021e27c8
extern "C" ARM void func_ov025_021e27c8(char* name, int id) {
    char archive[0x50];
    char inner[0x50];
#if defined(jpn)

#else
    char path[0x50];
#endif

    void* data;
    unsigned int size;
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    func_ov025_021e8a54(data_ov025_021ef988.unknown_c_);
    func_ov025_021e8a64(data_ov025_021ef988.unknown_c_);
    func_02057924();
#if defined(jpn)

#else
    int language = GameState_GetLanguage((Struct0200fb08*)GameState::GetInstance());
#endif

    data = 0;
#if defined(jpn)

#else
    __clear(path, 0x50);
    StringReplaceLanguageTag(name, path, language);
#endif

    int task;
    if (func_ov025_021e24d0(name, archive, inner)) {
        task = loader->GetLoadedFileInArchive(archive, inner, &data, &size);
    } else {
#if defined(jpn)
        task = loader->GetLoadedFileByName(name, &data, &size);
#else
        task = loader->GetLoadedFileByName(path, &data, &size);
#endif

    }
    void* src = data;
    if (src != 0) {
        unsigned int len = size;
        BackgroundLoader::GetInstance();
        char* tables;
        SafeAllocator* alloc;
        void* copy;
        Struct_02057de0_2* list;
        alloc = func_ov025_021e8a54(data_ov025_021ef988.unknown_c_);
        tables = func_ov025_021e8a64(data_ov025_021ef988.unknown_c_);
        list = func_02057924();
        copy = alloc->Allocate(len);
        if (copy != 0) {
            memcpy(copy, src, len);
            if (id < 0) id = data_ov025_021ef988.unknown1_8_ + 0x64;
            Struct_ov025_021e267c_3* node = (Struct_ov025_021e267c_3*)alloc->Allocate(0xc);
            if (node != 0) {
                node->byte0 = 1;
                node->unknown_4_ = id;
                func_ov025_021e8bac((Struct_ov025_021e267c_2*)data_ov025_021ef988.unknown_c_, node);
                VramState_Restore(tables);
                func_02057de0(list, id, alloc, (int)copy, len);
                VramState_Save(tables);
                data_ov025_021ef988.unknown1_8_++;
            }
        }
    }
    if (task >= 0) {
        loader->RemoveTask(task);
        func_ov025_021eb084((Struct_ov025_021e27c8*)data_ov025_021ef988.unknown_c_, task);
    }
}
