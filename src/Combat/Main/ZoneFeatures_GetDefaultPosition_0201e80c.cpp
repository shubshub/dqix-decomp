#include <globaldefs.h>

// ZoneFeatures::vector_70_ (World/ZoneFeatures.h), the party's default position in the zone
struct ThreeWords_1e80c {
    int x;
    int y;
    int z;
};

// A ZoneFeatures (World/ZoneFeatures.h)
struct Owner_1e80c {
    char unk[0x70];
    struct ThreeWords_1e80c defaultPosition;
};

// Main, originally GetThreeWordsAt0x70_0201e80c (USA 0x0201e80c, EUR 0x0201e81c, JPN 0x0201e598)
ARM struct ThreeWords_1e80c ZoneFeatures_GetDefaultPosition(struct Owner_1e80c* features) {
    return features->defaultPosition;
}
