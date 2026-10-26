#include <globaldefs.h>

struct UpdateStateStruct;

extern "C" unsigned char* Zone3D_GetChest(unsigned char* p, int i);
extern "C" void ZoneChest_StartOpening(UpdateStateStruct* p, int h, int i1, int i2);
extern "C" void* Zone3D_GetInstance(void* self);

struct Struct_ov017_021cfda0 {
    unsigned char pad0[4];
    unsigned short field4;
    unsigned short field6;
    unsigned char field8;
};

// USA: func_ov017_021cfda0
extern "C" ARM void func_ov017_021cfda0(void* self, Struct_ov017_021cfda0* obj) {
    unsigned char* ptr = (unsigned char*)Zone3D_GetInstance(self);
    if (obj->field4 != *(unsigned short*)ptr) return;
    unsigned char* stride = Zone3D_GetChest(ptr, obj->field6);
    if (!stride) return;
    ZoneChest_StartOpening((struct UpdateStateStruct*)stride, obj->field8, 0, 0);
}
