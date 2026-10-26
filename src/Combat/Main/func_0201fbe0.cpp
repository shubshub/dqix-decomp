#include <globaldefs.h>

#include "Combat/ActionState.h"

// USA: func_0201fbe0
extern "C" ARM void func_0201fbe0(struct Struct_020fdc60 *s, int force) {
    if (s->b2 != 0 && force == 0) return;
    if (s->field4 != 0 && force == 0) return;
    if (s->state == 2 || s->state == 3 || force != 0 || s->unknown_1_ == 3) {
        s->unknown_1_ = 4;
    }
    s->field4 = 0;
}
