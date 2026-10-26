#include <globaldefs.h>

struct Struct_02097280 {
    char pad[8];
    int value;
};

// USA: func_02097280
extern "C" ARM int func_02097280(Struct_02097280 *obj, char *idx, int arg2) {
    int flag = 1;
    int i = (int)(idx - (char *)0);
    if (i != -1) {
        if (obj->value != 0) {
            flag = 0;
        }
    }
    if (flag == 0) {
        return obj->value + i;
    }
    return arg2;
}
