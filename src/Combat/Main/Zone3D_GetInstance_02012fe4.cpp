#include <globaldefs.h>
#include "World/ZoneTerrain.h"

extern Zone3D Zone3D_instance;

// Main, originally func_02012fe4 (USA 0x02012fe4, EUR 0x02012ff4, JPN 0x02012dac)
extern "C" ARM Zone3D* Zone3D_GetInstance(void) {
    return &Zone3D_instance;
}
