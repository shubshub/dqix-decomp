#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"


struct Struct_02074bd0;
extern "C" void func_02074bd0(struct Struct_02074bd0* arg0);
struct Struct_02074bf4;
extern "C" void func_02074bf4(struct Struct_02074bf4* arg0);

struct Obj0204b010;
void Background_ClearMap(struct Obj0204b010* obj, void* p);
extern "C" void Background_FlushMap(void* p, int flag);
extern "C" void Background_TransferMap(void* p, int flag);
struct List0204afb4;
void ResetRecordList0204afb4(struct List0204afb4* obj);
void CleanInvalidateCacheRange(const void* addr, unsigned int size);
extern "C" int LoadToMainBG1CharacterData(int arg0, int arg1, unsigned int arg2);
extern "C" void __clear(void* arg0, int arg1);

// USA: func_ov023_021eb26c
extern "C" ARM void func_ov023_021eb26c(void* arg0) {
    char* var0 = (char*)arg0;
    int var1 = (int)BackgroundLoader::GetInstance();
    if (*(int*)(var0 + 0x434) >= 0) {
        ((BackgroundLoader*)(var1))->RemoveTask((int)(*(int*)(var0 + 0x434)));
        *(int*)(var0 + 0x434) = -1;
    }

    unsigned int* var2 = (unsigned int*)0x4000000;
    *var2 = (*var2 & ~0x1f00) | (*(int*)(var0 + 0x3c) << 8);
    unsigned int* var3 = (unsigned int*)0x4001000;
    *var3 = (*var3 & ~0x1f00) | (*(int*)(var0 + 0x40) << 8);

    func_02074bd0((struct Struct_02074bd0*)(var0 + 0x2a));
    func_02074bf4((struct Struct_02074bf4*)(var0 + 0x2a));

    unsigned char mode = *(unsigned char*)(o + 0x430);
    if (mode == 2 || (mode == 7 && (*(unsigned short*)(o + 0x438) & 8) != 0)) {
        Background_ClearMap((struct Obj0204b010*)(o + 0x44), 0);
        Background_FlushMap(o + 0x44, 0);
        Background_TransferMap(o + 0x44, 0);
        ResetRecordList0204afb4((struct List0204afb4*)(o + 0x44));
        memset(*(void**)(o + 0x420), 0, 0x20);
        CleanInvalidateCacheRange(*(void**)(o + 0x420), 0x20);
        LoadToMainBG1CharacterData(*(int*)(o + 0x420), 0, 0x20);
    }

    *(int*)(var0 + 0x20) = 0;
    *(int*)(var0 + 0x24) = 0;
    *(unsigned char*)(var0 + 0x430) = 0xff;
    *(unsigned char*)(var0 + 0x431) = 0;
    *(unsigned char*)(var0 + 0x432) = 0;
    *(unsigned char*)(var0 + 0x433) = 0;
    *(int*)(var0 + 0x434) = -1;
    *(unsigned short*)(var0 + 0x438) = 0;
    *(unsigned short*)(var0 + 0x43a) = 0;
    *(unsigned char*)(var0 + 0x43c) = 0;
    *(unsigned char*)(var0 + 0x43d) = 0;
    *(unsigned short*)(var0 + 0x43e) = 0;
    *(unsigned short*)(var0 + 0x440) = 0;
    *(unsigned short*)(var0 + 0x442) = 0;
    *(unsigned short*)(var0 + 0x444) = 0;
    *(unsigned short*)(var0 + 0x446) = 0;
    *(unsigned short*)(var0 + 0x448) = 0;

    SafeAllocator* var5[5];
    __clear(var5, 0x14);
    var5[0] = (SafeAllocator*)(*(char**)(var0 + 0));
    var5[1] = (SafeAllocator*)(*(char**)(var0 + 0) + 0x14);
    var5[2] = (SafeAllocator*)(*(char**)(var0 + 0) + 0x28);
    var5[3] = (SafeAllocator*)(*(char**)(var0 + 0) + 0x3c);

    for (int var6 = 0; var5[var6] != 0; var6++) {
        if (var5[var6]->GetSignedAllocator() != 0) {
            var5[var6]->Destroy();
        }
    }
}
