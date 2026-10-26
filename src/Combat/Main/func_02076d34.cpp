#include <globaldefs.h>

extern "C" void Zone3D_GetInstance(void* obj);

struct Bytes02033b88;
extern "C" int GameObject_ForceMotionState(struct Bytes02033b88* p, int val);

struct Struct_02076d34 {
    char pad[0xb2];
    unsigned short unknown_b2_;
};

// USA: func_02076d34
extern "C" ARM int func_02076d34(struct Struct_02076d34* p) {
    Zone3D_GetInstance(p);
    p->unknown_b2_ = 0;
    GameObject_ForceMotionState((struct Bytes02033b88*)p, 5);
    return 1;
}
