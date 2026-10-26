#include <globaldefs.h>

struct Struct_ov011_02184c68 {
    int tag;
    Struct_ov011_02184c68* link;
};

// USA: func_ov011_02184c68
extern "C" ARM void func_ov011_02184c68(Struct_ov011_02184c68* obj, void* val) {
    if (obj->tag == 3) {
        obj->link->link = (Struct_ov011_02184c68*)val;
    }
}
