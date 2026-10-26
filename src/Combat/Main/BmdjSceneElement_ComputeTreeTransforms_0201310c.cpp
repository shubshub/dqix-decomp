#include <globaldefs.h>

extern "C" void __clear(void* buf, int n);
extern "C" void BmdjSceneElement_ComputeTransforms(void* a, void* b, void* c, void* d);

// (0x1000, 0x1000, 0x1000): a scale of 1.0 on each axis
struct Struct_020e6dfc { unsigned int v[3]; };
extern Struct_020e6dfc data_020e6dfc;

// Main, originally InitWithUnitScaleVec0201310c (USA 0x0201310c, EUR 0x0201311c, JPN 0x02012ed4)
extern "C" ARM void BmdjSceneElement_ComputeTreeTransforms(void* firstNode) {
    char origin[12];
    int angle;
    Struct_020e6dfc scale;
    __clear(origin, 0xc);
    scale = data_020e6dfc;
    angle = 0;
    BmdjSceneElement_ComputeTransforms(firstNode, origin, &angle, &scale);
}
