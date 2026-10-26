#include <globaldefs.h>
#include "Resource/GameResources.h"

struct Obj02022d78;
void MapDisplay_SetMode(struct Obj02022d78*, int);

// USA: func_020dc3b8
ARM void Notify02022d78WithCode2_020dc3b8(void) {
    MapDisplay_SetMode((struct Obj02022d78*)GetGameResources()->unknown_ptr_36d0, 2);
}
