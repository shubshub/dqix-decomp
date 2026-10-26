#if defined(jpn)
#define R(j,u) (j)
#define data_ov011_021889a0 data_ov011_02189700
#define data_ov013_02187dd8 data_ov013_02188cf0
#define func_ov006_02154fe4 func_ov006_02156730
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#include "Filesystem/BackgroundLoader.h"
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

struct BackgroundGraphics;
extern "C" void* Background_GetScreen(struct BackgroundGraphics* list, unsigned int index);

void CleanInvalidateCacheRange(const void* where, unsigned int len);
extern "C" void LoadToMainBG1CharacterData(int, int, unsigned int);

extern "C" void Background_UploadMap(struct BackgroundGraphics* obj, void* buf);

struct Struct_02074bd0;
extern "C" void func_02074bd0(struct Struct_02074bd0* obj);

struct Struct_02074bf4;
extern "C" void func_02074bf4(struct Struct_02074bf4* obj);

// USA: func_ov013_02186fa0
extern "C" ARM void func_ov013_02186fa0(unsigned char* obj) {
    FontBankLoader* g = FontBankLoader_GetInstance();
    func_02094b38(g, 0x68);
    FontBankLoader_CancelLoads(g);

    if (obj[R(0x50,0x64)] == 0) {
        void* entry = Background_GetScreen((struct BackgroundGraphics*)(obj + 0x28), 0);
        void* buf;
        if (entry != 0 && (buf = *(void**)((char*)entry + 0xc)) != 0) {
            memset(buf, 0, 0x600);
            CleanInvalidateCacheRange(buf, 0x20);
            LoadToMainBG1CharacterData((int)buf, 0, 0x20);
            Background_UploadMap((struct BackgroundGraphics*)(obj + 0x28), buf);
        }

        func_02074bd0((struct Struct_02074bd0*)(obj + 0x14));
        {
            volatile unsigned int* reg = (unsigned int*)0x4000000;
            *reg = (*reg & ~0x1f00) | (*(unsigned int*)(obj + R(0x4c,0x60)) << 8);
        }
    } else {
        func_02074bf4((struct Struct_02074bf4*)(obj + 0x14));
        {
            volatile unsigned int* reg = (unsigned int*)0x4001000;
            *reg = (*reg & ~0x1f00) | (*(unsigned int*)(obj + R(0x4c,0x60)) << 8);
        }
    }

    if (*(int*)(obj + R(0x48,0x5c)) >= 0) {
        int a = (int)BackgroundLoader::GetInstance();
        ((BackgroundLoader*)(a))->RemoveTask((int)(*(int*)(obj + R(0x48,0x5c))));
        *(int*)(obj + R(0x48,0x5c)) = -1;
    }

    if (*(void**)(obj + 0x0) == 0) return;

    unsigned char i;
    for (i = 0; i < R(4,5); i++) {
        ((SafeAllocator*)(*(void**)(obj + 0x0)))[i].Destroy();
    }
}
