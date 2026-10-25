#include <globaldefs.h>
#include "Resource/Script.h"

struct Variant02030b0c {
    int tag;
    union {
        int i;
        float f;
    } u;
};
struct Struct02030b7c;
extern "C" void* Zone3D_GetInstance(void);

struct Global020fdc4c_f950 {
    int pad0;
    void* field4;
};
extern struct Global020fdc4c_f950 data_020fdc4c;

// USA: func_0201f950
ARM int CacheField4IfIdMatches_0201f950(struct Variant02030b0c* v) {
    int val;
    if (data_020fdc4c.field4 != 0) return 1;
    val = ((Script::Parameter*)v)->ToInt();
    if (val == *(unsigned short*)Zone3D_GetInstance()) {
        data_020fdc4c.field4 = (void*)((Script::Parameter*)((struct Struct02030b7c*)(v + 1)))->ToString();
    }
    return 1;
}
