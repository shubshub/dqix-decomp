#include <globaldefs.h>

extern "C" int func_ov017_021d60f4(void*);
extern "C" void func_ov017_021d6134(void*, int);
extern "C" void* func_0203cf4c(void);
extern "C" int func_0203dfdc(void* base, int key);

// USA: func_ov001_0215fa10
extern "C" ARM int func_ov001_0215fa10(char* obj) {
    int key = func_ov017_021d60f4(obj);
    void* base = func_0203cf4c();
    int idx = func_0203dfdc(base, key);
    func_ov017_021d6134(obj + 8, idx);
    return 1;
}
