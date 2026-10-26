#include <globaldefs.h>

struct Struct_020afe50 {
    int f0;
    int f4;
    int f8;
};

extern "C" int func_020c895c(int, int, int, void *);

// USA: func_020afe50
extern "C" ARM int func_020afe50(struct Struct_020afe50 *p, int x) {
    return func_020c895c(p->f8, p->f4, x, p);
}
