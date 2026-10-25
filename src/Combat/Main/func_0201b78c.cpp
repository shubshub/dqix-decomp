#include <globaldefs.h>

#include "World/Zone3D.h"
struct Struct_0201b78c {
    int unknown_0_;
    int unknown_4_;
    Vector3fix unknown_8_;
    char unknown_14_[0x28];
    int unknown_3c_;
    char unknown_40_[0x30];
    Struct_0201b78c* unknown_70_;
};
void* ZoneFeatures_GetFirstOfType(unsigned char*, unsigned int);
int Vector3fix_Distance(const Vector3fix*, const Vector3fix*);

// USA: func_0201b78c
extern "C" ARM ProximityNode0201b78c* func_0201b78c(Zone3D* zone, const Vector3fix* input) {
    ProximityNode0201b78c* preferred = 0;
    ProximityNode0201b78c* node = (ProximityNode0201b78c*)ZoneFeatures_GetFirstOfType((unsigned char*)&zone->substruct_6c_, 11);
    Vector3fix position;
    position.x = input->x * 6;
    position.y = input->y * 6;
    position.z = input->z * 6;
    int preferredDistance = 0x0ffff000;
    int fallbackDistance = preferredDistance;
    ProximityNode0201b78c* fallback = 0;
    position.x -= zone->substruct_c_.unknown_38_;
    position.z -= zone->substruct_c_.unknown_3c_;
    while (node) {
        int distance = Vector3fix_Distance(&node->position, &position);
        if (distance < preferredDistance) {
            if (distance <= node->radius) {
                preferredDistance = distance;
                preferred = node;
            } else if (distance < fallbackDistance) {
                fallbackDistance = distance;
                fallback = node;
            }
        }
        var1 = var1->unknown_70_;
    }
    if (var0) return var0;
    if (!var5) var5 = 0;
    return var5;
}
