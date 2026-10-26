#include <globaldefs.h>
#include "Util/Random.h"

extern "C" int func_ov017_021d60f4(void*);
extern "C" void func_ov017_021d6134(void*, int);

// USA: func_0209d3cc
extern "C" ARM int func_0209d3cc(char* arg) {
    struct Random* rng = GetBTRandom();
    int n = NextRandomMax(rng, func_ov017_021d60f4(arg) + 1);
    func_ov017_021d6134(arg + 8, n);
    return 1;
}
