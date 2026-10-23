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

struct Struct_02012de8;
extern "C" int func_02046708(struct Struct_02012de8* arg0, unsigned int arg1);
extern "C" void* func_020d6c00(void);
extern "C" void func_02022b90(void* arg0, int* arg1);
extern "C" void func_020c9820(void);

struct ActiveEntry02046900;
int Pac_CountFiles(struct ActiveEntry02046900* entry);

struct Rec020467f0;
void* Pac_GetFile(struct Rec020467f0* rec, int index, void** out, int* out44);

struct List0204af64;
void Background_Init(struct List0204af64* obj);

void Background_SetMapSize(unsigned char* obj, int value);

extern "C" void Background_SetPriority(void*, int);

struct Obj0204b5e8;
int Background_SetScroll(struct Obj0204b5e8* obj, int a, int b);

void Background_FlushFile(void* obj, char* str);

struct SelfTag0204b3a0;
void Background_UploadFile(struct SelfTag0204b3a0* self, char* str);

struct List0204b0e8;
void Background_UploadMap(struct List0204b0e8* obj, void* buf);

struct Struct_02020cb8_3;
extern "C" void func_0204afb4(struct Struct_02020cb8_3* arg0);

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

    if (func_02046708((struct Struct_02012de8*)func_020d6c00(), 0x41)) {
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
        int count = Pac_CountFiles((struct ActiveEntry02046900*)recListHead);
        for (int i = 0; i < count; i++) {
            arrayC[i] = Pac_GetFile((struct Rec020467f0*)recListHead, i, &dummyPtr, &arrayB[i]);
        }

        DelayThenSyncBit0_020c9820();
        Background_Init((struct List0204af64*)&s);
        s.lo = 1;
        s.hi = 0;
        Background_SetPriority(&s, 2);
        Background_SetMapSize((unsigned char*)&s, 0);
        Background_SetScroll((struct Obj0204b5e8*)&s, 0, 0);

        for (int i = 0; i < count; i++) {
            Background_FlushFile(&s, (char*)arrayC[i]);
            Background_UploadFile((struct SelfTag0204b3a0*)&s, (char*)arrayC[i]);
        }

        Background_UploadMap((struct List0204b0e8*)&s, 0);
        ResetRecordList0204afb4((struct List0204afb4*)&s);
    }

    func_02022b90(arg0, &arg0->unknown_a0c_);
    arg0->unknown_55c_ = 1;
    arg0->unknown_9c5_ = 0;
}
