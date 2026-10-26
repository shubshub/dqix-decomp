#include <globaldefs.h>

struct Struct_020e545c {
    unsigned int w[4];
};

struct Struct_020e53bc {
    unsigned int count : 12;
    unsigned int pad : 20;
    struct Struct_020e545c* elements;
};

typedef void (*Type_020e53bc)(struct Struct_020e53bc*, struct Struct_020e545c*);

// USA: func_020e545c
extern "C" ARM int func_020e545c(struct Struct_020e53bc* list, Type_020e53bc callback) {
    int count;
    struct Struct_020e545c* element = list->elements;
    int i;
    if (!(element != NULL && (count = list->count) != 0 && callback != NULL)) {
        return 0;
    }
    i = 0;
    while (i < count) {
        callback(list, element);
        i++;
        element++;
    }
    return 1;
}
