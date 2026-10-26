#include <globaldefs.h>
#include "NitroSDK/Matrix.h"

extern "C" int func_ov017_021d446c(void* obj, void* out, int flags);
extern "C" int Zone3D_GetInstance(void);
extern "C" int Zone3D_GetGroundHeight(int seed, Vector3i* v);
struct Obj02033874;
extern "C" void GameObject_SnapFacing(Obj02033874* obj, int arg);
extern "C" void func_02076ccc(void*, int);

struct Struct_ov017_021c949c {
    unsigned char pad0[4];
    unsigned short field4;
    unsigned char pad1[2];
    short field8;
    short fieldA;
    int fieldC;
    int field10;
};

// USA: func_ov017_021c949c
extern "C" ARM void func_ov017_021c949c(int unused0, Struct_ov017_021c949c* evt) {
#if defined(jpn)
 enum {regionalOffset0=0x444};
#else
 enum {regionalOffset0=0x424};
#endif
    int local[3];
    if (!func_ov017_021d446c((char*)evt + 4, local, -1)) return;

    Vector3i v;
    v.x = evt->fieldC;
    v.y = evt->fieldA << 4;
    v.z = evt->field10;
    short y = evt->field8;

    int g = Zone3D_GetInstance();
    if (evt->field4 == *(unsigned short*)g && *(int*)((char*)g + regionalOffset0) == 0) {
        v.y = Zone3D_GetGroundHeight(g, &v);
    }

    *(Vector3i*)((char*)local[2] + 0x44) = v;
    GameObject_SnapFacing((Obj02033874*)local[2], y);

    if (*(int*)((char*)local[2] + 0x130) != 9) {
        func_02076ccc((void*)local[2], 1);
    }
}
