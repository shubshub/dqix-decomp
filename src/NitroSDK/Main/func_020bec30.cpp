#include <globaldefs.h>

struct Struct_020bec10;
extern "C" void func_020bec10(struct Struct_020bec10* owner);
extern "C" int func_020bebb4(void* a, int key, int arg2);

// USA: func_020bec30
extern "C" ARM int func_020bec30(void* a, int key, int arg2) {
    if (func_020bebb4(a, key, arg2) == 0) return 0;
    func_020bec10((struct Struct_020bec10*)a);
    return 1;
}
