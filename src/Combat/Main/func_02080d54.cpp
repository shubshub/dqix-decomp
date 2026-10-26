#include <globaldefs.h>

struct Struct_0207fdcc_2;

struct Struct_02080d54 {
    char pad[0xa8];
    short width;
    short height;
    short x;
    short y;
};

extern "C" struct Struct_02080d54* func_02081da8(struct Struct_0207fdcc_2* obj, int key);

// USA: func_02080d54
extern "C" ARM int func_02080d54(struct Struct_0207fdcc_2* obj, int key, int px, int arg3) {
    struct Struct_02080d54* elem = func_02081da8(obj, key);
    short x1, var2;
    if (elem == NULL) {
        return 0;
    }
    x1 = elem->x + elem->width;
    var2 = elem->y + elem->height;
    if (px >= (short)(elem->x * 8)) {
        if (px < (short)(x1 * 8)) {
            if (arg3 >= (short)(elem->y * 8)) {
                if (arg3 < (short)(var2 * 8)) {
                    return 1;
                }
            }
        }
    }
    return 0;
}
