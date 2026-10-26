#include <globaldefs.h>
#include "Graphics/Background.h"

void CleanInvalidateCacheRange(const void* p, unsigned int size);

// USA: func_0204bc08
extern "C" ARM void func_0204bc08(BackgroundGraphics* layer, int idx, unsigned char mode, void* addr, unsigned int size) {
    unsigned char sel = layer->subScreen_;
    BackgroundLoadFunction fn = layer->unk_c ? Background_loadPaletteFunctions[sel] : Background_loadPaletteFunctions[sel];
    int shift = 5;
    if (layer->unk_c != 0) {
        mode = 0xff;
        shift = 9;
    }
    int val = (idx & 0xf) << shift;
    val += (mode & 0xf) << 1;
    size &= ~1u;
    CleanInvalidateCacheRange(addr, size);
    fn(addr, val, size);
}
