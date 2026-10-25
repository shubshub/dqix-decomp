#include <globaldefs.h>
#include "Graphics/Background.h"
#include "std_library_functions.h"

extern "C" void __clear(void* buf, int len);
extern "C" int memcmp(void* a, void* b, int n);

void TileHeader_Flush(char* dst, char* src);

struct HeaderAt0204ab4c;
struct BufferAt0204ab4c;
void InvalidateDirtyCacheBlocks(struct HeaderAt0204ab4c* header, struct BufferAt0204ab4c* buffer);

void ClearRecordFields(struct BackgroundScreen* rec);
void BackgroundScreen_Flush(void* a, void* b);

// Main, originally DispatchByTag0204b2e0 (USA 0x0204b2e0, EUR 0x0204b2f0, JPN 0x0204c100)
ARM void Background_FlushFile(void* layer, char* file) {
    char tag[5];

    if (file == 0) {
        return;
    }

    __clear(tag, 5);
    memcpy(tag, file, 5);

    if (memcmp(tag, Background_charTag, 4) == 0) {
        TileHeader_Flush((char*)layer, file);
        return;
    }

    if (memcmp(tag, Background_paltTag, 4) == 0) {
        InvalidateDirtyCacheBlocks((struct HeaderAt0204ab4c*)((char*)layer + 0xc), (struct BufferAt0204ab4c*)file);
        return;
    }

    if (memcmp(tag, Background_scrnTag, 4) == 0) {
        struct BackgroundScreen screen;
        ClearRecordFields(&screen);
        BackgroundScreen_Flush(&screen, file);
    }
}
