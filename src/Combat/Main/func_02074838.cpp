#include <globaldefs.h>
#include "Util/Random.h"

// USA: func_02074838
extern "C" ARM float func_02074838(int value, int arg1, struct Random* arg2) {
    if (arg2 == NULL) {
        arg2 = &data_02108ddc;
    }
    if (arg1 != 0) {
        return (float)value * NextRandomFloatBetween(arg2, 0.95f, 1.05f);
    }
    return (float)value * NextRandomFloatBetween(arg2, 1.5f, 2.0f);
}
