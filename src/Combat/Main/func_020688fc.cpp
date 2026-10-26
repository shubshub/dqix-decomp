#include <globaldefs.h>

struct Struct_020688fc {
    int field0;
    char unk[0xc];
    int field10;
};

// USA: func_020688fc
extern "C" ARM int func_020688fc(int unused, struct Struct_020688fc* obj) {
    int a = obj->field0;
    int b = obj->field10;
    if (a != 0 && b != 0) {
        return a != b;
    }
    return 0;
}
