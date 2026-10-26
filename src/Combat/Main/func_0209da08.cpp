#include <globaldefs.h>

extern "C" int func_ov017_021d60f4(void*);
extern "C" int func_ov017_021d6134(void*, int);
extern "C" void* func_0209dccc();
struct Struct_0209da08;
extern "C" int func_0209fc9c(struct Struct_0209da08*, int);

// USA: func_0209da08
extern "C" ARM int func_0209da08(void* arg) {
    void* mgr = func_0209dccc();
    if (mgr == NULL) return 0;
    int v = func_ov017_021d60f4(arg);
    int r = func_0209fc9c((struct Struct_0209da08*)mgr, v);
    func_ov017_021d6134((char*)arg + 8, r);
    return 1;
}
