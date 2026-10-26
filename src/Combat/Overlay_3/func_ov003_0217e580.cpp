#include <globaldefs.h>

extern "C" void func_ov003_02168560(void);

// USA: func_ov003_0217e580
extern "C" ARM void func_ov003_0217e580(int* obj) {
    if (obj[8] != 0) {
        func_ov003_02168560();
    }
}
