#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

struct Struct_02070a30;
extern "C" int func_02070af4(struct Struct_02070a30*);

struct Struct_020709ec {
    unsigned int count : 12;
    unsigned int unknown_1_4_ : 19;
    unsigned int flag  : 1;
    void* buf1;
    void* buf2;
};

// USA: func_02070a30
extern "C" ARM void func_02070a30(struct Struct_020709ec* obj, SafeAllocator* alloc, void* src, unsigned int sourceLength) {
    if (alloc == NULL || src == NULL) return;
    memcpy(obj, src, 4);
    int var0 = func_02070af4((struct Struct_02070a30*)obj);
    int var1 = obj->unknown_1_4_;
    if (var0 != 0) obj->buf1 = alloc->Allocate(var0);
    else obj->buf1 = NULL;
    if (var1 != 0) obj->buf2 = alloc->Allocate(var1);
    else obj->buf2 = NULL;
    if (obj->buf1) memcpy(obj->buf1, (char*)src + 4, var0);
    if (obj->buf2) memcpy(obj->buf2, (char*)src + (func_02070af4((struct Struct_02070a30*)obj) + 4), var1);
    obj->flag = 1;
}
