#include <globaldefs.h>
extern "C" int func_020d5490(int);

extern "C" int func_0202d108(void);
extern "C" void func_0202c848(int arg);

// USA: func_0202d0e0
extern "C" ARM int func_0202d0e0(void) {
    int r = func_020d5490((int)(func_0202d108));
    if (r == 2) {
        return 1;
    }
    func_0202c848(r);
    return 0;
}
