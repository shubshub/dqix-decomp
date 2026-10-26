#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"
#include "Resource/ActionDataTables.h"

struct Struct_02079bac_3 {
    unsigned int f : 12;
};

struct Struct_02079bac {
    unsigned char pad[8];
};

extern "C" int func_02079ce8(struct Struct_02079bac_3* p);

// USA: func_02079bac
extern "C" ARM int func_02079bac(struct Struct_02079bac_2* obj, SafeAllocator* alloc, void* src, Type_02079bac cb, Type_02079bac_2 cb2
#if !defined(jpn)
    , SafeAllocator* arg5
#endif
) {
#if defined(jpn)
    SafeAllocator* arg5 = alloc;
#endif
    int var0;
    unsigned int var1;
    int i;
    struct Struct_02079bac* e;
    int cnt;

    if (alloc == 0 || src == 0) {
        return 0;
    }
#if !defined(jpn)
    if (arg5 == 0) {
        arg5 = alloc;
    }
#endif
    memcpy(obj, src, 4);
    var0 = func_02079ce8((struct Struct_02079bac_3*)obj);
    var1 = obj->hi;
    obj->arr = var0 ? (struct Struct_02079bac*)alloc->Allocate(var0) : 0;
    obj->extra = var1 ? (unsigned char*)arg5->Allocate(var1) : 0;
    if (obj->arr != 0) {
        memcpy(obj->arr, (char*)src + 4, var0);
    }
    if (obj->extra != 0) {
        memcpy(obj->extra, (char*)src + (func_02079ce8((struct Struct_02079bac_3*)obj) + 4), var1);
    }
    if (cb != 0) {
        if (obj->arr != 0) {
            cnt = (short)obj->count;
            if (cnt != 0 && cb != 0) {
                for (i = 0, e = obj->arr; i < cnt; i++, e++) {
                    cb(obj, e);
                }
            }
        }
    }
    if (cb2 != 0) {
        cb2(obj);
    }
    obj->flag = 1;
    return 1;
}
