#include <globaldefs.h>

#include "Graphics/Vector.h"
#include "World/Object3D.h"

struct Struct_ov025_021df864_2 {
    unsigned char distance;
    unsigned char alpha;
};

struct Struct_ov025_021df864 {
    Object3D unknown_0_;
    Object3D unknown_ac_;
    Vector3fix direction;
    Vector3fix origin;
    int unknown_170_;
    unsigned char mode;
    char unknown_175_;
    Struct_ov025_021df864_2 unknown_176_[10];
};

// USA: func_ov025_021df864
extern "C" ARM void func_ov025_021df864(Struct_ov025_021df864* fx) {
    int i;
    int var1;
    if (fx->mode <= 3) {
        var1 = 1;
    } else {
        var1 = 0;
    }
    if (var1) {
        for (i = 0; i < 10; i++) {
            Struct_ov025_021df864_2* var2 = &fx->unknown_176_[i];
            if (var2->alpha != 0) {
                Vector3fix pos;
                Vector3fixMultiplyScalar(&fx->direction, var2->distance << 12, &pos);
                Vector3fix_Add(&fx->origin, &pos, &pos);
                pos.y = 0x400;
                Object3D* obj = &fx->unknown_0_;
                obj->position_ = pos;
                obj->SetInheritedAlpha(var2->alpha);
                obj->DrawMeshWithMaterial(true, 0, 0, 1);
            }
        }
    } else {
        for (i = 0; i < 10; i++) {
            Struct_ov025_021df864_2* var5 = &fx->unknown_176_[i];
            if (var5->alpha != 0) {
                Vector3fix pos;
                Vector3fixMultiplyScalar(&fx->direction, var5->distance << 12, &pos);
                Vector3fix_Add(&fx->origin, &pos, &pos);
                pos.y = 0x400;
                Object3D* obj = &fx->unknown_ac_;
                obj->position_ = pos;
                obj->SetInheritedAlpha(var5->alpha);
                obj->DrawMeshWithMaterial(true, 0, 0, 1);
            }
        }
    }
}
