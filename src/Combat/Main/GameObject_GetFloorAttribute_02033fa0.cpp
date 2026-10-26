#include <globaldefs.h>

enum { GameObject_floorAttributeOffset = 0x114 };  // GameObject_SetFloorAttribute stores it

// Main, originally GetPtrField0x114_02033fa0 (USA 0x02033fa0, EUR 0x02033fb0, JPN 0x02033ad8)
extern "C" ARM void* GameObject_GetFloorAttribute(void* object) {
    return (char*)object + GameObject_floorAttributeOffset;
}
