#include <globaldefs.h>

struct Struct_0208bf78_5;

struct Struct_0208dac4 {
    char pad[0x10];
    int unknown_10_;
    int unknown_14_;
};

extern "C" struct Struct_0208dac4* func_0208d994(struct Struct_0208bf78_5* l, int key);

// USA: func_0208dac4
extern "C" ARM int func_0208dac4(struct Struct_0208bf78_5* l, int key) {
    struct Struct_0208dac4* e = func_0208d994(l, key);
    return e ? e->unknown_10_ : 0;
}
