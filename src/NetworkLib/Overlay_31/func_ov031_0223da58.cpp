#include <globaldefs.h>

extern "C" int func_ov031_0223bf48(int, void*);
extern void* data_ov031_02290d60;

struct Struct_ov031_0223da58 { unsigned int flags; };

// USA: func_ov031_0223da58
extern "C" ARM int func_ov031_0223da58(Struct_ov031_0223da58* obj) {
    obj->flags = (obj->flags & 0xc1fffcff) | 0x200;
    int idx = 0;
    char* base = (char*)data_ov031_02290d60;
    if ((char*)obj >= base + 0x400) idx = 1;
    int val = *(int*)(base + idx * 4 + 0x800);
    return func_ov031_0223bf48(val, obj);
}
