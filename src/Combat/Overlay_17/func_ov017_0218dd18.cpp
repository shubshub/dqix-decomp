#include <globaldefs.h>
#include "Graphics/Vector.h"
#include "World/Object3D.h"

struct Struct_ov017_0218dd18_3 {
    Vector3fix center;
    fix32_t radius;
};

struct Struct_ov017_0218dd18 {
    char pad0[0x5c];
    Struct_ov017_0218dd18_3* bounds;
};

struct Struct_ov017_0218dd18_2 {
    unsigned int flags;
    char pad4[0x14];
    Object3D* model;
};

extern "C" Vector3fix func_020406f8(Struct_ov017_0218dd18_2* node);
struct Struct_0203e0a0;
extern "C" Struct_ov017_0218dd18* func_02040538(Struct_0203e0a0*);
struct Struct_0203d028_15;
extern "C" void func_02040774(Struct_0203d028_15*, int, int, int);
extern "C" unsigned int func_02039dcc(unsigned char* obj);

// USA: func_ov017_0218dd18
extern "C" ARM int func_ov017_0218dd18(Object3D* self, Struct_ov017_0218dd18_2* node, int arg2) {
    Vector3fix pos = self->position_;
    Vector3fix target = func_020406f8(node);
    if (fix32abs(target.y - pos.y) >= 0x2000) {
        return 0;
    }
    int var2 = self->GetRadius() * 0.5f;
    int var3 = 0x800;
    if (node->model != NULL) {
        var3 = node->model->GetRadius() / 2;
    }
    Struct_ov017_0218dd18_3* bounds = func_02040538((Struct_0203e0a0*)node)->bounds;
    if (bounds != NULL) {
        var3 = bounds->radius;
        Vector3fix_Add(&target, &bounds->center, &target);
    }
    int var5 = var2 + var3;
    if (var5 == 0) {
        return 0;
    }
    if (var5 < fix32abs(pos.x - target.x)) {
        return 0;
    }
    if (var5 < fix32abs(pos.z - target.z)) {
        return 0;
    }
    target.y = pos.y;
    int dist = Vector3fix_Distance(&pos, &target);
    if (var5 < dist) {
        return 0;
    }
    if (node->flags & 0x40000) {
        return 0;
    }
    if (!func_02039dcc((unsigned char*)self)) {
        if (arg2) {
            var5 -= (int)(0.2f * (self->GetRadius() * 0.5f));
            if (var5 < dist) {
                return 0;
            }
            Vector3fix delta;
            Vector3fix_Subtract(&target, &pos, &delta);
            Vector3fixMultiplyScalar(&delta, fix32_Divide(var5, dist), &delta);
            Vector3fix_Add(&pos, &delta, &target);
            func_02040774((Struct_0203d028_15*)node, target.x, target.y, target.z);
        } else {
            Vector3fix delta;
            Vector3fix_Subtract(&pos, &target, &delta);
            if (dist < var2) {
                dist = var2;
            }
            Vector3fixMultiplyScalar(&delta, fix32_Divide(var5, dist), &delta);
            Vector3fix_Add(&target, &delta, &pos);
            self->position_ = pos;
        }
    }
    return 1;
}
