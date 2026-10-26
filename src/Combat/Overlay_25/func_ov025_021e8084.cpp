#include <globaldefs.h>
#include "Resource/GameResources.h"

extern "C" int func_ov017_02191aac(int a, int b, int c, int d);

extern "C" int func_ov000_021820bc(void* obj, int unused, int index, int arg);

// USA: func_ov025_021e8084
extern "C" ARM int func_ov025_021e8084(int a, int b, int c, int d) {
    int local[4];
    int r4 = (int)GetGameResources();
    if (func_ov000_021820bc((void*)d, b, 7, (int)&local[0])) {
        func_ov017_02191aac(r4, 1, local[0], 4);
    }
    return 1;
}
