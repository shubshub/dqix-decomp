#include <globaldefs.h>
#include "Util/Random.h"

// USA: func_ov024_021ed890
extern "C" ARM int func_ov024_021ed890(struct Random** arg0, int* arg1, short* table) {
    int idx = NextRandomMax(*arg0, *arg1);
    short val = table[idx];
    table[0] = val;
    *arg1 = 1;
    return 1;
}
