#include <globaldefs.h>

extern "C" void* func_02094d6c(void);
extern "C" void* func_0209dccc(void);

extern "C" int func_ov017_021d60f4(void*);
struct Struct_0205faf4_7;
struct Struct_0205faf4_8;
extern "C" struct Struct_0205faf4_8* func_02096134(struct Struct_0205faf4_7*, int);

struct Struct_0209d2a8 { char pad[0xa]; unsigned short arr[1]; };
struct Struct_0209d2a8_2 { char pad[0x98]; int field98; };

// USA: func_0209d2a8
extern "C" ARM int func_0209d2a8(void* arg) {
    void* table = func_02094d6c();
    if (table == NULL) return 0;
    struct Struct_0209d2a8_2* mgr = (struct Struct_0209d2a8_2*)func_0209dccc();
    if (mgr == NULL) return 0;
    struct Struct_0209d2a8* entry = (struct Struct_0209d2a8*)func_02096134((struct Struct_0205faf4_7*)table, func_ov017_021d60f4(arg));
    if (entry == NULL) return 0;
    int idx = func_ov017_021d60f4((char*)arg + 8);
    int delta = mgr->field98;
    int sum = entry->arr[idx];
    sum += delta;
    if (sum >= 0xffff) return 0;
    unsigned short* var6 = (unsigned short*)((char*)entry + 0xa);
    int v = var6[idx];
    v += delta;
    var6[idx] = v;
    return 1;
}
