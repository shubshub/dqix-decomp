#include <globaldefs.h>

struct ShapeSize {
    short w;
    short h;
};

extern const ShapeSize Keyboard_keySizes[];
// Keyboard_keySizes seen from +2, so .w here is the height of the same entry: the literal pool has its own address
// for it.
extern const ShapeSize Keyboard_keySizeHeights[];

// Overlay 3, originally func_ov003_0215ec68 (USA/EUR 0x0215ec68; JPN not identified)
extern "C" ARM void Keyboard_GetKeySize(int size, short* width, short* height) {
    *width = Keyboard_keySizes[size].w;
    *height = Keyboard_keySizeHeights[size].w;
}
