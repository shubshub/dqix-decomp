#include <globaldefs.h>

struct ShapeSize {
    short w;
    short h;
};

extern const ShapeSize data_ov003_0217f3b2[];
extern const ShapeSize data_ov003_0217f3b4[];

// Overlay 3, originally func_ov003_0215ec68 (USA/EUR 0x0215ec68; JPN not identified)
extern "C" ARM void Keyboard_GetKeySize(int size, short* width, short* height) {
    *width = data_ov003_0217f3b2[size].w;
    *height = data_ov003_0217f3b4[size].w;
}
