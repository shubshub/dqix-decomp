#include <globaldefs.h>

typedef void (*Type_020a8f70)(void*, void*);

struct Struct_020a8f70 {
    unsigned int count : 12;
    char* base;
};

#pragma optimize_for_size off

// USA: func_020a8f70
extern "C" ARM int func_020a8f70(struct Struct_020a8f70* obj, Type_020a8f70 fn) {
    int count;
    char* p = obj->base;
    if (p == 0) goto fail;
    count = obj->count;
    if (count != 0 && fn != 0) goto doloop;
fail:
    return 0;
doloop:
    {
        int i = 0;
        while (i < count) {
            fn(obj, p);
            i++;
            p += 64;
        }
    }
    return 1;
}
