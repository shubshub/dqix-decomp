#include <globaldefs.h>

struct Struct_020bc180_2;
extern "C" void func_020c0204(struct Struct_020bc180_2*, int, int);

struct Struct_020bc180 { unsigned char pad[0x2c]; unsigned char state; };
struct Struct_0209c2e0_2 { struct Struct_020bc180* node; };

static inline bool inline_020bc180(const struct Struct_0209c2e0_2* o) { return o->node != NULL; }

// USA: func_020bc180
extern "C" ARM void func_020bc180(struct Struct_0209c2e0_2* obj, int value, int arg) {
    if (!inline_020bc180(obj)) return;
    if (obj->node->state == 2) return;
    func_020c0204((struct Struct_020bc180_2*)((char*)obj->node + 0x1c), value << 8, arg);
}
