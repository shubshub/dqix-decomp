#include <globaldefs.h>
#include <NitroSDK/Matrix.h>

class Struct_ov004_0215e574 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6();
    virtual void inline_ov004_0215e574_8(const Vector3i& v);
    virtual Vector3i inline_ov004_0215e574_9();
};

extern "C" int func_ov004_0215e4e8(void* a, int key);
extern "C" Struct_ov004_0215e574* func_ov004_0215e47c(void* a, int key);

// USA: func_ov004_0215e574
extern "C" ARM void func_ov004_0215e574(void* a, int b, int c, int d) {
    int r5 = func_ov004_0215e4e8(a, (short)b);
    Struct_ov004_0215e574* node = func_ov004_0215e47c(a, b);
    if (!node) return;
    Vector3i v2;
    const Vector3i& v = node->inline_ov004_0215e574_9();
    v2 = v;
    v2.x = (d + ((c - r5) >> 1)) << 12;
    node->inline_ov004_0215e574_8(v2);
}
