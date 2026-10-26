#include <globaldefs.h>
#include "Combat/MapDisplay.h"
#include "Filesystem/BackgroundLoader.h"

struct Struct_020534ac;

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

struct BackgroundScreen;
extern "C" void ClearRecordFields(struct BackgroundScreen* rec);
extern "C" void BackgroundScreen_Flush(void* a, void* b);
extern "C" int func_0204a5f8(int a, int b);
typedef void (*Callback0204adb4)(void*, int, int);
extern "C" void BackgroundScreen_Upload(unsigned char* dst, Callback0204adb4 callback, unsigned char* src);
extern "C" void Forward0204acd0(struct BackgroundScreen* rec);

extern "C" void Background_UploadMap(struct BackgroundGraphics* obj, void* buf);

extern "C" void Background_Destroy(struct BackgroundGraphics* obj);

// USA: func_02020cb8
extern "C" ARM void func_02020cb8(void* self, MapDisplayTaskHandle handle) {
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    void* recListHead = 0;
    unsigned int var2 = 0;
    void* dummyPtr;
    void* arrayC[3];
    int arrayB[3];
    BackgroundGraphics s;
    unsigned char struct2[0x10];

    loader->GetLoadedFileByID(
#if defined(jpn)
        handle
#else
        *handle
#endif
, &recListHead, &var2);
    int count = Pac_CountFiles((struct PacRecord*)recListHead);
    for (int i = 0; i < count; i++) {
        arrayC[i] = Pac_GetFile((struct PacRecord*)recListHead, i, &dummyPtr, &arrayB[i]);
    }

    Background_Init((struct BackgroundGraphics*)&s);
    s.subScreen_ = 1;
    s.bgNumber_ = 1;
    Background_SetPriority(&s, 3);
    Background_SetMapSize((unsigned char*)&s, 0);
    Background_SetScroll((struct BackgroundGraphics*)&s, 0, 0);

    s.characterOffset_ = 0x6000;
    s.paletteMask_ = 0xfffe;
    unsigned short* tbl = (unsigned short*)((char*)arrayC[2] + 0x10);
    for (int i = 0; i < 0x300; i++) {
        tbl[i] = tbl[i] + 0x300;
    }

    for (int i = 0; i < 2; i++) {
        Background_FlushFile(&s, (char*)arrayC[i]);
        Background_UploadFile((struct BackgroundGraphics*)&s, (char*)arrayC[i]);
    }

    ClearRecordFields((struct BackgroundScreen*)struct2);
    BackgroundScreen_Flush(struct2, arrayC[2]);
    Callback0204adb4 fn = (Callback0204adb4)func_0204a5f8(1, 1);
    BackgroundScreen_Upload(struct2, fn, (unsigned char*)arrayC[2]);
    Forward0204acd0((struct BackgroundScreen*)struct2);

    Background_UploadMap((struct BackgroundGraphics*)&s, 0);
    Background_Destroy((struct BackgroundGraphics*)&s);

    BackgroundLoader* var14 = BackgroundLoader::GetInstance();
    var14->RemoveTask(
#if defined(jpn)
        handle
#else
        *handle
#endif
);
#if !defined(jpn)
    *handle = -1;
#endif
}
