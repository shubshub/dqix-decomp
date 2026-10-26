#include <globaldefs.h>

extern "C" int func_ov017_021d60f4(void* obj);
extern "C" void* func_ov001_0215ab20(int idx);
extern "C" int func_ov001_0215a094(void* node);
extern "C" void func_ov017_021d6134(void*, int);

// USA: func_ov001_0215bf58
extern "C" ARM int func_ov001_0215bf58(void* obj) {
    void* node = func_ov001_0215ab20(func_ov017_021d60f4(obj));
    if (node == NULL) return 0;
    int r = func_ov001_0215a094(node);
    func_ov017_021d6134((char*)obj + 8, r == 0);
    return 1;
}
