#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"


struct Struct_02074bd0;
extern "C" void func_02074bd0(struct Struct_02074bd0* obj);
struct Struct_02074bf4;
extern "C" void func_02074bf4(struct Struct_02074bf4* obj);

struct BackgroundGraphics;
extern "C" void Background_ClearMap(struct BackgroundGraphics* obj, void* p);
extern "C" void Background_FlushMap(void* p, int flag);
extern "C" void Background_TransferMap(void* p, int flag);
extern "C" void Background_Destroy(struct BackgroundGraphics* obj);
void CleanInvalidateCacheRange(const void* addr, unsigned int size);
extern "C" int LoadToMainBG1CharacterData(int arg0, int arg1, unsigned int arg2);
extern "C" void __clear(void* buf, int len);

// USA: func_ov023_021eb26c
extern "C" ARM void func_ov023_021eb26c(void* obj) {
    char* o = (char*)obj;
    int data4 = (int)BackgroundLoader::GetInstance();
    if (*(int*)(o + 0x434) >= 0) {
        ((BackgroundLoader*)(data4))->RemoveTask((int)(*(int*)(o + 0x434)));
        *(int*)(o + 0x434) = -1;
    }

    unsigned int* var2 = (unsigned int*)0x4000000;
    *var2 = (*var2 & ~0x1f00) | (*(int*)(o + 0x3c) << 8);
    unsigned int* var3 = (unsigned int*)0x4001000;
    *var3 = (*var3 & ~0x1f00) | (*(int*)(o + 0x40) << 8);

    func_02074bd0((struct Struct_02074bd0*)(o + 0x2a));
    func_02074bf4((struct Struct_02074bf4*)(o + 0x2a));

    unsigned char mode = *(unsigned char*)(o + 0x430);
    if (mode == 2 || (mode == 7 && (*(unsigned short*)(o + 0x438) & 8) != 0)) {
        Background_ClearMap((struct BackgroundGraphics*)(o + 0x44), 0);
        Background_FlushMap(o + 0x44, 0);
        Background_TransferMap(o + 0x44, 0);
        Background_Destroy((struct BackgroundGraphics*)(o + 0x44));
        memset(*(void**)(o + 0x420), 0, 0x20);
        CleanInvalidateCacheRange(*(void**)(o + 0x420), 0x20);
        LoadToMainBG1CharacterData(*(int*)(o + 0x420), 0, 0x20);
    }

    *(int*)(o + 0x20) = 0;
    *(int*)(o + 0x24) = 0;
    *(unsigned char*)(o + 0x430) = 0xff;
    *(unsigned char*)(o + 0x431) = 0;
    *(unsigned char*)(o + 0x432) = 0;
    *(unsigned char*)(o + 0x433) = 0;
    *(int*)(o + 0x434) = -1;
    *(unsigned short*)(o + 0x438) = 0;
    *(unsigned short*)(o + 0x43a) = 0;
    *(unsigned char*)(o + 0x43c) = 0;
    *(unsigned char*)(o + 0x43d) = 0;
    *(unsigned short*)(o + 0x43e) = 0;
    *(unsigned short*)(o + 0x440) = 0;
    *(unsigned short*)(o + 0x442) = 0;
    *(unsigned short*)(o + 0x444) = 0;
    *(unsigned short*)(o + 0x446) = 0;
    *(unsigned short*)(o + 0x448) = 0;

    SafeAllocator* arr[5];
    __clear(arr, 0x14);
    arr[0] = (SafeAllocator*)(*(char**)(o + 0));
    arr[1] = (SafeAllocator*)(*(char**)(o + 0) + 0x14);
    arr[2] = (SafeAllocator*)(*(char**)(o + 0) + 0x28);
    arr[3] = (SafeAllocator*)(*(char**)(o + 0) + 0x3c);

    for (int i = 0; arr[i] != 0; i++) {
        if (arr[i]->GetSignedAllocator() != 0) {
            arr[i]->Destroy();
        }
    }
}
