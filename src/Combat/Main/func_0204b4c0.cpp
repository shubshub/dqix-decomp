#include <globaldefs.h>
#include "Graphics/Background.h"
#include "std_library_functions.h"
extern "C" void __clear(void*, unsigned int);
extern "C" int memcmp(const void*, const void*, unsigned int);
extern "C" void func_0204a9c4(BackgroundGraphics*, unsigned int, unsigned int, const void*);
extern "C" void func_0204ac60(void*, unsigned int, const void*);
extern "C" void ClearRecordFields(BackgroundScreen*);
extern "C" void func_0204ade8(BackgroundScreen*, unsigned int, unsigned int, const void*);

// USA: func_0204b4c0
extern "C" ARM void func_0204b4c0(BackgroundGraphics* layer, const void* data) {
    if (!data) return;
    char header[5];
    BackgroundScreen record;
    __clear(header, 5);
    memcpy(header, data, 5);
    if (memcmp(header, Background_charTag, 4) == 0) {
        func_0204a9c4(layer, layer->subScreen_, layer->bgNumber_, data);
    } else if (memcmp(header, Background_paltTag, 4) == 0) {
        func_0204ac60(&layer->unk_c, layer->subScreen_, data);
    } else if (memcmp(header, Background_scrnTag, 4) == 0) {
        ClearRecordFields(&record);
        func_0204ade8(&record, layer->subScreen_, layer->bgNumber_, data);
    }
}
