#include <globaldefs.h>

// A ZoneFeatures (World/ZoneFeatures.h): angle_7c_, the party's default heading in the zone
struct S_e820 {
    char pad[0x7c];
    short defaultAngle;
};

// Main, originally GetSignedFieldAt0x7c_0201e820 (USA 0x0201e820, EUR 0x0201e830, JPN 0x0201e5ac)
ARM int ZoneFeatures_GetDefaultAngle(struct S_e820* features) {
    return features->defaultAngle;
}
