#include <globaldefs.h>
#include "Util/Random.h"

// USA: func_ov024_021d8f18
extern "C" ARM int func_ov024_021d8f18(struct Random** arg0, int a1, int a2, int a3, int a4, int val) {
    struct Random* rng = *arg0;
    float f = NextRandomFloatBetween(rng, 0.1f, 0.5f);
    return (int)((float)val * f);
}
