#include <globaldefs.h>

struct Struct_020bc9a8;
extern "C" void func_020bc9a8(struct Struct_020bc9a8*);

// USA: func_020bf2d4
extern "C" ARM void func_020bf2d4(void *obj) {
    if (*(int *)((char *)obj + 0x120) == 0) return;
    if ((*(int *)((char *)obj + 0x120) -= 1) != 0) return;
    func_020bc9a8((struct Struct_020bc9a8*)obj);
}
