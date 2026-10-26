#include <globaldefs.h>
extern "C" void* func_02094d6c(void);

extern "C" int func_ov017_021d60f4(void*);
extern "C" void func_ov017_021d6134(void*, int);
struct Struct_0205faf4_7;
struct Struct_0205faf4_8;
extern "C" struct Struct_0205faf4_8* func_02096134(struct Struct_0205faf4_7*, int);

struct Struct_0209d214 { char pad[0xa]; unsigned short field_a; };

// USA: func_0209d214
extern "C" ARM int func_0209d214(char* arg) {
    void* table = func_02094d6c();
    if (table == NULL) return 0;
    struct Struct_0209d214* entry = (struct Struct_0209d214*)func_02096134(
        (struct Struct_0205faf4_7*)table, func_ov017_021d60f4(arg));
    if (entry == NULL) return 0;
    func_ov017_021d6134(arg + 8, entry->field_a);
    return 1;
}
