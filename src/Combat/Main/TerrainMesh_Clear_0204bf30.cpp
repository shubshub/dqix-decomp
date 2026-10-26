#include <globaldefs.h>
#include "std_library_functions.h"

// Main, originally Clear0x4cBytes0204bf30 (USA 0x0204bf30, EUR 0x0204bf40, JPN 0x0204cd50)
extern "C" ARM void* TerrainMesh_Clear(void* obj) {
    return memset(obj, 0, 0x4c);
}
