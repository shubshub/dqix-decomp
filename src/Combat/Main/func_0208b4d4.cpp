#include <globaldefs.h>
#include "Resource/GameResources.h"

extern "C" unsigned short* Zone3D_GetInstance(void);

struct Struct_0208b088_2 {
    char pad[0xac];
    int captured;   // 0xac
    int done;       // 0xb0
};

// USA: func_0208b4d4
extern "C" ARM int func_0208b4d4(struct Struct_0208b088_2* obj) {
    unsigned short cur;
    (int)GetGameResources();
    cur = *Zone3D_GetInstance();
    if (cur != obj->captured) {
        obj->done = 0;
        obj->captured = -1;
    }
    return obj->done;
}
