#include <globaldefs.h>

struct Struct_020bc948;
extern "C" int func_020bc948(struct Struct_020bc948*, int, unsigned char*);

// USA: func_020bf29c
extern "C" ARM int func_020bf29c(void *obj, int a, int b) {
    if (*(int *)((char *)obj + 0x120) == 0) {
        if (func_020bc948((struct Struct_020bc948*)obj, a, (unsigned char*)b) == 0) return 0;
    }
    *(int *)((char *)obj + 0x120) += 1;
    return 1;
}
