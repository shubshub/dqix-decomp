#include <globaldefs.h>
#include "NitroSDK/Matrix.h"


Matrix4x3 RotationMatrixX(int angle);
extern "C" void G3_MultMtx43(const fix32_t* matrix);

// Main, originally func_020311f0 (USA 0x020311f0, EUR 0x02031200, JPN 0x02030d28)
extern "C" ARM void G3_RotateX(int angle) {
    if (angle) {
        Matrix4x3 rotation;
        rotation = RotationMatrixX(angle);
        G3_MultMtx43(rotation.entries);
    }
}
