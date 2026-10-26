#include <globaldefs.h>
#include "Resource/GameResources.h"

#if defined(jpn)
enum { kObjectOffset = 0x4c0 };
#else
enum { kObjectOffset = 0x6d0 };
#endif


extern "C" void* Zone3D_GetInstance(void);
struct Obj02022d78;
void MapDisplay_SetMode(struct Obj02022d78*, int);
int ZoneId_IsGrotto(int);

// USA: func_020dc214
ARM void SetModeBasedOnCombatState020dc214(int mode) {
    int base = (int)GetGameResources();
    void* raw = *(void**)(base + 0x3000 + kObjectOffset);
    unsigned short id = *(unsigned short*)Zone3D_GetInstance();
    struct Obj02022d78* obj = (struct Obj02022d78*)raw;
    if (mode == 1) {
        MapDisplay_SetMode(obj, 1);
        return;
    }
    if (mode == 2) {
        MapDisplay_SetMode(obj, 4);
        return;
    }
    if (mode != 0) {
        return;
    }
    if (ZoneId_IsGrotto(id)) {
        MapDisplay_SetMode(obj, 3);
        return;
    }
    if (id == 0x2710 || id == 0x2774) {
        MapDisplay_SetMode(obj, 4);
    } else {
        MapDisplay_SetMode(obj, 0);
    }
}
