#include <globaldefs.h>
#include "Combat/MapDisplay.h"
#include "Filesystem/BackgroundLoader.h"

struct List0202fec8;

struct PacRecord;
int Pac_CountFiles(PacRecord* entry);

void* Pac_GetFile(PacRecord* rec, int index, void** out, int* out44);

struct BackgroundGraphics;
void Background_Init(BackgroundGraphics* obj);

void Background_SetMapSize(unsigned char* obj, int value);

extern "C" void Background_SetPriority(void*, int);

int Background_SetScroll(BackgroundGraphics* obj, int a, int b);

void Background_FlushFile(void* obj, char* str);

void Background_UploadFile(BackgroundGraphics* self, char* str);

void Background_UploadMap(BackgroundGraphics* obj, void* buf);

void Background_Destroy(BackgroundGraphics* obj);

// USA: func_02020e58
ARM void RefreshRecordListDisplay02020e58(void* self, MapDisplayTaskHandle handle) {
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    void* recListHead = 0;
    unsigned int val2Ignored = 0;
    int r = loader->GetTaskStatus(
#if defined(jpn)
        handle
#else
        *handle
#endif
);
    if (r == -1) {
        *(unsigned int*)0x04001000 = (*(unsigned int*)0x04001000 & ~0x1f00) | 0x200;
        ((MapDisplay*)self)->field768 = 0;
    } else {
        void* dummyPtr;
        void* arrayC[3];
        int arrayB[3];
        BackgroundGraphics s;

        loader->GetLoadedFileByID(
#if defined(jpn)
        handle
#else
        *handle
#endif
, &recListHead, &val2Ignored);
        int count = Pac_CountFiles((PacRecord*)recListHead);
        for (int i = 0; i < count; i++) {
            arrayC[i] = Pac_GetFile((PacRecord*)recListHead, i, &dummyPtr, &arrayB[i]);
        }
        Background_Init((BackgroundGraphics*)&s);
        s.subScreen_ = 1;
        s.bgNumber_ = 0;
        Background_SetPriority(&s, 2);
        Background_SetMapSize((unsigned char*)&s, 0);
        Background_SetScroll((BackgroundGraphics*)&s, 0, 0);
        for (int i = 0; i < count; i++) {
            Background_FlushFile(&s, (char*)arrayC[i]);
            Background_UploadFile((BackgroundGraphics*)&s, (char*)arrayC[i]);
        }
        Background_UploadMap((BackgroundGraphics*)&s, 0);
        Background_Destroy((BackgroundGraphics*)&s);
        ((MapDisplay*)self)->forwardingPending = 1;
    }
    BackgroundLoader* finalLoader = BackgroundLoader::GetInstance();
    finalLoader->RemoveTask(
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
