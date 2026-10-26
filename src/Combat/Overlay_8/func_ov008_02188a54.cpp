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

struct Entry_0205d6a0;
struct BackgroundGraphics;
struct PacRecord;
struct WindowPane;
struct Struct_0205cf78;
struct WindowPane;
struct TextWindow {
    char pad0[0x98];
    BackgroundGraphics* backgrounds;
    char pad1[0xb2 - 0x9c];
    unsigned char enabled;
    char pad2[0xbc - 0xb3];
};
struct Canvas {
    Canvas* previous;
    BackgroundGraphics* backgrounds;
    char pad0[0xe0 - 8];
};
struct Struct_ov008_021842a0_2 {
    char pad0[0x14];
    SafeAllocator backgroundAllocator;
    char pad1[0xa0 - 0x28];
    Container020e0310 texts;
    char pad2[0xf0 - 0xa8];
    BackgroundGraphics background;
    BackgroundGraphics textBackground;
    TextWindow window;
    Canvas canvases[6];
    int pixels;
    char pad3[0xb12 - 0x730];
    unsigned char loadStep;
    char pad4[0xb20 - 0xb13];
    int task;
};

extern "C" const char* KeyTable_Get(Container020e0310*, int);
extern "C" void Window_ClosePane(Entry_0205d6a0*, int);
extern "C" void Background_Init(BackgroundGraphics*);
extern "C" void Background_SetMapSize(unsigned char*, int);
extern "C" void Background_SetPriority(BackgroundGraphics*, int);
extern "C" void Background_SetScroll(BackgroundGraphics*, int, int);
extern "C" void Background_AllocateMap(BackgroundGraphics*, SafeAllocator*);
extern "C" void Background_AllocateScreens(BackgroundGraphics*, int, SafeAllocator*);
extern "C" int Pac_CountFiles(PacRecord*);
extern "C" void* Pac_GetFile(PacRecord*, int, void**, int*);
extern "C" void Background_LoadFile(BackgroundGraphics*, void*, SafeAllocator*, int);
extern "C" void Background_DrawScreen(BackgroundGraphics*, unsigned int, int, int, short, short, short, short, unsigned short);
extern "C" void Background_UploadMap(BackgroundGraphics*, void*);
extern "C" void Background_FillRect(BackgroundGraphics*, int, int, int, int, int, int);
extern "C" void WindowPane_AllocateBuffer(WindowPane*, SafeAllocator*, int, unsigned int);
extern "C" void Window_SetPanes(Struct_0205cf78*, WindowPane*, unsigned char);

// USA: func_ov008_02188a54
extern "C" ARM int func_ov008_02188a54(Struct_ov008_021842a0_2* self, int arg1) {
    GameResources* resources = GetGameResources();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    int step = self->loadStep;
    if (step == 0) {
#if defined(jpn)
        int fileKey = 1;
        if (arg1) fileKey = 2;
        const char* file = KeyTable_Get(&self->texts, fileKey);
        self->task = loader->QueueLoadFile(file, 0);
#else
        int archiveKey = 1;
        int fileKey = 2;
        if (arg1) {
            archiveKey = 3;
            fileKey = 4;
        }
        const char* file = KeyTable_Get(&self->texts, fileKey);
        const char* archive = KeyTable_Get(&self->texts, archiveKey);
        self->task = loader->QueueLoadFileInGP2(archive, file, 0);
#endif
        ++self->loadStep;
    }
    if (step == 1) {
        if (IsBrightnessTransitionActive(resources)) return 0;
        Window_ClosePane((Entry_0205d6a0*)&self->window, 1);
        ++self->loadStep;
    }
    if (step == 2) {
        if (loader->GetTaskStatus(self->task)) {
            self->backgroundAllocator.Reset();
            Background_Init(&self->background);
            Background_SetMapSize((unsigned char*)&self->background, 0);
            self->background.subScreen_ = 1;
            self->background.bgNumber_ = 0;
            Background_SetPriority(&self->background, 1);
            Background_SetScroll((BackgroundGraphics*)&self->background, 0, 0);
            Background_AllocateMap((BackgroundGraphics*)&self->background, &self->backgroundAllocator);
            Background_AllocateScreens((BackgroundGraphics*)&self->background, 1, &self->backgroundAllocator);
            Background_Init(&self->textBackground);
            Background_SetMapSize((unsigned char*)&self->textBackground, 0);
            self->textBackground.subScreen_ = 1;
            self->textBackground.bgNumber_ = 1;
            Background_SetPriority(&self->textBackground, 0);
            Background_SetScroll((BackgroundGraphics*)&self->textBackground, 0, 0);
            Background_AllocateMap((BackgroundGraphics*)&self->textBackground, &self->backgroundAllocator);
            void* recordData;
            void* data;
            unsigned int size;
            loader->GetLoadedFileByID(self->task, &data, &size);
            int count = Pac_CountFiles((PacRecord*)data);
            int recordSize;
            for (int index = 0; index < count; ++index) {
                void* record = Pac_GetFile((PacRecord*)data, index, &recordData, &recordSize);
                if (record) {
                    if (index == count - 1) Background_LoadFile(&self->textBackground, record, &self->backgroundAllocator, recordSize);
                    else Background_LoadFile(&self->background, record, &self->backgroundAllocator, recordSize);
                }
            }
            loader->RemoveTask(self->task);
            self->task = -1;
            Background_DrawScreen((BackgroundGraphics*)&self->background, 0, 0, 0, 0, 0, 32, 24, 0xffff);
            Background_UploadMap((BackgroundGraphics*)&self->background, 0);
            Background_FillRect(&self->textBackground, 0, 0, 0, 32, 25, 0);
            Background_UploadMap((BackgroundGraphics*)&self->textBackground, 0);
            Canvas* canvas;
            for (int index = 0; index < 6; ++index) {
                canvas = &self->canvases[index];
                WindowPane_AllocateBuffer((WindowPane*)canvas, &self->backgroundAllocator, self->pixels, 512);
                canvas->backgrounds = &self->textBackground;
            }
            self->window.backgrounds = &self->textBackground;
            self->window.enabled = 1;
            Window_SetPanes((Struct_0205cf78*)&self->window, (WindowPane*)self->canvases, 6);
            self->loadStep = 0;
            return 1;
        }
    }
    return 0;
}
