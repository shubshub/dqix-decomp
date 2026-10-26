#include <globaldefs.h>
#include "NitroSDK/Matrix.h"

struct Vec3 : Vector3i {};

extern "C" void __clear(void* ptr, int size);

struct Struct_0200f374 { unsigned char pad[0x400]; };
struct Struct_ov015_0218f44c { unsigned char pad0[8]; struct Struct_0200f374 arr[2]; };

struct Struct_ov015_0218f44c_2 {
    unsigned char pad1[0x1c];
    unsigned char mode;
    unsigned char pad2[3];
    unsigned char pad3[4];
    struct Struct_ov015_0218f44c* base;
};

// USA: func_ov015_0218f44c
extern "C" ARM void func_ov015_0218f44c(struct Struct_ov015_0218f44c_2* obj, struct Vec3 accum) {
    Vector3i local;
    __clear(&local, 0xc);
    switch (obj->mode) {
        case 0:
            local = *(Vector3i*)((char*)obj->base + 0xf0);
            Vector3fix_Add(&local, &accum, &local);
            *(Vector3i*)((char*)obj->base + 0xf0) = local;
            local = *(Vector3i*)((char*)obj->base + 0x44);
            Vector3fix_Add(&local, &accum, &local);
            *(Vector3i*)((char*)obj->base + 0x44) = local;
            break;
        case 1:
            local = *(Vector3i*)((char*)&obj->base->arr[1] + 0x44);
            Vector3fix_Add(&local, &accum, &local);
            *(Vector3i*)((char*)&obj->base->arr[1] + 0x44) = local;
            local = *(Vector3i*)((char*)obj->base + 0xf0);
            Vector3fix_Add(&local, &accum, &local);
            *(Vector3i*)((char*)obj->base + 0xf0) = local;
            local = *(Vector3i*)((char*)obj->base + 0x3a0);
            Vector3fix_Add(&local, &accum, &local);
            *(Vector3i*)((char*)obj->base + 0x3a0) = local;
            local = *(Vector3i*)((char*)obj->base + 0x44);
            Vector3fix_Add(&local, &accum, &local);
            *(Vector3i*)((char*)obj->base + 0x44) = local;
            break;
        default:
            local = *(Vector3i*)((char*)obj->base + 0x44);
            Vector3fix_Add(&local, &accum, &local);
            *(Vector3i*)((char*)obj->base + 0x44) = local;
            break;
    }
}
