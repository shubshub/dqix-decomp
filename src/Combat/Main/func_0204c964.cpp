#include <globaldefs.h>

struct Canvas0204e998;
extern "C" void WindowPane_Update(struct Canvas0204e998 *s, int a);
extern "C" void func_0204e998(struct Canvas0204e998 *s);

// USA: func_0204c964
extern "C" ARM void func_0204c964(struct Canvas0204e998 *s) {
    WindowPane_Update(s, 1);
    func_0204e998(s);
}
