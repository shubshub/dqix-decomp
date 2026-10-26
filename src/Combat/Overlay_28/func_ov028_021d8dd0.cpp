#if defined(jpn)
#define R(j,u) (j)
#define data_ov001_02164ca4 data_ov001_02166270
#define data_ov028_021d9aa0 data_ov028_021da400
#define func_ov014_02188330 func_ov014_02189234
#define func_ov014_0218854c func_ov014_0218942c
#define func_ov014_021885bc func_ov014_0218948c
#define func_ov015_02191f04 func_ov015_02192a48
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Cache.h"
#include "std_library_functions.h"
#include "GameState/GameState.h"
#include "Resource/Brightness.h"

extern "C" void func_020dc2bc();
extern "C" void func_02074af4(void*);
struct GameResources;
void SetBrightness(GameResources*, int, int);

struct Struct_020978fc;
extern "C" void func_02097bc4(struct Struct_020978fc*, int);
extern "C" void func_02097c18(void*, int, int, int, int, int, int, int);

struct BackgroundGraphics;
extern "C" void Background_Init(BackgroundGraphics*);
extern "C" void Background_SetMapSize(unsigned char*, int);
extern "C" void Background_SetScroll(BackgroundGraphics*, int, int);
extern "C" void Background_FlushFile(void*, char*);
extern "C" void Background_UploadFile(BackgroundGraphics*, char*);

extern "C" void LoadToSubBGStandardPalette(int, int, unsigned int);
extern "C" void LoadToSubBG1ScreenData(int, int, unsigned int);
extern "C" void LoadToSubBG1CharacterData(int, int, unsigned int);

extern "C" void func_ov028_021d98e0(void*, void*, int, int);
int IsBrightnessTransitionActive(GameResources*);

extern int data_ov028_021d9aa0;

// USA: func_ov028_021d8dd0
extern "C" ARM void func_ov028_021d8dd0(unsigned char* self) {
    FontBankLoader* g = FontBankLoader_GetInstance();
    void* data = BackgroundLoader::GetInstance();
    void* battle = GameState::GetInstance();
    void* word = (void*)((GameState*)battle)->GetResources();
    unsigned char state = self[0x81];

    if (state == 0) {
        FontBankLoader_CancelLoads(g);
        func_02094b34(g, 0x7a, 0x20b, 0, 0);
        self[0x81] = self[0x81] + 1;
    } else if (state == 1) {
        if (func_02094b4c(g) != 0) {
            self[0x81] = self[0x81] + 1;
        }
    } else if (state == 2) {
        func_020dc2bc();
        func_02074af4(self + 0xc);
        *(unsigned int*)(self + 0x74) = GetFlags00((GameResources*)word);
        *(unsigned int*)(self + 0x78) = GetFlags04((GameResources*)word);
        *(unsigned int*)(self + 0x7c) = GetFlags08((GameResources*)word);
        SetFlags04((GameResources*)word, 0x90);
        void* buf40 = *(void**)(self + 0x40);
        func_02097bc4((struct Struct_020978fc*)(self + 0x20), 2);
        func_02097c18(self + 0x20, 2, 0, 0, 0, 0, 0x180, 0);

        unsigned short* var6 = (unsigned short*)0x400100a;
        *var6 = (*var6 & 0x43) | 0x1000;

        unsigned char list[0x20];
        Background_Init((BackgroundGraphics*)list);
        unsigned char v = list[0x1c];
        v = (v & ~0xf) | 1;
        v = v & 0xff;
        v = (v & ~0xf0) | 0x10;
        list[0x1c] = v;
        Background_SetMapSize((unsigned char*)list, 0);
        Background_SetScroll((BackgroundGraphics*)list, 0, 0);
        int tag = *(int*)((char*)word + 0x2c);
        Background_FlushFile(list, (char*)tag);
        Background_UploadFile((BackgroundGraphics*)list, (char*)tag);

        unsigned short var10 = 0x67f5;
        memcpy(buf40, &var10, 2);
        CleanInvalidateCacheRange(buf40, 2);
        LoadToSubBGStandardPalette((int)buf40, 0xa, 2);

        unsigned short* p = (unsigned short*)buf40;
        for (unsigned short i = 0; i < 0x400; i++) {
            p[i] = i;
        }

        CleanInvalidateCacheRange(buf40, 0x800);
        LoadToSubBG1ScreenData((int)buf40, 0, 0x800);
        memset(buf40, 0x11111111, 0x8000);
        CleanInvalidateCacheRange(buf40, 0x8000);
        LoadToSubBG1CharacterData((int)buf40, 0, 0x8000);
        void* buf2 = *(void**)(self + 0x40);
        memset(buf2, 0x11111111, 0x8000);
        buf2 = *(void**)(self + 0x40);
        CleanInvalidateCacheRange(buf2, 0x8000);

        unsigned short* var14 = (unsigned short*)0x4001008;
        var14[0] = (var14[0] & ~3) | 1;
        var14[1] = var14[1] & ~3;
        var14[2] = (var14[2] & ~3) | 2;
        var14[3] = (var14[3] & ~3) | 3;
        unsigned int* var15 = (unsigned int*)0x4000000;
        *var15 = (*var15 & ~0x1f00) | 0x1100;
        unsigned int* var16 = (unsigned int*)0x4001000;
        *var16 = (*var16 & ~0x1f00) | 0x200;

        self[0x81] = self[0x81] + 1;
    } else if (state == 3) {
        int r = ((BackgroundLoader*)((int)data))->QueueLoadFile((const char*)((int)&data_ov028_021d9aa0), (SafeAllocator*)(0));
        *(int*)(self + 0x70) = r;
        self[0x81] = self[0x81] + 1;
    } else if (state == 4) {
        if (((BackgroundLoader*)(data))->GetTaskStatus((int)(*(int*)(self + 0x70))) != 0) {
            int a, b;
            ((BackgroundLoader*)(data))->GetLoadedFileByID((int)(*(int*)(self + 0x70)), (void**)(&a), (unsigned int*)(&b));
            if (a != 0 && b != 0) {
                ((SafeAllocator*)(self + 0x44))->Reset();
                func_ov028_021d98e0(self, self + 0x44, a, b);
            }
            ((BackgroundLoader*)(data))->RemoveTask((int)(*(int*)(self + 0x70)));
            *(int*)(self + 0x70) = -1;
            self[0x81] = self[0x81] + 1;
        }
    } else if (state == 5) {
        self[0x81] = state + 1;
        SetBrightness((GameResources*)word, 0, 0x1e);
    } else if (state == 6) {
        if (IsBrightnessTransitionActive((GameResources*)word) == 0) {
            self[0x80] = 1;
            self[0x81] = 0;
        }
    }
}
