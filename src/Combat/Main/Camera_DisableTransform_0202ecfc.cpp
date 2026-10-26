#include <globaldefs.h>

// Camera::flags: Camera_Update applies Camera::transform (+0xf0) to the position and target only while bit 1 is set.
struct Flags0202ecfc {
    char padding0[0x168];
    unsigned int flags;
};

// Main, originally ClearFlag0x1At0x168 (USA 0x0202ecfc, EUR 0x0202ed0c, JPN 0x0202e86c)
ARM void Camera_DisableTransform(struct Flags0202ecfc* camera) {
    camera->flags &= ~0x1;
}
