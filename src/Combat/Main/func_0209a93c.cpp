#include <globaldefs.h>

struct PairEntry0209a93c {
    unsigned short a;
    unsigned short b;
};
struct Struct_0209a93c_2 {
    struct PairEntry0209a93c entries[0x42];
    int count;
};
struct PairHolder0209a93c {
    struct Struct_0209a93c_2* container;
};

// USA: func_0209a93c
extern "C" ARM void func_0209a93c(struct PairHolder0209a93c* holder, struct PairEntry0209a93c* src) {
    struct Struct_0209a93c_2* c = holder->container;
    int n;
    if (c == NULL) {
        return;
    }
    n = c->count;
    if (n >= 0x42) {
        return;
    }
    c->count = n + 1;
    {
        struct PairEntry0209a93c* dst = &holder->container->entries[n];
        dst->a = src->a;
        dst->b = src->b;
    }
}
