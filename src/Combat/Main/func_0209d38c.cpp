#include <globaldefs.h>

extern "C" int func_ov017_021d60f4(void*);
extern "C" void func_ov017_021d6134(void*, int);
extern "C" void* func_0209dccc();
struct Struct_0209d38c;
extern "C" int func_0209fc84(struct Struct_0209d38c*, int);

// USA: func_0209d38c
extern "C" ARM int func_0209d38c(char* arg) {
    void* mgr = func_0209dccc();
    if (mgr == NULL) return 0;
    int v = func_0209fc84((struct Struct_0209d38c*)mgr, func_ov017_021d60f4(arg));
    func_ov017_021d6134(arg + 8, v);
    return 1;
}
