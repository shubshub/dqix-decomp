#include <globaldefs.h>

#include "Resource/GameResources.h"
#include "Combat/MapDisplay.h"
extern "C" int Zone3D_GetInstance(void);
extern "C" int sprintf(char* dst, const char* fmt, ...);

struct Struct_020dc3d4;
extern "C" void func_020e063c(Struct_020dc3d4* self, int b, int c);

extern char data_020f2948[];
extern char data_020f294f[];

// USA: func_020dc3d4
extern "C" ARM void func_020dc3d4(void) {
    char buf[0x18];
    GameResources* resources = GetGameResources();
    MapDisplay* display = resources->unknown_ptr_36d0;
    MapDisplay_ResetMap(display);
    sprintf(buf, data_020f2948, Zone3D_GetInstance() + 0x26);
    func_020e063c((Struct_020dc3d4*)display, (int)data_020f294f, (int)buf);
}
