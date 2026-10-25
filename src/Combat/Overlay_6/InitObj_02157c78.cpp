#include <globaldefs.h>
#include "std_library_functions.h"

struct StructDE1D4;
void ItemRecord_Clear(struct StructDE1D4* p);

struct Obj02157c78 {
    void* p20;
    void* p40;
    char pad8[0x20 - 0x8];
    char field20[0x20];
    char field40[0x30];
    char pad70[0x70 - 0x70];
    short field70;
};

// USA: func_ov006_02157c78
ARM void InitObj_02157c78(struct Obj02157c78* obj) {
    ItemRecord_Clear((struct StructDE1D4*)obj);
    memset(obj->field20, 0, 0x20);
    memset(obj->field40, 0, 0x30);
    obj->p20 = obj->field20;
    obj->p40 = obj->field40;
    obj->field70 = -1;
}
