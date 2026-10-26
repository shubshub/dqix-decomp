#include <globaldefs.h>

struct KeyMap020a0b3c;
extern "C" signed char func_020a0b3c(struct KeyMap020a0b3c* map, int key);
extern "C" int func_0207c7a0(void* p, int key, int n);

// USA: func_02086bf4
extern "C" ARM short func_02086bf4(char* obj, int key) {
    short var0 = 0;
    if (key < 0) {
        return 0;
    }
    var0 = var0 + func_020a0b3c((struct KeyMap020a0b3c*)obj, key);
    var0 = var0 + func_0207c7a0(obj + 0x1d4, key, 9);
    var0 = var0 + func_020a0b3c((struct KeyMap020a0b3c*)(obj + 0xe04), key);
    return var0;
}
