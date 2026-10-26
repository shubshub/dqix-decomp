#include <globaldefs.h>

// A terrain polygon's attribute record (func_ov017_02192b48 picks it from the mesh by the polygon's attribute).
// colorA and colorB are RGB555 values the game decodes channel by channel: func_0204bd7c
// turns colorA into the zone-table key 30000 + r*100 + g*10 + b, func_0204be3c does colorB
struct FourHalfwords02033f7c {
    unsigned short colorA;
    unsigned short unknown2;
    unsigned short colorB;
    unsigned short unknown6;
};

extern "C" void TerrainAttribute_Copy(struct FourHalfwords02033f7c* dst, struct FourHalfwords02033f7c* src);

enum { GameObject_floorAttributeOffset = 0x114 };  // GameObject_GetFloorAttribute reads it back

// Main, originally CopyFourHalfwordsToField0x114_02033f6c (USA 0x02033f6c, EUR 0x02033f7c, JPN 0x02033aa4)
extern "C" ARM void GameObject_SetFloorAttribute(void* object, struct FourHalfwords02033f7c* floorAttribute) {
    TerrainAttribute_Copy((struct FourHalfwords02033f7c*)((char*)object + GameObject_floorAttributeOffset), floorAttribute);
}
