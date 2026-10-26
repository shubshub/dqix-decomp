#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

struct Struct_020e0688_2 {
    unsigned char pad0[0x55c];
    unsigned char unknown_55c_;
#if defined(jpn)
    unsigned char pad1[0x6bc - 0x55d];
#else
    unsigned char pad1[0x768 - 0x55d];
#endif
    unsigned char unknown_768_;
    unsigned char pad2[0x9c5 - 0x769];
    unsigned char unknown_9c5_;
    unsigned char pad3[0xa0c - 0x9c6];
    int handle_a0c;
};

struct FlagWord02046708;
extern "C" int FlagWord_TestBits(struct FlagWord02046708* word, unsigned int mask);
extern "C" void* GlobalFlags_GetInstance(void);
extern "C" void MapDisplay_RemoveTask(void* owner, int* handle);
extern "C" void OS_WaitVBlankIntr(void);

struct PacRecord;
extern "C" int Pac_CountFiles(struct PacRecord* entry);

extern "C" void* Pac_GetFile(struct PacRecord* rec, int index, void** out, int* out44);

struct BackgroundGraphics;
extern "C" void Background_Init(struct BackgroundGraphics* obj);

extern "C" void Background_SetMapSize(unsigned char* obj, int value);

extern "C" void Background_SetPriority(void*, int);

extern "C" int Background_SetScroll(struct BackgroundGraphics* obj, int a, int b);

extern "C" void Background_FlushFile(void* obj, char* str);

extern "C" void Background_UploadFile(struct BackgroundGraphics* self, char* str);

extern "C" void Background_UploadMap(struct BackgroundGraphics* obj, void* buf);

extern "C" void Background_Destroy(struct BackgroundGraphics* obj);

struct Struct_020e0688 {
    unsigned char pad0[0x1c];
    unsigned char lo : 4;
    unsigned char hi : 4;
    unsigned char unknown_1d_[3];
};

// USA: func_020e0688
extern "C" ARM void func_020e0688(struct Struct_020e0688_2* self) {
    if (self->unknown_9c5_ == 0) {
        return;
    }

    if (FlagWord_TestBits((struct FlagWord02046708*)GlobalFlags_GetInstance(), 0x41)) {
        return;
    }

    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    int status = loader->GetTaskStatus(self->handle_a0c);
    if (status == 0) {
        return;
    }

    if (status == -1) {
        *(volatile unsigned int*)0x04001000 = (*(volatile unsigned int*)0x04001000 & ~0x1f00) | 0x200;
        self->unknown_768_ = 0;
    } else {
        int recListHead = 0;
        int var3 = 0;
        void* dummyPtr;
        void* arrayC[3];
        int arrayB[3];
        Struct_020e0688 s;

        loader->GetLoadedFileByID(self->handle_a0c, (void**)(&recListHead), (unsigned int*)(&var3));
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
    self->unknown_55c_ = 1;
    self->unknown_9c5_ = 0;
}
