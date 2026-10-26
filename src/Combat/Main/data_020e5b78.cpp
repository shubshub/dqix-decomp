#include <globaldefs.h>

#pragma define_section initcode ".init" RX

extern float object3DsData[8];
extern float boneTracking[8];

// USA: func_020e5b78
extern "C" __declspec(initcode) ARM void __sinit_020e5b78(void) {
    float t;
    float a;
    float b;
    boneTracking[3] = object3DsData[1] + (object3DsData[2] + (object3DsData[3] + object3DsData[0]));
    t = boneTracking[1] + object3DsData[3];
    a = object3DsData[0];
    boneTracking[4] = t;
    t = t + a;
    b = object3DsData[2];
    boneTracking[2] = t;
    t = t + b;
    boneTracking[0] = t;
}
