#include <globaldefs.h>

extern "C" void func_02001728(void* obj);

// USA: func_0200edb4
extern "C" ARM void func_0200edb4(void* obj) {
    if (obj == 0) return;
    func_02001728(obj);
}
