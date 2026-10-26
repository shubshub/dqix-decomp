#include <globaldefs.h>

struct Struct_020dfbfc {
    char pad[8];
    int value;
};

// USA: func_020dfbfc
extern "C" ARM int func_020dfbfc(Struct_020dfbfc *obj, char *idx, int arg2) {
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
