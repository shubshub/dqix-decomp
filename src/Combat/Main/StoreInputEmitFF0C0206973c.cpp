#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void func_020696bc(int a, int* out, int c);
char* MessageSystem_GetInstance();

struct Struct0206973c { void* ptr; };

// USA: func_0206973c
ARM int StoreInputEmitFF0C0206973c(Struct0206973c* obj, int input) {
    int val;
    unsigned short buf;
    void* dst;
    func_020696bc(input, &val, 1);
    MessageSystem_GetInstance()[0x1960] = val;
    dst = obj->ptr;
    buf = 0xff0c;
    memcpy(dst, &buf, 2);
    return 2;
}
