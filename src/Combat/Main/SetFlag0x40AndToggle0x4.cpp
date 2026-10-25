#include <globaldefs.h>


extern "C" void* Scenario_GetInstance(void);

struct Struct02013380 {
    unsigned short unk0;
    unsigned short flags;
};

// USA: func_02013380
ARM void SetFlag0x40AndToggle0x4(Struct02013380* obj, int unused, int clear4) {
    Scenario_GetInstance();
    if (clear4 != 0)
        obj->flags &= ~4;
    else
        obj->flags |= 4;
    obj->flags |= 0x40;
}
