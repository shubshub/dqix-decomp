#include <globaldefs.h>
#include "NitroSDK/Matrix.h"

class Struct_ov004_0216b390 {
public:
    virtual void v00(); virtual void inline_ov004_0216b390_2(); virtual void inline_ov004_0216b390_3(); virtual void inline_ov004_0216b390_4();
    virtual void v04(); virtual void inline_ov004_0216b390_6(); virtual void inline_ov004_0216b390_7();
    virtual void inline_ov004_0216b390_8(Vector3i* arg);
    virtual Vector3i inline_ov004_0216b390_9();
};

extern "C" int func_ov004_0216af24(void* a, int key);
extern "C" void* func_ov011_021849c8(void* a);
extern "C" Struct_ov004_0216b390* func_ov023_021f6880(void* obj, int key);

// USA: func_ov004_0216b390
extern "C" ARM void func_ov004_0216b390(void* a, int arg1, int axis) {
    Vector3i v2;
    Vector3i v4;

    int delta = func_ov004_0216af24(a, (short)arg1);
    Struct_ov004_0216b390* var3 = func_ov023_021f6880(func_ov011_021849c8(a), arg1);
    if (!var3) return;

    const Vector3i& v1 = var3->inline_ov004_0216b390_9();
    v2 = v1;
    v2.x = v2.x + ((delta + 0xa) << 12);

    Struct_ov004_0216b390* node2 = func_ov023_021f6880(func_ov011_021849c8(a), 0xc);
    if (!node2) return;

    const Vector3i& v3 = node2->inline_ov004_0216b390_9();
    v4 = v3;
    v4.x = v2.x;

    if (axis == 0) v4.y = 0x24000;
    else if (axis == 1) v4.y = 0x34000;
    else if (axis == 2) v4.y = 0x42000;
    else if (axis == 3) v4.y = 0x1b000;

    node2->inline_ov004_0216b390_8(&v4);
    *((unsigned char*)node2 + 0x3a) = 0;
}
