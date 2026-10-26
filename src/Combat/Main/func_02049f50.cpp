#include <globaldefs.h>
#include "World/Object3D.h"

struct Struct_020489e8;

struct Struct_02049f50 {
    unsigned char pad1[0x41];
    unsigned char unknown_41_;
    unsigned char pad2[0x13c - 0x42];
    unsigned char* sub;
};

#pragma optimize_for_size off
// USA: func_02049f50
extern "C" ARM void func_02049f50(struct Struct_02049f50* obj, int val, int count) {
    if (count <= 0) {
        obj->unknown_41_ = (obj->unknown_41_ & ~0x1f) | ((unsigned char)val & 0x1f);
    }
    if (obj->sub == NULL) return;
    int x = ((Object3D*)((struct Struct_020489e8*)obj))->GetOwnAlpha();
    float f = (float)x;
    ((AlphaTween*)((unsigned short*)(obj->sub + 0x60)))->SetCurrentValue(f);
    ((AlphaTween*)(obj->sub + 0x60))->ConfigureTween(val, count);
}
