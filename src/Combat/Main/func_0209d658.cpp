#include <globaldefs.h>

extern "C" void* func_0209fd00();
extern "C" void func_ov017_021d6134(void*, void*);
extern "C" void* func_0209dccc();

// USA: func_0209d658
extern "C" ARM int func_0209d658(void* arg) {
    if (func_0209dccc() == NULL) return 0;
    func_ov017_021d6134(arg, func_0209fd00());
    return 1;
}
