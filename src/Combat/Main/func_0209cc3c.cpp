#include <globaldefs.h>
#include "Graphics/LightingManager.h"


extern "C" ARM void* Scenario_GetInstance(void);
extern "C" int Scenario_TestFlag(int unused, unsigned char* arr, int index);

struct Struct_0209cc3c {
    unsigned int id : 16;
    unsigned int unknown_2_0_ : 6;
    unsigned int field22 : 9;
    unsigned int unknown_3_7_ : 1;
};

struct Struct_0209cc3c_2 { struct Struct_0209cc3c* words; unsigned char count; };
struct Struct_0209cc3c_3 { char pad[0x98]; int field98; };

// USA: func_0209cc3c
extern "C" ARM int func_0209cc3c(struct Struct_0209cc3c_2* obj, unsigned short id) {
    void* self = Scenario_GetInstance();
    struct Struct_0209cc3c_3* data = (struct Struct_0209cc3c_3*)LightingManager::GetInstance();
    int i;
    for (i = 0; i < obj->count; i++) {
        struct Struct_0209cc3c* w = &obj->words[i];
        if (w->id != id) continue;
        if (!Scenario_TestFlag((int)self, (unsigned char*)self + 0x8c, w->field22)) continue;
        if (!w->unknown_3_7_ || data->field98 == 0) return w->unknown_2_0_;
    }
    return -1;
}
