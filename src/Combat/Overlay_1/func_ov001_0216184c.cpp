#include <globaldefs.h>

extern "C" void* func_0203cf4c(void);
extern "C" int func_ov017_021d60f4(void*);

struct Struct_ov001_0216184c { char pad[0x98]; unsigned int field98; };

// USA: func_ov001_0216184c
extern "C" ARM int func_ov001_0216184c(void* obj) {
    struct Struct_ov001_0216184c* g = (struct Struct_ov001_0216184c*)func_0203cf4c();
    int flag = func_ov017_021d60f4(obj);
    if (flag == 0) {
        g->field98 |= 0x2;
    } else {
        g->field98 &= ~0x2;
    }
    return 1;
}
