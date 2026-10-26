#include <globaldefs.h>
#include "World/Object3D.h"

struct Struct_ov001_02164808_2 { int selector; char pad[8]; unsigned char* target; };
struct Struct_ov001_02164808 { int x, y, z; };

// USA: func_ov001_02164808
extern "C" ARM int func_ov001_02164808(struct Struct_ov001_02164808_2* arr, int index, struct Struct_ov001_02164808* out) {
    struct Struct_ov001_02164808_2* e;
    unsigned char* t;
    unsigned char* src;

    if (index < 0 || index >= 0x20) {
        return 0;
    }
    e = &arr[index];
    switch (e->selector) {
    case 0:
    case 1:
    case 4:
    case 5: {
        t = e->target;
        if (t == NULL) return 0;
        Vector3fix var3 = ((Object3D*)t)->GetScale();
        out->x = var3.x;
        out->y = var3.y;
        out->z = var3.z;
        return 1;
    }
    case 6: {
        t = e->target;
        if (t == NULL) return 0;
        src = *(unsigned char**)(t + 0x18);
        if (src == NULL) return 0;
        Vector3fix var4 = ((Object3D*)src)->GetScale();
        out->x = var4.x;
        out->y = var4.y;
        out->z = var4.z;
        return 1;
    }
    }
    return 0;
}
