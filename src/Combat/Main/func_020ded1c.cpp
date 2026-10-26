#include <globaldefs.h>

extern "C" void func_020de524(int a, int b, void** out);

typedef int (*Type_020ded1c)(void*, int, int, int);

struct Struct_020ded1c {
    unsigned short count;
    unsigned short pad2;
    unsigned int pad4;
    unsigned int pad8;
    void* base;
};

// USA: func_020ded1c
extern "C" ARM int func_020ded1c(struct Struct_020ded1c* obj, int arg1, int a, int b) {
    void* fn = 0;
    int count;
    char* elem;
    int i;
    func_020de524(a, b, &fn);
    if (fn == NULL) return 0;
    count = obj->count;
    elem = (char*)obj->base;
    for (i = 0; i < count; i++, elem += 0x20) {
        if (((Type_020ded1c)fn)(elem, arg1, a, b) != 0) return (int)elem;
    }
    return 0;
}
