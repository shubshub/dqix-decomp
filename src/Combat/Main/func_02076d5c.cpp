#include <globaldefs.h>
extern "C" void func_02076ccc(void*, int);

struct Foo02033b58;
extern "C" void GameObject_StoreMotionState(struct Foo02033b58* p, unsigned char v);
extern "C" int ZoneId_IsGrottoBossFloor(int x);

extern "C" unsigned short* Zone3D_GetInstance(void);

struct Struct_02076d5c { char pad[0x14c]; unsigned int field_14c; };

// USA: func_02076d5c
extern "C" ARM void func_02076d5c(struct Struct_02076d5c* obj) {
    if (ZoneId_IsGrottoBossFloor(*Zone3D_GetInstance()) != 0 || obj->field_14c > 0x3e8) {
        GameObject_StoreMotionState((struct Foo02033b58*)obj, 0);
        func_02076ccc((void*)(obj), (int)(1));
    }
}
