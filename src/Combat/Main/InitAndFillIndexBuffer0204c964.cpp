#include <globaldefs.h>

struct Canvas0204e998;
extern "C" void WindowPane_Update(struct Canvas0204e998 *s, int a);
void FillIndexBuffer0204e998(struct Canvas0204e998 *s);

// USA: func_0204c964
ARM void InitAndFillIndexBuffer0204c964(struct Canvas0204e998 *s) {
    WindowPane_Update(s, 1);
    FillIndexBuffer0204e998(s);
}
