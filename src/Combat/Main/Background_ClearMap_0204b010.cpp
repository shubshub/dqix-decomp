#include <globaldefs.h>
#include "std_library_functions.h"

extern unsigned int data_020e7b98[][4];

struct Obj0204b010 {
    char pad0[0x14];
    void* field14;
    unsigned int field18;
    char pad1c[3];
    unsigned char byte1f;
};

// Main, originally ClearBuffer0204b010 (USA 0x0204b010, EUR 0x0204b020, JPN 0x0204be30)
ARM void Background_ClearMap(Obj0204b010* obj, void* p) {
    if (p == NULL) p = obj->field14;
    if (p == NULL) return;
    memset(p, 0, data_020e7b98[obj->byte1f][obj->field18]);
}
