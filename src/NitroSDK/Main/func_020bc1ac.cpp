#include <globaldefs.h>

extern "C" int func_020d1e88(int, int);

struct Struct_020bc1ac_2 { unsigned char pad[0x3c]; unsigned char field3c; };
struct Struct_020bc1ac { struct Struct_020bc1ac_2* node; };

static inline bool inline_020bc180(const struct Struct_020bc1ac* o) { return o->node != NULL; }

// USA: func_020bc1ac
extern "C" ARM void func_020bc1ac(struct Struct_020bc1ac* obj, int arg) {
    if (!inline_020bc180(obj)) return;
    func_020d1e88(obj->node->field3c, arg);
}
