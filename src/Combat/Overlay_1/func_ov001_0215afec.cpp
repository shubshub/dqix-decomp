#include <globaldefs.h>
#include "Util/Random.h"

extern "C" int func_ov017_021d60f4(void*);
extern "C" void func_ov017_021d6134(void*, int);

// USA: func_ov001_0215afec
extern "C" ARM int func_ov001_0215afec(void* obj, int count) {
    if (count < 2) return 0;
    struct Random* rng = GetBTRandom();
    int var1 = func_ov017_021d60f4(obj);
    int var2 = func_ov017_021d60f4((char*)obj + 8);
    int n = NextRandomBetween(rng, var1, var2);
    func_ov017_021d6134((char*)obj + 0x10, n);
    return 1;
}
