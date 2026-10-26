#include <globaldefs.h>

struct Struct_0209ce14;
extern "C" void func_0209e4a0(struct Struct_0209ce14*);
extern "C" void* func_0209dccc();

// USA: func_0209ce14
extern "C" ARM int func_0209ce14() {
    struct Struct_0209ce14* mgr = (struct Struct_0209ce14*)func_0209dccc();
    if (mgr == NULL) return 0;
    func_0209e4a0(mgr);
    return 1;
}
