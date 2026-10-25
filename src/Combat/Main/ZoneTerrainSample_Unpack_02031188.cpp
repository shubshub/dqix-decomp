#include <globaldefs.h>
#include "World/ZoneTerrain.h"

extern "C" ARM void Vector3fix_Set(Vector3fix* v, int x, int y, int z);

// Main, originally func_02031188 (USA 0x02031188, EUR 0x02031198, JPN 0x02030cc0)
extern "C" ARM void ZoneTerrainSample_Unpack(ZoneTerrainSample* sample, short* polygon) {
    Vector3fix_Set(&sample->normal, polygon[9], polygon[10], polygon[11]);
    Vector3fix_Set(&sample->vertices[0], polygon[0], polygon[1], polygon[2]);
    Vector3fix_Set(&sample->vertices[1], polygon[3], polygon[4], polygon[5]);
    Vector3fix_Set(&sample->vertices[2], polygon[6], polygon[7], polygon[8]);
}
