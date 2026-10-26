#include <globaldefs.h>
#include <NitroSDK/Matrix.h>


Matrix4x3 RotationMatrixZ(int angle);
extern "C" void G3_MultMtx43(const fix32_t* matrix);

// Main, originally func_02031278 (USA 0x02031278, EUR 0x02031288, JPN 0x02030db0)
extern "C" ARM void G3_RotateZ(int angle) {
    Matrix4x3 rotation;
    if (angle == 0) return;
    rotation = RotationMatrixZ(angle);
    G3_MultMtx43(rotation.entries);
}
