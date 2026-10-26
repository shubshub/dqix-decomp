#include <globaldefs.h>

extern "C" void* func_ov023_021e19ec(void*, void*, int, int, int);

// USA: func_ov023_021e1870
extern "C" ARM void func_ov023_021e1870(void* a, void* b, int c, int d, int e) {
    void* cur = func_ov023_021e19ec(a, b, c, d, e);
    if (cur == 0) return;
    *(void**)a = cur;
    while (cur != 0) {
        void* next = func_ov023_021e19ec(a, b, c, d, e);
        *(void**)cur = next;
        cur = next;
    }
}
