#include <globaldefs.h>

struct Struct_021117ec_4 { unsigned char pad[0x1c]; int lock; void (*fn)(int, int); int arg; };
extern struct Struct_021117ec_4 data_021117ec;

// USA: func_020ce240
extern "C" ARM void func_020ce240(int a) {
    void (*fn)(int, int);
    int arg;
    fn = data_021117ec.fn;
    arg = data_021117ec.arg;
    data_021117ec.lock = 0;
    if (fn == NULL) {
        return;
    }
    data_021117ec.fn = NULL;
    fn(a, arg);
}
