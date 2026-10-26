#include <globaldefs.h>
#include "World/Object3D.h"

struct Struct_ov001_021649d4 { int type; char pad[8]; void* ptr; };
struct Struct_020484f8_3;

// USA: func_ov001_021649d4
extern "C" ARM int func_ov001_021649d4(Struct_ov001_021649d4* arr, int idx, int value) {
    if (idx < 0 || idx >= 0x20) {
        return 0;
    }
    int type = arr[idx].type;
    Struct_ov001_021649d4* entry = &arr[idx];
    if (type != 1) {
        goto fail;
    }
    {
        void* ptr = entry->ptr;
        if (ptr == NULL) {
            return 0;
        }
        ((Object3D*)((Struct_020484f8_3*)ptr))->SetRadius(value);
        return 1;
    }
fail:
    return 0;
}
