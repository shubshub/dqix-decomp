#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"


struct Struct_ov023_021f5410 {
    char pad0[0xc];
    short fieldc;
    char pad2[2];
    int field10;
    int field14;
};

// USA: func_ov023_021f5410
extern "C" ARM int func_ov023_021f5410(struct Struct_ov023_021f5410* obj) {
    int v = (int)BackgroundLoader::GetInstance();
    if (obj->field10 >= 0) {
        ((BackgroundLoader*)(v))->RemoveTask((int)(obj->field10));
        obj->field10 = -1;
    }
    obj->fieldc = 0;
    obj->field14 = 0;
    return 1;
}
