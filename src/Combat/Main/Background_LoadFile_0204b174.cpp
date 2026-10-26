#include <globaldefs.h>
#include "Graphics/Background.h"
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

extern "C" void __clear(void* buf, int len);
extern "C" int memcmp(void* a, void* b, int n);

struct Rec0204a848;
struct Rec0204acdc;
struct Obj0204aa64;

extern "C" int func_0204a848(Rec0204a848* dst, BackgroundLoadFunction cb, unsigned char* src, void* extra);
extern "C" int func_0204acdc(Rec0204acdc* dst, void* unused, unsigned char* src, SafeAllocator* alloc);
extern "C" int Background_LoadPalette(Obj0204aa64* obj, BackgroundLoadFunction cb, unsigned char* src, void* src2);

// Main, originally func_0204b174 (USA 0x0204b174, EUR 0x0204b184, JPN 0x0204bf94)
extern "C" ARM int Background_LoadFile(struct BackgroundGraphics* layer, char* file, SafeAllocator* allocator) {
    char tag[5];

    if (file == 0) {
        return 1;
    }

    __clear(tag, 5);
    memcpy(tag, file, 5);

    if (memcmp(tag, Background_charTag, 4) == 0) {
        BackgroundLoadFunction load = Background_loadCharacterFunctions[layer->subScreen_][layer->bgNumber_];
        return func_0204a848((Rec0204a848*)layer, load, (unsigned char*)file, (void*)allocator);
    }

    if (memcmp(tag, Background_paltTag, 4) == 0) {
        BackgroundLoadFunction load = Background_loadPaletteFunctions[layer->subScreen_];
        return Background_LoadPalette((Obj0204aa64*)&layer->unk_c, load, (unsigned char*)file, (void*)allocator);
    }

    if (memcmp(tag, Background_scrnTag, 4) == 0) {
        if (layer->screens_ != 0) {
            if (layer->screenCapacity_ <= layer->screenCount_) {
                return 1;
            }
            int result = func_0204acdc((Rec0204acdc*)&layer->screens_[layer->screenCount_],
                                           (void*)Background_loadScreenFunctions[layer->subScreen_][layer->bgNumber_],
                                           (unsigned char*)file, allocator);
            if (result != 0) {
                return 1;
            }
            layer->screenCount_ = layer->screenCount_ + 1;
            return 0;
        }
    }

    return 1;
}
