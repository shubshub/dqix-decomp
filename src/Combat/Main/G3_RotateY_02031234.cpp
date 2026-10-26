#include <globaldefs.h>
#include "NitroSDK/Matrix.h"


Matrix4x3 RotationMatrixY(int angle);
extern "C" void G3_MultMtx43(const fix32_t* matrix);

// Main, originally func_02031234 (USA 0x02031234, EUR 0x02031244, JPN 0x02030d6c)
extern "C" ARM void G3_RotateY(int angle) {
    Matrix4x3 rotation;

    if (arg0 == 0) {
        return;
    }

    rotation = RotationMatrixY(angle);
    G3_MultMtx43(rotation.entries);
}
