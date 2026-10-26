#include <globaldefs.h>
#if defined(jpn)
enum { Enum_ov000_021637fc_828 = 0x12c, Enum_ov000_021637fc_29696 = 0x7800, Enum_ov000_021637fc_30528 = 0x7930 };
#else
enum { Enum_ov000_021637fc_828 = 0x33c, Enum_ov000_021637fc_29696 = 0x7400, Enum_ov000_021637fc_30528 = 0x7740 };
#endif
#include "Util/Random.h"

// USA: func_ov000_021637fc
extern "C" ARM int func_ov000_021637fc(void* obj, int id) {
    int i;
    signed char last;
    char* p;
    if (id < 0 || id >= 4) {
        return 0;
    }
    p = (char*)obj + Enum_ov000_021637fc_828;
    last = -1;
    i = 0;
    p = p + Enum_ov000_021637fc_29696;
    while (i < 4) {
        signed char v = p[i];
        if (v < 0) {
            int r;
            struct Random* rng;
            p[i] = (char)id;
            rng = GetBTRandom();
            if (last < 0) {
                r = 0;
            } else {
                r = last + NextRandomBetween(rng, 3, 10);
            }
            *((char*)obj + i + Enum_ov000_021637fc_30528) = (char)r;
            return 1;
        }
        last = *((char*)obj + i + Enum_ov000_021637fc_30528);
        i++;
    }
    return 0;
}
