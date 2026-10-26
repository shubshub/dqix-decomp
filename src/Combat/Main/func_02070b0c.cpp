#include <globaldefs.h>

struct Struct_02070b0c_2 {
    unsigned char data[0x84];
};

struct Struct_02070b0c {
    unsigned int count : 12;
    struct Struct_02070b0c_2 *elements;
};

typedef void (*Type_02070b0c)(struct Struct_02070b0c *, struct Struct_02070b0c_2 *);

// USA: func_02070b0c
extern "C" ARM int func_02070b0c(struct Struct_02070b0c *container, Type_02070b0c callback) {
    int count;
    struct Struct_02070b0c_2 *elem = container->elements;
    int i;
    if (elem == NULL) goto ret_zero;
    count = container->count;
    if (count != 0 && callback != NULL) goto run_loop;
ret_zero:
    return 0;
run_loop:
    i = 0;
    while (i < count) {
        callback(container, elem);
        i++;
        elem++;
    }
    return 1;
}
