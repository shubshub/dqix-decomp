#include <globaldefs.h>
#include "Combat/EntryGetterTypes.h"

struct Struct_02040a20 { unsigned int v[3]; };

// USA: func_02040a20
extern "C" ARM int func_02040a20(Struct_0203dce4* obj) {
    void* p;

    p = obj->child14;
    if (p != NULL) {
        return func_0203cdd0((struct Struct_0203cdd0*)p);
    }

    p = obj->unknown_18_;
    if (p != NULL) {
        struct Struct_02040a20 var1;
        var1 = *(struct Struct_02040a20*)((char*)p + 0x50);
        return (int)var1.v[1];
    }

    p = obj->child1c;
    if (p != NULL) {
        struct Struct_02040a20 t2;
        t2 = *(struct Struct_02040a20*)((char*)p + 0x50);
        return (int)t2.v[1];
    }

    return 0;
}
