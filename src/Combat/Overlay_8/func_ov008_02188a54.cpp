#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include <Filesystem/BackgroundLoader.h>
#include <Memory/SafeAllocator.h>
#include <Resource/Brightness.h>
#include <Resource/CharacterCreationUI.h>
#include <Combat/MapDisplay.h>
#include "Resource/GameResources.h"

struct Struct_0205d6a0;
struct Struct_02020cb8_5;
struct Struct_0204b12c;
struct Struct_0204af38;
struct Struct_02020cb8_4;
struct Struct_02020aec;
struct Struct_0204b8d0;
struct Struct_02020cb8_2;
struct Struct_0204c7a8;
struct Struct_0205cf78;
struct Struct_0205cf78_2;
struct Struct_02081870_2 {
    char unknown_0_[0x98];
    Struct_02020cb8* unknown_98_;
    char unknown_9c_[0xb2 - 0x9c];
    unsigned char unknown_b2_;
    char unknown_b3_[0xbc - 0xb3];
};
struct Struct_ov006_02158478 {
    Struct_ov006_02158478* unknown_0_;
    Struct_02020cb8* unknown_4_;
    char unknown_8_[0xe0 - 8];
};
struct Struct_ov008_021842a0_2 {
    char unknown_0_[0x14];
    SafeAllocator unknown_14_;
    char unknown_28_[0xa0 - 0x28];
    Struct_0201099c_3 unknown_a0_;
    char unknown_a8_[0xf0 - 0xa8];
    Struct_02020cb8 unknown_f0_;
    Struct_02020cb8 unknown_110_;
    Struct_02081870_2 unknown_130_;
    Struct_ov006_02158478 unknown_1ec_[6];
    int unknown_72c_;
    char unknown_730_[0xb12 - 0x730];
    unsigned char unknown_b12_;
    char unknown_b13_[0xb20 - 0xb13];
    int unknown_b20_;
};

const char* KeyTable_Get(Container020e0310*, int);
void ResetEntryList0205d6a0(Entry_0205d6a0*, int);
void Background_Init(List0204af64*);
void Background_SetMapSize(unsigned char*, int);
extern "C" void Background_SetPriority(List0204af64*, int);
void Background_SetScroll(Obj0204b5e8*, int, int);
void Background_AllocateMap(AllocTarget0204b12c*, SafeAllocator*);
void Background_AllocateScreens(Foo0204af38*, int, SafeAllocator*);
int Pac_CountFiles(ActiveEntry02046900*);
void* Pac_GetFile(Rec020467f0*, int, void**, int*);
extern "C" void Background_LoadFile(List0204af64*, void*, SafeAllocator*, int);
void Background_DrawScreen(Obj0204b8d0*, unsigned int, int, int, short, short, short, short, unsigned short);
void Background_UploadMap(List0204b0e8*, void*);
extern "C" void Background_FillRect(List0204af64*, int, int, int, int, int, int);
void WindowPane_AllocateBuffer(Obj0204c7a8*, SafeAllocator*, int, unsigned int);
void Window_SetPanes(Struct_0205cf78*, Elem_0205cf78*, unsigned char);

// USA: func_ov008_02188a54
extern "C" ARM int func_ov008_02188a54(Struct_ov008_021842a0_2* arg0, int arg1) {
    GameResources* var0 = GetGameResources();
    BackgroundLoader* var1 = BackgroundLoader::GetInstance();
    int var2 = arg0->unknown_b12_;
    if (var2 == 0) {
#if defined(jpn)
        int fileKey = 1;
        if (lastClear) fileKey = 2;
        const char* file = KeyTable_Get(&self->texts, fileKey);
        self->task = loader->QueueLoadFile(file, 0);
#else
        int var5 = 1;
        int var6 = 2;
        if (arg1) {
            var5 = 3;
            var6 = 4;
        }
        const char* file = KeyTable_Get(&self->texts, fileKey);
        const char* archive = KeyTable_Get(&self->texts, archiveKey);
        self->task = loader->QueueLoadFileInGP2(archive, file, 0);
#endif
        ++arg0->unknown_b12_;
    }
    if (var2 == 1) {
        if (IsBrightnessTransitionActive(var0)) return 0;
        func_0205d6a0((Struct_0205d6a0*)&arg0->unknown_130_, 1);
        ++arg0->unknown_b12_;
    }
    if (step == 2) {
        if (loader->GetTaskStatus(self->task)) {
            self->backgroundAllocator.Reset();
            Background_Init(&self->background);
            Background_SetMapSize((unsigned char*)&self->background, 0);
            self->background.b1c_lo = 1;
            self->background.b1c_hi = 0;
            Background_SetPriority(&self->background, 1);
            Background_SetScroll((Obj0204b5e8*)&self->background, 0, 0);
            Background_AllocateMap((AllocTarget0204b12c*)&self->background, &self->backgroundAllocator);
            Background_AllocateScreens((Foo0204af38*)&self->background, 1, &self->backgroundAllocator);
            Background_Init(&self->textBackground);
            Background_SetMapSize((unsigned char*)&self->textBackground, 0);
            self->textBackground.b1c_lo = 1;
            self->textBackground.b1c_hi = 1;
            Background_SetPriority(&self->textBackground, 0);
            Background_SetScroll((Obj0204b5e8*)&self->textBackground, 0, 0);
            Background_AllocateMap((AllocTarget0204b12c*)&self->textBackground, &self->backgroundAllocator);
            void* recordData;
            void* data;
            unsigned int size;
            loader->GetLoadedFileByID(self->task, &data, &size);
            int count = Pac_CountFiles((ActiveEntry02046900*)data);
            int recordSize;
            for (int index = 0; index < count; ++index) {
                void* record = Pac_GetFile((Rec020467f0*)data, index, &recordData, &recordSize);
                if (record) {
                    if (index == count - 1) Background_LoadFile(&self->textBackground, record, &self->backgroundAllocator, recordSize);
                    else Background_LoadFile(&self->background, record, &self->backgroundAllocator, recordSize);
                }
            }
            loader->RemoveTask(self->task);
            self->task = -1;
            Background_DrawScreen((Obj0204b8d0*)&self->background, 0, 0, 0, 0, 0, 32, 24, 0xffff);
            Background_UploadMap((List0204b0e8*)&self->background, 0);
            Background_FillRect(&self->textBackground, 0, 0, 0, 32, 25, 0);
            Background_UploadMap((List0204b0e8*)&self->textBackground, 0);
            Canvas* canvas;
            for (int index = 0; index < 6; ++index) {
                canvas = &self->canvases[index];
                WindowPane_AllocateBuffer((Obj0204c7a8*)canvas, &self->backgroundAllocator, self->pixels, 512);
                canvas->backgrounds = &self->textBackground;
            }
            self->window.backgrounds = &self->textBackground;
            self->window.enabled = 1;
            Window_SetPanes((Struct_0205cf78*)&self->window, (Elem_0205cf78*)self->canvases, 6);
            self->loadStep = 0;
            return 1;
        }
    }
    return 0;
}
