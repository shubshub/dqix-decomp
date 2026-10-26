#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void func_ov001_02157668(void* p);

struct Struct_ov001_02157570 { int x, y, z; };
extern "C" void func_ov001_02157890(char* d, struct Struct_ov001_02157570* v1, struct Struct_ov001_02157570* v2);

struct Vec3 { int x, y, z; };
extern "C" void Vector3fix_Subtract(struct Vec3* a, struct Vec3* b, struct Vec3* out);

// USA: func_ov001_02158384
extern "C" ARM int func_ov001_02158384(int unused, char* self) {
    if (*(int*)(self + 0x38) <= 0) {
        func_ov001_02157668(self + 0x15c);
        *(int*)(self + 0xa1c) = 1;
        *(int*)(self + 0x38) = 1;
    }

    struct Struct_ov001_02157570 v1, v2;
    func_ov001_02157890(self + 0x15c, &v1, &v2);

    struct Vec3 pos;
    pos.x = *(int*)(self + 0x64);
    pos.y = *(int*)(self + 0x68);
    pos.z = *(int*)(self + 0x6c);

    Vector3fix_Subtract((struct Vec3*)&v1, &pos, (struct Vec3*)(self + 0x128));
    Vector3fix_Subtract((struct Vec3*)&v2, (struct Vec3*)(self + 0x58), (struct Vec3*)(self + 0x11c));

    memcpy(&pos, &v1, 0xc);
    memcpy(self + 0x58, &v2, 0xc);

    if (pos.x >= 0x647a) {
        pos.x -= 0x647a;
    }

    *(int*)(self + 0x64) = pos.x;
    *(int*)(self + 0x68) = pos.y;
    *(int*)(self + 0x6c) = pos.z;

    int flag = (*(int*)(self + 0xa1c) == 0) ? 1 : 0;
    if (flag) {
        flag = 0;
        *(int*)(self + 0x38) = flag;
    } else {
        flag = 1;
    }
    return flag;
}
