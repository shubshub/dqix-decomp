#include <globaldefs.h>

struct Struct_02003d58 {
    char* cursor;
    int field4;
};


// USA: func_02003d58
extern "C" ARM int func_02003d58(Struct_02003d58* obj, int val, int cmd) {
    switch (cmd) {
    case 0: {
        char c = *obj->cursor;
        if (c == 0) {
            obj->field4 = 1;
            return -1;
        }
        obj->cursor++;
        return (unsigned char)c;
    }
    case 1:
        if (obj->field4 == 0) {
            obj->cursor--;
        } else {
            obj->field4 = 0;
        }
        return val;
    case 2:
        return obj->field4;
    default:
        return 0;
    }
}
