#include <globaldefs.h>
#include "Resource/GameResources.h"

struct Obj02022d78;
extern "C" void MapDisplay_SetMode(struct Obj02022d78*, int);

// USA: func_020dc3b8
extern "C" ARM void func_020dc3b8(void) {
    MapDisplay_SetMode((struct Obj02022d78*)GetGameResources()->unknown_ptr_36d0, 2);
}
