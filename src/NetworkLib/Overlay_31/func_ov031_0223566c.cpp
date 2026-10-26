#include <globaldefs.h>

extern "C" ARM void func_ov031_0223566c(int id, void *buf);
extern "C" ARM int func_ov031_0223d524(void *buf);
extern "C" ARM int func_ov031_0223d49c(void *buf);

// USA: func_ov031_02235594
extern "C" ARM int func_ov031_02235594() {
    int buf[2];
    func_ov031_0223566c(1, buf);
    if (func_ov031_0223d524(buf) != 0)
        return 1;
    int i = 2;
    do {
        func_ov031_0223566c(i, buf);
        if (func_ov031_0223d524(buf) != 0)
            return i;
        i++;
    } while (i <= 3);
    func_ov031_0223566c(4, buf);
    if (func_ov031_0223d49c(buf) != 0)
        return 4;
    return 0;
}
