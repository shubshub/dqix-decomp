#include <globaldefs.h>

struct Struct_020578e8 {
    int x;
    float y;
};
struct Struct_020557a4 {
    Struct_020578e8* p;
};

// USA: func_020578e8
extern "C" ARM float func_020578e8(Struct_020557a4* a, Struct_020557a4* b) {
    Struct_020578e8* pa = a->p;
    Struct_020578e8* pb = b->p;
    return (pb->y - pa->y) / (float)(pb->x - pa->x);
}
