#include <globaldefs.h>

extern "C" void func_ov017_02190264(void* p, int idx);

// USA: func_ov017_02190238
extern "C" ARM void func_ov017_02190238(void* p) {
    for (int i = 0; i < 4; i++) {
        func_ov017_02190264(p, i);
    }
}
