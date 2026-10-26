#include <globaldefs.h>

extern "C" int func_02079840(void* base, int offset, int arg2);

struct Struct_02079808 {
    int f0;
    char pad[0x30];
    int f34;
};

// USA: func_02079808
extern "C" ARM int func_02079808(void* base, struct Struct_02079808* obj) {
    obj->f0 = func_02079840(base, obj->f0, 0);
    obj->f34 = func_02079840(base, obj->f34, 0);
    return 1;
}
