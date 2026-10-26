#include <globaldefs.h>

extern "C" void* func_02094d6c(void);
extern "C" void* func_0209dccc(void);

extern "C" int func_ov017_021d60f4(void*);
struct Struct_0205faf4_7;
struct Struct_0205faf4_8;
extern "C" struct Struct_0205faf4_8* func_02096134(struct Struct_0205faf4_7*, int);

struct Struct_0209d1a4 { char pad[0xa]; unsigned short field_a; };
struct Struct_0209d1a4_2 { char pad[0x98]; int field98; };

// USA: func_0209d1a4
extern "C" ARM int func_0209d1a4(void* arg) {
    void* table = func_02094d6c();
    if (table == NULL) return 0;
    struct Struct_0209d1a4_2* mgr = (struct Struct_0209d1a4_2*)func_0209dccc();
    if (mgr == NULL) return 0;
    struct Struct_0209d1a4* entry = (struct Struct_0209d1a4*)func_02096134((struct Struct_0205faf4_7*)table, func_ov017_021d60f4(arg));
    if (entry == NULL) return 0;
    if (entry->field_a + mgr->field98 >= 0xffff) return 0;
    entry->field_a = entry->field_a + mgr->field98;
    return 1;
}
