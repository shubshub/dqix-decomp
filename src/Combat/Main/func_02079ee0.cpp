#include <globaldefs.h>

struct Struct_02079ee0;
struct Struct_02079ee0_2;
struct Struct_020797f8;
typedef int (*Type_02079ee0)(struct Struct_02079ee0*);

extern "C" struct Struct_02079ee0* func_02079f20(struct Struct_02079ee0_2* c, int key, Type_02079ee0 fn);
extern "C" int func_020797f8(struct Struct_020797f8* p);

// USA: func_02079ee0
extern "C" ARM struct Struct_02079ee0* func_02079ee0(void* obj, int key) {
    struct Struct_02079ee0* r;
    if (key == 0) return NULL;
    r = func_02079f20((struct Struct_02079ee0_2*)((char*)obj + 0x18), key, (Type_02079ee0)func_020797f8);
    if (r != NULL) return r;
    return func_02079f20((struct Struct_02079ee0_2*)((char*)obj + 0x24), key, (Type_02079ee0)func_020797f8);
}
