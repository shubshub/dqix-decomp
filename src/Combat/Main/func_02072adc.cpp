#include <globaldefs.h>
#include "World/Object3D.h"

struct Struct_02072adc;
struct Object3D;

// USA: func_02072adc
extern "C" ARM void func_02072adc(struct Struct_02072adc* src, struct Struct_02072adc* dst) {
    ((Object3D*)src)->ShallowCloneModelAndAnimationsTo((Object3D*)dst);
    *(short*)((char*)dst + 0x178) = *(int*)((char*)src + 0xac);
}
