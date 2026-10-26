#include <globaldefs.h>

extern "C" int func_020d28f0(void);
struct Struct_020d2404;
extern "C" struct Struct_020d2404* func_020d28a8(void);
extern "C" int func_020d27e0(void);
extern "C" int func_020d22f4(int);
extern "C" void func_020d24c4(int);
extern "C" void func_020d2880(void);

// USA: func_020d2404
extern "C" ARM int func_020d2404(int flag) {
    struct Struct_020d2404* node;
    if (func_020d28f0() == 0) return 0;
    node = func_020d28a8();
    if (node != 0) return (int)node;
    if (!(flag & 1)) return 0;
    if (func_020d27e0() > 0) {
        while (func_020d22f4(0) != 0) {
        }
        node = func_020d28a8();
        if (node != 0) return (int)node;
    } else {
        func_020d24c4(1);
    }
    func_020d2880();
    do {
        func_020d22f4(1);
        node = func_020d28a8();
    } while (node == 0);
    return (int)node;
}
