#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

struct Struct_020e0688_2 {
    unsigned char unknown_0_[0x55c];
    unsigned char unknown_55c_;
#if defined(jpn)
    unsigned char unknown_55d_[0x6bc - 0x55d];
#else
    unsigned char unknown1_55d_[0x768 - 0x55d];
#endif
    unsigned char unknown_768_;
    unsigned char unknown_769_[0x9c5 - 0x769];
    unsigned char unknown_9c5_;
    unsigned char unknown_9c6_[0xa0c - 0x9c6];
    int unknown_a0c_;
};

struct FlagWord02046708;
int FlagWord_TestBits(struct FlagWord02046708* word, unsigned int mask);
void* GlobalFlags_GetInstance(void);
void MapDisplay_RemoveTask(void* owner, int* handle);
void OS_WaitVBlankIntr(void);

struct PacRecord;
int Pac_CountFiles(struct PacRecord* entry);

void* Pac_GetFile(struct PacRecord* rec, int index, void** out, int* out44);

struct BackgroundGraphics;
void Background_Init(struct BackgroundGraphics* obj);

void Background_SetMapSize(unsigned char* obj, int value);

extern "C" void Background_SetPriority(void*, int);

int Background_SetScroll(struct BackgroundGraphics* obj, int a, int b);

void Background_FlushFile(void* obj, char* str);

void Background_UploadFile(struct BackgroundGraphics* self, char* str);

void Background_UploadMap(struct BackgroundGraphics* obj, void* buf);

void Background_Destroy(struct BackgroundGraphics* obj);

struct Struct_020e0688 {
    unsigned char unknown_0_[0x1c];
    unsigned char unknown_1c_0_ : 4;
    unsigned char unknown_1c_4_ : 4;
    unsigned char unknown_1d_[3];
};

// USA: func_020e0688
extern "C" ARM void func_020e0688(struct Struct_020e0688_2* arg0) {
    if (arg0->unknown_9c5_ == 0) {
        return;
    }

    if (FlagWord_TestBits((struct FlagWord02046708*)GlobalFlags_GetInstance(), 0x41)) {
        return;
    }

    BackgroundLoader* var0 = BackgroundLoader::GetInstance();
    int var1 = var0->GetTaskStatus(arg0->unknown_a0c_);
    if (var1 == 0) {
        return;
    }

    if (var1 == -1) {
        *(volatile unsigned int*)0x04001000 = (*(volatile unsigned int*)0x04001000 & ~0x1f00) | 0x200;
        arg0->unknown_768_ = 0;
    } else {
        int var2 = 0;
        int var3 = 0;
        void* var4;
        void* var5[3];
        int var6[3];
        Struct_020e0688 var7;

        loader->GetLoadedFileByID(self->handle_a0c, (void**)(&recListHead), (unsigned int*)(&val2Ignored));
        int count = Pac_CountFiles((struct PacRecord*)recListHead);
        for (int i = 0; i < count; i++) {
            arrayC[i] = Pac_GetFile((struct PacRecord*)recListHead, i, &dummyPtr, &arrayB[i]);
        }

        OS_WaitVBlankIntr();
        Background_Init((struct BackgroundGraphics*)&s);
        s.lo = 1;
        s.hi = 0;
        Background_SetPriority(&s, 2);
        Background_SetMapSize((unsigned char*)&s, 0);
        Background_SetScroll((struct BackgroundGraphics*)&s, 0, 0);

        for (int i = 0; i < count; i++) {
            Background_FlushFile(&s, (char*)arrayC[i]);
            Background_UploadFile((struct BackgroundGraphics*)&s, (char*)arrayC[i]);
        }

        Background_UploadMap((struct BackgroundGraphics*)&s, 0);
        Background_Destroy((struct BackgroundGraphics*)&s);
    }

    MapDisplay_RemoveTask(self, &self->handle_a0c);
    self->flag_55c = 1;
    self->flag_9c5 = 0;
}
