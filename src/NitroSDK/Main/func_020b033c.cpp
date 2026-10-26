#include <globaldefs.h>

struct Struct_020b033c {
    char pad[8];
    int arr[3];
};

// USA: func_020b033c
extern "C" ARM void func_020b033c(struct Struct_020b033c* obj) {
    int i = 0;
    do {
        obj->arr[i] = -1;
    } while (++i < 3);
}
