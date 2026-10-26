#include <globaldefs.h>

extern "C" int func_ov023_021f6558(void*);
extern "C" void* func_ov011_021849c8(void*);
extern "C" void func_ov023_021f6880(void*, int);

// USA: func_ov023_021f6590
extern "C" ARM void func_ov023_021f6590(void* arg0) {
    int r4 = func_ov023_021f6558(arg0);
    void* r0 = func_ov011_021849c8(arg0);
    func_ov023_021f6880(r0, r4);
}
