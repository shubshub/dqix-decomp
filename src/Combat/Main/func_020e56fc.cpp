#include <globaldefs.h>

extern "C" void func_020e53bc(void* a, int b, void* c, void* d);
struct Struct_020e5204;
extern "C" void func_020e5204(void*, struct Struct_020e5204*);

// USA: func_020e56fc
extern "C" ARM int func_020e56fc(void* a0, int a1, int a2) {
    int local;
    if (a1 == 0 || a2 == 0) return 0;
    func_020e53bc(a0, a1, &local, (void*)func_020e5204);
    return 1;
}
