#include <globaldefs.h>

struct Struct_0209aa40_2 {
    char pad[0x108];
    int count;
};
struct Struct_0209aa40 {
    struct Struct_0209aa40_2* container;
};

// USA: func_0209aa40
extern "C" ARM int func_0209aa40(struct Struct_0209aa40* holder) {
    struct Struct_0209aa40_2* c = holder->container;
    if (c != NULL) {
        return c->count;
    }
    return 0;
}
