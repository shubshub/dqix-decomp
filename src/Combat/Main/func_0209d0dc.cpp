#include <globaldefs.h>

extern "C" int func_ov017_021d60f4(void*);
extern "C" void func_0209ef2c(void*, int, int, int);
extern "C" void* func_0209dccc();

// USA: func_0209d0dc
extern "C" ARM int func_0209d0dc(char* entries, int count) {
    void* mgr = func_0209dccc();
    if (mgr == NULL) return 0;
    int first = func_ov017_021d60f4(entries);
    entries += 8;
    for (int i = 1; i < count; i += 2) {
        int a = func_ov017_021d60f4(entries);
        char* next = entries + 8;
        entries += 0x10;
        int b = func_ov017_021d60f4(next);
        func_0209ef2c(mgr, first, a, b);
    }
    return 1;
}
