#include <globaldefs.h>

#include "World/Zone3D.h"
struct ProximityNode0201b78c {
    int field0;
    int field4;
    Vector3fix position;
    char unknown14[0x28];
    int radius;
    char unknown40[0x30];
    ProximityNode0201b78c* next;
};
extern "C" void* ZoneFeatures_GetFirstOfType(unsigned char*, unsigned int);
int Vector3fix_Distance(const Vector3fix*, const Vector3fix*);

// USA: func_0201b78c
extern "C" ARM ProximityNode0201b78c* func_0201b78c(Zone3D* zone, const Vector3fix* input) {
    ProximityNode0201b78c* preferred = 0;
    ProximityNode0201b78c* node = (ProximityNode0201b78c*)ZoneFeatures_GetFirstOfType((unsigned char*)&zone->substruct_6c_, 11);
    Vector3fix position;
    position.x = input->x * 6;
    position.y = input->y * 6;
    position.z = input->z * 6;
    int var3 = 0x0ffff000;
    int var4 = var3;
    ProximityNode0201b78c* var5 = 0;
    position.x -= zone->substruct_c_.unknown_38_;
    position.z -= zone->substruct_c_.unknown_3c_;
    while (node) {
        int distance = Vector3fix_Distance(&node->position, &position);
        if (distance < var3) {
            if (distance <= node->radius) {
                var3 = distance;
                preferred = node;
            } else if (distance < var4) {
                var4 = distance;
                var5 = node;
            }
        }
        node = node->next;
    }
    if (preferred) return preferred;
    if (!var5) var5 = 0;
    return var5;
}
