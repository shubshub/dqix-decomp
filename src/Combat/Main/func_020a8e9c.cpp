#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

struct Struct_020a8e9c;
extern "C" int func_020a8f60(struct Struct_020a8e9c* obj);

struct Struct_020a8e9c_2 {
    unsigned int count1 : 12;
    unsigned int count2 : 19;
    unsigned int flag : 1;
};

struct Obj020a8e9c {
    Struct_020a8e9c_2 header;
    void* buf1;
    void* buf2;
};

// USA: func_020a8e9c
extern "C" ARM void func_020a8e9c(Obj020a8e9c* obj, SafeAllocator* allocator, void* src, unsigned int) {
    if (allocator == 0 || src == 0) return;
    memcpy(obj, src, 4);
    int var0 = func_020a8f60((struct Struct_020a8e9c*)obj);
    unsigned int var1 = obj->header.count2;
    if (var0 != 0) obj->buf1 = allocator->Allocate(var0); else obj->buf1 = 0;
    if (var1 != 0) obj->buf2 = allocator->Allocate(var1); else obj->buf2 = 0;
    if (obj->buf1 != 0) {
        memcpy(obj->buf1, (char*)src + 4, var0);
    }
    if (obj->buf2 != 0) {
        memcpy(obj->buf2, (char*)src + (func_020a8f60((struct Struct_020a8e9c*)obj) + 4), var1);
    }
    obj->header.flag = 1;
}
