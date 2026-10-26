#include <globaldefs.h>

#if defined(jpn)
enum { Enum_02082fc4_2384 = 0x8b8 };
#else
enum { Enum_02082fc4_2384 = 0x950 };
#endif

#include "Combat/ResourceScriptEntry.h"
#include "Filesystem/BackgroundLoader.h"
#include "std_library_functions.h"
#include "Filesystem/FileIO.h"

extern "C" void* ResourceScriptEntry_Init(void* obj);

extern "C" void PartyMember_ApplyLevelStats(void* a, void* obj, void* tail);
extern "C" void PartyMember_RecalculateStats(void* a, int arg1);

extern char data_020f1019[];
extern unsigned char g_fileLoadBuffer[0x30000];
struct Struct_02082fc4 { unsigned int w[5]; };
struct Struct_02082fc4_2 { unsigned char b[0x18]; };
struct Struct_02082fc4_3 {
    Struct_02082fc4 unknown_0_;
    Struct_02082fc4 unknown_14_;
    Struct_02082fc4 unknown_28_;
    Struct_02082fc4_2 tail;
};

// USA: func_02082fc4
extern "C" ARM void func_02082fc4(void* a, void* b) {
    char path[0x18];
    sprintf(path, data_020f1019, *(int*)((char*)a + Enum_02082fc4_2384));
    BackgroundLoader::AddLockGlobal();
    unsigned int size;
    void* addr = LoadFileIntoMemory(path, &g_fileLoadBuffer, &size);
    if (addr != NULL) {
        Struct_02082fc4_3 local;
        ResourceScriptEntry_Init(&local);
        unsigned short val = *(unsigned short*)((char*)a + *(int*)((char*)a + Enum_02082fc4_2384) * 2 + 0x16c);
        ResourceScriptEntry_LoadLevel(&local, addr, size, val, 0);
        PartyMember_ApplyLevelStats(a, &local, &local.tail);
        PartyMember_RecalculateStats(a, 0);
        if (b != NULL) {
            Struct_02082fc4_3* dst = (Struct_02082fc4_3*)b;
            dst->unknown_0_ = local.unknown_0_;
            dst->unknown_14_ = local.unknown_14_;
            dst->unknown_28_ = local.unknown_28_;
            dst->tail = local.tail;
        }
    }
    BackgroundLoader::RemoveLockGlobal();
}
