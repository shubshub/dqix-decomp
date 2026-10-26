#include <globaldefs.h>
#include "Graphics/Background.h"
#include "std_library_functions.h"

extern "C" void __clear(void* buf, int len);
extern "C" int memcmp(void* a, void* b, int n);

// The table functions as the upload functions' C++ symbols type them: (void* source, int offset, int size).
typedef void (*BackgroundUploadFunction)(void*, int, int);

extern "C" void Background_UploadCharacterData(int* a0, BackgroundUploadFunction fn, char* ctx);

struct Obj0204abcc;
struct P0204abcc;
extern "C" void Background_UploadPalette(struct Obj0204abcc* obj, BackgroundUploadFunction fn, struct P0204abcc* p);

extern "C" void BackgroundScreen_Upload(unsigned char* dst, BackgroundUploadFunction callback, unsigned char* src);

extern "C" void ClearRecordFields(struct BackgroundScreen* rec);

// Main, originally DispatchByTagLookup0204b3a0 (USA 0x0204b3a0, EUR 0x0204b3b0, JPN 0x0204c1c0)
extern "C" ARM void Background_UploadFile(struct BackgroundGraphics* layer, char* file) {
    char tag[5];

    if (file == 0) {
        return;
    }

    __clear(tag, 5);
    memcpy(tag, file, 5);

    if (memcmp(tag, Background_charTag, 4) == 0) {
        BackgroundUploadFunction load = (BackgroundUploadFunction)Background_loadCharacterFunctions[layer->subScreen_][layer->bgNumber_];
        Background_UploadCharacterData(&layer->characterOffset_, load, file);
        return;
    }

    if (memcmp(tag, Background_paltTag, 4) == 0) {
        BackgroundUploadFunction load = (BackgroundUploadFunction)Background_loadPaletteFunctions[layer->subScreen_];
        Background_UploadPalette((struct Obj0204abcc*)&layer->unk_c, load, (struct P0204abcc*)file);
        return;
    }

    if (memcmp(tag, Background_scrnTag, 4) == 0) {
        struct BackgroundScreen screen;
        ClearRecordFields(&screen);
        BackgroundUploadFunction load = (BackgroundUploadFunction)Background_loadScreenFunctions[layer->subScreen_][layer->bgNumber_];
        BackgroundScreen_Upload((unsigned char*)&screen, load, (unsigned char*)file);
    }
}
