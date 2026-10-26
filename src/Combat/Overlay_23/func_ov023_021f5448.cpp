#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

struct Struct_ov023_021f5448 { unsigned int value : 12; };
extern "C" unsigned int func_ov023_021f5524(struct Struct_ov023_021f5448* obj);

struct Struct_ov023_021f5448_2 {
    unsigned int count1 : 12;
    unsigned int count2 : 19;
    unsigned int flag : 1;
    void* field4;
    void* field8;
};

// USA: func_ov023_021f5448
extern "C" ARM int func_ov023_021f5448(struct Struct_ov023_021f5448_2* obj, SafeAllocator* alloc, void* src, int cond) {
    if (alloc == 0 || src == 0 || cond == 0) {
        return 0;
    }

    if (alloc != 0 && src != 0) {
        memcpy(obj, src, 4);

        unsigned int var0 = func_ov023_021f5524((struct Struct_ov023_021f5448*)obj);
        unsigned int var1 = obj->count2;

        if (var0 != 0) {
            obj->field4 = alloc->Allocate(var0);
        } else {
            obj->field4 = 0;
        }
        if (var1 != 0) {
            obj->field8 = alloc->Allocate(var1);
        } else {
            obj->field8 = 0;
        }

        if (obj->field4 != 0) {
            memcpy(obj->field4, (char*)src + 4, var0);
        }
        if (obj->field8 != 0) {
            unsigned int off = func_ov023_021f5524((struct Struct_ov023_021f5448*)obj) + 4;
            memcpy(obj->field8, (char*)src + off, var1);
        }

        obj->flag = 1;
    }

    return 1;
}
