#include <globaldefs.h>

#if defined(jpn)
enum { Enum_02027304_1880 = 0x6ac };
#else
enum { Enum_02027304_1880 = 0x758 };
#endif


#include "Combat/ActionState.h"

// USA: func_02027304
extern "C" ARM void func_02027304(unsigned char *obj, int id) {
    if (id < 0) {
        int i;
        for (i = 0; i < 4; i++) {
            func_0201fbe0(&data_020fdc60[i], 0);
        }
        return;
    }
    if (id >= 4) return;
    {
        int i;
        unsigned char *p;
        for (i = 0; i < 4; i++) {
            p = obj + i;
            if (id == p[Enum_02027304_1880]) {
                func_0201fbe0(&data_020fdc60[i], 0);
                return;
            }
        }
    }
}
