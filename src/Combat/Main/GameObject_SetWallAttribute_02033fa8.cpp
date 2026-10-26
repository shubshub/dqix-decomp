#include <globaldefs.h>

// A terrain polygon's attribute record (func_ov017_02192b48 picks it from the mesh by the polygon's attribute).
// colorA and colorB are RGB555 values the game decodes channel by channel: ConvertColorToDecimalOffset30000
// turns colorA into the zone-table key 30000 + r*100 + g*10 + b, ConvertColorToDecimal_0204be3c does colorB
struct FourHalfwords02033f7c {
    unsigned short colorA;
    unsigned short unknown2;
    unsigned short colorB;
    unsigned short unknown6;
};

void TerrainAttribute_Copy(struct FourHalfwords02033f7c* dst, struct FourHalfwords02033f7c* src);

enum {
    GameObject_flagsE0Offset = 0xe0,
    GameObjectFlagsE0_WallAttribute = 0x80,     // cleared with the wall-hit bit by GameObject_ClearWallHit
    GameObject_wallAttributeOffset = 0x11c,     // GetFieldPtrAt0x11c_02033fc4 reads it back
};

// Main, originally SetFlag0x80AndCopyToField0x11c_02033fa8 (USA 0x02033fa8, EUR 0x02033fb8, JPN 0x02033ae0)
ARM void GameObject_SetWallAttribute(void* object, struct FourHalfwords02033f7c* wallAttribute) {
    *((unsigned char*)object + GameObject_flagsE0Offset) |= GameObjectFlagsE0_WallAttribute;
    TerrainAttribute_Copy((struct FourHalfwords02033f7c*)((char*)object + GameObject_wallAttributeOffset), wallAttribute);
}
