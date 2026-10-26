#include <globaldefs.h>

extern "C" int func_ov017_021d60f4(void*);

extern "C" int* func_02094d6c(void);
extern "C" void* func_0209dccc(void);

struct Struct_0205faf4_7;
extern "C" void* func_02096134(struct Struct_0205faf4_7* t, int id);

// USA: func_0209d83c
extern "C" ARM int func_0209d83c(void* obj) {
    struct Struct_0205faf4_7* table;
    void* entry;
    int id;
    int val;

    table = (struct Struct_0205faf4_7*)func_02094d6c();
    if (table == NULL) return 0;

    if (func_0209dccc() == NULL) return 0;

    id = func_ov017_021d60f4(obj);
    entry = func_02096134(table, id);
    if (entry == NULL) return 0;

    val = func_ov017_021d60f4((char*)obj + 8);
    if (val > 0xffff) val = 0xffff;
    *(unsigned short*)((char*)entry + 0xa) = (unsigned short)val;
    return 1;
}
