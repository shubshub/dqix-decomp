#include <globaldefs.h>
#include "Combat/MapDisplay.h"
#include "Filesystem/BackgroundLoader.h"

struct List0202fec8;

struct ActiveEntry02046900;
int Pac_CountFiles(ActiveEntry02046900* entry);

struct Rec020467f0;
void* Pac_GetFile(Rec020467f0* rec, int index, void** out, int* out44);

struct List0204af64;
void Background_Init(List0204af64* obj);

void Background_SetMapSize(unsigned char* obj, int value);

extern "C" void Background_SetPriority(void*, int);

struct Obj0204b5e8;
int Background_SetScroll(Obj0204b5e8* obj, int a, int b);

void Background_FlushFile(void* obj, char* str);

struct SelfTag0204b3a0;
void Background_UploadFile(SelfTag0204b3a0* self, char* str);

struct List0204b0e8;
void Background_UploadMap(List0204b0e8* obj, void* buf);

struct List0204afb4;
void ResetRecordList0204afb4(List0204afb4* obj);

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
        List0204af64 s;

        loader->GetLoadedFileByID(
#if defined(jpn)
        handle
#else
        *handle
#endif
, &recListHead, &val2Ignored);
        int count = Pac_CountFiles((ActiveEntry02046900*)recListHead);
        for (int i = 0; i < count; i++) {
            arrayC[i] = Pac_GetFile((Rec020467f0*)recListHead, i, &dummyPtr, &arrayB[i]);
        }
        Background_Init((List0204af64*)&s);
        s.b1c_lo = 1;
        s.b1c_hi = 0;
        Background_SetPriority(&s, 2);
        Background_SetMapSize((unsigned char*)&s, 0);
        Background_SetScroll((Obj0204b5e8*)&s, 0, 0);
        for (int i = 0; i < count; i++) {
            Background_FlushFile(&s, (char*)arrayC[i]);
            Background_UploadFile((SelfTag0204b3a0*)&s, (char*)arrayC[i]);
        }
        Background_UploadMap((List0204b0e8*)&s, 0);
        ResetRecordList0204afb4((List0204afb4*)&s);
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
