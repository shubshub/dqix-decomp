#if defined(jpn)
enum { Enum_ov017_021c9334_1060 = 0x444 };
#else
enum { Enum_ov017_021c9334_1060 = 0x424 };
#endif

#include <globaldefs.h>
#include "NitroSDK/Matrix.h"

extern "C" int func_ov017_021d446c(void* obj, void* out, int flags);
extern "C" int Zone3D_GetInstance(void);
extern "C" int Zone3D_GetGroundHeight(int seed, Vector3i* v);
struct Obj02033834;
extern "C" void GameObject_SetFacing(struct Obj02033834* obj, int arg);
extern "C" void func_02076ccc(void*, int);

struct Struct_ov017_021c9334 {
    unsigned char pad0[4];
    unsigned short field4;
    unsigned char field6 : 6;
    unsigned char unknown_6_6_ : 2;
    signed char unknown_7_0_ : 4;
    signed char unknown_7_4_ : 4;
    short field8;
    short fieldA;
    int fieldC;
    int field10;
};

// USA: func_ov017_021c9334
extern "C" ARM void func_ov017_021c9334(int unused0, Struct_ov017_021c9334* evt) {
    int local[3];
    if (!func_ov017_021d446c((char*)evt + 4, local, -1)) return;
    if (*(int*)((char*)local[2] + 0x130) == 9) return;

    Vector3i v;
    v.x = evt->fieldC;
    v.y = evt->fieldA << 4;
    v.z = evt->field10;
    short y = evt->field8;
    int mode = evt->field6;

    int g = Zone3D_GetInstance();
    if (evt->field4 == *(unsigned short*)g && *(int*)((char*)g + Enum_ov017_021c9334_1060) == 0) {
        v.y = Zone3D_GetGroundHeight(g, &v);
    }

    *(short*)((char*)local[2] + 0x100 + 0x66) = evt->unknown_7_4_;
    *(Vector3i*)((char*)local[2] + 0x158) = v;
    GameObject_SetFacing((struct Obj02033834*)local[2], y);
    func_02076ccc((void*)local[2], mode);
}
