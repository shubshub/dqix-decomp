#include <globaldefs.h>
#include "Resource/GameResources.h"

extern "C" unsigned short* Zone3D_GetInstance(void);

struct Obj0208b4d4 {
    char pad[0xac];
    int captured;   // 0xac
    int done;       // 0xb0
};

// USA: func_0208b4d4
ARM int ValidateCapturedValue0208b4d4(struct Obj0208b4d4* obj) {
    unsigned short cur;
    (int)GetGameResources();
    cur = *Zone3D_GetInstance();
    if (cur != obj->captured) {
        obj->done = 0;
        obj->captured = -1;
    }
    return obj->done;
}
