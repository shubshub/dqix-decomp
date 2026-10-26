#include <globaldefs.h>
#include "std_library_functions.h"
#include "Combat/Overlay_1/EventArgs.h"

struct Struct_ov001_0215a608 { int type; int f1, f2, f3; int unknown_10_; };

extern "C" struct Struct_ov001_0215a608* func_ov001_02159fd4(void);

// USA: func_ov001_0215a608
extern "C" ARM int func_ov001_0215a608(void* unused, EventVec3 v, int count) {
    struct Struct_ov001_0215a608* obj = func_ov001_02159fd4();
    if (obj == NULL) return (int)obj;
    if (count <= 0) {
        obj->type = 0x10;
    } else {
        obj->type = 0x11;
    }
    memcpy(&obj->f1, &v, 0xc);
    obj->unknown_10_ = count;
    return count;
}
