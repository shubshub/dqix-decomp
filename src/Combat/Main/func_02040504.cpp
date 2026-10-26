#include <globaldefs.h>

extern "C" ARM void func_020404c0(int* obj);

// USA: func_02040504
extern "C" ARM void func_02040504(int* obj) {
    obj[5] = 0;
    obj[6] = 0;
    obj[7] = 0;
    func_020404c0(obj);
}
